#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Item {
private:
	const string name;
	int quantity;
	double price;
public:
	Item(string n, int q);
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

Item::Item(string n, int q):name(n) { //constructor for the Item class
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
		Item *i = new Item(str, q);
		inv.push_back(*i);
	}
}

void Inventory::removeItem(string str, int q) {

}

void Inventory::display() {
	for (size_t i = 0; i < inv.size(); i++) {
		cout << "Item: " << inv[i].getName() << endl;
		cout << "Quantity: " << inv[i].getQuantity() << endl;
		cout << "Price: " << inv[i].getPrice() << endl;
	}
}

int main() {
	Inventory *inventory = new Inventory();
	inventory->addItem("Beats Headphones", 3);
	inventory->display();
	return 0;
}
