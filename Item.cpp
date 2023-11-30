#include "Item.h"
#include<iostream>
using namespace std;


string Item::toString()
{
	return string();
}


Item::Item() {
	calories = 0;
	price = 0.0;
}

Item::Item(string name, double price, int calories) {

	this->name = name;
	this->price = price;
	this->calories = calories;
}


Item::~Item() {
	cout << "deleted" << endl;
}



