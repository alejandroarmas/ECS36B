#include <string>

#include "Runway.h"


const int SITE_NUMBER_START = 0;
const int SITE_NUMBER_LENGTH = 10;

const int NAME_START = 13;
const int NAME_LENGTH = 7;

const int LENGTH_START = 20;
const int LENGTH_LENGTH = 5;


Runway::Runway(std::string s) :
        site_number_(s.substr(SITE_NUMBER_START, SITE_NUMBER_LENGTH)), 
        name_(s.substr(NAME_START, NAME_LENGTH)), 
        length_(convert_length(s.substr(LENGTH_START, LENGTH_LENGTH))) {}


std::string Runway::site_number(void) const {
    return site_number_;
}


std::string Runway::name(void) const {
    return name_;
}


int Runway::length(void) const {
    return length_;
}


int Runway::convert_length(std::string s) const {
    return stoi(s);
}