#include "AVLTree.hpp"
#include "AVLNode.hpp"
#include "SplayNode.hpp"
#include "SplayTree.hpp"
#include "SoccerTeam.hpp"
#include <iostream>
#include <fstream>
using namespace std;
/*
	main file, this program should load a file containing soccer teams and then lookup some teams and compare how well does 
	one tree does comparing to the other tree, one using the AVL structure and one using the Splay structure
	Henrique Medeiros Dos Reis
	April 04 2021
*/
int main(int argc, char *argv[])
{
	//declare both of the trees
	AVLTree avlT;
	SplayTree splayT;
	//ask the input of the user
	cout<<"Please input 'F', 'L', or 'Q' (F for an input file, L for a lookup, and Q to quit."<<endl;
	cout<<">>>";
	char input; cin>>input;
	string fname;
	int avlAccess, splayAccess =0;//at the beggining of the program, both accesses should be 0
	while(input!='Q')//keep going until the user types 'Q'
	{
		if(input=='q')//makes this case insenstive
			return 0;
		else if(input=='F' || input =='f')//if the user input is f
		{
			cout<<"Enter a filename: ";//ask the used for the file name
			cin>>fname;
			ifstream ifile(fname);//go ahead and open the file
			SoccerTeam thisTeam;
			ifile>>thisTeam;//get the input from the filr
			while(ifile)//if the file inst null, there might be more teams
			{
				avlT.insert(thisTeam);//insert the value to the AVL tree
				splayT.insert(thisTeam);//insert the value to the splay tree
				ifile>>thisTeam;//get the next team from the input file
			}
		}
		else if(input=='L' || input =='l')//if the user input is l
		{
			cout<<"Enter the name of a team: ";//get the name of the team that the user wants to look at
			string teamName;
			cin>>teamName;
			SoccerTeam newTeam = SoccerTeam(teamName, 0,0);//start a team with the same name as the team we want to find, since they only compare the name and not the wins and losses, we can set both wins and loses to 0 
			AVLNode* ptrTeam = new AVLNode(newTeam);//make an AVL pointer of this team
			AVLNode* found = avlT.find(ptrTeam, avlAccess);//try to find this team in the tree
			cout<<"Found: "<<found->value()<<endl;//print the team we found in the tree
			
			SplayNode* ptrTeamS = new SplayNode(newTeam);//make a Splay pointer of this team
			SplayNode* foundS = splayT.findS(ptrTeamS, splayAccess);//try to find this team in the tree
			splayT.lookup(newTeam);//also, lookup the team, so we can have the actual rotations done
			//print the results
		 	cout<<"Total AVL nodes accessed during searches: "<<avlAccess<<endl;
		 	cout<<"Total Splay nodes accessed during searches: "<<splayAccess<<endl;
		}
		else//if im here, then the input inst valid, let the user know and keep running
			cout<<"Invalid input, please try again!"<<endl;
		cout<<">>>";
		cin>>input;
	}
 	return 0;//
}
