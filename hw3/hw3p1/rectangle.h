#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <string>

#include "shape.h"
#include "point.h"


class Rectangle : public Shape {
    public:
        Rectangle(int x, int y, int w, int h) : lower_left_corner(x, y), width(w), height(h) {}
        virtual const std::string create_svg_markup() const {
            const std::string output = "<rect x=\""
                         + std::to_string(lower_left_corner.get_x()) + "\" y=\""
                          + std::to_string(lower_left_corner.get_y()) + "\" width=\""
                          + std::to_string(width) + "\" height=\""
                          + std::to_string(height) + "\"/>";
            return output;
        };

    private:
        Cartesian_Point lower_left_corner;
        int width, height; 

};

#endif