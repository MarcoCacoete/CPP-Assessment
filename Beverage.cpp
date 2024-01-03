#include "Beverage.h"
#include <sstream>
#include <iostream>
#include <iomanip>

Beverage::Beverage() {
    alc=false;
}
        // Once again, similar as appetiser class inherits necessary attributes.
Beverage::Beverage(string type, string name, double price, int calories, double volume, double abv) : Item(type, name, price, calories), volume(volume), abv(abv), alc(isAlcoholic(abv)) {
}

bool Beverage::isAlcoholic(double abv) {
    return abv > 0.0;                       // Returns true if alcohol abv is higher than 0, to tell toString to include it in output.
}

double Beverage::getVolume()  // Accessors and muutators 
{
    return volume;
}

double Beverage::getAbv()
{
    return abv;
}

bool Beverage::getAlc()
{
    return alc;
}

void Beverage::setVolume(const double& newVolume)
{
    volume = newVolume;
}

void Beverage::setAbv(const double& newAbv)
{
    abv = newAbv;
}

void Beverage::setAlc(const bool& newAlc)
{
    alc = newAlc;
}

Beverage::~Beverage() {
    cout << "Beverage terminated." << endl;

}

string Beverage::toString() {  // The same to string logic as in the other appetiser, explained already on comments on appetiser cpp. 
    stringstream priceSS;
    priceSS << fixed << setprecision(2) << getPrice();  
    char pound = 156;
    string priceString = priceSS.str();

    stringstream volumeSS;
    volumeSS << fixed << setprecision(2) << volume;
    string volumeString = volumeSS.str();

    stringstream abvSS;
    abvSS << fixed << setprecision(2) << abv;
    string abvString = abvSS.str();

    if (alc)
        return getName() + ", Price: " + pound + priceString + ", Calories: " + to_string(getCalories()) + ", Volume: " + volumeString + "ml, ABV: " + abvString + "%";
    else
        return getName() + ", Price: " + pound + priceString + ", Calories: " + to_string(getCalories()) + ", Volume: " + volumeString + "ml";
}
