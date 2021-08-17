#ifndef _AVL_TREE_HPP_
#define _AVL_TREE_HPP_
/*
	AVL tree header file
	Henrique Medeiros Dos Reis
	April 04 2021
*/
#include "AVLNode.hpp"
//this is a tree that is of Soccer teams, in order to represent it, we just need an AVLNode that will be the root
#include <iostream>
#include "SoccerTeam.hpp"
class AVLTree
{
private:
	AVLNode *_root;
public:
	AVLTree():_root(nullptr) {}//default contructor
	//method used to insert a node to this tree
	void insert(SoccerTeam newVal);
	//method used to remove a node from this tree
	void remove(SoccerTeam val); 
  	//simple method to find a node in the tree, it also helps to keep the count of the number of node accesses before getting to the result, this is needed in order to compare to the splay tree result  
	AVLNode* find(AVLNode* ptr, int& avlAccess) const;
  	//method used to print the whole tree
 	std::ostream& display(std::ostream &os) const;
};
#endif
