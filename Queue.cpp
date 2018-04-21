#include<iostream>
using namespace std;
template<typename T>
struct Node
{
	T d;
	Node *next;
};

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
		cout<<"delete..  ";
	}
	delete this->head;
	cout<<"final delete..\n";
}

int main(void)
{
	Queue<int> q;

/*
	for(int i=0;i<10;i++){
		q.Enqueue(i);
	}*/
	try{
		
		q.front();
	}catch(const char* msg){
		cout<<msg<<endl;
	}
	cout<<endl;
}



