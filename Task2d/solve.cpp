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

void Solve::Task1e(Hash < string, int > &H, Produs *produse,
	ResizableArray < Bon < int, string, time_t > > &bonuri) {
	Pair < int, int > pereche;
	List < Pair < int, int > > bestPair;
	//ofstream g("task1e.txt");
	// numar intr-o matrice de cate ori apare
	// perechea (i, j) pe bonuri

	int **perechi;

	perechi = new int*[NumarProduse];

	int i;
	for (i = 0; i < NumarProduse; i++) {
		perechi[i] = new int[NumarProduse]();
	}

	int bonActual=0, nrBonuri=0, nrProduse=0;
	int maxVanzari = 1; // trebuie sa fie vandute cel putin o data
	int prod1, prod2;
	bool inList;
	int szBonuri = bonuri.size();
	for (int i = 0; i < szBonuri; ++i) {
		int *fcvProduse = new int[NumarProduse]();
		ResizableArray < int > continutBon = H.getValue(bonuri[i].idBon);
		int szContinut = continutBon.size();
		// daca e un singur produs pe bon, nu avem ce verifica
		if (szContinut < 2) continue;
		for (int j = 0; j < szContinut; ++j) {
			fcvProduse[continutBon[j]]++;
		}
		for (int j = 0; j < szContinut - 1; ++j) {
			for (int k = j + 1; k < szContinut; ++k) {
				prod1 = continutBon[j];
				prod2 = continutBon[k];
				if (prod1 == prod2) continue;
				bonActual = Min(fcvProduse[prod1], fcvProduse[prod2]);
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
		delete[] fcvProduse;
	}

	if (bestPair.empty()) {
		cout << "Nu exista nicio pereche de produse vandute bine impreuna\n";
		return;
	}
	cout << "Perechile de produse cel mai bine vandute impreuna sunt:\n\n";
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

void Solve::Task2d(ResizableArray < Bon < int, string, time_t > > &bonuri, Hash < string, int > &H) {
	int szBonuri = bonuri.size();
	int nrClienti = 0;
	int i, szContinut, timpPerTranzactie;
	int timp1, timp2;

	for  (i = 0; i < szBonuri-1; ++i) {
		szContinut = H.getValue(bonuri[i].idBon).size();

		timpPerTranzactie = szContinut * TimpPerProdus;

		timp1 = bonuri[i].timestamp;
		timp2 = bonuri[i + 1].timpestamp;

		if (timp2 - timp1 < timpPerTranzactie &&
			bonuri[i].idMag == bonuri[i + 1].idMag) {
				nrClienti++;
		}

		if (bonuri[i].idMag != bonuri[i + 1].idMag) {
			cout << "In magazinul " << bonuri[i].idMag;
			if (nrClienti == 0) {
				cout << ", niciun client nu ar beneficia de introducerea unei a doua case.\n";
				continue;
			}
			cout << ", " << nrClienti << " clienti ar beneficia de o a doua casa.\n";
			nrClienti = 0;
		}
	}

	if (nrClienti == 0) {
		cout << ", niciun client nu ar beneficia de introducerea unei a doua case.\n";
		return;
	}
	cout << ", " << nrClienti << " clienti ar beneficia de o a doua casa.\n";
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



