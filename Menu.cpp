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

Menu::Menu() : calories(0), shareable(false), twoFourOne(false), volume(0.0), abv(0.0), price(0.0) //Constructors and destructors.
{
}


Menu::~Menu()
{
	cout << "Menu terminated." << endl;

	for (Item* item : items) {
		delete item;
	}

}

Menu::Menu(string s) {

	cout << "Welcome to GenEric's restaurant, your menu is ready." << endl;  // Friendly messages.
	cout << "" << endl;
	cout << "To view the menu, enter menu." << endl;
	cout << "" << endl;
	cout << "To see all available options enter help. (We kindly recommend you do this now.) " << endl;
	cout << "" << endl;

	string temp = s;  // Variables and method calls.
	fileLoader(temp, Lines);  // Calls filedloader, responsible for loading up csv file with menu information, and handing the data off to a vector of strings.
	MenuBuilder(Lines);   // Menu Builder is responsible for constructing the menu.
	appetiser = false;    // Very useful booleans helpful for tostring.
	beverage = false;
	mainCourse = false;
	originalItems = items;  // This vector holds data for original order of menu, to reset sorting.
}
string Menu::toString()						// toString, to output the menu in a colourful way, uses validation for different sorts.
{
	string menu = "\033[34m--------------------------------------Menu---------------------------------------\033[0m\n";  // Visual dividers output in different colours.
	int iterator = 1;
	
	string ite;
	for (Item* item : items) {	//Similar as first one, however using booleans that flip to true if all items of a certain type have been processed.
		if (iterator < items.size()&&items[0]->getType() == "a" && appetiser == false) { // Iterates through items gets item type and state of their boolean to know if it should output the divider.
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
			 ite = "0"+to_string(iterator);		// This bit inserts 0 character to line up item numbers better in menu output.
		}
		else {
			 ite = to_string(iterator); // This line adds iterator as a string, to items from first to last to number items..
		}
		menu += ite+" - " + item->toString() + "\n";  // Hands off items to their respective to string methods.
			iterator++;
	}
	return menu;
}

// This function loads the csv file, it's a trimmed out version of the one that I used for one of the previeous assessed workshop tasks.

void Menu::fileLoader(string s, vector<string>& Lines) {

	string word;

	string filename = s;

	ifstream myFile(filename);   // Input file stream to read data. Opens file handed over as argument.

	while (getline(myFile, word)) {
									// Add to the list of output strings
		Lines.push_back(word);
	}
	myFile.close();  // Closes file
	string temp;
	vector<string> temporary;
	for (string& line : Lines) {
		regex multiCommas("(,)+"); // Defines a regular expression that matches commas
		string processedText = regex_replace(line, multiCommas, ",");  // Replaces all occurrences of one or more consecutive commas in the line with a single comma to remove unnecessary extra commas in csv
		line = processedText;  // Saves it as a processed line.
		

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
	sort(items.begin(), items.end(), [](const Item* a, const Item* b) {	 //Lambda function being used here to tell the sort function how to compare the items from algorithm library.
		return *a < *b;													
		});
}
		// The lambda functions take two pointers to Items (a and b) as its parameters. It returns the result of the expression "*a < *b".
		// This expression uses the overloaded "<" operator from the Item class. This operator was redefined in the Item class to compare the prices of the items instead of their memory addresses.
		// If the price of item a is less than the price of item b, the expression "*a < *b" will be true. So, during the sorting process, item a will be placed before item b.

void Menu::sortByPriceDescending() {
	sort(items.begin(), items.end(), [](const Item* a, const Item* b) {  // Same as above
		return *a > *b;													// Same as above
		});
}


													// All accessors and mutators
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

