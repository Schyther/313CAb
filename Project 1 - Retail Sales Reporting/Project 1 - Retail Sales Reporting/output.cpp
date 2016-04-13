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
	cout << "5. Perechile de produse care se vand cel mai bine impreuna\n";
	cout << "6. Intoarecere la meniul principal\n\n";
	
	cout << "Tastati un numar:\n";

}

void Output::ShowTask2Menu() {
	
	
	cout << "\n\n Alegeti o cerinta: \n";
	cout << "1. Zilele cu cele mai multe produse vandute\n";
	cout << "2. Zilele cu cei mai multi cumparatori\n";
	cout << "3. Continutul unui bon dupa id\n";
	cout << "4. Numatul clientilor care ar beneficia de introducerea unei a doua case de marcat\n";
	cout << "5. Intoarecere la meniul principal\n\n";
	
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

//functie luata din aplicatiile cursului 3
void Output::copyFile(ifstream& input, ofstream& output) {
	string buffer;
	while (getline(input, buffer)) {
		output << buffer << '\n';
	}
}

void Output::Chart(const char* h, const char* f, const char* in, const char* ch)
{
	ifstream header;
	ifstream footer;
	ifstream intrare;
	ofstream chart;

	header.open(h);
	footer.open(f);
	intrare.open(in);
	chart.open(ch);

	copyFile(header, chart);

	char line[100];
	while (intrare.getline(line, 100))
	{
		char *p, *p1;
		p = strtok(line, ",");
		p1 = strtok(NULL, ",");
		chart << "['" << p << "', " << p1 << "],\n";
	}

	copyFile(footer, chart);
}

void Output::chartZile(const char* h, const char* f, const char* in, const char* ch, int nr_mag)
{
	ifstream header;
	ifstream footer;
	ifstream intrare;
	ofstream chart;

	header.open(h);
	footer.open(f);
	intrare.open(in);
	chart.open(ch);

	copyFile(header, chart);

	char line[100];

	for (int i = 1; i < nr_mag; i++)
	{

		for (int j = 0; j<366; j++)
			intrare.getline(line, 100);
	}

	for (int j = 0; j<366; j++)
	{
		intrare.getline(line, 100);
		char *p, *p1;
		p = strtok(line, ",");
		p1 = strtok(NULL, ",");
		chart << "['" << p << "', " << p1 << "],\n";
	}

	copyFile(footer, chart);
}