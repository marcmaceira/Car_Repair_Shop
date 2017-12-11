#include <iostream>
#include <fstream>
#include <string>
#include "Order.h"
#include "Customer.h"
#include "Date.h"

Order::Order()
{ theOrder = " "; }

Order::Order(string theOr)
{ theOrder = theOr; }

Order::~Order()
{ }

void Order::createReceipt()
{
  	ofstream myfile;
    string path = "Receipts\\" + getName() + ".txt";
  	myfile.open(path, ios::app);
  	myfile << getService() << ", $" << getPrice() << ", " << getLocation() << ", " << getTheDate() << endl;
  	myfile.close();
}

void Order::readReceipt()
{
  string line;
  string receipt = "Receipts\\" + getName() + ".txt";
	ifstream multiLineFile(receipt);

  if (multiLineFile.is_open())
  {//verify open file
    while (!multiLineFile.eof())
    {//while the file is not at the end
      getline(multiLineFile, line); //retrieve each line
      if (line != " ")
      { // it is not at the end of file
        cout << line << endl;
      }
    }
  }
}

void Order::createReceiptDB()
{
  int offset;
  ifstream Myfile;
  string line;

  Myfile.open("Receipts.csv", ios::app);
  if (Myfile.is_open())
  {
    while (Myfile.good())
    {
      getline(Myfile, line, ',');
      if (!((offset = line.find(getName(), 0)) != string::npos))
      {
        ofstream myfile;
        myfile.open("Receipts.csv", ios::app);
        myfile << getName() << endl;
        myfile.close();
      }
      else
      {
        cout << getName() << " already exists in the database" << endl;
      }
    }
    Myfile.close();
  }
  system("PAUSE");
}

void Order::readReceiptDB()
{
  ifstream myfile("Receipts.csv");
	string value;
	while (myfile.good())//validate file exists
	{
		getline(myfile, value, '\n'); // read a string until next comma
		cout << string(value) << endl; // display value and add tab for better display
	}
}

void Order::setCreationDate(int month, int day, int year)
{ theDate.setDate(month, day, year); }

string Order::getTheDate() const
{ return theDate.getDate(); }
