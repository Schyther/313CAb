#include "Classes.h"

void Read::Bonuri(const char* name) {

	bonuri.open(name);

	string line;
	char id_bon[30], id_produs[30];
	int i, n;

	// Sar peste headerele tabelului
	getline(bonuri, line, '\r');

	
	while (!bonuri.eof()) {

		getline(bonuri, line, '\r');
	

		// Fac split caracter cu caracter la linia citita
		i = 0; n = 0;
		while (line[i] != ',') {
			id_bon[n++] = line[i];
			i++;
		}

		id_bon[n] = '\0';

		i++; n = 0;
		while (i < (int)line.length()) {
		
			id_produs[n++] = line[i];
			i++;
		}
		
		id_produs[n] = '\0';
		

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
	short pos, length;
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
	char id_magazin[30], locatie[30];
	int i, n;

	// Sar peste headerele tabelului
	getline(bonuri, line, '\r');


	while (!bonuri.eof()) {

		getline(bonuri, line, '\r');


		// Fac split caracter cu caracter la linia citita
		i = 0; n = 0;
		while (line[i] != ',') {
			id_magazin[n++] = line[i];
			i++;
		}

		id_magazin[n] = '\0';

		i++; n = 0;
		while (i < (int)line.length()) {

			locatie[n++] = line[i];
			i++;
		}

		locatie[n] = '\0';

		cout << id_magazin << '\n' << locatie;
	}
}

Read::~Read() {

	bonuri.close();
	categorii.close();
	magazine.close();
	paleti.close();
	produse.close();

}