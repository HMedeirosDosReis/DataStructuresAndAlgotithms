#ifndef _SPLAY_NODE_HPP_
#define _SPLAY_NODE_HPP_
/*
	Splay Node header file
	Henrique Medeiros Dos Reis
	April 04 2021
*/
#include <iostream>
#include "SoccerTeam.hpp"
//this is a node that is made of a Soccer team, a pointer to the left, a pointer to the right
class SplayNode
{
private:
	SoccerTeam _val;
	SplayNode *_left;
 	SplayNode *_right;
public:
	//construtor for a node, it takes only one parameter, which is a SoccerTeam
 	SplayNode(SoccerTeam val): _val(val), _left(nullptr), _right(nullptr) {}
	//method used to print a node
 	std::ostream& print(std::ostream &os) const;
	//accessor and modifier for the value of this node, which is a soccer team
  	const SoccerTeam value() const {return _val;}
  	SoccerTeam & value() {return _val;}
	//accessor and modifier for the node in the left of this one  
  	const SplayNode* left() const {return _left;}
  	SplayNode* & left() {return _left;}
	//accessor and modifier for the node in the right of this one
  	const SplayNode* right() const {return _right;}
  	SplayNode* & right() {return _right;}
	//this method return a boolean variable that tells weather this node has childs or not, if it is a leaf
  	bool isLeaf() const { return !_left&&!_right; }
  	//method used to insert a new value in the tree, it requires where a pointer to a node, and the value wanted to insert 
  	SplayNode* insert(SoccerTeam newVal, SplayNode *intoSubTree);

	//this method will find a node and return it, since this is a splay tree, it will do all the needed rotations 
  	SplayNode* lookup(SoccerTeam val, SplayNode *subTree);
  	//overloaded method that will allow the usage of << when printing 
  	friend std::ostream& operator<<(std::ostream &os, const SplayNode &n);
};


#endif
