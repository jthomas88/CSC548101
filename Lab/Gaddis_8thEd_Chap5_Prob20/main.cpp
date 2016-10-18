/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month, Day, Year, Time
 * Purpose: 
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
    int num=0;
    //Process values -> map inputs to outputs    
    
    //Display output    
    for(int i=0;i<7;i++){
        for(int i=(num%7)+1;i>0;i--){
            cout<<'*';
            num+=2;
        }
        cout<<endl;
    }
    
    //Exit program
    return 0;
}

