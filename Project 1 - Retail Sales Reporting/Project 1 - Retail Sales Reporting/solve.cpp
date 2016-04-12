#include "Classes.h"

Solve::Solve()
{
}

Solve::~Solve()
{
}

void Solve::Task1a(ResizableArray < Magazin > &magazine, Produs *produse, Hash < string, int > &H) {
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
					totalVanzari += produse[continutBon[l]].getPret();
				}
			}
		}
		g << magazine[i].getLocatie() << ',' << totalVanzari << '\n';
	}
	g.close();
}

void Solve::Task1b(Hash < string, int > &H, Produs *produse,
    ResizableArray < Bon < int, string, time_t > > &bonuri) {
    ofstream g("task1b.txt");

    int szBonuri = bonuri.size();
    int fcvProduse[NumarProduse] = {0}; // fcvProduse[i] = de cate ori am vandut produsul cu id-ul i

    for (int i = 0; i < szBonuri; ++i) {
        ResizableArray < int > continutBon = H.getValue(bonuri[i].idBon);
        int szContinut = continutBon.size();

        for (int j = 0; j < szContinut; ++j) {
            ++fcvProduse[continutBon[j]];
        }
    }

    for (int i = 0; i < NumarProduse; ++i) {
        if (fcvProduse[i] > 0) {
            g << produse[i].getNume() << ',' << fcvProduse[i] * produse[i].getPret() << '\n';
        }
    }
    g.close();
}

void Solve::Task1c(Hash < string, int > &H, Produs *produse,
	ResizableArray < Bon < int, string, time_t > > &bonuri) {
    double costTotal = 0;
    int szBonuri = bonuri.size();
    for (int i = 0; i < szBonuri; ++i) {
        ResizableArray < int > continutBon = H.getValue(bonuri[i].idBon);
        int szContinut = continutBon.size();

        for (int j = 0; j < szContinut; ++j) {
            costTotal += produse[ continutBon[j] ].getPret();
        }
    }

    cout << "Valoare cosului mediu este: "<<
    (1.0 * costTotal / (double)bonuri.size()) <<'\n';
}

void Solve::Task1e(Hash < string, int > &H, Produs *produse) {
	//ofstream g("task1e.txt");
	int *counter; // vector de aparitii

	counter = new int[NumarProduse];

    // numar intr-o matrice de cate ori apare
    // perechea (i, j) pe bonuri
	int **perechi;

	perechi = new int*[NumarProduse];

	int i, j;
	for (i = 0; i < NumarProduse; i++) {
		perechi[i] = new int[NumarProduse];
		for (j = 0; j < NumarProduse; j++) perechi[i][j] = 0;
	}


    int bonActual, nrBonuri, nrProduse;
    int maxVanzari = 1; // trebuie sa fie vandute cel putin o data
    int prod1, prod2;
    bool inList;
    Pair < int, int > pereche;
    List < Pair < int, int > > bestPair;
    ResizableArray < int > continut;
    for (int i = 0; i < MOD; i++) { // nr hash
        nrBonuri = H[i].size(); // nr de bonuri din H[i]
        for (int j = 0; j < nrBonuri; j++) {
            memset(counter, 0, sizeof(counter));
            continut = H[i][j].second;
            nrProduse = continut.size();
            
            // daca e un singur produs pe bon, nu avem ce verifica
            if (nrProduse < 2) continue;

            for (int k = 0; k < nrProduse; k++) {
                counter[ continut[k] ]++;
            }
            for (int prod1 = 0; prod1 < nrProduse - 1; prod1++) {
                for (int prod2 = prod1 + 1; prod2 < nrProduse; prod2++) {
                    bonActual = Min(counter[prod1], counter[prod2]);
                    perechi[prod1][prod2] += bonActual;
                    perechi[prod2][prod1] += bonActual;
                    pereche.makePair(prod1, prod2);

                    if (perechi[prod1][prod2] == maxVanzari) {
                        // adaug la lista cu cele mai bine vandute perechi
                        inList = bestPair.getpos(pereche) < 0 ? 0 : 1;
                        if (!inList) bestPair.push_back(pereche);
                    }

                    if (perechi[prod1][prod2] > maxVanzari) {
                        // resetez lista cu cele mai bine vandute perechi
                        bestPair.clear();
                        maxVanzari = perechi[prod1][prod2];
                        bestPair.push_back(pereche);
                    }
                }
            }            
        }
    }
    if (bestPair.empty()) {
        cout << "Nu exista nicio pereche de produse vandute bine impreuna\n";
        return;
    }
    cout << "Perechile de produse cel mai bine vandute impreuna sunt:\n";
  	Node < Pair < int, int> > *perecheP; //pointer la pereche
    perecheP = bestPair.first();
    while (perecheP != NULL) {
        prod1 = perecheP->value.first;
        prod2 = perecheP->value.second;
        cout << produse[prod1].getNume() << ", ";
        cout << produse[prod2].getNume() << "\n";
        perecheP = perecheP->next;
    }
    cout << "Aceste perechi au fost vandute de " << maxVanzari << " ori\n";

	for (i = 0; i < NumarProduse; i++)
		delete[] perechi[i];
	delete[] perechi;
    //g.close();
}


