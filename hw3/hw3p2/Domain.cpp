#include <algorithm>  // for_each(), remove()
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>

#include "Domain.h"
#include "Shape.h"
#include "point.h"

const std::string TEMPLATE_START = "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>\n<svg width=\"700\" height=\"600\"\nxmlns=\"http://www.w3.org/2000/svg\">\n<g transform=\"matrix(1,0,0,-1,50,550)\"\nfill=\"white\" fill-opacity=\"0.5\" stroke=\"black\" stroke-width=\"2\">\n";
const std::string TEMPLATE_CENTER = "</g>\n<g transform=\"matrix(1,0,0,1,50,590)\"\n font-family=\"Arial\" font-size=\"32\">\n";
const std::string TEMPLATE_END = "</g>\n</svg>\n";


void Domain::addShape(const Shape* p) {
    s.emplace_back(p);
}


void Domain::draw(void) {
    std::string diagonistic_ok_msg = "ok";
    std::string canvas_error_msg = "does not fit";
    std::string overlap_error_msg = "overlap";

    bool overlap_error, canvas_error = false;
    std::vector<const Shape*>::iterator item = s.begin();
    Rectangle canvas(Point(0,0), 600, 500);
    
    std::cout << TEMPLATE_START;
    
    std::cout << "<rect fill=\"lightgrey\" x=\""
            + std::to_string(canvas.position.x) + "\" y=\""
            + std::to_string(canvas.position.y) + "\" width=\""
            + std::to_string(canvas.width) + "\" height=\""
            + std::to_string(canvas.height) + "\"/>\n";

    Rectangle const * rt;
    Circle const * ci;

    for (; item != s.end() && !canvas_error; item++) {

        std::vector<const Shape*>::iterator compareTo = item;
        compareTo++;
        canvas_error = !(*item)->fits_in(canvas);
        rt = dynamic_cast<Rectangle const *>((*item));
        ci = dynamic_cast<Circle const *>((*item)); 

        if (rt) {
            // Is rectangle
            std::cout << "<rect x=\""
            + std::to_string(rt->position.x) + "\" y=\""
            + std::to_string(rt->position.y) + "\" width=\""
            + std::to_string(rt->width) + "\" height=\""
            + std::to_string(rt->height) + "\"/>\n";
        }
        else {
            // Is Circle
            std::cout << "<circle cx=\""
                        + std::to_string(ci->center.x) + "\" cy=\""
                        + std::to_string(ci->center.y) + "\" r=\""
                        + std::to_string(ci->radius) + "\"/>\n";
        }

        // Validation for Overlapping.
        for (; compareTo != s.end() && !overlap_error; compareTo++) {
            overlap_error = (*item)->overlaps(**compareTo);   
        }

    }

    std::cout << TEMPLATE_CENTER;    

    std::string diagnosticMessage;

    // Print Diagnostic Message.
    if (canvas_error) {
        diagnosticMessage = canvas_error_msg;
    }
    else if (overlap_error) {
        diagnosticMessage = overlap_error_msg;
    }
    else {
        diagnosticMessage = diagonistic_ok_msg;
    }
    // std::cout << diagnosticMessage << std::endl;
    std::cout << "<text x=\"0\" y=\"0\">" << diagnosticMessage << "</text>\n";
    std::cout << TEMPLATE_END; 
    
}

Domain::Domain() {

}


struct shape_deleter {
    void operator()(const Shape*& s) { 
            delete s;
            s = nullptr;
        }
};


Domain::~Domain() {

    for_each(s.begin(), s.end(), shape_deleter());
    std::vector<const Shape*>::iterator new_end = remove(s.begin(), s.end(), static_cast<const Shape*>(nullptr));
    s.erase(new_end, s.end());
}