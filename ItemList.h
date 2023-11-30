#pragma once
#ifndef _ITEM_LIST_H_
#define _ITEM_LIST_H_

#include <string>
#include <vector>
#include "Item.h"
using namespace std;

class ItemList
{
public:
    virtual string toString() = 0;
    vector<Item*> items;

};


#endif
