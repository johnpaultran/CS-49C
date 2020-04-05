// Lab 6 Problem 2
#include <stdio.h>
#include <string.h>

// function main begins program execution
int main( void )
{
    char lines[100][1000];      // array to store input lines
    char c;                     // char to be inputted
    int lineCount = 0;          // total number of lines
    int wordCount = 0;          // total number of words
    printf("Enter input (insert blank line to stop):\n");

    for (int i = 0; i < 100; i++)       // loop to read/store lines
    {
        scanf("%c", &c);                // read next input char
        if(c == '\n')                   // if input is blank
        {
            break;                      // break out of loop
        }
        lineCount++;                    // increment number of lines
        for(int j = 0; j < 1000; j++)   // loop to read current line
        {
            lines[i][j] = c;            // add char to current line
            lines[i][j+1] = '\0';       // add null character to end string
            scanf("%c", &c);            // read next input char
            if(c == '\n')               // if input is blank
            {
                break;                  // break out of loop
            }
        }
    }

    for (int i = 0; i < lineCount; i++)             // loop to count number of words
    {
        char *currentWord = strtok(lines[i], " ");  // begin tokenizing sentence until NULL
        while(currentWord != NULL)                  // continue tokenizing sentence until NULL
        {
            wordCount++;                            // increment word count
            currentWord = strtok(NULL, " ");        // get next token
        }
    }
    
    // print total number of words
    printf("Total number of words: %d\n", wordCount);
}

/*
Sample Output:

Enter input (insert blank line to stop):
i like cats
cats are cool
dogs are furry and cute
i am allergic to dogs.

Total number of words: 16

*/