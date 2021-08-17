#ifndef _AIRPORTS_HPP_
#define _AIRPORTS_HPP_
// FILE: Airports.hpp
// AUTHOR: Henrique Medeiros Dos Reis
// DATE: 4/28/2021
//    Definition file for Airports class 


#include <iostream>
#include <string>
//This class helps to identify the airport by name and number
class Airports
{
private:
    std::string _name;//string that holds the name of the airport
    int _number;//integer that represents the number of that airport
public:
	//constructor of airports, it requires a name and a number as a parameter, simply puts that into the intance variables
  	Airports(std::string name, int number): _name(name), _number(number){}
 	
 	// accessor and modifier for name
  	const std::string name() const {return _name;}
  	std::string& name() {return _name;}
  	
  	//accessor and modifer for number 
  	const int number() const {return _number;}
  	int& number() {return _number;}
  	
  	//method and overload for printing an airport, mainly to help debbuging 
  	std::ostream& print (std::ostream &os) const;
 	friend std::ostream& operator<< (std::ostream &os, const Airports &node);
};

#endif
