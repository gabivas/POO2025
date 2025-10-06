#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

struct Masina
{
	char* marca;
	char* culoare;
	int anulFabricatiei;
};

void afisareMasina(Masina masina) {
	cout << endl << "Masina " << masina.marca << " este de culoare " << masina.culoare << " si a fost fabricata in anul " << masina.anulFabricatiei <<".";
}

float mediaNumere() {
	float medie = 0.0f;
	int suma = 0; 
	int dimensiune = 5;
	int numereIntregi[] = {22, 19, 5, 28, 49};
	for (int i = 0; i < dimensiune; i++) {
		/*suma = suma + numereIntregi[i];*/
		suma += numereIntregi[i];
	}
	medie = suma / dimensiune;
	return medie;
}

void main() {
	cout << endl << "Mesaj la consola!";

	Masina masina;
	masina.anulFabricatiei = 2021;
	masina.marca = new char[strlen("Ford") + 1];
	strcpy(masina.marca, "Ford");
	masina.culoare = new char[strlen("Albastru") + 1];
	strcpy(masina.culoare, "Albastru");

	afisareMasina(masina);

	cout << endl << "Media este: " << mediaNumere();

	//dezalocari
	delete[] masina.marca;
	delete[] masina.culoare;
}