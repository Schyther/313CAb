#include <iostream>

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
class List {
private:
	Node<T> *begin, *end;
public:
	List() {
		begin = NULL;
		end = NULL;
	}
	~List()	{
		end = begin;
		while(end != NULL) {
			begin = end;
			end = end->next;
			delete begin;
		}
	}
	List(List &other) {
		Node<T> *newNode, *current;
		if(other.begin = NULL) {
			begin = NULL;
			end = NULL;
		}
		else {
			current = other.begin;
			while (current != NULL) {
				this->push_back(current->value);
				current = current->next;
			}
		}
	}

	bool empty();

	T front();
	T back();

	void push_back(T value);
	void push_front(T value);
	void insert(int pos, T value);
	void erase(int pos);

	void printList();
	template<class Y>
	friend ostream& operator<<(ostream& out, const List<Y> &list);

};

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