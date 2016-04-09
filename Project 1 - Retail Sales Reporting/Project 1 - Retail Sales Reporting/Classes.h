#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#pragma once

#define MOD 100003
#define BASE 1867
#define NumarProduse 200


//Clasa pentru Resizable Array

template <typename T>
class ResizableArray {
private:
	T *array;
	unsigned int _capacity;
	unsigned int _size;
public:
	// Constructor default
	ResizableArray() {
		_size = 0;
		_capacity = 1;
		array = new T[_capacity];
	}

	// Constructor
	ResizableArray(const unsigned int capacity) {
		_capacity = capacity;
		_size = 0;
		array = new T[capacity];
	}

	// Copy-constructor
	ResizableArray(const ResizableArray &other) {
		if (other.size() > 0) {
			_capacity = other.capacity();
			_size = other.size();
			array = new T[_capacity];

			for (unsigned int i = 0; i < other.size(); ++i) {
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

			for (int i = 0; i < (int)other.size(); ++i) {
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

	// Metoda care redimensioneaza array-ul la dimensiunea "newDim"
	void resize(int newSize);

	// Metoda care adauga un element nou
	void push_back(const T something);

	// Metoda pentru stergerea ultimului element adaugat
	void pop_back();

	// Metoda pentru "Subscripting operator" 
	T &operator[](int position);

	// Metoda pentru a elimina elementul aflat la pozitia "position"
	void erase(const int position);

	// Metoda care returneaza primul indice pe care se afla un element cu
	// valoarea "value" si returneaza -1 daca elementul cautat nu se afla in
	// array
	int find(T value);

	void QuickSort(int pinitial, int pfinal);
	int BinarySearch(int pinitial, int pfinal, T cautat);
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
void ResizableArray<T>::resize(int newSize) {
	T *tmp = new T[newSize];

	int limit = (newSize < (int)_size) ? newSize : _size;
	for (int i = 0; i < limit; ++i) {
		tmp[i] = array[i];
	}

	delete[] array;

	array = tmp;
	_capacity = newSize;
}

template <typename T>
void ResizableArray<T>::push_back(const T something) {
	// Verifica daca vectorul e plin
	if (_size == _capacity) {
		resize(_capacity << 1);
	}

	array[_size++] = something;
}

template <typename T>
void ResizableArray<T>::pop_back() {
	if (_size == 0) {
		cerr << "Array-ul este deja gol!\n";
		return;
	}

	_size--;
	if (_size == _capacity >> 1) {
		resize(_capacity >> 1);
	}
}

template <typename T>
T& ResizableArray<T>::operator[](int position) {
	if (position > (int)_size) {
		cerr << "Pozitie invalida!\n";
		return array[0];
	}

	return array[position];
}

template < typename T>
void ResizableArray<T>::erase(const int position) {
	if (position >= _size || _size == 0) {
		cerr << "Pozitie invalida!\n";
		return;
	}

	for (int i = position; i < _size; ++i) {
		array[i] = array[i + 1];
		_size--;
	}

	// Daca am mai putin de jumatate de array nefolosit, ii injumatatesc capacitatea

	if (_size == _capacity >> 1) {
		resize(_capacity >> 1);
	}
}

template <typename T>
int ResizableArray<T>::find(T value) {
	for (unsigned int i = 0; i < _size; ++i) {
		if (array[i] == value) {
			return i;
		}
	}
	return -1;
}


template<class T>
void ResizableArray<T>::QuickSort(int pinitial, int pfinal)
{
	int m = (pinitial + pfinal) >> 1;
	int i = pinitial;
	int j = pfinal;
	T pivot = array[m];

	while (i <= j)
	{
		while (array[i]<pivot)
			i++;
		while (pivot<array[j])
			j--;

		if (i <= j)
		{
			T temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	if (pinitial<j)
	{
		quicksort(array, pinitial, j);
	}
	if (i<pfinal)
	{
		quicksort(array, i, pfinal);
	}
}

template<class T>
int ResizableArray<T>::BinarySearch(int pinitial, int pfinal, T cautat)
{
	int medie;
	medie = (pinitial + pfinal) >> 1; // >> 1 = impartire la 2
	if (array[medie] == cautat) return medie;
	if (array[medie] < cautat)
	{
		return binarysearch(array, medie + 1, pfinal, cautat);
	}
	else
	{
		return binarysearch(array, pinitial, medie - 1, cautat);
	}

}



// Hash

template <typename Tkey, typename Tvalue>
struct Pair {
	Tkey first;
	Tvalue second;
};

template <typename Tkey, typename Tvalue>
class Hash {
private:
	ResizableArray < Pair < Tkey, ResizableArray < Tvalue > > > *H;
	int Hmax;
public:
	// Constructor default
	Hash() {
	}

	// Constructor
	Hash(int Hmax);

	// Destructor
	~Hash();

	// Ridicare la putere in timp logaritmic. Returneaza (base^exponent) % MOD
	int logPow(int base, int exponent);
	int hashFunction(Tkey key);
	void insert(Tkey key, Tvalue value);

	// Metoda care returneaza continutul pentru cheia "key"
	ResizableArray < Tvalue > getValue(Tkey key);

	// Metoda pentru a supaincarca "Subscripting operator" 
	ResizableArray < Pair < Tkey, ResizableArray < Tvalue > > > &operator[](int position);
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



//Clasa pentru categorii

struct Categorie
{
	int id;
	string name;
};

class Categorii {

private:
	
	ResizableArray<Categorie> vector;

public:

	Categorii();
	Categorii(Categorii& c);
	~Categorii();

	void Add(int id, string name);

	string Get(int id);


};


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

	void Produs::AddData(int id,string nume, string categorie, int pret);
};


// CLasa pentru depozit magazin

class Depozit_Magazin {

	int nrProduse[NumarProduse];

public:

	Depozit_Magazin() {

	}


	Depozit_Magazin(const Depozit_Magazin& other)
	{
		int i;
		for (i = 0; i < NumarProduse; i++)
			nrProduse[i] = other.nrProduse[i];
	}

	~Depozit_Magazin() {

	}

	int findProdus(int);
	int getNProdus(int);

	void addProdus(int, int);
	void removeProdus(int, int);
};

int Depozit_Magazin::findProdus(int id)
{
	if (nrProduse[id] > 0) return 1;
	else return -1;
}

int Depozit_Magazin::getNProdus(int pos)
{
	return nrProduse[pos];
}


void Depozit_Magazin::addProdus(int id, int cantitate)
{
	nrProduse[id] += cantitate;
}

void Depozit_Magazin::removeProdus(int id, int cantitate) {

	nrProduse[id]-= cantitate;

}




//Clasa pentru bonuri

class Bon {

private:

	string id;
	ResizableArray <Produs> *produse;
	int *FcvProdus;    // Vector cu frecventa fiecarui prrodus 
	int nrProduse;
	long long utcTime;
	string idMagazin;


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

	//Metode
	void AddProdus(int id);

};


//Clasa pentru magazin
class Magazin {
	int id;
	string locatie;
	ResizableArray<Bon> bonuri;
	Depozit_Magazin *depozit;
public:
	Magazin()
	{
		this->depozit = new Depozit_Magazin;
	}
	Magazin(int id, string locatie)
	{
		this->id = id;
		this->locatie = locatie;
		this->depozit = new Depozit_Magazin;
	}
	Magazin(int id, string locatie, ResizableArray<Bon> bonuri, Depozit_Magazin* depozit)
	{
		this->id = id;
		this->locatie = locatie;
		this->bonuri = bonuri;
		this->depozit = depozit;
	}
	Magazin(const Magazin& other)
	{
		this->id = other.id;
		this->locatie = other.locatie;
		this->bonuri = other.bonuri;
		this->depozit = other.depozit;
	}
	~Magazin()
	{
		delete depozit;
	}

	void setId(int);
	void setLocatie(string);

	int getId();
	string getLocatie();
	int findProdus(int);
	int getNProdus(int);
	ResizableArray<Bon> getBonuri();
	Depozit_Magazin* getDepozit();

	void add_produs(Produs&, int);
	void remove_produs(int, int);

	void add_bon(Bon&);
};

void Magazin::setId(int id)
{
	this->id = id;
}

void Magazin::setLocatie(string locatie)
{
	this->locatie = locatie;
}


int Magazin::getId()
{
	return id;
}

string Magazin::getLocatie()
{
	return locatie;
}

int Magazin::findProdus(int id)
{
	return depozit->findProdus(id);
}

int Magazin::getNProdus(int id)
{
	return depozit->getNProdus(id);
}

ResizableArray<Bon> Magazin::getBonuri()
{
	return bonuri;
}

Depozit_Magazin* Magazin::getDepozit()
{
	return depozit;
}

void Magazin::add_produs(Produs& produs, int cantitate)
{
	depozit->addProdus(produs.getId(), cantitate);
}

void Magazin::remove_produs(int id, int cantitate)
{
	depozit->removeProdus(id, cantitate);
}

void Magazin::add_bon(Bon& bon)
{
	bonuri.push_back(bon);
}


// Clasa de citire

class Read {

private:

	ifstream bonurif;
	ifstream categoriif;
	ifstream magazinef;
	ifstream paletif;
	ifstream produsef;
	ifstream tranzactiif;

public:

	void BonuriRead(const char* name);
	void ProduseRead(const char* fileName, Produs *produse, Categorii& cat);
	void PaletiRead(const char* fileName);
	void MagazineRead(const char* fileName);
	void CategoriiRead(const char* fileName, Categorii& cat);
	void TranzactiiRead(const char* fileName);

	~Read();

};