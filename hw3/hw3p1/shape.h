#ifndef SHAPE_H
#define SHAPE_H

#include <stdexcept>
#include <string>


class Shape {
    public:
        virtual const std::string create_svg_markup() const = 0;
};

#endif

