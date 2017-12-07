#include <iostream>
#include <cstdlib>
#include <cctype>
#include "Shop.h"
#include "Service.h"
using namespace std;

void MainMenu();
void menuSelector(char);
void createNewService();

Service *TheServices = new Service[100];
int i = 0;

int main(){
  
  MainMenu();

  delete[] TheServices;
  return 0;
}

// Prints main menu
void MainMenu()
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
        
        break;
      }

      case '2':
        system("PAUSE");
        system("CLS");
        break;
      case '3':
        system("PAUSE");
        system("CLS");
        break;
      case '4':
        system("PAUSE");
        system("CLS");
        break;
      case '5':
        cout << "Ricardo Javier Porrata Samalot" << endl;
        cout << "Marc Anthony Maceira Zayas" << endl;
        cout << "Estefania Cristal Ramirez Ascar" << endl;
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
  double prices;
  Service theService;

  cin.ignore();
  cout << "Enter the new service: ";
  getline(cin,service);

  cout << "Enter the price: $";
  cin >> prices;
  
  cin.ignore();
  cout << "Enter the location: ";
  getline(cin,location);
  cout << endl;

  theService.setLocation(location);
  theService.setPrice(prices);
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