#include<iostream>
#include<string>

using namespace std;
enum Tip {BIO=7, DE_BAZA=3, NORMAL=5};

class ProdusAlimentar {
private:
	const int id;
	float pret;
	string denumire;
	Tip tip;
	int nrIngrediente;
	float* cantitati;
	static int nrProduseAlimentare;
public:
	//constructor default//fara parametri
	ProdusAlimentar() :id(++nrProduseAlimentare) {
		this->denumire = "Produs default";
		this->pret = 0;
		this->nrIngrediente = 0;
		this->cantitati = nullptr;
		this->tip = NORMAL;
	}

	ProdusAlimentar(string denumire, float pret, int nrIngrediente, float* cantitatiIngrediente, Tip tip) :id(++nrProduseAlimentare) {
		this->denumire = denumire;
		this->pret = pret;
		this->nrIngrediente = nrIngrediente;
		this->cantitati = new float[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->cantitati[i] = cantitatiIngrediente[i];
		}
		this->tip = tip;

		delete[] cantitatiIngrediente;
	}

	void afisareProdusAlimentar() {
		cout << endl << this->id << ". Produsul alimentar " << this->denumire << " costa " << this->pret << " lei, este de tipul ";
		if (this->tip == NORMAL) cout << "NORMAL";
		if (this->tip == BIO) cout << "BIO";
		if (this->tip == DE_BAZA) cout << "DE_BAZA";
		cout<< " si contine " << this->nrIngrediente << " ingrediente: ";
		if (this->cantitati != nullptr) {
			for (int i = 0; i < this->nrIngrediente - 1; i++) {
				cout << this->cantitati[i] << " grame, ";
			}
			cout << this->cantitati[this->nrIngrediente - 1] << " grame.";
		}
	}

	//get si set pentru nrIngrediente
	int getNrIngrediente() {
		return this->nrIngrediente;
	}

	void setNrIngrediente(int nrIngredienteNou) {
		if (nrIngredienteNou>0)
		{
			this->nrIngrediente = nrIngredienteNou;
		}
		else {
			//throw exception();
			//throw 404;
			throw "Valoare negativa";
		}
	}

	//get si set pentru pointeri
	float* getCantitati() {
		//return this->cantitati; - asa nu
		float* copieCantitati = new float[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			copieCantitati[i] = this->cantitati[i];
		}

		return copieCantitati;
	}

	void setCantitati(float* cantitatiNoi, int nrIngredienteNou) {
		setNrIngrediente(nrIngredienteNou);

		if (this->cantitati != nullptr) {
			delete[] this->cantitati;
		}
		this->cantitati = new float[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->cantitati[i] = cantitatiNoi[i];
		}

		delete[] cantitatiNoi;
	}

	~ProdusAlimentar() {
		if (this->cantitati != nullptr) {
			delete[] this->cantitati;
		}
	}
};

int ProdusAlimentar::nrProduseAlimentare = 0;

void main() {
	ProdusAlimentar pizza;
	//pizza.pret = 30;

	pizza.afisareProdusAlimentar();
	float* cantitati = new float[3] {100, 200, 300};
	ProdusAlimentar* sushi = new ProdusAlimentar("sushi", 100, 3, cantitati, BIO);

	sushi->afisareProdusAlimentar();
	try {
		sushi->setNrIngrediente(2);
	}
	catch (const char* mesaj) {
		cout << endl << mesaj;
	}
	catch (int cod) {
		cout << endl << cod;
	}
	catch (...) {
		cout << endl << "Valoare negativa sau 0!";
	}
	cout << endl << "Nr ingrediente nou: " << sushi->getNrIngrediente();

	sushi->setCantitati(new float[4] {200, 300, 400, 500}, 4);
	float* cantitatiActuale = sushi->getCantitati();
	for (int i = 0; i < sushi->getNrIngrediente(); i++) {
		cout << endl << "Cantitati[" << i << "]: " << cantitatiActuale[i];
	}

	delete[] cantitatiActuale;
	delete sushi;
}