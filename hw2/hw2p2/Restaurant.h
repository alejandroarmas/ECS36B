//
// Restaurant.h
//
#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "Table.h"

const int LARGE_TABLE_CAPACITY = 10;
const int MEDIUM_TABLE_CAPACITY = 7;
const int SMALL_TABLE_CAPACITY = 5;



class Restaurant
{
  public:
  Restaurant(int nLarge, int nMedium, int nSmall);
  void addGuests(int nGuests);
  void printSummary(void);

  private:
  const int size;
  Table** tableList;
};
#endif
