#ifndef POINT_H
#define POINT_H


class Cartesian_Point {

    public:
        Cartesian_Point(int a, int b) : x(a), y(b) {} 
        void set_x(int new_x) {x = new_x;}
        int get_x() const {return x;}
        int get_y() const {return y;}
        void set_y(int new_y) {y = new_y;}
    private: 
        int x, y;
};

#endif