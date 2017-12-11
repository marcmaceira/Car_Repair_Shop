#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include "Shop.h"
#include "Service.h"
#include "Order.h"
#include "NegativeNum.h"
using namespace std;

void mainMenu();
void menuSelector(char);
void createNewService(string, double, string);
void createCustomerOrder(string, double, string);
void manageServices();
string Locations[3] ={"Lot #1", "Lot #2", "Lot #3"};

int i = 0;

int main(){

  char option;
  do {
    cout << "MENU" << endl
      << "1 - Enter a new service" << endl
      << "2 - Manage services" << endl
      << "3 - Enter a customer service order" << endl
      << "4 - Print/Export all service items" << endl
      << "5 - About" << endl
      << "E - Exit" << endl << endl
      << "Choose an option: ";
    cin >> option;

    menuSelector(tolower(option));

  } while(option == '1' || option == '2' ||option== '3' || option== '4' || option == '5' || option=='e');

  return 0;
}

void menuSelector(char selection) 
{
  string service = " ";
  string location = " ";
  double price = 0.0;
  switch (selection) 
  {
    // Adds a new service to the offered services list
    case '1':
    {
      createNewService(service, price, location);
      break;
    }

    // Shows available customer receipts for printing
    case '2':
      manageServices();
      break;
    
    // Create a customer order
    case '3':
      createCustomerOrder(service, price, location);
      break;
    
    // Print offered services
    case '4':
    {
      Service services;
      services.showServiceDB();
      system("PAUSE");
      system("CLS");
      break;
    }

    
    case '5':
      cout << "Ricardo Javier Porrata Samalot" << endl;
      cout << "Marc Anthony Maceira Zayas" << endl;
      cout << "Estefania Cristina Ramirez Ascar" << endl;
      system("PAUSE");
      system("CLS");
      break;
    
    // Exit program
    case 'e':
      cout << "Exiting program..." << endl;
      exit(1);
      break;
    
    default:
      cout << "Invalid entry." << endl;
      system("PAUSE");
      system("CLS");
  }
}

void createNewService(string service, double price, string location) {
  Service newService;

  cin.ignore();
  cout << "Enter the new service: ";
  getline(cin,service);

  cout << "Enter the price: $";
  cin >> price;

  cin.ignore();
  cout << "Enter the location: ";
  getline(cin,location);
  cout << endl;

  // Validate price > 0
  bool tryAgain = true;
  while (tryAgain) {
    try
    {
      newService.setPrice(price);
      tryAgain = false;
    }
    catch(NegativeNum aNegNum)
    {
      cout << "Invalid entry. Value must be positive: $";
      cin >> price;
    }
  }

  newService.setService(service);
  newService.setPrice(price);
  newService.setLocation(location);
  
  // Add new service to CSV
  newService.createServiceDB(); 

  system("PAUSE");
  system("CLS");
}

void manageServices()
{
  Order theOrder;
  string name;

  // Print available receipts
  theOrder.readReceiptDB();

  cin.ignore();
  cout << "Enter the name of the customer receipt: ";
  getline(cin, name);

  // If the given name exists in the Receipts CSV, customer's applied services will be printed.
  theOrder.setName(name);
  theOrder.readReceipt();

  system("PAUSE");
  system("CLS");
}

void createCustomerOrder(string service, double price, string location) {

  Order theOrder;
  int option;
  // double price;
  // string location;
  // string service;
  string name;
  Service theService;
  int month, day, year;

  cin.ignore();
  cout << "Enter the name of the customer: ";
  getline(cin, name);
  cout << endl;
  theOrder.setName(name);
  theOrder.createReceiptDB(); // Add the customer's name to database

  cout << "Welcome "<< name << " your order #" << i + 1 << endl;

  bool repeat = true;
  char choice = ' ';

  while (repeat)
  {
    // Imprime los serivicos ofrecidos
    theService.showServiceDB();

    cin.ignore();
    cout << "\nSelect a service: ";
    cin.clear();
    getline(cin, service);

    theOrder.setService(service);

    cout << "Enter the price: $";
    cin >> price;

    bool tryAgain = true;
    while (tryAgain)
    {
      try
      {
        theOrder.setPrice(price);
        tryAgain = false;
      }
      catch(NegativeNum negNum)
      {
        cout << "Value cannot be negative. Re-enter: $";
        cin >> price;
      }
    }

    for (int x = 0; x < 3; x++)
      cout << x + 1 << " - " << Locations[x] << endl;

    cout << "Selector location: ";
    cin >> option;

    switch (option) {
    case 1:
      location = Locations[0];
      break;
    case 2:
      location = Locations[1];
      break;
    case 3:
      location = Locations[2];
      break;
    default:
      cout << "Wrong entry!" << endl;
    }

    theOrder.setLocation(location);

    cout << "Enter the creation date(mm/dd/yyyy)" << endl
        << "Month: ";
    cin >> month;
    while (month > 12 || month < 1)
    {
      cout << "That number is out of range, enter another number: ";
      cin >> month;
    }

    cout << "Day: ";
    cin >> day;
    while (day < 1 || day >= 31)
      {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
          if (day >= 1 || day <= 31)
          {
            cout << "That number is out of range, enter another number: ";
            cin >> day;
          }
        }

        if (month == 4 || month == 6 || month == 9 || month == 11)
        {
          if (day >= 1 || day <= 30)
          {
            cout << "That number is out of range, enter another number: ";
            cin >> day;
          }
        }

        if (month == 2)
        {
          if (day >= 1 || day <= 28)
          {
            cout << "That number is out of range, enter another number: ";
            cin >> day;
          }

        }
      }

    cout << "Year: ";
    cin >> year;
    while (year!=2017)
    {
      cout << "That number is out of range, enter another number: ";
      cin >> year;
    }

    theOrder.setCreationDate(month, day, year);

    cout << "Would you like to add another service(y/n)?";
    cin >> choice;

    theOrder.createReceipt();

    if (choice == 'y')
      repeat = true;
    else
      repeat = false;
  }

  system("PAUSE");
  system("CLS");
}
