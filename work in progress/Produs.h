#ifndef __PRODUS__
#define __PRODUS__

#ifndef __IOSTREAM__
#define __IOSTREAM__
#include <iostream>
#endif

#ifndef __STRING__
#define __STRING__
#include <string>
#endif

class Produs {

	int id;
	string nume;
	string categorie;
	int pret;

public:

	Produs(){};
	Produs(int id, string nume, string categorie, int pret)
	{
        this->id = id;
        this->nume = nume;
        this->categorie = categorie;
        this->pret = pret;
    }
	~Produs(){};
	Produs(const Produs& other)
    {
        this -> id = id;
        this -> nume = other.nume;
        this -> categorie = other.nume;
        this -> pret = other.pret;
    }

    void AddData(int id, string nume, string categorie, int pret);

	int getId();
	string getNume();
	string getCategorie();
	int getPret();

	Produs &operator= (const Produs &p);

	friend ostream &operator<<(ostream &, const Produs&);
};

// Supraincarcare operatori

ostream &operator<<(ostream &out, const Produs& p) {
	out << "id produs: " << p.id << '\n';
	out << "nume produs: " << p.nume << '\n';
	out << "categorie produs: " << p.categorie << '\n';
	out << "pret produs: " << p.pret << "\n\n";
	return out;
}

Produs& Produs:: operator= (const Produs &p) {
	this->id = p.id;
	this->nume = p.nume;
	this->categorie = p.categorie;
	this->pret = p.pret;
	return *this;
}

//Setter

void Produs::AddData(int id, string nume, string categorie, int pret)
{
	this->id = id;
	this->nume = nume;
	this->categorie = categorie;
	this->pret = pret;
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
#endif
