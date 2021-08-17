#include "PartiallyFilledArray.hpp"
#include "Rating.hpp"
#include <iostream>
using namespace std;
/*
	Partially Filled Array implementation, cpp file
	Henrique Medeiros Dos Reis
	April  2021
*/

//Constructor, it does not require any paramentes. Constructs a PFA of Rating, with maximum size of 10, but currently holding 0
PartiallyFilledArray::PartiallyFilledArray()
{
	_data = new Rating[MAX_SIZE];
	_maxSize = 10;
	_currSize = 0;
}
//method to resize this array, it does no require any parameters, and returns nothing
void
PartiallyFilledArray::resize()
{
	Rating *safer = new Rating[_maxSize*2];// create a new array with double size
	
	for(int i=0; i<_currSize; i++)//loop through this array
		safer[i]=_data[i];//the index of this new array is equal to the index of this array
		
	_maxSize=_maxSize*2;//update the maximum size
	_data=safer;//this array is now equal to the array we just created and modified
}

//Method used to get access to the object in a index, it requires an integer as its paremeter, and returns this object
Rating& 
PartiallyFilledArray::operator[](int index) const
{
	return _data[index];
}
//method used to add an element to this array, it requires what you want to add as a parameter
void 
PartiallyFilledArray::operator+=(const Rating value)
{
	if(_currSize>=_maxSize)//check if we need to resize
	{
		resize();
		_data[_currSize]=value;//put the value in the array
	}
	_data[_currSize]=value;//put the value in the array 
	_currSize++;//increment its size
}
//method used to print the whole PFA
std::ostream& 
PartiallyFilledArray::print(std::ostream &os) const
{
	for(int i=0; i<_currSize;i++)//loop through the array 
		cout<<_data[i]<<endl;//print each element
	return os;
}
//method to count inversions, thats were we start, it will return the number of inversions
int 
PartiallyFilledArray::countInversions()
{
	Rating temporary[_currSize];//create a temporary array, of the same size as the one we have 
	return countInversions(_data,temporary, 0, _currSize-1);//start the recursion
}
//this method will count the inversions, it requires 2 arrays, since it is going to be recursively changing it, and 
//where is the left and right of the first array
int
PartiallyFilledArray::countInversions(Rating myArray[],Rating temporary[], int left, int right)
{
	int inversions = 0;//to start with, inversions is 0
	int middle= (left+right)/2;//the middle is just the left + the right / 2
	if(right > left)//if my right is still bigger than my left, that means im not not
	{
		//go ahead and solve this recursivelly from the right half of this array
		inversions+=countInversions(myArray, temporary, middle+1, right);
		//also, solve from the beggining to the middle
		inversions+=countInversions(myArray, temporary, left, middle);
		//glue them back together, and count the number of inversions between them
		inversions+=inversionsBetween(myArray,temporary, left, middle+1, right);
	}
	//when I get here, I am done, return the number of inversions that was needed
	return inversions;
} 
//This method will count the number of inversions between each sub array, and put them back together
int
PartiallyFilledArray::inversionsBetween(Rating myArray[], Rating temporary[],int left, int middle, int right)
{
	int leftSubArrayBegin = left;//my sub array in the left starts in the most left point
	int rightSubArrayBegin = middle;//my sub array in the right starts in the middle point
	int resultantSubArray = left;//the result starts in the left
	int inversions = 0;
	//did I reach the middle comming from the left? and did I reach the right comming from the middle? keep going until do both
	while(leftSubArrayBegin<middle && rightSubArrayBegin <= right)
	{
		if(myArray[leftSubArrayBegin]<myArray[rightSubArrayBegin])//is my left smaller than my right?
		{
			temporary[resultantSubArray] = myArray[leftSubArrayBegin];//put the left in the result
			resultantSubArray++;//increment the size of the result
			leftSubArrayBegin++;//go to the next element in the left
		}
		else if(myArray[rightSubArrayBegin]<myArray[leftSubArrayBegin])//is my right smaller than my left?
		{
			temporary[resultantSubArray] = myArray[rightSubArrayBegin];//put the right in the result
			resultantSubArray++;//increment the size of the result
			rightSubArrayBegin++;//go to the next element in the right
		//the number of inversions is where the middle is, where my left sub array is starting now + my previous inversions
			inversions = middle-leftSubArrayBegin+inversions;
		}
	}
	while(leftSubArrayBegin < middle)//go from the left to the middle
	{
		temporary[resultantSubArray] = myArray[leftSubArrayBegin];//put the elements in the temporary array
		resultantSubArray++;//increment the size of the result
		leftSubArrayBegin++;//go to the next element
	}
	while(rightSubArrayBegin <= right)//go from the middle to the right
	{
		temporary[resultantSubArray] = myArray[rightSubArrayBegin];//put the elements in the temporary array
		resultantSubArray++;//increment the size of the result
		rightSubArrayBegin++;//go to the next element
	}
	for(int i = left; i<=right; i++)//loop throgh the whole array
		myArray[i] = temporary[i];//the first array is now the temporary onw
	return inversions;//return the number of inversions
}











