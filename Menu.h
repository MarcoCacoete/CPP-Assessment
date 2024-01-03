#pragma once
#include "ItemList.h"
#include<vector>
class Menu :
    public ItemList
{
public:

    Menu();     //Constructors and destructors

    Menu(string s);

    ~Menu();

    string toString();  //  To string methods and all class methods below.

    void fileLoader(string s, vector<string>& Lines);  // My file loader method, loads csv files for use in program.

    void MenuBuilder(vector<string> v);  // Menu building method.

    void sortByPriceAscending();  // Sorter methods as suggested in brief, change menu order by price ascending/descending.

    void sortByPriceDescending();

    vector <Item*> originalItems; // All class variables, vectors accessors and mutators.
   
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

