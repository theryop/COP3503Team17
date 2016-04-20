#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <iomanip>
#include <math.h>


using namespace std;

class items { //constructor for the item class
private:
	string itemName;
	double itemPrice;
	int itemCreativity;
	int itemActivity;
	int itemComplexity;
public:
	items(string n, double p, int c, int a, int comp) :itemName(n)
		, itemPrice(p)
		, itemCreativity(c)
		, itemActivity(a)
		, itemComplexity(comp)
	{}

	string getItemName() {
		return itemName;
	}

	double getItemPrice() {
		return itemPrice;
	}

	int getItemCreativity() {
		return itemCreativity;
	}

	int getItemActivity() {
		return itemActivity;
	}

	int getItemComplexity() {
		return itemComplexity;
	}
};

class employees { //constructor for employee class
private:
	string empName;
	string empUsername;
	string empPassword;
	double empTotalSales;
public:
	employees(string n, string u, string pw, double tSales) :empName(n)
		, empUsername(u)
		, empPassword(pw)
		, empTotalSales(tSales)
	{}

	string getEmpName() {
		return empName;
	}

	string getEmpUsername() {
		return empUsername;
	}

	string getEmpPassword() {
		return empPassword;
	}

	double getEmpTotalSales() {
		return empTotalSales;
	}

	void setEmpTotalSales(double s) {
		empTotalSales = s;
	}
};

class Customer
{
private:
	const string customername;
	string customerage;
	vector<string> shoppingBasket;

public:
	Customer(string cn, string ca) {};
	string getCustomerName() { return customername; }
	string getCustomerAge() { return customerage; }
	void addPurchase(string item) {
		//adds a gift to the customer's shopping basket 
		if (cartContains(item)) {
			cout << "you already have this item in your cart!" << endl;
		}
		else {
			shoppingBasket.push_back(item);
		}
	}
	void printPurchase() {
		//prints out all items in the customer's basket 
		cout << "these are the items you have in your basket" << endl;
		for (int i = 0; i<shoppingBasket.size(); i++) {
			cout << shoppingBasket[i] << endl;
		}
	}
	bool cartContains(string item) {
		//checks if customer is trying to add an item to their cart that they already have
		for (int i = 0; i<shoppingBasket.size(); i++) {
			if (shoppingBasket[i] == item) {
				return true;
			}
		}
		return false;
	}

};

void bestFitItem(vector<items> & recommendedItems, vector<items> vectorOfItems, int c, int a, int comp);

//finds the best fit item for user based on their characteristics
void bestFitItem(vector<items> & recommendedItems, vector<items> vectorOfItems, int c, int a, int comp) {
	int difference;
	int minDiff = 1;
	int diffCreativity;
	int diffActivity;
	int diffComplexity;
	//iterates through vector of inventory objects to find "least distance" between user characteristics and item characteristics
	while (true) {
		for (int i = 0; i<vectorOfItems.size(); i++) {
			diffCreativity = abs(c - vectorOfItems[i].getItemCreativity());
			diffActivity = abs(a - vectorOfItems[i].getItemActivity());
			diffComplexity = abs(comp - vectorOfItems[i].getItemComplexity());
			difference = diffComplexity + diffActivity + diffCreativity;
			if (difference < minDiff) {
				recommendedItems.push_back(vectorOfItems[i]);
			}
		}
		if (recommendedItems.empty()) {
			minDiff += 1;
		}
		else {
			break;
		}
	}
};


