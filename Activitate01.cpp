#include <iostream>
#include <string>

using namespace std;

class Cofetarie {
private:
	const int id;
	string denumire;
	int nrProduse;
	float* preturi;

public:
	static int nrCofetarii;

	Cofetarie() : id(++nrCofetarii), denumire("Cofetarie generala"), nrProduse(0), preturi(nullptr) {
	}

	Cofetarie(int id, const string& denumire, int nrProduse, const float* preturi)
		: id(id), denumire(denumire), nrProduse(nrProduse), preturi(nullptr) {
		nrCofetarii++;

		if (this->nrProduse > 0 && preturi != nullptr) {
			this->preturi = new float[this->nrProduse];
			for (int i = 0; i < this->nrProduse; i++) {
				this->preturi[i] = preturi[i];
			}
		}
		else {
			this->nrProduse = 0;
		}
	}

	~Cofetarie() {
		delete[] preturi;
	}

	Cofetarie(const Cofetarie&) = delete;
	Cofetarie& operator=(const Cofetarie&) = delete;

	void afisare() const {
		cout << endl << "Id: " << id;
		cout << endl << "Denumire: " << denumire;
		cout << endl << "Nr. produse: " << nrProduse;

		if (nrProduse > 0) {
			cout << " cu urmatoarele preturi: ";
			for (int i = 0; i < nrProduse - 1; i++) {
				cout << preturi[i] << " lei, ";
			}
			cout << preturi[nrProduse - 1] << " lei.";
		}
	}
};

int Cofetarie::nrCofetarii = 0;

int main() {
	Cofetarie cofetarieGenerala;
	cofetarieGenerala.afisare();

	float preturi[] = { 18.5f, 24.0f, 15.5f };
	Cofetarie* cofetarieRomana = new Cofetarie(7, "CofetarieRomana", 3, preturi);
	cofetarieRomana->afisare();

	delete cofetarieRomana;

	cout << endl << "Numar cofetarii: " << Cofetarie::nrCofetarii;
	return 0;
}
