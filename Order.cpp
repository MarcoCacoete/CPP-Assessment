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
	cout << "Order terminated." << endl;

}

string Order::toString()  // Order toString method. Goes through every item in orderlist and ouputs total cost and also savings from discount.
{
	stringstream output; // Creates a stringstream object to build the strings.

	output << "" << "\n"; // Adds new line

	output << "Your order : " << endl;  // Adds string
	output << "" << "\n";

	for (Item* j : orderList) {         // Iterates through vector to add items string representation to the stream
		output << j->toString() << endl;
		output << "" << "\n";

	}
	stringstream priceSS;
	priceSS << fixed << setprecision(2) << total;  // Sets precision of total to 2 decimal places.
	char pound = 156;								// My solution to be able to use the pound sign.
	string total = priceSS.str();
	output << "" << "\n";
	output << "Here's your total: "<<pound << total << " Your savings are: " <<pound << discount << endl;  // Summary of order.

	return output.str();  // Converts the stringstream to a string and returns it

}

void Order::add(Item*a)
{

		orderList.push_back(a);  // Adds item pointer to order list if match is found in items list.
	
	
	calculateTotal(orderList);  // Updates total every time.
}

void Order::remove(vector<Item*> items,vector<string> parameters)	//Removes items from order takes Item pointer vector and string vector as arguments. Originally my add method was the reverse of this one.
{
	for (int i = 1; i < parameters.size(); i++) {		// Iterates through parameters to call a check to see if they are a number or not, for input error prevention.

		bool check = inputCheck(parameters[i], items);

		if (check == true) {
			int itemNumber = stoi(parameters[i]);		// Those who pass get converted to ints and added to orderlist using same index as in original items list.
			int pick = itemNumber - 1;					// This offsets user input due to 0 being first element in programming.
			int limit = orderList.size();				// Defines limit to prevent sequencing issues.
			int ite = 0;

			while (ite < limit) {
				if (orderList[ite]->toString() == items[pick]->toString()) { // The limit is set to the size of the orderList to prevent out-of-bounds errors.
					orderList.erase(orderList.begin() + ite); // If it finds a match, it removes item per parameter.
					break;
				}
				ite++;
			}
		}
	}

	calculateTotal(orderList);		// Updates total
	cout << toString();				// Prints order.

}

double Order::calculateTotal(vector<Item*>orderList) {  // Calculates the total of items in orderlist
	double appetiserCount = 0.0;	
	double appetiserPrice = 0.0;			// 2 doubles for keeping tally of price and item count, to calculate the savings in two for one cases.
	total = 0;
	vector<Appetiser*> appetisers; 

	for (Item* item : orderList) {			// Iterates through order list
		if (item->getType() == "a") {		// Uses accessor to see if item is appetiser
			Appetiser* appetiser = dynamic_cast<Appetiser*>(item);	// Compares items, if they are appetiser casts items as appetisers and extracts prices.
			if (appetiser->getTwoForOne() == true) {
				appetiserPrice = appetiser->getPrice();
				appetisers.push_back(appetiser);				//Adds the appetisers to a vector, so that I could size it.
			}
			else {
				total += appetiser->getPrice();		// If two for 1 property not found, it gets treated as regular item.
			}
		}
		else {
			total +=item->getPrice();		// This is for regular items.
		}
	}

	if (appetisers.size() > 0) {			// Checks if appetisers vector isn't empty.
		for (size_t i = 0; i < appetisers.size(); i++) 	{		// Iterates through appetisers. size_t is an unsigned integer type guaranteed to be big enough to contain the size of the largest object.
												
			if (i % 2 == 0) {		// Checks if the index is even to enact two for 1
				appetiserCount++;		
												// Adds every other price of the appetiser to the total. Index 0 is even for index, so index 0 would add to total, 1 wouldn't 2 would etc.
				total += appetisers[i]->getPrice();
			}
		}
	}

	discount = appetiserPrice * (appetisers.size() - appetiserCount);		// Calculates discount by multiplying the price of an appetiser by the number of appetisers not included in the total.

	return total;	// Returns total.
}


void Order::printReceipt()
{
	// Opens the file in binary mode and specifies UTF-8 encoding for Pound sign.
	ofstream outputFile("Receipt.txt", ios::out | ios::binary);

	if (outputFile.is_open()) {		// If opened successfuly, adds all strings below to file.
		outputFile << "|||||||||||||||||||||||||||| YOUR RECEIPT! |||||||||||||||||||||||||||" << endl;

		string orderDetails = toString();  // Converts order to string, assigns it to string.

		for (int i = 0; i < orderDetails.size(); i++) {  // Swaps all instances the wrong char for the correct pound symbol. By looping through orderDetails.
			if (orderDetails[i] == 'œ') {
				orderDetails[i] = '£';
			}
		}

		outputFile << orderDetails;			// Adds orderdetails to the file folllowed by some spacing and strings.
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

bool Order::inputCheck(string v, vector<Item*> t) {  // My checker to correct user input in add and remove methods.

															
		if (all_of(v.begin(), v.end(), ::isdigit)){		//Checks if a string is numeric

			int itemNumber = stoi(v);					// Converts to int

			int picked = itemNumber - 1;				// Corrects input to match indexing, due to 0 being the first element in programming.

			if (picked < size(t)) {						// Ensures user can't pick an item that is out of bounds.
				return true;							// Returns true or false. With a message intended for the user.
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
