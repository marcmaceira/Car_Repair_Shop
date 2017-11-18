#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <string>
using namespace std;

class Shop
{
private:
  double price;
  string service;

public:
  Shop();
  Shop(double, string);
  ~Shop();
  void setPrice(double);
  double getPrice() const;
  void setService(string);
  string getService() const;
  void Show();
  friend ostream &operator<<(ostream&output,const Shop&);
};

#endif

/*

*/
