#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "lodging.h"

//Defining constructor and setting private variables. Main function is called
Lodging::Lodging(std::string city, int travelers, int duration) {
	//Converting cityName to lowercase for easy comparison later on
	for (char ch : city) {
    this->cityName += tolower(ch);
    }
	//Setting private variables
	this->nameCity = city;
  	this->travelers = travelers;
  	this->tripDuration = duration;
  	main();
}

// This function contains the user-interaction. Will be called within the class constructor
void Lodging::main() {
    std::string hotelRating;
	int fixedHotelRating; //Fixed means that the variable has been checked for correct input
    std::cout << "Welcome to " << nameCity << "!" << std::endl;
    std::cout << "It is now time to book your hotels." << std::endl;
	std::cout << std::endl;
    std::cout << "What type of hotel would you like to book?" << std::endl;
    for (int i = 1; i <= 5; ++i) {
        std::cout << std::string(i, '*') << " " << i << "-star hotel (Enter " << i << ")." << std::endl;
    }

    std::cout << "Enter your selection: ";
    std::cin >> hotelRating;
	int intPassKey = 100;
	fixedHotelRating = errorChecking(hotelRating, intPassKey);

	std::cout << std::endl;
	if (cityName == "los angeles") {
		LA(fixedHotelRating);
	}

	if (cityName == "new york") {
		NYC(fixedHotelRating);
	}

	if (cityName == "london") {
		LDN(fixedHotelRating);
	}

	if (cityName == "paris") {
		PAR(fixedHotelRating);
	}

	if (cityName == "dubai") {
		DBX(fixedHotelRating);
	}

	if (cityName == "sydney") {
		SYD(fixedHotelRating);
	}

	if (cityName == "tokyo") {
		TYO(fixedHotelRating);
	}
}


void Lodging::LA(int rating) {
	// Using paralell arrays to store hotel names and hotel prices per each rating.
	std::vector<std::string> star1 = {"Regal Inn", "Economy Inn", "Willow Tree Inn", "Sea Breeze Inn", "Banana Bungalow West Hollywood"};
	std::vector<std::string> star2 = {"Antonio Hotel", "Los Angeles Inn & Suites", "City Center Hotel", "Value Inn Hollywood", "Valley Inn"};
	std::vector<std::string> star3 = {"LA Adventure Hotel", "All Star Inn", "Shelter Hotels", "Palihotel Melrose Avenue", "Sunrise Hotel San Pedro"};
	std::vector<std::string> star4 = {"The Biltmore Los Angeles", "Dream Hollywood", "SIXTY Beverly Hills", "Sofitel Los Angeles at Beverly Hills", "Hilton Los Angeles Culver City"};
	std::vector<std::string> star5 = {"Four Seasons Hotel", "1 Hotel West Hollywood", "The Beverly Hills Hotel", "Shutters on the Beach", "Beverly Wilshire"};
	std::vector<int> price1 = {89, 120, 97, 73, 60};
	std::vector<int> price2 = {58, 89, 77, 95, 90};
	std::vector<int> price3 = {85, 116, 86, 245, 111};
	std::vector<int> price4 = {160, 212, 285, 283, 205};
	std::vector<int> price5 = {926, 427, 1195, 632, 778};

	hotelSelection(star1, star2, star3, star4, star5, price1, price2, price3, price4, price5, rating);
}	


void Lodging::NYC(int rating) {
	// Using paralell arrays to store hotel names and hotel prices per each rating.
	std::vector<std::string> star1 = {"Bowery Grand Hotel", "Wood Spring Suites Linden", "West Side YMCA", "U.S Pacific Hotel", "Chelsea International Hotel"};
	std::vector<std::string> star2 = {"Queens Hotel", "Hotel St. James", "Sheridan Hotel", "Carlton Arms Hotel", "Red Carpet Inn Brooklyn"};
	std::vector<std::string> star3 = {"The Manhattan at Times Square", "45 Times Square Hotel", "Pod Times Square", "The Gregorian Hotel", "YOTEL NY Times Square"};
	std::vector<std::string> star4 = {"Millennium Hilton", "Warwick NY", "Nilton NY Times Square", "Hyatt Grand Central NY", "The Empire Hotel"};
	std::vector<std::string> star5 = {"The Times Square EDITION", "The Laghman", "The Knickerbocker", "The St. Regis NY", "The Bowery Hotel"};
	std::vector<int> price1 = {69, 97, 103, 119, 117};
	std::vector<int> price2 = {108, 109, 134, 87, 119};
	std::vector<int> price3 = {84, 133, 115, 137, 96};
	std::vector<int> price4 = {152, 133, 150, 161, 136};
	std::vector<int> price5 = {305, 672, 224, 820, 564};

	hotelSelection(star1, star2, star3, star4, star5, price1, price2, price3, price4, price5, rating);
}


