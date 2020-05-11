// c file to define functions in header file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// included header file
#include "gameRule.h"

// function to print 7 by 6 game board
int printBoard(int gameBoard[7][6])
{
    int checkFull = 1;                      // int for whether or not the board is filled up
    printf(" 1 2 3 4 5 6 7 \n");            // column numbers at top of board
    printf(" -------------\n");
    for(int i = 5; i >= 0; i--)             // for loops to iterate through game board array
    {
        for(int j = 0; j < 7; j++)
        {
            printf(" %d",gameBoard[j][i]);  // print current array index
            if(gameBoard[j][i] == 0)        // if current index is zero
            {
                checkFull = 0;              // board is not full
            }
        }
        printf("\n");                       // print new line for next row
    }
    return checkFull;                       // return whether or not board is full
}

// function to show the player's move on game board
int showMove(int column, int player, int gameBoard[7][6])
{
    for(int i = 0; i < 6; i++)
    {
        if(gameBoard[column-1][i] == 0)             // if current index is empty
        {
            gameBoard[column-1][i] = player + 1;    // insert disc at current index
            // check if a player has won
            return winningMove(column - 1, player+1, i, gameBoard);
        }
    }
    return 0;
}