// Homework 2 Problem 1
#include <stdio.h>

// returns the celsius equivalent of a fahrenheit temperature
float celsius(int fahrenheit)
{
    float celsius = (fahrenheit - 32) * (5.0 / 9);  // formula to calculate C
    return celsius; // return celsius equivalent
}

// returns the fahrenheit equivalent of a celsius temperature
float fahrenheit(int celsius)
{
    float fahrenheit = (celsius * 9.0 / 5) + 32;    // formula to calculate F
    return fahrenheit;  // return fahrenheit equivalent
}

// function main begins program execution
// prints charts showing the fahrenheit equivalents 
// of all celsius temperatures from 0 to 100 degrees, 
// and the celsius equivalents of all 
// fahrenheit temperatures from 32 to 212 degrees
int main( void )
{
    // print results in table format
    printf("Celsius to Fahrenheit\n");
    printf("---------------------\n");
    // total field width = 21
    // right justify results for clear readability
    printf("%8s%13s\n", "Celsius:", "Fahrenheit:");
    for(int i = 0; i <= 100; i++)
    {
        // float conversion rounded to 1 decimal place
        // call to fahrenheit function
        printf("%8d%13.1f\n", i, fahrenheit(i));    // print table
    }
    // print results in table format
    printf("\nFahrenheit to Celsius\n");
    printf("---------------------\n");
    // total field width = 21
    // right justify results for clear readability
    printf("%11s%10s\n", "Fahrenheit:", "Celsius:");
    for(int i = 32; i <= 212; i++)
    {
        // float conversion rounded to 1 decimal place
        // call to celsius function
        printf("%11d%10.1f\n", i, celsius(i));      // print table
    }
}

/*
Sample Output:

Celsius to Fahrenheit
---------------------
Celsius:  Fahrenheit:
       0         32.0
       1         33.8
       2         35.6
       3         37.4
       4         39.2
       5         41.0
       6         42.8
       7         44.6
       8         46.4
       9         48.2
      10         50.0
.
.   continues down to 100 (didn't want to copy paste all 100 lines for clarity)
.

      90        194.0
      91        195.8
      92        197.6
      93        199.4
      94        201.2
      95        203.0
      96        204.8
      97        206.6
      98        208.4
      99        210.2
     100        212.0

Fahrenheit to Celsius
---------------------
Fahrenheit:  Celsius:
         32       0.0
         33       0.6
         34       1.1
         35       1.7
         36       2.2
         37       2.8
         38       3.3
         39       3.9
         40       4.4
         41       5.0
         42       5.6
.
.   continues down to 212 (didn't want to copy paste all 180 lines for clarity)
.
        202      94.4
        203      95.0
        204      95.6
        205      96.1
        206      96.7
        207      97.2
        208      97.8
        209      98.3
        210      98.9
        211      99.4
        212     100.0
*/