/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 5, 2016, 12:24 AM
 * Purpose: Determine if given date is a magic date.
 */

//System Libraries
#include <iostream>  //Input/Output objects
using namespace std; //Namespace used in system library

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    unsigned short mn,dy,yr; //User inputted month, date, and year
    
    //Input values
    cout<<"Input the date, month, and year of the date you'd like to check: ";
    cin>>dy>>mn>>yr;
    
    //Process values and Output
    if(dy*mn==yr) //Check if month multiplied by day equals the year
    {
        cout<<dy<<'/'<<mn<<'/'<<yr<<" is a magic date;";    //Output positive 
    }
    else
    {
        cout<<dy<<'/'<<mn<<'/'<<yr<<" is not a magic date;";//Output negative
    }

    
    //Exit program
    return 0;
}

