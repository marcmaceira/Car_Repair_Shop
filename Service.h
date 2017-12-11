#ifndef Service_h
#define Service_h

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Shop.h"
using namespace std;

class Service : public Shop{
private:
string combo;
public:
Service();
~Service();
void setCombo(string com);
string getCombo() const;
friend ostream &operator<<(ostream&output,const Shop&);
void createServiceDB();
void showServiceDB();
Service operator+(const Service&);
};

#endif // Service_h