void Lodging::LDN(int rating) {
	// Using paralell arrays to store hotel names and hotel prices per each rating.
	std::vector<std::string> star1 = {"Corbigoe Hotel", "Aquarius Hotel", "St. George Hotel", "Holly House Hotel LDN", "The London Hotel"};
	std::vector<std::string> star2 = {"Paramount Hotel", "Star Hotel", "Sheriff Hotel", "European Hotel", "Hyde Park Court Hotel"};
	std::vector<std::string> star3 = {"Sapphire Hotel LDN", "Rushmore Hotel", "Travelodge LDN", "King Solomon Hotel", "Zedwell Piccadilly Circus"};
	std::vector<std::string> star4 = {"Britannia International Hotel", "Hilton LDN Hyde Park", "The Crown LDN Hotel", "The Tower Hotel", "Merit Kensington Hotel"};
	std::vector<std::string> star5 = {"Bulgari Hotel", "The Ritz LDN", "Shangri-La The Shard", "Claridge's", "Rosewood LDN"};
	std::vector<int> price1 = {35, 47, 46, 57, 60};
	std::vector<int> price2 = {48, 64, 50, 63, 53};
	std::vector<int> price3 = {51, 61, 62, 52, 60};
	std::vector<int> price4 = {57, 158, 82, 148, 100};
	std::vector<int> price5 = {1114, 880, 663, 964, 614};

	hotelSelection(star1, star2, star3, star4, star5, price1, price2, price3, price4, price5, rating);
}


void Lodging::PAR(int rating) {
	// Using paralell arrays to store hotel names and hotel prices per each rating.
	std::vector<std::string> star1 = {"Victory Galou Hotel", "Hotel Ferney Republique", "Hotel Jarry", "Tiquetonne", "Hotel Bonsejour"};
	std::vector<std::string> star2 = {"Hotel de Paris Opera", "Hotel du Brabant", "Hotel Eiffel Kensington", "Hotel Europe BLV", "Hotel Altona"};
	std::vector<std::string> star3 = {"Timhotel Tour Eiffel", "Hotel Astoria - Astotel", "Britannique Hotel", "Hotel Elysees Union", "Hotel Rivieira Paris"};
	std::vector<std::string> star4 = {" Hotel La Comtesse Tour Eiffel", "Hotel Gustave", "Hotel Le Walt by Inwood", "Hilton Paris Opera", "Da Vinci Hotel & Spa"};
	std::vector<std::string> star5 = {"Hotel Plaza Athenee", "Ritz Paris", "Shangri-La Paris", "La Reserve", "Le Bristol Paris"};
	std::vector<int> price1 = {70, 70, 81, 121, 82};
	std::vector<int> price2 = {82, 50, 137, 54, 88};
	std::vector<int> price3 = {129, 107, 206, 175, 101};
	std::vector<int> price4 = {271, 159, 346, 312, 177};
	std::vector<int> price5 = {1932, 1872, 1345, 1887, 1826};

	hotelSelection(star1, star2, star3, star4, star5, price1, price2, price3, price4, price5, rating);
}


void Lodging::DBX(int rating) {
	// Using paralell arrays to store hotel names and hotel prices per each rating.
	std::vector<std::string> star1 = {"Africana Hotel", "Grand Square Hotel", "Trans World Hotel", "Delmon Palace Hotel", "Maaeen Hotel"};
	std::vector<std::string> star2 = {"AI Khoory Inn Hotel", "Royalton Hotel DBX", "Saffron Hotel", "Quenn's Hotel", "President Hotel"};
	std::vector<std::string> star3 = {"Kings Park Hotel", "Orchid Hotel", "Rove Expo City", "Grand Astoria Hotel", "Pinoy World"};
	std::vector<std::string> star4 = {"Emirates Grand Hotel", "Royal Ascot", "Aavri Hotel", "Raintree rolla", "Hues Boutique Hotel"};
	std::vector<std::string> star5 = {"Fairmont Dubai", "Grand Millennium Dubai", "Conrad Dubai", "Palazzo Versace Dubai", "Paramount Hotel"};
	std::vector<int> price1 = {26, 26, 28, 41, 30};
	std::vector<int> price2 = {29, 28, 29, 35, 37};
	std::vector<int> price3 = {26, 23, 37, 24, 23};
	std::vector<int> price4 = {29, 33, 29, 34, 30};
	std::vector<int> price5 = {112, 71, 164, 235, 115};

	hotelSelection(star1, star2, star3, star4, star5, price1, price2, price3, price4, price5, rating);
}


