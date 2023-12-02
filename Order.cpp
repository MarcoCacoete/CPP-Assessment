#include "Order.h"
#include "Menu.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include<sstream>
#include <iomanip>
#include "Appetiser.h"
using namespace std;
Order::Order() {


}

string Order::toString()
{
	return string();
}

void Order::add(vector<Item*>& a, vector<Item*>& b,vector<string> parameters)
{
	for (int i = 1; i < parameters.size(); i++) {
		int itemNumber = stoi(parameters[i]);

		int picked = itemNumber - 1;

		a.push_back(b[picked]);
	}
	cout << "" << "\n";
	cout << "Your current order is: " << endl;

	for (Item* i : a) {
		cout << i->toString() << endl;
	}
	calculateTotal(a);
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

	cout << "" << "\n";

	cout << "Your current order is: " << endl;
	for (Item* j : a) {
		cout << j->toString() << endl;
	}
	calculateTotal(a);

}

double Order::calculateTotal(vector<Item*>orderList) {
	total = 0.0;

	int appetiserCount = 0;
	
	vector<Appetiser*> appetisers; 

	for (Item* item : orderList) {
		if (item->type == "a") {
			Appetiser* appetiser = dynamic_cast<Appetiser*>(item);
			 // Add the appetiser to the vector
			if (appetiser->twoForOne == true) {
				appetisers.push_back(appetiser);
				appetiserCount++;
			}
			else {
				total += appetiser->price;
			}
		}
		else {
			total +=item->price;
		}
	}

	if (appetiserCount > 0) {
		for (size_t i = 0; i < appetisers.size(); i++) {
			// Check if the index is odd (2nd, 4th, 6th, etc.)
			if (i % 2 == 0) {
				// Add the price of the appetiser to the total
				total += appetisers[i]->price;
			}
		}
	}
	
	stringstream priceSS;
	priceSS << fixed << setprecision(2) << total;
	char pound = 156;
	string priceString = priceSS.str();

	cout << " Total: " << pound << priceString << endl;
	return total;
	
}


void Order::printReceipt()
{

}
