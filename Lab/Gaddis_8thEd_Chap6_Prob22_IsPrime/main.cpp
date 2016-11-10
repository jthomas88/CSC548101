/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 22, 2016, 09:32 PM
 * Purpose: Raise a mysterious creature to adulthood
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
void isPrime(int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    int num;
    
    //Input Values
    cin>>num;
    
    //Process Values
    cout<<"this number is ";
    isPrime(num);
    
    //Exit program
    return 0;
}

void isPrime(int num){
    for(int i=0;i<=num/2;i++){
    }
}