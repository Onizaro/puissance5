//
// Created by Nizar on 07/05/2024.
//

#ifndef PUISSANCE5_JOUEUR_H
#define PUISSANCE5_JOUEUR_H
#include <string>
#include "Grille.h"


using namespace std;

class Joueur {
private:
    string nom;
public:
    Joueur(const string& nom);
    string getNom() const;
    void jouer(int coup, string pion, Grille& grille);
    bool isdispo(int val, Grille& grille) const; //test si une valeur est disponible


};


#endif //PUISSANCE5_JOUEUR_H
