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

Item::Item(string type,string name, double price, int calories) {

	this->name = name;
	this->price = price;
	this->calories = calories;
	this->type = type;
}


Item::~Item() {
	cout << "deleted" << endl;
}



