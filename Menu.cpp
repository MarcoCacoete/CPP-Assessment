#include "Menu.h"
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
	fileLoader(temp);
}
/// <summary>
/// This function loads the csv file, it's a trimmed out version of the one that I used for one of the previeous assessed workshop tasks.
/// </summary>
/// <param name="s"></param>
void Menu::fileLoader(string s) {

	string word;

	string filename = s;

	vector<string> Lines;
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
		// File is open, proceed with writing
	}
	else {
		// Error handling: file could not be opened
	}
	for (string element : Lines) {
		outputFile << element << std::endl;
	}
	outputFile.close();



Item item = Item (Lines);

}

int Menu::toString() { return 1; };