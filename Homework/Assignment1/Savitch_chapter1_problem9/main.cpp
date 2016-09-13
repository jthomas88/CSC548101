/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on September 11, 2016, 9:17 PM
 * Purpose: Calculate amount of money in cents when given different coin amounts
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
    unsigned int quar, //Represents number of quarters
                 dime, //Represents number of dimes
                 nick, //Represents number of nickels
                 penn, //Represents number of pennies
                 totl; //Represents total amount in cents
    
    //Input values
    cout<<"Enter the amount of quarters: ";
    cin>>quar;
    cout<<"Enter the amount of dimes: ";
    cin>>dime;
    cout<<"Enter the amount of nickels: ";
    cin>>nick;
    cout<<"Enter the number of pennies: ";
    cin>>penn;
    
    //Process values -> map inputs to outputs
    quar=quar*25;
    dime=dime*10;
    nick=nick*5;
    totl=quar+dime+nick+penn;
    
    //Display output
    cout<<"Your total in cents is: "<<totl;
    
    //Exit program
    return 0;
}

