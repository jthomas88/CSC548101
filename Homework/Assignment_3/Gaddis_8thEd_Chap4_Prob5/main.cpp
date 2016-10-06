/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 5, 2016, 01:03 AM
 * Purpose: Calculate number of rewards points awarded on a given order
 */

//System Libraries
#include <iostream>  //Input/Output objects
using namespace std; //Namespace used in system library

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    int numBook;
    
    //Input values
    cout<<"How many books have you purchased this month? ";
    cin>>numBook;  
    
    //Input Validation
    while(numBook<0)
    {
        cout<<"Invalid input."<<endl;
        cout<<"How many books have you purchased this month? ";
        cin>>numBook; 
    }
    
    //Display output
    //Ternary operation testing for number of books purchased
    (numBook==0)?cout<<endl<<"You have earned 0 points!":
    (numBook==1)?cout<<endl<<"You have earned 5 points!":
    (numBook==2)?cout<<endl<<"You have earned 15 points!":
    (numBook==3)?cout<<endl<<"You have earned 30 points!":
    (numBook>=4)?cout<<endl<<"You have earned 60 points!":
                 cout<<"You have earned 0 points!";
    
    
    //Exit program
    return 0;
}

