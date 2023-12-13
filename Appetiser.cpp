#include "Appetiser.h"
#include "Item.h"
#include <sstream>
#include <iostream>
#include <iomanip>

Appetiser::Appetiser()
{
}
//Constructor inherits all attributes from parent class except shareable and twoForOne
Appetiser::Appetiser(string type, string name, double price, int calories, bool shareable, bool twoForOne) : Item(type, name, price, calories), shareable(shareable), twoForOne(twoForOne) {
}  

Appetiser::~Appetiser() {
}


void Appetiser::setShareable(const bool& newShareable)  // Accessors and mutator implementations. Const keyword used to prevent changes to original.
{
    shareable = newShareable;
}

void Appetiser::setTwoForOne(const bool& newTwoForOne)
{
    twoForOne = newTwoForOne;
}

bool Appetiser::getShareable() const
{
    return shareable;
}

bool Appetiser::getTwoForOne() const
{
    return twoForOne;
}

string Appetiser::toString() {  //My toString method custom made for this child class.
    stringstream ss;
    ss << fixed << setprecision(2) << getPrice();  // First time trying this stringstream method to remove unnecessary decimal places use getter to get the price from item.
    char pound = 156;                              // Had to define pount character using ascii code because it isn't recognized in c++ by default,

    string priceString = ss.str();   

    if (shareable && twoForOne)                         //I had to use elfe ifs for tostring because some appetisers had extra attributes, this only outputs as necessary
        return getName() + ", Price: " + pound + priceString + ", Calories: " + to_string(getCalories()) + ", Shareable, Two For One";
    else if (shareable)
        return getName() + ", Price: " + pound + priceString + ", Calories: " + to_string(getCalories()) + ", Shareable";
    else if (twoForOne)
        return getName() + ", Price: " + pound + priceString + ", Calories: " + to_string(getCalories()) + ", Two For One";
    else
        return getName() + ", Price: " + pound + priceString + ", Calories: " + to_string(getCalories());
}