/*
void userLoggedIn() {
while( true ) {
cout << "What would you like to do?" << endl;
cout << "1. Restock" << endl;
cout << "2. Make a sale" << endl;
cout << "3. Check inventory" << endl;
cout << "4. Exit" << endl;
int loggedInInput;
cin >> loggedInInput;
if ( loggedInInput == 1 ) {
//takes in input for creativity/activity/complexity
//creates item
//pushes on to vectorOfItems
int creativity;
int activity;
int complexity;
string name;
// make name all lowercase
int price;
vectorOfItems.push_back(item(name, price, creativity, activity, complexity));
}
else if ( loggedInInput == 2 ) {
//takes in input of item name
//removes first found item from vectorOfItems
//add to sale count of employee -> increments value of count for employee
// again this would be better in main function because we can keep track of employee with a variable equal to the username
string purchaseName;
// make all lowercase
for (int i = 0; i < vectorOfItems.size(); i++) {
if (purchaseName == vectorOfItems[i].getItemName) {
vectorOfEmployees[currentEmployee].totalSales++;
//deletes item in vector
vectorOfItems.erase(vectorOfItems.begin() + i);
}
}
}
else if ( loggedInInput == 3 ) {
//loops through vectorOfItems and prints each itemName and itemPrice
cout << "Current in stock: " << endl;
for (int i = 0; i < vectorOfItems.size(); i++) {
cout << "Item: " <<vectorOfItems[i].getItemName << " Price: " << vectorOfItems[i].getItemPrice << endl;
}
}
else if ( loggedInInput == 4 ) {
break;
}
} // end of while loop for user logged in
}
*/

bool isNumber(string str) {
	for (size_t i = 0; i < str.length(); i++) {
		if(!isdigit(str.at(i))) {
			return false;
		} 
	}
	return true;
}

bool isDouble(string str) {
	int numPeriods = 0;
	for (size_t i = 0; i < str.length(); i++) {
		if (!(isdigit(str.at(i)) || str.at(i) == '.')) {
			return false;
		}
		if (str.at(i) == '.') {
			numPeriods++;
		}
	}
	if (numPeriods > 1) {
		return false;
	}
	return true;
}

