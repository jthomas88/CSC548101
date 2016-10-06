/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 5, 2016, 08:19 PM
 * Purpose: Convert a given mass to weight in newtons
 */

//System Libraries
#include <iostream>  //Input/Output objects

using namespace std; //Namespace used in system library

//User libraries

//Global constants
const float NEWT=9.8; //Newton conversion constant

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    float mass,wgt; //Mass in kg and weight in newtons, respectively
    
    //Input values
    cout<<"Enter a mass in kg: ";
    cin>>mass;
    
    //Process values -> map inputs to outputs
    wgt=mass*NEWT;
    
    //Display output
    cout<<endl;
    if(wgt>1000) //Display too heavy message if mass exceeds 1000kg
    {
        cout<<"Object mass: "<<mass<<"kg"<<endl;
        cout<<"Object weight: "<<wgt<<"kg"<<endl;
        cout<<"The object is too heavy."<<endl;
    }
    else if(wgt<10) //Display too light message if mass falls below 10kg
    {
        cout<<"Object mass: "<<mass<<"kg"<<endl;
        cout<<"Object weight: "<<wgt<<"kg"<<endl;
        cout<<"The object is too light."<<endl;
    }
    else
    {
        cout<<"Object mass: "<<mass<<"kg"<<endl;
        cout<<"Object weight: "<<wgt<<"kg"<<endl;
        cout<<"The object is adequate."<<endl;
    }
    
    //Exit program
    return 0;
}

