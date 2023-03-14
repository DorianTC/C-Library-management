#include <iostream>
#include <string>
using namespace std;

struct Carte {     //Am creat structura  de carte pentru a grupa  toate criterile de introducere si afisare a cartilor. Acestea au tipuri de date diferitr
    int id;
    int codid;
    string autor;
    string nume;
    int anpublicatie;
};

void adaugaCarte(Carte* biblioteca[], int size) {
    Carte* carteNoua = new Carte;
    cout << "Id-ul: ";
    cin >> carteNoua->id;
    cout << "Cod identificare: ";
    cin >> carteNoua->codid;
    cout << "Autor: ";
    cin.ignore();  //Am folosit aceasta linie de cod pentru a ne asigura ca prin urmatorul apel getline compilatorul citeste intrarea dorita 
    getline(cin, carteNoua->autor); 
    cout << "Nume: ";
    getline(cin, carteNoua->nume);
    cout << "An publicatie: ";
    cin >> carteNoua->anpublicatie;
    int contor = 0;
    while (contor < size && biblioteca[contor] != NULL) {
        contor++;
    }
    if (contor < size) {
        biblioteca[contor] = carteNoua;
    }
    else {
        delete carteNoua;
        cout << "Biblioteca este plina!\n";
    }
}

void listareCarte(Carte* biblioteca[], int size) {
    for (int i = 0; i < size; i++) {
        if (biblioteca[i] != NULL) {
            cout << biblioteca[i]->codid << " " << biblioteca[i]->id << " " << biblioteca[i]->autor << " " << biblioteca[i]->nume << " " << biblioteca[i]->anpublicatie << endl;

        }
    }
}

void eliminareCarte(Carte* biblioteca[], int size) {   //Am creat aceasta functie pentru a ne asigura ca avem spatiu de memorie libera deoarece
    for (int i = 0; i < size; i++) {                   //prin folosirea pointerilor avem nevoie de a aloca memorie in mod dinamic. 
        if (biblioteca[i] != NULL) {
            delete biblioteca[i];
            biblioteca[i] = NULL;
        }
    }
}

int main() {
    const int size = 2;
    Carte* biblioteca[size];    //Am creat un array de pointeri pentru a crea o variabila care stocheaza adresa fiecarui element introdus in mod dinamic
    for (int i = 0; i < size; i++) {
        biblioteca[i] = NULL;
    }
    adaugaCarte(biblioteca, size);
    adaugaCarte(biblioteca, size);
    listareCarte(biblioteca, size);
    eliminareCarte(biblioteca, size);
    return 0;
}
