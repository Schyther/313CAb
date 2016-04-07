#include <iostream>

using namespace std;

template <class T>
class ResizableArray {
	T *array;
	int capacity;
	int size;
 
  public:

  	int getSize() {
  		return size;
  	}

	// Metoda de initializare
	ResizableArray(int capacity) {
		this->capacity = capacity;
		this->size = 0;
		this->array = new T[ capacity ];
	}


	//TODO: consider rule of three
	~ResizableArray() {
		delete[] array;
	}

	//TODO: consider that subscript operators usually come in pairs 
	T& operator[] (const int index) {
		if (index<0 || index>size-1) {
			cout<<"Out of bounds"<<endl;
			return array[0];
		}
		return array[index];
	}

	void push_back(T value) {
		// Verific daca vectorul intern este plin
		if (size == capacity) {
			// Voi face o realocare. La final copiez elementele in noul vectorl
	 
			// Aloc un nou vector de dimensiune dubla.
			T *tmpArray = new T[ 2*capacity ];
	 
			// Copiez elementele in noul vector
			for ( int i = 0; i < size; ++i ) {
				tmpArray[ i ] = array[ i ];
			}
	 
			// Eliberez memoria ocupata de vechiul vector.
			delete[] array;
	 
			// Salvez vectorul nou format, care are capacitate dubla.
			array = tmpArray;
			capacity = 2 * capacity;
		}
	 
		// Adaug elementul la finalul vectorului
		// Pozitia noului element este size;
		array[ size ] = value;
		size++; // urmatorul element adaugat va fi adaugat la o urmatoarea pozitie
	}
};
