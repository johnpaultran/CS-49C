// Homework 2 Problem 2
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// function main begins program execution
int main( void )
{
    int die1, die2;     // value of each dice
    int sum = 0;        // total number of rolls
    // array of 13 elements with range 0-12
    int dice[13]= {0};  // initialize entire array to zeros
  
    srand(time(NULL));  // seed value to ensure randomization
    for (int i = 1; i <= 36000; i++)  // for loop to roll the dice 36000 times
    {
        // shift range of rand from 0-5 to 1-6
        die1 = 1 + rand() % 6;  // first rolled die value
        die2 = 1 + rand() % 6;  // second rolled die value
        dice[die1 + die2]++;    // increment the array index of the sum of two dice
    }

    // print results in tabular format
    printf("%4s%10s\n", "Sum:", "Total:");  // field width 4 for first row, 10 for second
    for (int i = 2; i <= 12; i++)           // for loop to display results of rolling dice
    {
        printf("%4d%10d\n", i, dice[i]);    // field width 4 for first row, 10 for second
        sum += dice[i];                     // add # of rolls per sum value to check total
    }
    printf("\nTotal number of rolls is: %d", sum);   // print total # of rolls
}

/*
Sample Cases:

Sum:    Total:
   2      1020
   3      1964
   4      2939
   5      4022
   6      5038
   7      6024
   8      5001
   9      4002
  10      2997
  11      1985
  12      1008

Total number of rolls is: 36000

Sum:    Total:
   2       946
   3      2027
   4      2935
   5      4055
   6      5059
   7      5900
   8      4964
   9      4015
  10      3089
  11      2001
  12      1009

Total number of rolls is: 36000

These totals are reasonable since i.e. there is only 1/36 chance
of getting a sum of 2 or 12, so out of 36,000 rolls, it should be about
1,000 rolls with those results. For a sum of 7, the probability is about
1/6 so about 1/6 of the results should be a sum of 7. This lines up
with my final results.
*/