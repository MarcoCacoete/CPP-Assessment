#pragma once
#include "ItemList.h"
#include <vector>

using namespace std;

class Menu :
    public ItemList
{
public:
    Menu(string s);
    void toString() override;
    void fileLoader(string s);
    
private:

};

