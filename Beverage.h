#pragma once
#include "Item.h"
class Beverage :
    public Item
{
public:
    Beverage();
    string toString() override;

    double volume = 0;
    double abv = 0;

    Beverage(string name, double price, int calories, double volume, double abv);
    ~Beverage();
private:
};

