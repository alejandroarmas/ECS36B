#include <iostream>

#include "Shape.h"


bool Circle::overlaps(const Shape& s) const {
    return s.overlaps(*this);
}


bool Circle::overlaps(const Circle& r) const {
    
    int squared_l2_norm =  (this->center.x - r.center.x) * (this->center.x - r.center.x)
     + (this->center.y - r.center.y) * (this->center.y - r.center.y);
 
    return squared_l2_norm < (r.radius * r.radius);
}


bool Circle::overlaps(const Rectangle& r) const {
    return r.overlaps(*this);
}


bool Circle::fits_in(const Rectangle& r) const {

    bool a = this->center.x - radius >= r.position.x;
    bool b = this->center.y - radius >= r.position.y;
    bool c = this->center.x + radius <= r.position.x + r.width;
    bool d = this->center.y + radius <= r.position.y + r.height;

    bool fits = a && b && c && d;
    return fits;
}


void Circle::draw(void) const {
    const std::string output = "<circle cx=\""
                          + std::to_string(center.x) + "\" cy=\""
                          + std::to_string(center.y) + "\" r=\""
                          + std::to_string(radius) + "\"/>";
    std::cout << output << std::endl;
}

Circle::~Circle(void) {
    
}