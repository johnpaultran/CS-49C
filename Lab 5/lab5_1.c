// Lab 5 Problem 1
// sorting an array's values into ascending order
#include <stdio.h>
#define SIZE 10

// function main begins program execution
int main(void)
{
    // initialize a
    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};

    puts("Data items in original order");

    // output original array
    for (size_t i = 0; i < SIZE; ++i) {
        printf("%4d", a[i]);
    }

    // bubble sort
    // loop to control number of passes
    for(unsigned int pass = 1; pass < SIZE; ++pass)
    {
       // number of swaps in this pass
       int numOfSwaps = 0;
       // the largest numbers are guaranteed to be in 
       // the highest numbered elements of the array on each pass
       // instead of making nine comparisons on every pass, 
       // make (size of array) - (current pass) comparisons
       // i.e. 8 comparisons on the 2nd pass, 7 on the 3rd pass, etc
       for(size_t i = 0; i < SIZE - pass; ++i)
       {
           // compare adjacent elements and swap them if
           // first element > second element
           if(a[i] > a[i + 1])
           {
               // number of swaps is incremented if any swap happens
               numOfSwaps++;
               int hold = a[i];
               a[i] = a[i+1];
               a[i+1] = hold;
           }
       }

       // if there are no swaps then the loop breaks since it is already sorted
       if(numOfSwaps == 0)
           break;
    }

    puts("\nData items in ascending order");

    // prints output sorted array
    for (size_t i = 0; i < SIZE; ++i) {
        printf("%4d", a[i]);
    }

    puts("");
}