#ifndef __MAGAZIN__
#define __MAGAZIN__
#ifndef __IOSTREAM__
#define __IOSTREAM__
#include <iostream>
#endif

#ifndef __STRING__
#define __STRING__
#include <string>
#endif

#include "ResizableArray.h"
#include "Depozit_Magazin.h"

using namespace std;

class Magazin {
    int id;
    string locatie;
    ResizableArray<Bon*> bonuri;
    Depozit_Magazin *depozit;
public:
    Magazin()
    {
        this -> depozit = new Depozit_Magazin;
    };
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
    ~Magazin()
    {
        delete depozit;
    }
    int getId();
    string getLocatie();
    int findProdus(string);
    int getNProdus(string);
    ResizableArray<Bon*> getBonuri();
    Depozit_Magazin* getDepozit();

    void add_produs(Produs*, int);
    void remove_produs(string, int);

    void add_bon(Bon*);
    void remove_bon(string);
};

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
    int pos = depozit -> findProdus(id);
    if(pos == -1)
    {
        return -1;
    }
    return depozit -> nr_produse[pos];
}

ResizableArray<Bon*> Magazin::getBonuri()
{
    return bonuri;
}

Depozit_Magazin* Magazin::getdepozit()
{
    return depozit;
}

void Magazin::add_produs(Produs* produs, int cantitate)
{
    pos = findProdus(produs -> id);
    if(pos == -1)
    {
        depozit -> produse.push_back(produs);
        depozit -> nr_produse.push_back(cantitate);
    }
    else
    {
        depozit -> nr_produse[pos] += cantitate;
    }
}

void Magazin::remove_produs(string id)
{
    pos = findProdus(id);
    if(pos)
    {
        if(depozit -> nr_produse[pos] < cantitate)
        {
            cout << "Nu sunt suficiente produse\n";
        }
        else
        {
            depozit -> nr_produse[pos] -= cantitate;
        }
    }
    else
    {
        cout << "Produsul nu exista in depozitul magazinului\n";
    }
}

void Magazin::add_tranzactie(Tranzactie* tranzactie)
{
    tranzactii.push_back(tranzactie);
}

void Magazin::erase_tranzactie(int pos)
{
    tranzactii.erase(pos);
}

template class<T>
void Magazin::remove_tranzactie(string id)
{
    List<tranzactie*> aux = tranzactii;
    if(aux.front() -> id == id)
    {
        tranzactii.pop();
        return;
    }
    while(!aux.empty())
    {
        aux.pop
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
#endif