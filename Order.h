#pragma once
#include "ItemList.h"
class Order :
    public ItemList
{
public:

    Order(); //Constructor and destructor
    ~Order();

    string toString(); // toString method

    vector<Item*> orderList;  // Vectors

    vector<Item*> emptyOrder;

    vector<int>quantity;

    vector<int> picks;

    void add(Item*);            // Method for adding items to order.

    void remove(vector<Item*> items, vector<string> parameters); // Method to remove items.

    double calculateTotal(vector<Item*>orderList);  // Calculate total method.

    void printReceipt();                            // Receipt printing method.

    bool inputCheck(string v, vector<Item*> t);     // My checker to correct user input in add and remove methods.

    double getTotal() { return total; }     // Accessors and mutators
    void setTotal(double t) { total = t; }

    double getDiscount() { return discount; }
    void setDiscount(double d) { discount = d; }

private:
    double total;
    double discount;
};
