//
// Created by Nizar on 07/05/2024.
//

#ifndef PUISSANCE5_GRILLE_H
#define PUISSANCE5_GRILLE_H
#include <iostream>
#include <vector>
using namespace std;

class Grille {
private:
    string plateau[6][7];
    const int colonne = 7 ;
    const int ligne = 6 ;
public:
    Grille();
    Grille(Grille& g);
    int getColonne() const;
    int getLigne() const;
    string (&getPlateau() )[6][7];
    string getCase(int i, int j) const;
    void setPlateau(const std::string (&nouveauPlateau)[6][7]);
    void affiche() const;
    vector<int> dispo() const; // retourne les cases disponible pour jouer
    bool fin() const; // determine si la partie est fini
    Grille& operator=(const Grille& g);


};


#endif //PUISSANCE5_GRILLE_H
