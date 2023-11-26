#include "Beverage.h"
Beverage::Beverage() {

}

Beverage::Beverage(string name, double price, int calories, double volume, double abv) {
	char pound = 156;
	this-> volume = volume;
	this-> abv = abv;
	cout << "Beverage: " << name << " Price: "<<pound << price << " Calories: " << calories << endl;
	cout << "Volume: " << volume << endl;
	cout << "ABV: " << abv << endl;
}
Beverage::~Beverage()
{
	cout<<"deleted" << endl;
};