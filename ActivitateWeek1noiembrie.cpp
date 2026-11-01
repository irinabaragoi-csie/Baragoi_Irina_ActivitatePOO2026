#include<iostream>
#include<string>

using namespace std;

enum Zona { CENTRALA = 1, PERIFERICA = 2 };

class Muzeu {
private:
	const int id;
	Zona zona;
	string denumire;
	float incasariTotale;
	int nrExponate;
	float* valoriExponate;
public:
	static int nrMuzee;
	Muzeu() :id(++nrMuzee) {
		//this->id = 0;
		this->denumire = "Muzeu general";
		this->incasariTotale = 0;
		this->zona = PERIFERICA;
		this->nrExponate = 0;
		this->valoriExponate = nullptr;
	}

	Muzeu(int id, string denumire, float incasariTotale, int nrExponate, float* valoriExponate, Zona zona) :id(id) {
		//this->id = 0;
		nrMuzee++;
		this->denumire = denumire;
		this->incasariTotale = incasariTotale;
		this->zona = zona;
		this->nrExponate = nrExponate;
		this->valoriExponate = new float[nrExponate];
		for (int i = 0; i < this->nrExponate; i++)
		{
			this->valoriExponate[i] = valoriExponate[i];
		}
		delete[] valoriExponate;
	}

	Muzeu(const Muzeu& copie) :id(++nrMuzee) {
		this->denumire = copie.denumire;
		this->nrExponate = copie.nrExponate;
		this->incasariTotale = copie.incasariTotale;
		this->zona = copie.zona;

		if (copie.valoriExponate != nullptr) {
			this->valoriExponate = new float[this->nrExponate];
			for (int i = 0; i < this->nrExponate; i++)
			{
				this->valoriExponate[i] = copie.valoriExponate[i];
			}
		}
		else {
			this->valoriExponate = nullptr;
		}

	}

	void operator=(const Muzeu& copie) {
		this->denumire = copie.denumire;
		this->nrExponate = copie.nrExponate;
		this->incasariTotale = copie.incasariTotale;
		this->zona = copie.zona;

		if (this->valoriExponate != nullptr) {
			delete[] this->valoriExponate;
			this->valoriExponate = nullptr;
		}

		if (copie.valoriExponate != nullptr) {
			this->valoriExponate = new float[this->nrExponate];
			for (int i = 0; i < this->nrExponate; i++)
			{
				this->valoriExponate[i] = copie.valoriExponate[i];
			}
		}
		else {
			this->valoriExponate = nullptr;
		}

	}

	//get si set pentru nrExponate
	int getNrExponate() {
		return this->nrExponate;
	}

	void setNrExponate(int valoareNoua) {
		if (valoareNoua >= 0) {
			this->nrExponate = valoareNoua;
		}
		else {
			throw exception();
			//throw 404;
			//throw "Valoare negativa!";
		}
	}

	//get si set pentru valoriExponate
	float* getValoriExponate() {
		//return this->valoriExponate;
		float* vValori = new float[this->nrExponate];
		for (int i = 0; i < this->nrExponate; i++)
		{
			vValori[i] = this->valoriExponate[i];
		}
		return vValori;
	}

	void setValoriExponate(float* vValori, int dim) {
		setNrExponate(dim);

		if (this->valoriExponate != nullptr) {
			delete[] this->valoriExponate;
			this->valoriExponate = nullptr;
		}

		if (vValori != nullptr) {
			this->valoriExponate = new float[this->nrExponate];
			for (int i = 0; i < this->nrExponate; i++)
			{
				this->valoriExponate[i] = vValori[i];
			}

			delete[] vValori;
		}
		else {
			this->valoriExponate = nullptr;
		}
	}

	void afisare() {
		cout << endl << "Id: " << this->id;
		cout << endl << "Denumire: " << this->denumire;
		cout << endl << "Incasari totale: " << this->incasariTotale;
		cout << endl << "Zona: ";
		if (this->zona == 1) {
			cout << "CENTRALA";
		}
		else {
			cout << "PERIFERICA";

		}
		cout << endl << "Nr. exponate: " << this->nrExponate;
		if (this->nrExponate > 0) {
			cout << " cu urmatoarele valori ale exponatelor: ";
			for (int i = 0; i < this->nrExponate - 1; i++)
			{
				cout << this->valoriExponate[i] << " lei, ";
			}
			cout << this->valoriExponate[this->nrExponate - 1] << " lei.";
		}
	}

