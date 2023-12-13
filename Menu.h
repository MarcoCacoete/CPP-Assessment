#pragma once
#include "ItemList.h"
#include<vector>
class Menu :
    public ItemList
{
public:

    Menu();

    Menu(string s);

    ~Menu();

    string toString();

    void fileLoader(string s, vector<string>& Lines);

    void MenuBuilder(vector<string> v);

    void sortByPriceAscending();

    void sortByPriceDescending();

    vector <Item*> originalItems;
   
    vector <string> Lines;


    string getType() const;

    string getName() const;

    string getTemp() const;

    int getCalories() const;

    bool getAppetiser() const;

    bool getBeverage() const;

    bool getMainCourse() const;

    double getVolume() const;

    double getAbv() const;

    bool getShareable() const;

    bool getTwoForOne() const;

    void setTwoForOne(bool value);

    void setAbv(double newAbv);

    double getPrice() const;

    void setType(const string& newType);

    void setName(const string& newName);

    void setTemp(const string& newTemp);

    void setCalories(int newCalories);

    void setAppetiser(bool isAppetiser);

    void setBeverage(bool isBeverage);

    void setMainCourse(bool isMainCourse);

    void setVolume(double newVolume);

    void setPrice(double newPrice);

    void setShareable(bool value);



private:

    string type;

    string name;

    string temp;

    int calories;

    bool appetiser;

    bool beverage;

    bool mainCourse;

    bool shareable;

    bool twoFourOne;

    double volume;

    double abv;

    double price;

    

};

