#include "trip.h"
#include "flight.h"
#include "lodging.h"
#include <iostream>
#include <string>

// define constructor, using inputs from users
Trip::Trip(Flight *departingFlight, Flight *returningFlight, Lodging *lodging, std::string tripName) {
  this->departingFlight = departingFlight;
  this->returningFlight = returningFlight;
  this->lodging = lodging;
  this->tripName = tripName;
}

// function that prits trip details
void Trip::printTripStats() {
    std::cout << tripName << ":" << std::endl;
    std::cout << "\tDeparting City: " << departingFlight->getDepartureAirport() << std::endl;
    std::cout << "\tDestination City: " << returningFlight->getDepartureAirport() << std::endl;
    std::cout << "\tHotel: " << lodging->getHotelName() << " Rating: " << lodging->getRating() << " stars" << std::endl;
    std::cout << "\tTravelers: " << departingFlight->getTravelers() << std::endl;
    std::cout << "\tDuration: " << lodging->getDuration() << " days." << std::endl;
    std::cout << "\tDepart Time: " << departingFlight->getDepartureTime() << std::endl;
    std::cout << "\tTotal Cost: $" << departingFlight->getFlightCost() + returningFlight->getFlightCost() + lodging->getHotelsCost() << std::endl;    
}
