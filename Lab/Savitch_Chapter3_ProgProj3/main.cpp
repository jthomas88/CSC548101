/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 3, 2016, 10:38 AM
 * Purpose: Convert Arabic digits to Roman numerals
 */

//System Libraries
#include <iostream> //Input/Output objects
using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    unsigned short araNum; //Arabic digit input
    char romNum;           //Roman Numerals
    char count;
    
    //Input values
    cout<<"Input a 4-digit year: ";
    cin>>araNum;
    
    //Process values -> map inputs to outputs
    count=araNum/1000;
    while(count>0)
    {
        cout<<'M';
        araNum/=1000;
    }
    
    //Display output
    
    
    //Exit program
    return 0;
}

