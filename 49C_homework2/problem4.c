// Homework 2 Problem 4
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// boolean function to determine if a character is a vowel
bool isVowel(char c)
{
    // returns true if character is a vowel
    return (c == 'A' || c == 'E' || c == 'I' ||  
            c == 'O' || c == 'U' || c == 'a' ||  
            c == 'e' || c == 'i' || c == 'o' || 
            c == 'u'); 
}

// function to translate english word to pig latin
void pigLatin(char english[])
{
    char piglatin[50];          // piglatin translated string to be printed
    char consonants[5];         // array for up to 1st 4 consonants in english word
    char restOfSent[45];        // array for rest of sentence once a vowel is hit
    char firstVowel[] = "yay";  // string added to end of word if first letter is a vowel
    char firstCons[] = "ay";    // string added to end of word if first letter is a consonant

    if (isVowel(english[0]) == true)    // if first letter is a vowel
    {
        strcat(english, firstVowel);    // combine "yay" to end of string
        strcpy(piglatin, english);      // copy new string into piglatin
    }
    else    // if first letter is not a vowel
    {
        for (int i = 0; english[i] != '\0'; i++)    // for loop for each letter in english word
        {
            if (english[i] == 'q' && english[i+1] == 'u')   // special case for 'qu' to be paired
            {
                char qu[] = "qu";       // create array for qu to be together
                strcat(consonants, qu); // add qu to string of consonants to be moved to end
                i++;                // increment i to skip over u in next iteration of for loop
            }
            else if (isVowel(english[i]) == false)  // if letter is not a consonant
            {
                // special case for y to be treated as a vowel after the first char in a word
                if (i > 0 && (english[i] == 'y' || english[i] == 'Y')) 
                {
                    for (int j = i; english[j] != '\0'; j++)    // for loop for rest of chars in english word
                    {
                        char temp = english[j];         // copy current character
                        strncat(restOfSent, &temp, 1);  // place in string of chars after leading consonants
                    }
                    break;  // break out of the for loop, no need to iterate through rest of word
                }
                char temp = english[i];         // copy current leading consonant character
                strncat(consonants, &temp, 1);  // place in string of leading consonants
            }
            else    // if the character is a vowel
            {
                for (int j = i; english[j] != '\0'; j++)    // for loop for rest of chars in english word
                {
                    char temp = english[j];         // copy current character
                    strncat(restOfSent, &temp, 1);  // place in string of chars after leading consonants
                }
                break;  // break out of the for loop, no need to iterate through rest of word
            }
        }
        strcat(restOfSent, consonants); // move all leading consonants to the end of the word
        strcat(restOfSent, firstCons);  // combine "ay" to end of string
        strcpy(piglatin, restOfSent);   // copy new string into piglatin
    }
    // print the pig lation translation of english word
    printf("Pig Latin translation is: \n%s", piglatin);
}

// function main begins program execution
int main( void )
{
    char english[50];                   // english word to be translated
    printf("Enter English word: \n");   // prompt
    scanf("%s", english);               // enter english word
    pigLatin(english);                  // call to translate function
}

/*
Sample Cases:

Enter English word:
yes
Pig Latin translation is:
esyay

Enter English word:
example
Pig Latin translation is:
exampleyay

Enter English word:
bygone
Pig Latin translation is:
ygonebay

Enter English word:
test
Pig Latin translation is:
esttay

Enter English word:
quiz
Pig Latin translation is:
izquay

Enter English word:
strip
Pig Latin translation is:
ipstray

Enter English word:
trips
Pig Latin translation is:
ipstray

// works w uppercase letters

Enter English word:
sChNitZel
Pig Latin translation is:
itZelsChNay

Enter English word:
RHYME
Pig Latin translation is:
YMERHay
*/