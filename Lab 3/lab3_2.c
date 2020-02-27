/* 
Problem 2:

(Pythagorean Triples) A right triangle can have sides that are all integers. 
The set of three integer values for the sides of a right triangle is called a Pythagorean triple. 
These three sides must satisfy the relationship that the sum of the squares of two of the sides is equal to the square of the hypotenuse. 
Find all Pythagorean triples for side1, side2, and the hypotenuse all no larger than 500. 
Use a triple-nested for loop that simply tries all possibilities.
*/
#include <stdio.h>

// function main begins program execution
int main( void )
{
    int result;     // result of Pythagorean triple

    // three sides of Pythagorean triple
    int side1;
    int side2;
    int hypotenuse;

    int maxSide = 500;  // maximum size of one side of Pythagorean triple
 
    // triple nested loop to go through all possible Pythagorean triples
    for (side1 = 1; side1 <= maxSide; side1++)
    {
        for (side2 = 1; side2 <= maxSide; side2++)
        {
            for (hypotenuse = 1; hypotenuse <= maxSide; hypotenuse++)
            {
                result = (side1 * side1) + (side2 * side2); // Pythagorean formula
 
                if(result == (hypotenuse * hypotenuse)) // if hypotenuse is found
                {
                    // print out side lengths of Pythagorean triple
                    printf("side1: %d, side2: %d, hypotenuse: %d\n", side1, side2, hypotenuse);
                }
            }
        }
    }
}