/*
 * Payment.hpp
 *
 *  Created on: Mar 11, 2021
 *      Author: meganmehta
 */

#ifndef PAYMENT_HPP_
#define PAYMENT_HPP_
#include <iostream>
using namespace std;
class Payment
{
	void* payment;
private:
	string creditCardNum;
	string cardFirstName;
	string cardMiddleName;
	string cardLastName;
	string cardExpMonth;
	string cardExpYear;
	string cardCVV;

	float flightTicketCost = 0.0;
	float hotelRoomCost = 0.0;
	float totalCost = 0.0;

	const float flightFees = 10.00;
	float hotelFees = 5.00;
	const float taxRate = 0.1;

public:
	// setter for flight and hotel room cost
	void setFlightTicketCost(float input)
	{
		flightTicketCost = input;
	}
	void setHotelRoomCost(float input)
	{
		hotelRoomCost = input;
	}

	// getters for cost-related members, no getters for credit card related info ("setter" for credit card info is in calcPayment())
	float getFlightTicketCost()
	{
		return flightTicketCost;
	}
	float getHotelRoomCost()
	{
		return hotelRoomCost;
	}
	float getTotalCost()
	{
		return totalCost;
	}

	float calcPayment()
	{
		float tax = taxRate * (flightTicketCost + hotelRoomCost);
		totalCost = flightTicketCost + hotelRoomCost + flightFees + hotelFees + tax;

		if(hotelRoomCost == 0.0)
		{
			hotelFees = 0.0;
		}

		cout << "Flight Ticket Cost: $" << flightTicketCost << endl;
		cout << "Flight Ticket Fees: $" << flightFees << endl;
		cout << "Hotel Room Cost: $" << hotelRoomCost << endl;
		cout << "Hotel Room Fees: $" << hotelFees << endl;
		cout << "Tax (applied only to flight ticket and hotel room costs, not fees): $" << tax;
		cout << "TOTAL COST: $" << totalCost << endl;

		cout << "Enter the first name on the credit card: " << endl;
		cin >> cardFirstName;
		cout << "Enter the middle name on the credit card (press spacebar then enter if no middle name): " << endl;
		cin >> cardMiddleName;
		cout << "Enter the last name on the credit card: " << endl;
		cin >> cardLastName;

		cout << "Enter your credit card number: " << endl;
		cin >> creditCardNum;
		cout << "Enter credit card expiration month: " << endl;
		cin >> cardExpMonth;
		cout << "enter credit card expiration year: " << endl;
		cin >> cardExpYear;
		cout << "Enter credit card CVV (3 digits on the back of the card): " << endl;
		cin >> cardCVV;
	}
};


#endif /* PAYMENT_HPP_ */
