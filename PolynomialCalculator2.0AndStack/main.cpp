/*
* Henrique Medeiros Dos Reis 
* Feb 27 2020 versrion
* project 2 CSC36000
*/


#include <iostream>
#include <list>
#include "Term.hpp"
#include "Polynomial.hpp"
#include "MyStack.hpp"
#include "MyStack.ctt"

using namespace std;

int main(int argc, char* argv[])
{	
	//creates a stack of polynomials
	MyStack<Polynomial> polyStack;
	//get the user choice from the keybord
	char choice;
	cout<<">>>";
	cin >> choice;
	// while the user input is not q, keep going
	while(choice!='q')
	{	
		if(choice == 'c')//in case the user types 'c', simply remove the top element
		{	
			if(!polyStack.isEmpty())//check to see if the stack is not empty
			{
				polyStack.pop();//remove the element
				cout<<polyStack.top()<<endl;//print the last element in the stack
			}
			else
				cout<<"The stack is empty, please enter polynomials in the stack before using this option"<<endl;
		}
		else if(choice == 'd') // remove all elements in the accumulator
		{
			while(!polyStack.isEmpty())//keep removing items from the stack, until it is empry
				polyStack.pop();
		}
		else if(choice == 's')//if the user wants to store a new poylonimial
		{	//get the polynomial from the user input
			Polynomial polyToStore;
			cout << "Enter a polynomial to push: ";
			cin>>polyToStore;
			polyStack.push(polyToStore);//add the element to the stack
			cout<<polyStack.top()<<endl;//print the top element in the stack
		}
		else if(choice == 'e')//if the user wants to evaluate the polynomial
		{
			if(!polyStack.isEmpty())//check to see if the stack is empty
			{	//get the value that the user wants to evaluate the polynomial
				double userValue;
				cout<<"Enter a value of x at which to evaluate polynomial: ";
				cin>>userValue;
				Polynomial polyToEvaluate = polyStack.top();//get the last element added to the stack
				cout<<polyToEvaluate.eval(userValue)<<endl;//evaluate and print the result
				cout<<polyStack.top()<<endl;//print the polynomial that is the top of the stack
			}
			else
				cout<<"The stack is empty, please enter polynomials in the stack before using this option"<<endl;
		}
		else if(choice == '+')// if the user wants to add two polynomials
		{	
			if(!polyStack.isEmpty())//check to see if the stack is empty
			{
				Polynomial first = polyStack.top();//get the first element from the stack
				polyStack.pop();//remove the element from the stack
				if(!polyStack.isEmpty())//check if now it is empty or not
				{
					Polynomial second = polyStack.top();// get the second element from the stack
					polyStack.pop();//remove the element 
					Polynomial result = second + first;//add both elements
					polyStack.push(result);//push it in to the sack
					cout<<polyStack.top()<<endl;//print the result
				}
				else
				cout<<"The stack needs to have two polynomials for this operation, please enter another polynomial in the stack before using this option"<<endl;
			}
			else
				cout<<"The stack is empty, please enter polynomials in the stack before using this option"<<endl;
		}
		else if(choice == '-')// if the user wants to subtract two polynomials
		{	
			if(!polyStack.isEmpty())//check to see if the stack is empty
			{
				Polynomial first = polyStack.top();//get the first element from the stack
				polyStack.pop();//remove the element from the stack
				if(!polyStack.isEmpty())//check if now it is empty or not
				{
					Polynomial second = polyStack.top();// get the second element from the stack
					polyStack.pop();//remove the element 
					Polynomial result = second - first;//subtract both elements
					polyStack.push(result);//push the result in to the stack
					cout<<polyStack.top()<<endl;//print the result
				}
				else
				cout<<"The stack needs to have two polynomials for this operation, please enter another polynomial in the stack before using this option"<<endl;
			}
			else
				cout<<"The stack is empty, please enter polynomials in the stack before using this option"<<endl;
		}
		else if(choice == '*')// if the user wants to multiply two polynomials
		{	
			if(!polyStack.isEmpty())//check to see if the stack is empty
			{
				Polynomial first = polyStack.top();//get the first element from the stack
				polyStack.pop();//remove the element from the stack
				if(!polyStack.isEmpty())//check if now it is empty or not
				{
					Polynomial second = polyStack.top();// get the second element from the stack
					polyStack.pop();//remove the element 
					Polynomial result = first * second;//multiply both elements
					polyStack.push(result);//push the result in to the stack
					cout<<polyStack.top()<<endl;//print the result
				}
				else
				cout<<"The stack needs to have two polynomials for this operation, please enter another polynomial in the stack before using this option"<<endl;
			}
			else
				cout<<"The stack is empty, please enter polynomials in the stack before using this option"<<endl;
		}
		else if(choice == 'p')//if the user wnats to print the top polynomial
		{	
			if(!polyStack.isEmpty())//make sure the stack isnt empty
				cout<<polyStack.top()<<endl;
			else
				cout<<"The stack is empty, please enter polynomials in the stack before using this option"<<endl;
		}
		else if(choice == 'q')//if the user wants to quit
		{	
			cout<<"Thank you for using polyCalc!";
			return 0;
		}
		else//in case the user chooses a nonmatch choice 
			cout<<"This option is not supported. Please select one of the available options."<<endl;
		cout<<">>>";
		cin >> choice;
		
	}
	cout<<"Thank you for using polyCalc!"<<endl;
	return 0;
}
