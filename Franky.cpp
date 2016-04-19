#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <iomanip>
#include <math.h>

using namespace std;

class items {
public:
  items(string n, int p, int c, int a):itemName(n)
                                      , itemPrice(p)
                                      , itemCreativity(c)
                                      , itemActivity(a)
                                      , itemComplexity(c)
                                    {}
  string getItemName() { return itemName; }
  int getItemPrice() { return itemPrice; }
  int getItemCreativity() { return itemCreativity; }
  int getItemActivity() { return itemActivity; }
  int getItemComplexity() { return itemComplexity; }

  string itemName;
  int itemPrice;
  int itemCreativity;
  int itemActivity;
  int itemComplexity;
};

class employees {
public:
  employees(string n, string u, string pw, int tSales):empName(n)
                                                      , empUsername(u)
                                                      , empPassword(pw)
                                                      , empTotalSales(tSales)
                                                     {}

  string getEmpName() { return empName; }
  string getEmpUsername() { return empUsername; }
  string getEmpPassword() { return empPassword; }
  int getEmpTotalSales() { return empTotalSales; }

  string empName;
  string empUsername;
  string empPassword;
  int empTotalSales;
};

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


int main() {
  vector<items> vectorOfItems;
  vector<employees> vectorOfEmployees;

  int currentEmployee;

  cout << "Welcome to the shop! Are you an employee or customer?" << endl;
  cout << "1. Employee" << endl;
  cout << "2. Customer" << endl;
  int firstInput;
  cin >> firstInput;

  if (firstInput == 1) {
    cout << "Hello Employee! Please login or register for an account." << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;
    while (true) {
      int secondInput;
      cin >> secondInput;

      if (secondInput == 1) {
        string username;
        string password;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        bool isAuthenticated = false;
        //Iterate through vector and compare username/password -> write a method to return true/false
        for (int i = 0; i < vectorOfEmployees.size(); i++) {
          if(username == vectorOfEmployees[i].getEmpUsername() && password == vectorOfEmployees[i].getEmpPassword()) {
            currentEmployee = i;
            isAuthenticated = true;
            break;
          }
        }
        if (isAuthenticated) {
          //write function for logged in prompts for employees
          userLoggedIn();
          //might put code directly in here because it would be easier to append to vector, check username for sales... etc
        }
      }

      if ( secondInput == 2 ) {
        string name;
        string username;
        string password;

        cout << "Name: ";
        cin >> name;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        //validate for uniqueness of account
        //will return true of false value which will be used in this conditional
        bool isUnique = true;
        for (int i = 0; i < vectorOfEmployees.size(); i++) {
          if ( username == vectorOfEmployees[i].getEmpUsername() ) {
            isUnique = false;
            break;
          }
        }

        if (isUnique) {
          int sales = 0;
          vectorOfEmployees.push_back(employees(name, username, password, sales));
          cout << "Thank you for registering, " << name << "! Please log in with your new credentials." << endl;
        } else {
          //prints and loop will run again
          cout << "Username already taken!" << endl;
        }
      }

      if ( secondInput == 3 ) {
        break;
      }
      cout << "Hello Employee! Please login or register for an account." << endl;
      cout << "1. Login" << endl;
      cout << "2. Register" << endl;
      cout << "3. Exit" << endl;
    } // closing bracket for top while loop
  } //closing bracket for if employee

  if ( firstInput == 2 ) {

  }//closing bracket for if customer

  return 0;
}
