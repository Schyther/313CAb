#ifndef __STACK__
#define __STACK__
#endif

#ifndef __IOSTREAM__
#define __IOSTREAM__
#include <iostream>
#endif

using namespace std;

template<class T>
struct Node{
	T value;
	Node<T> *next;
	Node(T value) {
		this->value = value;
		next = NULL;
	}
	Node() {
		next = NULL;
	}
};

template <class T>
class Stack {
private:
	Node<T> *last;
public:
	Stack();
	~Stack();
	Stack(Stack &other);

	Stack<T> operator=(const Stack<T> &other);

	bool empty();
	T top();
	int size();

	void push(T value);
	void pop();
};


//CONSTRUCTOR
template <class T>
Stack<T>::Stack() {
	last = NULL;
}

//DESTRUCTOR
template<class T>
Stack<T>::~Stack() {
	Node <T> node;
	while(last != NULL) {
		node = last;
		last = last->next;
		delete node;
	}
}

//COPY-CONSTRUCTOR
template <class T>
Stack<T>::Stack(Stack<T> &other) {
	Node<T> *current, *begin,*end;
	last = NULL;

	begin = end = NULL;

	current = other.begin;
	while (current != NULL) {
		this->push(current->value);
		current = current->next;
	}

	Node<T> *newNode = new Node<T>;

	current = this->last;
	while(current != NULL) {
		newNode->value = this.top();
		newNode->next = NULL;
		this.pop();

		if (!begin) {
			begin = end = newNode;
		}
		else {
			end->next = newNode;
			end = newNode;
		}
	}

	current = begin;
	while(current != NULL) {
		this.push(current->value);
		current = current->next;
	}
}

//COPY-ASSIGNMENT
template <class T>
Stack<T> Stack<T>::operator=(const Stack<T> &other) {
	Node<T> *current, *begin,*end;
	last = NULL;

	begin = end = NULL;

	current = other.begin;
	while (current != NULL) {
		this->push(current->value);
		current = current->next;
	}

	Node<T> *newNode = new Node<T>;

	current = this->last;
	while(current != NULL) {
		newNode->value = this.top();
		newNode->next = NULL;
		this.pop();

		if (!begin) {
			begin = end = newNode;
		}
		else {
			end->next = newNode;
			end = newNode;
		}
	}

	current = begin;
	while(current != NULL) {
		this.push(current->value);
		current = current->next;
	}

	return *this;
}

template <class T>
bool Stack<T>::empty() {
	if (last == NULL)
		return true;
	return false;
}

template <class T>
T Stack<T>::top() {
	if (last)
		return last->value;
	else return T(); //ASK TEO
}

template <class T>
void Stack<T>::push(T value) {
	Node<T> *newNode = new Node<T>;
	newNode->value = value;
	newNode->next = NULL;
	if (!last) {
		last = newNode;
	} 
	else {
		newNode->next = last;
		last = newNode;
	}
}

template <class T>
void Stack<T>::pop() {
    if(empty())
    	return;
    Node<T> *elemToRemove = last;
    last = last->next;
    delete elemToRemove;
}

template <class T>
int Stack<T>::size() {
    Node<T> *current = last;
    int nr_elem = 0;
    while(current)
    {
        nr_elem++;
        current = current->next;
    }
    return nr_elem;
}
