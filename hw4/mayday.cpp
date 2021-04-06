//
// mayday.cpp
//
// use: mayday latitude longitude min_length
//
// Provide a list of facilities and runways closest to the location specified
// by the coordinates (latitude,longitude).
// Only facilities having runways longer than min_length are printed.
// Only runways longer than min_length are printed.
//
// Input:
//   latitude, longitude in degrees decimal
//   min_length in ft
// Output:
//   list of nearest facilities and runways including distance in nautical miles

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm> // sort(), remove_if()
#include <vector>
#include <cassert>
#include <cmath>

#include "Facility.h"
#include "Runway.h"
#include "Closer.h"
#include "SiteNumber.h"

using namespace std;


int main(int argc, char **argv) {
  // use: mayday current_latitude current_longitude min_runway_length
  // latitude and longitudes in degrees decimal
  // min runway length of runway in ft

  assert(argc==4);
  const double current_latitude = atof(argv[1]);
  const double current_longitude = atof(argv[2]);
  const int min_runway_length = atoi(argv[3]);

  vector<Facility*> facilities;
  // load facilities data
  // Insert your code here

  std::fstream fs;
  std::stringstream ss;
  std::string line;

  const std::string FACILITY_FILE = "Facilities.txt";
  const std::string RUNWAY_FILE = "Runways.txt";

  fs.open(FACILITY_FILE, std::fstream::in);

  if (fs) {

    while (getline(fs, line)) {
        
      Facility * fptr = new Facility(line);
      
      facilities.emplace_back(fptr);

      line.clear();
    }

    fs.close();

  }

  // sort facilities in order of proximity to the current position
  sort(facilities.begin(), facilities.end(),
       Closer(current_latitude,current_longitude));


  vector<Runway*> runways;
  // load runways data
  // Insert your code here

  fs.open(RUNWAY_FILE, std::fstream::in);

  if (fs) {

    while (getline(fs, line)) {
        
      Runway * rptr = new Runway(line);
      
      runways.emplace_back(rptr);

      line.clear();
    }

    fs.close();

  }

  typedef vector<Runway*> rwp; 

  // list up to 10 nearest facilities that have a long enough runway
  // list each runway that is long enough
  rwp good_runways;
  rwp::iterator rwiter, it;
  int count = 0;
  for ( unsigned int i = 0; i < facilities.size() && count < 10; i++ ) {

    Facility *a = facilities[i];
    rwp runways_copy = runways;
   
    rwiter = remove_if(runways_copy.begin(), runways_copy.end(), SiteNumber(a->site_number()));

    for (it = runways_copy.begin(); it != rwiter; it++) {

      if ((*it)->length() >= min_runway_length) {

        good_runways.emplace_back((*it));
      }

      
    }
    if ( !good_runways.empty() ) {

        // increment count of good facilities
        count++;

        cout << a->type() << " " << a->code() << " "
            << a->name() << " ";
        cout.setf(ios_base::fixed,ios_base::floatfield);
        cout.setf(ios_base::right, ios_base::adjustfield);
        cout.width(5);
        cout.precision(1);
        cout << a->distance(current_latitude,current_longitude)
            << " NM" << endl;

        // print all runways that are long enough
        for ( unsigned int i = 0; i < good_runways.size(); i++ )
        {
          Runway *r = good_runways[i];
          cout << "  Runway: " << r->name() << "  length: " << r->length()
              << " ft" << endl;
        }
        good_runways.clear();
    }
  }
  

    // print this facility if it has long enough runways
    
}
