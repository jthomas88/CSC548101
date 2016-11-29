/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on November 28, 2016, 10:40 AM
 * Purpose: Raise a mysterious creature to adulthood
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>   //Random Numbers
#include <ctime>     //Random Seed

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
const int SIZE=10;

void fillAry(int[]);
void prntAry(int[]);
int  findWin(int[],int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    int lotto=0;      //This week's lotto number
    int tix[SIZE]={}; //10 Lottery tickets
    
    //Process Values
    
    
    //Exit program
    return 0;
}
void fillAry(int array[]){
    
}

void prntAry(int array[]){
    for(int i=0;i<SIZE;i++)
}

int findWin(int[],int);
