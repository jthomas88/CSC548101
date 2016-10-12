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
char PERCENT =100;
//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    int numRoom;
    int occRoom;
    float perRoom;
    
    //Input values
    cin>>numRoom>>occRoom;
    
    //Process values -> map inputs to outputs
    perRoom=(static_cast<float>(numRoom)/static_cast<float>(occRoom))*PERCENT;
    
    //Display output
    cout<<perRoom;
    
    //Exit program
    return 0;
}

