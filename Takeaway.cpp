/* ------------------------------------------------------
CMP2811 Applied Programming Paradigms
Driver program for "Takeaway" assignment
Autumn 2023

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"
#include "ItemList.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;


int main()
{
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();
	
	while (userCommand != "exit")
	{
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		string command = ";";

		if (!parameters.empty()) {
			command = parameters[0];
		}

		if (command.compare("menu") == 0) {
			cout << menu.toString();
		}

		else if (command.compare("add") == 0)
		{
			

			Item* choice; // you need to instantiate this using the menu object!


			for (int i = 1; i < parameters.size(); i++) {
				int itemNumber = stoi(parameters[i]);

				int picked = itemNumber - 1;

				choice = menu.items[picked];

				order.add(choice);
			}

			cout<<order.toString()<<endl;


			// You may also wish to implement the ability to add multiple items at once!
			// e.g. add 1 5 9 
		}
	
		else if (command.compare("remove") == 0)
		{
			
			order.remove(order.orderList, menu.items,parameters);
			
		}
		else if (command.compare("checkout") == 0)
		{
			cout << "Are you ready to place your order? (y/n)" << endl;
			string yOrn;
			cin >> yOrn;
			if (yOrn == "y") {
				order.printReceipt();
			}
		}
		else if (command.compare("help") == 0)
		{
			cout << "" << endl;
			cout << "To view the menu, enter menu." << endl;
			cout << "" << endl;
			cout << "To add to your order, enter add followed by the numbers corresponding to the item, separated by spaces." << endl;
			cout << "" << endl;
			cout << "To remove items to your order, enter remove followed by the numbers corresponding to the item, separated by spaces." << endl;
			cout <<""<<endl;
			cout << "To go to checkout, enter checkout followed by y or n to finalize your order or cancel." << endl;
			cout <<"" << endl;
			cout << "To exit, enter exit and press any key after. " << endl;			

		}

		parameters.clear();
		delete[] cstr;
	}

	cout << "Press any key to quit...";
	std::getchar();
}