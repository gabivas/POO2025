#include<iostream>

using namespace std;

class Fruct {
private:
	const int idFruct;
	static int numarFructe;
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
		//throw exception();
		throw 404;
		//throw "Pozitie in afara intervalului vectorului!";
	}

	int getIdFruct() {
		return this->idFruct;
	}

	static int getNumarFructe() {
		return numarFructe;
	}

	void setNumarFructe(int nrFructe) {
		numarFructe = nrFructe;
	}

	Fruct() :idFruct(++numarFructe) {
		//this->idFruct = 1;
		this->culoare = "Rosu";
		this->greutate = 0.6;
		this->lunaMaturitate = 6;
		this->nrSeminte = 0;
		this->greutatiSeminte = nullptr;
		this->nume = nullptr;
	}

	Fruct(const char* nume, string culoare, float greutate, int lunaMaturitate, int nrSeminte, const float* greutatiSeminte) :idFruct(++numarFructe) {
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

	Fruct(const Fruct& copie) :idFruct(++numarFructe) {
		this->culoare = copie.culoare;
		this->greutate = copie.greutate;
		this->lunaMaturitate = copie.lunaMaturitate;
		this->nrSeminte = copie.nrSeminte;

		if (copie.greutatiSeminte != nullptr) {
			this->greutatiSeminte = new float[copie.nrSeminte];
			for (int i = 0; i < copie.nrSeminte; i++) {
				this->greutatiSeminte[i] = copie.greutatiSeminte[i];
			}
		}
		else {
			this->greutatiSeminte = nullptr;
		}

		if (copie.nume != nullptr) {
			this->nume = new char[strlen(copie.nume) + 1];
			strcpy_s(this->nume, strlen(copie.nume) + 1, copie.nume);
		}
		else {
			this->nume = nullptr;
		}
	}

	void operator=(const Fruct& copie) {
		this->culoare = copie.culoare;
		this->greutate = copie.greutate;
		this->lunaMaturitate = copie.lunaMaturitate;
		this->nrSeminte = copie.nrSeminte;

		if (this->greutatiSeminte != nullptr) {
			delete[] this->greutatiSeminte;
			this->greutatiSeminte = nullptr;
		}

		if (copie.greutatiSeminte != nullptr) {
			this->greutatiSeminte = new float[copie.nrSeminte];
			for (int i = 0; i < copie.nrSeminte; i++) {
				this->greutatiSeminte[i] = copie.greutatiSeminte[i];
			}
		}
		else {
			this->greutatiSeminte = nullptr;
		}

		if (this->nume != nullptr) {
			delete[] this->nume;
			this->nume = nullptr;
		}

		if (copie.nume != nullptr) {
			this->nume = new char[strlen(copie.nume) + 1];
			strcpy_s(this->nume, strlen(copie.nume) + 1, copie.nume);
		}
		else {
			this->nume = nullptr;
		}

		//return *this;
	}

	int getLunaMaturitate() {
		return this->lunaMaturitate;
	}

	string getCuloare() {
		return this->culoare;

	}

	int getNrSeminte() {
		return this->nrSeminte;
	}

	void afisareFruct() {
		cout << endl << this->getIdFruct() << ". Fructul ";
		if (this->getNume() != nullptr) {
			cout << this->getNume();
		}
		else
		{
			cout << "Neidentificat";
		}
		cout << ", are culoarea " << this->getCuloare() << " , greutatea este de "
			<< this->getGreutate() << " kg, a fost copt in luna a " <<
			this->getLunaMaturitate() << "-a. Contine " << this->getNrSeminte()
			<< " seminte";
		if (this->getNrSeminte() > 0) {
			cout << " cu urmatoarele greutati : ";
			for (int i = 0; i < this->getNrSeminte() - 1; i++) {
				cout << this->getGreutateSamanta(i) << ", ";
			}
			cout << this->getGreutateSamanta(this->getNrSeminte() - 1) << ".";
		}
	}

	~Fruct() {
		if (this->greutatiSeminte != nullptr) {
			delete[] this->greutatiSeminte;
		}
		if (this->nume != nullptr) {
			delete[] this->nume;
		}
	}

	void operator+=(float valoareDeAdaugatLaGreutate) {
		this->greutate += valoareDeAdaugatLaGreutate;
	}

	//Fruct operator+=(float valoareDeAdaugatLaGreutate, const Fruct& f) {
	//	f.greutate += valoareDeAdaugatLaGreutate;

	//	return *this;
	//}

	//comparatie intre 2 obiecte dupa un atribut => return bool
	bool operator<(const Fruct& f) {
		return this->greutate < f.greutate;
	}

	//operator negatie
	bool operator!() {
		return this->lunaMaturitate != 0;
	}

	//operatorul functie
	float operator()(int pozitie) {
		return this->getGreutateSamanta(pozitie);
	}
};

int Fruct::numarFructe = 0;

void main() {
	float* vector = new float[3] {0.1, 0.2, 0.3};
	Fruct fruct("Mar", "Galben", 0.4, 8, 3, vector);
	try {
		cout << endl << fruct.getGreutateSamanta(3);
	}
	catch (int cod) {
		cout << endl << cod;
	}
	catch (const char* mesaj) {
		cout << endl << mesaj;
	}
	catch (...) {
		cout<< endl << "Pozitia este in afara intervalului!";
	}
	cout<< endl<< "Id fruct bazat pe contructorul cu toti parametri: " << fruct.getIdFruct();

	//constr de copiere
	Fruct fruct2 = fruct;
	//Fruct fruct2(fruct);

	cout << endl << "Id fruct bazat pe contructorul de copiere: " << fruct2.getIdFruct();

	Fruct fructDefault;
	fructDefault.afisareFruct();
	//op =
	fructDefault = fruct;

	cout << endl << "Id fruct bazat dupa apelul op =: " << fructDefault.getIdFruct();
	
	fruct.afisareFruct();
	fruct2.afisareFruct();
	fructDefault.afisareFruct();

	fruct += 0.1;
	//0.1 += fruct;

	fruct.afisareFruct();

	if (fruct < fruct2) {
		cout << endl << "Primul fruct are greutatea mai mica decat al doilea fruct!";
	}
	else {
		cout << endl << "Al doilea fruct are greutatea mai mica decat primul fruct!";

	}

	if (!fruct) {
		cout << endl << "Fructul este copt!";
	}
	else {
		cout << endl << "Fructul este crud!";

	}

	cout << endl << fruct(2);

	cout << endl << "Am initializat " << Fruct::getNumarFructe() <<" obiect/e!";
}