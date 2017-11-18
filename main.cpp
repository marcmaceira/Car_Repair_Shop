#include <iostream>
#include <cstdlib>
#include <cctype>
#include "Shop.h"
using namespace std;

void MainMenu();
Shop *TheServices = new Shop[100];

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
    cout << "===================================" << endl;
    cout << "Menu" << endl;
    cout << "1 - Enter a new service" << endl;
    cout << "2 - Manage services" << endl;
    cout << "3 - Enter a customer service order" << endl;
    cout << "4 - Print/Export all service items" << endl;
    cout << "5 - About this program" << endl;
    cout << "E - Exit" << endl;
    cout << "===================================" << endl << endl;

    cout << "Choose an option: ";
    cin >> option;
    switch (option) {
      // Adds a new service to the offered services list
      case '1':
      {
        string service;
        double prices;
        Shop shopper;
        cin.ignore();
        cout << "Enter the new service: ";
        getline(cin,service);
        cout << "Enter the price: $";
        cin >> prices;
        cout << endl;

        shopper.setPrice(prices);
        shopper.setService(service);

        // <-- PRUEBA
        int i = 0;
        TheServices[0] = shopper;
        // -->

        cout << shopper;

        system("PAUSE");
        system("CLS");
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

  } while(option == '1' || option == '2' ||option== '3' || option== '4' || option == '5' || option =='E' || option=='e');
}
