#pragma once
#include "ItemList.h"
#include <vector>

using namespace std;

class Menu :
    public ItemList
{
public:
    Menu(string s);
    int ToString() override;
    vector<string> Lines;

    void fileLoader(string s, vector<string>& Lines);
    void MenuBuilder(vector<string> v);
    string name = " ";
    int calories = 0;
    double price = 0;
    string twoFourOne;
    string shareable;
    double volume = 0;
    double abv = 0;
    string temp;
    string type;
private:

};

