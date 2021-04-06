#include "Restaurant.h"
#include "Table.h"

#include <iostream>


Restaurant::Restaurant(int nLarge, int nMedium, int nSmall) : size(nLarge + nMedium + nSmall) {
    
    tableList = new Table *[size];

    for (int tableIndex = 0; tableIndex < size; tableIndex++) {

        if (tableIndex < nLarge) {
            tableList[tableIndex] = new Table(LARGE_TABLE_CAPACITY);
        }
        else if (tableIndex < nLarge + nMedium) {
            tableList[tableIndex] = new Table(MEDIUM_TABLE_CAPACITY);
    
        }
        else if (tableIndex < nLarge + nMedium + nSmall) {
            tableList[tableIndex] = new Table(SMALL_TABLE_CAPACITY);        
        }
        std::cout << "Table "<< tableIndex + 1 <<" maximum occupancy " << tableList[tableIndex]->maxOccupancy() << std::endl;
    }

}

void Restaurant::addGuests(int n) {

    bool canSupportMoreGuests = false;

    int tableIndex = 0; 
    while (tableIndex < size && !canSupportMoreGuests) {

        if (tableList[tableIndex]->addGuests(n)) {
            canSupportMoreGuests = true;
            std::cout << n << " guests added to table " << tableIndex + 1 << std::endl;
        } 
         tableIndex++;
    }
    if (!canSupportMoreGuests) {
        std::cout << " could not accommodate " << n << " guests" << std::endl;
    }

}

void Restaurant::printSummary(void) {

    std::cout << "Summary:" << std::endl;

    for (int tableIndex = 0; tableIndex < size; tableIndex++) {
        if (tableList[tableIndex]->currentOccupancy() > 0) {
            std::cout << "table " << tableIndex + 1 << " " << tableList[tableIndex]->currentOccupancy() << "/" << tableList[tableIndex]->maxOccupancy() << std::endl;
        }

    }

}
