#include "Classes.h"

Magazin::Magazin() {

}

Magazin::Magazin(string locatie) {
	this->locatie = locatie;
	for (int i = 0; i < NumarProduse; i++)
		addProdus(i, NrProdIntial);

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


void Magazin::addProdus(int idProd, int cantitate) {

	depozit.addProdus(idProd, cantitate);
}

void Magazin::add_produs(Produs& produs, int cantitate) {
	int pos = depozit.findProdus(produs.getId());
	if (pos == -1) {
		depozit.addProdus(&produs, cantitate);
	}
	else {
		depozit.addProdus(pos, cantitate);
	}
}

void Magazin::remove_produs(int id, int cantitate) {
	depozit.addProdus(id, -cantitate);

}

void Magazin::add_bon(string id_bon, int zi) {
	this->zi[zi].push_back(id_bon);
}