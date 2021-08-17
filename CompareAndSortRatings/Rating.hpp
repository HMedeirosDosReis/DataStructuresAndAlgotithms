#ifndef _SOCCER_TEAM_HPP_
#define _SOCCER_TEAM_HPP_

// FILE: Rating.hpp
// AUTHOR: Henrique Medeiros Dos Reis
// DATE: 4/17/2021
//    Definition file for Rating class class 


#include <string>
#include <iostream>

class Rating
{
private:
	std::string _name;   //name of this rating
	int _rate;            //where it is stading comparing to the others
public:
  // default constructor
	Rating() : _name(), _rate(0) {}

  // fully qualified constructor
  	Rating(const std::string &name, int rate): _name(name), _rate(rate) {}

  // accessor and modifier for name
  const std::string& name() const {return _name;}
  std::string& name() {return _name;}

  // accessor and modifier for rate
  const int rate() const {return _rate;}
  int& rate() {return _rate;}


  // overloaded assignment operator
  const Rating& operator=(const Rating &other);

  // overloaded less than and greater than operators if needed for sorting
  bool operator<(const Rating &other) const {return _rate < other._rate;}
  bool operator>(const Rating &other) const {return _rate > other._rate;}
  
  // method to write out a Rating via a stream 
  std::ostream& print (std::ostream &os) const;

  // overloaded << operator. 
  friend std::ostream& operator<< (std::ostream &os, const Rating &rating);

};

#endif
