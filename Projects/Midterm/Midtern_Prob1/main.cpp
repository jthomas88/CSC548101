/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month, Day, Year, Time
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>   //Set spacing of numbers

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    int num=6;
    int numsub=num;
    int numsubb=num;
    
    //Input values
    
    //Process values -> map inputs to outputs    
    for(int i=1;i<=num/2;i++){
        cout<<setw(i)<<numsubb<<setw(numsub-1)<<numsubb<<endl;
        numsub-=2;
        numsubb--;
        }
    for(int i=num/2;i>=1;i--){
        
        cout<<setw(i)<<numsubb%2<<setw(numsub+1)<<numsubb%2<<endl;
        numsub+=2;
        numsub--;
        }
    
    
    //Display output    
    
    //Exit program
    return 0;
}

