#ifndef Order_h
#define Order_h
#include <iostream>
#include <string>
#include <fstream>
#include "Customer.h"
#include "Date.h"
using namespace std;

class Order : public Customer {
protected:
  string theOrder;
  Date theDate;
public:
  Order();
  Order(string);
  ~Order();
  void setTheOrder(string);
  void setCreationDate(int, int, int);
  string getTheDate() const;
  string getTheOrder() const;
  void createReceipt();
  void readReceipt();
  void createReceiptDB();
  void readReceiptDB();
};

#endif // Order_h
