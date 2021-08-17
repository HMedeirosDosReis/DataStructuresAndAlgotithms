// FILE: Connection.cpp
// AUTHOR: Henrique Medeiros Dos Reis
// DATE: 4/28/2021
//    implementation file for the remaining of Connection class 
#include "Connection.hpp"

#include <iostream>
using namespace std;

// print method
ostream&
Connection::print (ostream &os) const
{
  //prints from which is the connetion comming from and to where it is going, lastly the price
  os << _from << "    to:" << _to<<"price: "<<_price<<"->";
  return os;
}
//overloaded operator<< simply calls the print method
ostream& operator<< (ostream &os, const Connection &t)
{
  return t.print(os);
}


