// Homework 2 Problem 5 Extra Credit
/*
MAIN CHANGES:

takeOut (remove) function now first checks for matching table size
i.e. if input is 6, iterates through array to find first matching table of 6
if a match is found, then seatFound (indicator for a match) is set to 1

if a match is not found, then seatFound is still at 0
function now iterates through array looking for the first table size less than input table size
to be taken off the waitlist. if match is found, seatFound is set to 1

if a match is still not found (seatFound still at 0)
then there is no waitlist entry that fits the input table size
*/
#include <stdio.h>
#include <string.h>

int counter;                      // counter to count people on waitlist
char name[1000][50], item[50];    // array for names, name to be inserted
int tableSize[1000];              // array for table size

// function to insert name and table size to waitlist
void insert(char item[50], int number)
{
    // first check if new party matches already existing party on waitlist 
    for (int i = 0; i <= counter; i++)              // for each item in name array
    {
        if (strcmp(&name[i][0], item) == 0)         // if there is already an identical name
        {
            printf("Repeated name not allowed.\n"); // repeated names not allowed
            printf("Please try again!\n");          // ask to try again
            break;                                  // break out of loop 
        }
        else 
        {
            counter++;                          // increment counter each time you add to waitlist
            strcpy(name[counter-1], item);      // add name to back of waitlist
            tableSize[counter-1] = number;      // add table size to back of waitlist
            break;                              // break out of loop
        }
    }
}

// modified remove function to fit extra credit criteria
// remove function to take out a waiting list entry of table size matches available table
void takeOut(int seatSize)
{
    int seatFound = 0;      // indicates if a seat is found
    int temp;               // temporary int for swapping
    char ntemp[50];         // temporary string for swapping
    
    // new condition to seat the next table available to the largest entry that fits its size
    for (int i = 0; i < counter; i++)  // for loop to go through waitlist
    {
        if (tableSize[i] == seatSize)   // if a party's table size matches available seat size
        {
            // table size swapping
            for(int k = i; k < counter - 1; k++)    // for each element in array
            {
                temp = tableSize[k];                // temp keep next number
                tableSize[k] = tableSize[k+1];      // swap the order with next one
                tableSize[k + 1] = temp;            // swap
            }
            
            // name swapping
            for(int k = i;k < counter - 1; k++)     // for each element in array
            {
                strcpy(name[k],ntemp);          // temp keep next number
                strcpy(name[k],name[k+1]);      // swap the order with next one
                strcpy(name[k + 1],ntemp);      // swap
            }

            counter--;                  // decrement counter since we are seating a table
            seatFound = 1;              // seat has been found
            printf("Seat found!\n");    // prompt
            break;                      // break out of loop once seat is found
        } 
    } 

    // if there is still no match, then look for the next table that fits
    if (seatFound == 0)
    {
        for (int i = 0; i < counter; i++)  // for loop to go through waitlist
        {
            if (tableSize[i] < seatSize)   // if a party's table size < available seat size
            {
                // table size swapping
                for(int k = i; k < counter - 1; k++)    // for each element in array
                {
                    temp = tableSize[k];                // temp keep next number
                    tableSize[k] = tableSize[k+1];      // swap the order with next one
                    tableSize[k + 1] = temp;            // swap
                }
            
                // name swapping
                for(int k = i;k < counter - 1; k++)     // for each element in array
                {
                    strcpy(name[k],ntemp);          // temp keep next number
                    strcpy(name[k],name[k+1]);      // swap the order with next one
                    strcpy(name[k + 1],ntemp);      // swap
                }

                counter--;                  // decrement counter since we are seating a table
                seatFound = 1;              // seat has been found
                printf("Seat found!\n");    // prompt
                break;                      // break out of loop once seat is found
            }
        } 
    }

    if (seatFound == 0) // if seat still is not found (no matching table size)
    {
        printf("No waitlist entry matches available table size.\n");   // prompt
    }
}

// show list function to display waitlist from oldest party (top) to newest (bottom)
void showList()
{
    for (int i = 0; i < counter; i++) // for each element in arrays
    {
        // print name & table size by first to last (top to bottom)
        printf("Name: %s\t # of people: %d", &name[i][0], tableSize[i]);
        printf("\n");   // new line for clarity
    }
}

