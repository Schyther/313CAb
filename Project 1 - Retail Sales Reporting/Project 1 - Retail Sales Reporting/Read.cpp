#include "Classes.h"

void Read::BonuriRead(const char* name) {

	bonurif.open(name);

	string line;
	string id_bon, id_produs;
	int i;

	// Sar peste headerele tabelului
	getline(bonurif, line, '\r');

	
	while (!bonurif.eof()) {

		getline(bonurif, line, '\r');

		id_bon = "";
		id_produs = "";

		// Fac split caracter cu caracter la linia citita
		i = 0;
		while (line[i] != ',') {
			id_bon += line[i++];
		}

		i++;
		while (i < (int)line.length()) {
		
			id_produs+= line[i++];
		}
		

		cout << id_bon << '\n' << id_produs<<'\n';
		// TODO: adaugare date la structuri

	}
	

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

			produse[prodId].AddData(prodName, cat.Get(prodCategory), prodPrice);

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

void Read::MagazineRead(const char* fileName) {

	magazinef.open(fileName);
	
	string line;
	string id_magazin, locatie;
	int i;

	// Sar peste headerele tabelului
	getline(magazinef, line);


	while (!magazinef.eof()) {

		getline(magazinef, line);
		id_magazin = "";
		locatie = "";
		if (line != "") {
			// Fac split caracter cu caracter la linia citita
			i = 0;
			while (line[i] != ',') {
				id_magazin += line[i++];
			}

			i++;
			while (i < (int)line.length()) {

				locatie += line[i++];

			}

			// TODO: adaugare date la structuri
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

void Read::TranzactiiRead(const char *fileName) {

	tranzactiif.open(fileName);

	int id;
	char timestamp[30];
	string id_bon, id_magazin, line;
	int i, n;

	// Sar peste headerele tabelului
	getline(tranzactiif, line, '\r');

	while (!tranzactiif.eof()) {

		getline(tranzactiif, line, '\r');
		id = 0;
		id_bon = "";
		id_magazin = "";
		
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

				id_magazin += line[i++];
			}

			// TODO: adaugare date la structuri
			

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