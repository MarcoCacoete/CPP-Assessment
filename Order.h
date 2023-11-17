#pragma once
#include "ItemList.h"
#include "Item.h"
class Order :
    public ItemList
{
public:
   void add(Item*);
    double total;

private:
};

