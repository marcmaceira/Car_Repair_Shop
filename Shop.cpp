#include "Shop.h"

Shop::Shop()
{
  service = "";
  price = 0.00;
};

Shop::Shop(double price, string service)
{
  setService(service);
  setPrice(price);
};

Shop::~Shop()
{

};

void Shop::setPrice(double aPrice)
{
  price = aPrice;
};

double Shop::getPrice() const
{
  return price;
};

void Shop::setService(string aService)
{
  service = aService;
};

string Shop::getService() const
{
  return service;
};

void Shop::Show()
{
  cout << "Service: " << getService() << endl;
  cout << "Price: $" << getPrice() << endl;
};

ostream &operator<<(ostream&output,const Shop&aShop)
{
  output << "Service: " << aShop.getService();
  output << endl;
  output << "Price: $" << aShop.getPrice();
  output << endl;
  return output;
};
