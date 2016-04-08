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

//#include "list.h"

using namespace std;

class Produs {
    string id;
    string nume;
    string categorie;
    int pret;
public:
    Produs();

    Produs(string id, string nume, string categorie, int pret)
    {
        this -> id = id;
        this -> nume = nume;
        this -> categorie = categorie;
        this -> pret = pret;
    }
    
    Produs(const Produs& other)
    {
        this -> id = other.id;
        this -> nume = other.nume;
        this -> categorie = other.nume;
        this -> pret = other.pret;
    }

    ~Produs();

    void setId(string);
    void setNume(string);
    void setCategorie(string);
    void setPret(int);

    string getId();
    string getNume();
    string getCategorie();
    int getPret();

    Produs &operator= (const Produs &p){
        this -> id = p.id;
        this -> nume = p.nume; 
        this -> categorie = p.categorie; 
        this -> pret = p.pret;     
    }

    friend ostream &operator<<(ostream &, Produs);
};

ostream &operator<<(ostream &out, Produs p) {
    out << "id produs: " << p.id << '\n';
    out << "nume produs: " << p.nume << '\n';
    out << "categorie produs: " << p.categorie << '\n';
    out << "pret produs: " << p.pret << '\n';
}

void Produs::setId(string id)
{
	this -> id = id;
}

void Produs::setNume(string nume)
{
	this -> nume = nume;
}

void Produs::setCategorie(string categorie)
{
	this -> categorie = categorie;
}

void Produs::setPret(int pret)
{
	this -> pret = pret;
}

string Produs::getId()
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
