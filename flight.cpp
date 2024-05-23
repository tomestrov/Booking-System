#include "flight.h"
#include <iostream>
#include <string>

using namespace std;
// Constructor implementation
Flight::Flight(std::string departAirport, std::string arrivalAirport, int departureTime, int numTravelers) {
    this->departAirport = departAirport;
    this->arrivalAirport = arrivalAirport;
    this->departureTime = departureTime;
    this->numTravelers = numTravelers;
}

double Flight::getFlightCost() {
    // Calculating the cost
    int distance = getFlightDistance(departAirport, arrivalAirport);
    double cost = distance * costPerMile * numTravelers;
    // std::cout << "distance: " << distance << std::endl;
    return cost;
}

int Flight::getDepartureTime() { return departureTime; }

int Flight::findIndex(std::string airport) {
    for (int i = 0; i < 7; ++i) {
        if (this->airports.at(i) == airport) {
            return i;
        }
    }
    return -1; // Airport not found
}

int Flight::getFlightDistance(std::string depart, std::string arrival) {
    int depIndex = findIndex(depart);
    int arrIndex = findIndex(arrival);

    if (depIndex == -1 || arrIndex == -1) {
        std::cout << "Invalid airport names." << std::endl;
        return -1;
    }

    // Finding the distance based on departure and arrival airports
    int distance;
    if (depIndex == 0) {
        distance = losAngelesDistances.at(arrIndex);
    } else if (depIndex == 1) {
        distance = newYorkDistances.at(arrIndex);
    } else if (depIndex == 2) {
        distance = londonDistances.at(arrIndex);
    } else if (depIndex == 3) {
        distance = parisDistances.at(arrIndex);
    } else if (depIndex == 4) {
        distance = dubaiDistances.at(arrIndex);
    } else if (depIndex == 5) {
        distance = sydneyDistances.at(arrIndex);
    } else if (depIndex == 6) {
        distance = tokyoDistances.at(arrIndex);
    }
    return distance;
}
