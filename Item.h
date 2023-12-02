#pragma once
#include <string>

using namespace std;

class Item {
public:
    Item();
    ~Item();
    Item(string type,string name, double price, int calories);
    virtual string toString();
    string type;
    string name;
    double price;
    int calories;
private:
    // ... any private members
};
