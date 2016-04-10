#include "Classes.h"

Magazin::Magazin(){

}

Magazin::Magazin(int id, string locatie)
{
	this->id = id;
	this->locatie = locatie;

}

Magazin::Magazin(int id, string locatie, ResizableArray<Bon> bonuri, Depozit_Magazin* depozit)
{
	this->id = id;
	this->locatie = locatie;
	this->bonuri = bonuri;
	this->depozit = *depozit;
}

Magazin::Magazin(const Magazin& other)
{
	this->id = other.id;
	this->locatie = other.locatie;
	this->bonuri = other.bonuri;
	this->depozit = other.depozit;
}

Magazin::~Magazin()
{
}

void Magazin::setId(int id)
{
	this->id = id;
}

void Magazin::setLocatie(string locatie)
{
	this->locatie = locatie;
}


int Magazin::getId()
{
	return id;
}

string Magazin::getLocatie()
{
	return locatie;
}

int Magazin::findProdus(int id)
{
	return depozit.findProdus(id);
}

int Magazin::getNProdus(int id)
{
	return depozit.getNProdus(id);
}

ResizableArray<Bon>& Magazin::getBonuri()
{
	return bonuri;
}

Depozit_Magazin* Magazin::getDepozit()
{
	return &depozit;
}

void Magazin::add_produs(Produs& produs, int cantitate)
{
	depozit.addProdus(produs.getId(), cantitate);
}

void Magazin::remove_produs(int id, int cantitate)
{
	depozit.removeProdus(id, cantitate);
}

void Magazin::add_bon(Bon& bon)
{
	bonuri.push_back(bon);
}