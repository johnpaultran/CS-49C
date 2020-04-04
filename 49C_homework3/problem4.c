// Homework 3 Problem 4
#include <stdio.h>

// function prototypes
char *strcpy1(char *s1, char *s2);
char *strcpy2(char *s1, char *s2);
char *strncpy1(char *s1, char *s2, size_t n);
char *strncpy2(char *s1, char *s2, size_t n);
char *strcat1(char *s1, char *s2);
char *strcat2(char *s1, char *s2);
char *strncat1(char *s1, char *s2, size_t n);
char *strncat2(char *s1, char *s2, size_t n);

// function main begins program execution
int main ( void )
{   
    int n = 4;                      // integer to use in functions
    char str1[100];                 // string 1 to be manipulated
    char str2[100];                 // string 2 to be manipulated

    printf("Enter a string: ");     // prompt
    scanf("%s", str2);              // insert a string 

    // test the strcpy functions
    printf("Copied string returned from strcpy1: %s\n", strcpy1(str1, str2));
    printf("Copied string returned from strcpy2: %s\n", strcpy2(str1, str2));

    // test the strncpy functions
    printf("Copied %d elements returned from strncpy1: %s\n", n, strncpy1(str1, str2, n));
    printf("Copied %d elements returned from strncpy2: %s\n", n, strncpy2(str1, str2, n));

    // test the strcat functions
    printf("Concatenated string returned from strcat1: %s\n", strcat1(str1, str2));
    printf("Concatenated string returned from strcat2: %s\n", strcat2(str1, str2));

    // test the strncat functions
    printf("Concatenated %d elements returned from strncat1: %s\n", n, strncat1(str1, str2, n));
    printf("Concatenated %d elements returned from strncat2: %s\n", n, strncat2(str1, str2, n));
}

// function for copying string with array subscripting
char *strcpy1(char *s1, char *s2)
{
    int i;              // intialize i for loop
    // loop for each element until null character of second array
    for (i = 0; s2[i] != '\0'; i++)
    {
        s1[i] = s2[i];  // copy elements of second array to first array
    }
    s1[i] = '\0';       // add null character to end of first array
    return s1;          // return first string array
}  

// function for copying string with pointer arithmetic
char *strcpy2(char *s1, char *s2)
{
    // initialize pointers
    char *ptr1;
    char *ptr2;

    // loop for each element until null character of second string
    for (ptr1 = s1, ptr2 = s2; *ptr2 != '\0'; ptr1++, ptr2++) 
    {
        *ptr1 = *ptr2;  // copy elements of second string to first string
    }
    *ptr1 = '\0';       // add null character to end of first string
    return s1;          // return first string
}

// function for copying n characters of string with array subscripting
char *strncpy1(char *s1, char *s2, size_t n)
{
    size_t counter;     // counter for loop

    // loop for each element until specified n
    for (counter = 0; counter < n; counter++)
    {
        s1[counter] = s2[counter];  // copy elements of second array to first array
    }
    s1[counter] = '\0';             // add null character to end of first array
    return s1;                      // return first string array
}

// function for copying n characters of string with pointer arithmetic
char *strncpy2(char *s1, char *s2, size_t n)
{
    size_t counter;     // counter for loop
    char *ptr1 = s1;    // initialize
    char *ptr2 = s2;    // pointers^

    // loop for each element until specified n
    for (counter = 0; counter < n; counter++, ptr1++, ptr2++)
    {
        *ptr1 = *ptr2;  // copy elements of second string to first string
    }
    *ptr1 = '\0';       // add null character to end of first string
    return s1;          // return first string
}

// function for string concatenation with array subscripting
char *strcat1(char *s1, char *s2)
{
    // initialize i and j for loop
    int i;
    int j;

    // first loop to find null character of first array
    for (i = 0; s1[i] != '\0'; i++)
    {
        ;               // empty body
    }
    // second loop for each element until null character of second array
    for (j = 0; s2[j] != '\0'; j++, i++)
    {
        s1[i] = s2[j];  // copy elements of second array to end of first array
    }
    s1[i] = '\0';       // add null character to end of first array
    return s1;          // return first string array
}

// function for string concatenation with pointer artihmetic
char *strcat2(char *s1, char *s2)
{
    // initialize pointers
    char *ptr1;
    char *ptr2;

    // first loop to find null character of first string
    for (ptr1 = s1; *ptr1 != '\0'; ptr1++)
    {
        ;               // empty body
    }
    // second loop for each element until null character of second string
    for (ptr2 = s2; *ptr2 != '\0'; ptr1++, ptr2++) 
    {
        *ptr1 = *ptr2;  // copy elements of second string to end of first string
    }
    *ptr1 = '\0';       // add null character to end of first string
    return s1;          // return first string
}

// function for string concatenation of n characters with array subscripting
char *strncat1(char *s1, char *s2, size_t n)
{
    int i;              // initialize i for loop
    size_t j;           // counter for loop

    // first loop to find null character of first array
    for (i = 0; s1[i] != '\0'; i++)
    {
        ;               // empty body
    }
    // second loop for each element until specified n
    for (j = 0; j < n; j++, i++)
    {
        s1[i] = s2[j];  // copy elements of second array to end of first array
    }
    s1[i] = '\0';       // add null character to end of first array
    return s1;          // return first string array
}

// function for string concatenation of n characters with pointer arithmetic
char *strncat2(char *s1, char *s2, size_t n)
{
    // initialize pointers
    char *ptr1;
    char *ptr2;
    size_t j;           // counter for loop

    // first loop to find null character of first string
    for (ptr1 = s1; *ptr1 != '\0'; ptr1++)
    {
        ;               // empty body
    }
    // second loop for each element until specified n
    for (ptr2 = s2, j = 0; j < n; ptr1++, ptr2++, j++) 
    {
        *ptr1 = *ptr2;  // copy elements of second string to end of first string
    }
    *ptr1 = '\0';       // add null character to end of first string
    return s1;          // return first string
}

/*
Sample Cases:

Enter a string: Spamming
Copied string returned from strcpy1: Spamming
Copied string returned from strcpy2: Spamming
Copied 4 elements returned from strncpy1: Spam
Copied 4 elements returned from strncpy2: Spam
Concatenated string returned from strcat1: SpamSpamming
Concatenated string returned from strcat2: SpamSpammingSpamming
Concatenated 4 elements returned from strncat1: SpamSpammingSpammingSpam
Concatenated 4 elements returned from strncat2: SpamSpammingSpammingSpamSpam

Enter a string: Rocket
Copied string returned from strcpy1: Rocket
Copied string returned from strcpy2: Rocket
Copied 4 elements returned from strncpy1: Rock
Copied 4 elements returned from strncpy2: Rock
Concatenated string returned from strcat1: RockRocket
Concatenated string returned from strcat2: RockRocketRocket
Concatenated 4 elements returned from strncat1: RockRocketRocketRock
Concatenated 4 elements returned from strncat2: RockRocketRocketRockRock

Enter a string: starfish
Copied string returned from strcpy1: starfish
Copied string returned from strcpy2: starfish
Copied 4 elements returned from strncpy1: star
Copied 4 elements returned from strncpy2: star
Concatenated string returned from strcat1: starstarfish
Concatenated string returned from strcat2: starstarfishstarfish
Concatenated 4 elements returned from strncat1: starstarfishstarfishstar
Concatenated 4 elements returned from strncat2: starstarfishstarfishstarstar
*/