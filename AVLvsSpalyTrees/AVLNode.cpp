#include "AVLNode.hpp"
/*
	implementation of avl Node
	Henrique Medeiros Dos Reis
	April 04 2021
*/
#include <iostream>

using namespace std;
//declarationg of methods that willbbe used later
AVLNode* rotateWithLeftChild(AVLNode *k2);
AVLNode* rotateWithRightChild(AVLNode *k2);

//this method returns the height of this node
int getHeight(AVLNode *n)
{
  if (!n)//in case this node is not null
    {
      return 0;
    }
  else//if it is null, return the height 
    {
      return n->height();
    }
}
//method used to print a node  
std::ostream&
AVLNode::print(std::ostream &os) const
{
  os << _val//print the value
     << " (" << getHeight(_left) << "<->" << getHeight(_right) << ")";//print the heights of both children
     //helps to debug the tree
  return os;
}

//this method rotates the tree when it is umbalanced, and we rotate with the left child 
AVLNode* rotateWithLeftChild(AVLNode *k2)
{
 	AVLNode *k1 = k2->left();//my k1 node is the left child
 	k2->left() = k1->right();//now my left is my left child's right
	k1->right() =  k2;//my left child's right is not me
	//now updates the height of mboth nodes 
	k2->height() = 1 + max (getHeight(k2->left()), getHeight(k2->right()) );
 	k1->height() = 1 + max (getHeight(k1->left()), getHeight(k2) );
	//return the k1 node
 	return k1;
}
//this method will take care if we need two rotations in order to balance this tree, with the left child
AVLNode* doubleWithLeftChild(AVLNode *k3)
{
  AVLNode *k1 = k3->left();//my k1 node is my left child 
  k3->left() = rotateWithRightChild(k1);//my left child now rotates with its right child
  return rotateWithLeftChild(k3);//and then i can rotate with my left child for the second rotations
}
//this method rotates the tree when it is unbalanced, and we rotate with the right child
//the same thing as the left child, but now with the right
AVLNode* rotateWithRightChild(AVLNode *k2)
{
  AVLNode *k1 = k2->right();
  k2->right() = k1->left(); 
  k1->left() =  k2;

  k2->height() = 1 + max (getHeight(k2->left()), getHeight(k2->right()) );
  k1->height() = 1 + max (getHeight(k1->right()), getHeight(k2) );

  return k1;
}
//this method will take care if we need two rotations in order to balance this tree, with the right child
//the same thing as the double left, but now with the right
AVLNode* doubleWithRightChild(AVLNode *k3)
{
  AVLNode *k1 = k3->right();
  k3->right() = rotateWithLeftChild(k1);
  return rotateWithRightChild(k3);
}


