//
// Created by Nizar on 08/05/2024.
//

#ifndef PUISSANCE5_IA_H
#define PUISSANCE5_IA_H
#include "Grille.h"
#include "Joueur.h"
#include <random>



class IA {
public:
    static int utility(Grille grille, string val); // fonction pour determiner le score dans l'algorithme minmax
    static int absearch(Grille grille) ;
    static pair<int, int> maxvalue(Grille& grille, int a, int b, int p);
    static pair<int, int> minvalue(Grille& grille, int a, int b, int p);
    static int rdm(Grille grille);
};


#endif //PUISSANCE5_IA_H
