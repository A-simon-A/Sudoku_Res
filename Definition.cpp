//
//  Definition.cpp
//  Sudoku_Res
//
//  Created by Simon AUTECHAUD on 26/08/2021.
//

#include <iostream>
#include "Statement.h"
using namespace std ;

coord ask_coord(void){
    coord res ;
    
    // algorithm
    cout << "! Numéros de colone et de ligne entre 0 et 8, pas entre 1 et 9 !" << endl ;
    cout << "Entrez le No. de colone : " ;
    cin >> res.column ;
    cout << endl << "Entrez le No. de ligne : " ;
    cin >> res.row ;
    cout << endl ;
    return res ;
}

square fill_square(void){
    square res ;
    unsigned int value ;
    
    // algorithm
    res.valid_status = true ;
    cout << "Entrez la valeur de la case : " ;
    cin >> value ;
    cout << endl ;
    while (value<1 || value >9){
        cout << "Erreur de saisie, veuillez entrer un entier entre 1 et 9." << endl ;
        cin >> value ;
    }
    res.value = 0b1 << (value - 1) ;
    return res ;
}

void fill_row(grid& playing_grid, unsigned int row){
    char row_input[10] ;
    int increment ;
    
    // algorithm
    cout << "Entrez les valeurs des 9 cases de la ligne " << row << "." << endl ;
    cout << "Mettre un zéro pour chaque case vide, ne pas utiliser d'espaces." << endl ;
    cin >> row_input ;
    for (increment = 0; increment <= 8; ++increment) {
        switch (row_input[increment]) {
            case '1':
                playing_grid.tabular[row][increment].value = 0b000000001 ;
                playing_grid.tabular[row][increment].valid_status = true ;
                ++playing_grid.valid_squares ;
                break;
            case '2':
                playing_grid.tabular[row][increment].value = 0b000000010 ;
                playing_grid.tabular[row][increment].valid_status = true ;
                ++playing_grid.valid_squares ;
                break;
            case '3':
                playing_grid.tabular[row][increment].value = 0b000000100 ;
                playing_grid.tabular[row][increment].valid_status = true ;
                ++playing_grid.valid_squares ;
                break;
            case '4':
                playing_grid.tabular[row][increment].value = 0b000001000 ;
                playing_grid.tabular[row][increment].valid_status = true ;
                ++playing_grid.valid_squares ;
                break;
            case '5':
                playing_grid.tabular[row][increment].value = 0b000010000 ;
                playing_grid.tabular[row][increment].valid_status = true ;
                ++playing_grid.valid_squares ;
                break;
            case '6':
                playing_grid.tabular[row][increment].value = 0b000100000 ;
                playing_grid.tabular[row][increment].valid_status = true ;
                ++playing_grid.valid_squares ;
                break;
            case '7':
                playing_grid.tabular[row][increment].value = 0b001000000 ;
                playing_grid.tabular[row][increment].valid_status = true ;
                ++playing_grid.valid_squares ;
                break;
            case '8':
                playing_grid.tabular[row][increment].value = 0b010000000 ;
                playing_grid.tabular[row][increment].valid_status = true ;
                ++playing_grid.valid_squares ;
                break;
            case '9':
                playing_grid.tabular[row][increment].value = 0b100000000 ;
                playing_grid.tabular[row][increment].valid_status = true ;
                ++playing_grid.valid_squares ;
                break;
            default:
                break;
        }
    }
}

void full_1_init(grid& playing_grid){
    unsigned int column, row ;
    for (column = 0; column <= 8; ++column) {
        for (row = 0; row <= 8; ++row) {
            if (playing_grid.tabular[row][column].valid_status == false) {
                playing_grid.tabular[row][column].value = 0b111111111 ;
            }
        }
    }
}

void valid_status_verification(grid& playing_grid, coord coordinates){
    switch (playing_grid.tabular[coordinates.row][coordinates.column].value) {
        case 0b000000001:
            playing_grid.tabular[coordinates.row][coordinates.column].valid_status = true ;
            ++playing_grid.valid_squares ;
            break;
        case 0b000000010:
            playing_grid.tabular[coordinates.row][coordinates.column].valid_status = true ;
            ++playing_grid.valid_squares ;
            break;
        case 0b000000100:
            playing_grid.tabular[coordinates.row][coordinates.column].valid_status = true ;
            ++playing_grid.valid_squares ;
            break;
        case 0b000001000:
            playing_grid.tabular[coordinates.row][coordinates.column].valid_status = true ;
            ++playing_grid.valid_squares ;
            break;
        case 0b000010000:
            playing_grid.tabular[coordinates.row][coordinates.column].valid_status = true ;
            ++playing_grid.valid_squares ;
            break;
        case 0b000100000:
            playing_grid.tabular[coordinates.row][coordinates.column].valid_status = true ;
            ++playing_grid.valid_squares ;
            break;
        case 0b001000000:
            playing_grid.tabular[coordinates.row][coordinates.column].valid_status = true ;
            ++playing_grid.valid_squares ;
            break;
        case 0b010000000:
            playing_grid.tabular[coordinates.row][coordinates.column].valid_status = true ;
            ++playing_grid.valid_squares ;
            break;
        case 0b100000000:
            playing_grid.tabular[coordinates.row][coordinates.column].valid_status = true ;
            ++playing_grid.valid_squares ;
            break;
        default:
            break;
    } // OPTIMISATION ???
}

