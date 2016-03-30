#include "Classes.h"

void Read::Bonuri() {

	bonuri.open("bonuri.csv");

	string line;
	string id_bon, id_produs;
	char *p;

	// Sar peste headerele tabelului
	getline(bonuri, line, '\n');



	while (!bonuri.eof()) {

		getline(bonuri, line, '\n');
	
		
		p = strtok(line, ",");

		cout << id_bon << '\n' << id_produs;
		// TODO: adaugare date la structuri

	}
	

}

Read::~Read() {

	bonuri.close();
	categorii.close();
	magazine.close();
	paleti.close();
	produse.close();

}