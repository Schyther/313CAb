#include "list.h"
#include <iostream>

using namespace std;

//CONSTRUCTOR

template <class T>
List<T>::List() {
	begin = end = NULL;
}

//DESTRUCTOR

template<class T>
List<T>::~List() {
	end = begin;
	while(end != NULL) {
		begin = end;
		end = end->next;
		delete begin;
	}
}

//COPY-CONSTRUCTOR

template <class T>
List<T>::List(List<T> &other) {
	Node<T> *newNode, *current;
	begin = NULL;
	end = NULL;
	current = other.begin;
	while (current != NULL) {
		this->push_back(current->value);
		current = current->next;
	}
}

//COPY-ASSIGNMENT

template <class T>
List<T> List<T>::operator=(const List<T> &other) {
	Node<T> *newNode, *current;
	begin = NULL;
	end = NULL;
	current = other.begin;
	while (current != NULL) {
		this->push_back(current->value);
		current = current->next;
	}
	return *this;
}

//functions

template <class T>
bool List<T>::empty() {
	if (begin == NULL) return 1;
	else return 0;
}

template <class T>
T List<T>::front() {
	return begin->value;
}

template <class T>
T List<T>::back() {
	return end->value;
}

template <class T>
void List<T>::push_back(T value) {
	Node<T> *newNode = new Node<T>;
	newNode->value = value;
	newNode->next = NULL;
	if (!begin) {
		begin = end = newNode;
	}
	else {
		end->next = newNode;
		end = newNode;
	}
}
template <class T>
void List<T>::push_front(T value) {
	Node<T> *newNode = new Node<T>;
	newNode->value = value;
	newNode->next = NULL;
	if (!end) {
		begin = end = newNode;
	} 
	else {
		newNode->next = begin;
		begin = newNode;
	}
}

template <class T>
void List<T>::insert(int pos, T value) {
	Node<T> *newNode, *current;
	current = begin;
	int poscrt;
	newNode = new Node<T>(value);
	while (current) {
		if (pos == poscrt) {
			newNode->next = current->next;
			current->next = newNode;
			break;
		}
		current = current->next;
		poscrt++;
	}
	if (newNode->next == NULL) {
		end = newNode;
	}
}

template <class T>
void List<T>::printList() {
	Node<T> *current = begin;
	while (current) {
		cout << current->value << " ";
		current = current->next;
	}
	cout << "\n";
}

template <class T>
void List <T>::erase(int pos) {
	Node<T> *current = begin, *elemToRemove;
	int poscrt = 0;
	if (!current) return;
	if (pos == 0) {
		if (begin) {
			elemToRemove = begin;
			begin = begin->next;
			delete elemToRemove;
		}
		return;
	}
	while (current->next) {
		if (poscrt == pos - 1) { //delete elem
			elemToRemove = current->next;
			current->next = current->next->next;
			if (elemToRemove == end) {
				end = current;
			}
			delete elemToRemove;
			break;
		}
		current = current->next;
		poscrt++;
	}
}

template<class T>
ostream& operator<<(ostream& out, const List<T>& list) {
	Node<T> *current = list.begin;
	while (current) {
		out << current->value << " ";
		current = current->next;
	}
	out << "\n";
	return out;
}