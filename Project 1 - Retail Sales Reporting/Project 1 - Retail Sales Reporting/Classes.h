#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

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

	T peek();

	void QuickSort(int pinitial, int pfinal);
	int BinarySearch(int pinitial, int pfinal, T cautat);
};

template <typename T>
T ResizableArray<T>::peek() {
	return array[_size - 1];
}

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



// Hash pentru bonuri

template <typename Tkey, typename Tvalue>
struct Pair {
	Tkey first;
	Tvalue second;
};

template <typename Tkey, typename Tvalue>
class HashBon {
private:
	ResizableArray < Pair < Tkey, ResizableArray < Tvalue > > > *H;
	int Hmax;
public:
	HashBon() {

	}

	HashBon(int Hmax) {
		this->Hmax = Hmax;
		H = new ResizableArray < Pair < Tkey, ResizableArray < Tvalue > > >[Hmax];
	}

	~HashBon() {
		delete[] H;
	}


	int logPow(int base, int exponent) {
		int res = 1;
		while (exponent > 0) {
			if (exponent & 1) {
				res = (1LL * res * base) % MOD;
			}

			base = (1LL * base * base) % MOD;
			exponent >>= 1;
		}
		return res;
	}

	int hashFunction(Tkey key) {
		int sum = 0, sz = key.size();
		for (int i = 0; i < sz; ++i) {
			sum = (sum + (logPow(BASE, sz - i - 1) * (int)(key[i])) % MOD) % MOD;
		}
		return sum;
	}


	void insert(Tkey key, Tvalue value) {
		Pair < Tkey, ResizableArray < Tvalue > > data;

		int hashKey = hashFunction(key);
		int ok = 0;

		if (H[hashKey].size() > 0) {
			int sz = H[hashKey].size();
			for (int i = 0; i < sz && !ok; ++i) {
				if (H[hashKey][i].first == key) {
					H[hashKey][i].second.push_back(value);
					return;
				}
			}
		}

		data.first = key;
		data.second.push_back(value);
		H[hashKey].push_back(data);
	}


	int getValue(Tkey key) {
		int hashKey = hashFunction(key);
		int sz = H[hashKey].size();

		for (int i = 0; i < sz; ++i) {
			if (H[hashKey][i].first == key) {
				return H[hashKey][i].second;
			}
		}

		return ResizableArray < Tvalue >();
	}

	ResizableArray < Pair < Tkey, ResizableArray < Tvalue > > >& operator[](int position) {
		if (position >= Hmax) {
			cerr << "Pozitie invalida!\n";
			return H[0];
		}

		return H[position];
	}

};


// Hash generic

template <typename Tkey, typename Tvalue>
class HashGen {
private:
	ResizableArray < Pair < Tkey, Tvalue > > *H;
	int Hmax;
public:
	// Constructor
	HashGen(int Hmax) {
		this->Hmax = Hmax;
		H = new ResizableArray < Pair < Tkey, Tvalue > >[Hmax];
	}

	// Destructor
	~HashGen() {
		delete[] H;
	}


	int logPow(int base, int exponent) {
		int res = 1;
		while (exponent > 0) {
			if (exponent & 1) {
				res = (1LL * res * base) % MOD;
			}

			base = (1LL * base * base) % MOD;
			exponent >>= 1;
		}
		return res;
	}

	int hashFunction(Tkey key) {
		int sum = 0, sz = key.size();
		for (int i = 0; i < sz; ++i) {
			sum = (sum + (logPow(BASE, sz - i - 1) * (int)(key[i])) % MOD) % MOD;
		}
		return sum;
	}

	void insert(Tkey key, Tvalue value) {
		Pair < Tkey, Tvalue > data;
		int hashKey = hashFunction(key);

		data.first = key;
		data.second = value;
		H[hashKey].push_back(data);
	}

	Tvalue getValue(Tkey key) {
		int hashKey = hashFunction(key);
		int sz = H[hashKey].size();

		for (int i = 0; i < sz; ++i) {
			if (H[hashKey][i].first == key) {
				return H[hashKey][i].second;
			}
		}

		return Tvalue();
	}

	ResizableArray<Tvalue> operator[](int position) {
		if (position >= Hmax) {
			cerr << "Pozitie invalida!\n";
			return H[0];
		}

		return H[position];
	}
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

		for (int i = 0; i < NumarProduse; i++) {
			nrProduse[i] = 0;
		}
	}


	Depozit_Magazin(const Depozit_Magazin& other)
	{
		int i;
		for (i = 0; i < NumarProduse; i++)
			nrProduse[i] = other.nrProduse[i];
	}

	~Depozit_Magazin() {

	}


	int findProdus(int id)
	{
		if (nrProduse[id] > 0) return 1;
		else return -1;
	}

	int getNProdus(int pos)
	{
		return nrProduse[pos];
	}


	void addProdus(int id, int cantitate)
	{
		nrProduse[id] += cantitate;
	}

	void removeProdus(int id, int cantitate) {

		nrProduse[id] -= cantitate;

	}


};


//Clasa pentru bonuri

class Bon {

private:

	string id;
	int fcvProdus[NumarProduse];    // Vector cu frecventa fiecarui prrodus 
	int nrProduse;
	long long utcTime;
	string idMagazin;


public:

	//Constructori/Destructori
	Bon();
	Bon(string id, long long utcTime, int idMagazin);
	~Bon();
	Bon(const Bon& other);

	//Getteri
	string getId();
	int* getFcvProduse();
	int getNrProduse();
	long long GetTime();
	string getIdMagazin();

	//Metode
	void AddData(string id, long long utcTime, string idMagazin);
	void AddProdus(int id);

};


//Clasa pentru magazin
class Magazin {
	int id;
	string locatie;
	ResizableArray<Bon> bonuri;
	Depozit_Magazin depozit;
public:
	Magazin()
	{
	}
	Magazin(int id, string locatie)
	{
		this->id = id;
		this->locatie = locatie;

	}
	Magazin(int id, string locatie, ResizableArray<Bon> bonuri, Depozit_Magazin* depozit)
	{
		this->id = id;
		this->locatie = locatie;
		this->bonuri = bonuri;
		this->depozit = *depozit;
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
	}

	void setId(int id)
	{
		this->id = id;
	}

	void setLocatie(string locatie)
	{
		this->locatie = locatie;
	}


	int getId()
	{
		return id;
	}

	string getLocatie()
	{
		return locatie;
	}

	int findProdus(int id)
	{
		return depozit.findProdus(id);
	}

	int getNProdus(int id)
	{
		return depozit.getNProdus(id);
	}

	ResizableArray<Bon>& getBonuri()
	{
		return bonuri;
	}

	Depozit_Magazin* getDepozit()
	{
		return &depozit;
	}

	void add_produs(Produs& produs, int cantitate)
	{
		depozit.addProdus(produs.getId(), cantitate);
	}

	void remove_produs(int id, int cantitate)
	{
		depozit.removeProdus(id, cantitate);
	}

	void add_bon(Bon& bon)
	{
		bonuri.push_back(bon);
	}

};




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

	void BonuriRead(const char* name, HashGen <string, Bon*>& hBonuri);
	void ProduseRead(const char* fileName, Produs *produse, Categorii& cat);
	void PaletiRead(const char* fileName);
	void MagazineRead(const char* fileName, ResizableArray<Magazin> &magazine);
	void CategoriiRead(const char* fileName, Categorii& cat);
	void TranzactiiRead(const char* fileName, ResizableArray<Magazin> &magazine, HashGen <string, Bon*>& hBonuri);
	time_t Read::ConvertTime(char *timeToConvert);

	~Read();

};