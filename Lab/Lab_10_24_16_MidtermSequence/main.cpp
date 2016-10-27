/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 24, 2016, 10:18 AM
 * Purpose: Midterm problem 6 written as a function
 */

//System Libraries
#include <iostream>  //Input/Output objects

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes


//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    float x,seq=1;
    int   n;
    float term=1;
    
    //Input Values
    n=10;
    x=1.0f;
    
    //Process Values
    for(int cnt=1,nterms=2;nterms<=n;cnt+=2,nterms++){
        term*=-1.0f*x*x/cnt/(cnt+1);
        seq+=term;
        
    }
    
    //Output values
    cout<<"Sequence = "<<seq<<endl;
    
    //Exit program
    return 0;
}

float sequens(float x, int n){
    //Initialize variables
    float seq=1.0f,term=seq;
    //
}



