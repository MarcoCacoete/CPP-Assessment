#include "Item.h"
using namespace std;
#include <iostream>


Item::Item() {
	cout << "I'm another fuckin item." << endl;
}

Item::Item(vector <string> Lines) {

	ItemBuilder(Lines);
}

 void Item::ItemBuilder(vector<string> v){
vector<string> Temporary = v;
int iterator = 0;

name = Temporary[1];
temp = Temporary[2];
price = stod(temp);
temp = Temporary[3];
calories = stoi(temp);
char pound = 156;
	if (Temporary[0] == "a") {
		iterator = 6;
		type = "Appetiser";		
	}
	if (Temporary[0] == "m") {
		iterator = 4;
		type = "Main Course";		

	}
	if (Temporary[0] == "b") {
		iterator = 6;
		type = "Beverage";		
	}	
	while (iterator > 0) {
		Temporary.erase(Temporary.begin());
		iterator--;
	}
	cout << type << " " << name << " Price: "<<pound << price << " Calories: " << calories << endl;
	
	if (!Temporary.empty()){ItemBuilder(Temporary);}
 }


Item::~Item() {
	 
}


 