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
   void add(Item*);
    double total;

private:
};

