#ifndef Customer_h
#define Customer_h

#include <iostream>
#include <string>
#include "Shop.h"
using namespace std;

class Customer : public Shop {
protected:
  string name;
public:
  Customer();
  Customer(string);
  void setName(string);
  string getName() const;
};

#endif
