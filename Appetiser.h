#pragma once
#include "Item.h"
class Appetiser :
    public Item
{
public:
    Appetiser();
    Appetiser(string name, double price, int calories, string shareable, string twoForOne);

    string toString() override;
    ~Appetiser();
    string shareable;
    string twoForOne;

};