	bool operator<(const Muzeu& c) {
		return this->nrExponate < c.nrExponate;
	}

	~Muzeu() {
		cout << endl << "S-a apelat destructorul!";
		if (this->valoriExponate != nullptr) {
			delete[] this->valoriExponate;
		}
	}

	void operator+=(float incasariTotaleDeAdunat) {
		this->incasariTotale += incasariTotaleDeAdunat;
	}

	//operatorul negatie
	bool operator!() {
		return this->incasariTotale > 0;
	}

	//operatorul functie
	float operator()(float valoareDeAdaugat)
	{
		return this->incasariTotale + valoareDeAdaugat;
	}

	//operatorul index
	float& operator[](int index) {
		if (index >= 0 && index < this->nrExponate) {
			return this->valoriExponate[index];
		}
		else {
			throw exception();
		}
	}

	//operator << / operator de afisare
	friend void operator<<(ostream& out, Muzeu c) {
		out << endl << "Operator de afisare: ";
		out << endl << "Id: " << c.id;
		out << endl << "Denumire: " << c.denumire;
		out << endl << "Incasari totale: " << c.incasariTotale;
		out << endl << "Zona: ";
		if (c.zona == CENTRALA) out << "CENTRALA";
		if (c.zona == PERIFERICA) out << "PERIFERICA";
		out << endl << "Nr exponate: " << c.nrExponate;
		if (c.valoriExponate != nullptr) {
			out << endl << "Valori exponate: ";
			for (int i = 0; i < c.nrExponate - 1; i++) {
				out << c.valoriExponate[i] << " lei, ";
			}
			out << c.valoriExponate[c.nrExponate - 1] << " lei.";
		}
	}

	friend void operator>>(istream& in, Muzeu& c);

	//postincrementare ob++
	Muzeu operator++(int) {
		Muzeu copie = *this;
		this->incasariTotale++;

		return copie;
	}

	//preincrementare ++ob
	Muzeu operator++() {
		this->incasariTotale++;
		return *this;
	}

	//cast explicit
	explicit operator int() {
		return this->nrExponate;
	}
};

void operator>>(istream& in, Muzeu& c) {
	cout << endl << "Incasari totale: ";
	in >> c.incasariTotale;

	cout << endl << "Denumire: ";
	in >> c.denumire;

	cout << endl << "Zona: ";
	int zona;
	in >> zona;

	if (zona == 1) c.zona = CENTRALA;
	if (zona == 2) c.zona = PERIFERICA;

	cout << endl << "Nr exponate: ";
	in >> c.nrExponate;

	cout << endl << "Valori exponate: ";

	if (c.valoriExponate != nullptr) {
		delete[] c.valoriExponate;
		c.valoriExponate = nullptr;
	}

	c.valoriExponate = new float[c.nrExponate];
	for (int i = 0; i < c.nrExponate; i++) {
		cout << endl << "valoriExponate[" << i << "]: ";
		in >> c.valoriExponate[i];
	}
}

int Muzeu::nrMuzee = 0;

int main() {
	Muzeu muzeuGeneral;

	if (!muzeuGeneral) {
		cout << endl << "Incasarile totale sunt pozitive!";
	}
	else {
		cout << endl << "Nu exista incasari!";
	}

	cout << endl << muzeuGeneral(100);

	cout << muzeuGeneral;

	float* valoriExponate = new float[3] {1500, 3200.5, 9800};
	Muzeu* muzeuArta = new Muzeu(7, "Muzeu de Arta Contemporana", 97000, 3, valoriExponate, CENTRALA);
	(*muzeuArta) += 100;

	if (muzeuGeneral < *muzeuArta) {
		cout << endl << "Muzeul General are mai putine exponate decat Muzeul de Arta!";
	}
	else {
		cout << endl << "Muzeul de Arta are mai putine exponate decat Muzeul General!";
	}

	(*muzeuArta)[0] = 1700;

	cout << endl << (*muzeuArta)[0];

	cout << *muzeuArta;

	//Muzeu muzeuNou;
	//cin >> muzeuNou;
	//cout << muzeuNou;

	Muzeu muzeu1 = muzeuGeneral++;

	cout << muzeu1;
	cout << muzeuGeneral;

	Muzeu muzeu2 = ++muzeuGeneral;

	cout << muzeu2;
	cout << muzeuGeneral;

	cout << endl << "Cast muzeu -> int: " << int(*muzeuArta);

	delete muzeuArta;

	cout << endl << "Numar muzee: " << Muzeu::nrMuzee;
	return 0;
}