//
//  Statement.h
//  Sudoku_Res
//
//  Created by Simon AUTECHAUD on 26/08/2021.
//

#ifndef Statement_h
#define Statement_h

struct coord{
    unsigned int column ;
    unsigned int row ;
};

/*
 value refers to the avaible values for the square (if there are two posibilities [eg. 1 and 9] value will have the corresponding bits at 1 [eg. the first and the 9th bit at 1])
 if valid_status == true, it means that the program has the final value of the square, otherwise, the program has only hypotetic values.
 */
struct square{
    bool valid_status = false ;
    int value = 0 ;
};

struct grid{
    unsigned int valid_squares = 0 ;
    square tabular[9][9] ;
};

/*
 Role   : ask the coordinates of a square, put the value in the coord structure
 Input  : /
 Output : coord
 */
coord ask_coord(void) ;

/*
 Role   : change the square.valid_status, ask a value, convert it and put it in square.value
 Input  : /
 Output : square
 */
square fill_square(void) ;

/*
 Role           : fill a complete row (number of the row indicated in Input)
 Input          : row
 Input / Output : grid
 Output         : /
 */
void fill_row(grid& playing_grid, unsigned int row) ;

/*
 Role           : initialization of all empty squares at 0b111111111
 Input          : /
 Input / Output : grid
 Output         : /
 */
void full_1_init(grid& playing_grid) ;

/*
 Role           : Check if the square is valid or not
 Input          : coordinates of the square
 Input / Output : grid
 Output         : /
 */
void valid_status_verification(grid& playing_grid, coord coordinates);

/*
 Role           : search clues in the row of the square and save them in playing_grid.tabular[X][X].value
 Input          : coordinates of the searched square
 Input / Output : grid
 Output         : /
 */
void row_analysis(grid& playing_grid, coord coordinates) ;

/*
 Role           : search clues in the column of the square and save them in playing_grid.tabular[X][X].value
 Input          : coordinates of the searched square
 Input / Output : grid
 Output         : /
 */
void column_analysis(grid& playing_grid, coord coordinates) ;

/*
 Role           : search clues in the box of the square and save them in playing_grid.tabular[X][X].value
 Input          : coordinates of the searched square
 Input / Output : grid
 Output         : /
 */
void box_analysis(grid& playing_grid, coord coordinates) ;


/*
 Role           : makes the resolution of the sudoku
 Input          : /
 Input / Output : grid
 Output         : /
 */
void sudoku_resolution(grid& playing_grid) ;

/*
 Role           : displays the sudoku
 Input          : grid
 Output         : /
 */
void sudoku_display(const grid playing_grid) ;

#endif /* Statement_h */
