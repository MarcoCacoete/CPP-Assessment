#include "Order.h"
#include "Menu.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include<sstream>
#include <iomanip>
#include "Appetiser.h"
#include <fstream>
#include <regex>

using namespace std;

Order::Order() {  // Constructors and destructors.

	total=0.0;

	discount=0.0;
}

Order::~Order()
{
	
}

string Order::toString()  // Order toString method. Goes through every item in orderlist and ouputs total cost and also savings from discount.
{
	stringstream output;

	output << "" << "\n";

	output << "Your order : " << endl;
	output << "" << "\n";

	for (Item* j : orderList) {
		output << j->toString() << endl;
		output << "" << "\n";

	}
	stringstream priceSS;
	priceSS << fixed << setprecision(2) << total;
	char pound = 156;
	string total = priceSS.str();
	output << "" << "\n";
	output << "Here's your total: "<<pound << total << " Your savings are: " <<pound << discount << endl;

	return output.str();

}

void Order::add(Item*a)
{

		orderList.push_back(a);  // Adds item pointer to order list if match is found in items list.
	
	
	calculateTotal(orderList);
}

void Order::remove(vector<Item*> items,vector<string> parameters)	// Originally my add method was the reverse of this one.
{
	for (int i = 1; i < parameters.size(); i++) {		// Iterates through parameters to call a check to see if they are a number or not, for error input prevention.

		bool check = inputCheck(parameters[i], items);

		if (check == true) {
			int itemNumber = stoi(parameters[i]);		// Those who pass get converted and added to orderlist using same index as in original items list.
			int pick = itemNumber - 1;
			int limit = orderList.size();
			int ite = 0;

			while (ite < limit) {
				if (orderList[ite]->toString() == items[pick]->toString()) { // limits the while loop index to prevent out of bounds. Compares the 2 string representations.
					orderList.erase(orderList.begin() + ite); // If it finds a match, it removes item per parameter.
					break;
				}
				ite++;
			}
		}
	}

	calculateTotal(orderList);
	cout << toString();

}

double Order::calculateTotal(vector<Item*>orderList) {  // Calculates the total of items in orderlist
	double appetiserCount = 0.0;	
	double appetiserPrice = 0.0;			// 2 doubles for keeping tally of price and item count, to calculate the savings in two for one cases.
	total = 0;
	vector<Appetiser*> appetisers; 

	for (Item* item : orderList) {
		if (item->getType() == "a") {
			Appetiser* appetiser = dynamic_cast<Appetiser*>(item);	// Compares items, if they are appetiser casts, items as appetisers and extracts prices.
			if (appetiser->getTwoForOne() == true) {
				appetiserPrice = appetiser->getPrice();
				appetisers.push_back(appetiser);				//Adds the appetisers to a vector, so that we can size it.
			}
			else {
				total += appetiser->getPrice();		// If two for 1 property not found, it gets treated as regular item.
			}
		}
		else {
			total +=item->getPrice();		// This is for regular items.
		}
	}

	if (appetisers.size() > 0) {
		for (size_t i = 0; i < appetisers.size(); i++) 	{		
												// Checks if the index is odd (2nd, 4th, 6th, etc.) to enact two for 1
			if (i % 2 == 0) {
				appetiserCount++;
												// Adds every other price of the appetiser to the total
				total += appetisers[i]->getPrice();
			}
		}
	}

	discount = appetiserPrice * (appetisers.size() - appetiserCount);		// Ccalculates discount

	return total;	
}


void Order::printReceipt()
{
																	// Opens the file in binary mode and specifies UTF-8 encoding for Pound sign.
	ofstream outputFile("Receipt.txt", ios::out | ios::binary);

	if (outputFile.is_open()) {
		outputFile << "|||||||||||||||||||||||||||| YOUR RECEIPT! |||||||||||||||||||||||||||" << endl;

		string orderDetails = toString();

		for (int i = 0; i < orderDetails.size(); i++) {  // Swaps the wrong char for the correct pound symbol.
			if (orderDetails[i] == 'œ') {
				orderDetails[i] = '£';
			}
		}

		outputFile << orderDetails;
		cout << endl;
		cout << "Receipt printed!" << endl;
		cout << endl;
		cout <<"Enter exit to exit followed by any key, or continue shopping. For extra help enter help!"<< endl;
		cout << endl;		
		orderList.clear();									// Clear the vector after deleting the elements

	}
	else {
		cerr << "Error: Unable to open file." << endl;
	}

	outputFile.close();										// Closes file
}
bool Order::inputCheck(string v, vector<Item*> t) {

															// My checker to correct user input in add and remove methods.
		if (all_of(v.begin(), v.end(), ::isdigit)){		//Checks if a string is numeric

			int itemNumber = stoi(v);					// COnverts to int

			int picked = itemNumber - 1;

			if (picked < size(t)) {
				return true;							//Returns true or false. With a message intended for the user.
			}
			else {
				cout << "Enter a valid Item! " << ">> " << v << " << " << " is not a valid item!" << " Enter help for all commands, enter Menu for all available items." << endl;
				return false;
			}
		}
		else {
			cout << "Enter a valid Item! " << ">> " << v << " << " << " is not a valid item!" << " Enter help for all commands, enter Menu for all available items." << endl;
			return false;
		}
}
