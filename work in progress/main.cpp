using namespace std;
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <time.h>

#include "resizablearray.h"
#include "hash.h"

#include "Magazin.h"
#include "Read.h"

Produs produse[200];

void continutBon(string idBon, Hash < string, int > &H) {
    ResizableArray < int > continut = H.getValue(idBon);

    if (continut.size() == 0) {
        cout << "Id de bon invalid!\n";
        return;
    }

    cout <<"Bonul cu id-ul " << idBon << " contine urmatoarele produse:\n";

    int sz = continut.size();
    for (int i = 0; i < sz; ++i) {
        cout << "   " << produse[ continut[i] ].getNume()<< '\n';
    }
}

double cosMediu(Hash < string, int > &H) {
    // presupun ca am am vectorul Produs care in Produs[ i ] are caracteristicile
    // (pret, nume, categorie) produsului cu id-ul i si ca vectorul Produs
    // e declarat global
    int nrBonuri = 0;
    int costTotal = 0;
    int sz1, sz2;
    for (int i = 0; i < MOD; ++i) {
        nrBonuri += H[i].size();
        sz1 = H[i].size();
        for (int j = 0; j < sz1; ++j) {
            sz2 = H[i][j].second.size();
            for (int k = 0; k < sz2; ++k) {
                costTotal += produse[ H[i][j].second[k] ].getPret();
            }
        }
    }

    return (1.0 * costTotal / nrBonuri);
}

int main()
{
    // Ordonam array-ul asta dupa time_t pentru ultimul task
    ResizableArray < Pair < string, time_t > > bonuri;
    ResizableArray<Magazin> magazine; //magazinele vor fi tinute in RA si indexate dupa id - 1
    Categorii cat;
    Hash < string, int > hBonuri(MOD);

    Read R;
    R.MagazineRead("magazine.csv", magazine);
    R.CategoriiRead("categorii.csv", cat);
    R.ProduseRead("produse.csv", produse, cat);
    R.BonuriRead("bonuri.csv", hBonuri);
    R.TranzactiiRead("tranzactii.csv", magazine, bonuri);
    /*for(unsigned i = 0; i < magazine.size(); ++i)
    {
        cout << "locatie magazin cu id-ul " << i + 1 << ": " << magazine[i].getLocatie() << '\n';
    }
    for(int i=0; i< 50; ++i)
    {
        cout << produse[i];
    }*/

    /*int sz1, sz2;
    for (int i = 0; i < MOD; ++i) {
        int sz1 = hBonuri[i].size();
        for (int j = 0; j < sz1; ++j) {
            cout << hBonuri[i][j].first << '\n';
            sz2 = hBonuri[i][j].second.size();
            for (int k = 0; k < sz2; ++k) {
                cout << "   " << produse[ hBonuri[i][j].second[k] ].getNume() << '\n';
            }
        }
    }*/

    // continutBon("569847491688512", hBonuri);
    // cout << fixed << setprecision(7) << cosMediu(hBonuri) << '\n';

    /*for (int i = 0; i < magazine.size(); ++i) {
        for (int j = 1; j < 367; ++j) {
            for (int k = 0; k < magazine[i].zi[j].size(); ++k) {
                cout << i + 1 << " " << magazine[i].zi[j][k] << '\n';
            }
        }
    }*/

    /*cout << bonuri.size() << '\n';
    for (int i = 0; i < bonuri.size(); ++i) {
        cout << bonuri[i].first << '\n';
    }*/
    return 0;
}
