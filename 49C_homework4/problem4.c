// Homework 4 Problem 4
#include <stdio.h>
#include <string.h>    

// structure for hardware inventory records
struct hardwareInventory
{
    unsigned int record;
    char tool[40];
    unsigned int quantity;
    double cost;
};

// function prototypes
unsigned int choiceMenu(void);
void textFile(FILE *readPtr);
void updateRecord(FILE *filePtr);
void addRecord(FILE *filePtr);
void deleteRecord(FILE *filePtr);
void displayRecord(FILE *filePtr);

// function main begins program execution
int main( void )
{
    // initialize file pointers.
    FILE *datafilePtr;
    FILE *createFilePtr;
    struct hardwareInventory tools = {0, "", 0, 0.0};   // create tools w/ default info

    // loop until the file pointer to open the hardware.dat file is null.
    while ((datafilePtr = fopen("hardware.dat", "r+b")) == NULL)
    {
        // if file pointer is null then open hardware.dat again in write mode
        if ((createFilePtr = fopen("hardware.dat", "wb")) == NULL)
        {
            printf("File can not be open.\n" );         // exits if file cannot be opened
        }
        else
        {
            // loop for 100 records in the file
            for (int i = 1; i <= 100; i++ )
            {
                // initialize 100 empty records in hardware.dat
                fwrite(&tools, sizeof(struct hardwareInventory), 1, createFilePtr);
            }
            fclose(createFilePtr);                      // close file pointer
        }
    }

    // if the file pointer to open the file hardware.dat is still null
    if((datafilePtr = fopen("hardware.dat", "r+b")) == NULL)
    {
        printf("File can not be open.\n");      // exits if file cannot be opened
    }
    else
    {
        unsigned int choice;                    // unsigned int to store menu choice
        while((choice = choiceMenu()) != 6)     // loop until user wants to exit
        {
            switch (choice)                     // switch to execute menu choice
            {
                // create text file from record file
                case 1:
                    textFile(datafilePtr);
                    break;
                // update a record
                case 2:
                    updateRecord(datafilePtr);
                    break;
                // create a record
                case 3:
                    addRecord(datafilePtr);
                    break;
                // delete an existing record
                case 4:
                    deleteRecord(datafilePtr);
                    break;
                // display a record
                case 5:
                    displayRecord(datafilePtr);
                    break;
                // display message for invalid choice
                default:
                    printf("User choice is invalid\n");
                    break;
            }
        }
        fclose(datafilePtr);                    // close file
    }
}

// function to enable user to input menu choice
unsigned int choiceMenu( void )
{
    // display available options
    printf("%s", "\nYour choices are:\n"
    "1 - STORE a formatted text file of hardware called\n"
    "    \"hardware.txt\" for printing\n"
    "2 - UPDATE a record\n"
    "3 - ADD a new record\n"
    "4 - DELETE a record\n"
    "5 - DISPLAY a tool record\n"
    "6 - END program\n Selection : ");
    
    unsigned int menuChoice;   // to store menu choice
    scanf("%d", &menuChoice);  // enter choice
    return menuChoice;
}

// function to write the tool records to the text file
void textFile(FILE *readPtr)
{
    FILE *textFile;     // initialize file pointer to open text file

    if((textFile = fopen("hardware.txt", "w")) == NULL) // open the file hardware.txt file in write mode
    {
        printf("File cannot be open.");     // exits if file cannot be opened
    }
    else
    {
        rewind(readPtr);        // sets pointer to beginning of file
        // print table header
        fprintf(textFile, "%-10s %-20s%-10s%-10s\n","Record #", "Tool Name", "Quantity", "Cost");
        while(!feof(readPtr))   // copy all records from random-access file into text file
        {
            struct hardwareInventory tools = {0, "", 0, 0.0};   // create tools w/ default info
            int result = fread(&tools, sizeof(struct hardwareInventory), 1, readPtr);
            if(result != 0 && tools.record != 0)                // write single record to text file
            {
                fprintf(textFile, "%-8d %-20s %-10d %-10.2f\n", tools.record, 
                tools.tool, tools.quantity, tools.cost);     
            }
        }
        fclose(textFile);       // close file
    }
}

