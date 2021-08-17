#include "SplayNode.hpp"
/*
	implementation of avl Node
	Henrique Medeiros Dos Reis
	April 04 2021
*/
#include <iostream>

using namespace std;
//declaration of the helper method that will be used later
extern void helper(ostream &os, const SplayNode* node);

//this method rotates the tree when it is umbalanced, and we rotate with the left child 
SplayNode* rotateWithLeftChild(SplayNode *k2)
{
	SplayNode *k1 = k2->left();//my k1 pointer represents the left child of k2
 	k2->left() = k1->right(); //now the left of k1, is the right child of k1
  	k1->right() = k2;//finally, the k1 right is the same as k2
  	return k1;
}
//this method rotates the tree when it is umbalanced, and we rotate with the right child 
SplayNode* rotateWithRightChild(SplayNode *k2)
{
  	SplayNode *k1 = k2->right();//my k1 pointer is now the right of k2
  	k2->right() = k1->left(); //k2 right is now k1 left
  	k1->left() = k2;//finally, the left of k1 is k2
  	return k1;
}
//this method will take care if we need two rotations in order to balance this tree, with the left child
SplayNode* doubleWithLeftChild(SplayNode *k3)
{
   	SplayNode *k1 = k3->left();//my k1 node is my left child 
   	k3->left() = rotateWithRightChild( k1 );//my left child now rotates with its right child
   	return rotateWithLeftChild( k3 );//and then i can rotate with my left child for the second rotations
}
//this method will take care if we need two rotations in order to balance this tree, with the right child
SplayNode* doubleWithRightChild(SplayNode *k3)
{
   	SplayNode *k1 = k3->right();//my k1 node is my right child 
   	k3->right() = rotateWithLeftChild( k1 );//my right child now rotates with its left child
   	return rotateWithRightChild( k3 );//and then i can rotate with my right child for the second rotations
}	
//method used to insert a new value in the tree, it requires where a pointer to a node, and the value wanted to insert 
SplayNode*
SplayNode::insert(SoccerTeam val, SplayNode *intoSubTree)
{
  	if (intoSubTree==nullptr)//is this null?
    	return new SplayNode(val);//then insert it
  	else if (val < intoSubTree->_val)//is this smaller than my subtree value?
      	intoSubTree->_left=insert(val, intoSubTree->_left);//go and solve recursively from the left
  	else if (val > intoSubTree->_val)//is this bigger than my subtree value?
      	intoSubTree->_right=insert(val, intoSubTree->_right);//go to the right and solve this recursively 
  	else // equal
    	;	

 	return intoSubTree;
}
//this method will find a node and return it, since this is a splay tree, it will do all the needed rotations 
SplayNode*
SplayNode::lookup(SoccerTeam val, SplayNode *subTree)
{
  	if (subTree==nullptr)//do i have this tree?
    	return nullptr;
	//little message that can helo debugging
  	//cout << "looking up " << val << " @ " << subTree->value() << endl;
  
  	if (subTree->value()==val)//is it the value im looking for?
    	return subTree;
  
  	// check left child
  	if (val<subTree->value())
    {
    	if (!subTree->left())//do i have a left child?
			return subTree;
      
      	// LL case
      	if (val < subTree->left()->value())
		{
	 	 	// recursively bring val to root of left-left
	  		subTree->left()->left()=lookup( val, subTree->left()->left() );
	  
	 		// now rotate the current root right
	  		subTree=rotateWithLeftChild(subTree);
	  
	  		//note: second rotation is below (common for LL and LR case)
		}
      	else if  (val > subTree->left()->value())
		{
	  		// recursively bring val to root of left-right
	  		subTree->left()->right()=lookup( val, subTree->left()->right() );
	  
	  		// if exists, do first step of RL (second is below)
	  		if (subTree->left()->right())
	    	subTree->left() = rotateWithRightChild(subTree->left());
		}
      
      	if (!subTree->left())
			return subTree;
      	else
			return rotateWithLeftChild(subTree);
    }
  	// check right child
  	else // val>subTree->value()
    {
      	if (!subTree->right())
		return subTree;
      
      	// RR case
      	if (val > subTree->right()->value())
		{
	  		// recursively bring val to root of right-right
	  		subTree->right()->right()=lookup( val, subTree->right()->right() );
	  
	  		// now rotate the current root left
	  		subTree=rotateWithRightChild(subTree);
	  
	  		//note: second rotation is below (common for LL and LR case)
		}
      	else if  (val < subTree->right()->value())
		{
	  		// recursively bring val to root of right-left
	  		subTree->right()->left()=lookup( val, subTree->right()->left() );
	  
	  		// if exists, do first step of LR (second is below)
	  		if (subTree->right()->left())
	    	subTree->right() = rotateWithLeftChild(subTree->right());
		}
      
      	if (!subTree->right())
			return subTree;
      	else
			return rotateWithRightChild(subTree);
    }
}
//method used to print a node
ostream&
SplayNode::print(ostream &os) const
{
  	os << _val;//<< "(" << getHeight(_left) << "<->" << getHeight(_right) << ')'; may help with debbuging
  	return os;
}
//overloaded method that will allow the usage of << when printing
ostream& operator<<(ostream &os, const SplayNode &n)
{
  	return n.print(os);
}
