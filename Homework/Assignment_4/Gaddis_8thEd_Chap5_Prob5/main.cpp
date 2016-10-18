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
float KMTOMIL=0.6214;

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    int   kph=60;
    float mph=0;
    
    //Process values -> map inputs to outputs
    cout<<"Km/h"<<"    "<<"Mil/h"<<endl;
    cout<<"---------------"<<endl;
    for(int i=kph;i<=130;i+=5){
        mph=kph*KMTOMIL;
        cout<<kph<<setw(10)<<setprecision(3)<<mph<<endl;
        kph+=5;
    }
    
    //Display output
    
    
    //Exit program
    return 0;
}

