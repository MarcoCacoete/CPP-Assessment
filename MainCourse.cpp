#include "MainCourse.h"
MainCourse::MainCourse() {


}
MainCourse::MainCourse(string name, double price, int calories) {
	this->name = name;
	this->price = price;
	this->calories = calories;
	char pound = 156;
	cout << "Main Course: " << name << " Price: " <<pound<< price << " Calories: " << calories << endl;

}
MainCourse::~MainCourse()
{
}
;