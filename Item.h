#pragma once
#include <string>

using namespace std;

class Item {
public:
    Item();
    ~Item();
    Item(string type,string name, double price, int calories);

    virtual string toString();  

    bool operator<(const Item& other) const;   // Operator overloading to be used in sorting methods. Changes what < and > do.
    bool operator>(const Item& other) const;

    string getType() const;                        // Acessors and mutators. 
    string getName() const;
    double getPrice() const;
    int getCalories() const;

    void setType(const string& newType);
    void setName(const string& newName);
    void setPrice(double newPrice);
    void setCalories(int newCalories);

private:
    string type;
    string name;
    double price;
    int calories;
};
