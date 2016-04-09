#include "Classes.h"

void Read::BonuriRead(const char* name, HashGen <string, Bon*>& hBonuri) {

	bonurif.open(name);

	string line;
	string id_bon;
	int id_produs;
	int i;

	// Sar peste headerele tabelului
	getline(bonurif, line, '\r');

	
	while (!bonurif.eof()) {

		getline(bonurif, line, '\r');

		id_bon = "";
		id_produs = 0;

		// Fac split caracter cu caracter la linia citita
		i = 0;
		while (line[i] != ',') {
			id_bon += line[i++];
		}

		i++;
		while (i < (int)line.length()) {
		
			id_produs= id_produs*10 + line[i++]- '0';
		}
		
		
		Bon *b = hBonuri.getValue(id_bon);

		b->AddProdus(id_produs);

	}
	

}

time_t Read::ConvertTime(char *timeToConvert) {
	struct tm newTime = { 0 };
	char *dates[7];
	char *p;
	int nr = 0;

	timeToConvert[strlen(timeToConvert)] = '\0';
	p = strtok(timeToConvert, "- : ");
	while (p != NULL) {
		dates[nr++] = p;
		p = strtok(NULL, "- : ");
	}

	newTime.tm_year = atoi(dates[0]) - 1900;
	newTime.tm_mon = atoi(dates[1]) - 1;
	newTime.tm_mday = atoi(dates[2]);
	newTime.tm_hour = atoi(dates[3]);
	newTime.tm_min = atoi(dates[4]);
	newTime.tm_sec = atoi(dates[5]);

	time_t temp = mktime(&newTime);


	return temp;
}

void Read::ProduseRead(const char *fileName, Produs *produse, Categorii& cat) {

	string line = "";
	produsef.open(fileName);

	int prodId;
	string prodName;
	int prodCategory;
	int prodPrice;
	int pos, length;


	getline(produsef, line);
	while (getline(produsef, line)) {

		if (line != "") {

			prodName = "";
			prodId = 0;
			prodCategory = 0;
			prodPrice = 0;
			length = line.size();
			pos = 0;


			while (line[pos] != ',') {
				prodId = prodId * 10 + line[pos++] - '0';
			}

			++pos;
			while (line[pos] != ',') {
				prodName += line[pos++];
			}

			++pos;
			while (line[pos] != ',') {
				prodCategory = 10 * prodCategory + short(line[pos++] - '0');
			}

			++pos;
			while (pos < length) {
				prodPrice = 10 * prodPrice + short(line[pos++] - '0');
			}

			produse[prodId].AddData(prodId, prodName, cat.Get(prodCategory), prodPrice);

		}
	}
}

void Read::PaletiRead(const char* fileName) {

	string line = "";
	int pos, length;
	paletif.open(fileName);

	string paletId = "";
	short prodType = 0, nItems = 0, slot = 0;

	paletif >> line;
	while (paletif >> line) {
		paletId = "";
		prodType = nItems = slot = 0;
		pos = 0;
		length = line.size();

		while (line[pos] != ',') {
			paletId += line[pos++];
		}

		++pos;
		while (line[pos] != ',') {
			prodType = 10 * prodType + short(line[pos++] - '0');
		}

		++pos;
		while (line[pos] != ',') {
			nItems = 10 * nItems + short(line[pos++] - '0');
		}

		++pos;
		while (pos < length) {
			slot = 10 * slot + short(line[pos++] - '0');
		}

		// TODO: adaugare date la structuri

	}

}

void Read::MagazineRead(const char* fileName, ResizableArray<Magazin> &magazine) {

	magazinef.open(fileName);
	
	string line;
	int id_magazin;
	string locatie;
	int i;

	// Sar peste headerele tabelului
	getline(magazinef, line);


	while (!magazinef.eof()) {

		getline(magazinef, line);
		id_magazin = 0;
		locatie = "";
		if (line != "") {
			// Fac split caracter cu caracter la linia citita
			i = 0;
			while (line[i] != ',') {
				id_magazin = id_magazin * 10 + line[i++] - '0';
			}

			i++;
			while (i < (int)line.length()) {

				locatie += line[i++];

			}

			Magazin m(id_magazin, locatie);

			magazine.push_back(m);
		}
	}
}

void Read::CategoriiRead(const char *fileName, Categorii& cat) {

	categoriif.open(fileName);

	string line;
	string categorie;
	int id_categorie;
	int i;

	// Sar peste headerele tabelului
	getline(categoriif, line);

	while (!categoriif.eof()) {

		getline(categoriif, line);
		id_categorie = 0;
		categorie = "";

		if (line != "") {

			// Fac split caracter cu caracter la linia citita
			i = 0;
			while (line[i] != ',') {
				id_categorie = id_categorie*10 + line[i++]-'0';
			}

			i++;
			while (i < (int)line.length()) {

				categorie += line[i++];

			}

			cat.Add(id_categorie, categorie);

		}
	}


}

void Read::TranzactiiRead(const char *fileName, ResizableArray<Magazin>& magazine, HashGen <string, Bon*>& hBonuri) {

	tranzactiif.open(fileName);

	int id;
	char timestamp[30];
	int id_magazin;
	string id_bon, line;
	int i, n;

	// Sar peste headerele tabelului
	getline(tranzactiif, line, '\r');

	while (!tranzactiif.eof()) {

		getline(tranzactiif, line, '\r');
		id = 0;
		id_bon = "";
		id_magazin = 0;
		
		if (line != "") {

			// Fac split caracter cu caracter la linia citita
			i = 0;
			while (line[i] != ',') {
				id = id * 10 + line[i++] - '0';
			}

			i++; n = 0;
			while (line[i] != ',') {

				timestamp[n++] = line[i++];

			}

			timestamp[n] = '\0';

			i++;

			while (line[i] != ',') {
				
				id_bon += line[i++];
			}

			i++;

			while (i < (int)line.length()) {

				id_magazin = id_magazin*10 + line[i++] - '0';
			}

			for (i = 0; i <= (int)magazine.size(); i++) {

				if (magazine[i].getId() == id_magazin)
					break;

			}

			Bon b(id_bon, ConvertTime(timestamp));
			
			magazine[i].add_bon(b);
			hBonuri.insert(id_bon, &magazine[i].getBonuri()->peek());

		}
	}


}




Read::~Read() {

	bonurif.close();
	categoriif.close();
	magazinef.close();
	paletif.close();
	produsef.close();

}