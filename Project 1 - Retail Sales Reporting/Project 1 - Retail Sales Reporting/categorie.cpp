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

int Categorii::GetId(string categ) {
	unsigned int i;

	for (i = 0; i < vector.size(); i++) {
		if (categ == vector[i].name)
			return i;
	}
	return -1;
}

int Categorii::GetSize() {
	return vector.size();
}