/*COP3503 Team Project
**Team 17
**Peter Theryo, Devansh Parekh, Jed Rojas, Michelle Tzou, Scott Liu, Franky Liang
**
**Short Description: The following program maintains a database of items for a shop with two main interfaces, 
**one for the employees and one of the customers. A few functionalities that employees can perform are restocking items, 
**making sales, and checking profit. A few funcitons that customers can perform are purchasing an item and filling out a 
**questionnaire which will the output which items currently in the inventory best suit the individiual.
*/

//The password to the initial authorization is "COP3503rocks".

using namespace std;

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <iomanip>
#include <math.h>



class items {
private:
	string itemName;
	double itemPrice;
	double itemCost;
	int itemCreativity;
	int itemActivity;
	int itemComplexity;
public:
	items(string n, double p, double cost, int c, int a, int comp) :itemName(n) //constructor for the item class
		, itemPrice(p)
		, itemCost(cost)
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

	double getItemCost() {
		return itemCost;
	}

	double getItemProfit() {
		return itemPrice - itemCost;
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
	string customername;
	int customerage;
	double customerbudget;
	vector<string> shoppingBasket;

public:
	Customer(string cn, int ca, double budget) { //constructor for the customer class
		customername = cn;
		customerage = ca;
		customerbudget = budget;
	};
	string getCustomerName() {
		return customername;
	}
	int getCustomerAge() {
		return customerage;
	}
	double getCustomerBudget() {
		return customerbudget;
	}
	void addPurchase(string item) {
		//adds a gift to the customer's shopping basket 
		if (cartContains(item)) {
			cout << "You already have this item in your cart!" << endl;
		}
		else {
			shoppingBasket.push_back(item);
		}
	}
	void printPurchase() {
		//prints out all items in the customer's basket 
		cout << "These are the items you have in your basket" << endl;
		for (size_t i = 0; i < shoppingBasket.size(); i++) {
			cout << shoppingBasket[i] << endl;
		}
	}
	void subtractBudget(double amount) {
		customerbudget = customerbudget - amount;
	}
	void addBudget(double amount){
		customerbudget = customerbudget + amount;
	}
	bool noMoreMoney(double amount) {
		if (customerbudget - amount<0) {
			return true;
		}
		return false;
	}
	bool cartContains(string item) {
		//checks if customer is trying to add an item to their cart that they already have
		for (size_t i = 0; i < shoppingBasket.size(); i++) {
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
	while (true)
	{
		bool already_checked = false;
		for (size_t i = 0; i < vectorOfItems.size(); i++)
		{
			diffCreativity = abs(c - vectorOfItems[i].getItemCreativity());
			diffActivity = abs(a - vectorOfItems[i].getItemActivity());
			diffComplexity = abs(comp - vectorOfItems[i].getItemComplexity());
			difference = diffComplexity + diffActivity + diffCreativity;
			if (difference < minDiff) {
				for (size_t j = 0; j < recommendedItems.size(); j++)
				{
					if (vectorOfItems[i].getItemName() == recommendedItems[j].getItemName()) {
						already_checked = true;
					}
				}
				if (!already_checked) {
					recommendedItems.push_back(vectorOfItems[i]);
				}
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

bool authorizationCheck(string pw) {
	if (pw == "COP3503rocks") {
		return true;
	}
	return false;
}

bool isNumber(string str) {
	if (str == "")
	{
		return false;
	}
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str.at(i))) {
			return false;
		}
	}
	return true;
}

bool isDouble(string str) {
	int numPeriods = 0;
	if (str == "")
	{
		return false;
	}
	for (size_t i = 0; i < str.length(); i++)
	{
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

bool isValidString(string str) {
	if (str == "") {
		return false;
	}
	return true;
}

void purchaseItem(vector<items> & vectorOfItems, Customer & user) {
	int count = 0;
	int index;
	string input;
	string temp;
	cout << "Enter the name of the item: " << endl;
	getline(cin, temp);
	getline(cin, input);
	for (unsigned int i = 0; i < input.length(); i++)
	{
		input[i] = tolower(input[i]);
	}
	bool isInStock = false;
	for (size_t i = 0; i < vectorOfItems.size(); i++)
	{
		if (vectorOfItems[i].getItemName() == input) {
			isInStock = true;
			index = i;
			count++;
		}
	}
	if (!isInStock) {
		cout << "Sorry, that item is not in stock" << endl;
	}
	else {
		cout << "We have " << count << " " << input << "(s) in stock for " << vectorOfItems[index].getItemPrice() << " each. Continue with purchase?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		string optionS;
		int option = 0;
		getline(cin, optionS);
		option = atoi(optionS.c_str());
		while (!isNumber(optionS) || (option != 1 && option != 2))
		{
			cout << "Not a valid choice. Please enter 1 or 2." << endl;
			getline(cin, optionS);
			if (isNumber(optionS))
			{
				option = atoi(optionS.c_str());
			}
		}
		if (option == 1)
		{
			int amt = -1;
			cout << "How many would you like to purchase?" << endl;
			getline(cin, optionS);
			amt = atoi(optionS.c_str());
			int num = 0;
			while ((!isNumber(optionS)) || (amt < 1) || (amt > count))
			{
				cout << "Not a valid choice. Please enter a number between 1 and " << count << "." << endl;
				getline(cin, optionS);
				if (isNumber(optionS))
				{
					amt = atoi(optionS.c_str());
				}
			}
			for (size_t i = 0; i < vectorOfItems.size(); i++)
			{
				if (input == vectorOfItems[i].getItemName())
				{
					if (user.noMoreMoney(vectorOfItems[i].getItemPrice()))
					{
						cout << "You have no more money left!" << endl;
						break;
					}
					else
					{
						user.subtractBudget(vectorOfItems[i].getItemPrice());
						num += 1;
						vectorOfItems.erase(vectorOfItems.begin() + i);
						i--;
						amt--;
						if (amt == 0)
							i = vectorOfItems.size();
					}
				}
			}
			cout << "Congratulations, you purchased  " << amt << " " << input << "(s)!" << endl;
		}
		else if (option == 2)
		{
		}
		else
		{
			cout << "Invalid choice. Purchase?" << endl;
			cout << "1. Yes" << endl;
			cout << "2. No" << endl;
		}
	}
}

//method that generates a questionnaire for the customer to fill out.
void recGift(vector<items> & vectorOfItems, vector<items> & recommendedItems, Customer & user) {
	string userchoice = "";
	int userpref = 0;
	int creativity = 0;
	int activity = 0;
	int complexity = 0;
	string tempchoice = "";
	recommendedItems.clear();
	cout << "Please answer the following questions with either a 1 or 2 so we can match you to your perfect item" << endl;
	cout << endl << "Would you rather 1. paint a picture or 2. ride a bike?" << endl;
	getline(cin, tempchoice);

	getline(cin, userchoice);
	userpref = atoi(userchoice.c_str());
	while (!isNumber(userchoice) || (userpref != 1 && userpref != 2))
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
	cout << endl << "Can you solve a Rubiks Cube? 1. yes 2. no" << endl;
	userpref = 0;
	getline(cin, userchoice);
	userpref = atoi(userchoice.c_str());
	while (!isNumber(userchoice) || (userpref != 1 && userpref != 2))
	{
		cout << endl << "Not a valid choice. Please enter 1 or 2." << endl;
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
	cout << endl << "Have you ever watched a Marvel movie? 1. yes 2. no " << endl;
	userpref = 0;
	getline(cin, userchoice);
	userpref = atoi(userchoice.c_str());
	while (!isNumber(userchoice) || (userpref != 1 && userpref != 2))
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
	cout << endl << "Can you see yourself skydiving? 1. yes 2. no" << endl;
	userpref = 0;
	getline(cin, userchoice);
	userpref = atoi(userchoice.c_str());
	while (!isNumber(userchoice) || (userpref != 1 && userpref != 2))
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
	cout << endl << "Is your spirit animal moreso 1. a cheetah or 2. a sloth" << endl;
	userpref = 0;
	getline(cin, userchoice);
	userpref = atoi(userchoice.c_str());
	while (!isNumber(userchoice) || (userpref != 1 && userpref != 2))
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
	cout << endl << "Do you believe in aliens? 1. yes 2. no" << endl;
	userpref = 0;
	getline(cin, userchoice);
	userpref = atoi(userchoice.c_str());
	while (!isNumber(userchoice) || (userpref != 1 && userpref != 2))
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
	cout << endl << "Can you do a backflip? 1. yes 2. no" << endl;
	userpref = 0;
	getline(cin, userchoice);
	userpref = atoi(userchoice.c_str());
	while (!isNumber(userchoice) || (userpref != 1 && userpref != 2))
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
	cout << endl << "1. Super Smash or 2. volleyball?" << endl;
	userpref = 0;
	getline(cin, userchoice);
	userpref = atoi(userchoice.c_str());
	while (!isNumber(userchoice) || (userpref != 1 && userpref != 2))
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
	cout << endl << "Would you rather 1. become a sentient strawberry with the mind you have now (cannot communicate or have mobility) or 2. just become a regular strawberry with strawberry thoughts?" << endl;
	userpref = 0;
	getline(cin, userchoice);
	userpref = atoi(userchoice.c_str());
	while (!isNumber(userchoice) || (userpref != 1 && userpref != 2))
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
	if (activity > 5) {
		activity = 5;
	}
	if (complexity < 0) {
		complexity = 0;
	}
	if (creativity < 0) {
		creativity = 0;
	}
	if (activity < 0) {
		activity = 0;
	}

	bestFitItem(recommendedItems, vectorOfItems, creativity, activity, complexity);
	cout << endl << "The following are your survey results:" << endl;
	cout << "Activity: " << activity << endl;
	cout << "Creativity: " << creativity << endl;
	cout << "Complexity: " << complexity << endl;
	cout << "The following items are recommended for you:" << endl;
	for (size_t i = 0; i < recommendedItems.size(); i++) {
		cout << "Item: " << recommendedItems[i].getItemName() << endl;
		cout << "\tPrice: $" << recommendedItems[i].getItemPrice() << endl;
		if (user.noMoreMoney(recommendedItems[i].getItemPrice())){
			cout<<"\twarning! this item is over your budget!"<<endl;
		}
	}
	cout << endl;
}	

void display(vector<items> & vectorOfItems) {
	cout << "Inventory:" << endl;
	for (size_t i = 0; i < vectorOfItems.size(); i++) {
		cout << endl << "Item: " << vectorOfItems[i].getItemName() << endl;
		cout << "Price: $" << vectorOfItems[i].getItemPrice() << endl; //formats output to display two decimal places
	}
	cout << endl;
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
		vectorOfItems.push_back(items("ball", 2.50, 1.10, 2, 5, 1));
		example++;
	}
	example = 0;
	while (example < 3)
	{
		vectorOfItems.push_back(items("rubix's cube", 3.75, 1.25, 2, 1, 5));
		example++;
	}
	example = 0;
	while (example < 3)
	{
		vectorOfItems.push_back(items("coloring book", 2.25, .50, 4, 1, 2));
		example++;
	}
	example = 0;
	while (example < 3)
	{
		vectorOfItems.push_back(items("keyboard", 25.50, 20, 4, 1, 4));
		example++;
	}
	example = 0;
	while (example < 3)
	{
		vectorOfItems.push_back(items("dance lessons", 15.50, 6.50, 5, 5, 4));
		example++;
	}
	example = 0;
	while (example < 3)
	{
		vectorOfItems.push_back(items("chalk", 5.25, 2.75, 5, 4, 1));
		example++;
	}
	example = 0;
	while (example < 3)
	{
		vectorOfItems.push_back(items("exercise machine", 175.25, 125.00, 1, 4, 4));
		example++;
	}
	example = 0;
	while (example < 3)
	{
		vectorOfItems.push_back(items("pinwheel", 1.25, 0.50, 2, 1, 1));
		example++;
	}

	//initial prompt for user to select employee or customer
	cout << "Welcome to the shop! Are you an employee or customer?" << endl;
	cout << "1. Employee" << endl;
	cout << "2. Customer" << endl;
	cout << "3. Exit Shop" << endl;
	string userInput = "";
	int firstInput = 0;
	bool hello = true;

	while (firstInput != 1 && firstInput != 2 && firstInput != 3) { //input validation for the first menu choice
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
			cout << "AUTHORIZATION REQUIRED. PLEASE ENTER COMPANY PASSWORD." << endl;
			string pw = "";
			getline(cin, pw);
			if (!authorizationCheck(pw)) {
				cout << "UNAUTHORIZED ACCESS TO SYSTEM DATABASE. RETURNING TO ENTRY POINT." << endl << endl;
				cout << "Welcome to the shop! Are you an employee or customer?" << endl;
				cout << "1. Employee" << endl;
				cout << "2. Customer" << endl;
				cout << "3. Exit Shop" << endl;
				firstInput = -1;
			}
			cout << endl;
		}
		if (firstInput == 1) {
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
				getline(cin, secondUserInput);
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
								double cost = 0;
								string costStr = "";
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
								while (!isValidString(n)) { //input validation for string. String cannot be empty
									cout << "Error. The name of the item cannot be empty. Plase re-enter the name of the item." << endl;
									getline(cin, n);
								}
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
								bool alreadychecked = false; //boolean to see if the vector has been searched through once for the item
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
										while (!isNumber(restockchoiceStr) || (restockchoice != 1 && restockchoice != 2)) {
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
											cost = vectorOfItems[counter].getItemCost();
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
										//rounds the price to two decimals
										price = floor((100.*price) + .5) / 100.;
									}
									while (!isDouble(priceStr)) {
										cout << "Not a valid choice. Please enter a valid price." << endl;
										getline(cin, priceStr);
										if (isDouble(priceStr)) {
											price = atof(priceStr.c_str());
											//rounds the price to two decimals
											price = floor((100.*price) + .5) / 100.;
										}
									}
									cout << "What is the cost of making this item?" << endl; // dis dat shit
									cout << "$";
									getline(cin, costStr);
									cost = atof(costStr.c_str());
									//rounds the price to two decimals
									cost = floor((100.*cost) + .5) / 100.;
									while (!isDouble(costStr) || (cost > price)) {
										cout << "Not a valid choice. Please enter a valid cost." << endl;
										getline(cin, costStr);
										if (isDouble(costStr)) {
											cost = atof(costStr.c_str());
											//rounds the price to two decimals
											cost = floor((100.*cost) + .5) / 100.;
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

								vectorOfItems.push_back(items(name, price, cost, creativity, activity, complexity));
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
										while (!isNumber(pchoiceStr) || (pchoice != 1 && pchoice != 2)) {
											cout << "Not a valid choice. Please enter 1 for Yes or 2 for No." << endl;
											getline(cin, pchoiceStr);
											if (isNumber(pchoiceStr)) {
												pchoice = atoi(pchoiceStr.c_str());
											}
										}
										if (pchoice == 1) //adds total profit to sales
										{
											vectorOfEmployees[currentEmployee].setEmpTotalSales(vectorOfEmployees[currentEmployee].getEmpTotalSales() + vectorOfItems[i].getItemProfit());
											vectorOfItems.erase(vectorOfItems.begin() + i);//deletes item in vector
											cout << "Successful Transaction" << endl;
											success = true; //changes the success variable to true so as to not print the error
										}
									}
								}
								if (!success)
								{
									cout << "Failed to sell item! Item not found in inventory." << endl;
								}
								loggedInInput = 0;
							}

							else if (loggedInInput == 3)
							{
								//loops through vectorOfItems and prints each itemName and itemPrice
								cout << "Current in stock: " << endl;
								for (size_t i = 0; i < vectorOfItems.size(); i++) {
									cout << "Item: " << vectorOfItems[i].getItemName() << " Price: $" << vectorOfItems[i].getItemPrice() << endl;
								}
								loggedInInput = 0;
							}

							else if (loggedInInput == 4)
							{
								cout << "Employee " << vectorOfEmployees[currentEmployee].getEmpName() << " has sold items in total of $" << vectorOfEmployees[currentEmployee].getEmpTotalSales() << endl;
								loggedInInput = 0;
							}

							else if (loggedInInput == 5)
							{
								cout << "Logout successful." << endl;
								secondInput = 0;
							}
							else
							{
								cout << "Error. Not a valid choice. Please try again." << endl;
								loggedInInput = 0;
							}
						} //end of Employee options loop
					//} // end of while loop for user logged in
					}
					else { //if (!isAuthenticated)
						secondInput = 0;
						hello = true;
						cout << endl << "Login Unsuccesful. Invalid username or password. Please try again." << endl;
					}
				}

				else if (secondInput == 2) { //entry point for new account registration
					string name = "";
					string username = "";
					string password = "";
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
						//if there exists another employee currently in the database with the same username, break and set the
						//corresponding boolean iUnique to false.
						if (username == vectorOfEmployees[i].getEmpUsername()) {
							isUnique = false;
							break;
						}
					}
					//if there does not exist an employee with that username, create one and add it to the database of employees
					if (isUnique)
					{
						int sales = 0;
						vectorOfEmployees.push_back(employees(name, username, password, sales));
						cout << "Thank you for registering, " << name << "! Please log in with your new credentials." << endl << endl;
						secondInput = 0;
					}
					else
					{
						//prints and loop will run again
						cout << "Username already taken!" << endl << endl;
						secondInput = 0;
					}
				}

				else if (secondInput == 3) { //go back to the employee or customer selection menu
					firstInput = 0;
					cout << "Welcome to the shop! Are you an employee or customer?" << endl;
					cout << "1. Employee" << endl;
					cout << "2. Customer" << endl;
					cout << "3. Exit" << endl;
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
		if (firstInput == 2) { //entry point for customer
			string cn = "";
			string ageStr = "";
			int age = 0;
			double budget = 0.0;
			cout << "Hello customer! Please enter your name" << endl;
			getline(cin, cn);
			cout << endl << "Please enter your age" << endl;
			getline(cin, ageStr);
			while (!isNumber(ageStr)) {
				cout << endl << "Not a valid age. Please enter a positive integer." << endl;
				getline(cin, ageStr);
			}
			age = atoi(ageStr.c_str());

			cout << endl << "How much money are you looking to spend today?" << endl;
			cin >> budget;

			Customer *user = new Customer(cn, age, budget); //creates a new instance of a customer

			cout << endl << "Hello " << user->getCustomerName() << "! Would would you like to do today?" << endl;
			cout << "1. Purchase item" << endl;		//search by name, instock? remove from list, display price
			cout << "2. Find gift" << endl;			//go to questionnaire
			cout << "3. Display all" << endl;		//loop through vector and print inventory
			cout << "4. view budget" << endl;
			cout << "5. add money to budget" <<endl;
			cout << "6. go back" <<endl;

			bool keepgoing = true;
			int secondinput = 0;
			string input1 = "";
			while (secondinput != 1 && secondinput != 2 && secondinput != 3 && secondinput != 4 && secondinput != 5 && keepgoing) {
				bool isNum1 = true;
				cin >> input1; //input validation
				for (size_t j = 0; j < input1.length(); j++) {
					if (!isdigit(input1.at(j))) {
						isNum1 = false;
					}
				}
				if (isNum1) {
					secondinput = atoi(input1.c_str());
				}
				if (secondinput == 1) { //entry point for item purchase within customer class
					purchaseItem(vectorOfItems, *user);
					secondinput = 0;
				}
				else if (secondinput == 2) { //entry point for the questionnaire
					recGift(vectorOfItems, recommendedItems, *user);
					secondinput = 0;
				}
				else if (secondinput == 3) {
					display(vectorOfItems);
					secondinput = 0;
				}
				else if (secondinput == 4) {
					cout << user->getCustomerBudget() << endl;
					cout << endl;
					secondinput = 0;
				}
				else if(secondinput==5){
					cout<<"how much money would you like to add?"<<endl;
					double addbudget;
					cin>>addbudget;
					user->addBudget(addbudget);
					cout<<"added successfully!"<<endl;
					secondinput=0;
				}
				else if (secondinput == 6) { //exit function to return to employee/customer select screen
					firstInput = -1;
					cout << endl;
					cout << "Welcome to the shop! Are you an employee or customer?" << endl;
					cout << "1. Employee" << endl;
					cout << "2. Customer" << endl;
					cout << "3. Exit" << endl;
					hello = true;
					break;
				}
				else {
					cerr << endl << "Error, not a valid choice. " << endl;
				}
				cout << "1. Purchase item" << endl;
				cout << "2. Find gift" << endl;
				cout << "3. Display all" << endl;
				cout << "4. view budget" << endl;
				cout << "5. add money to budget" <<endl;
				cout << "6. go back" <<endl;
			}
		}//closing bracket for if customer
		if (firstInput == 3) { //this is how to the user exists the shop
			cout << "Are you sure you want to leave? Please enter 1 for yes or 2 for no" << endl;
			string exitOptionStr = "";
			int exitOption = 0;
			getline(cin, exitOptionStr);
			if (isNumber(exitOptionStr)) { //input validation for the exitOption variable
				exitOption = atoi(exitOptionStr.c_str());
			}
			while (!isNumber(exitOptionStr) || (exitOption != 1 && exitOption != 2)) {
				cout << "Not a valid choice. Please enter 1 for Yes and 2 for No." << endl;
				getline(cin, exitOptionStr);
				if (isNumber(exitOptionStr)) {
					exitOption = atoi(exitOptionStr.c_str());
				}
			}
			//returns back to the main menu when the user does not want to exit the program
			if (exitOption == 2) {
				firstInput = -1;
				cout << endl;
				cout << "Welcome to the shop! Are you an employee or customer?" << endl;
				cout << "1. Employee" << endl;
				cout << "2. Customer" << endl;
				cout << "3. Exit Shop" << endl;
			}
			//safely exists the program
			if (exitOption == 1)
			{
				exit(EXIT_SUCCESS);
			}
		}
		if (!(firstInput == 1 || firstInput == 2 || firstInput == 3)) {
			cout << "Error, not a valid choice. Please enter either 1 for employee, 2 for customer or 3 to exit the shop." << endl;
		}
			firstInput = 0;
	} //closing bracket for the outermost while loop which checks for user validation
	return 0;
}
