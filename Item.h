#pragma once
#include <string>

using namespace std;

class Item {
public:
    Item();
    ~Item();
    Item(string name, double price, int calories);
    virtual string toString();
    string name;
    double price;
    int calories;
private:
    // ... any private members
};
