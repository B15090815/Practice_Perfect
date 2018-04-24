#include<iostream>
#include"Node.h"

using namespace std;

template<typename T>
class Stack
{
	private:
		struct Node<T> *head;
		struct Node<T> *tail;
		
	public:
		Stack();
		~Stack();
		bool IsEmpty();
		T pop();
		void push();
};

template<typename T>
Stack<T>::Stack()
{
	this->head = new Node<T>;
	this->tail = this->head; 
}

template<typename T>
bool Stack<T>::IsEmpty()
{
	return this->head == this->tail;
}

template<typename T>
T Stack<T>::pop()
{
	
}

template<typename T>
void Stack<T>::push()
{
	struct Node<T> *node = new Node<T>;
	this->head = NULL;
}


