#pragma once
#include "Item.h"
class Appetiser :
    public Item
{
public:
    Appetiser();  // Default constructor and custom constructor for child class.
    Appetiser(string type,string name, double price, int calories, bool shareable, bool twoForOne);

    string toString() override; // Overriden to string method, inherited from item.
    ~Appetiser();       // Destructor followed by the variables specified in brief.

    bool getShareable() const;
    bool getTwoForOne() const;
                                                    // Accessor and mutators.
    void setShareable(const bool& newShareable);
    void setTwoForOne(const bool& newTwoForOne);
   

private:
    bool shareable;
    bool twoForOne;

};
