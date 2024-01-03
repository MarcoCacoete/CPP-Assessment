#include "Item.h"
#include<iostream>
using namespace std;




Item::Item() {	// Constructors and destructors, same for all classes.
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
	cout << "Item terminated." << endl;

}

string Item::toString()  //To string method.
{
	return string();
}
									// Accessors and mutators
string Item::getName() const {
	return name;
}

double Item::getPrice() const {
	return price;
}

int Item::getCalories() const {
	return calories;
}

string Item::getType() const {
	return type;
}

void Item::setName(const string& newName) {
	name = newName;
}

void Item::setPrice(double newPrice) {
	price = newPrice;
}

void Item::setCalories(int newCalories) {
	calories = newCalories;
}

void Item::setType(const string& newType) {
	type = newType;
}

bool Item::operator<(const Item& other) const {
	return price < other.price;
}

bool Item::operator>(const Item& other) const {
	return price > other.price;
}