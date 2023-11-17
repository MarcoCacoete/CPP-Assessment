#include "Menu.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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

	for (string& i : Lines) {
		cout << i << endl;
	}
}

int Menu::toString() { return 1; };