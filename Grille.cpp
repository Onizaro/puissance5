//
// Created by Nizar on 07/05/2024.
//

#include "Grille.h"
Grille::Grille (){
    for (int i = 0 ; i < 6 ; i++){
        for (int j = 0 ; j < 7 ; j++){
            this->plateau[i][j]="-";
        }
    }
}

Grille::Grille(Grille& g){
    for (int i = 0 ; i < 6 ; i++){
        for (int j = 0 ; j < 7 ; j++){
            this->plateau[i][j]=g.getCase(i,j);
        }
    }
}

int Grille::getColonne() const {return this->colonne;}

int Grille::getLigne() const {return this->ligne;}

void Grille::setPlateau(const string (&nouveauPlateau)[6][7]) {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            plateau[i][j] = nouveauPlateau[i][j];
        }
    }
}

string (&Grille::getPlateau())[6][7] {return plateau;}

string Grille::getCase(int i, int j) const {
    if (i >= 0 && i < ligne && j >= 0 && j < colonne) {return plateau[i][j];}
    else {return "";}
}

void Grille::affiche() const{
    cout << endl;
    for (int i = 0 ; i < 7 ; i++) {
        cout << i+1 << "\t";
    }
    cout << "\n\n";
    for (int i = 0 ; i < 6 ; i++){
        for (int j = 0 ; j < 7 ; j++){
            cout << this->plateau[i][j] << "\t";
        }
        cout << endl;
    }
}

vector<int> Grille::dispo() const{
    vector<int> rep;
    for (int i=0 ; i < 7 ; i++){
        if (this->plateau[0][i]=="-"){rep.push_back(i);}
    }
    return rep;
}

bool Grille::fin() const{
    bool rep(false);
    for (int i = 0 ; i < 6 ; i++){
        for (int j = 0 ; j < 7 ; j++){
            if (plateau[i][j] != "-" && j <= 2 &&
                plateau[i][j] == plateau[i][j+1] && // lignes horizontales
                plateau[i][j] == plateau[i][j+2] &&
                plateau[i][j] == plateau[i][j+3] &&
                plateau[i][j] == plateau[i][j+4]) {
                rep = true;
            }
            if (plateau[i][j] != "-" && i <= 1 &&
                plateau[i][j] == plateau[i+1][j] && // lignes verticales
                plateau[i][j] == plateau[i+2][j] &&
                plateau[i][j] == plateau[i+3][j] &&
                plateau[i][j] == plateau[i+4][j]) {
                rep = true;
            }
            if (plateau[i][j] != "-" && i <= 1 && j <= 2 &&
                plateau[i][j] == plateau[i+1][j+1] && // diagonales montantes
                plateau[i][j] == plateau[i+2][j+2] &&
                plateau[i][j] == plateau[i+3][j+3] &&
                plateau[i][j] == plateau[i+4][j+4]) {
                rep = true;
            }
            if (plateau[i][j] != "-" && i >= 4 && j <= 2 &&
                plateau[i][j] == plateau[i-1][j+1] && // diagonales descendantes
                plateau[i][j] == plateau[i-2][j+2] &&
                plateau[i][j] == plateau[i-3][j+3] &&
                plateau[i][j] == plateau[i-4][j+4]) {
                rep = true;
            }

        }

    }
    return rep;
}

Grille& Grille::operator=(const Grille& g) {
    for (int i = 0; i < ligne; ++i) {
        for (int j = 0; j < colonne; ++j) {
            this->plateau[i][j] = g.plateau[i][j];
        }
    }
    return *this;
}

