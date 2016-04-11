#include "Classes.h"

DepozitGlobal::DepozitGlobal() {


}

DepozitGlobal::DepozitGlobal(const DepozitGlobal& other) {

	for (int i = 0; i < NumarSloturi; i++) {
		sloturi[i] = other.sloturi[i];
	}
}

DepozitGlobal::~DepozitGlobal() {

	
}

Stack<Palet>*  DepozitGlobal::GetSloturi() {

	return sloturi;
}
/*
int DepozitGlobal::findSlot(string id_produs) {
	for (int i = 0; i < NumarSloturi; ++i) {
		ResizableArray <Palet> temp; //pastreaza paletii in timp ce efectuam cautarea
		
		Palet palet_crt = sloturi[i].top();

		while (!sloturi[i].empty && palet_crt.getIdPalet != id_produs) {
			temp.push_back(palet_crt);
			sloturi[i].pop();
			palet_crt = sloturi[i].top();
		}

		//pune paletii la loc in slotul i dupa ce a efectuat cautarea
		for (int j = temp.size() - 1; j >= 0; --j) {
			sloturi[i].push(temp[j]);
		}

		//verifica daca a gasit produsul cautat in slotul i
		if (palet_crt.getIdProdus == id_produs && palet_crt.getNrItems > 0) {
			return i;
		}
	}

	return -1; //produsul cautat nu se afla in depozit


		 TODO: in loc sa returneze primul slot unde gaseste produsul,
		sa returneze slotul unde care produsul se gaseste cat mai aproape
		de varful stivei 
}

bool DepozitGlobal::Comanda(string id_produs) {
	int slotProdus = findSlot(id_produs);
	int slotAuxiliar; //slotul in care se depoziteaza paletii de deasupra paletului cautat

	if (slotProdus < NumarProduse - 1) {
		slotAuxiliar = slotProdus + 1;
	}
	else {
		slotAuxiliar = 0;
	}

	if (slotProdus == -1) {
		cout << "Comana nu poate fi onorata";
		return false;
	}

	Palet palet_crt = sloturi[slotProdus].top();

	while (!sloturi[slotProdus].empty && palet_crt.getIdPalet != id_produs) {
		//transfer palet dintr-o stiva in alta
		sloturi[slotAuxiliar].push(palet_crt);
		sloturi[slotProdus].pop();
		palet_crt = sloturi[slotProdus].top();

		//afisare mutare
		cout << "MOVE PALET " << palet_crt.getIdPalet;
		cout << " FROM SLOT " << slotProdus << " TO SLOT " << slotAuxiliar << '\n';
	}

	//actualizare numar produse in paletul cautat
	sloturi[slotProdus].top().setNrItems(0);
	ar trebuie sa dau pop() paletului si sa uitam ca a existat vreodata?
	in felul asta nu mai avem history, dar e ceva mai eficient

	return true; //Comanda a fost onorata!
}
*/