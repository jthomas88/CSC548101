/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 3, 2016, 08:54 AM
 * Purpose: Quadratic Equation
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cmath>     //Square Root
using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    float a,b,c;
    
    //Input values
    cout<<"Input 3 float data types a b c"<<endl;
    cin>>a>>b>>c;
    
    
    //Process values -> map inputs to outputs
    float vb4sqrt=b*b-4*a*c;
    if(a==0)
    {
        cout<<"x = "<<-c/b<<endl;
    }
    else if(vb4sqrt>0)
    {
        cout<<"x  = ("<<(-b+sqrt(vb4sqrt)/(2*a))<<" , "
                      <<(-b-sqrt(vb4sqrt)/(2*a))<<")"<<endl;
    }
    else
    {
        cout<<"x = ("<<(-b/(2*a))<<" + "<<(sqrt(-vb4sqrt)/(2*a))<<"i, "
                     <<(-b/(2*a))<<" + "<<(-sqrt(-vb4sqrt)/(2*a))<<"i)";
    }
    
    //Display output
    
    
    //Exit program
    return 0;
}

