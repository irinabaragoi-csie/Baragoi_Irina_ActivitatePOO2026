
#include <iostream>
#include <string>
using namespace std;

class Colet {
    string cod;
    string destinatie;
    float greutate;
    float costTransport;

public:
    Colet() {
        this->cod = "Necunoscut";
        this->destinatie = "Nespecificata";
        this->greutate = 0;
        this->costTransport = 0;
    }

    Colet(string cod, string destinatie, float greutate, float costTransport) {
        this->cod = cod;
        this->destinatie = destinatie;
        this->greutate = greutate;
        this->costTransport = costTransport;
    }

    float getGreutate() const {
        return this->greutate;
    }

    Colet& operator+=(float kg) {
        if (kg > 0) {
            this->greutate += kg;
        }
        return *this;
    }

    bool operator>(const Colet& c) const {
        return this->greutate > c.greutate;
    }

    void afisare() const {
        cout << this->cod << " - " << this->destinatie
            << ", " << this->greutate << " kg, "
            << this->costTransport << " lei" << endl;
    }
};

int main() {
    Colet colet1("C101", "Brasov", 2.5f, 25);
    Colet colet2("C102", "Cluj", 4.0f, 35);
    Colet colet3;

    cout << "Constructor implicit: ";
    colet3.afisare();
    cout << "Colet initial: ";
    colet1.afisare();
    cout << "Mai greu decat colet2 (inainte): " << (colet1 > colet2) << endl;

    colet1 += 2.0f;
    cout << "Dupa adaugarea a 2 kg: ";
    colet1.afisare();
    cout << "Mai greu decat colet2 (dupa): " << (colet1 > colet2) << endl;

    colet1 += -1.0f;
    cout << "Greutate dupa valoare invalida: " << colet1.getGreutate() << endl;
    return 0;
}
