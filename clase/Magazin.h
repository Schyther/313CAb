#ifndef __MAGAZIN__
#define __MAGAZIN__

using namespace std;

#ifndef __IOSTREAM__
#define __IOSTREAM__
#include <iostream>
#endif

#ifndef __STRING__
#define __STRING__
#include <string>
#endif

#include "resizablearray.h"
#include "Depozit_Magazin.h"
#include "Produs.h"

class Bon;

class Magazin {
    int id;
    string locatie;
    ResizableArray<Bon*> bonuri;
    Depozit_Magazin *depozit;
public:
    Magazin()
    {
        this -> depozit = new Depozit_Magazin;
    }
    Magazin(int id, string locatie)
    {
        this -> id = id;
        this -> locatie = locatie;
        this -> depozit = new Depozit_Magazin;
    }
    Magazin(int id, string locatie, ResizableArray<Bon*> bonuri, Depozit_Magazin* depozit)
    {
        this -> id = id;
        this -> locatie = locatie;
        this -> bonuri = bonuri;
        this -> depozit = depozit;
    }
    Magazin(const Magazin& other)
    {
        this -> id = other.id;
        this -> locatie = other.locatie;
        this -> bonuri = other.bonuri;
        this -> depozit = other.depozit;
    }
    ~Magazin()
    {
        delete depozit;
    }

    void setId(int);
    void setLocatie(string);

    int getId();
    string getLocatie();
    int findProdus(string);
    int getNProdus(string);
    ResizableArray<Bon*> getBonuri();
    Depozit_Magazin* getDepozit();

    void add_produs(Produs*, int);
    void remove_produs(string, int);

    void add_bon(Bon*);
};

void Magazin::setId(int id)
{
    this -> id = id;
}

void Magazin::setLocatie(string locatie)
{
    this -> locatie = locatie;
}


int Magazin::getId()
{
    return id;
}

string Magazin::getLocatie()
{
    return locatie;
}

int Magazin::findProdus(string id)
{
    return depozit -> findProdus(id);
}

int Magazin::getNProdus(string id)
{
    return depozit -> getNProdus(id);
}

ResizableArray<Bon*> Magazin::getBonuri()
{
    return bonuri;
}

Depozit_Magazin* Magazin::getDepozit()
{
    return depozit;
}

void Magazin::add_produs(Produs* produs, int cantitate)
{
    int pos = findProdus(produs -> getId());
    if(pos == -1)
    {
        depozit -> addProdus(produs, cantitate);
    }
    else
    {
        depozit -> addProdus(pos, cantitate);
    }
}

void Magazin::remove_produs(string id, int cantitate)
{
    int pos = findProdus(id);
    if(pos)
    {
        if(depozit -> getNProdus(pos) < cantitate)
        {
            cerr << "Nu sunt suficiente produse\n";
        }
        else
        {
            depozit -> addProdus(pos, -cantitate);
        }
    }
    else
    {
        cerr << "Produsul nu exista in depozitul magazinului\n";
    }
}

void Magazin::add_bon(Bon* bon)
{
    bonuri.push_back(bon);
}
#endif
