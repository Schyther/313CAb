#include "Classes.h"

//Constructori/ Destructori

Bon::Bon() {

	nrProduse = 0;
	for (int i = 0; i < NumarProduse; i++)
		fcvProdus[i] = 0;

}

Bon::Bon(string id, long long utcTime, int idMagazin) {

	nrProduse = 0;
	for (int i = 0; i < NumarProduse; i++)
		fcvProdus[i] = 0;
	this->id = id;
	this->utcTime = utcTime;
	this->idMagazin = idMagazin;

}

Bon::~Bon() {

}

Bon::Bon(const Bon& other) {

	this->id = other.id;
	this->nrProduse = other.nrProduse;
	for (int i = 0; i < NumarProduse; i++)
		this->fcvProdus[i] = other.fcvProdus[i];
	this->utcTime = other.utcTime;
	this->idMagazin = other.idMagazin;

}

//Getteri
string Bon::getId() {
	
	return id;
}

int* Bon::getFcvProduse() {

	return fcvProdus;

}

int Bon::getNrProduse() {

	return nrProduse;

}

long long Bon::GetTime() {

	return utcTime;

}
string Bon::getIdMagazin() {

	return idMagazin;

}



//Metode

void Bon::AddData(string id, long long utcTime, string idMagazin) {

	this->id = id;
	this->utcTime = utcTime;
	this->idMagazin = idMagazin;

}

void Bon::AddProdus(int id) {

	nrProduse++;
	fcvProdus[id] ++;

}