void Lodging::SYD(int rating) {
	// Using paralell arrays to store hotel names and hotel prices per each rating.
	std::vector<std::string> star1 = {"Lido Suites", "The Pod Sydney", "Trademark Hostel Sydney", "Palms Hotel", "The Grand Hotel"};
	std::vector<std::string> star2 = {"Highfield Private Hotel", "Sydney Central Inn", "Venus by the Harbour", "Bridgeview Hotel", "Willey Park Hotel"};
	std::vector<std::string> star3 = {"Sydney Boutique Hotel", "Grandville Hotel", "Palms Hotel", "The Palace Hotel", "The Ociddental Hotel"};
	std::vector<std::string> star4 = {"Rydges Sydney Central", "Penshurst Hotel", "The Great Southern Hotel", "Megaboon City Hotel", "Crown Hotel Surry Hills"};
	std::vector<std::string> star5 = {"Shangri-La Sydnet", "Hilton Sydney", "Park Hyatt Sydney", "Four Seasons Hotel Sydney", "The Langham"};
	std::vector<int> price1 = {113, 51, 64, 89, 85};
	std::vector<int> price2 = {62, 73, 56, 66, 68};
	std::vector<int> price3 = {82, 61, 84, 70, 76};
	std::vector<int> price4 = {126, 76, 142, 94, 101};
	std::vector<int> price5 = {211, 170, 969, 249, 377};

	hotelSelection(star1, star2, star3, star4, star5, price1, price2, price3, price4, price5, rating);
}


void Lodging::TYO(int rating) {
	// Using paralell arrays to store hotel names and hotel prices per each rating.
	std::vector<std::string> star1 = {"Ace Inn Shinjuku", "New Koiwa 310", "Capsulre Inn Kinshichou", "Kimi Ryokan", "Imano Tokyo Ginza Hostel"};
	std::vector<std::string> star2 = {"The Global Hotel Tokyo", "Little Japan", "Rex Inn Kawasaki", "Hotel AmethysT", "Sakura Hotel Nippori"};
	std::vector<std::string> star3 = {"Sun Hotel", "Hotel Cue Sea Stork", "Hotel Emisia", "Shinagawa Prince Hotel", "Hotel Tavinos Asakusa"};
	std::vector<std::string> star4 = {"Hotel East 21 Tokyo", "Hotel Gracery Shinjuku", "Asakusa View Hotel", "Tokyo Prince Hotel", "Kyatt Regency Tokyo"};
	std::vector<std::string> star5 = {"Aman Tokyo", "Mandarin Oriental", "Hilton Tokyo", "Imperial Hotel Tokyo", "The Peninsula Tokyo"};
	std::vector<int> price1 = {29, 47, 43, 44, 67};
	std::vector<int> price2 = {47, 38, 37, 48, 45};
	std::vector<int> price3 = {37, 42, 54, 120, 70};
	std::vector<int> price4 = {79, 122, 153, 130, 305};
	std::vector<int> price5 = {1497, 877, 308, 310, 1040};

	hotelSelection(star1, star2, star3, star4, star5, price1, price2, price3, price4, price5, rating);
}


