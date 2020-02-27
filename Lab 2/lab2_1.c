/* 
Problem 1:

Write a program that utilizes while loop to print the numbers from 1 to 10 
side by side on the same line with three spaces between numbers.
*/
#include <stdio.h>
 
// function main begins program execution
int main( void ) 
{
    // initialize variables
    unsigned int counter = 1; // counter for while loop
    unsigned int integer = 0; // number being printed

    // print out 1 to 10 with a while loop
    while ( counter <= 10)
    {
        integer += 1; // increment number being printed
        printf( "%d   ", integer); // print number
        counter++; // increment counter
    } // end while
}