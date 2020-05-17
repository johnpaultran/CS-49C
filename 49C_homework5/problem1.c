// Homework 5 Problem 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// given stack structure
struct stackNode
{
    char data;
    struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

// function prototypes
void push(StackNodePtr *topPtr, int value);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr topPtr);
int calculate(int op1, int op2, char operator);
int evaluatePostfixExpression(char *expr);

// function main begins program execution
int main( void )
{
    char post[100];             // character array to hold postfix expression
    printf("Enter postfix expression: ");    // prompt
    fgets(post, 100, stdin);    // user inputs postfix expression
    // call to evaluatePostfix and print the value
    printf("Result is %d\n", evaluatePostfixExpression(post));
}

// function to push a value on to the stack (fig 12.8)
void push(StackNodePtr *topPtr, int value)
{
    StackNodePtr newNodePtr;                // pointer to new node
    newNodePtr = malloc(sizeof(StackNode)); // if memory was allocated then assign data
    if (newNodePtr != NULL)
    {
        newNodePtr->data = value;
        newNodePtr->nextPtr = *topPtr;
        *topPtr = newNodePtr;
    }
    else    // there is no more available space
    {
        printf("%d not inserted (no available memory)\n", value);
    }
}

// function to pop a value off the stack (fig 12.8)
int pop(StackNodePtr *topPtr)
{
    StackNodePtr tempNodePtr;       // pointer to temporary node
    int popNode;                    // value of node

    tempNodePtr = *topPtr;
    popNode = (*topPtr)->data;
    *topPtr = (*topPtr)->nextPtr;
    free(tempNodePtr);

    return popNode;
}

// function to print the stack (fig 12.8)
void printStack(StackNodePtr topPtr)
{
    if (topPtr == NULL) // if the stack is empty
    {
        // print notification for empty stacl
        printf("The stack is empty\n");
    }
    else 
    {
        printf("The stack is: \n");
        // while end of stack is not reached
        while(topPtr != NULL)
        {
            printf("%d -> ", topPtr->data); // print node value
            topPtr = topPtr->nextPtr;       // point to next node
        }
        printf("NULL\n\n");                 // end of stack
    }
}

// function to determine if the stack is empty (fig 12.8)
int isEmpty(StackNodePtr topPtr)
{
    // return 1 if stack is empty or 0 if not empty
    return topPtr == NULL;
}

// function to evaluate the expression (op1) operator (op2)
int calculate(int op1, int op2, char operator)
{
    int result = 0;     // int to hold result of evaluation
    switch (operator)   // switch depending on argument operator
    {
        // each case executes its operator symbol
        case '+':
            result = op1 + op2;
            break;
        case '-':
            result = op1 - op2;
            break;
        case '*':
            result = op1 * op2;
            break;
        case '/':
            result = op1 / op2;
            break;
        case '%':
            result = op1 % op2;
            break;
        case '^':
            result = op1 ^ op2;
            break;
    }      
    return result;      // return the result
}

// function to evaluate the postfix expression
int evaluatePostfixExpression(char *expr)
{
    StackNodePtr stackPtr = NULL;       // points to the top of stack
    int i;                              // int for loop iteration

    for(i = 0; expr[i]; ++i)            // for each char in char array
    {
        if(isdigit(expr[i]))            // if char is a digit (1-9) function is from ctype header
        {
            push(&stackPtr, expr[i] - '0');  // push the digit onto the stack
        }
        // if the char is an operator
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' ||
        expr[i] == '/' || expr[i] == '%' || expr[i] == '^')
        {
            int val1 = pop(&stackPtr);      // pop first node value
            int val2 = pop(&stackPtr);      // pop second node value
            int val3 = calculate(val2, val1, expr[i]);  // calculate the expression between val 1 & 2
            push(&stackPtr, val3);          // push result onto stack
        }
        else if (expr[i] == ' ')        // if there is a space
        {
            continue;                   // continue to next char in array
        }
    }
    return pop(&stackPtr);              // return top of stack
}

/*
Sample Cases:

Enter postfix expression: 6 2 + 5 * 8 4 / -
Result is 38

Enter postfix expression: 4 2 + 3 5 1 - * +
Result is 18

Enter postfix expression: 5 7 + 6 2 - *
Result is 48

Enter postfix expression: 4 2 3 5 1 - + * +
Result is 18
*/