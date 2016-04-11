using namespace std;
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <cstdlib>

#include "resizablearray.h"
#include "hash.h"

#include "Magazin.h"
#include "Read.h"

#define MAXPROD 500

void Task2c(string idBon, Hash < string, int > &H, Produs *produse) {
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

double Task1c(Hash < string, int > &H, Produs *produse) {
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

void Task1a(ResizableArray < Magazin > &magazine, Produs *produse, Hash < string, int > &H) {
    int szBon;
    string idBon;
    ofstream g("task1a.txt");
    g << "Magazin,Vanzari totale\n";
    int magSz = magazine.size();

    for (int i = 0; i < magSz; ++i) {
        int totalVanzari = 0;

        for (int j = 1; j < 367; ++j) {
            int bonuriZi = magazine[i].zi[j].size(); // cate bonuri am vandut in ziua j
            for (int k = 0; k < bonuriZi; ++k) {
                idBon = magazine[i].zi[j][k];
                ResizableArray < int > continutBon = H.getValue(idBon);

                szBon = continutBon.size();
                for (int l = 0; l < szBon; ++l) {
                    totalVanzari += produse[ continutBon[l] ].getPret();
                }
            }
        }
        g << magazine[i].getLocatie() << ',' << totalVanzari << '\n';
    }
    g.close();
}

int main()
{
    // Ordonam array-ul asta dupa time_t pentru ultimul task
    ResizableArray < Pair < string, time_t > > bonuri;
    ResizableArray< Magazin > magazine; //magazinele vor fi tinute in RA si indexate dupa id - 1
    Categorii cat;
    Produs produse[MAXPROD];
    Hash < string, int > hBonuri(MOD);

    Read R;
    R.MagazineRead("magazine.csv", magazine);
    R.CategoriiRead("categorii.csv", cat);
    R.ProduseRead("produse.csv", produse, cat);
    R.BonuriRead("bonuri.csv", hBonuri);
    R.TranzactiiRead("tranzactii.csv", magazine, bonuri);

    Task1a(magazine, produse, hBonuri);

    /*for(unsigned i = 0; i < magazine.size(); ++i)
    {
        cout << "locatie magazin cu id-ul " << i + 1 << ": " << magazine[i].getLocatie() << '\n';
    }
    for(int i=0; i< 50; ++i)
    {
        cout << produse[i];
    }

    int sz1, sz2;
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

    //cout << fixed << setprecision(7) << Task3c(hBonuri, produse) << '\n';

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
