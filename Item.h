#pragma once

#include "ItemList.h"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>
#include <vector>
using namespace std;
class Item
{
public:
	Item();
	Item(vector <string> Lines);
	~Item();
	string temp;
	string type;
	vector<string>Temporary;
	void ItemBuilder(vector<string>v);
	string name = " ";
	int calories = 0;
	double price = 0;
	string twoFourOne;
	string shareable;
	double volume=0;
	double abv=0;
	//virtual void toString() = 0;
	vector <string> items;
private:

};

