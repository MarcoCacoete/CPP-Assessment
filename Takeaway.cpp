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

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();
	
	bool checkoutParam = false;  // I added this boolean for use further down for the purpose of user input error prevention.

	// I'm not sure if we are meant to comment the supplied code, I will do it just in case, if it wasn't required please skip to line 58.
	while (userCommand != "exit") // This while loop waits for user input to match the exit string to exit.
	{

		getline(cin, userCommand);   
		char* cstr = new char[userCommand.length() + 1];   // Creates a character pointer and dinamycally allocates memory for a string that matches user input in size, this was later deleted to prevent leaks.
		strcpy(cstr, userCommand.c_str());				   // This copies the contents of the string resulting from user input into cstr.												

		char* token;
		token = strtok(cstr, " "); // From my interpretation this separates the user input into strings using spaces as a token.

		while (token != NULL)
		{
			parameters.push_back(token);    // It then populates a parameters vector with these strings.
			token = strtok(NULL, " ");
		}

		string command = ";";		// I Think this is used to initialize the command string with a placeholder? I'm not quite sure if that is the point of the ;

		if (!parameters.empty()) {
			command = parameters[0];  //I had to insert this if clause here because otherwise the program would crsah, due to indexing issues if parameters was empty.
		}

		if (checkoutParam == true) {
			command = "checkout";			// This if clause was added by me to force a checkout command if true, as part of a method I tried for user input error prevention (line 109), worked ok.
		}

		if (command.compare("menu") == 0) {
			cout << menu.toString();			
		}

		else if (command.compare("add") == 0)
		{
			
			Item* choice; // you need to instantiate this using the menu object!				


				for (int i = 1; i < parameters.size(); i++) {
					bool check = order.inputCheck(parameters[i], menu.items);   // calls a method I created to validate user inputs, preventing user error, located in order class assigns return to bool.

					if (check == true) {
						int itemNumber = stoi(parameters[i]);  // If the check passes I procede to convert the input to int to then subtract 1 so it matches index, due to menu starting at 1 not 0

						int picked = itemNumber - 1;

						choice = menu.items[picked]; // Implementation of provided skeleton code. assigns specific item pointer to choice to be added to order below

						order.add(choice); // Implementation of provided skeleton code.

						cout << order.toString() << endl;  
					}
				}

			// You may also wish to implement the ability to add multiple items at once!					 This was achieved above.
			// e.g. add 1 5 9 
		}
	
		else if (command.compare("remove") == 0)
		{
			
			order.remove( menu.items,parameters);  // calls remove method in order class to remove multiple items from order or just 1
			
		}
		else if (command.compare("clear") == 0)    // Clears current order, by overwriting order list with empty list, recalculate total to 0.
		{
			order.orderList = order.emptyOrder;
			order.calculateTotal(order.orderList);
			cout << order.toString() << endl;

		}
		else if (command.compare("checkout") == 0)  
		{
			cout << "||||||||||||||||| CHECKOUT |||||||||||||||||||" << endl;
			cout<<"" << endl;
			cout << order.toString() << endl;


			cout << "Are you ready to place your order? (y/n)" << endl;   // Finishes the order and prints receipt to file. Overwriting every time.
			string yOrn;
			cin >> yOrn;
			if (yOrn == "y") {
				order.printReceipt();
				checkoutParam = false;
			}													// a few if clauses for user input, handles user error in a way I never tried before, using the provided skeleton code logic
			else if (yOrn == "n") {
				cout << "Returning to your active order. " << endl;
				checkoutParam = false;
				cout << order.toString() << endl;

			}
			else {
				cout << "Enter a valid option! (y/n) " << endl;
				checkoutParam = true;
			}
		}
		else if (command.compare("original") == 0)
		{												// Reverts sorting to original menu order. Sets some bools to false to properly print tostring.
			menu.setAppetiser(false);
			menu.setBeverage(false);
			menu.setMainCourse(false);
			menu.items= menu.originalItems;
			cout << menu.toString();

		}
		else if (command.compare("ascending") == 0)
		{
			menu.setAppetiser(true);
			menu.setBeverage(true);
			menu.setMainCourse(true);						// Sorts in ascending order. Similar to above, except bools are set to true so that item types don't get printed.
			menu.sortByPriceAscending();				// Implementation found in menu class.
			cout << menu.toString();

		}
		else if (command.compare("descending") == 0)
		{
			menu.setAppetiser(true);
			menu.setBeverage(true);
			menu.setMainCourse(true);			// Exactly as above but in opposite order.
			menu.sortByPriceDescending();
			cout << menu.toString();

		}
		else if (command.compare("help") == 0)   // Several outputs to help user navigate program.
		{
			cout << "" << endl;
			cout << "To view the menu, enter menu." << endl;
			cout << "" << endl;
			cout << "To view the menu sorted in ascending order, enter ascending." << endl;
			cout << "" << endl;
			cout << "To view the menu sorted in descending order, enter descending." << endl;
			cout << "" << endl;
			cout << "To view the menu in the original order enter original." << endl;
			cout << "" << endl;
			cout << "To add to your order, enter add followed by the numbers corresponding to the items, separated by spaces." << endl;
			cout << "Example: add 1 2 2 4 6" << endl;
			cout << "" << endl;
			cout << "To remove items from your order, enter remove followed by the numbers corresponding to the item, separated by spaces." << endl;
			cout << "Example: remove 1 2 2 4 6" << endl;
			cout <<""<<endl;
			cout << "To clear your order, enter clear." << endl;
			cout << "" << endl;
			cout << "To go to checkout, enter checkout followed by y or n to finalize your order or cancel." << endl;
			cout <<"" << endl;
			cout << "To exit, enter exit and press any key after. " << endl;			

		}
		delete[] cstr; // Releases memory allocated above, prevents memory leaks.

		parameters.clear();  //clears parameters every time to stay in loop.
	}

	cout << "Press any key to quit...";
	std::getchar();
}


