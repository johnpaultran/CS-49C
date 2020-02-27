/*
Problem 1:

If the total selling price of 15 items 
and the total profit earned on them is input through the keyboard, 
write a program to find the cost price of one item.

Hint: sp = cp + profit
*/
#include <stdio.h>
 
// function main begins program execution
int main( void )
{
    float sp;     // selling price of 15 items
    float profit; // total profit

    printf( "Enter selling price of 15 items:\n" ); // prompt
    scanf( "%f", &sp);       // enter selling price

    printf( "Enter total profit:\n" );              // prompt
    scanf( "%f", &profit);   // enter profit

    float cp;           // cost of 15 items
    cp = sp - profit;   // calculate cost

    float cp_one;       // cost of 1 item
    cp_one = cp / 15;   // calculate cost of 1 item

    printf( "Cost of one item is: %f", cp_one );    // print cost of 1 item
}