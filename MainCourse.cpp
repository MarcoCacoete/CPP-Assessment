#include "MainCourse.h"
#include<iostream>
#include <iomanip>

using namespace std;

MainCourse::MainCourse() {


}
MainCourse::MainCourse(string name, double price, int calories): Item(name,price,calories) {
	this->name = name;
	this->price = price;
	this->calories = calories;

}
string MainCourse::ToString() {
	std::stringstream priceSS;
	priceSS << std::fixed << std::setprecision(2) << price;
	char pound = 156;
	string priceString = priceSS.str();
	return "Main Course: " + name + "Price: "+pound + priceString + ", Calories: " + to_string(calories);
};

MainCourse::~MainCourse()
{
}
;