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

	void Read::Bonuri();

	~Read();

};