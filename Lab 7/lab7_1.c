// Lab 7 Problem 1
#include <stdio.h>

// create union
union integer
{
    char c;
    short s;
    int i;
    long b;
};

// function prototype
void display(union integer u);

// function main begins program execution
int main( void )
{
    union integer u;                        // initialize union
  
    // enter data of specified type and print the values in union
    printf("Enter data for type char: ");
    scanf("%c", &u.c);
    display(u);
  
    printf("Enter data for type short: ");
    scanf("%hd", &u.s);
    display(u);
  
    printf("Enter data for type int: ");
    scanf("%d", &u.i);
    display(u);
  
    printf("Enter data for type long: ");
    scanf("%ld", &u.b);
    display(u);
}

// function to display the values in union
void display(union integer u)
{
    printf("\nBreakdown of the values in the union:\n");
    printf("char = %c\n",u.c);
    printf("short = %hd \n", u.s);
    printf("int = %d\n", u.i);
    printf("long = %ld\n\n", u.b);
}