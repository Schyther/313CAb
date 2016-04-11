#include "Classes.h"


int main() {
	
	Read r;
	
	Categorii categorii;
	Produs produse[NumarProduse];  // produse[i] - produsul cu id-ul i
	ResizableArray < Pair < string, time_t > > bonuri;
	ResizableArray< Magazin > magazine; //magazinele vor fi tinute in RA si indexate dupa id - 1
	HashBon < string, int > hBonuri(MOD);
	DepozitGlobal depozit;

	// Citire date
	r.CategoriiRead("categorii.csv", categorii);
	r.ProduseRead("produse.csv", produse, categorii);
	r.MagazineRead("magazine.csv", magazine);
	r.TranzactiiRead("tranzactii.csv", magazine, bonuri);
	r.BonuriRead("bonuri.csv", hBonuri);
	r.PaletiRead("paleti.csv", depozit);


	return 0;
}