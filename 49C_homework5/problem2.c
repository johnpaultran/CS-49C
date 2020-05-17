// Homework 5 Problem 2 (modify fig 12.19 to create and use delete function)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// self referential structure
struct treeNode 
{
    struct treeNode *leftPtr;   // left subtree pointer
    int data;                   // value of node
    struct treeNode *rightPtr;  // right subtree pointer
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

// function prototypes
void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);
void deleteNode(TreeNodePtr *treePtr, int value);

// function main begins program execution
int main( void )
{
    TreeNodePtr rootPtr = NULL; // empty tree
    int i;                      // loop counter
    int random;                 // integer to hold random values

    srand(time( NULL ));        // seed for random number generation
    printf("The numbers being placed in the tree are:\n");

    // insert random values between 0-14 into tree
    for (i = 1; i <= 10; i++) 
    {
        random = rand() % 15;           // generate random number (0-14)
        printf("%3d", random);          // print random number
        insertNode(&rootPtr, random);   // insert into tree
    }

    // traverse preOrder
    printf("\n\nThe preOrder traversal is:\n" );
    preOrder(rootPtr);

    // traverse inOrder
    printf("\n\nThe inOrder traversal is:\n" );
    inOrder(rootPtr);

    // traverse postOrder
    printf("\n\nThe postOrder traversal is:\n" );
    postOrder(rootPtr);

    printf("\n\nEnter the node to delete: \n"); // prompt
	scanf("%d", &random);                       // input node to delete
	deleteNode(&rootPtr, random);               // call to delete node function

    // print the pre, in & post order again to show that node got deleted from tree
    printf("\nThe preOrder traversal is:\n");
	preOrder(rootPtr );

	printf("\n\nThe inOrder traversal is:\n");
	inOrder(rootPtr);

	printf("\n\nThe postOrder traversal is:\n");
	postOrder(rootPtr);

	printf("\n");   // new line for clarity
}

// function to insert node into tree (fig 12.19)
void insertNode(TreeNodePtr *treePtr, int value)
{
    if (*treePtr == NULL)                       // if tree is empty
    {
        *treePtr = malloc(sizeof(TreeNode));    // if memory was allocated then assign data
        if ( *treePtr != NULL ) 
        {
            ( *treePtr )->data = value;
            ( *treePtr )->leftPtr = NULL;
            ( *treePtr )->rightPtr = NULL;
        }
        else        // there is no more available space
        {
            printf("%d not inserted (no available memory)\n", value);
        }
    }
    else            // tree not empty
    {
        if (value < ( *treePtr )->data)         // if data to insert < data in current node
        {                   
            insertNode(&((*treePtr)->leftPtr), value);  // insert in left subtree
        }                                   
        else if (value > ( *treePtr )->data)    // data to insert > data in current node
        {                 
            insertNode(&((*treePtr)->rightPtr), value); // insert in right subtree 
        }                                    
        else
        {
            printf("dup");  // duplicate data will be ignored
        }
    }
}

// function for inorder traversal (fig 12.19)
void inOrder(TreeNodePtr treePtr)
{
    if (treePtr != NULL)    // if tree is not empty
    {                
        inOrder(treePtr->leftPtr);      // left subtree
        printf("%3d", treePtr->data);   // root
        inOrder(treePtr->rightPtr);     // right subtree
    }                         
}

// function for preorder traversal of tree (fig 12.19)
void preOrder(TreeNodePtr treePtr)
{
    if (treePtr != NULL)    // if tree is not empty
    {                
        printf("%3d", treePtr->data);   // root
        preOrder(treePtr->leftPtr);     // left subtree
        preOrder(treePtr->rightPtr);    // right subtree
    }                        
}

// function for postorder traversal of tree (fig 12.19)
void postOrder(TreeNodePtr treePtr)
{
    if (treePtr != NULL)    // if tree is not empty
    {                
        postOrder(treePtr->leftPtr);    // left subtree
        postOrder(treePtr->rightPtr);   // right subtree
        printf("%3d", treePtr->data);   // root
    }                       
}

