/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month, Day, Year, Time
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>   //Format table
using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    float calBurn=3.9f;
    float totBurn=0.0f;
    
    //Process values -> map inputs to outputs
    cout<<"Minutes on treadmill"<<"    "<<"Calories burned"<<endl;
    cout<<"--------------------------------------"<<endl;
    for(int i=10;i<=30;i+=5){
        totBurn=calBurn*i;
        cout<<i<<setw(30)<<setprecision(3)<<totBurn<<endl;
    }
    
    //Display output
    
    
    //Exit program
    return 0;
}

