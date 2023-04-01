/*
 * userFlight.hpp
 *
 *  Created on: Mar 11, 2021
 *      Author: meganmehta
 */

#ifndef HOTELS_HPP_
#define HOTELS_HPP_
#include <iostream>
#include <string>
#include "Payment.hpp"
using namespace std;
// stores data for the flight the user selects
class Hotels
{
public:
	Hotels * nextHotel;
	Payment * payment;
	Hotels(string readArrLoc, float readMilesFromAirport, string readAmenities, string readCheckinTime, string readCheckoutTime, float readStarRating, float readHotelCostPerNight)
	{
		arrLoc = readArrLoc;
		milesFromAirport = readMilesFromAirport;
		amenities = readAmenities;
		checkinTime = readCheckinTime;
		checkoutTime = readCheckoutTime;
		starRating = readStarRating;
		hotelCostPerNight = readHotelCostPerNight;
	}

	// getters (no setters because we are using the constructor as a setter)
	string getArrLoc()
	{
		return arrLoc;
	}
	float getMilesFromAirport()
	{
		return milesFromAirport;
	}
	string getAmenities()
	{
		return amenities;
	}
	string getCheckinTime()
	{
		return checkinTime;
	}
	string getCheckoutTime()
	{
		return checkoutTime;
	}
	float getStarRating()
	{
		return starRating;
	}
	float getHotelCostPerNight()
	{
		return hotelCostPerNight;
	}
	int getNumNights()
	{
		return numNights;
	}

	// setter for number of nights at the hotel
	void setNumNights(int input)
	{
		numNights = input;
	}
private:
	string arrLoc = "";
	float milesFromAirport = 0.0;
	string amenities = "";
	string checkinTime = "";
	string checkoutTime = "";
	float starRating = 0.0;
	float hotelCostPerNight = 0.0;
	int numNights = 0;

	float totalHotelCost = 0.0;
};

#endif /* HOTELS_HPP_ */
