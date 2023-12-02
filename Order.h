#pragma once
#include "ItemList.h"
class Order :
    public ItemList
{
public:
   
    Order();

    string toString();

    vector<Item*> orderList;

    vector<int>quantity;

    void add(vector<Item*>& a, vector<Item*>& b,vector <string> parameters);

    void remove(vector<Item*>& a, vector<Item*>& b, vector<string> parameters);

    double calculateTotal(vector<Item*>orderList);

    void printReceipt();


    vector<int> picks;
    
    double total;


};

