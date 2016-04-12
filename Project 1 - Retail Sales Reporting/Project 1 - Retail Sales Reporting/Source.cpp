#include "Classes.h"


bool CompareTime(const Bon < int, string, time_t >& a, const Bon < int, string, time_t >& b) {
	return a.timestamp < b.timestamp;
}

bool CompareIdMagTime(const Bon < int, string, time_t >& a, const Bon < int, string, time_t >& b) {

	if (a.idMag < b.idMag) return 1;
	else if (a.idMag == b.idMag)
		return a.timestamp < b.timestamp;

	return 0;
}

int main() {
	
	Read r;
	Solve s;
	Output o;
	
	Categorii categorii;
	Produs produse[NumarProduse];  // produse[i] - produsul cu id-ul i
	ResizableArray < Bon < int, string, time_t > > bonuri;
	ResizableArray< Magazin > magazine; //magazinele vor fi tinute in RA si indexate dupa id - 1
	Hash < string, int > hBonuri(MOD);
	DepozitGlobal depozit;

	// Citire date
	r.CategoriiRead("categorii.csv", categorii);
	r.ProduseRead("produse.csv", produse, categorii);
	r.MagazineRead("magazine.csv", magazine, produse);
	r.TranzactiiRead("tranzactii.csv", magazine, bonuri);
	r.BonuriRead("bonuri.csv", hBonuri);
	r.PaletiRead("paleti.csv", depozit);


	/*for (int i = 0; i < magazine[1].GetDepozit().getNProduse(); i++) {
		cout << magazine[3].GetDepozit().GetFcvP()[i] << '\n';
		cout << "CACA"<<"\n";
		cout << magazine[3].GetDepozit().getNProdus(i) << '\n';
	}*/

	string idBon;

	


	// Meniu
	while (1) {

		o.ShowMenu();

		char line[30], l[30];
		int selection, ok;
		int idMag;
	lineread:
		cin.getline(line, 30);

		if (strcmp(line, "") == 0)
			goto lineread;

		if (strcmp(line, "end") == 0)
			return 0;

		if (strcmp(line, "Task1") == 0) {

			ok = 1;
			while (ok) {
			back1:
				o.ShowTask1Menu();
				
				cin >> l;
				if (!strstr("0123456789", l)) {
					cout << "Selectie invalida!\n";
					goto back1;
				}

				selection = atoi(l);
				switch (selection) {

				case 1:
					s.Task1a(magazine, produse, hBonuri);
					cout << "\nTask executat cu succes. Outputul se regaseste in fisierul: chartVanzariMagazine.html\n";
					o.Chart("output/VanzariMagazineHeader.htm", "output/VanzariMagazineFooter.htm", 
						"output/task1a.txt", "output/chartVanzariMagazine.html");
					break;
				case 2:
					s.Task1b(hBonuri, produse, bonuri);
					cout << "\nTask executat cu succes. Outputul se regaseste in fisierul: chartVanzariProduse.html\n";
					o.Chart("output/VanzariProduseHeader.htm", "output/VanzariProduseFooter.htm", "output/task1b.txt",
						"output/chartVanzariProduse.html");
					break;
				case 3:
					s.Task1c(hBonuri, produse, bonuri);
					break;
				case 4:
					s.Task1d(magazine, hBonuri, categorii, produse);
					break;
				case 5:
					s.Task1e(hBonuri, produse, bonuri);
					break;
				case 6:
					ok = 0;
					break;
				default:
					cout << "\nSelectie invalida!\n\n" << '\n';
					break;
				}

			}
			continue;

		}

		if (strcmp(line, "Task2") == 0) {

			ok = 1;
			while (ok) {
			back2:
				o.ShowTask2Menu();
			
			
				cin >> l;
				if (!strstr("0123456789", l)) {
					cout << "Selectie invalida!\n";
					goto back2;
				}

				selection = atoi(l);
				switch (selection) {

				case 1:
					s.Task2a(magazine, hBonuri);
					cout << "\n Introduceti id-ul magazinului pentru care doriti grafic:\n";
					cin >> idMag;
					o.chartZile("output/VanzariZileHeader.htm", "output/VanzariZileFooter.htm", 
						"output/NrProdusePeZile2a.txt", "output/chartVanzariZile.html", idMag);
					cout << "\nGraficul se regaseste in fisierul: chartVanzariZile.html\n";
					break;
				case 2:
					s.Task2b(magazine, hBonuri);
					cout << "\nGraficul se regaseste in fisierul...\n";
					break;
				case 3:
					cout << "\nIntroduceti id-ul bonului:\n";
					cin >> idBon;
					cout << '\n';
					s.Task2c(idBon, hBonuri, produse);
					break;
				case 4:

					bonuri.QuickSort(0, bonuri.size() - 1, CompareIdMagTime);
					s.Task2d(bonuri, hBonuri);
					break;
				case 5:
					ok = 0;
					break;

				default:
					cout << "\nSelectie invalida!\n\n" << '\n';
					break;
				}

			}
			continue;
		}

		if (strcmp(line, "Task3") == 0) {
			ok = 1;
			while (ok) {
			back3:
				o.ShowTask3Menu();
			
				cin >> l;
				if (!strstr("0123456789", l)) {
					cout << "Selectie invalida!\n";
					goto back3;
				}

				selection = atoi(l);
				
				switch (selection) {

				case 1:
					cout << "\nIntroduceti id-ul produsului:\n";
					int idProd;
					cin >> idProd;
					cout << '\n';
					s.Task3a(idProd, depozit);
					break;
				case 2:
					cout << "\nIntroduceti id-ul produsului:\n";
					cin >> idProd;
					cout << '\n';
					s.Task3b(idProd, depozit);
					break;
				case 3:
					bonuri.QuickSort(0, bonuri.size() - 1, CompareTime);
					s.Task3c(bonuri, magazine, depozit, hBonuri);
					break;
				case 4:
					ok = 0;
					break;
				default:
					cout << "\nSelectie invalida!\n\n" << '\n';
					break;
				}

			}
			continue;
		}

		cout << "\nSelectie invalida!\n\n";
	}

	
	
	return 0;
}