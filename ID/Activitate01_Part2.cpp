#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

enum Combustibil { BENZINA = 1, DIESEL = 2, ELECTRIC = 3 };

class  Motocicleta {
public:
	char* marca = nullptr;
	string model = "Necunoscut";
	int nrKm = 0;
	Combustibil combustibil = BENZINA;

	void afisareMotocicleta() {
		cout << endl << "Motocicleta avand marca ";
		if (this->marca != nullptr) {
			cout << this->marca;
		}

		cout << ", model " << this->model << " are " << this->nrKm << " km, combustibilul fiind ";
		if (this->combustibil == 1) {
			cout << "BENZINA";
		}
		else if (this->combustibil == 2) {
			cout << "DIESEL";
		}
		else {
			"ELECTRIC";
		}

		cout << ".";
	}
};

void main() {

	Motocicleta moto1;

	moto1.marca = new char[strlen("Honda") + 1];
	strcpy(moto1.marca, "Honda");
	moto1.model = "CBR";
	moto1.nrKm = 10000;
	moto1.combustibil = DIESEL;

	moto1.afisareMotocicleta();
}