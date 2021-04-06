#include <string>
#include <sstream>


#include "Facility.h"
#include "gcdistance.h"


const int SITE_NUMBER_START = 0;
const int SITE_NUMBER_LENGTH = 10;

const int TYPE_START = 11;
const int TYPE_LENGTH = 13;

const int CODE_START = 24;
const int CODE_LENGTH = 4;

const int NAME_START = 130;
const int NAME_LENGTH = 50;

const int LATITUDE_START = 535;
const int LATITUDE_LENGTH = 12;

const int LONGITUDE_START = 562;
const int LONGITUDE_LENGTH = 12;

const int SECONDS_IN_HOUR = 3600;


Facility::Facility(std::string s) : 
            site_number_(s.substr(SITE_NUMBER_START, SITE_NUMBER_LENGTH)), 
            type_(s.substr(TYPE_START, TYPE_LENGTH)), 
            code_(s.substr(CODE_START, CODE_LENGTH)), 
            name_(s.substr(NAME_START, NAME_LENGTH)),
            latitude_(convert_latitude(s.substr(LATITUDE_START, LATITUDE_LENGTH))) ,
            longitude_(convert_longitude(s.substr(LONGITUDE_START, LONGITUDE_LENGTH))) {}


double Facility::latitude(void) const {
    return latitude_;
}


std::string Facility::site_number(void) const {
    return site_number_;
}


std::string Facility::type(void) const {
    return type_;
}


std::string Facility::code(void) const {
    return code_;
}


std::string Facility::name(void) const {
    return name_;
}



double Facility::longitude(void) const {
    return longitude_;
}


double Facility::convert_latitude(std::string s) const {
    
    std::stringstream ss(s);
    double latitude;
    char direction;
    
    ss >> latitude >> direction;
 
    latitude = (direction == 'N') ? latitude : -latitude;
    latitude /= SECONDS_IN_HOUR;
    
    return latitude;
}


double Facility::convert_longitude(std::string s) const {
    
    std::stringstream ss(s);
    double longitude;
    char direction;
    
    ss >> longitude >> direction;
 
    longitude = (direction == 'E') ? longitude : -longitude;
    longitude /= SECONDS_IN_HOUR;

    return longitude;
}


double Facility::distance(double lat, double lon) const {
    /**
     * Calculate the Nautical Mile distance between two
     *  points on Earth given latitude and longitude. 
     */

    return gcdistance(lat, lon, latitude_, longitude_);
}