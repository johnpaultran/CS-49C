/* 
Problem 1:

The Fibonacci series
0, 1, 1, 2, 3, 5, 8, 13, 21, ...
begins with the terms 0 and 1 and has the property that each succeeding term is the sum of the two preceding terms. 
a) Write a nonrecursive function fibonacci( n ) that calculates the nth Fibonacci number. 
b) Determine the largest Fibonacci number that can be printed on your system. 
*/
#include <stdio.h>
 
// function main begins program execution
int main (void)
{
    int term1 = 0;      // first term of fibonacci
    int term2 = 1;      // second term of fibonacci
    int current;        // initialize current term of fibonacci
    int n;              // nth term of fibonacci sequence
    printf("Enter n for nth term in Fibonacci: ");  // prompt
    scanf( "%d", &n );  // enter nth term

    // for loop for calculating fibonacci sequence
    for (int i = 1; i <= n; i++)
    {
        if (i == 1) 
        {
          printf("%d\n", term1);    // first term
          continue;
        }
        if (i == 2)
        {
          printf("%d\n", term2);    // second term
          continue;
        }
            current = term1 + term2;    // current term = sum of 2 pervious terms
            printf("%d\n", current);    // print current term

        // update terms for next iteration of the loop
        term1 = term2;
        term2 = current;
    }
}