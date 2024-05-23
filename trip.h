#pragma once
#include <string>
#include <vector>
#include "flight.h"
#include "lodging.h"

class Trip {
 public:
 // The function is used to assign all the values obtained in other functions to a certain trip
  Trip(Flight *departingFlight, Flight *returningFlight, Lodging *lodging, std::string tripName);

// this function prints out the details of a holiday, so that the user can visualise the trip they have created, uses inputs from other functions
  void printTripStats();

// this function simply obtains the name the user wants to attach to a saved holiday, this is used to differentiate between saved trips when viewing or deleting
  std::string getName() { return tripName; }

// function(s) that will be private
 private:
  Flight *departingFlight;
  Flight *returningFlight;
  Lodging *lodging;
  std::string tripName;
};
