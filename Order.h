#ifndef Order_h
#define Order_h
#include <iostream>
#include <string>
#include "Shop.h"
using namespace std;

class Order : public Shop {
private:
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
