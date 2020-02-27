// Homework 1 Problem 1
#include <stdio.h>
 
// function main begins program execution
int main( void )
{
    int number;                         // binary number to be inserted
    printf( "Enter binary number: " );  // prompt
    scanf( "%d", &number );             // enter binary number

    int decValue = 0;   // new decimal equivalent
    int base = 1;       // initialize base to 1 (2^0)

    while (number != 0)    // while loop
    {    
        int remainder = number % 10;    // remainder after dividing by 10
        number /= 10;                   // result of dividing binary by 10
        decValue += remainder * base;   // decimal value = summation of remainder * base
        base *= 2;                      // increment base by * 2 for each digit in binary number
    }    

    printf( "Decimal equivalent is: %d", decValue );    // print decimal number
}

/*
Sample Cases:

Enter binary number: 110
Decimal equivalent is: 6

Enter binary number: 10110011
Decimal equivalent is: 179

Enter binary number: 100110101101
Decimal equivalent is: 2245

Enter binary number: 1111
Decimal equivalent is: 15
*/