// function to to update a record in the file
void updateRecord(FILE *filePtr)
{
    unsigned int recordNum;                                     // record number to be updated
    printf("\nEnter the record number to update (1 - 100): ");  // prompt
    scanf("%d", &recordNum);                                    // enter record number

    // move file pointer to correct record in file
    fseek(filePtr, (recordNum - 1) * sizeof(struct hardwareInventory), SEEK_SET);
    struct hardwareInventory tools = {0, "", 0, 0.0};           // create tools w/ default info
    fread(&tools, sizeof(struct hardwareInventory), 1, filePtr);// read record from file
    
    // display message if record is empty
    if (tools.record == 0)
    {
        printf("Record #%d is empty.\n", recordNum);
    }
    else
    {
        printf("%-10d %-20s %-10d %-10f\n\n", tools.record,     // display olf record
        tools.tool, tools.quantity, tools.cost);
        unsigned int choice;                                    // user choice to update
        printf("1 = update name of the tool\n");
        printf("2 = update the quantity of the tool\n");
        printf("3 = update cost of tool\n");
        printf("4 = exit\nChoice: ");
        scanf("%d", &choice);                                   // enter user choice
        
        while (choice != 4)     // loop until user wants to exit
        {
            switch(choice)      // switch to execute user choice
            {
                case 1:
                    printf("Enter the new name of the tool: "); // prompt
                    while (getchar() != '\n');                  // user input
                    fgets(tools.tool, 39, stdin);               // store input as new name
                    int lastIndex = strlen(tools.tool) - 1;     // last index of name of tool
                    if (tools.tool[lastIndex] =='\n')
                    {
                        tools.tool[lastIndex] = '\0';           // add null character to end of string
                    }
                    break;
                case 2:
                    printf("Enter the new quantity: ");         // prompt
                    scanf("%d", &tools.quantity);               // enter new quantity
                    break;
                case 3:
                    printf("Enter the new cost of tool: ");     // prompt
                    scanf("%lf", &tools.cost);                  // enter new cost
                    break;
                // display message for invalid choice
                default:
                    printf("User choice is invalid");
                    break;
            }
            printf("\nChoice: ");                               // prompt for new user choice
            scanf("%d", &choice);
        }

        printf("%-10d %-20s %-10d %-10f\n\n", tools.record,     // display updated info
        tools.tool, tools.quantity, tools.cost);
        // move file pointer to correct record in file
        fseek(filePtr, (recordNum - 1) * sizeof(struct hardwareInventory), SEEK_SET);
        // write the updated record over old record in file     
        fwrite(&tools, sizeof(struct hardwareInventory), 1, filePtr);
    }
}

// function to add a record to the file
void addRecord(FILE *filePtr)
{
    struct hardwareInventory toolRec = { 0, "", 0, 0.0 };                   // create empty record
    printf("\nEnter record number (1 - 100, 0 to return to main menu): ");  // prompt
    scanf("%d", &toolRec.record );                                          // enter record number

    if(toolRec.record < 0 || toolRec.record > 100)      // if the record number is not between 0-100
    {
        printf("Invalid record number inserted.\n");    // display message for invalid record number
    }
    else
    {
        while(toolRec.record != 0)                      // loop until user exits
        {
            printf("Enter the name of the tool: ");     // prompt
            while (getchar() != '\n');                  // user input
            fgets(toolRec.tool, 39, stdin);             // store input as new name
            int lastIndex = strlen(toolRec.tool)-1;     // last index of name of tool
            if (toolRec.tool[lastIndex] == '\n')
            {
                toolRec.tool[lastIndex] = '\0';         // add null character to end of string
            }
            printf("Enter the quantity of the tool: "); // prompt
            scanf("%d", &toolRec.quantity);             // enter a new quantity
            printf("Enter the cost of tool: " );        // prompt
            scanf("%lf", &toolRec.cost);                // enter a new cost

            // move file pointer to correct record in file            
            fseek(filePtr, (toolRec.record - 1) * sizeof(struct hardwareInventory), SEEK_SET);
            // insert record in file   
            fwrite(&toolRec, sizeof(struct hardwareInventory), 1, filePtr);
            // prompt for user to continue
            printf("\nEnter another record number, enter 0 to exit: ");
            scanf("%d", &toolRec.record );
        }
    }
}

// function to delete a record from the file
void deleteRecord(FILE *filePtr)
{
    unsigned int recordNum;                                     // record number to be deleted
    printf("\nEnter a record number to delete (1 - 100): ");    // prompt
    scanf("%d", &recordNum);                                    // enter record number

    // move file pointer to correct record in file          
    fseek(filePtr, (recordNum - 1) * sizeof(struct hardwareInventory), SEEK_SET);
    struct hardwareInventory toolRec;                               // stores record read from file
    fread(&toolRec, sizeof(struct hardwareInventory), 1, filePtr);  // read record from file
    if(toolRec.record == 0)
    {
        printf("Record #%d does not exist.\n", recordNum);          // if error does not exist
    }
    else
    {
        // move file pointer to correct record in file         
        fseek(filePtr, (recordNum - 1) * sizeof(struct hardwareInventory), SEEK_SET);
        struct hardwareInventory emptyRec = {0, "", 0, 0.00};               // create empty record
        fwrite(&emptyRec, sizeof(struct hardwareInventory), 1, filePtr);    // replace w/ empty
    }
}

