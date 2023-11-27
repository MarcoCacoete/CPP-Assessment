#pragma once
#include "Item.h"
class Beverage :
    public Item
{
public:
    Beverage();
    double volume = 0;
    double abv = 0;

    Beverage(string name, double price, int calories, double volume, double abv);
    virtual string ToString() override;

    ~Beverage();
private:
};

