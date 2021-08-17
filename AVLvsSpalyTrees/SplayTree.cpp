#include "SplayTree.hpp"
/*
	AVL tree header file
	Henrique Medeiros Dos Reis
	April 04 2021
*/
using namespace std;

//declaration of variable used later
int depth1=0;

//method used to help the printing
void helper(ostream &os, const SplayNode* node)
{
	if(!node) return;//if im in a null node, then im done

  	depth1++;//increment the depth
  	helper(os, node->right());//solve this recursively from the right
  	depth1--;//decrement the depth

  	for (int i=0; i< depth1; i++)//print some nice spacing so it looks like a tree
    	os << "    ";

 	os << *node << endl;//print the contents of this node

 	depth1++;//increment the depth
  	helper(os, node->left());//solve this recursively from the left
  	depth1--;//decrement the depth
}
//method used to print the whole tree
ostream&
SplayTree::display(ostream &os) const
{
  	depth1=0;//reset the depth
  	helper(os, _root);//call the helper
  	return os;
}
//simple method to find a node in the tree, it also helps to keep the count of the number of node accesses before getting to the result, this is needed in order to compare to the AVL tree result. this does not impact the rotations, so it shoudl always be used before rotating to be accurate. And then call the lookup in order to get the rotations done.
SplayNode*
SplayTree::findS(SplayNode* ptr, int& SplayAccess) const
{
	SplayNode *curr = _root;//start at the root
	while(curr!=nullptr)//keep going until the reach a null
	{
		SplayAccess++;//increment the number of nodes accessed
		if(curr->value()==ptr->value())//is this what im looking for?
			return curr;//return the current node then
		else if(ptr->value() <curr->value())//am i smaller than what im looking for?
			curr = curr->left();//go to the left
		else//if i get here, im bigger
			curr = curr->right();//go to the right
	}
	return nullptr;//if i get here, this is not in the tree
}

