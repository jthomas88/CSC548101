/* 
   File:   main
   Author: Jeffrey Thomas
   Created on September 12, 2016, 10:26 PM
   Purpose: Calculate distance an object will fall given an amount of time 
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cmath>      //Math library
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const float G=32.74; //Gravity Constant, acceleration in ft/sec^2

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) 
{
    //Declaration of Variables
    float time;    //Time as input in seconds
    float distFal; //Calculated distance fallen
    int places;    //Decimal places to round to
    
    //Input values
    cout<<"This will calculate the distance an object falls "
          "given time in seconds.\n";
    cout<<"Input a time in seconds: ";
    cin>>time;
    cout<<"How many decimal places to round to: ";
    cin>>places;
    
    //Process values -> Map inputs to Outputs
    distFal=G*time*time/2;        //Calculate distance using gravity constant
    float shift=pow(10,places);   //Number of places to shift
    int round1=distFal*shift+0.5; //Round to nearest 10^places
    distFal=round1/shift;
    
    //Display Output
    cout<<"Gravity = "<<G<<" ft/sec^2\n";
    cout<<"Time object was in free fall: "<<time<<" sec\n";
    cout<<"Distance fallen: "<<distFal<<" ft\n";

    //Exit Program
    return 0;
}