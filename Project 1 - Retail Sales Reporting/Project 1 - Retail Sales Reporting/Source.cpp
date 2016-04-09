#include "Classes.h"


int main() {
	
	Read r;
	
	Categorii categorii;
	Produs produse[NumarProduse];  // produse[i] - produsul cu id-ul i.
	
	// Citire date
	r.CategoriiRead("categorii.csv", categorii);
	r.ProduseRead("produse.csv", produse, categorii);
	

	return 0;
}