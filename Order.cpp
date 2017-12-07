#include "Order.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Shop.h"

Order::Order()
{ theOrder = " "; }

Order::Order(string theOr)
{ theOrder = theOr; }

Order::~Order()
{ }

void Order::setTheOrder(string theOr)
{ theOrder = theOr;}

string Order::getTheOrder() const
{ return theOrder; }

void Order::createReceipt(int j)
{
    string service = getService();
  	double Theprice = getPrice();
  	string Thelocation = getLocation();
  	string order = theOrder;
  	ofstream myfile;
  	myfile.open("WritingObjectFile.txt", ios::app);
  	//while (int j == 0)
  	  myfile << order << ", " << service << ", " << Theprice << ", " << Thelocation << endl;
  	myfile.close();
}

void Order::readReceipt()
{
  string line;
	ifstream multiLineFile("WritingObjectFile.txt");

  if (multiLineFile.is_open())
  {//verify open file
    while (!multiLineFile.eof())
    {//while the file is not at the end
      getline(multiLineFile, line); //retrieve each line
      if (line != "")
      { // it is not at the end of file
        cout << line << endl;
      }
    }
  }
}
