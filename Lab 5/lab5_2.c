// Lab 5 Problem 2
// C program to multiply two square (4x4) matrices
#include <stdio.h> 
#define SIZE 4 
  
// this function multiplies matrix1 and matrix2, 
// and stores the output in result
void multiply(int matrix1[][SIZE], int matrix2[][SIZE], int result[][SIZE]) 
{ 
    // for loops to access each index of multidimensional array
    for (int i = 0; i < SIZE; i++) 
    { 
        for (int j = 0; j < SIZE; j++) 
        { 
            result[i][j] = 0; // set current result element to 0

            // matrix multiplication is done by "dot product"
            // defined as the sum of the product of matching numbers
            for (int k = 0; k < SIZE; k++) 
            {
                // result is the sum of the products of
                // each element of matrix1's row and each element of matrix2's column
                result[i][j] += matrix1[i][k] * matrix2[k][j]; 
            }
        } 
    } 
} 

// function main begins program execution
// test case for multiply function
int main(void) 
{ 
    // initialize values of matrix1 and matrix2
    int matrix1[SIZE][SIZE] = { {1, 2, 3, 4}, 
                                {1, 2, 3, 4}, 
                                {1, 2, 3, 4}, 
                                {1, 2, 3, 4}}; 
  
    int matrix2[SIZE][SIZE] = { {1, 2, 3, 4}, 
                                {1, 2, 3, 4}, 
                                {1, 2, 3, 4}, 
                                {1, 2, 3, 4}}; 
  
    int result[SIZE][SIZE]; // product of matrix1 and matrix2
    
    // call multiply function
    multiply(matrix1, matrix2, result); 
  
    // prints the result
    printf("Result is: \n"); 
    for (int i = 0; i < SIZE; i++) 
    { 
        for (int j = 0; j < SIZE; j++) 
        {
           printf("%d ", result[i][j]); 
        }
        printf("\n"); 
    } 
} 

/*
output of main function:

Result is:
10 20 30 40
10 20 30 40
10 20 30 40
10 20 30 40

which is correct
*/