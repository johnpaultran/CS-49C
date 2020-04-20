// Homework 4 Problem 1
#include <stdio.h>
#include <string.h>

// structure for an employee containing their ID, name, and job title
struct employee
{
    int employeeId;
    char name[20];
    char jobTitle[20];
};

// function prototype
void sort(struct employee array[], int n);

// function main begins program execution
int main( void ) 
{
    struct employee record[30];         // array to hold employee information
    int flag = 0;                       // flag for when to stop taking input
    int count = 0;                      // counter for number of employees
 
    while (flag == 0)                   // while flag at 0, keep taking in employees
    {
        int id;                                     // variable for employee id
        printf("\nEnter employee ID number: ");     // prompt
        scanf("%d",&id);                            // enter id
        record[count].employeeId = id;              // insert id into employee records

        char name[20];                              // char array for employee name
        printf("Enter employee name: ");            // prompt
        scanf("%s", name);                          // enter name
        strcpy(record[count].name, name);           // insert name into employee records


        char jobTitle[20];                          // char array for job title
        printf("Enter employee job title: ");       // prompt
        scanf("%s", jobTitle);                      // enter job title
        strcpy(record[count].jobTitle, jobTitle);   // insert job title into employee records
        count++;                                    // increment number of employees

        char choice[2];                                     // char array for Y or N
        printf("Insert more employees? Enter Y or N: ");    // prompt
        scanf("%s", choice);                                // enter choice

        // to stop inputting employee records, but hasn't met requirement of >= 5 employees
        if (choice[0] == 'N' && count < 5)
        {
            printf("Need minimum of 5 employees in record\n");
        }
        // to stop inputting employee records
        else if (choice[0] == 'N')
        {
            flag++;                 // increment flag
        }
        // to continue inputtinf more employee records
        else if (choice[0] == 'Y')  
        {
            continue;               // continue to next iteration of loop
        }
    }

    sort(record,(count + 1));       // call to sort function to sort records in descending order

    // print the employee records
    printf("\nEmployee Records:\n");
    printf("-----------------\n");
    printf("%-10s%-19s%-19s\n", "ID:", "Name:", "Job Title:");
    for (int i = 0; i < count; i++)
    {
        printf("%-10d%-19s%-19s\n", record[i].employeeId, record[i].name, record[i].jobTitle);
    }
}

// function to sort records in descending order based on employee name
void sort(struct employee array[], int n)
{
    struct employee temp;   // temporary structure for swapping
    // use bubble sort to swap employee records
    for (int i = 0; i < n; i++)   
    {
        for (int j = i + 1; j < n-1; j++)
        {
            // swap if j comes after i
            if (strcmp(array[i].name, array[j].name) < 0)
            {
                // swap
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

/*
Sample Output:

Enter employee ID number: 12053
Enter employee name: Catherine
Enter employee job title: Manager
Insert more employees? Enter Y or N: Y

Enter employee ID number: 45392
Enter employee name: Jack
Enter employee job title: Chef
Insert more employees? Enter Y or N: Y

Enter employee ID number: 63912
Enter employee name: Adam
Enter employee job title: Waiter
Insert more employees? Enter Y or N: N
Need minimum of 5 employees in record

Enter employee ID number: 95862
Enter employee name: Zach
Enter employee job title: Janitor
Insert more employees? Enter Y or N: Y

Enter employee ID number: 29354
Enter employee name: Katrina
Enter employee job title: Hostess
Insert more employees? Enter Y or N: Y

Enter employee ID number: 82830
Enter employee name: Melvin
Enter employee job title: Waiter
Insert more employees? Enter Y or N: N

Employee Records:
-----------------
ID:       Name:              Job Title:         
95862     Zach               Janitor            
82830     Melvin             Waiter             
29354     Katrina            Hostess            
45392     Jack               Chef               
12053     Catherine          Manager            
63912     Adam               Waiter 
*/