#include "Classes.h"

Categorii::Categorii() {

};

Categorii::Categorii(Categorii& c) {

}

Categorii::~Categorii() {

}

void Categorii::Add(int id, string name) {

	Categorie nou;
	nou.id = id;
	nou.name = name;
	vector.push_back(nou);

}

string Categorii::Get(int id) {

	unsigned int i;

	for (i = 0; i < vector.size(); i++) {
		if (id == vector[i].id) 
			return vector[i].name;
	}

	return "";

}