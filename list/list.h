#ifndef LIST_H
#define LIST_H
//#include <iostream>

//using namespace std;

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
	List();
	~List();
	List(List &other);

	List<T> operator=(const List<T> &other);

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
