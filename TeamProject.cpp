#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <iomanip>

using namespace std;

class Item {
private:
	const string name;
	int quantity;
	double price;
public:
	Item(string n, int q);
	Item(string n, int q, double p);
	string getName();
	int getQuantity();
	double getPrice();
	void setQuantity(int q);
};

class Inventory {
private:
	vector<Item> inv;
public:
	Inventory();
	bool isInStock(string str);
	void addItem(string str, int q);
	void removeItem(string str, int q);
	void display();
};

class Employee { //missing methods for adding/removing items from Inventory? -SL
private: //also the Milestone 2 mentioned username and password, include that also? -SL
	const string name;
	string username;
	string password;
	double totalSales;
public:
	Employee(string n, string u, string p);
	string getName();
	string getUsername();
	string getPassword();
	void setUsername(string u);
	void setPassword(string p);
};

class EmployeeDatabase {
private:
	vector<Employee> employees;
public:
	EmployeeDatabase();
	bool isInDatabase(string u);
	void addEmployee(string n, string u, string p);
	Employee* login(string u, string p);
};

//need to add Customer class later from the peeps working on the other module

Item::Item(string n, int q) : name(n) { //constructor for the Item class without price parameter
	quantity = q;
}

Item::Item(string n, int q, double p) : name(n) { //constructor for the Item class with price parameter
	price = floor((100.*p) + .5) / 100.; //rounds price to nearest two decimals
	quantity = q;
}

string Item::getName() { //returns the name of the item
	return name;
}

int Item::getQuantity() { //returns the quantity of the desired item remaining
	return quantity;
}

double Item::getPrice() { //returns the unit price of the item
	return price;
}

void Item::setQuantity(int q) { //sets the quantity of a certain item
	if (q < 0) {
		quantity = 0;
	}
	else {
		quantity = q;
	}
}

bool Inventory::isInStock(string str) { //checks to see if the desired item is in stock within the inventory
	for (size_t i = 0; i < inv.size(); i++) {
		if (inv[i].getName() == str) {
			if (inv[i].getQuantity() > 0) {
				return true;
			}
		}
	}
	return false;
}

Inventory::Inventory() { //constructor for the Inventory class
	inv = {};
}

void Inventory::addItem(string str, int q) { //method for adding item to the inventory
	if (isInStock(str)) { //checks to see if the item is in the inventory already
		for (size_t i = 0; i < inv.size(); i++) {
			if (inv[i].getName() == str) {
				inv[i].setQuantity(inv[i].getQuantity() + q); //if it is, simply updates the quantity
			}
		}
	}
	else { //otherwise add the item to the inventory
		cout << "Please enter the price of " << str << ": ";
		string input = "";
		double d = 0;
		getline(cin, input);
		d = atof(input.c_str());
		Item *i = new Item(str, q, d);
		inv.push_back(*i);
	}
}

void Inventory::removeItem(string str, int q) { //method for removing a certain quantity of a certain item from the inventory
	if (isInStock(str)) {
		for (size_t i = 0; i < inv.size(); i++) {
			if (inv[i].getName() == str && inv[i].getQuantity() > 0) {
				//so my idea if not enough in stock was to just remove the remainder of the inventory
				//what do you guys think? -SL
				if (inv[i].getQuantity() - q < 0) { 
					cout << "Not enough of " << str << " in stock. Only " << inv[i].getQuantity() << " could be removed." << endl;
					inv[i].setQuantity(0);
				}
				else {
					inv[i].setQuantity(inv[i].getQuantity() - q);
				}
			}
		}
	}
	else {
		cout << "There is none of " << str << " in the inventory." << endl;
	}
}

void Inventory::display() {
	for (size_t i = 0; i < inv.size(); i++) {
		cout << "Item: " << inv[i].getName() << endl;
		cout << "Quantity: " << inv[i].getQuantity() << endl;
		cout << "Price: $" << fixed << setprecision(2) << setfill('0') << inv[i].getPrice() << endl; //formats output to display two decimal places
	}
}

