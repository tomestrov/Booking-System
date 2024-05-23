//#pragma once
#include <string>
#include <vector>

#include "flight.h"
#include "lodging.h"
#include "trip.h"

class Booking {
 public:
  // This function starts the booking process, the function gets inputs from the users and uses them as parameters in other functions
  void start();

 // function(s) that will be private
 private:
  std::vector<Trip*> trips;
  void createTrip();
  void viewTrips();
  void deleteTrip();
  std::string departingCity;
  std::string destinationCity;
  int departTime;
  int travelers;
  int duration;
};
