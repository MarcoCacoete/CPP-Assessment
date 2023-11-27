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
using namespace std;

/// <summary>
/// Menu Class constructor
/// </summary>
/// <param name="s"></param>
Menu::Menu(string s) {

	cout << "I am a menu" << endl;
	string temp = s;
	fileLoader(temp,Lines);
	MenuBuilder(Lines);
}

int Menu::ToString()
{
	return 0;
}

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

	std::ofstream outputFile("myData.txt");
	
	if (outputFile.is_open()) {
	 //File is open, proceed with writing
	}
	else {
	// Error handling: file could not be opened
	}
	for (string element : Lines) {
		outputFile << element << std::endl;
	}
	outputFile.close();
}
vector <Item*> Items;

void Menu::MenuBuilder(vector<string> v) {
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
		//cerr << "not a brew" << endl;
	}

	char pound = 156;

	if (Temporary[0] == "a") {
		iterator = 6;
		type = "Appetiser";
		Appetiser* appetiser = new Appetiser(name, price, calories, shareable, twoFourOne);
		Items.push_back(appetiser);
		cout << appetiser->ToString() << endl;
	}
	if (Temporary[0] == "m") {
		iterator = 4;
		type = "Main Course";
		MainCourse* main = new MainCourse(name, price, calories);
		Items.push_back(main);
		cout << main->ToString() << endl;

	}
	if (Temporary[0] == "b") {
		iterator = 6;
		type = "Beverage";
		Beverage* bev = new Beverage(name, price, calories, volume, abv);
		Items.push_back(bev);
		cout << bev->ToString() << endl;

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
		
	
	
