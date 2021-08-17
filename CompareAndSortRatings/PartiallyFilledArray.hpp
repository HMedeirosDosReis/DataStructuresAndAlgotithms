#ifndef _PARTIALLY_FILLED_ARRAY_H_
#define _PARTIALLY_FILLED_ARRAY_H_
/*
	Partially Filled Array header file
	Henrique Medeiros Dos Reis
	April  2021
*/
#include <iostream>
#include <string>
#include "Rating.hpp"

#define MAX_SIZE 10

class PartiallyFilledArray
{
private:
	Rating *_data;//pointer to the array
	int _maxSize;//int that holds the maximum size
	int _currSize;//int that holds the current size
public:
	PartiallyFilledArray();//contructor, creates an array of size MAX_SIZE, sets _maxSize to 10, and _currSize to 0
	
	//Acessor and modifier for the array
	Rating*& data(){return _data;}
	const Rating* data()const {return _data;};
	//Accessor and modifier for the _currSize
	const int size() const {return _currSize;}
	int& size() {return _currSize;}
	//method used to double the size of the array when needed 
	void resize(); 
	//acts like a normal [] in a normal array 
	Rating& operator[](int index) const;
	//adds an element to this PFA
	void operator+=(const Rating value);
	
	//these three following methods will be used to count the inversions, in this array. 
	int countInversions();
	int countInversions(Rating myArray[],Rating temporary[], int left, int right);
	int inversionsBetween(Rating myArray[], Rating temporary[],int left, int middle, int right);
	
	//Methods that will allow us to print the array
	std::ostream& print(std::ostream &os) const;
	friend std::ostream& operator<<(std::ostream &os, const PartiallyFilledArray &PFA){return PFA.print(os);}
	
};

#endif
