#include <string>
#include <vector>
#pragma once

// The functions below ask the user info about their trip to use as parameters to update in the class with function in "setTripParematers"
class Flight {
    public:

        // The function for assigning all of the values that the algorithims use to calculate exact details
        Flight(std::string departAirport, std::string arrivalAirport, int departureTime, int numTravelers);
        
        // The functions below return the values after the are calculated by the algorithim that the user NEEDS to see
        double getFlightCost(); // Returns flight cost as a double (missing "$")

        int getDepartureTime(); // Returns departure time as a 4-digit number

        std::string getDepartureAirport() { return departAirport; }

        int getTravelers() { return numTravelers; }
        // Function(s) that will be private
    private:
        std::string departAirport;
        std::string arrivalAirport;
        int getFlightDistance(std::string depart, std::string arrival);
        int findIndex(std::string airport);
        double cost;
        int numTravelers;
        int departureTime;
        int duration;

        const std::vector<std::string> airports = {"los angeles", "new york", "london", "paris", "dubai", "sydney", "tokyo"};
        const std::vector<int> losAngelesDistances = {0, 2469, 5444, 5664, 8350, 7231, 5475};
        const std::vector<int> newYorkDistances = {2469, 0, 3442, 3624, 6848, 10374, 6757};
        const std::vector<int> londonDistances = {5444, 3442, 0, 227, 3425, 10506, 5960};
        const std::vector<int> parisDistances = {5664, 3624, 227, 0, 3268, 10423, 6053};
        const std::vector<int> dubaiDistances = {8350, 6848, 3425, 3268, 0, 7232, 4954};
        const std::vector<int> sydneyDistances = {7231, 10374, 10506, 10423, 7232, 0, 5070};
        const std::vector<int> tokyoDistances = {5475, 6757, 5960, 6053, 4954, 5070, 0};
        const double costPerMile = 0.14;
};