// This function prints the hotels based on the rating and interacts with the user
void Lodging::hotelSelection(std::vector<std::string> star1, std::vector<std::string> star2, std::vector<std::string> star3, std::vector<std::string> star4, std::vector<std::string> star5, std::vector<int> price1, std::vector<int> price2, std::vector<int> price3, std::vector<int> price4, std::vector<int> price5, int rating)  {
	std::string hotelChoice;
	int checkedHotelChoice;

	while (true) {
		// Printing hotel and prices based on rating
		switch(rating) {
		case 1:
			printHotelsandPrices(star1, price1, rating);
			break;

		case 2:
			printHotelsandPrices(star2, price2, rating);
			break;

		case 3:
			printHotelsandPrices(star3, price3, rating);
			break;

		case 4:
			printHotelsandPrices(star4, price4, rating);
			break;

		case 5:
			printHotelsandPrices(star5, price5, rating);
			break;
		}
		// Giving the user the option to choose a hotel or to go back and choose a different rating
		std::cout << "Choose your hotel or enter 'b' to go back and choose another rating: ";
		std::cin >> hotelChoice;
		int charIntPassKey = 25;
		int intPassKey = 100;
		checkedHotelChoice = errorChecking(hotelChoice, charIntPassKey);

		std::cout << std::endl;
		// Prompting the user to enter a new hotel rating
		if (checkedHotelChoice == -1) {
			std::cout << "Please enter the new hotel rating: ";
			std::cin >> hotelChoice;
			rating = errorChecking(hotelChoice, intPassKey);
		}
		else {
			break;
		}
	}
    this->rating = rating;

	// Setting hotel name and total cost based on rating
	switch(rating) {
		case 1:
			setHotelNameAndTotalCost(star1, price1, checkedHotelChoice);
			break;

		case 2:
			setHotelNameAndTotalCost(star2, price2, checkedHotelChoice);
			break;

		case 3:
			setHotelNameAndTotalCost(star3, price3, checkedHotelChoice);
			break;

		case 4:
			setHotelNameAndTotalCost(star4, price4, checkedHotelChoice);
			break;

		case 5:
			setHotelNameAndTotalCost(star5, price5, checkedHotelChoice);
			break;
	}
}


// This supportive function prints the hotels and prices based on rating
void Lodging::printHotelsandPrices(std::vector<std::string> hotels, std::vector<int> prices, int rating) {
	std::cout << "The hotels rated as " << rating << "-star in " << nameCity << " are:" << std::endl;
	std::cout << std::left << std::setw(45) << "Hotels" << "|" << " Price" << std::endl;
	for (int i = 0; i < 5; ++i) {
		std::cout << i + 1 << ". " << std::left << std::setw(42) << hotels.at(i) << "|" << " $" << prices.at(i) << std::endl;
	}
}


// This function sets the private variables with their respective values
void Lodging::setHotelNameAndTotalCost(std::vector<std::string> hotels, std::vector<int> prices, int hotelChoice) {
	this->hotelName = hotels.at(hotelChoice - 1);
	this->hotelsCost = prices.at(hotelChoice - 1) * travelers * tripDuration;
	return;
}


/*This function checks whether the user input is correct or not.
It uses passkeys to differentiate what to check for.
For example, if passKey is 100, it will check if the input is a integer or not.
Similarly, if passKey is 25, it will check if the input is either an int or a char.
int values should be between 1-5 and char should only be 'b'
*/
int Lodging::errorChecking(std::string valueToCheck, int passKey) {
  int returnValue;
  if (passKey == 100) {
	while (true) {
			bool flag = true;
			for (char ch : valueToCheck) {
				if (!isdigit(ch)) {
					flag = false;
					break;
				}
			}
			if (flag) {
				returnValue = std::stoi(valueToCheck);
				if (returnValue >= 1 && returnValue <= 5) {
					return returnValue;
				}
			}
			std::cout << "Invalid input. Please try again: ";
			std::cin >> valueToCheck;
		}
	} else if (passKey == 50) {
		while (true) {
			if (valueToCheck == "b") {
				return -1;
			}
			std::cout << "Invalid input. Please try again: ";
			std::cin >> valueToCheck;
		}
	} else if (passKey == 25) {
		while (true) {
			bool flag = true;
			for (char ch : valueToCheck) {
				if (!isdigit(ch) && ch != 'b') {
					flag = false;
					break;
      			}
    		}
			if (flag) {
				if (valueToCheck == "b") {
					return -1;
				}
				returnValue = std::stoi(valueToCheck);
				if (returnValue >= 1 && returnValue <= 5) {
					return returnValue;
				}
  			}
			else {
    			std::cout << "Invalid input. Please try again: ";
    			std::cin >> valueToCheck;
				}
			std::cout << "Invalid input. Please try again: ";
  			std::cin >> valueToCheck;

	}

	}

	return 0;
}