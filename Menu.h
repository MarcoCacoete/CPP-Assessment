#pragma once
#include "ItemList.h"
#include <vector>

using namespace std;

class Menu :
    public ItemList
{
public:
    Menu(string s);

    void fileLoader(string s);

    int toString();

private:

};