void Solve::Task2a(ResizableArray<Magazin> &magazine, Hash < string, int > &hBonuri) {
	int *vanzari = new int[367]();
	int vanzareInZi;
	string idBon;

	for (int idmag = 0; idmag < (int)magazine.size(); ++idmag) {
		for (int i = 1; i < 367; ++i) {
			vanzareInZi = 0;
			for (int j = 0; j < (int)magazine[idmag].zi[i].size(); ++j) {
				idBon = magazine[idmag].zi[i][j];
				ResizableArray < int > continut = hBonuri.getValue(idBon);
				vanzareInZi += continut.size();
			}
			vanzari[i] += vanzareInZi;
		}
	}

	ofstream g("task2a.txt");
	for (int i = 1; i < 367; ++i)
		g << i << ',' << vanzari[i] << '\n';
	// cout << vanzari[i] << '\n';

	int max1 = vanzari[1], max2 = vanzari[2], max3 = vanzari[3];
	for (int i = 4; i < 367; ++i) {
		if (vanzari[i] < max1)
		{
			if (vanzari[i] < max2)
			{
				if (vanzari[i] > max3)  max3 = vanzari[i];
			}
			else {
				max3 = max2;
				max2 = vanzari[i];
			}
		}
		else {
			max3 = max2;
			max2 = max1;
			max1 = vanzari[i];
		}
	}

	for (int i = 1; i < 367; ++i) {
		if (vanzari[i] == max1) cout << i << ' ';
	}
	cout << max1 << '\n';
	for (int i = 1; i < 367; ++i) {
		if (vanzari[i] == max2) cout << i << ' ';
	}
	cout << max2 << '\n';
	for (int i = 1; i < 367; ++i) {
		if (vanzari[i] == max3) cout << i << ' ';
	}
	cout << max3 << '\n';


	delete[] vanzari;
	g.close();
}


void Solve::Task2c(string idBon, Hash < string, int > &H, Produs *produse) {
	ResizableArray < int > continut = H.getValue(idBon);

	if (continut.size() == 0) {
		cout << "Id de bon invalid!\n";
		return;
	}

	cout << "Bonul cu id-ul " << idBon << " contine urmatoarele produse:\n";

	int sz = continut.size();
	for (int i = 0; i < sz; ++i) {
		cout << "   " << produse[continut[i]].getNume() << '\n';
	}
}


void Solve::Task3a(int idProdus, DepozitGlobal& depozit) {

	int idSlot;
	idSlot = depozit.FindSlot(idProdus);
	cout << "Produsul a fost gasit in slotul: "<< idSlot <<'\n';
}

void Solve::Task3b(int idProdus,DepozitGlobal& depozit) {

	if (depozit.Comanda(idProdus)) cout << "Comanda onorata" << '\n';
	else cout << "Comanda nu a putut fi onorata" << "\n";

}

void Solve::Task3c(ResizableArray < Bon < int, string, time_t > > &bonuri, ResizableArray< Magazin > &magazine, DepozitGlobal &depozit) {
	ResizableArray< Magazin > *maux; //copie la magazine
	DepozitGlobal *daux; //copie la depozitglobal

	maux = new ResizableArray< Magazin >;
	maux = &magazine;

	daux = new DepozitGlobal;
	daux = &depozit;

	



}


/*
bool Solve::CompareTime(const Bon < int, string, time_t >& a, const Bon < int, string, time_t >& b) {
	return a.timestamp < b.timestamp;
}
*/

bool Solve::CompareIdMagTime(const Bon < int, string, time_t >& a, const Bon < int, string, time_t >& b) {
	
	if (a.idMag < b.idMag) return 1;
	else if (a.idMag == b.idMag)
		return a.timestamp < b.timestamp;
	
	return 0;
}

