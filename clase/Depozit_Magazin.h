#ifndef __DEPOZIT_MAGAZIN__
#define __DEPOZIT_MAGAZIN__

#ifndef __IOSTREAM__
#define __IOSTREAM__
#include <iostream>
#endif

#ifndef __STRING__
#define __STRING__
#include <string>
#endif

#include "ResizableArray.h"

class Depozit_Magazin {
	
	ResizableArray<Produs*> produse;
	ResizableArray<int> nr_produse;

 public:

	Depozit_Magazin();

	Depozit_Magazin(ResizableArray<Produs*> produse, ResizableArray<int> nr_produse) {
		this->produse = produse;
		this->nr_produse = nr_produse;
	};

	~Depozit_Magazin();

	int findProdus(string);
};

int findProdus(string id)
{
	int i, n = produse.size();
	for(i = 0; i < n; ++i)
	{
		if(produse[i] -> getId() == id) return i;
	}
	return -1;
}
#endif