// function to delete a node from the tree
void deleteNode(TreeNodePtr *treePtr, int value)
{
    TreeNodePtr *parent = treePtr;      // pointer for parent
	TreeNodePtr current = *treePtr;     // pointer for current node
	TreeNodePtr deleteNode = NULL;      // empty tree

    // find node to delete in tree
    while(current != NULL)              // while current node is not NULL
	{
		if(value > current->data)       // if value > current node
		{
			parent = &(current->rightPtr);  // set parent to address of right subtree
			current = current->rightPtr;    // set current node to right subtree
		}
		else if(value < current->data)      // if value < current node
		{
			parent = &(current->leftPtr);   // set parent to address of left subtree
			current = current->leftPtr;  // set current node to left subtree
		}
		else        // node is found
		{
			break;  // break out of loop
		}
	}
	if(current == NULL)     // if the value was not found
    {
		printf("Value not found.\n");
        return;
    }

	deleteNode = current;   // node to delete is current node pointed to 

    if(current->leftPtr == NULL && current->rightPtr == NULL)   // no children
	{
		if(current->leftPtr != NULL)        // if leftsubtree of current is not null
        {
			*parent = current->leftPtr;     // set parent to left subtree
        }
		else
        {
			*parent = current->rightPtr;    // set parent to right subtree
        }
	}
	else
	{
		TreeNodePtr *parent2 = &(current->rightPtr);    // if there are two children
		current = current->rightPtr;                 // set current node to right subtree
		while(current->leftPtr != NULL)     // while left subtree of current is not NULL
		{
			parent2 = &(current->leftPtr);  // set parent 2 to left subtree
			current = current->leftPtr;     // set current node to left subtree
		}
		if(current->rightPtr != NULL)       // if right subtree of current is not NULL
        {
			*parent2 = current->rightPtr;   // set parent2 to right subtree
        }
		else
        {
			*parent2 = NULL;                // set parent 2 to NULL
        }

		*parent = current;                          // set parent to current node
		current->rightPtr = deleteNode->rightPtr;   // set right subtree to right subtree of deleted node
		current->leftPtr = deleteNode->leftPtr;     // set left subtree to left subtree of deleted node
	}
	free(deleteNode);   // free memory pointed by deleted node
}

/*
Sample Cases:

Trial #1
The numbers being placed in the tree are:
 11  1  2  8  4 11dup  2dup 11dup  3  7

The preOrder traversal is:
 11  1  2  8  4  3  7

The inOrder traversal is:
  1  2  3  4  7  8 11

The postOrder traversal is:
  3  7  4  8  2  1 11

Enter the node to delete: 
7

The preOrder traversal is:
 11  1  2  8  4  3

The inOrder traversal is:
  1  2  3  4  8 11

The postOrder traversal is:
  3  4  8  2  1 11

Trial #2
The numbers being placed in the tree are:
  6  3  0 11 14  7  3dup  6dup  8 12

The preOrder traversal is:
  6  3  0 11  7  8 14 12

The inOrder traversal is:
  0  3  6  7  8 11 12 14

The postOrder traversal is:
  0  3  8  7 12 14 11  6

Enter the node to delete: 
11

The preOrder traversal is:
  6  3  0 12  7  8 14

The inOrder traversal is:
  0  3  6  7  8 12 14

The postOrder traversal is:
  0  3  8  7 14 12  6

Trial #3
The numbers being placed in the tree are:
  3 10  4  0  9 13 14  9dup 11 14dup

The preOrder traversal is:
  3  0 10  4  9 13 11 14

The inOrder traversal is:
  0  3  4  9 10 11 13 14

The postOrder traversal is:
  0  9  4 11 14 13 10  3

Enter the node to delete: 
5
Value not found.

The preOrder traversal is:
  3  0 10  4  9 13 11 14

The inOrder traversal is:
  0  3  4  9 10 11 13 14

The postOrder traversal is:
  0  9  4 11 14 13 10  3
*/