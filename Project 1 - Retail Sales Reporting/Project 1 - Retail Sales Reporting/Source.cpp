#include "Classes.h"


int main() {
	
	Read r;
	
	Categorii categorii;
	Produs produse[NumarProduse];  // produse[i] - produsul cu id-ul i
	
	ResizableArray <Magazin> magazine;
	HashGen <string, Bon*> hBonuri(MOD);

	// Citire date
	r.CategoriiRead("categorii.csv", categorii);
	r.ProduseRead("produse.csv", produse, categorii);
	r.MagazineRead("magazine.csv", magazine);
	r.TranzactiiRead("tranzactii.csv", magazine, hBonuri);
	r.BonuriRead("bonuri.csv", hBonuri);
	
	for (int i = 0; i < magazine.size(); i++)
		cout << magazine[0].getBonuri()->peek().getNrProduse() << '\n';

	return 0;
}