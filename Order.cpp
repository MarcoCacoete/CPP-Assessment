#include "Order.h"


Order::Order() {

	cout << "I'm an empty order" << endl;
	vector<Item*> OrderList;

}
Order::Order(const Order& obj) {

	cout << "Created a copy" << endl;
}
Order::~Order() {
	cout << "Destroyed " << "." << endl;
	
}
void Order::toString()
{
}


double total = 0;


void Order::add(Item* obj) {

	OrderList.push_back(obj);
}
