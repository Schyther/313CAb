#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Clasa de citire

class Read {

private:

	ifstream bonuri;
	ifstream categorii;
	ifstream magazine;
	ifstream paleti;
	ifstream produse;

public:

	void Bonuri(const char* name);
	void Produse(const char* fileName);
	void Paleti(const char* fileName);
	void Magazine(const char* fileName);
	void Categorii(const char* fileName);

	~Read();

};

//Clasa list

template<class T>
struct Node {
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

	int getpos(T value);

	void push_back(T value);
	void push_front(T value);
	void insert(int pos, T value);

	void pop();
	void erase(int pos);
	void remove(T value);
	void remove_next(Node<T> *);

	int length();

	template<class Y>
	friend ostream& operator<<(ostream& out, const List<Y> &list);
};


//Clasa pentru Resizable Array

template <typename T>
class ResizableArray {
private:
	T *array;
	unsigned int _capacity;
	unsigned int _size;
public:
	// Metoda de initializare
	void init(const int capacity) {
		_capacity = capacity;
		_size = 0;
		array = new T[capacity];
	}

	// Constructor 
	ResizableArray() {
		_size = 0;
		_capacity = 1;
		array = new T[_capacity];
	}

	// Copy-constructor
	ResizableArray(const ResizableArray &other) {
		if (other.size() > 0) {
			_capacity = other.capacity();
			_size = other.size();
			array = new T[_capacity];

			for (int i = 0; i < other.size(); ++i) {
				array[i] = other.array[i];
			}
		}
	}

	// Copy assignement operator
	ResizableArray &operator=(const ResizableArray &other) {
		if (this != &other) {
			_size = other.size();
			_capacity = other.capacity();
			T *tmp = new T[other.capacity()];

			for (int i = 0; i < other.size(); ++i) {
				tmp[i] = other.array[i];
			}

			delete[] array;
			array = tmp;
		}

		return *this;
	}

	// Destructor
	~ResizableArray() {
		delete[] array;
	}

	// Getter pentru size
	unsigned int size() const;

	// Getter pentru capacity
	unsigned int capacity() const;

	// Metoda care adauga un element nou
	void push_back(const T something);

	// Metoda pentru "Subscripting operator" 
	T &operator[](int position);

	// Metoda pentru a elimina elementul aflat la pozitia "position"
	void erase(const int position);
};

template <typename T>
unsigned int ResizableArray<T>::size() const {
	return _size;
}

template <typename T>
unsigned int ResizableArray<T>::capacity() const {
	return _capacity;
}

template <typename T>
void ResizableArray<T>::push_back(const T something) {
	// Verifica daca vectorul e plin
	if (_size == _capacity) {
		// Aloc un vector nou de demensiune 2 * capacity
		T *tmp = new T[_capacity << 1];

		// Copiez elementele in vectorul nou
		for (int i = 0; i < _size; ++i) {
			tmp[i] = array[i];
		}

		delete[] array;

		// Adaug elementul nou la finalul vectorului
		array = tmp;

		// Dublez capacitatea vectorului
		_capacity <<= 1;
	}

	array[_size++] = something;
}

template <typename T>
T& ResizableArray<T>::operator[](int position) {
	if (position > _size) {
		fprintf(stderr, "Pozitie invalida!\n");
		return array[0];
	}

	return array[position];
}

template < typename T>
void ResizableArray<T>::erase(const int position) {
	if (position >= _size || _size == 0) {
		return;
	}

	// Daca voi avea mai putin de jumatate de vector nefolosit, ii
	// injumatatesc capacitatea
	if (_size - 1 == _capacity >> 1) {
		T *tmp = new T[_capacity >> 1];

		for (int i = 0; i < position; ++i) {
			tmp[i] = array[i];
		}
		for (int i = position; i < _size; ++i) {
			tmp[i] = array[i + 1];
		}

		delete[] array;

		_size--;
		array = tmp;
		_capacity >>= 1;
	}
	else {
		for (int i = position; i < _size; ++i) {
			array[i] = array[i + 1];
			_size--;
		}
	}

	return;
}


//Clasa pentru produse

class Produs {

private:
	int id;
	string nume;
	string categorie;
	int pret;

public:

	Produs();
	Produs(int id, string nume, string categorie, int pret);
	~Produs();

	int getId();
	string getNume();
	string getCategorie();
	int getPret();

	Produs &operator= (const Produs &p);

	friend ostream &operator<<(ostream &, Produs);
};

//Clasa pentru magazin
class Magazin {


};

//Clasa pentru bonuri

class Bon {

private:

	string id;
	ResizableArray <Produs> *produse;
	int *FcvProdus;    // Vector cu frecventa fiecarui prrodus 
	int nrProduse;
	long long utcTime;
	string idMagazin;
	Magazin *magazin;


public:

	//Constructori/Destructori
	Bon();
	~Bon();

	//Getteri
	string getId();
	int* getFcvProduse();
	int getNrProduse();
	long long GetTime();
	string getIdMagazin();
	Magazin* getMagazin();

	//Metode
	void AddProdus(int id);
	
};

