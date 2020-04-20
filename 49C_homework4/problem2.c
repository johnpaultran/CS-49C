// Homework 4 Problem 2
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void packCharacters(char character1, char character2);
void displayBitFormat(unsigned int character);

// function main begins program execution
int main( void )
{
    // intialize two characters
    char character1;
    char character2;

    printf("Enter the first character: ");      // prompt
    character1 = getchar();                     // read first character
    getchar();                                  // delete new line left on input stream

    printf("Enter the second character: ");     // prompt
    character2 = getchar();                     // read second character
    getchar();                                  // delete new line left on input stream

    // print the two characters in bit format before they are packed
    printf("\n%c's bit representation is: \n", character1);
    displayBitFormat(character1);                           // call to displayBitFormat function
    printf("\n%c's bit representation is: \n", character2);
    displayBitFormat(character2);                           // call to displayBitFormat function
    printf("\n");                                           // print new line for clarity

    packCharacters(character1, character2);                 // call to packCharacters function
}

// function to pack two characters into an unsigned integer variable
void packCharacters(char character1, char character2)
{
    unsigned int c;         // initialize unsigned variable
    c = character1;         // assign first character to unsigned variable
    c = c << 8;             // left shift first char by 8 bits
    c = c | character2;     // combine with second character using bitwise inclusive OR 

    // print the packed unsigned variable
    printf("Result in binary after packing characters: \n");
    displayBitFormat(c);
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

Enter the first character: A
Enter the second character: B

A's bit representation is: 
65 = 00000000 00000000 00000000 01000001 

B's bit representation is: 
66 = 00000000 00000000 00000000 01000010 

Result in binary after packing characters: 
16706 = 00000000 00000000 01000001 01000010

Enter the first character: S
Enter the second character: P

S's bit representation is: 
83 = 00000000 00000000 00000000 01010011 

P's bit representation is: 
80 = 00000000 00000000 00000000 01010000 

Result in binary after packing characters: 
21328 = 00000000 00000000 01010011 01010000 

Enter the first character: a
Enter the second character: b

a's bit representation is: 
97 = 00000000 00000000 00000000 01100001 

b's bit representation is: 
98 = 00000000 00000000 00000000 01100010 

Result in binary after packing characters: 
24930 = 00000000 00000000 01100001 01100010 
*/