#include "Item.h"
#include <iostream>
#include "Appetiser.h"
#include "Beverage.h"
#include "MainCourse.h"
using namespace std;

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


 