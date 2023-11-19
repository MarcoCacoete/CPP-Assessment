#include "Order.h"


Order::Order() {

	cout << "I'm an empty order" << endl;

}
Order::Order(const Order& obj) {

	cout << "Created a copy" << endl;
}
Order::~Order() {
	cout << "Destroyed " << "." << endl;

}

void Order::add(Item*) {

}