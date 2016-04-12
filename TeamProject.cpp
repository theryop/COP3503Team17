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
	double totalSales;
};

//need to add Customer class later from the peeps working on the other module

Item::Item(string n, int q) : name(n) { //constructor for the Item class without price parameter
	quantity = q;
}

Item::Item(string n, int q, double p) : name(n) { //constructor for the Item class with price parameters
	price = floor((100.*p) + .5) / 100.;
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

void Inventory::addItem(string str, int q) {
	if (isInStock(str)) {
		for (size_t i = 0; i < inv.size(); i++) {
			if (inv[i].getName() == str) {
				inv[i].setQuantity(inv[i].getQuantity() + q);
			}
		}
	}
	else {
		cout << "Please enter the price of " << str << ": ";
		string input = "";
		double d = 0;
		getline(cin, input);
		d = atof(input.c_str());
		Item *i = new Item(str, q, d);
		inv.push_back(*i);
	}
}

void Inventory::removeItem(string str, int q) {

}

void Inventory::display() {
	for (size_t i = 0; i < inv.size(); i++) {
		cout << "Item: " << inv[i].getName() << endl;
		cout << "Quantity: " << inv[i].getQuantity() << endl;
		cout << "Price: $" << fixed << setprecision(2) << setfill('0') << inv[i].getPrice() << endl; //formats output to display two decimal places
	}
}

int main() {
	Inventory *inventory = new Inventory(); //random stuff to test methods
	inventory->addItem("Beats Headphones", 3);
	inventory->addItem("Beats Headphones", 2);
	inventory->addItem("Football", 3);
	inventory->display();
	return 0;
}