void row_analysis(grid& playing_grid, coord coordinates){
    unsigned int column ;
    for (column = 0; column <= 8; ++column) {
        if(column != coordinates.column){
            if(playing_grid.tabular[coordinates.row][column].valid_status == true){
                playing_grid.tabular[coordinates.row][coordinates.column].value &= (~playing_grid.tabular[coordinates.row][column].value) ;
            }
        }
    }
}

void column_analysis(grid& playing_grid, coord coordinates){
    unsigned int row ;
    for (row = 0; row <= 8; ++row) {
        if(row != coordinates.row){
            if (playing_grid.tabular[row][coordinates.column].valid_status == true) {
                playing_grid.tabular[coordinates.row][coordinates.column].value &= (~playing_grid.tabular[row][coordinates.column].value) ;
            }
        }
    }
}

void box_analysis(grid& playing_grid, coord coordinates){
    int row, row_mod, init_row ;
    int column, column_mod, init_column ;
    /*
     the value of init_row and init_column will specify the position of the first square of the box, compared to the studied square
     */
    
    
    // algorithm
    row_mod = coordinates.row % 3 ;
    column_mod = coordinates.column % 3 ;
    switch (row_mod) {
        case 0:
            init_row = 0 ;
            break;
        case 1:
            init_row = -1 ;
            break;
        default:
            init_row = -2 ;
            break;
    }
    switch (column_mod) {
        case 0:
            init_column = 0 ;
            break;
        case 1:
            init_column = -1 ;
            break;
        default:
            init_column = -2 ;
            break;
    }
    for (row = 0; row <= 2; ++row) {
        for (column=0; column <= 2; ++column) {
            if((init_row + row != 0) && (init_column + column != 0)){
                if (playing_grid.tabular[coordinates.row + init_row + row][coordinates.column + init_column + column].valid_status == true) {
                    playing_grid.tabular[coordinates.row][coordinates.column].value &= (~playing_grid.tabular[coordinates.row + init_row + row][coordinates.column + init_column + column].value) ;
                }
            }
        }
    }
}

void sudoku_resolution(grid& playing_grid){
    coord coordinates ;
    unsigned int choice ;
    
    // algorithm
    full_1_init(playing_grid) ;
    do{
        for (coordinates.row = 0; coordinates.row <= 8; ++coordinates.row) {
            for (coordinates.column = 0; coordinates.column <= 8; ++coordinates.column) {
                if (playing_grid.tabular[coordinates.row][coordinates.column].valid_status != true) {
                    row_analysis(playing_grid, coordinates) ;
                    valid_status_verification(playing_grid, coordinates) ;
                    if (playing_grid.tabular[coordinates.row][coordinates.column].valid_status != true) {
                        column_analysis(playing_grid, coordinates) ;
                        valid_status_verification(playing_grid, coordinates) ;
                        if (playing_grid.tabular[coordinates.row][coordinates.column].valid_status != true) {
                            box_analysis(playing_grid, coordinates) ;
                            valid_status_verification(playing_grid, coordinates) ;
                        }
                    }
                }
            }
        }
        
        cout << "Nombre de cases validées : " << playing_grid.valid_squares << endl ;
        cout << "Que voulez-vous faire?" << endl ;
        cout << "\t1. Continuer." << endl ;
        cout << "\t2. Afficher la grille." << endl ;
        cout << "\t3. Avorter l'opération." << endl ;
        cout << "Saisissez votre choix:" ;
        cin  >> choice ;
        while(choice < 1 || choice > 3){
            cout << "Erreur de saisie, veuillez ressaisir votre choix : " ;
            cin >> choice ;
        }
        switch (choice) {
            case 1 :
                break;
                
            case 2 :
                sudoku_display(playing_grid) ;
                break ;
                
            default :
                playing_grid.valid_squares = 81 ;
                cout << "Opération avortée." << endl ;
                break;
        }
    }while (playing_grid.valid_squares < 81);
    
}

void sudoku_display(const grid playing_grid){
    unsigned int row, column ;
    cout << "---------------------------------" << endl ;
    for (row = 0; row <= 8; ++row) {
        cout << "|" ;
        for (column = 0; column <= 8; ++column) {
            cout << " " ;
            switch (playing_grid.tabular[row][column].value) {
                case 0b000000001:
                    cout << "1";
                    break;
                case 0b000000010:
                    cout << "2";
                    break;
                case 0b000000100:
                    cout << "3";
                    break;
                case 0b000001000:
                    cout << "4";
                    break;
                case 0b000010000:
                    cout << "5";
                    break;
                case 0b000100000:
                    cout << "6";
                    break;
                case 0b001000000:
                    cout << "7";
                    break;
                case 0b010000000:
                    cout << "8";
                    break;
                case 0b100000000:
                    cout << "9";
                    break;
                default:
                    cout << " ";
                    break;
            }
            cout << " " ;
            if ((column == 2) || (column == 5)) {
                cout << "||" ;
            }
        }
        cout << "|" << endl ;
        if ((row == 2) || (row == 5) || (row == 8)) {
            cout << "---------------------------------" << endl ;
        }
    }
}
