#ifndef Order_h
#define Order_h
#include <iostream>
#include <string>
#include "Customer.h"
using namespace std;

class Order : public Customer {
protected:
  string theOrder;
public:
  Order();
  Order(string);
  ~Order();
  void setTheOrder(string);
  string getTheOrder() const;
  void createReceipt(int j);
  void readReceipt();
};

#endif // Order_h
