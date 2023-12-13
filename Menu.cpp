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
#include <algorithm>

using namespace std; 

Menu::Menu() : calories(0), shareable(false), twoFourOne(false), volume(0.0), abv(0.0), price(0.0)
{
}

Menu::Menu(string s) {

	cout << "Welcome to GenEric's restaurant, your menu is ready." << endl;
	cout << "" << endl;
	cout << "To view the menu, enter menu." << endl;
	cout << "" << endl;
	cout << "To see all available options enter help. (We kindly recommend you do this now.) " << endl;
	cout << "" << endl;

	string temp = s;
	fileLoader(temp, Lines);
	MenuBuilder(Lines);
	appetiser = false;
	beverage = false;
	mainCourse = false;
	originalItems = items;
}
Menu::~Menu()
{
	for (Item* item : items) {
		delete item;
	}
	
}
string Menu::toString()						// toString, to output the menu in a colourful way, uses validation for different sorts.
{
	string menu = "\033[34m--------------------------------------Menu---------------------------------------\033[0m\n";
	int iterator = 1;
	
	string ite;
	for (Item* item : items) {
		if (iterator < items.size()&&items[0]->getType() == "a" && appetiser == false) {
			menu += "\n";
			menu+="\033[32m------------------------------------Appetiser------------------------------------\033[0m\n";
			menu += "\n";
			appetiser = true;
		}
		if (iterator < items.size()&&items[iterator-1]->getType() == "m" && mainCourse == false) {
			menu += "\n";
			menu+="\033[32m------------------------------------Main Course----------------------------------\033[0m\n";
			menu += "\n";
			mainCourse = true;
		}
		if (iterator < items.size()&&items[iterator-1]->getType() == "b" && beverage == false) {
			menu += "\n";
			menu+="\033[32m------------------------------------Beverage-------------------------------------\033[0m\n";
			menu += "\n";
			beverage = true;
		}

		if (iterator < 10) {
			 ite = "0"+to_string(iterator);		// This bit inserts 0 to line up item numbers better.
		}
		else {
			 ite = to_string(iterator); // This line adds iterator as a string, to items from first to last.
		}
		menu += ite+" - " + item->toString() + "\n";
			iterator++;
	}
	return menu;
}

// This function loads the csv file, it's a trimmed out version of the one that I used for one of the previeous assessed workshop tasks.

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
	
}

void Menu::MenuBuilder(vector<string> v) {
	vector<string> Temporary = v;    
	int iterator = 0;

	type = Temporary[0];
	name = Temporary[1];
	temp = Temporary[2];		// Assigns each string to a variable, converts some into apropriate types.
	price = stod(temp);
	temp = Temporary[3];		
	calories = stoi(temp);
	shareable = Temporary[4] == "y";
	twoFourOne = Temporary[5] == "y";
	temp = Temporary[4];
	try {
		volume = stod(temp);
		temp = Temporary[5];    // This try prevents a crash in case there's no abv.
		abv = stod(temp);
	}
	catch (invalid_argument& e) {
		//cerr << "not a brew" << endl;
	}

	char pound = 156;
							// These ifs create apropriate types of item depending on the first string value.
	if (type == "a") {
		iterator = 6;
		Appetiser* appetiser = new Appetiser(type,name, price, calories, shareable, twoFourOne);
		items.push_back(appetiser);		// Then add these items to items vector.
	}
	if (type == "m") {
		iterator = 4;
		MainCourse* main = new MainCourse(type,name, price, calories);
		items.push_back(main);

	}
	if (type == "b") {
		iterator = 6;
		Beverage* bev = new Beverage(type,name, price, calories, volume, abv);
		items.push_back(bev);

	}
	while (iterator > 0) {
		Temporary.erase(Temporary.begin()); // This removes strings from vector to later call recursively and work on new strings.
		iterator--;
	}
	
	if (!Temporary.empty()) {   // Recursive call until all strings are processed.
		MenuBuilder(Temporary);
	}	
}

void Menu::sortByPriceAscending() {
	sort(items.begin(), items.end(), [](const Item* a, const Item* b) {	 //Lambda function uses custom way to compare for sorting all items in items vector
		return *a < *b;													// Using the overloaded < operator defined in the Item class changed to compare item prices.
		});
}

void Menu::sortByPriceDescending() {
	sort(items.begin(), items.end(), [](const Item* a, const Item* b) {  // Same as above
		return *a > *b;													// Same as above
		});
}


													// All gets and sets.
string Menu::getType() const
{
	return type;
}

string Menu::getName() const
{
	return name;
}

string Menu::getTemp() const
{
	return temp;
}

int Menu::getCalories() const
{
	return calories;
}

bool Menu::getAppetiser() const
{
	return appetiser;
}

double Menu::getPrice() const
{
	return price;
}

bool Menu::getBeverage() const
{
	return beverage;
}

bool Menu::getMainCourse() const
{
	return mainCourse;
}

bool Menu::getShareable() const
{
	return shareable;
}

bool Menu::getTwoForOne() const
{
	return twoFourOne;
}

double Menu::getVolume() const
{
	return volume;
}

double Menu::getAbv() const
{
	return abv;
}

void Menu::setType(const string& newType)
{
	type = newType;
}

void Menu::setName(const string& newName)
{
	name = newName;
}

void Menu::setTemp(const std::string& newTemp)
{
	temp = newTemp;
}

void Menu::setCalories(int newCalories)
{
	calories = newCalories;
}

void Menu::setAppetiser(bool value)
{
	appetiser = value;
}

void Menu::setBeverage(bool value)
{
	beverage = value;
}

void Menu::setMainCourse(bool value)
{
	mainCourse = value;
}

void Menu::setShareable(bool value)
{
	shareable = value;
}

void Menu::setTwoForOne(bool value)
{
	twoFourOne = value;
}

void Menu::setVolume(double newVolume)
{
	volume = newVolume;
}

void Menu::setAbv(double newAbv)
{
	abv = newAbv;
}

void Menu::setPrice(double newPrice)
{
	price = newPrice;
}

