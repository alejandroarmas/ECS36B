// Alejandro Armas
// 915110085
#include "Angle.h"
#include <iostream>

void Angle::set(int inputAngle) {
    
    if (inputAngle > 120) {
        theta = 120;
    }
    else if (inputAngle < -60) {
        theta = -60;
    }
    else {
        theta = inputAngle;
    }
}

int Angle::get(void) { return theta; }

Angle::Angle(void) {
    set(30);
}

void Angle::change(int dt) {
    int currentAngle = get();
    set(currentAngle + dt);
}

void Angle::print(void){
    std::cout << "angle: " << get() << std::endl;
}