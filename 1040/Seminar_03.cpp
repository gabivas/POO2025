#include<iostream>
#include<string>

using namespace std;

class ProdusAlimentar {
private:
	const int id;
	float pret;
	string denumire;
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
	}

	ProdusAlimentar(string denumire, float pret, int nrIngrediente, float* cantitatiIngrediente) :id(++nrProduseAlimentare) {
		this->denumire = denumire;
		this->pret = pret;
		this->nrIngrediente = nrIngrediente;
		this->cantitati = new float[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->cantitati[i] = cantitatiIngrediente[i];
		}

		delete[] cantitatiIngrediente;
	}

	void afisareProdusAlimentar() {
		cout <<endl<< this->id << ". Produsul alimentar " << this->denumire << " costa " << this->pret << " lei, contine " << this->nrIngrediente << " ingrediente: ";
		if (this->cantitati != nullptr) {
			for (int i = 0; i < this->nrIngrediente-1; i++) {
				cout << this->cantitati[i] << " grame, ";
			}
			cout << this->cantitati[this->nrIngrediente - 1] << " grame.";
		}
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
	ProdusAlimentar* sushi = new ProdusAlimentar("sushi", 100, 3, cantitati);

	sushi->afisareProdusAlimentar();

	delete sushi;
}