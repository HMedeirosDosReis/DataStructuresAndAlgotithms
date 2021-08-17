#ifndef _AVL_NODE_HPP_
#define _AVL_NODE_HPP_
/*
	AVL Node header file
	Henrique Medeiros Dos Reis
	April 04 2021
*/
#include <iostream>
#include "SoccerTeam.hpp"
//this is a node that is made of a Soccer team, a pointer to the left, a pointer to the right, and an integer that will represent the height of this node
class AVLNode
{
private:
  SoccerTeam _val;
  AVLNode *_left;
  AVLNode *_right;
  int _height;
public:
	//construtor for a node, it takes only one parameter, which is a SoccerTeam
	AVLNode(SoccerTeam val):_val(val), _left(nullptr), _right(nullptr), _height(1) {}
	//accessor and modifier for the value of this node, which is a soccer team
	SoccerTeam value() const {return _val;}
 	SoccerTeam& value() {return _val;}
	//accessor and modifier for the node in the left of this one  
	AVLNode* left() const {return _left;}
	AVLNode* &left() {return _left;}
	//accessor and modifier for the node in the right of this one
	AVLNode* right() const {return _right;}
	AVLNode* &right() {return _right;}
	//accessor and modifier fot this node's height
	int height() const {return _height;}
	int &height()  {return _height;}
	//this method return a boolean variable that tells weather this node has childs or not, if it is a leaf
 	bool isLeaf() const {return !_left && !_right;}
	//method used to print a node  
	std::ostream& print(std::ostream &os) const;
 	//method used to insert a new value in the tree, it requires where a pointer to a node, and the value wanted to insert 
 	AVLNode* insert(SoccerTeam newVal, AVLNode *intoSubTree);
 	//method used to remove a value from the tree, it requires a pointer to a node, and the value wanted to be deleted
	AVLNode* remove(SoccerTeam exstingVal, AVLNode *fromSubTree); 
	//overloaded method to print a node.
	friend  std::ostream& operator<<(std::ostream &os, const AVLNode &n); 
};

#endif
