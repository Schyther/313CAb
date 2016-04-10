#include "Classes.h"

Depozit_Magazin::Depozit_Magazin() {

	for (int i = 0; i < NumarProduse; i++) {
		nrProduse[i] = 0;
	}
}


Depozit_Magazin::Depozit_Magazin(const Depozit_Magazin& other)
{
	int i;
	for (i = 0; i < NumarProduse; i++)
		nrProduse[i] = other.nrProduse[i];
}

Depozit_Magazin::~Depozit_Magazin() {

}


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

	nrProduse[id] -= cantitate;

}
