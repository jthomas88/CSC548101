/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 5, 2016, 01:03 AM
 * Purpose: Calculate number of rewards points awarded on a given order
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
    unsigned int numBook;
    
    //Input values
    cout<<"How many books have you purchased this month? ";
    cin>>numBook;  
    
    //Display output
    if(numBook>=0){
        switch(numBook)
        {
            case 0:cout<<endl<<"You have earned 0 points!";break;
            case 1:cout<<endl<<"You have earned 5 points!";break;
            case 2:cout<<endl<<"You have earned 15 points!";break;
            case 3:cout<<endl<<"You have earned 30 points!";break;
            case 4:cout<<endl<<"You have earned 60 points!";break;
        }
    }
    else{
        cout<<endl<<"Invalid input.";return 1;
    }
    
    
    
    //Exit program
    return 0;
}