Employee::Employee(string n, string u, string p) : name(n) {
	username = u;
	password = p;
}

string Employee::getName() {
	return name;
}

string Employee::getUsername() {
	return username;
}

string Employee::getPassword() {
	return password;
}

void Employee::setUsername(string u) {
	username = u;
}

void Employee::setPassword(string p) {
	password = p;
}

EmployeeDatabase::EmployeeDatabase() {
	employees = {};
}

bool EmployeeDatabase::isInDatabase(string u) {
	for (size_t i = 0; i < employees.size(); i++) {
		if (employees[i].getUsername() == u) {
			return true;
		}
	}
	return false;
}

void EmployeeDatabase::addEmployee(string n, string u, string p) {
	if (isInDatabase(u)) {
		cout << "An account with that username already exists." << endl;
	}
	else {
		Employee *e = new Employee(n, u, p);
		employees.push_back(*e);
	}
}

Employee* EmployeeDatabase::login(string u, string p) {
	Employee* e = NULL;
	if (!isInDatabase(u)) {
		cout << "No account exists with that username." << endl;
		//insert method for creating an acc here
	}
	else {
		for (size_t i = 0; i < employees.size(); i++) {
			if (employees[i].getUsername() == u) {
				string pass = p;
				while (employees[i].getPassword() != pass) {
					cout << endl << "Incorrect Password. Please try again." << endl;
					cout << "Password: ";
					cin >> pass;
				}
				e = &employees[i];
				cout << "Login successful.";
			}
		}
	}
	return e;
}

int main() {
	Inventory *inventory = new Inventory();
	EmployeeDatabase *db = new EmployeeDatabase();
	db->addEmployee("Bob", "Bob", "hi"); //delete after
	cout << "Welcome to the shop! Are you an employee or customer?" << endl;
	cout << "1. Employee" << endl;
	cout << "2. Customer" << endl;
	string input = "";
	int choice = 0;
	while (choice != 1 && choice != 2) {
		bool isNum = true;
		cout << endl;
		cin >> input;
		for (size_t i = 0; i < input.length(); i++) {
			if (!isdigit(input.at(i))) {
				isNum = false;
			}
		}
		if (isNum) {
			choice = atoi(input.c_str());
		}
		if (choice == 1) {
			cout << "Hello Employee! Please login or register for an account." << endl;
			cout << "1. Login" << endl;
			cout << "2. Register" << endl;
			string input1 = "";
			int choice1 = 0;
			while (choice1 != 1 && choice1 != 2) {
				bool isNum1 = true;
				cout << endl;
				cin >> input1;
				for (size_t j = 0; j < input1.length(); j++) {
					if (!isdigit(input1.at(j))) {
						isNum1 = false;
					}
				}
				if (isNum1) {
					choice1 = atoi(input1.c_str());
				}
				if (choice1 == 1) {
					string u = "";
					string p = "";
					cout << "Username: ";
					cin >> u;
					cout << "Password: ";
					cin >> p;
					db->login(u, p);
				}
				else if (choice1 == 2) {
					//insert Employee Register method here
				}
				else {
					cerr << "Error, not a valid choice. Please enter either 1 for login or 2 for register" << endl;
				}
			}
		}
		else if (choice == 2) {
			cout << "Hello Customer!" << endl;
			//insert questionaire here
		}
		else {
			cerr << "Error, not a valid choice. Please enter either 1 for employee or 2 for customer" << endl;
		}
	}
	/*inventory->addItem("Beats Headphones", 3); //random stuff to test methods
	inventory->addItem("Beats Headphones", 2);
	inventory->addItem("Football", 3);
	inventory->removeItem("Football", 4);
	inventory->removeItem("Football", 2);
	inventory->display();*/
	return 0;
}
