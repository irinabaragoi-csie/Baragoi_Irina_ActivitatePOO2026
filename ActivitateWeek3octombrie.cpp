#include <iostream>
#include <string>

using namespace std;

class Muzeu {
private:
    const int id;
    string denumire;
    int nrExponate;
    float* valoriExponate;

public:
    static int nrMuzee;

    // Constructor fara parametri:
    Muzeu() : id(++nrMuzee), denumire("Muzeu general"), nrExponate(0), valoriExponate(nullptr) {
    }

    // Constructor cu parametri:
    Muzeu(int id, const string& denumire, int nrExponate, const float* valori)
        : id(id), denumire(denumire), nrExponate(0), valoriExponate(nullptr) {
        nrMuzee++;

        if (nrExponate > 0 && valori != nullptr) {
            this->nrExponate = nrExponate;
            this->valoriExponate = new float[nrExponate];
            for (int i = 0; i < nrExponate; i++) {
                this->valoriExponate[i] = valori[i];
            }
        }
    }


    // Constructor de copiere, cu alocare separata a vectorului:
    Muzeu(const Muzeu& altMuzeu)
        : id(altMuzeu.id), denumire(altMuzeu.denumire),
        nrExponate(altMuzeu.nrExponate), valoriExponate(nullptr) {
        nrMuzee++;
        if (nrExponate > 0) {
            valoriExponate = new float[nrExponate];
            for (int i = 0; i < nrExponate; i++) {
                valoriExponate[i] = altMuzeu.valoriExponate[i];
            }
        }
    }

    // Destructor:
    ~Muzeu() {
        delete[] valoriExponate;
    }

    // Getteri & setteri:
    string getDenumire() const {
        return denumire;
    }

    int getNrExponate() const {
        return nrExponate;
    }

    void setDenumire(const string& denumireNoua) {
        if (!denumireNoua.empty()) {
            this->denumire = denumireNoua;
        }
    }

    // Atribuirea nu este permisa, id este un atribut const:
    Muzeu& operator=(const Muzeu&) = delete;

    void afisare() const {
        cout << "\nId: " << id;
        cout << "\nDenumire: " << denumire;
        cout << "\nNr. exponate: " << nrExponate;

        if (nrExponate > 0) {
            cout << "\nValori estimate ale exponatelor: ";
            for (int i = 0; i < nrExponate; i++) {
                cout << valoriExponate[i] << " lei";
                if (i < nrExponate - 1) {
                    cout << ", ";
                }
            }
        }
        cout << "\n";
    }
};

int Muzeu::nrMuzee = 0;

int main() {
    Muzeu muzeuGeneral;
    muzeuGeneral.afisare();

    float valori[] = { 1500.0f, 3200.5f, 9800.0f };
    Muzeu* muzeuArta = new Muzeu(7, "Muzeu de Arta Contemporana", 3, valori);
    muzeuArta->afisare();

    cout << "\nDenumirea muzeului: " << muzeuArta->getDenumire();
    cout << "\nNumar de exponate: " << muzeuArta->getNrExponate() << "\n";

    muzeuArta->setDenumire("Muzeu de Arta Moderna si Contemporana");
    muzeuArta->afisare();

    Muzeu muzeuCopie(*muzeuArta);
    muzeuCopie.afisare();

    delete muzeuArta;

    cout << "\nNumar total de muzee create: " << Muzeu::nrMuzee << "\n";
    return 0;
}
