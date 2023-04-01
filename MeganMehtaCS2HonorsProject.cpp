//============================================================================
// Name        : MeganMehtaCS2HonorsProject.cpp
// Author      : Megan Mehta
// Version     : 1
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>
#include "Flights.hpp"
#include "Hotels.hpp"
#include "Payment.hpp"
using namespace std;
// the number of chars for each private member of Flights
const int depLocChars = 3;
const int arrLocChars = 3;
const int depTimeChars = 4;
const int depDayChars = 3;
const int depMonthChars = 3;
const int depDateChars = 2;
const int depYearChars = 4;
const int arrTimeChars = 4;
const int arrDayChars = 3;
const int arrMonthChars = 3;
const int arrDateChars = 2;
const int arrYearChars = 4;
const int rowNumChars = 2;
const int seatNumChars = 2;
const int boardGroupChars = 1;
const int airlineNameChars = 20;
const int flightNumChars = 2;
const int gateNumChars = 2;
const int ticketCostChars = 3;

// the number of chars for each private member of Hotels
const int milesFromAirportChars = 3;
const int amenitiesChars = 30;
const int checkinTimeChars = 4;
const int checkoutTimeChars = 4;
const int starRatingChars = 3;
const int hotelCostPerNightChars = 3;

// total number of characters for each record in flightsAvailable.txt
const int flightClassTotalChars = 70;
const int MAX_NUM_FLIGHT_RECORDS = 20;		// max number of flight records in flightsAvailable.txt (real txt file has fewer)
const int MAX_NUM_HOTEL_RECORDS = 65;		// max num of hotel records in hotelsAvailable.txt (real txt file has fewer)

