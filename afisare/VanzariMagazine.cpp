//m-am bazat pe codul din app-urile cursului 3
#include <fstream>
#include <string>
#include "ResizableArray.h"

using namespace std;

class Magazin {
	string nume;
	int sales;
	
  public:	
  	Magazin() {
  		this->nume = "";
  		this->sales = 0;
   	}

	Magazin(string nume, int sales) {
		this->nume = nume;
		this->sales = sales;
		
	}

	friend std::ostream& operator<< (std::ostream& out, const Magazin& z);
};

ostream& operator<<(ostream& out, const Magazin& z){
	out << "['" << z.nume << "', " << z.sales << "]\n";
	return out;
}

void copyFile(ifstream& input, ofstream& output){
	string buffer;
	while (getline(input, buffer)) {
	    output << buffer << '\n';
	}
}

int main() {

	ifstream header;
	ifstream footer;
	ofstream chart;

	header.open("VanzariMagazineHeader.htm");
	footer.open("VanzariMagazineFooter.htm");
	chart.open("chart.html");

	copyFile(header, chart);

	ResizableArray<Magazin> ra = ResizableArray<Magazin>(10);
	ra.push_back(Magazin("Magazinul1", 100));
	ra.push_back(Magazin("Magazinul2", 200));
	ra.push_back(Magazin("Magazinul3", 210));
	ra.push_back(Magazin("Magazinul4", 300));
	ra.push_back(Magazin("Magazinul5", 400));
	ra.push_back(Magazin("Magazinul6", 500));
	ra.push_back(Magazin("Magazinul7", 600));
	ra.push_back(Magazin("Magazinul8", 700));
	ra.push_back(Magazin("Magazinul9", 800));
	for (int i=0; i<ra.getSize(); i++)
		chart<<ra[i]<<","<<endl;

	copyFile(footer, chart);

	return 0;
}