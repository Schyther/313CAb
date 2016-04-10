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
#define NumarSloturi 200

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

	Palet();
	Palet(string idPalet, int nrItemi, int idSlot, int produs);
	Palet(const Palet& x);
	~Palet();

	Palet& operator=(const Palet& x);

	string getIdPalet();
	int getNrItems();
	int getIdSlot();
	int getIdProdus();

	void setIdPalet(string id_nou);
	void setNrItems(int nr_nou);
	void setIdSlot(int id_nou);

};



// CLasa pentru depozit magazin

class Depozit_Magazin {

	int nrProduse[NumarProduse];

public:

	Depozit_Magazin();
	Depozit_Magazin(const Depozit_Magazin& other);
	~Depozit_Magazin();

	int findProdus(int id);
	int getNProdus(int pos);
	void addProdus(int id, int cantitate);
	void removeProdus(int id, int cantitate);


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

	Magazin();
	Magazin(int id, string locatie);
	Magazin(int id, string locatie, ResizableArray<Bon> bonuri, Depozit_Magazin* depozit);
	Magazin(const Magazin& other);
	~Magazin();

	int getId();
	string getLocatie();
	int findProdus(int id);
	int getNProdus(int id);
	ResizableArray<Bon>& getBonuri();
	Depozit_Magazin* getDepozit();

	void setId(int id);
	void setLocatie(string locatie);
	void add_produs(Produs& produs, int cantitate);
	void remove_produs(int id, int cantitate);
	void add_bon(Bon& bon);

};

// Depozitul mare

class DepozitGlobal {

private:

	Stack<Palet> sloturi[NumarSloturi];

public:
	DepozitGlobal();
	DepozitGlobal(const DepozitGlobal& other);
	~DepozitGlobal();

	Stack<Palet>* GetSloturi();

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
	void PaletiRead(const char* fileName, DepozitGlobal& d);
	void MagazineRead(const char* fileName, ResizableArray<Magazin> &magazine);
	void CategoriiRead(const char* fileName, Categorii& cat);
	void TranzactiiRead(const char* fileName, ResizableArray<Magazin> &magazine, HashGen <string, Bon*>& hBonuri);
	time_t Read::ConvertTime(char *timeToConvert);

	~Read();

};