/*
	Stack header file
	Henrique Medeiros Dos Reis
	feb 27 20201
*/

#ifndef _MY_STACK_HPP_
#define _MY_STACK_HPP_

#include <list>
//this stack is implemented using a list, but it will only allow the user to see only the first element on it
template <class T>
class MyStack : private std::list<T>
{
public:
  void push(const T &val);//method to add an elemment to the stack
  void pop();//method to remove an element from the stack
  const T& top() const;//method that will return the only element you have access to, the top element

  bool isEmpty() const;//method that will return weather the stack is empty or not
};

#endif
