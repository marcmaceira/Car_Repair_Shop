#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <string>
#include "NegativeNum.h"
using namespace std;

class Shop
{
protected:
  double price;
  string service;
  string location;

public:
  Shop();
  Shop(double, string);
  ~Shop();
  void setLocation(string loc);
  string getLocation() const;
  void setPrice(double);
  double getPrice() const;
  void setService(string);
  string getService() const;
  void Show();
  Shop operator+(Shop&);
  friend ostream &operator<<(ostream&output,const Shop&);
};

#endif
