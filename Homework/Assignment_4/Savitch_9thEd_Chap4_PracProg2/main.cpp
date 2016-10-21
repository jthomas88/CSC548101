/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 10, 2016, 07:44 PM
 * Purpose: Calculate MPG of a vehicle given liters of gas used
 */

//System Libraries
#include <iostream> //Input/Output objects
using namespace std; //Namespace used in system library

//User libraries

//Global constants
float LITER=0.264179; //Liter to Gallon conversion rate

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    unsigned int litUsed, galUsed; //Liters and gallons used, respectively
    unsigned int milTrav;          //Miles traveled by the user
    float mpg1,mpg2;               //Miles per gallon that the vehicle gets
    
    //Input values
    cout<<"Enter the number of liters of gas used: ";
    cin>>litUsed;
    cout<<"Enter the number of miles traveled: ";
    cin>>milTrav;

    //Process values
    galUsed=litUsed*LITER;
    mpg1=static_cast<float>(milTrav)/static_cast<float>(galUsed);

    //Display Output
    cout<<endl;    
    cout<<"This vehicle gets "<<mpg1<<" miles per gallon.";
    cout<<endl<<endl;
    
    //Reiterate code
    
    //Input values

    cout<<"Enter the number of liters of gas used: ";
    cin>>litUsed;
    cout<<"Enter the number of miles traveled: ";
    cin>>milTrav;

    //Process values
    galUsed=litUsed*LITER;
    mpg2=static_cast<float>(milTrav)/static_cast<float>(galUsed);

    //Display Output
    cout<<endl;    
    cout<<"This vehicle gets "<<mpg2<<" miles per gallon.";
    cout<<endl<<endl;

    if(mpg1>mpg2)
    {
        cout<<"Vehicle 1 gets "<<mpg1<<" miles per gallon."<<endl;
        cout<<"Vehicle 2 gets "<<mpg2<<" miles per gallon."<<endl;
        cout<<"Vehicle 1 has better fuel economy.";
    }
    else
    {
        cout<<"Vehicle 1 gets "<<mpg1<<" miles per gallon."<<endl;
        cout<<"Vehicle 2 gets "<<mpg2<<" miles per gallon."<<endl;
        cout<<"Vehicle 2 has better fuel economy.";
    }
    
    //Exit program
    return 0;
}

