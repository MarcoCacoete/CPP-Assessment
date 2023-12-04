#include "MainCourse.h"
#include<sstream>
#include<iostream>
#include <iomanip>
using namespace std;

MainCourse::MainCourse() {


}

MainCourse::MainCourse(string type,string name, double price, int calories) : Item(type,name, price, calories) {

}
string MainCourse::toString() {
	stringstream priceSS;
	priceSS << fixed << setprecision(2) << price;
	char pound = 156;
	string priceString = priceSS.str();
	return name + " Price: " + pound + priceString + ", Calories: " + to_string(calories);
};

MainCourse::~MainCourse()
{
};