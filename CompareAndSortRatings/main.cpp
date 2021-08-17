#include <iostream>
#include <fstream>
#include <string>
#include "PartiallyFilledArray.hpp"
#include "Rating.hpp"
/*
	main file, this program should load a file with the ratings of something, one line for each, then read a second file
	following the same rules as the first one. Than compare and see how many inversions are between those 2 files.
	Henrique Medeiros Dos Reis
	April 17 2021
*/
using namespace std;

int main(int argc, char* argv[])
{
	string fileName1, fileName2;//strings that will hold the name of the files
	cout<<"Enter first ranking file: ";
	cin>>fileName1;
	
	ifstream ifile1(fileName1);//open the file
	
	PartiallyFilledArray rating1;//create a PFA, that will hold the ratings
	string names1;//string that will hold each of the lines in the input file
	getline(ifile1, names1);//use get line, since it is possible to contain spaces between them 
	while(ifile1)
	{//create a rating, where the name comes from the input file, and the how "high" it is in the ratings, its the currrent 
	//size +1, so we dont have zeros
		Rating rates= Rating(names1,rating1.size()+1);
		rating1+=rates;//add this one to the array
		getline(ifile1, names1);//get the next line
	}	
	
	cout<<"Enter second ranking file: ";
	cin>>fileName2;//get the second input file name from the keybord
	
	ifstream ifile2(fileName2);//open the file
	
	PartiallyFilledArray rating2;//create the second array, which will contain the second person preferences
	string names2;
	//go ahead and load the same, but for the second file now
	getline(ifile2, names2);
	while(ifile2)
	{
		Rating rates= Rating(names2,rating2.size()+1);
		rating2+=rates;
		getline(ifile2, names2);	
	}
	PartiallyFilledArray wrongPlaces;//create a new PFA with only the values that are in different places comparing the first and second
	for(int i; i<rating1.size(); i++)
	{
		if(rating1[i].name()!=rating2[i].name())
			wrongPlaces+=rating1[i];
	}
	for(int i=0; i<rating2.size(); i++)//loop the second array
	{	
		for(int j=0;j<wrongPlaces.size(); j++)//loop just the incorrect array
		{	
			if(rating2[i].name()==wrongPlaces[j].name())//if the diffrennt is equal to me in names 
			{
				rating2[i].rate()=wrongPlaces[j].rate();//then change my rate
				j=100;//quit this loop 
			}
		}
	}
	int inversions= rating2.countInversions();//count the inversions between them
	cout<<"The total number of inversions is "<<inversions<<"."<<endl;
	return 0;
}
