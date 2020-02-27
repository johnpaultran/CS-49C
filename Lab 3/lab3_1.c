/* 
Problem 1:

Write a program that prints the following pattern. 
Use for loops to generate the patterns. 
All asterisks (*) should be printed by a single printf statement of the form printf( "*" );  
*/
#include <stdio.h>
 
// function main begins program execution
int main( void )
{
    int n;    // input number

    printf( "Input : n = " ); // prompt
    scanf( "%d", &n);         // enter number of asterisks for pattern
    printf("Output : \n");    // prompt

    for (int i = 1; i <= n; i++)    // for loop for total number of lines
    {
        for (int j = 1; j <= i; j++)    // for loop for number of asterisk per line
        {
            printf("*");    // print specified number of asterisks
        }
        printf(" \n");  // start new line
    }
}