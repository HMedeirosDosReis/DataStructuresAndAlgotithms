#ifndef _CONNECTION_HPP_
#define _CONNECTION_HPP_
// FILE: Connection.hpp
// AUTHOR: Henrique Medeiros Dos Reis
// DATE: 4/28/2021
//    Definition file for Connection class, this class represents the edges between graphs, calling conections because it correlates better with airports 

#include <iostream>
class Connection
{
private:
    int _from;//integer representing which airport number it is from
    int _to;//integer representing which airport number it is going to
    int _price;//integer representing the price of this ticket
public:
	//constructor for a connection, it requires 3 integers as it paramentes, sets the instance variables equal to them
  	Connection(int from, int to, int price): _from(from), _to(to), _price(price){}
 	
 	// accessor and modifier for _from
  	const int from() const {return _from;}
  	int& from() {return _from;}
  	//accessor and modifier for _to
  	const int to() const {return _to;}
  	int& to() {return _to;}
  	//accessor and modifier for _prince
  	const int price() const {return _price;}
  	int& price() {return _price;}
  	
  	// method to write out a Rating via a stream 
  	std::ostream& print (std::ostream &os) const;
  	// overloaded << operator. 
  	friend std::ostream& operator<< (std::ostream &os, const Connection &con);
};

#endif 
