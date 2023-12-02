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
    bool alc;
    Beverage(string type,string name, double price, int calories, double volume, double abv);
    bool isAlcoholic(double abv);
    ~Beverage();
private:
};

