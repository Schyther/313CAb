#include<iostream> //nu e versiunea buna, nu lucrati pe vesiunea asta
#include<string>

using namespace std;

class Palet {
private:
	string id_palet;
	string id_produs;
	int nr_itemi;
	int id_slot;

public:

	Palet() {

	}

	Palet(string id_palet, string id_produs, int nr_itemi, int id_slot) {
		this->id_palet = id_palet;
		this->id_produs = id_produs;
		this->nr_itemi = nr_itemi;
		this->id_slot = id_slot;
	}

	Palet(const Palet& x) {
		this->id_palet = x.id_palet;
		this->id_produs = x.id_produs;
		this->nr_itemi = x.nr_itemi;
		this->id_slot = x.nr_itemi;
	}

	~Palet() {
		this->id_palet = '\0';
		this->id_produs = '\0';
		this->nr_itemi = 0;
		this->id_slot = 0;
	}

	Palet& operator=(const Palet& x) {
		this->id_palet = x.id_palet;
		this->id_produs = x.id_produs;
		this->nr_itemi = x.nr_itemi;
		this->id_slot = x.id_slot;
		return *this;
	}

	string getIdPalet() {
		return id_palet;
	}

	string getIdProdus() {
		return id_produs;
	}

	int getNrItems() {
		return nr_itemi;
	}

	int getIdSlot() {
		return id_slot;
	}

	void setIdPalet(string id_nou) {
		this->id_palet = id_nou;
	}

	void setIdProdus(string id_nou) {
		this->id_produs = id_nou;
	}

	void setNrItems(int nr_nou) {
		this->nr_itemi = nr_nou;
	}

	void setIdSlot(int id_nou) {
		this->id_slot = id_nou;
	}




};

int main() {

	//test
	Palet* DEMON=new Palet("1","13",40,55);
	cout << DEMON->getIdPalet() << " " << DEMON->getIdProdus() << " " << DEMON->getIdSlot() << " " << DEMON->getNrItems() << endl;

	Palet *aux = new Palet("-1", "-1", -1, -1);
	DEMON = aux;
	cout << DEMON->getIdPalet() << " " << DEMON->getIdProdus() << " " << DEMON->getIdSlot() << " " << DEMON->getNrItems() << endl;

	DEMON->setIdPalet("10");
	cout << DEMON->getIdPalet() << endl;

	//l-am numit demon pentru ca facea ca posedatu la inceput..
	//test

	return 0;
}
