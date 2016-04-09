using namespace std;

#ifndef __IOSTREAM__
#define __IOSTREAM__
#include <iostream>
#endif

#ifndef __STRING__
#define __STRING__
#include <string>
#endif

#include "Produs.h"

class Palet {
private:
	string idPalet;
	//Produs *produs;
	int idProdus;
	int nrItemi;
	int idSlot;

public:
	
	Palet() {

	}

	Palet(string idPalet, int nrItemi, int idSlot,Produs produs) {
		this->idPalet = idPalet;
		this->nrItemi = nrItemi;
		this->idSlot = idSlot;
		this->idProdus = produs.idProdus;
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
		this->idProdus= 0;
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


