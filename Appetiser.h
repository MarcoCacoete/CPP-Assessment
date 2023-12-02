#pragma once
#include "Item.h"
class Appetiser :
    public Item
{
public:
    Appetiser();
    Appetiser(string type,string name, double price, int calories, bool shareable, bool twoForOne);

    string toString() override;
    ~Appetiser();
    bool shareable;
    bool twoForOne;

};
