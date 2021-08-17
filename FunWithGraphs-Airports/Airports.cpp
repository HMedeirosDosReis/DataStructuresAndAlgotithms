// FILE: Airports.cpp
// AUTHOR: Henrique Medeiros Dos Reis
// DATE: 4/28/2021
//   implementation file for the remaining of the Airports class 

#include "Airports.hpp"

#include <iostream>
using namespace std;

// print methodm the only thing that needs to be seen is the name, this method prints it 
ostream&
Airports::print (ostream &os) const
{
  os <<_name;
  return os;
}
//this overloaded method simply calls print
ostream& operator<< (ostream &os, const Airports &t)
{
  return t.print(os);
}

