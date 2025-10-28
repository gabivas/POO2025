#include<iostream>
#include<string>

using namespace std;
enum Tip { BIO = 7, DE_BAZA = 3, NORMAL = 5 };

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

	ProdusAlimentar(const ProdusAlimentar& copie) :id(++nrProduseAlimentare){
		this->pret = copie.pret;
		this->denumire = copie.denumire;
		this->tip = copie.tip;
		this->nrIngrediente = copie.nrIngrediente;

		if (copie.cantitati != nullptr) {
			this->cantitati = new float[copie.nrIngrediente];
			for (int i = 0; i < copie.nrIngrediente; i++) {
				this->cantitati[i] = copie.cantitati[i];
			}
		}
		else {
			this->cantitati = nullptr;
		}
	}

	void operator=(const ProdusAlimentar& copie){
		this->denumire = copie.denumire;
		this->pret = copie.pret;
		this->tip = copie.tip;
		this->nrIngrediente = copie.nrIngrediente;

		if (this->cantitati != nullptr) {
			delete[] this->cantitati;
			this->cantitati = nullptr;
		}

		if (copie.cantitati != nullptr) {
			this->cantitati = new float[copie.nrIngrediente];
			for (int i = 0; i < copie.nrIngrediente; i++) {
				this->cantitati[i] = copie.cantitati[i];
			}
		}
		else {
			this->cantitati = nullptr;
		}
		//return *this;
	}

	void afisareProdusAlimentar() {
		cout << endl << this->id << ". Produsul alimentar " << this->denumire << " costa " << this->pret << " lei, este de tipul ";
		if (this->tip == NORMAL) cout << "NORMAL";
		if (this->tip == BIO) cout << "BIO";
		if (this->tip == DE_BAZA) cout << "DE_BAZA";
		cout << " si contine " << this->nrIngrediente << " ingrediente: ";
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
		if (nrIngredienteNou > 0)
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

	void operator+=(float pretDeAdunat) {
		this->pret += pretDeAdunat;
	}

	bool operator>(const ProdusAlimentar& pa) {
		return this->pret > pa.pret;
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

	//ProdusAlimentar produs = *sushi;
	ProdusAlimentar produs(*sushi);
	produs.afisareProdusAlimentar();

	pizza = *sushi;
	pizza.afisareProdusAlimentar();

	pizza += 7;

	pizza.afisareProdusAlimentar();

	if (produs > pizza) {
		cout << endl << " Produsul sushi are pretul mai mare!";
	}
	else {
		cout << endl << " Produsul pizza are pretul mai mare!";
	}

	delete sushi;
}