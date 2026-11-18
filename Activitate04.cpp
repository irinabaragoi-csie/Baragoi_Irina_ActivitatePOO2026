#include<iostream>
#include<string>

using namespace std;

class ExceptieCustom : public exception
{
public:
	ExceptieCustom(const char* mesaj) :exception(mesaj) {}
};

class Produs {
private:
	const int id;
	string denumire;
	float pret;
public:
	static const float PRET_MINIM;
	Produs() :id(0), denumire("Laptop"), pret(5000) {
	}

	Produs(int idP, string denumireP, float pretP) :id(idP), denumire(denumireP), pret(pretP) {
		if (pret < PRET_MINIM) {
			throw ExceptieCustom("Pretul este prea mic!");
		}
	}

	virtual void afisare() {
		cout << endl << "Id: " << this->id;
		cout << endl << "Denumire: " << this->denumire;
		cout << endl << "Pret: " << this->pret;
	}

	~Produs() {
	}

	virtual float getProcentReducere() = 0;

};

const float Produs::PRET_MINIM = 1;

class ProdusRedus : public Produs {
private:
	float procentReducere;
public:
	ProdusRedus() :Produs(), procentReducere(10) {}

	ProdusRedus(int id, string denumire, float pret, float procentReducere) :Produs(id, denumire, pret), procentReducere(procentReducere) {}

	void afisare() {
		this->Produs::afisare();
		cout << endl << "Procent reducere: " << this->procentReducere;
	}

	float getProcentReducere() {
		return this->procentReducere;
	}
};

class MathInterface {
public:
	virtual int adunare(int a, int b) = 0;
	virtual int scadere(int a, int b) = 0;
	virtual int inmultire(int a, int b) = 0;
	virtual int impartire(int a, int b) = 0;
};

class MathOperation : public MathInterface {
public:
	int adunare(int a, int b) {
		return a + b;
	}

	int scadere(int a, int b) {
		return a - b;
	}

	int inmultire(int a, int b) {
		return a * b;

	}

	int impartire(int a, int b) {
		if (b != 0) {
			return a / b;
		}
		else {
			throw ExceptieCustom("Nu putem avea impartire la 0!");
		}
	}
};

void main() {

	//try {
	//	Produs frigider(1, "Frigider", 0);
	//}
	//catch (ExceptieCustom e) {
	//	cout << endl << e.what();
	//}

	//Produs frigider(1, "Frigider", 5000);
	//frigider.afisare();

	//ProdusRedus laptop(2, "Laptop", 6000, 10);
	//laptop.afisare();

	Produs* vectorProduse[3];

	vectorProduse[0] = new ProdusRedus(1, "Paine", 2, 10);
	vectorProduse[1] = new ProdusRedus(2, "Peste", 15, 8);
	vectorProduse[2] = new ProdusRedus(3, "Portocale", 10, 12);

	for (int i = 0; i < 3; i++) {
		vectorProduse[i]->afisare();
		delete vectorProduse[i];
	}

	MathInterface* operation = new MathOperation();
	cout << endl << operation->adunare(1, 2);
}