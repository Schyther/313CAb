#ifndef __MAGAZIN__
#define __MAGAZIN__

#ifndef __STRING__
#define __STRING__
#include <string>
#endif

#include "resizablearray.h"
#include "Depozit_Magazin.h"

class Magazin {
	string locatie;
	Depozit_Magazin depozit;
public:
	ResizableArray < string > zi[367]; // zi[ i ] contine bonurile vandute in ziua i
	Magazin() {
	    //depozit = new Depozit_Magazin;
	}

	Magazin(string locatie) {
		this->locatie = locatie;
        //depozit = new Depozit_Magazin;
	}

	Magazin(const Magazin& other) {
		this->locatie = other.locatie;
		for(int i = 1; i < 367; ++i)
            this->zi[i] = other.zi[i];
		this->depozit = other.depozit;
	}

	~Magazin() {
        // cout << depozit <<'\n';
        // cout << depozit -> getNProdus(1) << '\n';
        // delete depozit;
	}

	void setLocatie(string locatie) {
		this->locatie = locatie;
	}

	string getLocatie() {
		return locatie;
	}

	int findProdus(int id) {
		return depozit.findProdus(id);
	}

	int getNProdus(int id) {
		return depozit.getNProdus(id);
	}

/*	Depozit_Magazin& getDepozit() {
		return depozit;
	}*/

	void add_produs(Produs& produs, int cantitate) {
        int pos = depozit.findProdus(produs.getId());
        if(pos == -1) {
            depozit.addProdus(&produs, cantitate);
        }
        else {
            depozit.addProdus(pos, cantitate);
        }
	}

	void remove_produs(int id, int cantitate) {
		depozit.addProdus(id, -cantitate);
	}

	void add_bon(string id_bon, int zi) {
        this->zi[zi].push_back(id_bon);
	}
};
#endif
