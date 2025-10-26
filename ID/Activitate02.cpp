#include<iostream>

using namespace std;

class Fruct {
private:
	//const int idFruct;
	//numarFructe
	char* nume;
	string culoare;
	float greutate;
	int lunaMaturitate;
	int nrSeminte;
	float* greutatiSeminte;

public:
	void setGreutate(float greutate) {
		if (greutate > 0) {
			(*this).greutate = greutate;//-> inseamna dereferentiere+accesare
		}
	}

	float getGreutate() {
		return this->greutate;
	}

	char* getNume() {
		return this->nume;
	}

	void setNume(const char* nume) {
		if (strlen(nume) > 0) {
			if (this->nume != nullptr) {
				delete[]this->nume;
			}
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
	}

	void setCuloare(string culoare) {
		if (culoare.length() > 0) {
			this->culoare = culoare;
		}
	}

	void setGreutatiSeminte(int nrSeminte, float* greutatiSeminte) {
		if (nrSeminte > 0) {
			this->nrSeminte = nrSeminte;
			if (this->greutatiSeminte != nullptr) {
				delete[] this->greutatiSeminte;
			}
			this->greutatiSeminte = new float[nrSeminte];
			for (int i = 0; i < nrSeminte; i++) {
				this->greutatiSeminte[i] = greutatiSeminte[i];
			}
		}
	}

	float* getGreutatiSeminte() {
		return this->greutatiSeminte;
	}

	float getGreutateSamanta(int pozitie) {
		if (pozitie >= 0 && pozitie < nrSeminte) {
			return this->greutatiSeminte[pozitie];
		}
		return -1;//aruncam exceptie...atunci cand le invatam
	}

	Fruct() {
		this->culoare = "Rosu";
		this->greutate = 0.6;
		this->lunaMaturitate = 6;
		this->nrSeminte = 0;
		this->greutatiSeminte = nullptr;
		this->nume = nullptr;
	}

	Fruct(const char* nume, string culoare, float greutate, int lunaMaturitate, int nrSeminte, const float* greutatiSeminte) {
		this->culoare = culoare;
		this->greutate = greutate;
		this->lunaMaturitate = lunaMaturitate;
		this->nrSeminte = nrSeminte;

		this->greutatiSeminte = new float[nrSeminte];
		for (int i = 0; i < nrSeminte; i++) {
			this->greutatiSeminte[i] = greutatiSeminte[i];
		}
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}
};

void main() {
	Fruct fruct;
	cout << fruct.getGreutate() << endl << endl;
	Fruct f;
	Fruct para;

	fruct.setGreutate(2.5);
	fruct.setGreutate(-56);
	//cout << fruct.getGreutate();

	fruct.setNume("Mar");

	int seminte = 3;
	float* vector = new float[3] {0.1, 0.2, 0.3};
	fruct.setGreutatiSeminte(seminte, vector);

	cout << fruct.getGreutatiSeminte()[0]<<endl;
	cout << fruct.getGreutatiSeminte()[1] << endl;
	cout << fruct.getGreutatiSeminte()[2] << endl;

	cout << fruct.getGreutateSamanta(0) << endl;
	cout << fruct.getGreutatiSeminte()[1] << endl;
	cout << fruct.getGreutateSamanta(2) << endl;

	Fruct mar("Mar", "Galben", 0.4, 8, 3, vector);
	cout << mar.getNume();

	//discutie despre atribute constante
	//atribute statice
	//constructor de copiere
	// destructor
	//operator =(de atribuire)
	//alti operatori
}


