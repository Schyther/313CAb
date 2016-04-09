#include "Classes.h"

//Constructori/ Destructori

Bon::Bon() {

}

Bon::~Bon() {

	delete[] FcvProdus;

}

//Getteri
string Bon::getId() {
	
	return id;
}

int* Bon::getFcvProduse() {

	return FcvProdus;

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

void Bon::AddProdus(int id) {



}