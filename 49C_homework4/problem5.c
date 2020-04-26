// Homework 4 Problem 5
#include <stdio.h>
#include <stdlib.h>

// function main begins program execution
int main( void )
{
    int mastAcc;            // account from old master file
    int transAcc;           // account from transactions file
    double mastBal;         // balance from old master file
    double transBal;        // balance from transactions file
    char mastName[40];      // name from master file

    FILE *odfPtr;           // old master file pointer
    FILE *trfPtr;           // transactions file pointer
    FILE *nwfPtr;           // new master file pointer

    // opens file; exits if file cannot be opened
    if ((odfPtr = fopen("oldmast.dat", "r")) == NULL)
    {
        printf("Cannot open oldmast.dat\n");
    }
    // opens file; exits if file cannot be opened
    if ((trfPtr = fopen("trans.dat", "r")) == NULL)
    {
        printf("Cannot open trans.dat\n");
    }
    // opens file; exits if file cannot be opened
    if ((nwfPtr = fopen("newmast.dat", "r")) == NULL)
    {
        printf("Cannot open newmast.dat\n");
    }

    printf("Result:\n");  // display the account
    fscanf(trfPtr, "%d%lf", &transAcc, &transBal);

    while (!feof(trfPtr))   // while not at end of transactions file
    {
        // next record from old master file is read
        fscanf(odfPtr, "%d%[^0-9-]%lf", &mastAcc, mastName, &mastBal);
        // display accounts from master file until the time number of new account is reached
        while (mastAcc < transAcc && !feof(odfPtr))
        {
            fprintf(nwfPtr, "%d %s %.2f\n", mastAcc, mastName, mastBal);
            printf("%d %s %.2f\n", mastAcc, mastName, mastBal);

            // next record from old master file is read
            fscanf(odfPtr, "%d%[^0-9-]%lf", &mastAcc, mastName, &mastBal);
        }
        // if we find matching account, update balance and output account info
        if (mastAcc == transAcc)
        {
            mastBal += transBal;
            fprintf(nwfPtr, "%d %s %.2f\n", mastAcc, mastName, mastBal);
            printf("%d %s %.2f\n", mastAcc, mastName, mastBal);
        }
        // if transactions file is not matching with account from master file
        else if (mastAcc > transAcc)
        {
            printf("Unmatched transaction record for account %d\n", transAcc);
            fprintf(nwfPtr, "%d %s %.2f\n", mastAcc, mastName, mastBal);
            printf("%d %s %.2f\n", mastAcc, mastName, mastBal);
        }
        else
        {
            printf("Unmatched transaction record for account %d\n", transAcc);
        }
        // get next account/balance from transactions file
        fscanf(trfPtr, "%d%lf", &transAcc, &transBal); 
    }
    // display account number, name, and balance
    while (!feof(odfPtr))
    {
        fscanf(odfPtr, "%d%[^0-9-]%lf", &mastAcc, mastName, &mastBal);
        fprintf(nwfPtr, "%d %s %.2f\n", mastAcc, mastName, mastBal);
        printf("%d %s %.2f\n", mastAcc, mastName, mastBal);
    }
    // close all file pointers
    fclose(odfPtr);
    fclose(trfPtr);
    fclose(nwfPtr);
}

/*
Sample Output using reference files:

Result:
100   Alan Jones   375.31
300   Mary Smith   89.30
Unmatched transaction record for account 400
500   Sam Sharp   0.00
700   Suzy Green   -14.22
Unmatched transaction record for account 900
*/