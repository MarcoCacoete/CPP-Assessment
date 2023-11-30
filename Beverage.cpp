#include "Beverage.h"
#include<sstream>
#include<iostream>
#include <iomanip>
using namespace std;

Beverage::Beverage() {


}


Beverage::Beverage(string name, double price, int calories, double volume, double abv) : Item(name, price, calories) {
	char pound = 156;
	this->volume = volume;
	this->abv = abv;

}

Beverage::~Beverage()
{
	cout << "deleted" << endl;
};
string Beverage::toString() {
	stringstream priceSS;
	priceSS << std::fixed << std::setprecision(2) << price;
	char pound = 156;
	string priceString = priceSS.str();

	stringstream volumeSS;
	volumeSS << std::fixed << std::setprecision(2) << volume;
	string volumeString = volumeSS.str();

	stringstream abvSS;
	abvSS << std::fixed << std::setprecision(2) << abv;
	string abvString = abvSS.str();

	return "Beverage: " + name + ", Price: " + pound + priceString + ", Calories: " + to_string(calories) + ", Volume: " + volumeString + "ml, ABV: " + abvString + "%";
}

