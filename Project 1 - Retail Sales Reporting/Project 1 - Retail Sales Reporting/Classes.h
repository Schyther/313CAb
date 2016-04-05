#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Clasa de citires
class Read {

private:

	ifstream bonuri;
	ifstream categorii;
	ifstream magazine;
	ifstream paleti;
	ifstream produse;

public:

	void Bonuri(const char* name);
	void Produse(const char* fileName);
	void Paleti(const char* fileName);
	void Magazine(const char* fileName);
	void Categorii(const char* fileName);

	~Read();

};