// Homework 1 Problem 5
#include <stdio.h>
 
// function main begins program execution
int main( void )
{
    int rows;   // number of rows
    int k = 0;  // initialize k
    int j;      // declare j for for loops

    printf( "Input : n = " ); // prompt
    scanf( "%d", &rows);      // enter number of rows for pyramid pattern
    printf("Output : \n");    // prompt

    for (int i = 1; i <= rows; i++) // loop for number of rows
    {
        if (i % 2 != 0)             // if the row is odd = increasing order of numbers
        {
            for (j = k + 1; j < k + i; j++) // loop for increasing order
            {
                printf("%d*", j);           // print j and asterisk
            }
            printf("%d\n", j);              // print last j in row and start new line
            k = j + 1;                      // set k for next row
        }
        else                                // if row is even = decreasing order of numbers
        {
            k = k + i - 1;                  // set k to biggest number in even row
            for (j = k; j > k - i + 1; j--) // reverse loop for decreasing order
            {
                printf("%d*", j);           // print j and asterisk
            }
            printf("%d\n", j);              // print last j and start new line
        }
    }
}

/*
Sample Cases:

Input : n = 4
Output :
1
3*2
4*5*6
10*9*8*7

Input : n = 6
Output :
1
3*2
4*5*6
10*9*8*7
11*12*13*14*15
21*20*19*18*17*16

Input : n = 8
Output :
1
3*2
4*5*6
10*9*8*7
11*12*13*14*15
21*20*19*18*17*16
22*23*24*25*26*27*28
36*35*34*33*32*31*30*29

Input : n = 2
Output :
1
3*2
*/