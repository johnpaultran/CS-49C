// main driver code of project
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// header files
#include "board.h"
#include "gameRule.h"

int gameBoard[7][6];    // array for 7 by 6 game board
int turnCount = 0;      // counter for each turn

// function main begins program execution
int main( void )
{
    int mode;           // option for game mode
    for(;;)             // infinite loop to play game as much as player wants to
    {
        memset(gameBoard, 0, sizeof(int)*7*6);                  // initialize gameboard to 0's
        turnCount = 0;                                          // initialize turn count to 0
        puts("Welcome to John & Ken's Connect Four Game\n");
        printBoard(gameBoard);                                  // print game board
        printf("\nChoose game mode:\n");                        // prompt
        printf("1. Player versus Computer\n");                  // option 1
        printf("2. Player 1 versus Player 2\n");                // option 2
        printf("Your Choice: ");
        for(;;)                         // infinite loop to ensure input is valid
        {
            scanf("%d", &mode);         // enter user input
            if(mode == 1 || mode == 2)  // if input is a valid game mode option
            {
                break;                  // break out of loop
            }
            printf("Invalid option. Please try again: ");
        }
        for(;;)                         // infinite loop for current game
        {
            if(mode == 2)               // player versus player mode
            {
                turnCount++;                        // increment turn count
                // player 1 move
                int player1 = playerMove(0, turnCount, gameBoard);
                if(player1 == 1 || player1 == 0)    // if a player has won or it's a draw
                {
                    break;                          // end current game
                }
                // player 2 move
                int player2 = playerMove(1, turnCount, gameBoard);
                if(player2 == 1 || player2 == 0)    // if a player has won or it's a draw
                {
                    break;                          // end current game
                }
            }
            else        // player versus computer mode
            {
                int move = AImove(gameBoard);                   // computer computer's next move
                int computer = showMove(move, 1, gameBoard);    // play computer move
                turnCount++;                                    // increment turn count
                printf("\nTurn # %d ", turnCount);
                printf("\nComputer's turn\n");
                int checkFull = printBoard(gameBoard);          // check if board is full
                if(checkFull == 1)                              // if the board is full
                {
                    printf("\nIt's a DRAW!\n");                 // game ends in a draw
                    break;                                      // end current game
                }
                printf("\nComputer chose column %d\n", move);   // show computer move
                if(computer == 1)                               // if computer won
                {
                    printf("\nComputer won! \n");
                    break;                                      // end current game
                }
                // player move
                int player = playerMove(0, turnCount, gameBoard);
                if(player == 1 || player == 0)                  // if player has won or it's a draw
                {
                    break;                                      // end current game
                }
            }
        }

        // prompt to play again or exit game
        printf("Enter 3 to exit or any other number to play again: ");
        scanf("%d",&mode);  // enter user input
        if(mode == 3)       // if user wants to quit game
        {
            break;          // end the program
        }
    }
}