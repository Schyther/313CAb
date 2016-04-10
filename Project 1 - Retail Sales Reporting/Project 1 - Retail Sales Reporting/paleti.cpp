#include "Classes.h"

Palet::Palet() {

}

Palet::Palet(string idPalet, int nrItemi, int idSlot, int produs) {
	this->idPalet = idPalet;
	this->nrItemi = nrItemi;
	this->idSlot = idSlot;
	this->idProdus = produs;
}

Palet::Palet(const Palet& x) {
	this->idPalet = x.idPalet;
	this->nrItemi = x.nrItemi;
	this->idSlot = x.nrItemi;
	this->idProdus = x.idProdus;
}

Palet::~Palet() {
	this->idPalet = '\0';
	this->nrItemi = 0;
	this->idSlot = 0;
	this->idProdus = 0;
}

Palet& Palet::operator=(const Palet& x) {
	this->idPalet = x.idPalet;
	this->nrItemi = x.nrItemi;
	this->idSlot = x.idSlot;
	this->idProdus = x.idProdus;
	return *this;
}


string Palet::getIdPalet() {
	return idPalet;
}


int Palet::getNrItems() {
	return nrItemi;
}

int Palet::getIdSlot() {
	return idSlot;
}

int Palet::getIdProdus() {
	return idProdus;
}

void Palet::setIdPalet(string id_nou) {
	this->idPalet = id_nou;
}

void Palet::setNrItems(int nr_nou) {
	this->nrItemi = nr_nou;
}

void Palet::setIdSlot(int id_nou) {
	this->idSlot = id_nou;
}