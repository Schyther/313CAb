#include "Classes.h"

void Read::Bonuri(const char* name) {

	bonuri.open(name);

	string line;
	string id_bon, id_produs;
	int i;

	// Sar peste headerele tabelului
	getline(bonuri, line, '\r');

	
	while (!bonuri.eof()) {

		getline(bonuri, line, '\r');

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

void Read::Produse(const char *fileName) {

	string line = "";
	produse.open(fileName);

	string prodId;
	string prodName;
	int prodCategory;
	int prodPrice;
	int pos, length;


	getline(produse, line);
	while (getline(produse, line)) {
		prodName = "";
		prodId = "";
		prodCategory = 0;
		prodPrice = 0;
		length = line.size();
		pos = 0;

	
		while (line[pos] != ',') {
			prodId += line[pos++];
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

		// TODO: adaugare date la structuri

	}
}

void Read::Paleti(const char* fileName) {

	string line = "";
	int pos, length;
	paleti.open(fileName);

	string paletId = "";
	short prodType = 0, nItems = 0, slot = 0;

	paleti >> line;
	while (paleti >> line) {
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

void Read::Magazine(const char* fileName) {

	magazine.open(fileName);
	
	string line;
	string id_magazin, locatie;
	int i;

	// Sar peste headerele tabelului
	getline(magazine, line);


	while (!magazine.eof()) {

		getline(magazine, line);
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

void Read::Categorii(const char *fileName) {

	categorii.open(fileName);

	string line;
	string id_categorie, categorie;
	int i;

	// Sar peste headerele tabelului
	getline(categorii, line);

	while (!categorii.eof()) {

		getline(categorii, line);
		id_categorie = "";
		categorie = "";

		if (line != "") {

			// Fac split caracter cu caracter la linia citita
			i = 0;
			while (line[i] != ',') {
				id_categorie += line[i++];
			}

			i++;
			while (i < (int)line.length()) {

				categorie += line[i++];

			}

			// TODO: adaugare date la structuri

		}
	}


}

void Read::Tranzactii(const char *fileName) {

	tranzactii.open(fileName);

	int id;
	char timestamp[30];
	string id_bon, id_magazin, line;
	int i, n;

	// Sar peste headerele tabelului
	getline(tranzactii, line, '\r');

	while (!tranzactii.eof()) {

		getline(tranzactii, line, '\r');
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
			cout << id << '\n' << timestamp << '\n' << id_bon << '\n' << id_magazin;

		}
	}


}

Read::~Read() {

	bonuri.close();
	categorii.close();
	magazine.close();
	paleti.close();
	produse.close();

}