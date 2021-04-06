#ifndef CLOSER_H
#define CLOSER_H

#include <string>

#include "Facility.h"
#include "gcdistance.h"

class Closer {

    public:
        Closer(const double a, const double b) : 
                    current_latitude(a), 
                    current_longitude(b) {}

        bool operator()(Facility* f_1,Facility* f_2) {
            
            double dist_1 = gcdistance(current_latitude, 
                            current_longitude, 
                            f_1->latitude(), 
                            f_1->longitude());

            double dist_2 = gcdistance(current_latitude, 
                            current_longitude, 
                            f_2->latitude(), 
                            f_2->longitude());
            return dist_1 < dist_2;
        }

    private:
        const double current_latitude, 
                    current_longitude;
};

#endif