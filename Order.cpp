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

Order::Order() {

	total=0.0;

	discount=0.0;
}

Order::~Order()
{
	
}

string Order::toString()
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

		orderList.push_back(a);
	
	
	calculateTotal(orderList);
	//cout << toString();
}

void Order::remove(vector<Item*>& a, vector<Item*>& b, vector<string> parameters)
{
	for (int i = 1; i < parameters.size(); i++) {
		int itemNumber = stoi(parameters[i]);

		int pick = itemNumber - 1;
		int limit = a.size();
		int ite = 0;

		while (ite < limit) {
			if (a[ite]->toString() == b[pick]->toString()) {
				a.erase(a.begin() + ite);
				break; 
			}
			ite++;
		}
	}

	calculateTotal(a);
	cout << toString();

}

double Order::calculateTotal(vector<Item*>orderList) {
	double appetiserCount = 0.0;	
	double appetiserPrice = 0.0;

	vector<Appetiser*> appetisers; 

	for (Item* item : orderList) {
		if (item->type == "a") {
			Appetiser* appetiser = dynamic_cast<Appetiser*>(item);
			 // Add the appetiser to the vector
			if (appetiser->twoForOne == true) {
				appetiserPrice = appetiser->price;
				appetisers.push_back(appetiser);
			}
			else {
				total += appetiser->price;
			}
		}
		else {
			total +=item->price;
		}
	}

	if (appetisers.size() > 0) {
		for (size_t i = 0; i < appetisers.size(); i++) 	{		
			// Check if the index is odd (2nd, 4th, 6th, etc.)
			if (i % 2 == 0) {
				appetiserCount++;
				// Add the price of the appetiser to the total
				total += appetisers[i]->price;
			}
		}
	}

	discount = appetiserPrice * (appetisers.size() - appetiserCount);

	return total;	
}


void Order::printReceipt()
{
	// Open the file in binary mode and specify UTF-8 encoding
	ofstream outputFile("Receipt.txt", ios::out | ios::binary);

	if (outputFile.is_open()) {
		outputFile << "|||||||||||||||||||||||||||| YOUR RECEIPT! |||||||||||||||||||||||||||" << endl;

		string orderDetails = toString();

		for (int i = 0; i < orderDetails.size(); i++) {
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
		orderList.clear(); // Clear the vector after deleting the elements

	}
	else {
		cerr << "Error: Unable to open file." << endl;
	}

	outputFile.close();
}

