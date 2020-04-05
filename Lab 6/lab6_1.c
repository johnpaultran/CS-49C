// Lab 6 Problem 1
#include <stdio.h>
#include <ctype.h>

// function main begins program execution
int main( void )
{
    char c;                         // character to be input from keyboard
    printf("Enter a character: ");  // prompt
    scanf("%c", &c);                // enter a char

    // print the value returned by each function in the character-handling library
    printf("Value of isblank: %d\n", isblank(c));
    printf("Value of isdigit: %d\n", isdigit(c));
    printf("Value of isalpha: %d\n", isalpha(c));
    printf("Value of isalnum: %d\n", isalnum(c));
    printf("Value of isxdigit: %d\n", isxdigit(c));
    printf("Value of islower: %d\n", islower(c));
    printf("Value of isupper: %d\n", isupper(c));
    printf("Value of tolower: %d\n", tolower(c));
    printf("Value of toupper: %d\n", toupper(c));
    printf("Value of isspace: %d\n", isspace(c));
    printf("Value of iscntrl: %d\n", iscntrl(c));
    printf("Value of ispunct: %d\n", ispunct(c));
    printf("Value of isprint: %d\n", isprint(c));
    printf("Value of isgraph: %d\n", isgraph(c));
}