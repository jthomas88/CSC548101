/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month, Day, Year, Time
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>   //Table format

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    const float seaRise=3.1;
    float       totRise=seaRise;
    
    //Input values
    
    
    //Process values -> map inputs to outputs
    cout<<"Year"<<"       "<<"Sea level rise (mm)"<<endl;
    cout<<"---------------------------------"<<endl;
    for(int i=1;i<=25;i++){
        cout<<i<<setw(20);
        cout<<setprecision(3)<<totRise<<endl;
        totRise+=seaRise;
    }
    
    //Display output
    
    
    //Exit program
    return 0;
}

