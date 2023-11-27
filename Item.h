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
	Item(string name,double price,int calories);

	~Item();
	string name;
	double price;
	int calories;
	string virtual ToString() = 0;
private:

};

