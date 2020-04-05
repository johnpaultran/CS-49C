// Homework 3 Problem 5
#include<stdio.h>
#include<string.h>
#include<ctype.h>

// function prototypes
void convertToLower(char string[1000]);
void countLetterOccurrences(char string[1000]);
void countWordsLength(char string[1000]);
void countWordOccurrences(char myString[1000]);

// function main begins program execution
int main( void )
{
    char string[1000];                  // initialize string to be inputted
    printf("Enter a string: \n");       // prompt
    scanf("%[^\n]",string);             // get string with spaces from user
    countLetterOccurrences(string);     // call to count occurences of each letter in string
    countWordsLength(string);           // call to count the number of words of a certain length
    countWordOccurrences(string);
}

// function to convert string to lowercase
void convertToLower(char string[1000])
{
    for (int i = 0; i < strlen(string); i++)        // for each char in string
    {
        if (string[i] >= 'A' && string[i] <= 'Z')   // if char is uppercase
        {
            string[i] = tolower(string[i]);         // convert to lowercase
        }
    }
}

// function to count occurences of each letter in alphabet
void countLetterOccurrences(char string[1000])
{
    char letterCount[26][2];                // array for each letter and their count
    convertToLower(string);                 // convert string to lowercase

    for (int i = 0; i < 26; i++)            // for loop for each letter of alphabet
    {
        letterCount[i][0] = 97 + i;         // first element in each row = a letter of alphabet
        letterCount[i][1] = 0;              // second element of each row = count
    }
    
    for (int i = 0; i < strlen(string); i++)            // loop for each char in string
    {
        if (string[i] >= 'a' && string[i] <= 'z')       // if char is a letter from a-z
        {
            letterCount[string[i]-97][1]++;;            // increment specified letter's count by 1
        }
    }

    // print the results in tabular format
    printf("\nLetter | Occurrences\n");
    printf("--------------------\n");
    for (int i = 0; i < 26; i++)
    {
        printf("%-8c%d\n", letterCount[i][0], letterCount[i][1]);
    }
}

// function to count number of words of different lengths
void countWordsLength(char string[1000])
{
    int wordsLength[15][2];                 // array to store length of word and count

    for (int i = 0; i < 15; i++)            // for each word of length up to 15
    {
        wordsLength[i][0] = i + 1;          // first element in each row is word length
        wordsLength[i][1] = 0;              // second element in each row is count
    }
    char *currentWord = strtok(string," "); // begin tokenizing string until NULL
    while (currentWord != NULL)             // continue tokenizing sentence until NULL
    {
        int length = strlen(currentWord);   // length of current word
        if (length <= 15)
        {
            wordsLength[length - 1][1]++;   // increment count of specified word length
        }
        currentWord = strtok(NULL, " ");    // get next token
    }

    // print the results in tabular format
    printf("\nWord Length | Occurrences\n");
    printf("-------------------------\n");
    for (int i = 0; i < 15; i++)
    {
        printf("%d\t\t\t %d\n",wordsLength[i][0],wordsLength[i][1]);
    }
}

// function to count the occurrence of unique words
void countWordOccurrences(char string[1000])
{
    char totalWord[100][1000];      // array to store each unique word
    int wordCountList[100] = {0};   // array for count of each unique word
    int wordCount = 0;              // count for number of words
    int i = 0;                      // for loop iteration

    while (string[i]!='\0')         // loop thru each char until null
    {
        char currentWord[1000];     // array to copy the word
        int j = 0;                  // for loop iteration
      
        while (string[i] != ' ' && string[i] != '\0')   // tokenizing string
        {
            currentWord[j++] = string[i++];             // copy string into word
        }
      
        // if last char is a punctuation mark
        if (currentWord[j - 1] == ',' || currentWord[j - 1] == ':' || currentWord[j - 1] == ';' || currentWord[j - 1] == '.')
        {
            currentWord[j - 1] = '\0';          // replace with null char
        }

        currentWord[j] = '\0';                  // add null char to end
        int found = -1;                         // flag for matched word
      
        for (j = 0; j < wordCount; j++)         // loop for total words
        {
            if (strcmp(totalWord[j], currentWord) == 0)             // if current word found a match
            {
                found = j;                                          // set index of totalWord to found
                wordCountList[found] = wordCountList[found] + 1;    // increment count of that word
                break;                                              // break out of loop
            }
        }
      
        if (found < 0)  // if match wasn't found
        {
            wordCountList[wordCount] = wordCountList[wordCount] + 1;    // increment count of new word
            strcpy(totalWord[wordCount++], currentWord);                // copy new unique word into array   
        }
        i++;            // increment i
    }

    // print the results in tabular format
    printf("\n Unique Word  |  Occurrences\n");
    printf("-----------------------------\n");
    for (int i = 0; i < wordCount; i++)
    {
        printf("%-15s%d\n", totalWord[i], wordCountList[i]);
    }
}

/*
Sample Output:

Enter a string: 
There are a ton of dogs and cats in the house and even more cats and dogs outside

Letter | Occurrences
--------------------
a       7
b       0
c       2
d       6
e       9
f       1
g       2
h       3
i       2
j       0
k       0
l       0
m       1
n       6
o       7
p       0
q       0
r       3
s       6
t       6
u       2
v       1
w       0
x       0
y       0
z       0

Word Length | Occurrences
-------------------------
1            1
2            2
3            6
4            6
5            2
6            0
7            1
8            0
9            0
10           0
11           0
12           0
13           0
14           0
15           0

 Unique Word  |  Occurrences
-----------------------------
there          1
are            1
a              1
ton            1
of             1
dogs           2
and            3
cats           2
in             1
the            1
house          1
even           1
more           1
outside        1

Enter a string: 
Whether 'tis nobler in the mind to suffer

Letter | Occurrences
--------------------
a       0
b       1
c       0
d       1
e       5
f       2
g       0
h       3
i       3
j       0
k       0
l       1
m       1
n       3
o       2
p       0
q       0
r       3
s       2
t       4
u       1
v       0
w       1
x       0
y       0
z       0

Word Length | Occurrences
-------------------------
1            0
2            2
3            1
4            2
5            0
6            2
7            1
8            0
9            0
10           0
11           0
12           0
13           0
14           0
15           0

 Unique Word  |  Occurrences
-----------------------------
whether        1
'tis           1
nobler         1
in             1
the            1
mind           1
to             1
suffer         1

Enter a string: 
To be, or not to be: that is the question:

Letter | Occurrences
--------------------
a       1
b       2
c       0
d       0
e       4
f       0
g       0
h       2
i       2
j       0
k       0
l       0
m       0
n       2
o       5
p       0
q       1
r       1
s       2
t       7
u       1
v       0
w       0
x       0
y       0
z       0

Word Length | Occurrences
-------------------------
1            0
2            4
3            4
4            1
5            0
6            0
7            0
8            0
9            1
10           0
11           0
12           0
13           0
14           0
15           0

 Unique Word  |  Occurrences
-----------------------------
to             2
be             2
or             1
not            1
that           1
is             1
the            1
question       1
*/