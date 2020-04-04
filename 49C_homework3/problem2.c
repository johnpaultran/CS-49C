// Homework 3 Problem 2
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

// function prototypes
void shuffle(unsigned int wDeck[][FACES]);
void deal(unsigned int deck[][FACES], unsigned int hand[][2], char *suit[], char *face[]);
void pair(unsigned int hand[][2], char *suit[], char *face[]);
void twoPair(unsigned int hand[][2], char *suit[], char *face[]);
void threeOfKind(unsigned int hand[][2], char *suit[], char *face[]);
void fourOfKind(unsigned int hand[][2], char *suit[], char *face[]);
void flush(unsigned int hand[][2], char *suit[], char *face[]);
void straight(unsigned int hand[][2], char *suit[], char *face[]);

// function main begins program execution
int main( void )
{
    // initialize suit array
    char *suit[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    // initialize face array
    char *face[FACES] = { "Ace", "Deuce", "Three", "Four", "Five", 
        "Six", "Seven", "Eight", "Nine",
        "Ten", "Jack", "Queen", "King" };
    unsigned int deck[SUITS][FACES];    // array for deck of cards
    unsigned int hand[5][2];            // array for hand of 5 cards
    
    for (size_t row = 0; row < SUITS; ++row)    // for loop for rows of deck
    {
        for (size_t column = 0; column < FACES; ++column)   // for loop for columns of current row
        {
            deck[row][column] = 0;      // initialize deck slot to 0
        }
    }

    srand(time(NULL));              // seed to ensure randomization
    shuffle(deck);                  // shuffle deck
    deal(deck, hand, suit, face);   // deal a 5 card hand

    //determine the hands poker value
    twoPair(hand, suit, face);
    pair(hand, suit, face);
    threeOfKind(hand, suit, face);
    fourOfKind(hand, suit, face);
    flush(hand, suit, face);
    straight(hand, suit, face);
}

// function to shuffle cards
// untouched from fig 7.24
void shuffle(unsigned int wDeck[][FACES])
{
    // for each of the cards, choose slot of deck randomly
    for (size_t card = 1; card <= CARDS; ++card) 
    {
        size_t row; // row number
        size_t column; // column number
        // choose new random location until unoccupied slot found
        do 
        {
            row = rand() % SUITS;
            column = rand() % FACES;
        } 
        while(wDeck[row][column] != 0);
            // place card number in chosen slot of deck
            wDeck[row][column] = card;
    }
}

// function to deal 5 card hand from deck
void deal(unsigned int deck[][FACES], unsigned int hand[][2], char *suit[], char *face[])
{
    unsigned int counter = 0;   // counter for position in the hand
    printf("Your hand is:\n");  // prompt
    
    // for loop to deal 5 cards
    for (size_t card = 1; card <= 5; ++card)
        // for loop for rows of deck
        for (size_t row = 0; row < SUITS; ++row) 
        {
            // for loop for columns of current row
            for (size_t column = 0; column < FACES; ++column) 
            {
                // if slot contains current card
                if (deck[row][column] == card)
                {
                    // display the card in hand
                    hand[counter][0] = row;
                    hand[counter][1] = column;
                    printf("%5s of %-8s\n", face[column], suit[row]);
                    ++counter;    // increment counter
                }
            }
        }
    printf("\n");   // new line for clarity
}

// function to determine if the hand has a pair
void pair(unsigned int hand[][2], char *suit[], char *face[])
{
    unsigned int counter[FACES] = {0};  // counter for how many cards of each face are present

    // for loop to count how many cards of each face are in the hand
    for (size_t f = 0; f < 5; ++f)
    {
        ++counter[hand[f][1]];  // increment counter
    }
    // for loop to check for pairs
    for (size_t p = 0; p < FACES; ++p)
    {
        if (counter[p] == 2)    // if there is a pair
        {
            printf("Your hand has a pair of %ss.\n", face[p]);  // print the pair
        }
    }
}

// function to determine if the hand has two pairs
void twoPair(unsigned int hand[][2], char *suit[], char *face[])
{
    unsigned int counter[FACES] = {0};      // counter for how many cards of each face are present
    int pair = 0;                           // counter for number of pairs

    // for loop to count how many cards of each face are in the hand
    for (size_t f = 0; f < 5; ++f)
    {
        ++counter[hand[f][1]];  // increment counter
    }
    // for loop to check for pairs
    for (size_t p = 0; p < FACES; ++p)
    {
        if (counter[p] == 2)    // if there is a pair
        {
            pair++;             // increment number of pairs
        }
    }
    if (pair == 2)  // if there are two pairs
    {
        printf("Your hand has 2 pairs.\n"); // notify that there are 2 pairs
    }
}

// function to determine if the hand has a three of a kind
void threeOfKind(unsigned int hand[][2], char *suit[], char *face[])
{
    unsigned int counter[FACES] = {0};  // counter for how many cards of each face are present

    // for loop to count how many cards of each face are in the hand
    for (size_t f = 0; f < 5; ++f)
    {
        ++counter[hand[f][1]];  // increment counter
    }
    // for loop to check for three of a kind
    for (size_t t = 0; t < FACES; ++t)
    {
        if (counter[t] == 3)    // if there is a 3 of a kind
        {
            printf("Your hand has three %ss.\n", face[t]);  // print the 3 of a kind
        }
    }
}

// function to determine if the hand has a four of a kind
void fourOfKind(unsigned int hand[][2], char *suit[], char *face[])
{
    unsigned int counter[FACES] = {0};  // counter for how many cards of each face are present

    // for loop to count how many cards of each face are in the hand
    for (size_t f = 0; f < 5; ++f)
    {
        ++counter[hand[f][1]];  // increment counter
    }
    // for loop to check for 4 of a kind
    for (size_t fr = 0; fr < FACES; ++fr)
    {
        if (counter[fr] == 4)    // if there is a 4 of a kind
        {
            printf("Your hand has four %ss.\n", face[fr]);   // print the 4 of a kind
        }
    }
}

// function to determine if the hand has a flush
void flush(unsigned int hand[][2], char *suit[], char *face[])
{
    unsigned int count[SUITS] = { 0 };  // counter for how many cards of each suit are present
    
    // for loop to count how many cards of each suit are in the hand
    for (size_t s = 0; s < 5; ++s)
    {
        ++count[hand[s][0]];
    }
    // for loop to check for a flush
    for (size_t f = 0; f < SUITS; ++f)
    {
        if (count[f] == 5)  // if there is a flush
        {
            printf("Your hand has a flush of %ss.\n", suit[f]); // print the flush
        }
    }
}

// function to etermines if the hand has a straight
void straight(unsigned int hand[][2], char *suit[], char *face[])
{
    unsigned int s[5] = {0};    // array for copy of the hand
    unsigned int temp;          // temporary integer

    // copy column locations to sort
    for (size_t c = 0; c < 5; ++c)
    {
        s[c] = hand[c][1];
    }
    // use bubble sort to sort column locations
    for (size_t i = 1; i < 5; ++i)
    {
        for (size_t j = 0; j < 4; ++j)
        {
            if (s[j] > s[j + 1])
            {
                // swap
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    if (s[4] - 1 == s[3] && s[3] - 1 == s[2]        // if the sorted column is a straight
        && s[2] - 1 == s[1] && s[1] - 1 == s[0])
    {
        // print the straight
        printf("Your hand has a straight from %s to %s.\n", face[s[0]], face[s[4]]);
    }
}

/*
Sample Cases:

Your hand is:
 King of Hearts  
Eight of Spades  
 Nine of Spades  
Eight of Clubs   
 Jack of Spades  

Your hand has a pair of Eights.

Your hand is:
Seven of Spades  
  Ten of Hearts  
  Ten of Clubs   
 King of Clubs   
 King of Hearts  

Your hand has 2 pairs.
Your hand has a pair of Tens.
Your hand has a pair of Kings.

Your hand is:
  Ace of Spades  
 Four of Spades  
Three of Spades  
Deuce of Diamonds
 Five of Diamonds

Your hand has a straight from Ace to Five.

Your hand is:
Three of Hearts  
Eight of Diamonds
Three of Spades  
Queen of Spades  
Three of Clubs   

Your hand has three Threes.

Your hand is:
Queen of Clubs   
 King of Hearts  
Queen of Hearts  
 Jack of Clubs   
 King of Spades  

Your hand has 2 pairs.
Your hand has a pair of Queens.
Your hand has a pair of Kings.

Your hand is:
Deuce of Diamonds
  Ten of Diamonds
Three of Diamonds
Queen of Diamonds 
Eight of Diamonds

Your hand has a flush of Diamonds

Your hand is:
Deuce of Diamonds
Eight of Hearts  
 Five of Spades  
Three of Hearts  
 Nine of Hearts  

*/