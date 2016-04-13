#include "Classes.h"

Depozit_Magazin::Depozit_Magazin() {
	
	for (int i = 0; i < NumarProduse; i++)
		fcvProd[i] = 0;

}

void Depozit_Magazin::addStoc(Produs *prod) {
	
	for (int i = 0; i < NumarProduse; i++) {
		if (prod[i].getId() != 0) 
			addProdusCant(i, NrProdIntial);
		
	}
}


Depozit_Magazin::Depozit_Magazin(const Depozit_Magazin& other)
{
	for (int i = 0; i < NumarProduse; i++)
		this->fcvProd[i] = other.fcvProd[i];
}

Depozit_Magazin::~Depozit_Magazin() {

}



int Depozit_Magazin::getNProdus(int id)
{
	return fcvProd[id];
}


void Depozit_Magazin::addProdusCant(int idProd, int cantitate) {
	
	fcvProd[idProd] += cantitate;
}

Depozit_Magazin& Depozit_Magazin::operator= (const Depozit_Magazin& other)
{
	for (int i = 0; i < NumarProduse; i++)
		fcvProd[i] = other.fcvProd[i];
	return *this;
}