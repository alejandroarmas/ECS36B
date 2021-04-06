#include <iostream>
#include <sstream>
#include <vector>

#include "circle.h"
#include "rectangle.h"
#include "svg.h"


using namespace std;

int main()
{
    char shape;
    int a, b, c, d;
    std::vector<Shape*> shape_pointers;
    string input;
    SVG svg = SVG();
    svg.grabDataFromFile();
    
    getline(cin, input);

    a = b = c = d = 0;
     
    do {
        stringstream ss(input);
        ss >> shape;
        ss >> a;
        ss >> b;
        ss >> c;
        ss >> d;

        bool validInputs = a && b && c;
        
        
        if (validInputs) {
            if (toupper(shape) == 'R' && d) {
                shape_pointers.emplace_back(new Rectangle(a, b, c, d));
            }
            else if (toupper(shape) == 'C') {
                shape_pointers.emplace_back(new Circle(a, b, c));
            }
        
        }
        else cout << "Invalid Input" << endl;
        
        input.clear();

        } while(getline(cin, input));

        for (std::vector<Shape*>::iterator it = shape_pointers.begin(); it != shape_pointers.end();) {
            svg.insertData((*it++)->create_svg_markup());
        }

    svg.printData();

}