#pragma once
#include "ItemList.h"
#include<vector>
class Menu :
    public ItemList
{
public:
    Menu();
    string toString() override;
    void fileLoader(string s, vector<string>& Lines);
    void MenuBuilder(vector<string> v);
    Menu(string s);
    vector<string> Lines;
    string name = " ";
    int calories = 0;
    double price = 0;
    string twoFourOne;
    string shareable;
    double volume = 0;
    double abv = 0;
    string temp;
    string type;
};

