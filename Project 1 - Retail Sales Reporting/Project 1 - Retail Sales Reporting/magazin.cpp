#include "Classes.h"

Magazin::Magazin() {

	
}

Magazin::Magazin(string locatie, Produs *prod) {
	this->locatie = locatie;
	depozit.addStoc(prod);
	int n = depozit.getNProduse();
	for (int i = 0; i < depozit.getNProduse(); i++)
		StocInitial[i] = NrProdIntial;

}


Magazin::Magazin(const Magazin& other) {
	this->locatie = other.locatie;
	for (int i = 1; i < 367; ++i)
		this->zi[i] = other.zi[i];
	this->depozit = other.depozit;
}

Magazin::~Magazin() {

}

void Magazin::setLocatie(string locatie) {
	this->locatie = locatie;
}

string Magazin::getLocatie() {
	return locatie;
}

int Magazin::findProdus(int id) {
	return depozit.findProdus(id);
}

int Magazin::getNProdus(int id) {
	return depozit.getNProdus(id);
}

Depozit_Magazin& Magazin::GetDepozit() {

	return depozit;
}

void Magazin::addProdusCant(int idProd, int cantitate) {

	int pos = depozit.findProdus(idProd);
	depozit.addProdusCant(pos, cantitate);

}

void Magazin::add_produs(Produs& produs, int cantitate) {
	int pos = depozit.findProdus(produs.getId());
	if (pos == -1) {
		depozit.addProdus(&produs, cantitate);
	}
	else {
		depozit.addProdusCant(pos, cantitate);
	}
}



int Magazin::removeProdus(int id, int cantitate, DepozitGlobal &d) {
	
	int cant;
	depozit.addProdusCant(id, -cantitate);
	int nr = getNProdus(id);
	if (nr <= StocInitial[id] / 10) {
		cant = d.GetPalet(id);
		if (cant == -1) return -1;
		depozit.addProdusCant(id, cant);
		nr = getNProdus(id);
	}

	return 1;
}

void Magazin::add_bon(string id_bon, int zi) {
	this->zi[zi].push_back(id_bon);
}