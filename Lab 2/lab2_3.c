/* 
Problem 3:

Write a program that keeps printing the multiples of integer 2, namely 2, 4, 8, 16, 32, 64, and so on. 
Your loop should not terminate (i.e., you should create an infinite loop). 
What happens when you run this program? 
Write the answer to this in the comments of your code.
*/
#include <stdio.h>
 
// function main begins program execution
int main( void ) 
{
    // initialize variables
    unsigned int counter = 1; // counter for while loop
    unsigned int integer = 1; // number being printed

    // print out infinite multiples of 2 with a while loop
    while ( counter > 0 )
    {
        integer *= 2; // multiple number being printed by 2
        printf( "%d\n", integer); // print number
        counter++; // increment counter
    } // end while
}

/* When we run this program, it prints out infinite 0's. 
This happens because we did not specify when to terminate the loop, 
therefore it will either go on forever or it does nothing.
*/