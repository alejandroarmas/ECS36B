
#include "Table.h"
#include <stdexcept>

Table::Table(int n) : maxGuests(n) {}

int Table::currentOccupancy(void) {
    return numGuests;
}

int Table::maxOccupancy(void) {
    return maxGuests;
}

bool Table::addGuests(int n) {
    
    bool ableToAddGuests = numGuests + n <= maxGuests;
    
    if (n > 0 ) {
        

        if (ableToAddGuests) {
            numGuests += n;
        }
    }
    else {
        throw std::invalid_argument("must be positive");
    }

    return ableToAddGuests;
}

