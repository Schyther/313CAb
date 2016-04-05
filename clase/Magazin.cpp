#ifndef __IOSTREAM__
#define __IOSTREAM__
#include <iostream>
#endif

#ifndef __STRING__
#define __STRING__
#include <string>
#endif

#include "list.h"

using namespace std;

class Magazin;
class Depozit_Magazin;

class Produs;
class Categorie;
class Tranzactie;
class Bon;

class Depozit;
class Slot;
class Palet;

class Magazin {
    string id;
    string locatie;
    List<Tranzactie*> tranzactii;
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
    Magazin(int id, string locatie, List<Tranzactie*> tranzactii)
    {
        this -> id = id;
        this -> locatie = locatie;
        this -> tranzactii = tranzactii;
        this -> depozit = new Depozit_Magazin;
    }
    ~Magazin()
    {
        delete depozit;
    }
    string getid();
    string getlocatie();
    List<Produs*> getproduse();
    int nr_produse(string);
    List<Tranzactie*> gettranzactii();
    Depozit_Magazin* getdepozit();

    void add_produs(Produs*, int);
    void erase_produs(int, int);
    void remove_produs(string, int);

    void add_tranzactie(Tranzactie*);
    void erase_tranzactie(int);
    void remove_tranzactie(string);
};

string Magazin::getid()
{
    return id;
}

string Magazin::getlocatie()
{
    return locatie;
}

List<Produs*> Magazin::getproduse()
{
    return depozit -> produse;
}

int Magazin::nr_produse(string id)
{
    return depozit -> nr_produse[depozit -> produse.getpos(id)];
}

List<Tranzactie*> Magazin::gettranzactii()
{
    return tranzactii;
}

Depozit_Magazin* Magazin::getdepozit()
{
    return depozit;
}

/*void Magazin::add_produs(Produs* produs, int cantitate)
{
    pos = depozit -> tip_produs.search(produs)
    if(pos == -1)
    {
        depozit -> tip_produs.push_back(produs);
        depozit -> nr_produse.push(cantitate);
    }
    else
    {
        depozit -> nr_produse[pos] += cantitate;
    }
}

void Magazin::erase_produs(int pos)
{
    depozit -> produse.erase(pos);
}

void Magazin::remove_produs(string id)
{
    depozit -> remove(id);
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
}*/

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
