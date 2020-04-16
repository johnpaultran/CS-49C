// Lab 7 Problem 3
#include <stdio.h>

// create structure to store real/imaginary 
struct complex 
{
    float real;
    float imaginary;
};

// function prototype
struct complex add(struct complex n1, struct complex n2);

// function main begins program execution
int main( void ) 
{
    // initialize structures
    struct complex n1;
    struct complex n2;
    struct complex result;

    // enter first complex number
    printf("Enter the real and imaginary parts of first complex number: \n");
    scanf("%f %f", &n1.real, &n1.imaginary);

    // enter second complex number
    printf("Enter the real and imaginary parts of second complex number: \n");
    scanf("%f %f", &n2.real, &n2.imaginary);

    // add together two structures
    result = add(n1, n2);   

    // print the result
    printf("Sum = %.1f + %.1fi", result.real, result.imaginary);
}

// function to add two complex numbers
struct complex add(struct complex n1, struct complex n2) 
{
    struct complex temp;                            // temporary structure to hold values of sum
    temp.real = n1.real + n2.real;                  // add real numbers in structure
    temp.imaginary = n1.imaginary + n2.imaginary;   // add imaginary numbers in structure
    return temp;                                    // return structure
}