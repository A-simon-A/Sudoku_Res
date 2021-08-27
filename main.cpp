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
    coord coordinates ;
    unsigned int choice ;
    grid playing_grid ;
    
    // algorithm
    cout << "Bonjour." << endl ;
    cout << "Bienvenue dans un programme de résolution de Sudoku." << endl << endl;
    cout << "Veuillez entrer les valeurs de cases connues." << endl ;
    
    coordinates.row = 0 ;
    while(coordinates.row <= 8){
        fill_row(playing_grid, coordinates.row) ;
        ++coordinates.row ;
    }
    
    do{
        cout << "Que voulez-vous faire?" << endl ;
        cout << "\t1. Entrer de nouvelles valeurs." << endl ;
        cout << "\t2. Supprimer une case." << endl ;
        cout << "\t3. Lancer la résolution du Sudoku." << endl ;
        cout << "\t4. Afficher la grille." << endl ;
        cout << "\t5. Avorter l'opération." << endl ;
        cout << "Saisissez votre choix:" ;
        cin  >> choice ;
        while(choice < 1 || choice > 5){
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
                cout << "Entrez les coordonnées de la case que vous voulez supprimer :" << endl ;
                coordinates = ask_coord() ;
                playing_grid.tabular[coordinates.row][coordinates.column].value = 0 ;
                playing_grid.tabular[coordinates.row][coordinates.column].valid_status = false ;
                break ;
                
            case 3 :
                sudoku_resolution(playing_grid) ;
                break;
                
            case 4 :
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
