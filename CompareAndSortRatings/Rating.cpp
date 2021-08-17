#include "Rating.hpp"

#include <iostream>
using namespace std;

// print method
ostream&
Rating::print (ostream &os) const
{
  //prints the name and the rate, with an R in the middle to idenetify
  os << _name << "    R:" << _rate;
  return os;
}


// overlaod << output operator for Rating
ostream& operator<< (ostream &os, const Rating &t)
{
  return t.print(os);
}
//overload = operator for Rating, sets both instance variables to be the same
const Rating&
Rating::operator=(const Rating &other)
{
	Rating *returnPtr = new Rating(other._name, other._rate);
	_name = other._name;
	_rate = other._rate;
	return *returnPtr;
}
