#include "Classes.h"

void Output::ShowMenu() {

	cout << '\n';
	cout << " Alegeti un task pentru rulare:\n\n";
	cout << "Task1 (Directorii executivi)\n";
	cout << "Task2 (Directorii de magazine)\n";
	cout << "Task3 (Seful depozit)\n\n";
	cout << "Tastati alegerea dumneavostra. (Pentru iesire din program folositi comanda end)\n";

}

void Output::ShowTask1Menu() {

	cout << "\n\n Alegeti o cerinta: \n";
	cout << "1. Lista cu toate magazinele si vanzarile totale facute de acestea\n";
	cout << "2. Lista cu toate produsele si vanzarile totale facute de acestea\n";
	cout << "3. Valoarea cosului mediu\n";
	cout << "4. Categoriile cele mai bine vandute pentru fiecare magazin\n";
	cout << "5. Perechile de de produse care se vand cel mai bine impreuna\n";
	cout << "6. Intoarecere la meniul principal\n\n";
	
	cout << "Tastati un numar:\n";

}

void Output::ShowTask3Menu() {
	cout << "\n\n Alegeti o cerinta: \n";
	cout << "1. Slotul in care se gaseste un anumit tip de produs\n";
	cout << "2. Mutari necesare pentru obtinerea unui palet\n";
	cout << "3. Prima comanda ce nu se poate onora\n";
	cout << "4. Intoarecere la meniul principal\n\n";

	cout << "Tastati un numar:\n";
}