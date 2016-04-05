#include <iostream>
#include <fstream>
#include "List.h"

template <type T>
	class ResizableArray{

	};

	class Produs{

	};

class Depozit_Magazin{
	
	List<Produs*> tip_produs;
	ResizableArray nr_produse;

 public:

	Depozit_Magazin();

	Depozit_Magazin (List<Produs*> tip_produs, ResizableArray nr_produse){
		this->tip_produs = tip_produs;
		this->nr_produse = nr_produse;
	};

	~Depozit_Magazin();
};