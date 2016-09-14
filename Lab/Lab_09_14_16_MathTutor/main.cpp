/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on September 14, 2016, 10:16 AM
 * Purpose: Assist a student in solving math problems by providing random 
 * numbers
 */

//System Libraries
#include <cstdlib>   //Standard library for random number seed
#include <iostream>  //Input/Output objects
#include <ctime>     //Seed the random number generator
using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declaration of variables
    unsigned short op1, op2, result, answer;
    
    //Input values
    op1=rand()%900+100;  //3 digit random number
    op2=rand()%900+100;  //second random number generator
    
    //Process values -> map inputs to outputs
    result=op1+op2;
    
    //Display output
    cout<<"Solve the following addition problem\n";
    cout<<op1<<" + "<<op2<<" = ";
    
    //Ask for answer
    cout<<endl<<"What is the answer?\n";
    cin>>answer;
    
    //Determine if correct or not
    cout<<"The answer is "<<(result==answer?"correct":"incorrect")<<endl;
    cout<<"The correct answer is "<<result;
    
    //Exit program
    return 0;
}

