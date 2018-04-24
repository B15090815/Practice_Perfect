#include<iostream>
#include<time.h>
#include"Node.h"


using namespace std;
/*
template<typename T>
struct Node
{
	T d;
	struct Node<T> *next;
};*/

template<typename T>
class Queue
{
	private:
		struct Node<T> *head;
		struct Node<T> *tail;
		
	public:
	  Queue();
	  ~Queue();
		bool IsEmpty();
		T front();
		void Enqueue(T d); 
		
};

template<typename T>
Queue<T>::Queue()
{
	struct Node<T> *node = new Node<T>;
	this->head = node;
	this->tail = node;
}

template<typename T>
bool Queue<T>::IsEmpty()
{
	return this->head == this->tail;
}

template<typename T>
T Queue<T>::front()
{
	if(this->IsEmpty()){
		throw "Empty queue!";	
	} 
	struct Node<T> *current = this->head;
	T data = current->next->d;
	this->head = current->next;
	delete current;
	return data;
}

template<typename T>
void Queue<T>::Enqueue(T d)
{
	struct Node<T> *node = new Node<T>;
	node->d = d;
	this->tail->next = node;
	this->tail = node;
}

template<typename T>
Queue<T>::~Queue()
{
	struct Node<T> *current;
	while(!this->IsEmpty()){
		current = this->head;
		this->head = current->next;
		delete current;
	}
	delete this->head;
}

int main(void)
{
	Queue<int> q;
	int n = 10000;
	time_t start,stop;
	start = clock();
	for(int i=0;i<n;i++){
		q.Enqueue(i);
	}
	stop = clock();
	cout<<(double)(stop-start)/CLOCKS_PER_SEC<<endl;
	
/*
	try{
		
		q.front();
	}catch(const char* msg){
		cout<<msg<<endl;
	}*/
//	cout<<endl;
}



