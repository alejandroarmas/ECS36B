
#include "Aircraft.h"
#include <iostream>
#include <string>

const int A380_NUM_ENGINES = 4;
const int B737_NUM_ENGINES = 2;
const int A380_MAX_ENGINE_HOURS = 750;
const int B737_MAX_ENGINE_HOURS = 600;


Aircraft::Aircraft(int n, std::string name_str) : numEng(n), nm(name_str) {
    hrs = new int [n];
 }


const std::string Aircraft::name(void) const {
    return nm;
}


int Aircraft::numEngines(void) const {
    return numEng;
}


void Aircraft::setHours(int i, int h) {
    hrs[i - 1] = h;
}


void Aircraft::print(void) const {

    std::cout << "Aircraft: " << nm << " type: " << type() << " has " << numEng << " engines" << std::endl; 

    for (int i = 0; i < numEng; i++) {
        std::cout << "engine " << i + 1 << ": " << hrs[i] << " hours" << std::endl; 
    }
}


void Aircraft::printSchedule(void) const {

    std::cout << "Maintenance schedule for " << nm << std::endl;

    for (int i = 0; i < numEng; i++) {
        int hours_left = maxHours() - hrs[i];
        if (hours_left > 0){
            std::cout << "engine " << i + 1 << ": maintenance due in " << hours_left << " hours" << std::endl; 
        }
        else {
            std::cout << "engine " << i + 1 << ": maintenance due now!!" << std::endl; 

        }
    
    } 

    return ;
}


Aircraft::~Aircraft(void) {
    delete hrs;
}


Aircraft* Aircraft::makeAircraft(char ch, std::string name_str) {

    switch (ch){
        case 'A':
        return new A380(name_str);
        
        
        case 'B':
        return new B737(name_str);
        

        default: 
        return 0;
    }

    return 0;
}


A380::A380(std::string name_str) : Aircraft(A380_NUM_ENGINES, name_str) {}

const std::string A380::type(void) const {
    return "Airbus A380";
}

const int A380::maxHours(void) const {
    return A380_MAX_ENGINE_HOURS;
}

// A380::~A380(void) {

// }


B737::B737(std::string name_str) : Aircraft(B737_NUM_ENGINES, name_str) {}

const std::string B737::type(void) const {
    return "Boeing B737";
}


const int B737::maxHours(void) const {
    return B737_MAX_ENGINE_HOURS;
}


// B737::~B737(void) {

// }


