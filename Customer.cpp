#include <iostream>
#include <string>
#include "Customer.h"

Customer::Customer()
  { name = " "; }

Customer::Customer(string cu)
  { setName(cu); }

void Customer::setName(string aName)
  { name = aName; }

string Customer::getName() const
  { return name; }
