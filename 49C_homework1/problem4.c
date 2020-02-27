// Homework 1 Problem 4
#include <stdio.h>
 
// function main begins program execution
int main( void )
{
    int rows = 5;           // number of rows to print
    int spaces = rows - 1;  // decrement # rows by 1 for how many spaces to print in each line

    // prints the first half
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= spaces; j++)   // loop for how many spaces to print
        {
            printf(" ");
        }
        spaces--;                           // decrement spaces by 1 for next row
        for (int j = 1; j <= 2*i-1; j++)    // loop for number of asterisks to print
        {
            printf("*");
        }
        printf("\n");                       // start new line after each row
    }
    // prints the second half
    spaces = 1;                                     // set spaces to 1 for second half 
    for (int i = 1; i<= rows - 1; i++)
    {
        for (int j = 1; j <= spaces; j++)           // loop for how many spaces to print
        {
            printf(" ");
        }
        spaces++;                                   // increment spaces by 1 for next row
        for (int j = 1 ; j <= 2*(rows-i)-1; j++)    // loop for number of asterisks to print
        {
            printf("*");
        }
        printf("\n");                               // start new line after each row
    }
}

/*
Sample Output:

    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
*/