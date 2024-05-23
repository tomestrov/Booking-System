#include "trip.h"

#include <cassert>
#include <iostream>

#include "flight.h"
#include "lodging.h"

int main() {
  Flight* departingFlight = new Flight("los angeles", "new york", 1200, 2);
  Flight* returningFlight = new Flight("new york", "los angeles", 1800, 2);

  Lodging* lodging = new Lodging("los angeles", 2, 7);

  std::string tripName = "My Trip";
  Trip trip(departingFlight, returningFlight, lodging, tripName);

  assert(trip.getName() == tripName);

  delete departingFlight;
  delete returningFlight;
  delete lodging;

  std::cout << "All tests passed!\n";

  return 0;
}
