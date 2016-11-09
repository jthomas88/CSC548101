/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on November 6, 2016, 05:00 PM
 * Purpose: Raise a mysterious creature to adulthood
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>   //Format table

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
int celcius(int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Declare Variables
    
    //Generate Table
    cout<<"Celcius"<<"       "<<"Fahrenheit"<<endl;
    for(int f=0;f<=20;f++){
        cout<<f;
        cout<<fixed<<setw(15);
        cout<<celcius(f);
        cout<<endl;
    }
    
    
    //Exit program
    return 0;
}

int celcius(int f){
    int c;
    c=(f-32)*0.55556;
    return c;
}

