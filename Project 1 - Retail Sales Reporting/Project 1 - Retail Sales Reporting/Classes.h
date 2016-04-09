#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#include "DLL.h"
#include "List.h"
#include "stack.h"
#include "ResizableArray.h"
#include "HashTable.h"

using namespace std;

#define NumarProduse 200

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

//Clasa pentru paleti

class Palet {
private:
	string idPalet;
	int idProdus;
	int nrItemi;
	int idSlot;

public:

	Palet() {

	}

	Palet(string idPalet, int nrItemi, int idSlot, Produs produs) {
		this->idPalet = idPalet;
		this->nrItemi = nrItemi;
		this->idSlot = idSlot;
		this->idProdus = produs.getId();
	}

	Palet(const Palet& x) {
		this->idPalet = x.idPalet;
		this->nrItemi = x.nrItemi;
		this->idSlot = x.nrItemi;
		this->idProdus = x.idProdus;
	}

	~Palet() {
		this->idPalet = '\0';
		this->nrItemi = 0;
		this->idSlot = 0;
		this->idProdus = 0;
	}

	Palet& operator=(const Palet& x) {
		this->idPalet = x.idPalet;
		this->nrItemi = x.nrItemi;
		this->idSlot = x.idSlot;
		this->idProdus = x.idProdus;
		return *this;
	}


	string getIdPalet() {
		return idPalet;
	}


	int getNrItems() {
		return nrItemi;
	}

	int getIdSlot() {
		return idSlot;
	}

	int getIdProdus() {
		return idProdus;
	}

	void setIdPalet(string id_nou) {
		this->idPalet = id_nou;
	}

	void setNrItems(int nr_nou) {
		this->nrItemi = nr_nou;
	}

	void setIdSlot(int id_nou) {
		this->idSlot = id_nou;
	}

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

// Depozitul mare

class DepozitGlobal {

private:

	ResizableArray<Stack<Palet>> paleti;

public:
	DepozitGlobal();
	DepozitGlobal(const DepozitGlobal& other);
	~DepozitGlobal();

	ResizableArray<Stack<Palet>>& GetPaleti();

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