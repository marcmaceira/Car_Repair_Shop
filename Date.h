#ifndef Date_h
#define Date_h

#include <iostream>
#include <string>
using namespace std;

class Date {
private:
  int day;
  int month;
  int year;
public:
  Date();
  ~Date();
  void setDay(int);
  void setMonth(int);
  void setYear(int);
  void setDate(int,int,int);
  int getDay() const;
  int getMonth() const;
  int getYear() const;

  string getDate() const;
};

#endif /* Date_h */
