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
	ofstream g("output/task1a.txt");
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
    ofstream g("output/task1b.txt");

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
    (1.0 * costTotal / (double)bonuri.size()) << " lei"<<'\n';
}


void Solve::Task1d(ResizableArray<Magazin> &magazine, Hash < string,
	int > &hBonuri, Categorii &cat, Produs *produse) {

	string idBon, categoria;
	int szBon;

	
	for (int idmag = 0; idmag < (int)magazine.size(); ++idmag) {
		int *fcvCateg = new int[cat.GetSize()]();
		for (int i = 1; i < 367; ++i) {
			for (int j = 0; j < (int)magazine[idmag].zi[i].size(); ++j) {
				idBon = magazine[idmag].zi[i][j];
				ResizableArray < int > continut = hBonuri.getValue(idBon);
				szBon = continut.size();
				for (int k = 0; k < szBon; ++k) {
					categoria = produse[continut[k]].getCategorie();
					fcvCateg[cat.GetId(categoria)] += 1;
				}
			}
		}
		cout << "Pentru magazinul din " << magazine[idmag].getLocatie();
		cout << " cele mai vandute 3 categorii au fost:" << '\n' << "\t";

		int max[3] = { -1 }, luna=0, zi=0;
		Maxime(fcvCateg, cat.GetSize(), max[0], max[1], max[2]);

		for (int k = 0; k < 3; ++k) {
			for (int i = 1; i < cat.GetSize(); ++i) {
				if (fcvCateg[i] == max[k])
					cout << cat.Get(i) << ' ';
			}
			cout << "de " << max[k] << " ori " << '\n' << '\t';
		}
		cout << '\n';
		delete[] fcvCateg;
	}


}

void Solve::Task1e(Hash < string, int > &H, Produs *produse,
	ResizableArray < Bon < int, string, time_t > > &bonuri) {
	Pair < int, int > pereche;
	List < Pair < int, int > > bestPair;

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
		if (szContinut < 2) {
			delete[] fcvProduse;
			continue;
		}
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
	for (int i = 0; i < NumarProduse; i++)
		delete[] perechi[i];
	delete[] perechi;
}

// cele mai mari 3 elemente dintr-un vector
void Solve::Maxime(int *v, int sz, int &max1, int &max2, int &max3)
{
	for (int i = 1; i < sz; ++i) {
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
void Solve::ZileToData(int trecute, int &luna, int &zi) {
	unsigned short v[] = { 1, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 367 };

	for (int i = 1; i < 13; ++i)
		if (trecute >= v[i - 1] && trecute < v[i]) {
			luna = i;
			zi = trecute - v[i - 1] + 1;
		}
}


void Solve::Task2a(ResizableArray<Magazin> &magazine, Hash < string, int > &hBonuri) {
	int *fcvVanzari = NULL;
	int vanzareInZi;
	string idBon;

	ofstream g("output/NrProdusePeZile2a.txt");
	
	cout << "Zilele in care au fost cele mai multe produse vandute sunt:" << '\n';

	for (int idmag = 0; idmag < (int)magazine.size(); ++idmag) {
		cout << "Pentru magazinul din locatia " << magazine[idmag].getLocatie() << '\n' << '\t';
		int *fcvVanzari = new int[367]();
		for (int i = 1; i < 367; ++i) {
			vanzareInZi = 0;
			for (int j = 0; j < (int)magazine[idmag].zi[i].size(); ++j) {
				idBon = magazine[idmag].zi[i][j];
				ResizableArray < int > continut = hBonuri.getValue(idBon);
				vanzareInZi += continut.size();
			}
			fcvVanzari[i] += vanzareInZi;
		}

		for (int i = 1; i < 367; ++i)
			g << i << ',' << fcvVanzari[i] << '\n';
		//    g << '%' << '\n';

		int max[3] = { -1 }, luna, zi;
		Maxime(fcvVanzari, 367, max[0], max[1], max[2]);

		for (int k = 0; k < 3; ++k) {
			for (int i = 1; i < 367; ++i) {
				if (fcvVanzari[i] == max[k]) {
					ZileToData(i, luna, zi);
					cout << "2016/" << luna << '/' << zi << ' ';
				}
			}
			cout << "-> " << max[k] << " produse" << '\n' << '\t';
		}
		cout << '\n';
		delete[] fcvVanzari;
	}

	g.close();
	
}

void Solve::Task2b(ResizableArray<Magazin> &magazine, Hash < string, int > &hBonuri) {

	ofstream g("output/NrCumparatoriPeZile2b.txt");
	
	cout << "Zilele in care au fost cei mai multi cumparatori sunt:" << '\n';

	for (int idmag = 0; idmag < (int)magazine.size(); ++idmag) {
		int *fcvBonuri = new int[367]();
		for (int i = 1; i < 367; ++i) {
			fcvBonuri[i] += magazine[idmag].zi[i].size();
		}

		cout << "Pentru magazinul din locatia " << magazine[idmag].getLocatie() << '\n' << '\t';

		for (int i = 1; i < 367; ++i)
			g << i << ',' << fcvBonuri[i] << '\n';

		int max[3] = { -1 }, luna, zi;
		Maxime(fcvBonuri, 367, max[0], max[1], max[2]);

		for (int k = 0; k < 3; ++k) {
			for (int i = 1; i < 367; ++i) {
				if (fcvBonuri[i] == max[k]) {
					ZileToData(i, luna, zi);
					cout << "2016/" << luna << '/' << zi << ' ';
				}
			}
			cout << "-> " << max[k] << " cumparatori " << '\n' << '\t';
		}
		delete[] fcvBonuri;
		cout << '\n';
	}
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

void Solve::Task2d(ResizableArray < Bon < int, string, time_t > > &bonuri,
	Hash < string, int > &H) {
	int szBonuri = bonuri.size();
	int nrClienti = 0;
	int i, szContinut, timpPerTranzactie;
	time_t timp1, timp2;

	for (i = 0; i < szBonuri - 1; ++i) {
		szContinut = H.getValue(bonuri[i].idBon).size();

		timpPerTranzactie = szContinut * TimpPerProdus;

		timp1 = bonuri[i].timestamp;
		timp2 = bonuri[i + 1].timestamp;

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

	cout << "In magazinul " << bonuri[i].idMag;
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

void Solve::Task3c(ResizableArray < Bon < int, string, time_t > > &bonuri,
	ResizableArray< Magazin > magazine, DepozitGlobal depozit, Hash < string, int > &hBonuri) {

	ResizableArray <int> produse;

	int nrBonuri = bonuri.size() - 1;
	int i, j;



	for (i = 0; i <= nrBonuri; i++) {
		produse = hBonuri.getValue(bonuri[i].idBon);

		for (j = 0; j < (int)produse.size(); j++) {
			
			int check = magazine[bonuri[i].idMag-1].removeProdus(produse[j], 1, depozit);

			 if (check == -1) {
				 cout << "\nDupa realizarea tranzactiei bonului cu id-ul "
				 << bonuri[i].idBon << ", magazinul cu id-ul " << bonuri[i].idMag
				<< " a cerut depozitului" << " un palet de produse cu id-ul " << produse[j]
				 << ". Depozitul nu a putut onora aceasta comanda.\n";
				 return;
			}

		}

	}

	
}





