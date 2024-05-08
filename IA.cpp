//
// Created by Nizar on 08/05/2024.
//

#include "IA.h"

int IA::utility(Grille grille, string ia) {
    int score = 0;
    int x = grille.getLigne();
    int y = grille.getColonne();
    auto& plateau = grille.getPlateau();
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j < y; ++j) {
            if (plateau[i][j]==ia){
                // LES ALIGNEMENTS
                // alignements de 5 pions
                if (j <= 2 &&  // 5 horizontal
                    plateau[i][j] == plateau[i][j+1] &&
                    plateau[i][j] == plateau[i][j+2] &&
                    plateau[i][j] == plateau[i][j+3] &&
                    plateau[i][j] == plateau[i][j+4]) {
                    score += 1000;
                }
                if (i <= 1 && // 5 vertical
                    plateau[i][j] == plateau[i+1][j] &&
                    plateau[i][j] == plateau[i+2][j] &&
                    plateau[i][j] == plateau[i+3][j] &&
                    plateau[i][j] == plateau[i+4][j]) {
                    score += 1000;
                }
                if (j <= 2 &&  i <= 1 &&// 5 diagonale descendante vers la droite
                    plateau[i][j] == plateau[i+1][j+1] &&
                    plateau[i][j] == plateau[i+2][j+2] &&
                    plateau[i][j] == plateau[i+3][j+3] &&
                    plateau[i][j] == plateau[i+4][j+4]) {
                    score += 1000;
                }
                if (i >= 4 && j <= 2 &&// 5 diagonale montante vers la droite
                    plateau[i][j] == plateau[i-1][j+1] &&
                    plateau[i][j] == plateau[i-2][j+2] &&
                    plateau[i][j] == plateau[i-3][j+3] &&
                    plateau[i][j] == plateau[i-4][j+4]) {
                    score += 1000;
                }
                // alignements de 4 pions
                if (j <= 3 &&  // 4 horizontal
                    plateau[i][j] == plateau[i][j+1] &&
                    plateau[i][j] == plateau[i][j+2] &&
                    plateau[i][j] == plateau[i][j+3]) {
                    score += 500;
                }
                if (i <= 2 && // 4 vertical
                    plateau[i][j] == plateau[i+1][j] &&
                    plateau[i][j] == plateau[i+2][j] &&
                    plateau[i][j] == plateau[i+3][j]) {
                    score += 500;
                }
                if (j <= 3 &&  i <= 2 &&// 4 diagonale descendante vers la droite
                    plateau[i][j] == plateau[i+1][j+1] &&
                    plateau[i][j] == plateau[i+2][j+2] &&
                    plateau[i][j] == plateau[i+3][j+3]) {
                    score += 500;
                }
                if (i >= 3 && j <= 3 &&// 4 diagonale montante vers la droite
                    plateau[i][j] == plateau[i-1][j+1] &&
                    plateau[i][j] == plateau[i-2][j+2] &&
                    plateau[i][j] == plateau[i-3][j+3]) {
                    score += 500;
                }
                // alignements de 3 pions
                if (j <= 4 &&  // 3 horizontal
                    plateau[i][j] == plateau[i][j+1] &&
                    plateau[i][j] == plateau[i][j+2]) {
                    score += 250;
                }
                if (i <= 3 && // 3 vertical
                    plateau[i][j] == plateau[i+1][j] &&
                    plateau[i][j] == plateau[i+2][j]) {
                    score += 250;
                }
                if (i <= 3 && j <= 4 && // 3 diagonale descendante vers la droite
                    plateau[i][j] == plateau[i+1][j+1] &&
                    plateau[i][j] == plateau[i+2][j+2]) {
                    score += 250;
                }
                if (i >= 2 && j <= 4 &&// 3 diagonale montante vers la droite
                    plateau[i][j] == plateau[i-1][j+1] &&
                    plateau[i][j] == plateau[i-2][j+2] ) {
                    score += 250;
                }

                // LES BLOCAGES
                // blocage de 5 pions
                if (j <= 2 &&  // 5 horizontal bloque a gauche
                    "x" == plateau[i][j+1] &&
                    "x" == plateau[i][j+2] &&
                    "x" == plateau[i][j+3] &&
                    "x" == plateau[i][j+4]) {
                    score += 750;
                }
                if (j >=4 &&  // 5 horizontal bloque a droite
                    "x" == plateau[i][j-1] &&
                    "x" == plateau[i][j-2] &&
                    "x" == plateau[i][j-3] &&
                    "x" == plateau[i][j-4]) {
                    score += 750;
                }
                if (i <= 1 &&  // 5 vertical bloque
                    "x" == plateau[i+1][j] &&
                    "x" == plateau[i+2][j] &&
                    "x" == plateau[i+3][j] &&
                    "x" == plateau[i+4][j]) {
                    score += 750;
                }
                if (j <= 2 &&  i <= 1 &&// 5 diagonale descendante vers la droite bloque a gauche
                    "X" == plateau[i+1][j+1] &&
                    "X" == plateau[i+2][j+2] &&
                    "X" == plateau[i+3][j+3] &&
                    "X" == plateau[i+4][j+4]) {
                    score += 750;
                }
                if (j >=4 &&  i >=4 &&// 5 diagonale descendante vers la droite bloque a droite
                    "X" == plateau[i-1][j-1] &&
                    "X" == plateau[i-2][j-2] &&
                    "X" == plateau[i-3][j-3] &&
                    "X" == plateau[i-4][j-4]) {
                    score += 750;
                }
                if (i >= 4 && j <= 2 &&// 5 diagonale montante vers la droite bloque a gauche
                    "X" == plateau[i-1][j+1] &&
                    "X" == plateau[i-2][j+2] &&
                    "X" == plateau[i-3][j+3] &&
                    "X" == plateau[i-4][j+4]) {
                    score += 750;
                }
                if (i <= 1 && j >= 4 &&// 5 diagonale montante vers la droite bloque a droite
                    "X" == plateau[i+1][j-1] &&
                    "X" == plateau[i+2][j-2] &&
                    "X" == plateau[i+3][j-3] &&
                    "X" == plateau[i+4][j-4]) {
                    score += 750;
                }
                // blocages de 4 pions
                if (j <= 3 &&  // 4 horizontal bloque a gauche
                    "x" == plateau[i][j+1] &&
                    "x" == plateau[i][j+2] &&
                    "x" == plateau[i][j+3] ) {
                    score += 375;
                }
                if (j >=3 &&  // 4 horizontal bloque a droite
                    "x" == plateau[i][j-1] &&
                    "x" == plateau[i][j-2] &&
                    "x" == plateau[i][j-3] ) {
                    score += 375;
                }
                if (i <= 2 &&  // 4 vertical bloque
                    "x" == plateau[i+1][j] &&
                    "x" == plateau[i+2][j] &&
                    "x" == plateau[i+3][j] ) {
                    score += 375;
                }
                if (j <= 3 &&  i <= 2 &&// 4 diagonale descendante vers la droite bloque a gauche
                    "X" == plateau[i+1][j+1] &&
                    "X" == plateau[i+2][j+2] &&
                    "X" == plateau[i+3][j+3]) {
                    score += 375;
                }
                if (j >=3 &&  i >=3 &&// 4 diagonale descendante vers la droite bloque a droite
                    "X" == plateau[i-1][j-1] &&
                    "X" == plateau[i-2][j-2] &&
                    "X" == plateau[i-3][j-3]) {
                    score += 375;
                }
                if (i >= 3 && j <= 3 &&// 4 diagonale montante vers la droite bloque a gauche
                    "X" == plateau[i-1][j+1] &&
                    "X" == plateau[i-2][j+2] &&
                    "X" == plateau[i-3][j+3] ) {
                    score += 375;
                }
                if (i <= 2 && j >= 3 &&// 4 diagonale montante vers la droite bloque a droite
                    "X" == plateau[i+1][j-1] &&
                    "X" == plateau[i+2][j-2] &&
                    "X" == plateau[i+3][j-3]) {
                    score += 375;
                }

                // blocages de 3 pions
                if (j <= 4 &&  // 3 horizontal bloque a gauche
                    "x" == plateau[i][j+1] &&
                    "x" == plateau[i][j+2]) {
                    score += 200;
                }
                if (j >=2 &&  // 3 horizontal bloque a droite
                    "x" == plateau[i][j-1] &&
                    "x" == plateau[i][j-2]) {
                    score += 200;
                }
                if (i <= 3 &&  // 3 vertical bloque
                    "x" == plateau[i+1][j] &&
                    "x" == plateau[i+2][j]) {
                    score += 200;
                }
                if (j <= 4 &&  i <= 3 &&// 3 diagonale descendante vers la droite bloque a gauche
                    "X" == plateau[i+1][j+1] &&
                    "X" == plateau[i+2][j+2]) {
                    score += 200;
                }
                if (j >=2 &&  i >=2 &&// 3 diagonale descendante vers la droite bloque a droite
                    "X" == plateau[i-1][j-1] &&
                    "X" == plateau[i-2][j-2] ) {
                    score += 200;
                }
                if (i >= 2 && j <= 4 &&// 3 diagonale montante vers la droite bloque a gauche
                    "X" == plateau[i-1][j+1] &&
                    "X" == plateau[i-2][j+2]) {
                    score += 200;
                }
                if (i <= 3 && j >= 2 &&// 3 diagonale montante vers la droite bloque a droite
                    "X" == plateau[i+1][j-1] &&
                    "X" == plateau[i+2][j-2] &&
                    "X" == plateau[i+3][j-3]) {
                    score += 200;
                }

            }
            //meme avec les blocages l'IA favorise toujours l'attaque et perd tout le temps
            // on va donc ajouter des pénalité en cas de chaine adverses trop longues
            if (plateau[i][j]=="X"){
                // alignements de 5 pions
                if (j <= 2 &&  // 5 horizontal
                    plateau[i][j] == plateau[i][j+1] &&
                    plateau[i][j] == plateau[i][j+2] &&
                    plateau[i][j] == plateau[i][j+3] &&
                    plateau[i][j] == plateau[i][j+4]) {
                    score -= 1000;
                }
                if (i <= 1 && // 5 vertical
                    plateau[i][j] == plateau[i+1][j] &&
                    plateau[i][j] == plateau[i+2][j] &&
                    plateau[i][j] == plateau[i+3][j] &&
                    plateau[i][j] == plateau[i+4][j]) {
                    score -= 1000;
                }
                if (j <= 2 &&  i <= 1 &&// 5 diagonale descendante vers la droite
                    plateau[i][j] == plateau[i+1][j+1] &&
                    plateau[i][j] == plateau[i+2][j+2] &&
                    plateau[i][j] == plateau[i+3][j+3] &&
                    plateau[i][j] == plateau[i+4][j+4]) {
                    score -= 1000;
                }
                if (i >= 4 && j <= 2 &&// 5 diagonale montante vers la droite
                    plateau[i][j] == plateau[i-1][j+1] &&
                    plateau[i][j] == plateau[i-2][j+2] &&
                    plateau[i][j] == plateau[i-3][j+3] &&
                    plateau[i][j] == plateau[i-4][j+4]) {
                    score -= 1000;
                }
                // alignements de 4 pions
                if (j <= 3 &&  // 4 horizontal
                    plateau[i][j] == plateau[i][j+1] &&
                    plateau[i][j] == plateau[i][j+2] &&
                    plateau[i][j] == plateau[i][j+3]) {
                    score -= 500;
                }
                if (i <= 2 && // 4 vertical
                    plateau[i][j] == plateau[i+1][j] &&
                    plateau[i][j] == plateau[i+2][j] &&
                    plateau[i][j] == plateau[i+3][j]) {
                    score -= 500;
                }
                if (j <= 3 &&  i <= 2 &&// 4 diagonale descendante vers la droite
                    plateau[i][j] == plateau[i+1][j+1] &&
                    plateau[i][j] == plateau[i+2][j+2] &&
                    plateau[i][j] == plateau[i+3][j+3]) {
                    score -= 500;
                }
                if (i >= 3 && j <= 3 &&// 4 diagonale montante vers la droite
                    plateau[i][j] == plateau[i-1][j+1] &&
                    plateau[i][j] == plateau[i-2][j+2] &&
                    plateau[i][j] == plateau[i-3][j+3]) {
                    score -= 500;
                }
                // alignements de 3 pions
                if (j <= 4 &&  // 3 horizontal
                    plateau[i][j] == plateau[i][j+1] &&
                    plateau[i][j] == plateau[i][j+2]) {
                    score -= 250;
                }
                if (i <= 3 && // 3 vertical
                    plateau[i][j] == plateau[i+1][j] &&
                    plateau[i][j] == plateau[i+2][j]) {
                    score -= 250;
                }
                if (i <= 3 && j <= 4 && // 3 diagonale descendante vers la droite
                    plateau[i][j] == plateau[i+1][j+1] &&
                    plateau[i][j] == plateau[i+2][j+2]) {
                    score -= 250;
                }
                if (i >= 2 && j <= 4 &&// 3 diagonale montante vers la droite
                    plateau[i][j] == plateau[i-1][j+1] &&
                    plateau[i][j] == plateau[i-2][j+2] ) {
                    score -= 250;
                }
                // alignements de 2 pions
                if (j <= 5 &&  // 2 horizontal
                    plateau[i][j] == plateau[i][j+1] ) {
                    score -= 100;
                }
                if (i <= 4 && // 2 vertical
                    plateau[i][j] == plateau[i+1][j]) {
                    score -= 100;
                }
                if (i <= 4 && j <= 5 && // 2 diagonale descendante vers la droite
                    plateau[i][j] == plateau[i+1][j+1]) {
                    score -= 100;
                }
                if (i >= 1 && j <= 5 &&// 2 diagonale montante vers la droite
                    plateau[i][j] == plateau[i-1][j+1]) {
                    score -= 100;
                }
            }
        }
    }
    // lignes de pour voir le comportement de l'algorithme
    //grille.affiche();
    //cout << "\n\n" << score << endl;
    return score;
}

