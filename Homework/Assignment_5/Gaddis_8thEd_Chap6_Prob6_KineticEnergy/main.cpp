/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 22, 2016, 09:32 PM
 * Purpose: Raise a mysterious creature to adulthood
 */

//System Libraries
#include <iostream>  //Input/Output objects

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
float kinEner(float,float);

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    float mass=0.0f; //Object's mass in kg
    float velo=0.0f; //Object's velocity in m/s
    
    //Input Values
    cout<<"This program calculates the kinetic energy of an object.";
    cout<<endl<<endl;
    cout<<"Enter the mass of the object in KG: ";
    cin>>mass;
    cout<<"Enter the velocity of the object in m/s: ";
    cin>>velo;
    
    //Process Values
    cout<<"The calculated kinetic energy is: "<<kinEner(mass,velo);
    
    //Exit program
    return 0;
}

float kinEner(float mas,float vel){
    float ke=0; //Calculated kinetic energy of object;
    ke=0.5*(mas*(vel*vel));
    return ke;
}