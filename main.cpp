#include <iostream>
#include "Joueur.h"
#include "Grille.h"
#include "IA.h"

int main() {

    cout << "[PUISSANCE 5]\n\n";
    cout << "Veuillez choisir :\n1. Joueur contre Joueur\n2. Joueur contre IA\n";
    string choixJeu;
    while (choixJeu!="1" && choixJeu!="2"){
        cin >> choixJeu;
    }
    Grille grille;
    int choixJeuInt(0);
    if (choixJeu=="1"){choixJeuInt=1;}
    else {choixJeuInt=2;}
    switch (choixJeuInt){
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
                    j2.jouer(choixj2-1,"0", grille);
                    if (grille.fin()){
                        cout<<nom2<<" a gnagne!\n";
                        termine = true;
                    }
                }
            }
            break;}

        case 2: {
            string nom1, nom2;
            cout << "Choisir le nom du joueur :\n";
            cin >> nom1;
            string choixDifficulteString;
            int choixDifficulte(-1);
            cout << "Choisir la difficulté :\n1. Facile,\n2. Difficile\n";
            while (choixDifficulte!=1 && choixDifficulte!=2){
                cin >> choixDifficulteString;
                if (choixDifficulteString=="1"){choixDifficulte=1;}
                else if (choixDifficulteString=="2"){choixDifficulte=2;}
            }
            if (choixDifficulte==1){
                Joueur j1(nom1), j2("IA");
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

                        j2.jouer(IA::rdm(grille),"0", grille);
                        if (grille.fin()){
                            cout<<"IA a gnagne!\n";
                            termine = true;
                        }
                    }
                }
            }
            else {
                Joueur j1(nom1), j2("IA");
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

                        j2.jouer(IA::absearch(grille),"0", grille);
                        if (grille.fin()){
                            cout<<"IA a gnagne!\n";
                            termine = true;
                        }
                    }
                }
            }
            break;}

        default:{

            break;}
    }
    return 0;
}


