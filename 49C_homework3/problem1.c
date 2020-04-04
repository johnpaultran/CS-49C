// Homework 3 Problem 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// function main begins program execution
int main( void )
{
    // initialize four arrays of pointers
    char *article[] = {"the" , "a", "one", "some", "any"};
    char *noun[] = {"boy", "girl", "dog", "town", "car"};
    char *verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
    char *preposition[] = {"to", "from", "over", "under", "on"};
    char sentence[100] = "";        // array to hold entire sentence

    srand((int) time (NULL));       // seed to ensure randomization
    for (int i = 0; i < 20; i++)    // for loop to generate 20 sentences
    {
        // create a sentence by selecting a word at random 
        // from each array in the following order
        // each word should be concatenated to the previous words 
        // the words should be separated by spaces

        // order of words to form sentences:
        // 1) article followed by a space
        strcat(sentence, article[rand() % 5]);
        strcat(sentence, " ");

        // 2) noun followed by a space
        strcat(sentence, noun[rand() % 5]);
        strcat(sentence, " ");

        // 3) verb followed by a space
        strcat(sentence, verb[rand() % 5]);
        strcat(sentence, " ");

        // 4) preposition followed by a space
        strcat(sentence, preposition[rand() % 5]);
        strcat(sentence, " " );

        // 5) article followed by a space
        strcat(sentence, article[rand() %5]);
        strcat(sentence, " " );

        // 6) noun
        strcat(sentence, noun[rand() % 5]);

        putchar(toupper(sentence[0]));  // start sentence with capitalized letter
        printf("%s.\n", &sentence[1]);  // end sentence with a period
        sentence[0] = '\0';             // erase sentence for next iteration of loop
    }
}

/*
Sample Outputs:

Some dog walked on a car.
The car ran to some dog.
Some girl walked over some town.
The boy skipped to the boy.
Some dog jumped over any car.
Any town walked on any girl.
The girl drove under some boy.
One girl jumped to the boy.
Any dog ran to one dog.
One dog skipped under one girl.
The town jumped to one dog.
One car walked on any girl.
The dog ran from one car.
Some town jumped to any boy.
Any town drove from any dog.
One car drove to any car.
One town drove to some boy.
Some town ran over a girl.
A boy ran on the girl.
Any dog jumped on some boy.

The car ran from a girl.
A town walked from some car.
Some dog drove under a boy.
One car skipped from some dog.
Any boy ran under some town.
Any boy ran on some boy.
The dog walked from some dog.
One town skipped under a dog.
Some girl jumped on any dog.
Some town ran to some dog.
Some car drove under some town.
Some girl drove over any boy.
Any girl skipped to a dog.
Some dog drove from a car.
Some boy skipped from the dog.
The girl ran to any dog.
Any dog drove from a girl.
One boy walked under some girl.
The town walked from any boy.
One town ran over a car.
*/