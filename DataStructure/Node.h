#ifndef NODE_H
#define NODE_H
template<typename T>
struct Node
{
	T d;
	struct Node<T> *next;
};

#endif
