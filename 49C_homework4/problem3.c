// Homework 4 Problem 3
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void unpackCharacters(unsigned int integer);
void displayBitFormat(unsigned int character);

// function main begins program execution
int main( void )
{
    unsigned int integer;                   // unsigned int to be unpacked
    printf("Enter unsigned number: ");      // prompt
    scanf("%u", &integer);                  // enter unsigned int

    // print the unsigned integer in bit format before it is unpacked
    printf("\n%u's bit representation is: \n", integer);
    displayBitFormat(integer);                 // call to displayBitFormat function
    printf("\n");                              // print new line for clarity
    unpackCharacters(integer);                 // call to unpackCharacters function
}

// function to unpack two characters from an unsigned integer variable
void unpackCharacters(unsigned int integer)
{
    int mask1 = 65280;                                  // mask (11111111 00000000)
    int mask2 = 255;                                    // second mask (11111111)
    int masked1 = integer & mask1;                      // combine int w/ mask using AND operator
    char first = (char) (masked1 >> 8);                 // right shift the result by 8 bits
    char second = (char) integer & mask2;               // combine int w/ second mask using AND operator

    // print the two unpacked characters
    printf("Result in binary after unpacking characters: \n");
    printf("First unpacked charcter: %c\n", first);     // first charcter
    displayBitFormat(first);                            
    printf("Second unpacked charcter: %c\n", second);   // second character
    displayBitFormat(second);                           
}

// function to display character in bit format
void displayBitFormat(unsigned int character)
{
    unsigned int i;                     // bit counter
    unsigned int displayMask = 1 << 31; // leftshift 31 bits
    printf("%u = ", character);

    // loop to iterate through bits
    for (i = 1; i <= 32; ++i)
    {
        putchar(character&displayMask ? '1':'0');
        character <<= 1;    // left shift 1 bit
        if (i % 8 == 0)     // for every 8 bits
        {
            printf(" ");    // print a space
        }
    }
    printf("\n");           // print new line for clarity
}

/*
Sample Cases:

Enter unsigned number: 16706

16706's bit representation is: 
16706 = 00000000 00000000 01000001 01000010 

Result in binary after unpacking characters: 
First unpacked charcter: A
65 = 00000000 00000000 00000000 01000001 
Second unpacked charcter: B
66 = 00000000 00000000 00000000 01000010

Enter unsigned number: 21328

21328's bit representation is: 
21328 = 00000000 00000000 01010011 01010000 

Result in binary after unpacking characters: 
First unpacked charcter: S
83 = 00000000 00000000 00000000 01010011 
Second unpacked charcter: P
80 = 00000000 00000000 00000000 01010000

Enter unsigned number: 24930

24930's bit representation is: 
24930 = 00000000 00000000 01100001 01100010 

Result in binary after unpacking characters: 
First unpacked charcter: a
97 = 00000000 00000000 00000000 01100001 
Second unpacked charcter: b
98 = 00000000 00000000 00000000 01100010 
*/