#pragma once
#include "ItemList.h"
class Order :
    public ItemList
{
public:
   
    Order();
    ~Order();


    string toString();

    vector<Item*> orderList;

    vector<Item*> emptyOrder;


    vector<int>quantity;

    void add(Item*);

    void remove(vector<Item*> items, vector<string> parameters);

    double calculateTotal(vector<Item*>orderList);

    void printReceipt();

    bool inputCheck(string v, vector<Item*> t);

    vector<int> picks;
private:
    double total;

    double discount;

};

