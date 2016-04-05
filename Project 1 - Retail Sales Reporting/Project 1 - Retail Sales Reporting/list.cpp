#include "Classes.h"


//CONSTRUCTOR

template <class T>
List<T>::List() {
	begin = end = NULL;
}

//DESTRUCTOR

template<class T>
List<T>::~List() {
	end = begin;
	while (end != NULL) {
		begin = end;
		end = end->next;
		delete begin;
	}
}

//COPY-CONSTRUCTOR

template <class T>
List<T>::List(List<T> &other) {
	Node<T> *current;
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
	Node<T> *current;
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
	if (begin == NULL) return true;
	else return false;
}

/*
presupun ca tipul de date T primit are un constructor default
daca T ar fi pointer, ar trebui returnat NULL
dar echivalentul lui NULL nu exista pentru tipuri de date
primitive, cum ar fi int
*/
template <class T>
T List<T>::front() {
	if (begin) return begin->value;
	else return T();
}

template <class T>
T List<T>::back() {
	if (end) return end->value;
	else return T();
}

template <class T>
int List<T>::getpos(T value) {
	if (empty()) return -1;
	Node<T> *current = begin;
	int pos = 0;
	while (current) {
		if (value == current->value) {
			return pos;
		}
		pos++;
		current = current->next;
	}
	return -1;
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

template <class T>
void List<T>::remove(T value) {
	if (empty()) return;
	Node<T> *current = begin, *elemToRemove;
	if (value == begin->value)
	{
		elemToRemove = begin;
		begin = begin->next;
		delete elemToRemove;
	}
	while (current->next) {
		if (value == current->next->value) { //delete elem
			elemToRemove = current->next;
			current->next = current->next->next;
			if (elemToRemove == end) {
				end = current;
			}
			delete elemToRemove;
			return;
		}
		current = current->next;
	}
}

template <class T>
void List<T>::remove_next(Node<T> *node)
{
	if (!node->next) return;
	Node<T> *elemToRemove = node->next;
	if (elemToRemove == end) end = node;
	node->next = node->next->next;
	delete elemToRemove;
}

template <class T>
void List<T>::pop() {
	if (empty()) return;
	Node<T> *elemToRemove = begin;
	begin = begin->next;
	delete elemToRemove;
}

template <class T>
int List<T>::length() {
	Node<T> *current = begin;
	int nr_elem = 0;
	while (current)
	{
		nr_elem++;
		current = current->next;
	}
	return nr_elem;
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