// function to display a record in the file
void displayRecord(FILE *filePtr)
{
    unsigned int recordNum;                                     // record number to display
    printf("\nEnter a record number to display (1 - 100): ");   // prompt
    scanf("%d", &recordNum);                                    // enter recorf number

    // move file pointer to correct record in file
    fseek(filePtr, (recordNum - 1) * sizeof(struct hardwareInventory), SEEK_SET);
    struct hardwareInventory toolRec = {0, "", 0, 0.0};             // create empty record
    fread(&toolRec, sizeof(struct hardwareInventory), 1, filePtr);  // read record from file
    if(toolRec.record == 0)
    {
        printf("Record #%d does not exist.\n", recordNum);  // if record number is 0
    }
    else
    {
        // move file pointer to correct record in file
        fseek(filePtr, (recordNum - 1) * sizeof(struct hardwareInventory), SEEK_SET);
        if(toolRec.record != 0 )
        {
            printf("%-10d %-20s %-10d %-10.2f\n", toolRec.record,   // print record number info
            toolRec.tool, toolRec.quantity, toolRec.cost);
        }
        else
        {
            printf("Record does not exist.\n");                      // record does not exist
        }
    }
}

/* 
Sample Output:

Your choices are:
1 - STORE a formatted text file of hardware called
    "hardware.txt" for printing
2 - UPDATE a record
3 - ADD a new record
4 - DELETE a record
5 - DISPLAY a tool record
6 - END program
 Selection : 3

Enter record number (1 - 100, 0 to return to main menu): 3
Enter the name of the tool: Electric sander
Enter the quantity of the tool: 7
Enter the cost of tool: 57.98

Enter another record number, enter 0 to exit: 17
Enter the name of the tool: Hammer
Enter the quantity of the tool: 76
Enter the cost of tool: 11.99

Enter another record number, enter 0 to exit: 24
Enter the name of the tool: Jig saw
Enter the quantity of the tool: 21
Enter the cost of tool: 11.00

Enter another record number, enter 0 to exit: 39
Enter the name of the tool: Lawn mower
Enter the quantity of the tool: 3
Enter the cost of tool: 79.50

Enter another record number, enter 0 to exit: 56
Enter the name of the tool: Power saw
Enter the quantity of the tool: 18
Enter the cost of tool: 99.99

Enter another record number, enter 0 to exit: 68
Enter the name of the tool: Screwdriver
Enter the quantity of the tool: 106
Enter the cost of tool: 6.99

Enter another record number, enter 0 to exit: 77
Enter the name of the tool: Sledge hammer
Enter the quantity of the tool: 11
Enter the cost of tool: 21.50

Enter another record number, enter 0 to exit: 83
Enter the name of the tool: Wrench
Enter the quantity of the tool: 34
Enter the cost of tool: 7.50

Enter another record number, enter 0 to exit: 0

Your choices are:
1 - STORE a formatted text file of hardware called
    "hardware.txt" for printing
2 - UPDATE a record
3 - ADD a new record
4 - DELETE a record
5 - DISPLAY a tool record
6 - END program
 Selection : 2

Enter the record number to update (1 - 100): 68
68         Screwdriver          106        6.990000  

1 = update name of the tool
2 = update the quantity of the tool
3 = update cost of tool
4 = exit
Choice: 2
Enter the new quantity: 112

Choice: 4
68         Screwdriver          112        6.990000  

Your choices are:
1 - STORE a formatted text file of hardware called
    "hardware.txt" for printing
2 - UPDATE a record
3 - ADD a new record
4 - DELETE a record
5 - DISPLAY a tool record
6 - END program
 Selection : 3

Enter record number (1 - 100, 0 to return to main menu): 20
Enter the name of the tool: Mallet
Enter the quantity of the tool: 6
Enter the cost of tool: 4.85

Enter another record number, enter 0 to exit: 0

Your choices are:
1 - STORE a formatted text file of hardware called
    "hardware.txt" for printing
2 - UPDATE a record
3 - ADD a new record
4 - DELETE a record
5 - DISPLAY a tool record
6 - END program
 Selection : 4

Enter a record number to delete (1 - 100): 20

Your choices are:
1 - STORE a formatted text file of hardware called
    "hardware.txt" for printing
2 - UPDATE a record
3 - ADD a new record
4 - DELETE a record
5 - DISPLAY a tool record
6 - END program
 Selection : 5

Enter a record number to display (1 - 100): 56
56         Power saw            18         99.99     

Your choices are:
1 - STORE a formatted text file of hardware called
    "hardware.txt" for printing
2 - UPDATE a record
3 - ADD a new record
4 - DELETE a record
5 - DISPLAY a tool record
6 - END program
 Selection : 1

Your choices are:
1 - STORE a formatted text file of hardware called
    "hardware.txt" for printing
2 - UPDATE a record
3 - ADD a new record
4 - DELETE a record
5 - DISPLAY a tool record
6 - END program
 Selection : 9
User choice is invalid

Your choices are:
1 - STORE a formatted text file of hardware called
    "hardware.txt" for printing
2 - UPDATE a record
3 - ADD a new record
4 - DELETE a record
5 - DISPLAY a tool record
6 - END program
 Selection : 6

Following is the resulting text file:

Record #   Tool Name           Quantity  Cost      
3        Electric sander      7          57.98     
17       Hammer               76         11.99     
24       Jig saw              21         11.00     
39       Lawn mower           3          79.50     
56       Power saw            18         99.99     
68       Screwdriver          112        6.99      
77       Sledge hammer        11         21.50     
83       Wrench               34         7.50 
*/