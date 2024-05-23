#include <iostream>
#include <vector>
#pragma once

class Lodging {
	public:
		Lodging(std::string cityName, int travelers, int duration);
		std::string getHotelName() {return hotelName;}
		int getHotelsCost() {return hotelsCost;}
        int getDuration() { return tripDuration; }
        int getRating() { return rating; }

	private:
		int travelers; // Stores the amount of travelers
		std::string cityName; //Stores the city name in lowercase
		std::string nameCity; //Stores the city name in uppercase
		int tripDuration; //Stores the duration of the trip
		int hotelsCost; //Stores the total cost of hotels
        int rating;
		std::string hotelName; // Stores the hotel name
		void main(); //Function called within the constructor
		int errorChecking(std::string valueToCheck, int input_type); //Supportive Function
		void printHotelsandPrices(std::vector<std::string> hotels, std::vector<int> prices, int rating); //Supportive function
		void setHotelNameAndTotalCost(std::vector<std::string> hotels, std::vector<int> prices, int hotelChoice); // Supportive Function
		void hotelSelection(std::vector<std::string> star1, std::vector<std::string> star2, std::vector<std::string> star3, std::vector<std::string> star4, std::vector<std::string> star5, std::vector<int> price1, std::vector<int> price2, std::vector<int> price3, std::vector<int> price4, std::vector<int> price5, int rating); //Supportive function
		// Functions per each city, called in the main function.
		void LA(int rating);
		void NYC(int rating);
		void LDN(int rating);
		void PAR(int rating);
		void DBX(int rating);
		void SYD(int rating);
		void TYO(int rating);
};