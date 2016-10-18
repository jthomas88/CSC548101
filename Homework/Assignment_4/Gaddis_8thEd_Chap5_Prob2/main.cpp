/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month, Day, Year, Time
 * Purpose: 
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
    int loopNum;
    int total;
    
    //Input values
    cout<<"Input a value to get a sum of all previous numbers: ";
    cin>>loopNum;
    
    //Process values -> map inputs to outputs
    for(int i=loopNum;i>0;i--){
        total+=loopNum;
        loopNum--;
    }
    
    //Display output
    cout<<endl;
    cout<<"The total sum is: "<<total;
    
    //Exit program
    return 0;
}

