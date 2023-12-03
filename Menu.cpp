#include "Menu.h"
#include "Item.h"
#include "Appetiser.h"
#include "Beverage.h"
#include "MainCourse.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <regex>
#include<sstream>
#include "Order.h"
using namespace std; 

Menu::Menu(Item* choice) {
	
}

Menu::Menu(string s) {

	cout << "I am a menu" << endl;
	string temp = s;
	fileLoader(temp, Lines);
	MenuBuilder(Lines);
}
string Menu::toString()
{
	string menu = "\033[34m--------------------------------------Menu---------------------------------------\033[0m\n";
	int iterator = 1;
	bool a =false;
	bool b=false;
	bool c=false;
	string ite;
	for (Item* item : items) {
		if (iterator < items.size()&&items[0]->type == "a"&& a == false) {
			menu += "\n";
			menu+="\033[32m------------------------------------Appetiser------------------------------------\033[0m\n";
			menu += "\n";
			a = true;
		}
		if (iterator < items.size()&&items[iterator-1]->type == "m" && b == false) {
			menu += "\n";
			menu+="\033[32m------------------------------------Main Course----------------------------------\033[0m\n";
			menu += "\n";
			b = true;
		}
		if (iterator < items.size()&&items[iterator-1]->type == "b" && c == false) {
			menu += "\n";
			menu+="\033[32m------------------------------------Beverage-------------------------------------\033[0m\n";
			menu += "\n";
			c = true;
		}

		if (iterator < 10) {
			 ite = "0"+to_string(iterator);
		}
		else {
			 ite = to_string(iterator);
		}
		menu += ite+" - " + item->toString() + "\n";
			iterator++;
	}


	return menu;
};

/// <summary>
/// This function loads the csv file, it's a trimmed out version of the one that I used for one of the previeous assessed workshop tasks.
/// </summary>
/// <param name="s"></param>
void Menu::fileLoader(string s, vector<string>& Lines) {

	string word;

	string filename = s;

	ifstream myFile(filename);

	while (getline(myFile, word)) {
		// Add to the list of output strings
		Lines.push_back(word);
	}
	myFile.close();
	string temp;
	vector<string> temporary;
	for (string& line : Lines) {
		regex multiCommas("(,)+");
		string processedText = regex_replace(line, multiCommas, ",");
		line = processedText;
		

		// Split the line by commas and store the tokens in a temporary vector
		vector<string> tokens;
		stringstream ss(line);
		string token;

		while (getline(ss, token, ',')) {
			tokens.push_back(token);
		}

		// Add the tokens to the final output vector
		temporary.insert(temporary.end(), tokens.begin(), tokens.end());
	}

	Lines = temporary; // Update the Lines vector with the split lines
	//for (string s : Lines)cout << s << endl;

	
}

void Menu::MenuBuilder(vector<string> v) {
	vector<string> Temporary = v;
	int iterator = 0;

	type = Temporary[0];
	name = Temporary[1];
	temp = Temporary[2];
	price = stod(temp);
	temp = Temporary[3];
	calories = stoi(temp);
	shareable = Temporary[4] == "y";
	twoFourOne = Temporary[5] == "y";
	temp = Temporary[4];
	try {
		volume = stod(temp);
		temp = Temporary[5];
		abv = stod(temp);
	}
	catch (invalid_argument& e) {
		//cerr << "not a brew" << endl;
	}

	char pound = 156;

	if (type == "a") {
		iterator = 6;
		Appetiser* appetiser = new Appetiser(type,name, price, calories, shareable, twoFourOne);
		items.push_back(appetiser);
		//cout << appetiser->toString() << endl;
	}
	if (type == "m") {
		iterator = 4;
		MainCourse* main = new MainCourse(type,name, price, calories);
		items.push_back(main);
		//cout << main->toString() << endl;

	}
	if (type == "b") {
		iterator = 6;
		Beverage* bev = new Beverage(type,name, price, calories, volume, abv);
		items.push_back(bev);
		//cout << bev->toString() << endl;

	}
	while (iterator > 0) {
		Temporary.erase(Temporary.begin());
		iterator--;
	}
	//cout << type << " " << name << " Price: "<<pound << price << " Calories: " << calories << endl;

	//cout << "Size: " << Items.size() << endl;
	if (!Temporary.empty()) {
		MenuBuilder(Temporary);
	}	
}