//method used to insert
AVLNode*
AVLNode::insert(SoccerTeam newVal, AVLNode *intoSubTree)
{	//if im null, then we dont have a root yet, go ahead and make this the root
 	if (intoSubTree==nullptr)
	{
	    AVLNode *newRoot = new AVLNode(newVal);
     	return newRoot;
    }
	//if the value i want to insert is less than my subtree value
	else if (newVal < intoSubTree->_val)
   	{	//then, try to take care of this recursively starting in the left child of this subtree
    	intoSubTree->_left=insert(newVal, intoSubTree->_left);

    	// update _height for AVL manipulations
		int leftHeight = getHeight(intoSubTree->_left);

    	int rightHeight = getHeight(intoSubTree->_right);

    	// might need AVL rotations
    	if (leftHeight-rightHeight==2) // imbalance in left
		{
			// is this a left-left imbalance?
			if (newVal < intoSubTree->_left->_val )
	    		intoSubTree=rotateWithLeftChild(intoSubTree);
			// or is it a left-rght imabalance?
			else
	    		intoSubTree=doubleWithLeftChild(intoSubTree);
		}
    }
    //if the value i want to insert is bigger than my subtree value
    else if (newVal > intoSubTree->_val)
    {	//then, try to take care of this recursively starting in the left child of this subtree
        intoSubTree->_right=insert(newVal, intoSubTree->_right);

        // update _height for AVL manipulations
        int leftHeight = getHeight(intoSubTree->_left);

        int rightHeight = getHeight(intoSubTree->_right);

        // might need AVL rotations
        if (rightHeight-leftHeight==2) // imbalance in right
	    {
	    	// is this a right-right imbalance?
	  		if (newVal >  intoSubTree->_right->_val )
	      		intoSubTree=rotateWithRightChild(intoSubTree);
	  		// or is it a right-left imabalance?
	  		else
	      		intoSubTree=doubleWithRightChild(intoSubTree);
		}
    }
	// node value already in tree (==)
	
	//update the height 
  	intoSubTree->height() = 1 + max(getHeight(intoSubTree->left()),
				  getHeight(intoSubTree->right()) ); 

  	return intoSubTree;
}
//method used to remove from the tree 
AVLNode*
AVLNode::remove(SoccerTeam existingVal, AVLNode *fromSubTree)
{
	if (!fromSubTree)//in case this is a null tree, return null
	    return nullptr;
	//in case the value that i want to remove is smaller than the subtree value, then take care of this with recursion
	if (existingVal < fromSubTree->_val)
    	fromSubTree->left() = remove(existingVal, fromSubTree->left() );
    //in case the value that i want to remove is bigger than the subtree value, then take care of this with recursion
  	else if (existingVal > fromSubTree->_val)
      	fromSubTree->right() = remove(existingVal, fromSubTree->right() );
  	else // this is the node I want to remove!
    {
      	if (fromSubTree->isLeaf())  // 0 children
		{
		  	fromSubTree=nullptr;//just make me null
		}
      	else if (fromSubTree->left() && fromSubTree->right() ) // 2 children
		{
		  	AVLNode *toDel = fromSubTree->left();//the one i want to delete is now my left 
		  	while(toDel->right()!=nullptr)//if my to del, is not null
		    {
		      	toDel = toDel->right();//then go to the right
		    }

	  		SoccerTeam valueToMove = toDel->value();// sabe a value to move, wich is the same as the to dell vallue
			//the left of my subtree, remove this value from the left subtree with recursion
	  		fromSubTree->left()=remove(valueToMove, fromSubTree->left());
	  		fromSubTree->value() = valueToMove;//my new value is the value that i wanted to move
	  		
		}
      	else // 1 child
		{
	  		if (fromSubTree->left() )//in case my left isnt null
	    	fromSubTree = fromSubTree->left();
	  		else // only have right child
	    	fromSubTree = fromSubTree->right();
		}
      
    }
	//check once more if we are null already
  	if (!fromSubTree)
    	return nullptr;
  
    // rebalance now if needed
  	int balance = getHeight(fromSubTree->left()) -
                getHeight(fromSubTree->right()) ;

    // is the left subtree of height more than 2 bigger than right subtree
    if (balance==2)
    {
      	int subBalance = getHeight(fromSubTree->left()->left()) -
	               getHeight(fromSubTree->left()->right());

        // left-left issue
        if (subBalance >= 0)
	  		fromSubTree = rotateWithLeftChild(fromSubTree);
     	else // left-right issue
	  		fromSubTree = doubleWithLeftChild(fromSubTree);
    }
  
    // is the right subtree of height more than 2 bigger than left subtree
  	if (balance==-2)
    {
    	int subBalance = getHeight(fromSubTree->right()->left()) -
	               getHeight(fromSubTree->right()->right());

        // right-right issue
        if (subBalance < 0)
	  		fromSubTree = rotateWithRightChild(fromSubTree);
      	else // left-right issue
	  		fromSubTree = doubleWithRightChild(fromSubTree);
    }
	//updrate the height 
  	fromSubTree->_height = 1 + max( getHeight(fromSubTree->left()) ,
				  getHeight(fromSubTree->right()) );
    
  	return fromSubTree;
}

//overloaded operator that simply calls the print method
ostream& operator<<(ostream &os, const AVLNode &n)
{
	return n.print(os);
}
