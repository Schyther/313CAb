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

int DepozitGlobal::FindSlot(int id_produs) {

	int poz;

	for (int i = 0; i < NumarSloturi; ++i) {
		ResizableArray <Palet> temp; //pastreaza paletii in timp ce efectuam cautarea
		
		Palet palet_crt;
		poz = 0;

		while (!sloturi[i].empty()) {
			poz++;
			palet_crt = sloturi[i].top();
			sloturi[i].pop();
			temp.push_back(palet_crt);
			
			if (palet_crt.getIdProdus() == id_produs)
				break;
		}

		//pune paletii la loc in slotul i dupa ce a efectuat cautarea
		for (int j = temp.size() - 1; j >= 0; --j) {
			sloturi[i].push(temp[j]);
		}

		//verifica daca a gasit produsul cautat in slotul i
		if (palet_crt.getIdProdus() == id_produs && palet_crt.getNrItems() > 0) {
			return i;
		}
	}


	return -1; //produsul cautat nu se afla in depozit

}


bool DepozitGlobal::Comanda(int id_produs) {
	int slotProdus = FindSlot(id_produs);
	int i=slotProdus-1, j=slotProdus+1;
	ResizableArray <Palet> temp;
	
	while (i >= 0 && j < NumarSloturi) { // Verific care este primul slot cel mai apropiat fie la stanga fie la dreapta pe care se poate realiza o mutare
		if (!sloturi[i].empty()) { j = i; break; }
		if (!sloturi[j].empty()) { i = j; break; }
		i--; j++;
	}
	

	if (slotProdus == -1) {
		return false;
	}

	Palet palet_crt;

	while (!sloturi[slotProdus].empty()) {
		palet_crt = sloturi[slotProdus].top();
		if (palet_crt.getIdProdus() == id_produs) break;
		else {
			cout << "Paletul de pe slotul " << slotProdus << " cu ID " << palet_crt.getIdPalet() << " ,numar de produse " 
			<< palet_crt.getNrItems() << " si ID-PRODUS " << palet_crt.getIdProdus() << " se muta pe slotul " << i << '\n';
		}
		sloturi[i].push(palet_crt);
		sloturi[slotProdus].pop();
		temp.push_back(palet_crt);

	}

	cout << "Extrag paletul cu ID-PRODUS " << id_produs << '\n';

	for (int j = temp.size() - 1; j >= 0; --j) {
		cout << "Mut inapoi paletul de pe slotul " << i << " cu ID " << temp[j].getIdPalet() << " ,numar de produse " 
		<< temp[j].getNrItems() << " si ID-PRODUS " << temp[j].getIdProdus() << " pe slotul " << slotProdus << '\n';
		sloturi[slotProdus].push(temp[j]);
	}



	return true; //Comanda a fost onorata!
}


int DepozitGlobal::GetPalet(int idProd) {

	ResizableArray <Palet> temp;

	int slot = FindSlot(idProd);
	if (slot != -1) {

		Palet palet_crt;
		int poz = 0;

		while (!sloturi[slot].empty()) {
			poz++;
			palet_crt = sloturi[slot].top();
			sloturi[slot].pop();
			temp.push_back(palet_crt);
			if (palet_crt.getIdProdus() == idProd) {
				break;
			}
		}

		//pune paletii la loc in slotul i dupa ce a efectuat cautarea
		for (int j = temp.size() - 2; j >= 0; --j) {
			sloturi[slot].push(temp[j]);
		}

		return palet_crt.getNrItems();
	}

	return -1;
}
