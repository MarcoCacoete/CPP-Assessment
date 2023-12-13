#pragma once
#ifndef _ITEM_LIST_H_
#define _ITEM_LIST_H_

#include <string>
#include <vector>
#include "Item.h"
using namespace std;
                                // Very simple implementation of the abstract class as required in brief. Includes virtua functions for toString and virtual constructor. 
class ItemList
{
public:
    virtual ~ItemList() {}
    virtual string toString() = 0;
    vector<Item*> items;        // Also declareas the items vector, the most important one in the project. Where menu is created.

};


#endif
