#include<iostream>

using namespace std;

void afisareVector(int* vector, int dimensiune);

int pozitieMaximInVector(int* vector, int dimensiune) {
	int pozitieMax = 0;
	for (int i = 1; i < dimensiune; i++) {
		if (vector[pozitieMax] < vector[i]) {
			pozitieMax = i;
		}
	}
	return pozitieMax;
}

void stergereElementDePePozitieData(
	int** vector, int* dimensiune, int pozitie) {
	int* vectorCopie = new int[*dimensiune - 1];
	int j = 0;
	for (int i = 0; i < *dimensiune; i++) {
		if (i != pozitie) {
			vectorCopie[j] = (*vector)[i];
			j++;
		}

	}

	delete[] * vector;
	(*dimensiune)--;
	*vector = vectorCopie;
}

void main() {
	char* nume;
	char sirCaractere[20];

	//cout << endl << "Citim de la tastatura: ";
	//cin.getline(sirCaractere, 20);

	//cout << endl << "Sirul citit este: "<<sirCaractere;

	//definim un buffer
	//char buffer[20];
	//cout << endl << "Numele este: ";
	//cin >> buffer;

	//nume = new char[strlen(buffer)+1];
	//strcpy_s(nume, strlen(buffer) + 1, buffer);

	//cout << endl << "Numele citit este: " << nume;

	//delete[] nume;

	//vectori
	int* vector;
	int dimensiune = 5;

	vector = new int[dimensiune];
	for (int i = 0; i < dimensiune; i++) {
		cout << endl << "Vector[" << i << "]= ";
		cin >> vector[i];
	}

	cout << endl << "Valorile din vector sunt:";
	afisareVector(vector, dimensiune);

	cout << endl << "Pozitia pe care se afla maximul este: " << pozitieMaximInVector(vector, dimensiune);

	stergereElementDePePozitieData(&vector, &dimensiune, 3);

	afisareVector(vector, dimensiune);

}

void afisareVector(int* vector, int dimensiune) {
	for (int i = 0; i < dimensiune; i++) {
		cout << endl << "Vector[" << i << "]= " << vector[i];
	}
}