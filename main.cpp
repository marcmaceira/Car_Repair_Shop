#include <iostream>
#include <cstdlib>
#include <cctype>
#include "Shop.h"
#include "Service.h"
#include "Order.h"
#include "NegativeNum.h"
using namespace std;

void mainMenu();
void menuSelector(char);
void createNewService();
void createCustomerOrder();
string Locations[3] ={"Lot #1", "Lot #2", "Lot #3"};

Service *TheServices = new Service[100];
int i = 0;

int main(){

  mainMenu();

  delete[] TheServices;
  return 0;
}

// Prints main menu
void mainMenu()
{
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

    menuSelector(option);

  } while(option == '1' || option == '2' ||option== '3' || option== '4' || option == '5' || option =='E' || option=='e');
}

void menuSelector(char selection) {
switch (selection) {
      // Adds a new service to the offered services list
      case '1':
      {
        createNewService();
        break;
      }

      case '2':
        system("PAUSE");
        system("CLS");
        break;
      case '3':
        createCustomerOrder();
        system("PAUSE");
        system("CLS");
        break;
      case '4': {
        Service theService; // Delete later. Used to test service printing.
        theService.showServiceDB();
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

void createNewService() {
  string service;
  string location;
  double price;
  Service theService;

  cin.ignore();
  cout << "Enter the new service: ";
  getline(cin,service);

  cout << "Enter the price: $";
  cin >> price;

  cin.ignore();
  cout << "Enter the location: ";
  getline(cin,location);
  cout << endl;

  theService.setLocation(location);

  bool tryAgain = true;
  while (tryAgain) {

    try
    {
      theService.setPrice(price);
      tryAgain = false;
    }
    catch(NegativeNum aNegNum)
    {
      cout << "Invalid entry. Value must be positive: $";
      cin >> price;
    }
  }

  theService.setPrice(price);
  theService.setService(service);

  theService.createServiceDB();
  // <-- PRUEBA
  TheServices[i] = theService;
  // -->

  cout << theService;

  i++; // Move on to the next order

  system("PAUSE");
  system("CLS");
}

void createCustomerOrder() {

  Order theOrder;
  int option;
  string location;
  string service;
  string name;
  Service theService;


  cin.ignore();
  cout << "Enter the name of the customer: ";
  getline(cin, name);
  cout << endl;
  theOrder.setName(name);

  cout << "Welcome "<< name << "your order will be order #" << i + 1 << endl << endl;

  theService.showServiceDB();
  cout << "Select a service: ";
  cin.ignore();
  getline(cin, service);
  theOrder.setService(service);

  for (int x = 0; x < 3; x++)
    cout << x + 1 << " - " <<Locations[x] << endl;

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

  theOrder.createReceipt(i);

  system("CLS");

  theOrder.readReceipt();

  system("PAUSE");
  system("CLS");

}
