#pragma once
#include "Item.h"
class MainCourse :
    public Item
{
public:
    MainCourse();
    MainCourse(string name, double price,int calories);
    virtual string ToString() override;

    ~MainCourse();
};

