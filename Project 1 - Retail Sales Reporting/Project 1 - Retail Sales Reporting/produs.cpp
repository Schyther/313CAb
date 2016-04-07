#include "Classes.h"

// Supraincarcare operatori

ostream &operator<<(ostream &out, Produs p) {
	out << "id produs: " << p.id << '\n';
	out << "nume produs: " << p.nume << '\n';
	out << "categorie produs: " << p.categorie << '\n';
	out << "pret produs: " << p.pret << '\n';
	return out;
}

Produs& Produs:: operator= (const Produs &p) {
	this->id = p.id;
	this->nume = p.nume;
	this->categorie = p.categorie;
	this->pret = p.pret;
	return *this;
}

//Constructori / Destructor

Produs::Produs()
{
	this->id = 0;
	this->nume = "0";
	this->categorie = "0";
	this->pret = 0;
};

Produs::Produs(int id, string nume, string categorie, int pret)
{
	this->id = id;
	this->nume = nume;
	this->categorie = categorie;
	this->pret = pret;
};

Produs::~Produs() {
}


//Getteri

int Produs::getId()
{
	return id;
}

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