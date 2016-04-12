#include "Classes.h"


bool CompareTime(const Bon < int, string, time_t >& a, const Bon < int, string, time_t >& b) {
	return a.timestamp < b.timestamp;
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
	r.MagazineRead("magazine.csv", magazine);
	r.TranzactiiRead("tranzactii.csv", magazine, bonuri);
	r.BonuriRead("bonuri.csv", hBonuri);
	r.PaletiRead("paleti.csv", depozit);


	bonuri.QuickSort(0, bonuri.size() - 1, CompareTime);

	// Meniu
	while (1) {

		o.ShowMenu();

		char line[30];
		int selection, ok;
	lineread:
		cin.getline(line, 30);

		if (strcmp(line, "") == 0)
			goto lineread;

		if (strcmp(line, "end") == 0)
			return 0;

		if (strcmp(line, "Task1") == 0) {

			ok = 1;
			while (ok) {

				o.ShowTask1Menu();

				cin >> selection;
				switch (selection) {

				case 1:
					s.Task1a(magazine, produse, hBonuri);
					cout << "\nTask executat cu succes. Outputul se regaseste in fisierul...\n";
					break;
				case 2:
					s.Task1b(hBonuri, produse, bonuri);
					cout << "\nTask executat cu succes. Outputul se regaseste in fisierul...\n";
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					s.Task1e(hBonuri, produse);
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

				o.ShowTask2Menu();

				cin >> selection;
				switch (selection) {

				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
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

				o.ShowTask3Menu();

				cin >> selection;
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