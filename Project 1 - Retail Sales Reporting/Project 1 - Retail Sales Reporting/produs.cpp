#include "Classes.h"

// Supraincarcare operatori

ostream &operator<<(ostream &out, Produs p) {
	out << "nume produs: " << p.nume << '\n';
	out << "categorie produs: " << p.categorie << '\n';
	out << "pret produs: " << p.pret << '\n';
	return out;
}

Produs& Produs:: operator= (const Produs &p) {
	this->nume = p.nume;
	this->categorie = p.categorie;
	this->pret = p.pret;
	return *this;
}

//Constructori / Destructor

Produs::Produs()
{
	this->nume = "0";
	this->categorie = "0";
	this->pret = 0;
};

Produs::Produs( string nume, string categorie, int pret)
{
	this->nume = nume;
	this->categorie = categorie;
	this->pret = pret;
};

Produs::~Produs() {
}

void Produs::AddData(string nume, string categorie, int pret) 
{
	this->nume = nume;
	this->categorie = categorie;
	this->pret = pret;

}

//Getteri


string Produs::getNume()
{
	return nume;
}

string Produs::getCategorie()
{
	return categorie;
}

int Produs::getPret()
{
	return pret;
}