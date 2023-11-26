#include "Appetiser.h"

Appetiser::Appetiser() {
	
}
Appetiser::Appetiser(string name, double price,int calories,string shareable, string twoForOne) {
	char pound = 156;
	this->name = name;
	this->price = price;
	this->calories = calories;
	this->shareable = shareable;
	this->twoFourOne = twoForOne;
	cout << "Appetiser: " << name << " Price: "<<pound << price << " Calories: " << calories << endl;
	cout << "Shareable: " << shareable << endl;
	cout << "Two for One: " << twoForOne << endl;
}

Appetiser::~Appetiser()
{
}
