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

#define MAXPRODUSE 500

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

void Task1b(Hash < string, int > &H, Produs *produse) {
    ofstream g("task1b.txt");

    int fcvProduse[MAXPRODUSE] = {0}; // fcvProduse[i] = de cate ori am vandut produsul cu id-ul i

    int szBucket, szBon;
    for (int i = 0; i < MOD; ++i) {
        szBucket = H[i].size();
        for (int j = 0; j < szBucket; ++j) {
            szBon = H[i][j].second.size();

            for (int k = 0; k < szBon; ++k) {
                ++fcvProduse[ H[i][j].second[k] ];
            }
        }
    }

    for (int i = 0; i < MAXPRODUSE; ++i) {
        if (fcvProduse[i] > 0) {
            g << produse[i].getNume() << ',' << fcvProduse[i] << '\n';
        }
    }
    g.close();
}

// cele mai mari 3 elemente dintr-un vector
void Maxime(int *v, int sz, int &max1, int &max2, int &max3)
{
    for (int i = 1; i < sz; ++i){
        if (v[i] < max1)
        {
            if (v[i] < max2)
            {
                if (v[i] > max3)  max3 = v[i];
            }
            else
            if (v[i] > max2)
                {
                    max3 = max2;
                    max2 = v[i];
                }
        }
        else
            if (v[i] > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = v[i];
            }
    }
}

// Converteste zilele trecute in format luna, zi
void ZileToData(int trecute, int &luna, int &zi){
    unsigned short v[] = {1, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 367};

    for (int i = 1; i < 13; ++i)
        if (trecute >= v[i - 1] && trecute < v[i]){
            luna = i;
            zi = trecute - v[i - 1] + 1;
        }
} 

void Task2a(ResizableArray<Magazin> &magazine, Hash < string, int > &hBonuri){
    int *fcvVanzari = new int[367]();
    int vanzareInZi;
    string idBon;

    ofstream g("NrProdusePeZile2a.txt");
    ofstream h("task2a.txt");
    h << "Zilele in care au fost cele mai multe produse vandute sunt:" << '\n';

    for (int idmag = 0; idmag < magazine.size(); ++idmag){
        h << "Pentru magazinul din locatia " << magazine[idmag].getLocatie() << '\n' << '\t';
        int *fcvVanzari = new int[367]();
        for (int i = 1; i < 367; ++i){
            vanzareInZi = 0;
            for (int j = 0; j < magazine[idmag].zi[i].size(); ++j){
                idBon = magazine[idmag].zi[i][j];
                ResizableArray < int > continut = hBonuri.getValue(idBon);
                vanzareInZi += continut.size();
            }
            fcvVanzari[i] += vanzareInZi;
        }

        for (int i = 1; i < 367; ++i)
            g << i << ',' << fcvVanzari[i] << '\n';
            g << '%' << '\n';

        int max[3] = {-1}, luna, zi;
        Maxime(fcvVanzari, 367, max[0], max[1], max[2]);

        for (int k = 0; k < 3; ++k){
            for (int i = 1; i < 367; ++i){
                if (fcvVanzari[i] == max[k]){
                    ZileToData(i, luna, zi);
                    h << "2016/" << luna << '/' << zi << ' ';
                }
            }
            h << "-> " << max[k] << " produse" << '\n' << '\t';
        }
        h << '\n';
        delete[] fcvVanzari;
    }

    g.close();
    h.close();
}

void Task2b(ResizableArray<Magazin> &magazine, Hash < string, int > &hBonuri){

    ofstream g("NrCumparatoriPeZile2b.txt");
    ofstream h("task2b.txt");
    h << "Zilele in care au fost cei mai multi cumparatori sunt:" << '\n';

    for (int idmag = 0; idmag < magazine.size(); ++idmag){
        int *fcvBonuri = new int[367]();
        for (int i = 1; i < 367; ++i){
            fcvBonuri[i] += magazine[idmag].zi[i].size();
        }

    h << "Pentru magazinul din locatia " << magazine[idmag].getLocatie() << '\n' << '\t';

    for (int i = 1; i < 367; ++i)
        g << i << ',' << fcvBonuri[i] << '\n';
    g << '%' << '\n';

    int max[3] = {-1}, luna, zi;
    Maxime(fcvBonuri, 367, max[0], max[1], max[2]);

    for (int k = 0; k < 3; ++k){
        for (int i = 1; i < 367; ++i){
            if (fcvBonuri[i] == max[k]){
                ZileToData(i, luna, zi);
                h << "2016/" << luna << '/' << zi << ' ';
            }
        }
        h << "-> " << max[k] << " cumparatori " << '\n' << '\t';
    }
    delete[] fcvBonuri;
    h << '\n';
    }
    g.close();
}

void Task1d(ResizableArray<Magazin> &magazine, Hash < string,
int > &hBonuri, Categorii &cat, Produs *produse){
    // int *fcvCateg = new int[cat.size()]();
    string idBon, categoria;
    int szBon;

    ofstream g("task1d.txt");
    for (int idmag = 0; idmag < magazine.size(); ++idmag){
        int *fcvCateg = new int[cat.GetSize()]();
        for (int i = 1; i < 367; ++i){
            for (int j = 0; j < magazine[idmag].zi[i].size(); ++j){
                idBon = magazine[idmag].zi[i][j];
                ResizableArray < int > continut = hBonuri.getValue(idBon);
                szBon = continut.size();
                for (int k = 0; k < szBon; ++k){
                    categoria = produse[continut[k]].getCategorie();
                    fcvCateg[cat.GetId(categoria)] += 1;
                }
            }
        }
        g << "Pentru magazinul din " << magazine[idmag].getLocatie();
        g << " cele mai vandute 3 categorii au fost:" << '\n' << "\t";

        int max[3] = {-1}, luna, zi;
        Maxime(fcvCateg, cat.GetSize(), max[0], max[1], max[2]);

        for (int k = 0; k < 3; ++k){
            for (int i = 1; i < cat.GetSize(); ++i){
                if (fcvCateg[i] == max[k])
                    g << cat.Get(i) << ' ';
            }
            g << "de " << max[k] << " ori " << '\n' << '\t';
        }
        g << '\n';
        delete[] fcvCateg;
    }

    g.close();
}

int main()
{
    // Ordonam array-ul asta dupa time_t pentru ultimul task
    ResizableArray < Pair < string, time_t > > bonuri;
    ResizableArray< Magazin > magazine; //magazinele vor fi tinute in RA si indexate dupa id - 1
    Categorii cat;
    Produs produse[MAXPRODUSE];
    Hash < string, int > hBonuri(MOD);

    Read R;
    R.MagazineRead("magazine.csv", magazine);
    R.CategoriiRead("categorii.csv", cat);
    R.ProduseRead("produse.csv", produse, cat);
    R.BonuriRead("bonuri.csv", hBonuri);
    R.TranzactiiRead("tranzactii.csv", magazine, bonuri);

    Task1a(magazine, produse, hBonuri);
    Task1b(hBonuri, produse);
    Task2b(magazine, hBonuri);
    Task2a(magazine, hBonuri);
    Task1d(magazine, hBonuri, cat, produse);
    return 0;
}
