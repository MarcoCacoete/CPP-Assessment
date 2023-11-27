#pragma once
#include "Item.h"
#include<vector>
class ItemList
{

public:
	ItemList();

	int virtual ToString() = 0;
	virtual ~ItemList();

private:

};

