// Homework 3 Problem 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define START 1                 // starting gate position for the race

// function main begins program execution
int main( void )
{
    char track[71][8];          // array for race course
    int tortoisePos = START;    // variable for tortoise position
    int harePos = START;        // variable for hare position
    int clock = 0;              // counter for each tick of clock

    // initialize race course with spaces
    for (int i = 0; i<71; i++)
    {
        strcpy(track[i]," ");
    }

    printf("BANG !!!!!\n");             // prompt to begin race
    printf("AND THEY'RE OFF !!!!!\n");  // prompt to begin race
    printf("OUCH!!!!\n");               // since they start in same position,
                                        // the race starts with the tortoise biting the hare
    srand(time(NULL));                  // seed to ensure randomization

    // loop for the race (each tick of clock = 1 iteration)
    while (tortoisePos < 70 && harePos < 70)    // while neither have reached the finish
    {
        // generate random integer from 1 to 10 for table percentages
        int n = rand() % 10 + 1;

        // tortoise fast plod
        if (n >=1 && n <= 5)
        {
            tortoisePos = tortoisePos + 3;  // move 3 squares to the right
            if (tortoisePos > 70)           // if move exceeds position 70
            {
                tortoisePos = 70;           // set tortoise to position 70 (finish)
            }
        }
        // tortoise slip
        if (n >= 6 && n <= 7)
        {
            tortoisePos = tortoisePos - 6;  // move 6 squares to the left
            if (tortoisePos <= 0)           // if tortoise slips left past position 1
            {
                tortoisePos = START;        // set tortoise to starting gate
            }
        }
        // tortoise slow pod
        if (n >=8 && n <= 10)
        {
            tortoisePos = tortoisePos + 1;  // move 1 square to the right
            if (tortoisePos > 70)           // if move exceeds position 70
            {
                tortoisePos = 70;           // set tortoise to position 70 (finish)
            }
        }

        // skip 1 & 2 for hare since sleep does not move position
        // hare big hop 
        if (n >=3 && n <= 4)
        {
            harePos = harePos + 9;      // move 9 squares to the right
            if (harePos > 70)           // if move exceeds position 70
            {
                harePos = 70;           // set hare to position 70 (finish)
            }
        }
        // hare big slip
        if (n == 5)
        {
            harePos = harePos - 12;     // move 12 squares to the left
            if (harePos <= 0)           // if hare slips left past position 1
            {
                harePos = START;        // set hare to starting gate
            }
        }
        // hare small hop
        if (n >=6 && n <= 8)
        {
            harePos = harePos + 1;      // move 1 square to the right
            if (harePos>70)             // if move exceeds position 70
            {
                harePos = 70;           // set hare to position 70 (finish)
            }
        }
        // hare small slip
        if (n >= 9 && n <=10)
        {
            harePos = harePos - 2;      // move 2 squares to the left
            if (harePos <= 0)           // if hare slips left past position 1
            {
                harePos = START;        // set hare to starting gate
            }
        }

        // clear previous H and T position from last iteration
        for (int i = 0; i<70; i++)
        {
            strcpy(track[i]," ");   // empty race course
        }

        // if contenders land on the same space
        if (harePos == tortoisePos)
        {
            strcpy(track[harePos],"OUCH!!!!");  // tortoise bites the hare
        }
        else 
        {
            strcpy(track[tortoisePos],"T");     // print T in tortoise position
            strcpy(track[harePos],"H");         // print H in hare position
        }

        // for loop to print 70 position line for each tick of the clock
        for (int i = START; i<71; i++)
        {
            printf("%s",track[i]);  // print the line
        }
        printf("\n");               // new line for clarity
        clock++;                    // increment number of ticks
    }

    if (tortoisePos == 70 && harePos == 70) // if race ends in a tie
    {
        printf("It's a tie.\n");            // prompt
    }
    else if (tortoisePos >= 70)             // if tortoise wins
    {
        printf("TORTOISE WINS!!! YAY!!!\n");// prompt
    }
    else if (harePos >= 70)                 // if hare wins
    {
        printf("Hare wins. Yuch.\n");       // prompt
    }  
    // prints to total time of the race
    printf("The race lasted %d seconds\n",clock);
}

/*
Sample cases:

BANG !!!!!
AND THEY'RE OFF !!!!!
OUCH!!!!
HT                                                                    
 HT                                                                   
H    T                                                                
H     T                                                               
H        T                                                            
H           T                                                         
H              T                                                      
H                 T                                                   
 H                 T                                                  
          H           T                                               
H                        T                                            
H                           T                                         
 H                    T                                               
H                      T                                              
 H               T                                                    
  H        T                                                          
  H           T                                                       
           H     T                                                    
           TH                                                         
              T      H                                                
               T   H                                                  
       H          T                                                   
     H             T                                                  
   H                T                                                 
    H         T                                                       
             H   T                                                    
           T  H                                                       
            T  H                                                      
             OUCH!!!!                                                       
             H  T                                                     
              H  T                                                    
            H     T                                                   
            H        T                                                
            H           T                                             
          H              T                                            
                   H        T                                         
                    H T                                               
                    H    T                                            
                   T H                                                
         H            T                                               
                  H      T                                            
                  H         T                                         
                   H         T                                        
                   H            T                                     
                            H      T                                  
                H                     T                               
              H                        T                              
                       H                  T                           
                        H                  T                          
                         H           T                                
                          H           T                               
                           H    T                                     
                                   TH                                 
                             T       H                                
                       T              H                               
                        T              H                              
                           T           H                              
                              T        H                              
                           H     T                                    
                                    OUCH!!!!                                
                              T      H                                
                                 T            H                       
                                    T         H                       
                                     T      H                         
                                H       T                             
                                H          T                          
                                         H    T                       
                                         H       T                    
                                                  H T                 
                                                  H    T              
                                                   H    T             
                                                    H    T            
                                                    H       T         
                                                     HT               
                                                     H   T            
                                         H                  T         
                                       H                     T        
                                       H                        T     
                                     H                           T    
                                   H                              T   
                                    H                              T  
                                  H                                 T 
                                           H                         T
TORTOISE WINS!!! YAY!!!
The race lasted 83 seconds

BANG !!!!!
AND THEY'RE OFF !!!!!
OUCH!!!!
   T     H                                                            
      T           H                                                   
      H  T                                                            
    H     T                                                           
    TH                                                                
     H T                                                              
          T   H                                                       
           TH                                                         
              T      H                                                
                 T   H                                                
                  T   H                                               
            T          H                                              
             T          H                                             
                T       H                                             
                   T    H                                             
                    T H                                               
                      HT                                              
                          T    H                                      
                    T           H                                     
                       T        H                                     
                        T        H                                    
                     H     T                                          
                      H     T                                         
                               OUCH!!!!                                     
                             H  T                                     
                             H     T                                  
                           H        T                                 
                            H T                                       
                          H    T                                      
                         T H                                          
                         HT                                           
                         H   T                                        
                       H      T                                       
                                HT                                    
                              H   T                                   
                  H                  T                                
                   H           T                                      
                            H     T                                   
                                     OUCH!!!!                               
                                   H  T                               
                       H                 T                            
                       H                    T                         
                        H             T                               
                                 H       T                            
                                          H T                         
                                      T    H                          
                                         T          H                 
                                            T                H        
                                               T             H        
                                                T          H          
                                          T                 H         
                                           T                 H        
                                              T                      H
Hare wins. Yuch.
The race lasted 53 seconds
*/