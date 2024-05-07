#include <iostream>
#include "Joueur.h"
#include "Grille.h"

int main() {
    cout << "[PUISSANCE 5]\n\n";
    cout << "Veuillez choisir :\n1. Joueur contre Joueur\n2. Joueur contre IA\n";
    int choixJeu = 0;
    while (choixJeu!=1 && choixJeu!=2){
        cin >> choixJeu;
        cin.clear();
        cin.ignore(12345678, '\n'); // on "nettoie" le cin car il ne produit pas d'erreur pour
                                             // qu'on  puisse utiliser le try/catch
    }
    Grille grille;
    switch (choixJeu){
        case 1: {
            string nom1, nom2;
            cout << "Choisir le nom du joueur 1\n";
            cin >> nom1;
            cout << "Choisir le nom du joueur 2\n";
            cin >> nom2;
            Joueur j1(nom1), j2(nom2);
            bool termine = grille.fin();
            while (!termine){
                grille.affiche();
                int choixj1(-1);
                cout <<"Choix " << nom1 << " :\n";
                while (!j1.isdispo(choixj1-1, grille)){
                    cin >> choixj1;
                    cin.clear();
                    cin.ignore(12345678, '\n');
                }
                j1.jouer(choixj1-1,"X", grille);
                if (grille.fin()){
                    cout<<nom1<<" a gnagne!\n";
                    termine = true;
                }
                grille.affiche();
                if (!termine){
                    int choixj2(-1);
                    cout <<"Choix " << nom2 << " :\n";
                    while (!j2.isdispo(choixj2-1, grille)){
                        cin >> choixj2;
                        cin.clear();
                        cin.ignore(12345678, '\n');
                    }
                    j1.jouer(choixj2-1,"0", grille);
                    if (grille.fin()){
                        cout<<nom2<<" a gnagne!\n";
                        termine = true;
                    }
                }
            }
            break;}

        case 2: {

            break;}

        default:{

            break;}
    }
    return 0;
}
