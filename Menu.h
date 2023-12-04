#pragma once
#include "ItemList.h"
#include<vector>
class Menu :
    public ItemList
{
public:

    Menu();

    Menu(string s);

    ~Menu();

    string toString();

    void fileLoader(string s, vector<string>& Lines);

    void MenuBuilder(vector<string> v);
   
    vector <string> Lines;

    string type;

    string name;

    string temp;

    int calories;

    bool shareable;

    bool twoFourOne;

    double volume;

    double abv;

    double price;
};

