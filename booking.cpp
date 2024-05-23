#include "booking.h"
#include "lodging.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdexcept>
#include <limits>

#include "trip.h"

//Defining constructor and setting private variables.
void Booking::createTrip() {
  std::string departingCity, destinationCity, departTimeWord;
  int travelers, duration, departTime;
  std::string answer;

  // get input from user about their departing city, do so until they enter a valid departing city
  do {
    try {
        std::cout << "Enter departing city: ";
        std::getline(std::cin, departingCity);
        // convert input to lowercase, so we are able to compare it to the valid input options
        for (auto& x : departingCity) x = tolower(x);
        // if valid input
        if (departingCity == "los angeles" || departingCity == "new york" ||
            departingCity == "london" || departingCity == "paris" ||
            departingCity == "dubai" || departingCity == "sydney" ||
            departingCity == "tokyo") {
        break;
        // if invalid input
        } else {
            throw std::runtime_error("Invalid departing City. Please enter a valid departing City.");
        }
    } catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl;
        do {
            // give the user the option to see the list of valid departing cities
            std::cout << "Would you like to see a list of valid departing cities "
                        "cities? (yes or no): ";
            std::cin >> answer;
            std::cin.ignore(1000, '\n');
            // if they do want to see the list
            if (answer == "yes") {
            std::cout << "Los Angeles, New York, London, Paris, Dubai, Sydney, "
                        "Tokyo"
                        << std::endl;
            break;
            // if they do not
            } else if (answer == "no") {
            break;
            } else {
            // if invalid input, ask again
            std::cout << "Invalid input" << std::endl;
            }
        } while (true);
    }

  } while (true);
  // ask the user for their desired destination city until they enter a valid option
  do {
    try {
        // ask for desired destination city
        std::cout << "Enter destination city: ";
    std::getline(std::cin, destinationCity);
    // convert input to lowercase to compare to valid options
    for (auto& x : destinationCity) x = tolower(x);
        // if the user enters a valid destination City
        if ((destinationCity == "los angeles" || destinationCity == "new york" ||
            destinationCity == "london" || destinationCity == "paris" ||
            destinationCity == "dubai" || destinationCity == "sydney" ||
            destinationCity == "tokyo") && destinationCity != departingCity) {
        break;
        // if invalid destination city entered, let the user know
        } else { throw std::runtime_error("Invalid destination City. Please enter a valid destination City."); }
    } catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl;
        // ask the user if they want a reminder as to the valid destination cities available
        do {
            std::cout << "Would you like to see a list of destination "
                        "cities? (yes or no): ";
            std::cin >> answer;
            std::cin.ignore(1000, '\n');
            if (answer == "yes") {
            // if they do want a reminder
            std::cout << "Los Angeles, New York, London, Paris, Dubai, Sydney, "
                        "Tokyo" << " Except: " << departingCity
                        << std::endl;
            break;
            // if they do not want a reminder
            } else if (answer == "no") {
            break;
            } else {
            // if they enter an invalid input, repeat the function
            std::cout << "Invalid input" << std::endl;
            }
        } while (true);
    }
  } while (true);

  // ask the user what time they want their flight to be, 3 options.
  do {
    std::cout << "Enter departure time (morning, afternoon or evening): ";
    std::getline(std::cin, departTimeWord);
    // convert to lowercase so we can compare the options
    for (auto& x : departTimeWord) x = tolower(x);

    // if the user inputs 'morning', departTime = 1, this is used in the flight class
    if (departTimeWord == "morning") {
      departTime = 1;
      // break the function, valid input
      break;
      // if the user inputs 'afternoon', departTime = 2, this is used in the flight class
    } else if (departTimeWord == "afternoon") {
      departTime = 2;
      // break the function, valid input
      break;
      // if the user inputs 'evening', departTime = 3, this is used in the flight class
    } else if (departTimeWord == "evening") {
      departTime = 3;
      // break the function, valid input
      break;
      // if the user enters an invalid input, let them know and the function repeats
    } else {
      std::cout << "Invalid time of day" << std::endl;
    }
  } while (true);

  std::string input1;
  bool isInteger1;

  // get number of travelers from user, this is used for both the Flight and Lodging classes
  do {
    std::cout << "Enter number of travelers: ";
    std::getline(std::cin, input1);

    isInteger1 = true;
    for (char c : input1) {
      // if the user enters a non int, set isInteger1 to false, so the function runs again until they enter a valid input
      if (!isdigit(c)) {
        isInteger1 = false;
        break;
      }
    }

    if (!isInteger1) {
      // message to inform the user they entered an invalid input
      std::cout << "Invalid input. Please enter a valid integer." << std::endl;
    }
  } while (!isInteger1);

  travelers = std::stoi(input1);

  std::string input2;
  bool isInteger2;

  // get duration of stay from the user, this is used in the Lodging class
  do {
    std::cout << "Enter duration of stay (number of days): ";
    std::getline(std::cin, input2);

    isInteger2 = true;
    for (char c : input2) {
      // if the user enters a non int, set isInteger2 to false, so the function is run again
      if (!isdigit(c)) {
        isInteger2 = false;
        break;
      }
    }
    // If the user enters a non int, ask again
    if (!isInteger2) {
      std::cout << "Invalid input. Please enter a valid integer." << std::endl;
    }
  } while (!isInteger2);

  duration = std::stoi(input2);

  std::string tripName;

  std::cout << std::endl;
  // request a name for the trip the user just created
  std::cout << "Enter name for the trip: ";
  std::getline(std::cin, tripName);
  std::cout << std::endl;
  // request how many travelers
  std::cout << "travelers: " << travelers << std::endl;

  // create instances of the Flight and Lodging classes to allow the user to finalise booking their accomodation and flights
  Flight *departingFlight = new
      Flight(departingCity, destinationCity, departTime, travelers);
  Flight *returningFlight = new
      Flight(destinationCity, departingCity, departTime, travelers);
  Lodging *lodge = new Lodging(destinationCity, travelers, duration);

  // set private variables
  Trip *t = new Trip(departingFlight, returningFlight, lodge, tripName);
  this->departingCity = departingCity;
  this->destinationCity = destinationCity;
  this->departTime = departTime;
  this->travelers = travelers;
  this->duration = duration;  
  
  this->trips.push_back(t);
}
// if the user wants to delete a trip
void Booking::deleteTrip() {
    // ask the user which trip they want to delete, asking for the number of the trip they want to delete, enter '-1' if they want to exit
    std::cout << "Which trip do you want to delete? (-1 means exit) " << static_cast<int>(this->trips.size());
    for (int i = 0; i < static_cast<int>(this->trips.size()); i++) { std::cout << "\n" << i << ": " << this->trips.at(i)->getName(); }
    do {
        int tripIndex;
        try {
            std::cout << "\nInput: ";            
            std::cin >> tripIndex;
            std::cin.ignore(1000, '\n');
            if (tripIndex > static_cast<int>(this->trips.size()) - 1 || tripIndex < -1) { throw std::runtime_error("e"); }
            if (tripIndex == -1) { break; }
            // delete trip
            std::cout << "Deleted " << this->trips.at(tripIndex)->getName() << std::endl;
            this->trips.erase(trips.begin() + tripIndex);
            break;
        } catch (...) {
            std::cout << "Invalid Input. Please input a number from 0 to " << static_cast<int>(this->trips.size()) - 1 << std::endl;
        }
    } while (true);
}
// call the printTripStats function and output the details of the trips
void Booking::viewTrips() {
    for (int i = 0; i < static_cast<int>(trips.size()); i++) {
        trips.at(i)->printTripStats();
        std::cout << "\n" << std::endl;
    }
}

// Ask the user their intentions on the action they want to perform, until they exit the program (enter 0)
void Booking::start() {
    bool programOn = true;
    while (programOn) {
        int input = 0;
        do {
            try {
                // give the user the option to create, view or delete a trip. Also give the option to exit the program
                std::cout << "Do you want to (1) create trip, (2) view trips, (3) delete trip, or (0) exit program? ";
                std::cin >> input;
                std::cin.ignore(1000, '\n');
                // if the user enters an invalid input
                if (input > 3 || input < 0) { throw std::runtime_error("Invalid Input. Enter an Integer between 0 and 3."); }
                break;
            } catch (std::runtime_error &e) {
                std::cout << e.what() << std::endl;
            } catch (...) {
                std::cout << "Invalid Input. Enter an Integer between 1 and 3." << std::endl;
            }
        } while (true);

        // perform a certain action, depending on what the user inputs
        switch (input) {
            // user wants to create a trip
            case 1:
                createTrip();
                break;
            // user wants to view the trips
            case 2:
                viewTrips();
                break;
            // user wants to delete a trip
            case 3:
                deleteTrip();
                break;
            // user entered '0', exit the program
            default:
                programOn = false;
        }
    }
}
