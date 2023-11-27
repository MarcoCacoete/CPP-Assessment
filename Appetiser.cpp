#include "Appetiser.h"
#include<iostream>
#include <iomanip>

using namespace std;

Appetiser::Appetiser() {
	
}
Appetiser::Appetiser(string name, double price,int calories,string shareable, string twoForOne): Item(name,price,calories) {
	this->name = name;
	this->price = price;
	this->calories = calories;
	this->shareable = shareable;
	this->twoForOne = twoForOne;

}
string Appetiser::ToString() {
	std::stringstream ss;
	ss << std::fixed << setprecision(2) << price;
	char pound = 156;

	string priceString = ss.str();

	return "Appetiser: " + name + ", Price: "+pound + priceString + ", Calories: " + to_string(calories) + ", Shareable: " + shareable + ", Two for One: " + twoForOne;
}



Appetiser::~Appetiser()
{
}
