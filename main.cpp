#include <iostream>
#include "Joueur.h"
#include "Grille.h"
#include "IA.h"
#include "raylib.h"


const int screenWidth = 1200;
const int screenHeight = 900;

const int cellSize = 100;
const int gridPosX = (screenWidth - cellSize * 5) / 2;
const int gridPosY = 50;
void DrawGrid(Grille& grille) {
    // Calcul des positions pour centrer la grille
    int gridPosX = (screenWidth - grille.getColonne() * cellSize) / 2;
    int gridPosY = (screenHeight - grille.getLigne() * cellSize) / 2;

    // Dessinez le plateau de jeu
    for (int i = 0; i < grille.getLigne(); ++i) {
        for (int j = 0; j < grille.getColonne(); ++j) {
            Rectangle cell = { static_cast<float>(gridPosX + j * cellSize), static_cast<float>(gridPosY + i * cellSize), cellSize, cellSize };
            DrawRectangleLinesEx(cell, 2, BLACK);
        }
    }
    // Dessinez les jetons
    for (int i = 0; i < grille.getLigne(); ++i) {
        for (int j = 0; j < grille.getColonne(); ++j) {
            if (grille.getCase(i, j) == "X") {
                DrawCircle(gridPosX + j * cellSize + cellSize / 2, gridPosY + i * cellSize + cellSize / 2, cellSize / 2 - 5, RED);
            } else if (grille.getCase(i, j) == "0") {
                DrawCircle(gridPosX + j * cellSize + cellSize / 2, gridPosY + i * cellSize + cellSize / 2, cellSize / 2 - 5, BLUE);
            }
        }
    }
}

void update(string nom, Grille& grille, Color color){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText(nom.c_str(), 20, 20, 20, BLACK);
    DrawRectangle(150,18,30,30,color);
    DrawGrid(grille);
    DrawText("1", 300, 800, 20, BLACK);
    DrawText("2", 400, 800, 20, BLACK);
    DrawText("3", 500, 800, 20, BLACK);
    DrawText("4", 600, 800, 20, BLACK);
    DrawText("5", 700, 800, 20, BLACK);
    DrawText("6", 800, 800, 20, BLACK);
    DrawText("7", 900, 800, 20, BLACK);
    EndDrawing();
}


int main() {
    InitWindow(screenWidth, screenHeight,"PUISSANCE5");
    SetTargetFPS(60);
    int gameState = 0 ; // 0: Menu, 1: Joueur contre joueur, 2: Joueur contre IA
    Grille grille;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        if (gameState==0){
            DrawText("[PUISSANCE 5]",500,200,30,BLACK);
            DrawText("Veuillez choisir :",495,400,30,BLACK);
            DrawText("ENTER: Joueur contre Joueur\n\n\nCAPS_LOCK: Joueur contre IA\n\n\n",400,450,30,BLACK);
            if (IsKeyPressed(KEY_ENTER)) {
                gameState = 1;
            } else if (IsKeyPressed(KEY_CAPS_LOCK)) {
                gameState = 2;
            }
        }

        else if (gameState == 1) {
            string nom1, nom2;
            cout << "Choisir le nom du joueur 1\n";
            cin >> nom1;
            cout << "Choisir le nom du joueur 2\n";
            cin >> nom2;
            Joueur j1(nom1), j2(nom2);
            bool termine(false);
            while (!WindowShouldClose() && !termine) {
                // Affichage
                update(nom1, grille, RED);
                int choixj1(-1);
                cout <<"Choix " << nom1 << " :\n";
                while (!j1.isdispo(choixj1-1, grille)){
                    cin >> choixj1;
                    cin.clear();
                    cin.ignore(12345678, '\n');
                }
                j1.jouer(choixj1-1,"X", grille);
                update(nom2, grille, BLUE);
                if (grille.fin()){
                    cout << "Le gagnant est : "<< nom1<<endl;
                    termine = true;
                    break;
                }

                if (!termine){
                    int choixj2(-1);
                    cout <<"Choix " << nom2 << " :\n";
                    while (!j2.isdispo(choixj2-1, grille)){
                        cin >> choixj2;
                        cin.clear();
                        cin.ignore(12345678, '\n');
                    }
                    j2.jouer(choixj2-1,"0", grille);
                    update(nom1, grille, RED);
                    if (grille.fin()){
                        cout << "Le gagnant est : "<< nom2<<endl;
                        termine = true;
                    }
                }
                if (grille.dispo().size()==0){
                    cout<<"Match nul!";
                    termine = true;
                }
            }
            break;
        }

        else if (gameState == 2) {
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
                    update(nom1,grille, RED);
                    int choixj1(-1);
                    cout <<"Choix " << nom1 << " :\n";
                    while (!j1.isdispo(choixj1-1, grille)){
                        cin >> choixj1;
                        cin.clear();
                        cin.ignore(12345678, '\n');
                    }
                    j1.jouer(choixj1-1,"X", grille);
                    update(nom2, grille, BLUE);
                    if (grille.fin()){
                        cout<<nom1<<" a gnagne!\n";
                        termine = true;
                    }

                    if (!termine){

                        j2.jouer(IA::rdm(grille),"0", grille);

                        update(nom1, grille, RED);
                        if (grille.fin()){
                            cout<<"IA a gnagne!\n";
                            termine = true;
                        }
                    }
                    if (grille.dispo().size()==0){
                        cout<<"Match nul!";
                        termine = true;
                    }
                }
            }
            else {
                Joueur j1(nom1), j2("IA");
                bool termine = grille.fin();
                while (!termine){
                    update(nom1, grille, RED);
                    int choixj1(-1);
                    cout <<"Choix " << nom1 << " :\n";
                    while (!j1.isdispo(choixj1-1, grille)){
                        cin >> choixj1;
                        cin.clear();
                        cin.ignore(12345678, '\n');
                    }
                    j1.jouer(choixj1-1,"X", grille);
                    update(nom2, grille, BLUE);
                    if (grille.fin()){
                        cout<<nom1<<" a gnagne!\n";
                        termine = true;
                    }
                    if (!termine){

                        j2.jouer(IA::absearch(grille),"0", grille);
                        update(nom1, grille, RED);
                        if (grille.fin()){
                            cout<<"IA a gnagne!\n";
                            termine = true;
                        }
                    }
                    if (grille.dispo().size()==0){
                        cout<<"Match nul!";
                        termine = true;
                    }
                }
            }
            break;
        }
        EndDrawing();

    }

    WaitTime(10);
    CloseWindow();
    return 0;
}


