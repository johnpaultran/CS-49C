// Homework 1 Problem 3
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// function main begins program execution
int main( void )
{
    char RPS;               // input for player 1 (rock, paper, or scissors)
    int player1 = 0;        // converted RPS character to number
    int player1Count = 0;   // number of times player 1 won
    int player2Count = 0;   // number of times player 2 won

    srand ((int) time (NULL));      // before for loop call once (hinted)
    for (int i = 0; i < 10; i++)    // loop to play 10 times
    {
        printf( "Player 1, please enter R (Rock), P (Paper) or S (Scissors): "); // prompt
        scanf( "\n%c", &RPS );              // enter choice
        int player2 = rand ( ) % 3 + 1;     // computer's choice (random generated)

        // convert characters to numbers to compare to computer's choice
        if (RPS == 'P' || RPS == 'p')
        {
            player1 = 1;
        }
        else if (RPS == 'R' || RPS == 'r')
        {
            player1 = 2;
        }
        else if (RPS == 'S' || RPS == 's')
        {
            player1 = 3;
        }
        // if not R, P, or S then it is invalid
        else
        {
            printf("Not valid input, please try again.\n");
            printf("\n");   // new line for clarity
            continue;       // continue to next iteration of the loop
        }

        // program picks and announces winner based on rock, paper, scissors rules
        if (player1 == 1 && player2 == 2)
        {
            printf("Paper covers rock. Player 1 wins!\n");
            player1Count += 1;
        }
        else if (player1 == 2 && player2 == 1)
        {
            printf("Paper covers rock. Player 2 wins!\n");
            player2Count += 1;
        }
        else if (player1 == 1 && player2 == 3)
        {
            printf("Scissors cut paper. Player 2 wins!\n");
            player2Count += 1;
        }
        else if (player1 == 3 && player2 == 1)
        {
            printf("Scissors cut paper. Player 1 wins!\n");
            player1Count += 1;
        }
        else if (player1 == 3 && player2 == 2)
        {
            printf("Rock breaks scissors. Player 2 wins!\n");
            player2Count += 1;
        }
        else if (player1 == 2 && player2 == 3)
        {
            printf("Rock breaks scissors. Player 1 wins!\n");
            player1Count += 1;
        }
        else if (player1 == player2)
        {
            printf("It's a draw!\n");   // if they are the same then it is a draw
        }
        printf("\n");                   // new line after each game for clarity
    }

    // prints final score (total for each player)
    printf("Final Score:\n");
    printf("Player 1: %d \n", player1Count);
    printf("Player 2: %d \n", player2Count);

    // announces the winner based on number of games won
    if (player1Count > player2Count)
    {
        printf("Player 1 wins!\n");
    }
    else if (player2Count > player1Count)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }
}

/*
Sample Case:

Player 1, please enter R (Rock), P (Paper) or S (Scissors): R
It's a draw!

Player 1, please enter R (Rock), P (Paper) or S (Scissors): s
Scissors cut paper. Player 1 wins!

Player 1, please enter R (Rock), P (Paper) or S (Scissors): p
It's a draw!

Player 1, please enter R (Rock), P (Paper) or S (Scissors): S
It's a draw!

Player 1, please enter R (Rock), P (Paper) or S (Scissors): x
Not valid input, please try again.

Player 1, please enter R (Rock), P (Paper) or S (Scissors): P
Paper covers rock. Player 1 wins!

Player 1, please enter R (Rock), P (Paper) or S (Scissors): r
Rock breaks scissors. Player 1 wins!

Player 1, please enter R (Rock), P (Paper) or S (Scissors): R
Paper covers rock. Player 2 wins!

Player 1, please enter R (Rock), P (Paper) or S (Scissors): S
Rock breaks scissors. Player 2 wins!

Player 1, please enter R (Rock), P (Paper) or S (Scissors): p
Paper covers rock. Player 1 wins!

Final Score:
Player 1: 4
Player 2: 2
Player 1 wins!
*/