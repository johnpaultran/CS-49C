// Homework 2 Problem 3
#include <stdio.h>
#define FLOOR_DIMENSIONS 50 // dimensions of floor
#define DOWN 1              // pen position value 
#define UP 0                // pen position value 

// 50 x 50 floor initialized to 0's
int floorArr[FLOOR_DIMENSIONS][FLOOR_DIMENSIONS] = {0};
// turtle starts at 0,0
int xPos = 0; // Initial x position
int yPos = 0; // Initial y position

// function to move forward n spaces
void moveForward(int direction, int pen)
{
    int xPosChange;     // change in x position
    int yPosChange;     // change in y position
    int space;          // number of spaces to move forward
    // moving forward in array
    if (direction == 0) 
    { 
        xPosChange = 1; // x position value to be moved forward (1) per space
        yPosChange = 0; // y position value to be moved per space
    } 
    // moving up in array
    else if (direction == 90) 
    {
        xPosChange = 0;     // x position value to be moved per space
        yPosChange = -1;    // y position value to be moved upward (-1) per space
    }
    // moving left in array
    else if (direction == 180) 
    {
        xPosChange = -1;    // x position value to be moved backward (-1) per space
        yPosChange = 0;     // y position value to be moved per space
    } 
    // moving down in array
    else if (direction == 270) 
    {
        xPosChange = 0; // x position value to be moved per space
        yPosChange = 1; // y position value to be moved downward (1) per space
    }
    printf("How many spaces? ");        // prompt
    scanf("%d", &space);                // input number of spaces to move
    for (int i = 0; i < space; i++)     // for loop for number of spaces to move
    {
        //change x postion
        xPos += xPosChange; // move in x direction
        // special case when reaching edge of floor
        if (xPos < 0) 
        {
            xPos = 0;   // can't be negative
        } 
        // special case when reaching edge of floor
        else if (xPos > FLOOR_DIMENSIONS) 
        {
            xPos = FLOOR_DIMENSIONS;    // can't be > 50
        }
        //change y position
        yPos += yPosChange; // move in y direction
        // special case when reaching edge of floor
        if (yPos < 0) 
        {
            yPos = 0;   // can't be negative
        } 
        // special case when reaching edge of floor
        else if (yPos > FLOOR_DIMENSIONS) 
        {
            yPos = FLOOR_DIMENSIONS;    // can't be > 50
        }
        if (pen == DOWN) // if the pen is currently down
        {
            floorArr[yPos][xPos] = 1;   // place a 1 in the current array position
        }
    }
}

// function to change direction of pen
int change_dir(int direction)
{
    int current;                    // initialize current direction
    if (direction < 0)              // if given direction is < 0
    {
        current = 360 + direction;  // move left
    }
    else if (direction >= 360)      // if given direction is >= 360
    {
        current = direction - 360; // move right
    }
    else
    {
        current = direction;        // current direction is given direction
    }
    return current;                 // return current direction
}

// function main begins program execution
int main( void )
{
    int flag = 0;       // flag for when to terminate program
    int command;        // command to be given
    int pen = UP;       // initial pen position
    // turtle direction in degrees (0 right, 90 up, 180 left, 270 down)
    int direction = 0;  // initialize to right
    // list of commands for turtle
    printf("Turtle Commands:\n");
    printf("1 = pen up\n");
    printf("2 = pen down\n");
    printf("3 = turn right\n");
    printf("4 = turn left\n");
    printf("5 = walk n # of steps\n");
    printf("6 = print matrix\n");
    printf("9 = end program\n\n");
    // while flag is still at 0, keep iterating
    while (flag == 0) 
    {
        printf("Insert command: "); // prompt
        scanf("%d", &command);      // enter command

        switch (command)    // switch function for command
        {
            // if pen is down, move it up
            case 1:
                pen = UP;
                break;
            // if pen is up, move it down
            case 2:
                pen = DOWN;
                break;
            // turn right
            case 3:
                direction -= 90;                    // angle -90 degrees
                direction = change_dir(direction);  // call to change direction function
                break;
            // turn left
            case 4: 
                direction += 90;                    // angle +90 degrees
                direction = change_dir(direction);  // call to change direction function
                break;
            // move the pen n number of spaces
            case 5: 
                moveForward(direction, pen);        // call to move forward function
                break;
            // print out the output
            case 6:
                printf("\nDrawing of array is: \n"); // for clarity
                // nested for loop to iterate through all elements of multidimensional array
                for (int i = 0; i < FLOOR_DIMENSIONS; i++) 
                {
                    for (int j = 0; j < FLOOR_DIMENSIONS; j++)
                    {
                        printf(floorArr[i][j] ? "*" : " "); /* 1 is replaced by * and 0 replaced by ' ' */
                    }
                    printf("\n");   // move to next row
                }
                printf("\n");       // print new line for clarity
                break;
            // end the program
            case 9:
                flag = 1;       // set flag to value other than 0 to exit while loop
                break;
            // default case when wrong command input is entered
            default:
                printf("Wrong input, try again\n"); // prompt
        } 
    } 
}

/*
Sample Output:

Turtle Commands:
1 = pen up
2 = pen down
3 = turn right
4 = turn left
5 = walk n # of steps
6 = print matrix
9 = end program

Insert command: 2
Insert command: 5
How many spaces? 12
Insert command: 3
Insert command: 5
How many spaces? 12
Insert command: 3
Insert command: 5
How many spaces? 12
Insert command: 3
Insert command: 5
How many spaces? 12
Insert command: 1
Insert command: 6

Drawing of array is:
*************
*           *
*           *
*           *
*           *
*           *
*           *
*           *
*           *
*           *
*           *
*           *
*************






































Insert command: 9
*/