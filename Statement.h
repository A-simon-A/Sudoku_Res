//
//  Statement.h
//  Sudoku_Res
//
//  Created by Simon AUTECHAUD on 26/08/2021.
//

#ifndef Statement_h
#define Statement_h

/*
 value refers to the avaible values for the square (if there are two posibilities [eg. 1 and 9] value will have the corresponding bits at 1 [eg. the first and the 9th bit at 1])
 if valid_status == true, it means that the program has the final value of the square, otherwise, the program has only hypotetic values.
 */
struct square{
    bool valid_status = false ;
    int value ;
};
#endif /* Statement_h */