// Pour le code de la recherche alpha beta et minmax, nous avons simplement repris le pseudo-code du
// cours de Datascience et ia du semestre 5 et nous l'avons adapté en c++
int IA::absearch(Grille grille) {
    int pdr = 4; // profondeur de recherche
    int temp, ui = -1;
    tie(temp, ui) = maxvalue(grille, -1000000, 1000000, pdr);
    return ui;
}

pair<int, int> IA::maxvalue(Grille& grille, int a, int b, int p) {
    if (grille.fin() || p == 0) {
        return make_pair(utility(grille, "0"), 0);
    }

    int u = -1000000;
    int ui = 0;
    Joueur ia("ia");
    vector<int> actionsGrille = grille.dispo();
    for (int i : actionsGrille) {
        Grille grille1(grille);
        ia.jouer(i, "0", grille1);
        int score = minvalue(grille1, a, b, p - 1).first;
        if (score > u) {
            u = score;
            ui = i;
        }

        if (u >= b) {
            return make_pair(u, ui);
        }

        a = max(a, u);
    }
    return make_pair(u, ui);
}

pair<int, int> IA::minvalue(Grille& grille, int a, int b, int p) {

    if (grille.fin() || p == 0) {
        return make_pair(utility(grille, "0"), 0);
    }

    int u = 1000000;
    int ui = 0;
    Joueur ia("ia");
    vector<int> actionsGrille = grille.dispo();
    for (int i : actionsGrille) {
        Grille grille1(grille);
        ia.jouer(i, "X", grille1);
        int score = maxvalue(grille1, a, b, p - 1).first;
        if (score < u) {
            u = score;
            ui = i;
        }

        if (u <= a) {
            return make_pair(u, ui);
        }

        b = min(b, u);
    }
    return make_pair(u, ui);
}

int IA::rdm(Grille grille){
    // r = nombe aleatoire entre 0 et la taille du vecteur de disponibilite des coups
    int r = ((double)rand() / RAND_MAX) * (grille.dispo().size() - 0) + 0;
    return grille.dispo()[r];
}