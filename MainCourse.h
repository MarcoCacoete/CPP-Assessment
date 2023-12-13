#pragma once
#include "Item.h"
class MainCourse :
    public Item
{                               // Another child class, inherits all properties from item class.
public:
    MainCourse();
    string toString() override;

    MainCourse(string type,string name, double price, int calories);

    ~MainCourse();
};

