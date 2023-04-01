/*
 * Flights.hpp
 *
 *  Created on: Mar 11, 2021
 *      Author: meganmehta
 */

#ifndef FLIGHTS_HPP_
#define FLIGHTS_HPP_
#include <iostream>
#include <string>
#include "Hotels.hpp"
#include "Payment.hpp"
// stores data for ALL flights from flightsAvailable.txt
class Flights
{
public:
	Flights * nextFlight;
	Hotels * hotelChoice;
	Payment * payment;

	// inline function declarations because I felt lazy
	// constructor
	Flights(string readDepLoc, string readArrLoc, string readDepTime, string readDepDay, string readDepMonth, string readDepDate, string readDepYear, string readArrTime, string readArrDay, string readArrMonth, string readArrDate, string readArrYear, string readRowNum, string readSeatNum, string readBoardGroup, string readAirlineName, string readFlightNum, string readGateNum, float readTicketCost)
	{
		depLoc = readDepLoc;
		arrLoc = readArrLoc;
		depTime = readDepTime;
		depDay = readDepDay;
		depMonth = readDepMonth;
		depDate = readDepDate;
		depYear = readDepYear;
		arrTime = readArrTime;
		arrDay = readArrDay;
		arrMonth = readArrMonth;
		arrDate = readArrDate;
		arrYear = readArrYear;
		rowNum = readRowNum;
		seatNum = readSeatNum;
		boardGroup = readBoardGroup;
		airlineName = readAirlineName;
		flightNum = readFlightNum;
		gateNum = readGateNum;
		ticketCost = readTicketCost;

	}

	string getDepLoc()
	{
		return depLoc;
	}
	string getArrLoc()
	{
		return arrLoc;
	}
	string getDepTime()
	{
		return depTime;
	}
	string getDepDay()
	{
		return depDay;
	}
	string getDepMonth()
	{
		return depMonth;
	}
	string getDepDate()
	{
		return depDate;
	}
	string getDepYear()
	{
		return depYear;
	}
	string getArrTime()
	{
		return arrTime;
	}
	string getArrDay()
	{
		return arrDay;
	}
	string getArrMonth()
	{
		return arrMonth;
	}
	string getArrDate()
	{
		return arrDate;
	}
	string getArrYear()
	{
		return arrYear;
	}
	string getRowNum()
	{
		return rowNum;
	}
	string getSeatNum()
	{
		return seatNum;
	}
	string getBoardGroup()
	{
		return boardGroup;
	}
	string getAirlineName()
	{
		return airlineName;
	}
	string getFlightNum()
	{
		return flightNum;
	}
	string getGateNum()
	{
		return gateNum;
	}
	float getTicketCost()
	{
		return ticketCost;
	}

private:
	string depLoc;
	string arrLoc;
	string depTime;
	string depDay;
	string depMonth;
	string depDate;
	string depYear;
	string arrTime;
	string arrDay;
	string arrMonth;
	string arrDate;
	string arrYear;
	string rowNum;
	string seatNum;
	string boardGroup;
	string airlineName;
	string flightNum;
	string gateNum;
	float ticketCost;
};


#endif /* FLIGHTS_HPP_ */
