#include "Date.h"
#include <string>
using namespace std;

Date::Date()
{
  setDay(day);
  setMonth(month);
  setYear(year);
}
Date::~Date()
{

}
void Date::setDay(int d)
{
  day = d;
}
void Date::setMonth(int m)
{

  month = m;
}
void Date::setYear(int y)
{
  year = y;
}
int Date::getDay() const
{
  return day;
}
int Date::getMonth() const
{
  return month;
}
int Date::getYear() const
{
  return year;
}
void Date::setDate(int d,int m,int y)
{
  day = d;
  month = m;
  year = y;
}

string Date::getDate() const
{
  string datePart1;
  string datePart2;
  string datePart3;
  string theDate;


  datePart1 = to_string(month);
  datePart2 = to_string(day);
  datePart3 = to_string(year);
  
  theDate = datePart1 + "/" + datePart2 + "/" + datePart3;
  return theDate;
}
