#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <climits>

#include "utils.h"
#include "DLL.h"
#include "List.h"
#include "stack.h"
#include "ResizableArray.h"
#include "HashTable.h"

using namespace std;

#define NumarProduse 500
#define NumarSloturi 200
#define NrProdIntial 0
#define TimpPerProdus 10

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
	int GetId(string categ);
	int GetSize();

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

public:

	Palet();
	Palet(string idPalet, int nrItemi, int produs);
	Palet(const Palet& x);
	~Palet();

	Palet& operator=(const Palet& x);

	string getIdPalet();
	int getNrItems();
	int getIdProdus();

	void setIdPalet(string id_nou);
	void setNrItems(int nr_nou);

};



// CLasa pentru depozit magazin

class Depozit_Magazin {
	int fcvProd[NumarProduse];

public:

	Depozit_Magazin();
	Depozit_Magazin(const Depozit_Magazin& other);
	~Depozit_Magazin();

	int getNProdus(int);

	void addProdusCant(int idProd, int cantitate);
	void addStoc(Produs*prod);

	Depozit_Magazin& operator= (const Depozit_Magazin& other);

};



class DepozitGlobal {

private:

	Stack<Palet> sloturi[NumarSloturi];

public:
	DepozitGlobal();
	DepozitGlobal(const DepozitGlobal& other);
	~DepozitGlobal();

	Stack<Palet>* GetSloturi();

	int FindSlot(int id_produs);
	bool Comanda(int id_produs);
	int GetPalet(int id_produs);

};


//Clasa pentru magazin

class Magazin {
	string locatie;
	Depozit_Magazin depozit;
	int StocInitial[NumarProduse];
public:
	
	ResizableArray < string > zi[367]; // zi[ i ] contine bonurile vandute in ziua i
	Magazin();
	Magazin(string locatie, Produs *prod);
	Magazin(const Magazin& other);
	~Magazin();

	string getLocatie();
	int getNProdus(int id);

	Depozit_Magazin& GetDepozit();

	void setLocatie(string locatie);
	void addProdusCant(int idProd, int cantitate);
	int removeProdus(int id, int cantitate, DepozitGlobal &d);
	void add_bon(string id_bon, int zi);
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

	void BonuriRead(const char* name, Hash <string, int>& hBonuri);
	void ProduseRead(const char* fileName, Produs *produse, Categorii& cat);
	void PaletiRead(const char* fileName, DepozitGlobal& d);
	void MagazineRead(const char* fileName, ResizableArray<Magazin> &magazine, Produs *prod);
	void CategoriiRead(const char* fileName, Categorii& cat);
	void TranzactiiRead(const char *fileName, ResizableArray<Magazin>& magazine,
		ResizableArray < Bon < int, string, time_t > > &bonuri);
	time_t Read::ConvertTime(char *timeToConvert);

	~Read();

};

//Clasa Solve
class Solve 
{

private:

public:
	Solve();
	~Solve();

	void Task1a(ResizableArray < Magazin > &magazine, Produs *produse, Hash < string, int > &H);
	void Task1b(Hash < string, int > &H, Produs *produse,
    ResizableArray < Bon < int, string, time_t > > &bonuri);
	void Task1c(Hash < string, int > &H, Produs *produse,
    ResizableArray < Bon < int, string, time_t > > &bonuri);
	void Task1d(ResizableArray<Magazin> &magazine, Hash < string,
		int > &hBonuri, Categorii &cat, Produs *produse);
	void Solve::Task1e(Hash < string, int > &H, Produs *produse,
		ResizableArray < Bon < int, string, time_t > > &bonuri);
	void Task2a(ResizableArray<Magazin> &magazine, Hash < string, int > &hBonuri);
	void Task2b(ResizableArray<Magazin> &magazine, Hash < string, int > &hBonuri);
	void Task2c(string idBon, Hash < string, int > &H, Produs *produse);
	void Task2d(ResizableArray < Bon < int, string, time_t > > &bonuri, Hash < string, int > &H);
	void Task3a(int idProdus, DepozitGlobal& depozit);
	void Task3b(int idProdus, DepozitGlobal& depozit);
	void Task3c(ResizableArray < Bon < int, string, time_t > > &bonuri, 
		ResizableArray< Magazin > magazine, DepozitGlobal depozit, Hash < string, int > &hBonuri);
	
	
	void ZileToData(int trecute, int &luna, int &zi);
	void Maxime(int *v, int sz, int &max1, int &max2, int &max3);
};

// Clasa de output

class Output {

private:

public:

	void ShowMenu();
	void ShowTask1Menu();
	void ShowTask2Menu();
	void ShowTask3Menu();

  void copyFile(ifstream& input, ofstream& output);

	void Chart(const char* h, const char* f, const char* in, const char* ch);

	void chartZile(const char* h, const char* f, const char* in, const char* ch, int nr_mag);


};

