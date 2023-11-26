#pragma once
#include "ItemList.h"
#include "Item.h"
class Order :
    public ItemList
{
public:
    Order();
    Order(const Order& obj);
    ~Order();
    void toString() override;

   void add(Item* obj);
    double total;
    vector<Item*> OrderList;
private:
};

