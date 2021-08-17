#ifndef _SPLAY_TREE_HPP_
#define _SPLAY_TREE_HPP_
/*
	AVL tree header file
	Henrique Medeiros Dos Reis
	April 04 2021
*/
#include <iostream>

#include "SplayNode.hpp"
#include "SoccerTeam.hpp"
//this is a tree that is of Soccer teams, in order to represent it, we just need an SplayNode that will be the root
class SplayTree
{
private:
	SplayNode *_root;
public:
 	SplayTree(): _root(nullptr) {}//default contructor
	//method used to print the whole tree
	std::ostream& display(std::ostream &os) const;
  	//simple method to find a node in the tree, it also helps to keep the count of the number of node accesses before getting to the result, this is needed in order to compare to the AVL tree result. this does not impact the rotations, so it shoudl always be used before rotating to be accurate. And then call the lookup in order to get the rotations done.
  	SplayNode* findS(SplayNode* ptr, int& splayAccess) const;
	//method used to insert a node to this tree
  	void insert(SoccerTeam newVal) {if (!_root) _root=new SplayNode(newVal); else _root=_root->insert(newVal, _root);} 
  	//method used to lookup a value in the tree and then do the needed rotations
  	void lookup(SoccerTeam val) {_root=_root->lookup(val, _root);}
};

#endif
