#pragma once
#include "Item.h"
class MainCourse :
    public Item
{
public:
    MainCourse();
    string toString() override;

    MainCourse(string type,string name, double price, int calories);

    ~MainCourse();
};

