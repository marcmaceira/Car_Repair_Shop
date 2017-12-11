#include "Service.h"

using namespace std;

Service::Service()
{
  setCombo(combo);
}
Service::~Service()
{

}
void Service::setCombo(string com)
{
  combo = com;
}

string Service::getCombo() const
{
  return combo;
}

ostream &operator << (ostream &output,const Service &aService)
{
  output << "Service: " << aService.getService();
  output << endl;
  output << "Price: $" << aService.getPrice();
  output << endl;
  output << "Location: " << aService.getLocation();
  output << endl;
  return output;
}

void Service::createServiceDB() {
  ofstream myfile;
	myfile.open("Service.csv", ios::app);
	myfile << getService() << "," << setprecision(2) << fixed << "$" << getPrice() << ","  << getLocation() << endl;
	myfile.close();
}

void Service::showServiceDB() {
  cout << "Service\t\t\tPrice\t\tLocation" << endl;
  ifstream myfile("Service.csv");
	string value;
	while (myfile.good())//validate file exists
	{
		getline(myfile, value, ','); // read a string until next comma
		cout << string(value) << "\t\t"; // display value and add tab for better display
	}
  cout << endl;
}

Service Service::operator+(const Service&aService)
{
  Service ser;
  ser.price = price + aService.getPrice();
  return ser;
}
