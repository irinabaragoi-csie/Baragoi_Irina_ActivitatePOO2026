
#include <iostream>
#include <string>

using namespace std;

enum StadiuConstructie { Proiectare, InExecutie, InExploatare };

class Autostrada {
    string denumire;
    int nrTronsoane;
    int* kmPerTronson;
    bool iluminata;
    StadiuConstructie stadiuConstructie;
    float costIntretinerePerKm;
    const int idAutostrada;
    static int contor;

public:

    Autostrada() :idAutostrada(contor) {
        this->denumire = "Autostrada fara nume";
        this->nrTronsoane = 0;
        this->kmPerTronson = NULL;
        this->iluminata = false;
        this->stadiuConstructie = Proiectare;
        this->costIntretinerePerKm = 100.5f;
        contor++;
    }

    Autostrada(string denumire, int nrTronsoane, int* kmPerTronson)
        :idAutostrada(contor) {

        this->denumire = denumire;
        this->nrTronsoane = nrTronsoane;

        if (kmPerTronson != NULL) {
            this->kmPerTronson = new int[nrTronsoane];
            for (int i = 0; i < nrTronsoane; i++) {
                this->kmPerTronson[i] = kmPerTronson[i];
            }
        }
        else {
            this->kmPerTronson = NULL;
        }

        this->iluminata = false;
        this->stadiuConstructie = Proiectare;
        this->costIntretinerePerKm = 100.5f;
        contor++;
    }

    Autostrada(string denumire,
        int nrTronsoane,
        int* kmPerTronson,
        bool iluminata,
        StadiuConstructie stadiuConstructie,
        float costIntretinerePerKm) :idAutostrada(contor) {

        this->denumire = denumire;
        this->nrTronsoane = nrTronsoane;

        if (kmPerTronson != NULL) {
            this->kmPerTronson = new int[nrTronsoane];
            for (int i = 0; i < nrTronsoane; i++) {
                this->kmPerTronson[i] = kmPerTronson[i];
            }
        }
        else {
            this->kmPerTronson = NULL;
        }

        this->iluminata = iluminata;
        this->stadiuConstructie = stadiuConstructie;
        this->costIntretinerePerKm = costIntretinerePerKm;
        contor++;
    }

    Autostrada(const Autostrada& a) :idAutostrada(contor) {
        this->denumire = a.denumire;
        this->nrTronsoane = a.nrTronsoane;

        if (a.kmPerTronson != NULL) {
            this->kmPerTronson = new int[a.nrTronsoane];
            for (int i = 0; i < a.nrTronsoane; i++) {
                this->kmPerTronson[i] = a.kmPerTronson[i];
            }
        }
        else {
            this->kmPerTronson = NULL;
        }

        this->iluminata = a.iluminata;
        this->stadiuConstructie = a.stadiuConstructie;
        this->costIntretinerePerKm = a.costIntretinerePerKm;
        contor++;
    }

    Autostrada& operator=(const Autostrada& a) {
        if (this != &a) {
            this->denumire = a.denumire;
            this->nrTronsoane = a.nrTronsoane;

            if (this->kmPerTronson != NULL) {
                delete[] this->kmPerTronson;
            }

            if (a.kmPerTronson != NULL) {
                this->kmPerTronson = new int[a.nrTronsoane];
                for (int i = 0; i < a.nrTronsoane; i++) {
                    this->kmPerTronson[i] = a.kmPerTronson[i];
                }
            }
            else {
                this->kmPerTronson = NULL;
            }

            this->iluminata = a.iluminata;
            this->stadiuConstructie = a.stadiuConstructie;
            this->costIntretinerePerKm = a.costIntretinerePerKm;
        }
        return *this;
    }

    ~Autostrada() {
        if (this->kmPerTronson != NULL) {
            delete[] this->kmPerTronson;
        }
    }

    const int getIdAutostrada() const {
        return this->idAutostrada;
    }

    int getNrTronsoane() const {
        return this->nrTronsoane;
    }

    void setKmPerTronson(int nrTronsoane, const int* km) {
        if (nrTronsoane > 0 && km != NULL) {
            int* kmNoi = new int[nrTronsoane];

            for (int i = 0; i < nrTronsoane; i++) {
                kmNoi[i] = km[i];
            }

            delete[] this->kmPerTronson;
            this->kmPerTronson = kmNoi;
            this->nrTronsoane = nrTronsoane;
        }
    }

    int getKmDePeTronsonDat(int tronson) const {
        if (tronson >= 0 && tronson < this->nrTronsoane
            && this->kmPerTronson != NULL) {
            return this->kmPerTronson[tronson];
        }
        else {
            return 0;
        }
    }

    int* getKmPerTronson() const {
        return this->kmPerTronson;
    }

    static int getContor() {
        return contor;
    }

};

int Autostrada::contor = 100;

int main() {

    Autostrada autostrada1;

    int* temp = new int[3] {60, 45, 30};
    Autostrada autostrada2("A1", 3, temp, true, InExploatare, 180.5f);

    int nrTronsoaneA3 = 4;
    int* kmTronsoaneA3 = new int[nrTronsoaneA3];

    for (int i = 0; i < nrTronsoaneA3; i++) {
        kmTronsoaneA3[i] = 40 - 5 * i;
    }

    Autostrada autostrada3("A3", nrTronsoaneA3, kmTronsoaneA3);

    cout << autostrada3.getKmDePeTronsonDat(1) << endl;
    cout << autostrada3.getKmPerTronson()[1] << endl;

    cout << autostrada3.getContor() << endl;

    autostrada2 = autostrada3;

    cout << Autostrada::getContor() << endl;

    delete[] kmTronsoaneA3;
    delete[] temp;

    return 0;
}
