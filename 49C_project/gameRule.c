// c file to define functions in header file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// included header file
#include "board.h"

// function to check for winning move (4 in a row)
int winningMove(int row, int player, int col, int gameBoard[7][6])
{
    int count = 0;                          // int for counting 4 in a row
    for(int i = 0; i < 6; i++)              // loop to check horizontally
    {
        if(gameBoard[row][i] == player)     // if current index is filled by a player
        {
            count++;                        // increment count
        }
        else
        {
            count = 0;                      // reset count
        }
        if(count == 4)
        {
            return 1;                       // return 1 for winning move
        }
    }
    count = 0;                              // reset count for next condition
    
    for(int i = 0; i < 7; i++)              // loop to check vertically
    {
        if(gameBoard[i][col] == player)     // if current index is filled by player
        {
            count++;                        // increment count
            if(count == 4)
            {
                return 1;                   // return 1 for winning move
            }
        }
        else 
        {
            count = 0;                      // reset count
        }
    }
    count = 0;                              // reset the count for next condition
    
    for(int i = 0; i < 7 * 2; i++)              // loop to check diagonally
    {
        for(int j = 0; j <= i; j++)             // loop to check diagonally up
        {
            int k = i - j;                      // correct diagonal index
            if(k < 7 && j < 6)                  // if they are within the index
            {
                if(gameBoard[k][j] == player)   // if current index is filled by player
                {
                    count++;                    // increment count
                    if(count == 4) 
                    {
                        return 1;               // return 1 for winning move
                    }
                }
                else 
                {
                    count = 0;                  // reset count
                }
            }
        }
        count = 0;                              // reset count for next condition

        for(int j = 0; j <= i; j++)             // loop to check diagonally down
        {
            int k = i - j;                      // correct diagonal index
            int x = 6 - k;                      // correct diagonal index
            if(k < 7 && j < 6)                  // if they are within the index
            {
                if(gameBoard[x][j] == player)   // if current index is filled by player
                {
                    count++;                    // increment count
                    if(count == 4) 
                    {
                        return 1;               // return 1 for winning move
                    }
                }
                else 
                {
                    count = 0;                  // reset count
                }
            }
        }
        count = 0;                              // reset count for next condition
    }
    return 0;                                   // return 0 for no winning move
}

// function for player to move a piece to the board
int playerMove(int player, int turnCount, int gameBoard[7][6])
{
    int column;                                         // column for disc to be inserted                     
    printf("\nTurn # %d \n", turnCount);                // print current turn
    printf("Player %d 's turn \n", player + 1);         // print the current player's turn
    printf("Please choose a number from 1 to 7: ");     // prompt
    for(;;)                                             // infinite loop to ensure input is valid
    {
        scanf("%d", &column);                           // enter user input
        // if input is a valid column number
        if(column == 1 || column == 2 || column == 3 || column == 4 || column == 5 || column == 6 || column == 7)
        {
            if(gameBoard[column-1][5] == 0)             // check if column is full
            {
                break;                                  // break out of loop
            }
        }
        printf("Invalid number or columm is full. Please choose again: ");
    }
    int move = showMove(column, player, gameBoard);     // insert the selected move into board
    int checkFull = printBoard(gameBoard);              // check if board is full

    if(checkFull == 1)              // if the board is full
    {
        printf("\nIt's a DRAW!\n"); // game ends in a draw
        return 1;                   // return 1 for a draw
    }
    if(move == 1)                   // if the move was a winning move
    {
        printf("\nPlayer %d has won!\n", player + 1);
        return 0;                   // return 0 for winning move
    }
    return 9;                       // return nothing
}

// function for computer to check for possible winning moves
int winningComputer(int player, int gameBoard[7][6])
{
    int tempDisc = 0;               // temporary disc to be inserted into gameboard
    int move = 9;                   // initialize move with nothing value
    for(int i = 1; i < 8; i++)      // loop for each column
    {
        // if current index is not filled
        if(gameBoard[i - 1][5] != 1 && gameBoard[i - 1][5] != 2)
        {
            tempDisc = showMove(i, player, gameBoard);   // insert temporary disc to board
            if(tempDisc == 1)           // if temporary disc is a winning move
            {
                move = i;               // save winning column number
            }
            for(int j = 5; j >= 0; j--) // loop to delete temporary insert
            {
                if(gameBoard[i - 1][j] == player + 1)
                {
                    gameBoard[i - 1][j] = 0;    // reset current index back to 0 (deletes disc)
                    break;                      // break out of loop
                }
            }
        }
    }
    return move;        // return winning column number or nothing
}

// function for AI computer player's next move
int AImove(int gameBoard[7][6])
{
    int move = 9;                                   // initialize move with nothing value

    // AI first wants to win
    int checkWin= winningComputer(1, gameBoard);    // check for winning move
    if(checkWin != 9)                               // if there is a winning move
    {
        return checkWin;                            // return winning move
    }

    // second option is to block opponent from winning
    int checkBlock= winningComputer(0, gameBoard);  // check for move to block opponent from winning
    if(checkBlock != 9)                             // if there is a blocking move
    {
        return checkBlock;                          // return blocking move
    }

    // basic opening movesets we researched and implemented
    if(gameBoard[3][0] == 0) 
    {
        return 4;
    }
    else if(gameBoard[3][1] == 0) 
    {
        return 4;
    }
    else if(gameBoard[3][2] == 0 && gameBoard[3][1] == 2) 
    {
        return 4;
    }
    else if(gameBoard[3][1] != 0 && gameBoard[4][0] == 0) 
    {
        return 5;
    }
    else if(gameBoard[3][2] != 0 && gameBoard[5][0] == 0) 
    {
        return 6;
    }
    else if(gameBoard[4][0] != 0 && gameBoard[5][0] == 0) 
    {
        return 6;
    }
    else if(gameBoard[2][0] != 0 && gameBoard[1][0] == 0) 
    {
        return 2;
    }
    else if(gameBoard[1][1] != 0 && gameBoard[0][0] == 0) 
    {
        return 1;
    }
    else if(gameBoard[5][0] != 0 && gameBoard[6][0] == 0) 
    {
        return 7;
    }
    // if all the above moves are not possible
    else
    {
        srand(time(NULL));      // seed for random number
        move = 1 + rand() % 7;  // randomize a column number between 1 and 7
        while(gameBoard[move][5] != 0)  // if the column is full
        {
            move = 1 + rand() % 7;      // randomize another column number
        }
    }
    return move;                        // return move
}