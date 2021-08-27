//
//  main.cpp
//  Sudoku_Res
//
//  Created by Simon AUTECHAUD on 26/08/2021.
//

#include <iostream>
#include "Statement.h"
using namespace std ;

int main() {
    char verif ;
    coord coordinates ;
    unsigned int choice ;
    grid playing_grid ;
    // algorithm
    cout << "Bonjour." << endl ;
    cout << "Bienvenue dans un programme de résolution de Sudoku." << endl << endl;
    cout << "Veuillez entrer les valeurs de cases connues." << endl ;
    
    do{
        coordinates = ask_coord() ;
        playing_grid.tabular[coordinates.row][coordinates.column] = fill_square() ;
        ++playing_grid.valid_squares ;
        cout << "Voulez-vous entrer une autre case ? (Y/N)" ;
        cin >> verif ;
    }while(verif=='Y' || verif=='y') ;
    
    do{
        cout << "Que voulez-vous faire?" << endl ;
        cout << "\t1. Entrer de nouvelles valeurs." << endl ;
        cout << "\t2. Lancer la résolution du Sudoku." << endl ;
        cout << "\t3. Afficher la grille." << endl ;
        cout << "\t4. Avorter l'opération." << endl ;
        cout << "Saisissez votre choix:" ;
        cin  >> choice ;
        while(choice < 1 || choice > 4){
            cout << "Erreur de saisie, veuillez ressaisir votre choix : " ;
            cin >> choice ;
        }
        switch (choice) {
            case 1 :
                coordinates = ask_coord() ;
                playing_grid.tabular[coordinates.row][coordinates.column] = fill_square() ;
                ++playing_grid.valid_squares ;
                break;
                
            case 2 :
                sudoku_resolution(playing_grid) ;
                break;
                
            case 3 :
                sudoku_display(playing_grid) ;
                break;
                
            default :
                playing_grid.valid_squares = 81 ;
                cout << "Opération avortée." << endl ;
                break;
        }
    }while(playing_grid.valid_squares < 81);
    cout << "Fin du Sudoku, affichage automatique du résultat final :" << endl ;
    sudoku_display(playing_grid) ;

    
    
    
    return 0;
}
