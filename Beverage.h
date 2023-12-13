#pragma once
#include "Item.h"
class Beverage :
    public Item
{
public:     // Everything in this child class is similar to appetiser class, except a few variables and methods like isAlcoholic and volume abv alc also similar toString, but for beverages.
    Beverage();
    Beverage(string type,string name, double price, int calories, double volume, double abv);
    ~Beverage();

    string toString() override;
    bool isAlcoholic(double abv);  // Also implemented this method as required in brief.

    double getVolume();
    double getAbv();
    bool getAlc();

    void setVolume(const double& newVolume);
    void setAbv(const double& newAbv);
    void setAlc(const bool& newAlc);

private:
    double volume = 0;
    double abv = 0;
    bool alc;
};

