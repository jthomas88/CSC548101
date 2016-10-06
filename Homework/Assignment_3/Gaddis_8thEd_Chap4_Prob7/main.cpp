/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 5, 2016, 8:58 PM
 * Purpose: Convert a given number of seconds into a more readable format
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
    unsigned int sec;          //User inputted seconds
    unsigned int day,hr,min=0; //Conversions
    //Input values
    cout<<"Enter a number of seconds to be converted: ";
    cin>>sec;
    
    //Process values -> map inputs to outputs
    if(sec>=86400)     //Check for number of days
        day=sec/86400; //Convert seconds to days
        sec=sec%86400; //Assign remainder to seconds value
    if(sec>=3600)      //Check for number of hours
        hr=sec/3600;   //Convert seconds to hours
        sec=sec%3600;  //Assign remainder to seconds value
    if(sec>=60)        //Check for number of minutes
        min=sec/60;    //Convert seconds to minutes
        sec=sec%60;    //Assign remainder to minutes value
    //Display output
    cout<<endl<<day<<" day(s), "<<hr<<" hour(s), "
              <<min<<" minute(s), "<<sec<<" second(s)";
    
    //Exit program
    return 0;
}

