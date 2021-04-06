#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <fstream>
#include <sstream>

#include "shape.h"
#include "point.h"

class Circle: public Shape
{
    public:
        Circle(int x, int  y, int  r) : center(x, y), radius(r) {} 

        virtual const std::string create_svg_markup() const {
            const std::string output = "<circle cx=\""
                          + std::to_string(center.get_x()) + "\" cy=\""
                          + std::to_string(center.get_y()) + "\" r=\""
                          + std::to_string(radius) + "\"/>";
            return output;
        };
    private:
        Cartesian_Point center;
        int radius;
};

#endif