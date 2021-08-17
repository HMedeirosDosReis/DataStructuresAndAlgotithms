#include "AVLTree.hpp"
/*
	implementation of avl tree
	Henrique Medeiros Dos Reis
	April 04 2021
*/
#include <iostream>

using namespace std;
//method used to insert a node to this tree
void
AVLTree::insert(SoccerTeam newVal)
{
  if (!_root)//in case i do not have the root yet
    _root = new AVLNode(newVal);//then this new value is the root
  _root = _root->insert(newVal, _root);//if i have, then call the method in the node, and let it take care of the insertion
}
//method used to remove a node from this tree
void
AVLTree::remove(SoccerTeam toDel)
{
	if (!_root)//if i dont have a root, then i have nothing to remove
   		return;
  	else//if i do have a root, then call the remove in the node
    	_root = _root->remove(toDel, _root);
}

int depth;
///method used to help the printing 
void helper(ostream &os, AVLNode *node)
{
  if (!node) return;//if this node is null, we are done here

  depth++;//increment the depth
  helper(os, node->right());//solve this recursively
  depth--;//decrement the depth

  for (int i=0; i<depth; i++)//loop through the depth in order to print some spaces and make it look like a tree
    os << "    ";
  
  node->print(os);//print this node
  os << endl;

  depth++;
  helper(os, node->left());//solve this recursively to the left now
  depth--;
  
}
//method used to print the whole tree
ostream& 
AVLTree::display(ostream &os) const
{
  depth=0;
  helper(os, _root);//simply calls the helper in the root
  return os; 
}
//simple method to find a node in the tree, it also helps to keep the count of the number of node accesses before getting to the result, this is needed in order to compare to the splay tree result  
AVLNode*
AVLTree::find(AVLNode* ptr, int& avlAccess) const
{
	AVLNode *curr = _root;//start at the root
	while(curr!=nullptr)//keep going until the reach a null 
	{
		avlAccess++;//increment the number of nodes accessed
		if(curr->value()==ptr->value())//is this what im looking for?
			return curr;//return the current node then
		else if(ptr->value() <curr->value())//am i smaller than what im looking for?
			curr = curr->left();//go to the left
		else//if i get here, im bigger
			curr = curr->right();//go to the right
	}
	return nullptr;//if i get here, this is not in the tree
}



