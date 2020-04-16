// Lab 7 Problem 2
#include <stdio.h>
#include <stdlib.h>

// function prototype
void displayBitFormat(signed int number);

// function main begins program execution
int main( void )
{
    // intialize two characters
    signed int number;

    printf("Enter signed integer: ");       // prompt
    scanf("%d", &number);                   // read signed integer

    // print number before shift
    printf("\n%d's bit representation is: \n", number);
    displayBitFormat(number);
    
    number = number >> 4;                   // right shift by 4 bits

    // print number after shift
    printf("Signed integer after being right shifted 4 bits\n");
    displayBitFormat(number);
    printf("\n");                                          
}

// function to display character in bit format
void displayBitFormat(signed int number)
{
    unsigned int i;                     // bit counter
    unsigned int displayMask = 1 << 31; // leftshift 31 bits
    printf("%u = ", number);

    // loop to iterate through bits
    for (i = 1; i <= 32; ++i)
    {
        putchar(number&displayMask ? '1':'0');
        number <<= 1;       // left shift 1 bit
        if (i % 8 == 0)     // for every 8 bits
        {
            printf(" ");    // print a space
        }
    }
    printf("\n");           // print new line for clarity
}