#include "Appetiser.h"
#include"Item.h"
#include<sstream>
#include<iostream>
#include <iomanip>
using namespace std;

Appetiser::Appetiser(string type,string name, double price, int calories, bool shareable, bool twoForOne) : Item(type,name, price, calories) {
	this->name = name;
	this->price = price;
	this->calories = calories;
	this->shareable = shareable;
	this->twoForOne = twoForOne;
	this->type = type;

}
Appetiser::~Appetiser()
{
}

string Appetiser::toString()
{
	stringstream ss;
	ss << fixed << setprecision(2) << price;
	char pound = 156;

	string priceString = ss.str();

	if (shareable && twoForOne)
		return name + ", Price: " + pound + priceString + ", Calories: " + to_string(calories) + ", Shareable, Two For One";
	else if (shareable)
		return name + ", Price: " + pound + priceString + ", Calories: " + to_string(calories) + ", Shareable";
	else if (twoForOne)
		return name + ", Price: " + pound + priceString + ", Calories: " + to_string(calories) + ", Two For One";
	else
		return name + ", Price: " + pound + priceString + ", Calories: " + to_string(calories);
}



	