// function main begins program execution
int main( void )
{
    int flag = 0;       // flag for when to terminate program
    int command;        // command to be given
    int seatSize;       // seat size to be passed to remove function
    int tempnumber;     // number to be given to waiting list

    printf("Welcome to Restaurant Waiting List!\n\n");
    // menu of possible commands
    printf("Menu of commands: \n");
    printf("1 = insert lowercase name & number of people to bottom of waiting list\n");
    printf("2 = removes oldest entry with specified table size from the waitlist\n");
    printf("3 = shows the waitlist of names & numbers from oldest to newest\n");
    printf("4 = quits the waiting list program\n");
    // while flag is still at 0, keep iterating
    while (flag == 0)
    {
        printf("\nEnter command: \n");    // prompt
        scanf("%d", &command);            // enter command
        // command 1 is to insert name and table size to waiting list
        if (command == 1)
        {
            printf("Enter name & table size: " );    // prompt
            scanf("%s %d", &item[50], &tempnumber);  // enter name and table size
            insert(&item[50], tempnumber);           // call to insert function
        }
        // command 2 is to remove first party matching available seat size
        else if (command == 2)
        {
            printf("What is the available table size?\n");  // prompt
            scanf("%d", &seatSize);                         // enter seat size
            takeOut(seatSize);                              // call to remove function
        }
        // command 3 is to display the current waiting list from first to last (top to bottom)
        else if (command == 3)
        {
            printf("Current wait list:\n"); // prompt
            showList();                     // call to show list function
        }
        // command 4 quits the program
        else if (command == 4)
        {
            flag = 1; // set flag to 1 (terminates loop)
            printf("\nWaiting List is now closed.");
        }
    }
}

/*
Sample Case:

Welcome to Restaurant Waiting List!

Menu of commands:
1 = insert lowercase name & number of people to bottom of waiting list
2 = removes oldest entry with specified table size from the waitlist
3 = shows the waitlist of names & numbers from oldest to newest
4 = quits the waiting list program

Enter command:
1
Enter name & table size: peter 4

Enter command:
1
Enter name & table size: joseph 7

Enter command:
1
Enter name & table size: jack 2

Enter command:
1
Enter name & table size: megan 3

Enter command:
1
Enter name & table size: hank 2

Enter command:
1
Enter name & table size: mary 1

Enter command:
3
Current wait list:
Name: peter  # of people: 4
Name: joseph     # of people: 7
Name: jack   # of people: 2
Name: megan  # of people: 3
Name: hank   # of people: 2
Name: mary   # of people: 1

Enter command:
2
What is the available table size?
3
Seat found!

Enter command:
3
Current wait list:
Name: peter  # of people: 4
Name: joseph     # of people: 7
Name: jack   # of people: 2
Name: hank   # of people: 2
Name: mary   # of people: 1

Enter command:
2
What is the available table size?
3
Seat found!

Enter command:
3
Current wait list:
Name: peter  # of people: 4
Name: joseph     # of people: 7
Name: hank   # of people: 2
Name: mary   # of people: 1

Enter command:
2
What is the available table size?
7
Seat found!

Enter command:
3
Current wait list:
Name: peter  # of people: 4
Name: hank   # of people: 2
Name: mary   # of people: 1

Enter command:
2
What is the available table size?
3
Seat found!

Enter command:
3
Current wait list:
Name: peter  # of people: 4
Name: mary   # of people: 1

Enter command:
1
Enter name & table size: tony 5

Enter command:
1
Enter name & table size: steve 5

Enter command:
3
Current wait list:
Name: peter  # of people: 4
Name: mary   # of people: 1
Name: tony   # of people: 5
Name: steve  # of people: 5

Enter command:
2
What is the available table size?
5
Seat found!

Enter command:
3
Current wait list:
Name: peter  # of people: 4
Name: mary   # of people: 1
Name: steve  # of people: 5

Enter command:
2
What is the available table size?
1
Seat found!

Enter command:
3
Current wait list:
Name: peter  # of people: 4
Name: steve  # of people: 5

Enter command:
2
What is the available table size?
3
No waitlist entry matches available table size.

Enter command:
1
Enter name & table size: peter 3
Repeated name not allowed.
Please try again!

Enter command:
1
Enter name & table size: jack 2

Enter command:
3
Current wait list:
Name: peter  # of people: 4
Name: steve  # of people: 5
Name: jack   # of people: 2

Enter command:
4

Waiting List is now closed.
*/