// DOUBLY LINKED LIST = DLL

template <class T>
class DLL {
private:
	Node<T> *begin, *end;
public:
	DLL();
	~DLL();
	DLL(const DLL &other);

	DLL<T> &operator=(const DLL<T> &other);

	bool empty() const;

	T front() const;
	T back() const;

	Node<T> *first() const;
	Node<T> *last() const;	

	int getpos(T value) const;

	void push_back(T value);
	void push_front(T value);
	void insert(int pos, T value);

	void pop();
	void erase(int pos);
	void remove(T value);
	void remove_next(Node<T> *node);

	int length() const;

	void clear();

	template<class Y>
	friend ostream& operator<<(ostream& out, const DLL<Y> &DLL);
};

//CONSTRUCTOR

template <class T>
DLL<T>::DLL() {
	begin = end = NULL;
}

//DESTRUCTOR

template<class T>
DLL<T>::~DLL() {
	clear();
}

//COPY-CONSTRUCTOR

template <class T>
DLL<T>::DLL(const DLL<T> &other) {
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
DLL<T>& DLL<T>::operator=(const DLL<T> &other) {
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
bool DLL<T>::empty() const{
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
T DLL<T>::front() const {
	if (begin) return begin->value;
	else return T();
}

template <class T>
T DLL<T>::back() const {
	if (end) return end->value;
	else return T();
}

//GETTER PENTRU BEGIN

template <class T>
Node<T> * DLL<T>::first() const{
	return begin;
}

//GETTER PENTRU END

template <class T>
Node<T> * DLL<T>::last() const{
	return end;
}

template <class T>
int DLL<T>::getpos(T value) const{
	if(empty()) return -1;
	Node<T> *current = begin;
	int pos = 0;
	while (current) {
		if (value == current -> value) {
			return pos;
		}
		pos++;
		current = current -> next;
	}
	return -1;
}

template <class T>
void DLL<T>::push_back(T value) {
	Node<T> *newNode = new Node<T>;
	newNode->value = value;
	newNode->next = NULL;
	newNode->prev = end;
	if (!begin) {
		begin = end = newNode;
	}
	else {
		end->next = newNode;
		end = newNode;
	}
}
template <class T>
void DLL<T>::push_front(T value) {
	Node<T> *newNode = new Node<T>;
	newNode->value = value;
	newNode->next = begin;
	newNode->prev = NULL;
	if (!end) {
		begin = end = newNode;
	} 
	else {
		newNode->next = begin;
		begin = newNode;
	}
}

template <class T>
void DLL<T>::insert(int pos, T value) {
	Node<T> *newNode, *current;
	current = begin;
	int poscrt;
	newNode = new Node<T>(value);
	while (current) {
		if (pos == poscrt) {
			//noul nod se insereaza dupa curentul
			newNode->next = current->next;
			newNode->prev = current;
			if (current->next) current->next->prev = newNode;
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
void DLL <T>::erase(int pos) {
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

			current->next->prev = current;
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
void DLL<T>::remove(T value) {
	if(empty()) return;
	Node<T> *current = begin, *elemToRemove;
	if(value == begin -> value) {
	    elemToRemove = begin;
	    begin = begin -> next;
	    delete elemToRemove;
	}
	while (current -> next) {
		if (value == current -> next -> value) { //delete elem
			elemToRemove = current -> next;

			current->next->prev = current;
			current->next = current->next->next;

			if (elemToRemove == end) {
				end = current;
			}
			delete elemToRemove;
			break;
		}
		current = current->next;
	}
}

template <class T>
void DLL<T>::remove_next(Node<T> *node) {
    if(!node -> next) return;
    Node<T> *elemToRemove = node->next;
    if(elemToRemove == end) end = node;
    if (elemToRemove->next) { // elementul urmator dupa cel care trebuie sters
    	elemToRemove->next->prev = node;
    }
    node->next = elemToRemove->next;
    delete elemToRemove;
}

template <class T>
void DLL<T>::pop() {
    if(empty()) {
    	cerr << "error : Could not pop first value of doubly linked list. Empty list\n";
    	return;
    }
    Node<T> *elemToRemove = begin;
    begin = begin->next;
    //nu mai are niciun element in stanga
    if (begin) begin->prev = NULL;
    delete elemToRemove;
}

template <class T>
int DLL<T>::length() const {
    Node<T> *current = begin;
    int nr_elem = 0;
    while(current) {
        nr_elem++;
        current = current->next;
    }
    return nr_elem;
}

template <class T>
void DLL<T>::clear() {
	end = begin;
	while(end != NULL) {
		begin = end;
		end = end->next;
		delete begin;
	}
}

template<class T>
ostream& operator<<(ostream& out, const DLL<T>& DLL) {
	Node<T> *current = DLL.begin;
	while (current) {
		out << current->value << " ";
		current = current->next;
	}
	out << "\n";
	return out;
}
