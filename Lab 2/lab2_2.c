// Problem 2 (dangling else)

#include <stdio.h>
 
// function main begins program execution
int main( void ) 
{
    int x = 9;
    int y = 11;

    if ( x < 10 ) 
    {
        if ( y > 10 )
        printf( "*****\n" );
    }
    else 
    {
    printf( "#####\n" );
    printf( "$$$$$\n" );
    }
}

/*
// Problem 2
#include <stdio.h>
 
// function main begins program execution
int main( void ) 
{
    int x = 9;
    int y = 11;

    if ( x < 10 )
        if ( y > 10 )
            printf( "*****\n" );
        else
            printf( "#####\n" );
        printf( "$$$$$\n" );
}
*/