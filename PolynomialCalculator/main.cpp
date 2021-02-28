/*
* Henrique Medeiros Dos Reis 
* Feb 6 2020 versrion
* project 1 CSC36000
*/


#include <iostream>
#include <list>
#include "Term.hpp"

using namespace std;

int main(int argc, char* argv[])
{	
	std::list<Term> polynomial;//create a list that will hold the polynomial
	char choice;
	cout<<">>>";
	cin >> choice;
	int shouldPrint = 0;
	// while the user input is not q, keep going
	while(choice!='q')
	{	
		if(choice == 'c')//in case the user types 'c', clear the polynomial and set should print to true
		{
			polynomial.clear();
			shouldPrint=1;
		}
		else if(choice == 's')//if the user wants to store a new poylonimial
		{	
			polynomial.clear();//clear the current one
			Term myTerm;//create a term
			cin >> myTerm;//get the term from the input
			polynomial.push_back(myTerm);//place it in the list 
			while(myTerm.coefficient() != 0 || myTerm.degree() != 0)//if the degree or the coefficient are not 
			{//equal to zero, keep going
				cin >> myTerm;
				polynomial.push_back(myTerm);
			}
			polynomial.sort();//sort the list so it is in order of degrees
			shouldPrint=1;
			
		}
		else if(choice == 'e')//if the user wants to evaluate the polynomial
		{
			int sum=0;//creates a sum that will hold the total value of the polynomial
			float userNum;
			cin >> userNum;
			if(polynomial.empty())//if the polynomial is empty, the evaluation should be 0
				cout<<0;
			std::list<Term>::iterator it;//create a iterator to run through my list 
			int sumCoef=0;
			int currDegree=0;
			std::list<Term> resultant;
			Term myTerm;
			polynomial.sort();
			//make sure this polynomial is in order and there is no repering terms with the same degree
			for(it=polynomial.begin(); it!=polynomial.end(); it++)
			{	
				if(sumCoef==0)//if there is no polynomail before me that had the same degree, set the sumCoef to me
					sumCoef=it->coefficient();
				//creates an iterator that will represent my next term
				std::list<Term>::iterator nextP = it;
				nextP++;
				Term next = *nextP;
				if(next.degree()==it->degree())//if this term and the next termo have the same degree, sum their coefficient
					sumCoef+=next.coefficient();
				else if(next.degree()!=it->degree())//in case they dont have the same
				{
					currDegree=it->degree();//set curr degree to be the degree of this term
					myTerm = Term(sumCoef, currDegree);//create a new term of this degree and the sum of the coefficients up to now
					resultant.push_back(myTerm);//put it in the resultant list
					resultant.sort();//sort it
					sumCoef=0;//set sumCoef to 0, so it can start the next degree
				}
				
			}
			polynomial.clear();
			//stores the result of the polynomial in the actual polynomial
			polynomial = resultant;
			//dont forget that 3x^3+4 = 3x^3+0x^2+0x+4
			//Therefore, instead of creating a list with 0 in the coeficients for the corresponding degrees, lets
			// make it be a loop that will represent the degrees where coefficients are equal to 0. 
			// and in this way we are still O(n) were n is representing the degree of the polynomial, and not the 
			// number of terms in the polynomial list
			for(it=polynomial.begin(); it!=polynomial.end(); it++)
			{	
				if(it->coefficient()!=0)//check if my coefficient is 0
					sum = (sum * userNum) + it->coefficient();//if it not, we multiply by the user choice and add the coef
				if(it->coefficient()==0 && it->degree() !=1)
					sum = sum * userNum;//if coefficient is 0, but my degree is not equal to 1 just multiply the sum by the user num
				{
					int thisD=it->degree();//thisD is equal to the degree of the polynomial being analized now
					//creates a pointer to the next element
					std::list<Term>::iterator nextP = it;
					nextP++;
					thisD--;
					int nextD = nextP->degree();//hold the next degree
					while(thisD>nextD)//keep going until thisD is equal to the next
					{
						thisD--;//decrement this degree
						sum = sum * userNum;//multiply by user num (7x)*x if 7x^2, for example
					}					
				}
			}
			cout << sum<< endl;
			shouldPrint=1;
		}
		else if(choice == '+')// if the user wants to add a term to the polynomial
		{	
			std::list<Term> polyToAdd;//create a list with the polynomial they want to add
			//follow the same proccess as to create the first polynomial
			Term myTerm;
			cin >> myTerm;
			polyToAdd.push_back(myTerm);
			while(myTerm.coefficient() != 0 || myTerm.degree() != 0)
			{
				cin >> myTerm;
				polyToAdd.push_back(myTerm);
			}
			polyToAdd.sort();
			//iterates through the polynomial the user wants to add
			std::list<Term>::iterator it;
			for(it=polyToAdd.begin(); it!=polyToAdd.end(); it++)
			{	
				//append every element in this polynomial to the polynomial we started with
				polynomial.push_back(*it);
			}
			polynomial.sort();
			shouldPrint=1;
			//should print accumulator after this
		}
		else if(choice == '-')
		{	
		//follow the same procces as the '+' choice, with only one difference, instead of putting the value, put the 
		//negative value of that number
			std::list<Term> polyToSub;
			Term myTerm;
			cin >> myTerm;
			polyToSub.push_back(myTerm);
			while(myTerm.coefficient() != 0 || myTerm.degree() != 0)
			{
				cin >> myTerm;
				polyToSub.push_back(myTerm);
			}
			polyToSub.sort();
			std::list<Term>::iterator it;
			for(it=polyToSub.begin(); it!=polyToSub.end(); it++)
			{	
				Term negTerm = *it;
				//the only difference is here, where we multiply the coefficient by -1
				negTerm.coefficient() = negTerm.coefficient() * -1;
				polynomial.push_back(negTerm);
			}
			polynomial.sort();
			shouldPrint=1;
			//should print accumulator after here
		}
		else if(choice == '*')
		{	//if the user choice is * 
			//we will need two lists, the result of the operation and the polynomial the user wants to multiply by
			std::list<Term> resultant;
			std::list<Term> polyToMul;
			Term myTerm;
			cin >> myTerm;
			//get the input from the user and store in the elements to multiply vy
			polyToMul.push_back(myTerm);
			while(myTerm.coefficient() != 0 || myTerm.degree() != 0)
			{
				cin >> myTerm;
				polyToMul.push_back(myTerm);
			}
			polyToMul.sort();
			std::list<Term>::iterator it;
			//the multiplication is given (x+n)(x+n) where the first term multiply the whole polynomial, and the second 
			//does the same for n terms
			for(it=polynomial.begin(); it!=polynomial.end(); it++)//this is looping through the original poly
			{
				std::list<Term>::iterator it2;
				for(it2=polyToMul.begin(); it2!=polyToMul.end(); it2++)//this is looping through the seccond polynomial
				{	//multiply the looping term in the first list by the second looping term
					Term newTerm = Term(it->coefficient()*it2->coefficient(), it->degree()+it2->degree());
					if(newTerm.coefficient()!=0)	
					{
						resultant.push_back(newTerm);//put the element in the result
					}
				}
			}
			polynomial.clear();//clear the list 
			polynomial=resultant;//the polynomial is now equal to the 
			shouldPrint=1;
		}
		else if(choice == 'p')//if the user wnats to print the polynomial
		{	
			shouldPrint=1;
		}
		else if(choice == 'q')//if the user wants to quit
		{	
			cout<<"Thank you for using polyCalc!";
			return 0;
		}
		
		else//in case the user chooses a nonmatch choice 
			cout<<"This option is not supported. Please select one of the available options."<<endl;
		
		if(shouldPrint)
		{
			cout<<"Accumulator = ";//in case it is empty, should print a 0 after
			if(polynomial.empty())
				cout<<0;
			std::list<Term>::iterator it;
			int sumCoef=0;
			int currDegree=0;
			std::list<Term> resultant;
			Term myTerm;
			polynomial.sort();
			//loops through the polynomial
			for(it=polynomial.begin(); it!=polynomial.end(); it++)
			{	
				if(sumCoef==0)//if the coeff is still 0
					sumCoef=it->coefficient();//then my coef is equal to the coef in this iteration
				//creates a iterator that will point to the next term
				std::list<Term>::iterator nextP = it;
				nextP++;
				Term next = *nextP;
				
				if(next.degree()==it->degree())//if the degrees are the same
				{
						sumCoef+=next.coefficient();//sum the coeff so that 3x^2+x^2 = 4x^2 in only one term of the same degree
					
				}
				else if(next.degree()!=it->degree())//if the degrees are no longer equal
				{
					currDegree=it->degree();//change the curr degree
					myTerm = Term(sumCoef, currDegree);
					if(sumCoef!=0)//if the coef is not 0
					{
						//put this term in the result of this polynomial
						resultant.push_back(myTerm);
						resultant.sort();
					}
					sumCoef=0;
				}
				
				
			}
			//now that it is sure that our polynomial no longer have repeting degrees, we can print it
			for(it=resultant.begin();it!=resultant.end();it++)//loop through the list
			{
				std::list<Term>::iterator nextP = it;
				nextP++;
				Term next = *nextP;
				//if my next coef is equal to 0, im the last term, just print me, if my degree is 0, do the same
				if(next.coefficient() ==0 || it->degree()==0)
					cout<<*it;
				else if(nextP->coefficient() < 0)//if my next coef is negative, just print me, i already have the - sign
					cout<<*it;
				else if(it->coefficient() != 0)//if my coeff is not 0 and i am not any of the options above, then pring me and the + sign
					cout<<*it<<"+";
				
				
				else//else, im done, pring a new line
					cout<<endl;
				if(next.degree()==0 && next.coefficient()==0)//if my next degree and my next coef is 0, go to the next term
					it++;
			}
			cout<<endl;//
		}//reset should print and start over
		shouldPrint = 0;
		cout<<">>>";
		cin >> choice;
		
	}
	cout<<"Thank you for using polyCalc!"<<endl;
	return 0;
}
