// Homework 1 Problem 2
#include <stdio.h>
 
// function main begins program execution
int main( void )
{
    int number;                         // 5 digit number to be inserted
    printf( "Enter 5 digit number: " ); // prompt
    scanf( "%d", &number );             // enter 5 digit number

    int firstDigit, secondDigit, fourthDigit, fifthDigit;   // placeholder for each digit
    
    // single out each digit in number by using division and remainder operators
    firstDigit = number / 10000;
    secondDigit = number / 1000 % 10;
    fourthDigit = number / 10 % 10;
    fifthDigit = number % 10;

    // check if first and last digit match
    if (firstDigit == fifthDigit)
    {
        // check if second and second to last digit match
        if (secondDigit == fourthDigit)
        {
            printf("%d is a palindrome", number);       // print is palindrome if match
        }
        else
        {
            printf("%d is not a palindrome", number);   // print not palindrome if no match
        }
    }
    else
        {
            printf("%d is not a palindrome", number);   // print not palindrome if no match
        }
}

/*
Sample Cases:

Enter 5 digit number: 12321
12321 is a palindrome

Enter 5 digit number: 66766
66766 is a palindrome

Enter 5 digit number: 98765
98765 is not a palindrome

Enter 5 digit number: 19191
19191 is a palindrome

Enter 5 digit number: 48472
48472 is not a palindrome
*/