int main() {
	vector<items> vectorOfItems; //creates the vector of items
	vector<employees> vectorOfEmployees; //creates the vector of employees
	
	vector<items> recommendedItems; //creates the vector of recommended items

	int currentEmployee;

	// the following code is an example of what can be held in the database
	int example = 0;
	while (example < 3)
	{
		vectorOfItems.push_back(items("ball", 2.50, 2, 5, 1));
		example++;
	}
	example = 0;
	while (example < 3)
	{
		vectorOfItems.push_back(items("rubix's cube", 3.75, 2, 1, 5));
		example++;
	}
	example = 0;
	while (example < 3)
	{
		vectorOfItems.push_back(items("coloring book", 2.25, 4, 1, 2));
		example++;
	}
	example = 0;
	while (example < 3)
	{
		vectorOfItems.push_back(items("keyboard", 25.50, 4, 1, 4));
		example++;
	}
	example = 0;
	while (example < 3)
	{
		vectorOfItems.push_back(items("dance lessons", 15.50, 5, 5, 4));
		example++;
	}
	example = 0;
	while (example < 3)
	{
		vectorOfItems.push_back(items("chalk", 5.25, 5, 4, 1));
		example++;
	}
	example = 0;
	while (example < 3)
	{
		vectorOfItems.push_back(items("exercise machine", 175.25, 1, 4, 4));
		example++;
	}
	example = 0;
	while (example < 3)
	{
		vectorOfItems.push_back(items("pinwheel", 1.25, 2, 1, 1));
		example++;
	}

	//initial prompt for user to select employee or customer
	cout << "Welcome to the shop! Are you an employee or customer?" << endl;
	cout << "1. Employee" << endl;
	cout << "2. Customer" << endl;
	string userInput = "";
	int firstInput = 0;
	bool hello = true;

	while (firstInput != 1 && firstInput != 2) { //input validation for the first menu choice
		bool isNum = true;
		cout << endl;
		getline(cin, userInput);
		//the following for loop checks to see if the user inputed a number
		for (size_t i = 0; i < userInput.length(); i++) {
			if (!isdigit(userInput.at(i))) {
				isNum = false;
			}
		}
		//if the input is a number, convert the string to an int which will dictate where the code continues
		if (isNum) {
			firstInput = atoi(userInput.c_str());
		}
		if (firstInput == 1) { //entry points for the employee login
			if (hello) { //only prints the "Hello Employee!" statement once so as to not sound redundant
				cout << "Hello Employee! Please login or register for an account." << endl;
				hello = false;
			}
			cout << "1. Login" << endl;
			cout << "2. Register" << endl;
			cout << "3. Exit" << endl;
			int secondInput = 0;
			string secondUserInput = "";
			while (secondInput != 1 && secondInput != 2 && secondInput != 3) {
				bool isNum2 = true;
				cout << endl;
				getline(cin,secondUserInput);
				for (size_t i = 0; i < secondUserInput.length(); i++) {
					if (!isdigit(secondUserInput.at(i))) {
						isNum2 = false;
					}
				}
				if (isNum2) {
					secondInput = atoi(secondUserInput.c_str());
				}
				if (secondInput == 1) {
					string username;
					string password;
					cout << "LOGIN SCREEN" << endl;
					cout << "Username: ";
					getline(cin, username);
					cout << "Password: ";
					getline(cin, password);
					bool isAuthenticated = false;
					//Iterate through vector and compare username/password -> write a method to return true/false
					for (size_t i = 0; i < vectorOfEmployees.size(); i++) {
						if (username == vectorOfEmployees[i].getEmpUsername() && password == vectorOfEmployees[i].getEmpPassword()) {
							currentEmployee = i;
							isAuthenticated = true;
							break;
						}
					}
					if (isAuthenticated) {
						//write function for logged in prompts for employees
						//userLoggedIn(); <---__******


						//might put code directly in here because it would be easier to append to vector, check username for sales... etc
						bool loginFirstTime = true;
						string userLoggedInInput = "";
						int loggedInInput = 0;
						bool isNum3 = true;
							while (loggedInInput != 1 && loggedInInput != 2 && loggedInInput != 3 && loggedInInput != 4 && loggedInInput != 5) {
								isNum3 = true;
								if (loginFirstTime) {
									cout << endl << "Login successful." << endl;
								}
								loginFirstTime = false;
								cout << "What would you like to do?" << endl;
								cout << "1. Restock" << endl;
								cout << "2. Make a sale" << endl;
								cout << "3. Check inventory" << endl;
								cout << "4. Check total sales" << endl;
								cout << "5. Logout" << endl;
								cout << endl;
								getline(cin, userLoggedInInput);
								if (userLoggedInInput.length() == 0) {
									isNum3 = false;
								}
								for (size_t i = 0; i < userLoggedInInput.length(); i++) {
									if (!isdigit(userLoggedInInput.at(i))) {
										isNum3 = false;
									}
								}
								if (isNum3) {
									loggedInInput = atoi(userLoggedInInput.c_str());
								}
								if (loggedInInput == 1) { //RESTOCK METHOD
									//takes in input for creativity/activity/complexity
									//creates item
									//pushes on to vectorOfItems

									//VALUES ARE TEMPORARY
									int creativity = 0;
									int activity = 0;
									int complexity = 0;
									string creativityStr = "";
									string activityStr = "";
									string complexityStr = "";
									string name = "";
									string n = "";
									// make name all lowercase
									double price = 0;
									string priceStr = "";
									cout << "What is the name of item you'd like to restock?" << endl;
									getline(cin, n);
									size_t counter = 0;
									char c;
									while (counter < n.length()) //converts all characters in string to lowercase
									{
										c = n[counter];
										if (isupper(c))
										{
											n[counter] = tolower(c);
										}
										counter++;
									}
									name = n;
									counter = 0;
									size_t counter2 = 0;
									string restockchoiceStr = "";
									int restockchoice = 0;
									bool alreadychecked = false;
									bool usingprevious = false;
									vector<items> vectorOfCheckedItems;
									while (counter < vectorOfItems.size()) // checks to see if an item with the same name has already been added to the inventory, and prompts user if they would like to use these stats
									{
										while (counter2 < vectorOfCheckedItems.size()) // checks to see if the item is the same as what has previously been offered
										{
											if ((vectorOfCheckedItems[counter2].getItemName() == vectorOfItems[counter].getItemName()) && (vectorOfCheckedItems[counter2].getItemPrice() == vectorOfItems[counter].getItemPrice()) && (vectorOfCheckedItems[counter2].getItemCreativity() == vectorOfItems[counter].getItemCreativity()) && (vectorOfCheckedItems[counter2].getItemActivity() == vectorOfItems[counter].getItemActivity()) && (vectorOfCheckedItems[counter2].getItemComplexity() == vectorOfItems[counter].getItemComplexity()))
											{
												alreadychecked = true;
											}
											counter2++;
										}
										if ((vectorOfItems[counter].getItemName() == name) && !alreadychecked)
										{
											cout << name << " has been found in our inventory with a price of " << vectorOfItems[counter].getItemPrice() << ", " << vectorOfItems[counter].getItemCreativity() << " Creativity, " << vectorOfItems[counter].getItemActivity() << " Activity, and " << vectorOfItems[counter].getItemComplexity() << " complexity. Would you like to use these statistics?" << endl;
											cout << "1. Yes" << endl;
											cout << "2. No" << endl;
											getline(cin, restockchoiceStr);
											if (isNumber(restockchoiceStr)) { //input validation for the restockchoice variable
												restockchoice = atoi(restockchoiceStr.c_str());
											}
											while (!isNumber(restockchoiceStr) || restockchoice != 1 && restockchoice != 2) {
												cout << "Not a valid choice. Please enter 1 for Yes and 2 for No." << endl;
												getline(cin, restockchoiceStr);
												if (isNumber(restockchoiceStr)) {
													restockchoice = atoi(restockchoiceStr.c_str());
												}
											}
											//if the user wants to use same data from the previous item, create a duplicate
											//and push it into the inventory
											if (restockchoice == 1)
											{
												price = vectorOfItems[counter].getItemPrice();
												creativity = vectorOfItems[counter].getItemCreativity();
												activity = vectorOfItems[counter].getItemActivity();
												complexity = vectorOfItems[counter].getItemComplexity();
												usingprevious = true;
												break;
											}
											//otherwise create a item and push it into the inventory
											else if (restockchoice == 2)
											{
												vectorOfCheckedItems.push_back(vectorOfItems[counter]);
											}
										}

										counter++;
									}
									if (!usingprevious)
									{
										cout << "What is the selling price for this item?" << endl;
										cout << "$";
										getline(cin, priceStr);
										if (isDouble(priceStr)) { //input validation for the price variable
											price = atof(priceStr.c_str());
											price = floor((100.*price) + .5) / 100.;
										}
										while (!isDouble(priceStr)) {
											cout << "Not a valid choice. Please enter a valid price." << endl;
											getline(cin, priceStr);
											if (isDouble(priceStr)) {
												price = atof(priceStr.c_str());
												price = floor((100.*price) + .5) / 100.;
											}
										}
										cout << "What is the creativity value associated with the item? (Scale of 1-5)" << endl;
										getline(cin, creativityStr);
										if (isNumber(creativityStr)) { //input validation for the creativity variable
											creativity = atoi(creativityStr.c_str());
										}
										while (!isNumber(creativityStr) || creativity < 1 || creativity > 5) {
											cout << "Not a valid choice. Please enter an integer value between 1 and 5 inclusive." << endl;
											getline(cin, creativityStr);
											if (isNumber(creativityStr)) {
												creativity = atoi(creativityStr.c_str());
											}
										}
										cout << "What is the activity value associated with the item? (Scale of 1-5)" << endl;
										getline(cin, activityStr);
										if (isNumber(activityStr)) { //input validation for the activity variable
											activity = atoi(activityStr.c_str());
										}
										while (!isNumber(activityStr) || activity < 1 || activity > 5) {
											cout << "Not a valid choice. Please enter an integer value between 1 and 5 inclusive." << endl;
											getline(cin, activityStr);
											if (isNumber(activityStr)) {
												activity = atoi(activityStr.c_str());
											}
										}
										cout << "What is the complexity value associated with the item? (Scale of 1-5)" << endl;
										getline(cin, complexityStr);
										if (isNumber(complexityStr)) { //input validation for the complexity variable
											complexity = atoi(complexityStr.c_str());
										}
										while (!isNumber(complexityStr) || complexity < 1 || complexity > 5) {
											cout << "Not a valid choice. Please enter an integer value between 1 and 5 inclusive." << endl;
											getline(cin, activityStr);
											if (isNumber(complexityStr)) {
												complexity = atoi(complexityStr.c_str());
											}
										}
									}

									vectorOfItems.push_back(items(name, price, creativity, activity, complexity));
									cout << name << " successfully restocked!" << endl;
									loggedInInput = 0; //need this so the loop continues until it exits
								}

								else if (loggedInInput == 2)
								{
									//takes in input of item name
									//removes first found item from vectorOfItems
									//add to sale count of employee -> increments value of count for employee
									// again this would be better in main function because we can keep track of employee with a variable equal to the username
									string purchaseName;
									bool success = false;
									// make all lowercase
									cout << "What was the name of the item you sold?" << endl;
									getline(cin, purchaseName);
									size_t counter = 0;
									char c;
									while (counter < purchaseName.length()) //converts all characters in string to lowercase
									{
										c = purchaseName[counter];
										if (isupper(c))
										{
											purchaseName[counter] = tolower(c);

										}
										counter++;
									}

									for (size_t i = 0; i < vectorOfItems.size(); i++)
									{
										if (purchaseName == vectorOfItems[i].getItemName())
										{
											cout << "We have found a(n) " << purchaseName << " with a price of $" << vectorOfItems[i].getItemPrice() << " Proceed with transaction?" << endl;
											cout << "1. Yes" << endl;
											cout << "2. No" << endl;
											int pchoice = 0;
											string pchoiceStr = "";
											getline(cin, pchoiceStr);
											if (isNumber(pchoiceStr)) { //input validation for the complexity variable
												pchoice = atoi(pchoiceStr.c_str());
											}
											while (!isNumber(pchoiceStr) || pchoice != 1 && pchoice != 2) {
												cout << "Not a valid choice. Please enter 1 for Yes or 2 for No." << endl;
												getline(cin, pchoiceStr);
												if (isNumber(pchoiceStr)) {
													pchoice = atoi(pchoiceStr.c_str());
												}
											}
											if (pchoice == 1)
											{
												//NEED TO CHECK THE FOLLOWING CODE TO SEE IF IT WORKS ONCE WE IMPLEMENT A CHECK TOTAL SALES METHOD
												vectorOfEmployees[currentEmployee].setEmpTotalSales(vectorOfEmployees[currentEmployee].getEmpTotalSales() + vectorOfItems[i].getItemPrice());
												vectorOfItems.erase(vectorOfItems.begin() + i);//deletes item in vector
												cout << "Successful Transaction" << endl;
												success = true;
											}
										}
									}
									if (!success)
									{
										cout << "Failed to sell item!" << endl;
									}
									loggedInInput = 0;
								}

								else if (loggedInInput == 3) {
									//loops through vectorOfItems and prints each itemName and itemPrice
									cout << "Current in stock: " << endl;
									for (size_t i = 0; i < vectorOfItems.size(); i++) {
										cout << "Item: " << vectorOfItems[i].getItemName() << " Price: $" << vectorOfItems[i].getItemPrice() << endl;
									}
									loggedInInput = 0;
								}

								else if (loggedInInput == 4) {
									cout << "Employee " << vectorOfEmployees[currentEmployee].getEmpName() << " has sold items in total of $" << vectorOfEmployees[currentEmployee].getEmpTotalSales() << endl;
									loggedInInput = 0;
								}

								else if (loggedInInput == 5) {
									cout << "Logout successful." << endl;
									secondInput = 0;							
								}
								else {
									cout << "Error. Not a valid choice. Please try again." << endl;
									loggedInInput = 0;
								}
							} //end of Employee options loop
						//} // end of while loop for user logged in GIVING PROBLEMS RN
					}
					else { //if (!isAuthenticated)
						secondInput = 0;
						hello = true;
						cout << endl << "Login Unsuccesful. Invalid username or password. Please try again." << endl;
					}
				}

				else if (secondInput == 2) {
					string name;
					string username;
					string password;
					cout << "NEW ACCOUNT REGISTRATION SCREEN" << endl;
					cout << "Please enter the following information to register for a new account." << endl;
					cout << "Name: ";
					getline(cin, name);
					cout << "Username: ";
					getline(cin, username);
					cout << "Password: ";
					getline(cin, password);

					//validate for uniqueness of account
					//will return true of false value which will be used in this conditional
					bool isUnique = true;
					for (size_t i = 0; i < vectorOfEmployees.size(); i++) {
						if (username == vectorOfEmployees[i].getEmpUsername()) {
							isUnique = false;
							break;
						}
					}

					if (isUnique) {
						int sales = 0;
						vectorOfEmployees.push_back(employees(name, username, password, sales));
						cout << "Thank you for registering, " << name << "! Please log in with your new credentials." << endl << endl;
						secondInput = 0;
					}
					else {
						//prints and loop will run again
						cout << "Username already taken!" << endl << endl;
						secondInput = 0;
					}
				}

				else if (secondInput == 3) {
					firstInput = 0;
					cout << "Welcome to the shop! Are you an employee or customer?" << endl;
					cout << "1. Employee" << endl;
					cout << "2. Customer" << endl;
					hello = true;
					break;
				}
				else {
					cerr << "Error, not a valid choice. Please enter either 1 to login, 2 to register, or 3 to go back." << endl;
				}
				cout << "1. Login" << endl;
				cout << "2. Register" << endl;
				cout << "3. Exit" << endl;
			} // closing bracket for top while loop
		} //closing bracket for if employee
		else if (firstInput == 2) { //entry point for customer
			string cn;
			string age;
			cout << "Hello customer! Please enter your name" << endl;
			getline(cin, cn);

			cout << "Please enter your age" << endl;
			getline(cin, age);

			Customer *customer = new Customer(cn, age);

			cout << "1. Purchase item" << endl;		//search by name, instock? remove from list, display price
			cout << "2. Find gift" << endl;			//go to questionnaire
			cout << "3. Display all" << endl;		//loop through vector and print inventory
			cout << "4. Exit" << endl;

			bool keepgoing = true;
			int secondinput = 0;
			string input1 = "";
			while (secondinput != 1 && secondinput != 2 && secondinput != 3 && keepgoing) {
				bool isNum1 = true;
				cin >> input1;
				for (size_t j = 0; j < input1.length(); j++) {
					if (!isdigit(input1.at(j))) {
						isNum1 = false;
					}
				}
				if (isNum1) {
					secondinput = atoi(input1.c_str());
				}
				if (secondinput == 1) {
					int index;
					string input;
					string temp;
					cout << "Enter the name of the item: " << endl;
					getline(cin, input);
					getline(cin, input);
					for (unsigned int i = 0; i<input.length(); i++) {
						input[i] = tolower(input[i]);
					}
					bool isInStock = false;
					for (size_t i = 0; i < vectorOfItems.size(); i++) {
						if (vectorOfItems[i].getItemName() == input) {
							isInStock = true;
							index = i;
						}
					}
					if (!isInStock) {
						cout << "Sorry, that item is not in stock" << endl;
					}
					else {
						cout << input << "'s are " << vectorOfItems[index].getItemPrice() << " each. Purchase?" << endl;
						cout << "1. Yes" << endl;
						cout << "2. No" << endl;
						string option;
						int choice; 	
						
						getline(cin, option);
						while (choice != 2) 
						{
							while (!isNumber(option)) {
						cout << endl << "Not a valid choice. Please enter 1 or 2." << endl;
						getline(cin, option);
						}
						choice = atoi(option.c_str());

							if (choice == 1) 
							{
								cout << "Congratulations, you purchased a(n) " << vectorOfItems[index].getItemName() << "!" << endl;
								vectorOfItems.erase(vectorOfItems.begin() + index);
								break;
							}
							else {
								cout << "Invalid choice. Purchase?" << endl;
								cout << "1. Yes" << endl;
								cout << "2. No" << endl;
								getline(cin, option);
							}
						}
					}
				}
				else if (secondinput == 2) {
					string userchoice;
					int userpref;
					int creativity = 0;
					int activity = 0;
					int complexity = 0;
					string tempchoice = "";
					cout << "please answer the following questions with either a 1 or 2 so we can match you to your perfect item" << endl;
					cout << "Would you rather 1. paint a picture or 2. ride a bike?" << endl;
					getline (cin,tempchoice);
					
					getline (cin,userchoice);
					while (!isNumber(userchoice)|| userpref != 1 && userpref != 2) 
					{
						cout << "Not a valid choice. Please enter 1 or 2." << endl;
						getline(cin, userchoice);
						if (isNumber(userchoice))
						{
							userpref = atoi(userchoice.c_str());
						}
					}	
					if (userpref == 1) {
						creativity += 3;
						activity -= 1;
					}
					else if (userpref == 2) {
						activity += 3;
					}
					cout << "Can you solve a Rubiks Cube? 1. yes 2. no" << endl;
					userpref = 0;
					getline (cin,userchoice);
					while (!isNumber(userchoice)|| userpref != 1 && userpref != 2) 
					{
						cout << "Not a valid choice. Please enter 1 or 2." << endl;
						getline(cin, userchoice);
						if (isNumber(userchoice))
						{
							userpref = atoi(userchoice.c_str());
						}
					}	
					if (userpref == 1) {
						complexity += 2;
					}
					else if (userpref == 2) {
						complexity -= 1;
					}
					cout << "Have you ever watched a Marvel movie? 1. yes 2. no " << endl;
					userpref = 0;
					getline (cin,userchoice);
					while (!isNumber(userchoice)|| userpref != 1 && userpref != 2) 
					{
						cout << "Not a valid choice. Please enter 1 or 2." << endl;
						getline(cin, userchoice);
						if (isNumber(userchoice))
						{
							userpref = atoi(userchoice.c_str());
						}
					}
					if (userpref == 1) {
						creativity += 1;
					}
					cout << "Can you see yourself skydiving? 1. yes 2. no" << endl;
					userpref = 0;
					getline (cin,userchoice);
					while (!isNumber(userchoice)|| userpref != 1 && userpref != 2) 
					{
						cout << "Not a valid choice. Please enter 1 or 2." << endl;
						getline(cin, userchoice);
						if (isNumber(userchoice))
						{
							userpref = atoi(userchoice.c_str());
						}
					}
					if (userpref == 1) {
						activity += 3;
					}
					cout << "Is your spirit animal moreso 1. a cheetah or 2. a sloth" << endl;
					userpref = 0;
					getline (cin,userchoice);
					while (!isNumber(userchoice)|| userpref != 1 && userpref != 2) 
					{
						cout << "Not a valid choice. Please enter 1 or 2." << endl;
						getline(cin, userchoice);
						if (isNumber(userchoice))
						{
							userpref = atoi(userchoice.c_str());
						}
					}
					if (userpref == 1) {
						activity += 2;
					}
					else if (userpref == 2) {
						activity -= 2;
					}
					cout << "Do you believe in aliens? 1. yes 2. no" << endl;
					userpref = 0;
					getline (cin,userchoice);
					while (!isNumber(userchoice)|| userpref != 1 && userpref != 2) 
					{
						cout << "Not a valid choice. Please enter 1 or 2." << endl;
						getline(cin, userchoice);
						if (isNumber(userchoice))
						{
							userpref = atoi(userchoice.c_str());
						}
					}
					if (userpref == 1) {
						creativity += 2;
						complexity += 1;
					}
					cout << "Can you do a backflip? 1. yes 2. no" << endl;
					userpref = 0;
					getline (cin,userchoice);
					while (!isNumber(userchoice)|| userpref != 1 && userpref != 2) 
					{
						cout << "Not a valid choice. Please enter 1 or 2." << endl;
						getline(cin, userchoice);
						if (isNumber(userchoice))
						{
							userpref = atoi(userchoice.c_str());
						}
					}
					if (userpref == 1) {
						activity += 4;
					}
					cout << "1. Super Smash or 2. volleyball?" << endl;
					userpref = 0;
					getline (cin,userchoice);
					while (!isNumber(userchoice)|| userpref != 1 && userpref != 2) 
					{
						cout << "Not a valid choice. Please enter 1 or 2." << endl;
						getline(cin, userchoice);
						if (isNumber(userchoice))
						{
							userpref = atoi(userchoice.c_str());
						}
					}
					if (userpref == 1) {
						creativity += 2;
						activity -= 1;
					}
					else if (userpref == 2) {
						activity += 2;
					}
					cout << "Would you rather 1. become a sentient strawberry with the mind you have now (cannot communicate or have mobility) or 2. just become a regular strawberry with strawberry thoughts?" << endl;
					userpref = 0;
					getline (cin,userchoice);
					while (!isNumber(userchoice)|| userpref != 1 && userpref != 2) 
					{
						cout << "Not a valid choice. Please enter 1 or 2." << endl;
						getline(cin, userchoice);
						if (isNumber(userchoice))
						{
							userpref = atoi(userchoice.c_str());
						}
					}
					if (userpref == 1) {
						creativity += 1;
						activity += 1;
					}
					else if (userpref == 2) {
						activity -= 2;
					}

					if (complexity > 5) {
						complexity = 5;
					}
					if (creativity > 5) {
						creativity = 5;
					}
					if (activity>5) {
						activity = 5;
					}
					if (complexity<0) {
						complexity = 0;
					}
					if (creativity<0) {
						creativity = 0;
					}
					if (activity<0) {
						activity = 0;
					}

					bestFitItem(recommendedItems, vectorOfItems, creativity, activity, complexity);

					cout << "activity: " << activity << " creativity: " << creativity << " complexity: " << complexity << endl;
					cout << "items recommended: " << endl;
					for (int i = 0; i<recommendedItems.size(); i++) {
						cout << recommendedItems[i].getItemName() << endl;
					}
				}
				else if (secondinput == 3) {
					cout << "Inventory:" << endl;
					for (size_t i = 0; i < vectorOfItems.size(); i++) {
						cout << "\nItem: " << vectorOfItems[i].getItemName() << endl;
						cout << "Price: $" << vectorOfItems[i].getItemPrice() << endl; //formats output to display two decimal places
					}
					cout << endl;
				}
				else if (secondinput == 4) {
					break;
				}
				else {
					cerr << "Error, not a valid choice. " << endl;
				}
				cout << "1. Purchase item" << endl;
				cout << "2. Find gift" << endl;
				cout << "3. Display all" << endl;
				cout << "4. Exit" << endl;
				secondinput = 0;
			}
		}//closing bracket for if customer
		else {
			cerr << "Error, not a valid choice. Please enter either 1 for employee or 2 for customer" << endl;
		}
	} //closing bracket for the outermost while loop which checks for user validation
	return 0;
}
