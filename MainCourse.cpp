#include "MainCourse.h"
#include <sstream>
#include <iostream>
#include <iomanip>

MainCourse::MainCourse() {
}

MainCourse::MainCourse(string type, string name, double price, int calories) : Item(type, name, price, calories) {
}

string MainCourse::toString() {
    stringstream priceSS;
    priceSS << fixed << setprecision(2) << getPrice();  
    char pound = 156;

    string priceString = priceSS.str();
    return getName() + " Price: " + pound + priceString + ", Calories: " + to_string(getCalories());
}

MainCourse::~MainCourse() {
}
