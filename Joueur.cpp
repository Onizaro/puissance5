//
// Created by Nizar on 07/05/2024.
//

#include "Joueur.h"

Joueur::Joueur(const std::string &nom) {
    this->nom = nom;
}

string Joueur::getNom() const {return this->nom;}

void Joueur::jouer(int coup, string pion, Grille& grille) {
    bool coupDispo(false);
    for (int i:grille.dispo()){
        if (coup == i){
            coupDispo = true;
            break;
        }
    }
    if (coupDispo){
        bool aJoue(false);
        auto &plateau = grille.getPlateau();
        for (int i = 5 ; i >=0 ; i--){
            if (!aJoue && plateau[i][coup]=="-"){
                plateau[i][coup] = pion;
                aJoue = true;
                grille.setPlateau(plateau);
                break;
            }
        }

    }
}

bool Joueur::isdispo(int val, Grille& grille) const{
    for (int i:grille.dispo()){
        if (i==val){
            return true;
        }
    }
    return false;
}