int main()
{
	string entireRecord = "";

	// variables that will hold data for each category/line in flightsAvailable.txt
	string readDepLoc = "";
	string readArrLoc = "";
	string readDepTime = "";
	string readDepDay = "";
	string readDepMonth = "";
	string readDepDate = "";
	string readDepYear = "";
	string readArrTime = "";
	string readArrDay = "";
	string readArrMonth = "";
	string readArrDate = "";
	string readArrYear = "";
	string readRowNum = "";
	string readSeatNum = "";
	string readBoardGroup = "";
	string readAirlineName = "";
	string readFlightNum = "";
	string readGateNum = "";
	float readTicketCost = 0.0;

	// variables that will hold data for each category/line in hotelsAvailable.txt
	float readMilesFromAirport = 0.0;
	string readAmenities = "";
	string readCheckinTime = "";
	string readCheckoutTime = "";
	float readStarRating = 0;
	float readHotelCostPerNight = 0.0;

	int numFlights = 0;			// counter for the number of flights available
	Flights * flightsPointer[MAX_NUM_FLIGHT_RECORDS];
	int numHotels = 0; 			// count for the number of hotels available
	Hotels * hotelsPointer[MAX_NUM_HOTEL_RECORDS];
	ifstream inFile;
	ifstream inFile2;
	int flightChoice = 0;
	char hotelChoice;
	int selectHotel = 0;
	int numHotelDays = 0;

	inFile.open("/Users/meganmehta/Desktop/flightsAvailable.txt");
	inFile2.open("/Users/meganmehta/Desktop/hotelsAvailable.txt");
	if(!(inFile.is_open() or inFile2.is_open()))
	{
		cout << "The file 'flightsAvailble.txt' failed to open.\nProgram quit." << endl;
		exit(0);
	}

	// setting all elements in pointer array flightsPointer to nullptr
	for(int i = 0; i < MAX_NUM_FLIGHT_RECORDS; i++)
	{
		flightsPointer[i] = nullptr;
	}

	getline(inFile, entireRecord);		// gets initial flight record
	while(!inFile.eof())
	{
		readDepLoc = entireRecord.substr(0, depLocChars);
		readArrLoc = entireRecord.substr(depLocChars, arrLocChars);
		readDepTime = entireRecord.substr(depLocChars + arrLocChars, depTimeChars);
		readDepDay = entireRecord.substr(depLocChars + arrLocChars + depTimeChars, depDayChars);
		readDepMonth = entireRecord.substr(depLocChars + arrLocChars + depTimeChars + depDayChars, depMonthChars);
		readDepDate = entireRecord.substr(depLocChars + arrLocChars + depTimeChars + depDayChars + depMonthChars, depDateChars);
		readDepYear = entireRecord.substr(depLocChars + arrLocChars + depTimeChars + depDayChars + depMonthChars + depDateChars, depYearChars);
		readArrTime = entireRecord.substr(depLocChars + arrLocChars + depTimeChars + depDayChars + depMonthChars + depDateChars + depYearChars, arrTimeChars);
		readArrDay = entireRecord.substr(depLocChars + arrLocChars + depTimeChars + depDayChars + depMonthChars + depDateChars + depYearChars + arrTimeChars, arrDayChars);
		readArrMonth = entireRecord.substr(depLocChars + arrLocChars + depTimeChars + depDayChars + depMonthChars + depDateChars + depYearChars + arrTimeChars + arrDayChars, arrMonthChars);
		readArrDate = entireRecord.substr(depLocChars + arrLocChars + depTimeChars + depDayChars + depMonthChars + depDateChars + depYearChars + arrTimeChars + arrDayChars + arrMonthChars, arrDateChars);
		readArrYear = entireRecord.substr(depLocChars + arrLocChars + depTimeChars + depDayChars + depMonthChars + depDateChars + depYearChars + arrTimeChars + arrDayChars + arrMonthChars + arrDateChars, arrYearChars);
		readRowNum = entireRecord.substr(depLocChars + arrLocChars + depTimeChars + depDayChars + depMonthChars + depDateChars + depYearChars + arrTimeChars + arrDayChars + arrMonthChars + arrDateChars + arrYearChars, rowNumChars);
		readSeatNum = entireRecord.substr(depLocChars + arrLocChars + depTimeChars + depDayChars + depMonthChars + depDateChars + depYearChars + arrTimeChars + arrDayChars + arrMonthChars + arrDateChars + arrYearChars + rowNumChars, seatNumChars);
		readBoardGroup = entireRecord.substr(depLocChars + arrLocChars + depTimeChars + depDayChars + depMonthChars + depDateChars + depYearChars + arrTimeChars + arrDayChars + arrMonthChars + arrDateChars + arrYearChars + rowNumChars + seatNumChars, boardGroupChars);
		readAirlineName = entireRecord.substr(depLocChars + arrLocChars + depTimeChars + depDayChars + depMonthChars + depDateChars + depYearChars + arrTimeChars + arrDayChars + arrMonthChars + arrDateChars + arrYearChars + rowNumChars + seatNumChars + boardGroupChars, airlineNameChars);
		readFlightNum = entireRecord.substr(depLocChars + arrLocChars + depTimeChars + depDayChars + depMonthChars + depDateChars + depYearChars + arrTimeChars + arrDayChars + arrMonthChars + arrDateChars + arrYearChars + rowNumChars + seatNumChars + boardGroupChars + airlineNameChars, flightNumChars);
		readGateNum = entireRecord.substr(depLocChars + arrLocChars + depTimeChars + depDayChars + depMonthChars + depDateChars + depYearChars + arrTimeChars + arrDayChars + arrMonthChars + arrDateChars + arrYearChars + rowNumChars + seatNumChars + boardGroupChars + airlineNameChars +flightNumChars, gateNumChars);
		readTicketCost = stof(entireRecord.substr(depLocChars + arrLocChars + depTimeChars + depDayChars + depMonthChars + depDateChars + depYearChars + arrTimeChars + arrDayChars + arrMonthChars + arrDateChars + arrYearChars + rowNumChars + seatNumChars + boardGroupChars + airlineNameChars + flightNumChars + gateNumChars, ticketCostChars));

		// records data in Flights object, which is dynamically allocated by an element (pointer) in a pointer array
		flightsPointer[numFlights] = new Flights(readDepLoc, readArrLoc, readDepTime, readDepDay, readDepMonth, readDepDate, readDepYear, readArrTime, readArrDay, readArrMonth, readArrDate, readArrYear, readRowNum, readSeatNum, readBoardGroup, readAirlineName, readFlightNum, readGateNum, readTicketCost);
			// decided to use a pointer array to manage Flights objects because I wanted to use dyn alloc so that I can pass data through the constructor instead of creating setters, which would have been painful because there are SO MANY data fields.
		flightsPointer[numFlights]->nextFlight = flightsPointer[numFlights + 1];		// linking first node (Flights object managed by pointer array) to next node (the next Flight Object in the flightsPointer array)
			// this links all of the Flight objects managed by the pointer array together

		getline(inFile, entireRecord);
		numFlights++;
	}

	// displays all available flights
	cout << "\t  LOCATION\tTIME  DAY  DATE  MONTH  YEAR" << endl;
	for(int i = 0; i < numFlights; i++)
	{
		cout << (i+1) << ".\t" << "Departure: " << flightsPointer[i]->getDepLoc() << "  " << flightsPointer[i]->getDepTime() << "   " << flightsPointer[i]->getDepDay() << "   " << flightsPointer[i]->getDepDate() << "   " << flightsPointer[i]->getDepMonth() << "   " << flightsPointer[i]->getDepYear()
				<< "\n\t " << "Arrival: " << flightsPointer[i]->getArrLoc() << "  " << flightsPointer[i]->getArrTime() << "   " << flightsPointer[i]->getArrDay() << "   " << flightsPointer[i]->getArrDate() << "   " << flightsPointer[i]->getArrMonth() << "   " << flightsPointer[i]->getArrYear() << endl;
	}
	// asks user to select a flight, validates input
	cout << "Please select a flight: ";
	cin >> flightChoice;
	while(flightChoice < 0 or flightChoice > numFlights)
	{
		cout << "ERROR: That is an invalid flight choice. Please re-select a new fight: ";
		cin >> flightChoice;
	}

	// asks user if they want to book a flight, validates input
	cout << "Great! Your flight ticket costs: $" << flightsPointer[flightChoice + 1]->getTicketCost() << "\nWould you like to purchase a hotel room with your flight? (y for yes, n for no): ";
	cin >> hotelChoice;
	while(!(hotelChoice == 'n' or 'N' or 'y' or "Y"))
	{
		cout << "ERROR: That is an invalid choice. Please re-enter a new choice" << endl;
		cin >> hotelChoice;
	}
	if(hotelChoice == 'y' or 'Y')
	{
		getline(inFile2, entireRecord);
		readArrLoc = entireRecord.substr(0, arrLocChars);
		cout << "ARRIVAL LOCATION  MILES FROM AIRPORT  AMENITIES\t\t\t\tCHECK-IN TIME  CHECK-OUT TIME  STAR RATING  $COST" << endl;
		while(!inFile2.eof())
		{
			// iterate through all available hotels int txt file until it finds a matching arrival location
			if(readArrLoc == flightsPointer[flightChoice - 1]->getArrLoc())
			{
				readMilesFromAirport = stof(entireRecord.substr(arrLocChars, milesFromAirportChars));
				readAmenities = entireRecord.substr(arrLocChars + milesFromAirportChars, amenitiesChars);
				readCheckinTime = entireRecord.substr(arrLocChars + milesFromAirportChars + amenitiesChars, checkinTimeChars);
				readCheckoutTime = entireRecord.substr(arrLocChars + milesFromAirportChars + amenitiesChars + checkinTimeChars, checkoutTimeChars);
				readStarRating = stof(entireRecord.substr(arrLocChars + milesFromAirportChars + amenitiesChars + checkinTimeChars + checkoutTimeChars, starRatingChars));
				readHotelCostPerNight = stof(entireRecord.substr(arrLocChars + milesFromAirportChars + amenitiesChars + checkinTimeChars + checkoutTimeChars + starRatingChars, hotelCostPerNightChars));

				// record data in a Hotel object
				hotelsPointer[numHotels] = new Hotels(readArrLoc, readMilesFromAirport, readAmenities, readCheckinTime, readCheckoutTime, readStarRating, readHotelCostPerNight);
				hotelsPointer[numHotels]->nextHotel = hotelsPointer[numHotels + 1];		// creating a linked list
				numHotels++;

				// display the available hotel
				cout << numHotels << "\t" << readArrLoc << "\t\t" << readMilesFromAirport << "\t\t" << readAmenities << "\t" << readCheckinTime << "\t" << readCheckoutTime << "\t" << readStarRating << "\t" << readHotelCostPerNight << endl;
			}
			getline(inFile2, entireRecord);
			readArrLoc = entireRecord.substr(0, arrLocChars);
		}

		cout << "Please make a hotel selection: ";
		cin >> selectHotel;
		while(selectHotel < 1 or selectHotel > numHotels)
		{
			cout << "ERROR: That is an invalid hotel selection. Please re-enter a hotel selection: ";
			cin >> selectHotel;
		}
		cout << "How many days would you like to stay?" << endl;
		cin >> numHotelDays;
		while(numHotelDays < 1)
		{
			cout << "ERROR: You must stay at the hotel for at least one day. Please re-enter how many days you would like to stay: " << endl;
			cin >> numHotelDays;
		}
		hotelsPointer[selectHotel - 1]->setNumNights(numHotelDays);			// sets the number of days the user will stay
		flightsPointer[flightChoice - 1]->hotelChoice = hotelsPointer[selectHotel - 1];		// creates linked list between chosen flight and chosen hotel
		Payment p1;			// instantiates a new Payment class object
		hotelsPointer[selectHotel - 1]->payment = &p1;		// completes linked list of flight, hotel, and payment
		p1.setFlightTicketCost(flightsPointer[flightChoice - 1]->getTicketCost());		// sets flight ticket cost in payment class
		p1.setHotelRoomCost(hotelsPointer[selectHotel - 1]->getHotelCostPerNight() * hotelsPointer[selectHotel - 1]->getNumNights());	// sets hotel cost in payment class by multiplying cost per night and number of nights
		p1.calcPayment();		// calls function that calculates total payment (with taxes + fees) and processes credit card info
	}
	else
	{
		Payment p1;
		flightsPointer[flightChoice - 1]->payment = &p1;			// comples linked list of only flight and payment class objects
		p1.setFlightTicketCost(flightsPointer[flightChoice - 1]->getTicketCost());
		p1.calcPayment();		// calls function that calculates total payment (with taxes + fees) and processes credit card info
		cout << "Success! Thank you for using Megan Mehta's Flight-Hotel Booking System. Enjoy your vacation!" << endl;
	}
	return 0;
}
