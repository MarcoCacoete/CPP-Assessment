#include "MainCourse.h"
#include <sstream>
#include <iostream>
#include <iomanip>

MainCourse::MainCourse() {  // Constructors and destructors, only difference is the set of attributes inherited.
}

MainCourse::MainCourse(string type, string name, double price, int calories) : Item(type, name, price, calories) {
}

MainCourse::~MainCourse() {
    cout << "MainCourse terminated." << endl;

}

string MainCourse::toString() { // Already described in Appetiser class everything is the same.
    stringstream priceSS;
    priceSS << fixed << setprecision(2) << getPrice();  
    char pound = 156;

    string priceString = priceSS.str();
    return getName() + " Price: " + pound + priceString + ", Calories: " + to_string(getCalories());
}


