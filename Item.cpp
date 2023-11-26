#include "Item.h"
using namespace std;
#include <iostream>
#include "Appetiser.h"
#include "Beverage.h"
#include "MainCourse.h"

Item::Item() {
	cout << "I'm another fuckin item." << endl;
}

Item::Item(vector <string> Lines) {

	ItemBuilder(Lines);
}
vector <Item*> Items;
void Item::ItemBuilder(vector<string> v) {
vector<string> Temporary = v;
int iterator = 0;

name = Temporary[1];
temp = Temporary[2];
price = stod(temp);
temp = Temporary[3];
calories = stoi(temp);
shareable = Temporary[4];
twoFourOne = Temporary[5];
temp = Temporary[4];
try {
	volume = stod(temp);
	temp = Temporary[5];
	abv = stod(temp);
}
catch (invalid_argument& e) {
	cerr << "not a brew" << endl;
}

char pound = 156;



	if (Temporary[0] == "a") {
		iterator = 6;
		type = "Appetiser";
		Appetiser* appetiser = new Appetiser(name,price,calories,shareable,twoFourOne);
		Items.push_back(appetiser);
	}
	if (Temporary[0] == "m") {
		iterator = 4;
		type = "Main Course";		
		MainCourse* main = new MainCourse(name, price, calories);
		Items.push_back(main);
	}
	if (Temporary[0] == "b") {
		iterator = 6;
		type = "Beverage";		
		Beverage* bev = new Beverage(name, price, calories, volume, abv);
		Items.push_back(bev);
	}	
	while (iterator > 0) {
		Temporary.erase(Temporary.begin());
		iterator--;
	}
	//cout << type << " " << name << " Price: "<<pound << price << " Calories: " << calories << endl;
	
	cout << "Size: "<<Items.size() << endl;
	if (!Temporary.empty()){ItemBuilder(Temporary);}
 }

 

Item::~Item() {
	cout << "deleted" << endl;
}


 