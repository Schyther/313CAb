#ifndef __STACK__
#define __STACK__

#ifndef __IOSTREAM__
#define __IOSTREAM__
#include <iostream>
#endif

#include "DLL.h"

template <class T>
class Stack {
private:
	//folosim liste dublu inlantuite ca sa retinem stiva
	DLL < T > stiva; 
public:
	Stack();
	~Stack();
	Stack(const Stack &other);

	Stack<T> &operator=(const Stack<T> &other);

	bool empty() const;
	T top() const;
	int size() const;

	void push(T value);
	void pop();

	template<class Y>
	friend ostream& operator<<(ostream& out, const Stack<Y> &Stack);
};

//CONSTRUCTOR
template <class T>
Stack<T>::Stack() {
}

//DESTRUCTOR
template <class T>
Stack<T>::~Stack() {
}

/*
Folosesc liste dublu inlantuite pentru a face
copy-constructorul si copy-assignmentul sa fie
mai eficiente.
Daca lista folosita ar fi simplu inlantuita,
copia facuta ar fi stiva intoarsa
*/

//COPY-CONSTRUCTOR
template <class T>
Stack<T>::Stack(const Stack<T> &other) {
	//si in copy-constructor si in destructor copiez stiva de la sfarsit la inceput, ca sa nu fie invers
	DLL <T> lista;
	lista = other.stiva;
	Node <T> *current = lista.last();
	while (current) {
		push(current->value);
		current = current->prev;
	}
}

//COPY-ASSIGNMENT
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T> &other) {
	DLL <T> lista;
	lista = other.stiva;
	Node <T> *current = lista.last();
	while (current) {
		push(current->value);
		current = current->prev;
	}
	return *this;
}

template <class T>
bool Stack<T>::empty() const {
	return stiva.empty();
}

template <class T>
T Stack<T>::top() const {
	if (!empty()) {
		return stiva.front();
	}
	else {
		cerr << "Error: Could not return top element. Empty stack\n";
		return T();
	}
}

template <class T>
int Stack<T>::size() const {
	return stiva.length();
}

template <class T>
void Stack<T>::push(T value) {
	stiva.push_front(value);
}

template <class T>
void Stack<T>::pop() {
	if (!empty()) {
		stiva.pop();
	}
	else {
		cerr << "Error: Could not pop. Empty stack\n";
	}
}

template<class T>
ostream& operator<<(ostream& out, const Stack<T>& stack) {
	DLL < T > lista;
	lista = stack.stiva;
	out << lista;
	return out;
}

#endif