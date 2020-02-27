/*
Problem 2:

If a four-digit number is given as input through the keyboard, 
write a program to reverse the number. 
For example, if the number that is input is 1234 then the output should be displayed as 4321.

Hint: make use of mod (%), division (/) and multiplication (*) operators.
*/
#include <stdio.h>
 
// function main begins program execution
int main( void )
{
    int number;     // number to be inserted
    printf( "Enter 4 digit number:\n" );    // prompt
    scanf( "%d", &number );                 // enter number

    int reserve;        // placeholder for each digit
    int current = 0;    // new reversed number
    
    while(number > 0)    // while loop
    {    
    reserve = number % 10;              // single out each digit
    current =(current * 10)+ reserve;   // set new number 
    number = number /10;                // reset value for while loop
    }    

    printf( "Reversed 4 digit number is: %d", current );    // print reversed number
}
