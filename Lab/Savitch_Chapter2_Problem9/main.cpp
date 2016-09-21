/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on September 21, 2016. 10:27 AM
 * Purpose: Output sums of different integers
 */

//System Libraries
#include <iostream>  //Input/Output objects
using namespace std; //Namespace used in system library

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    int num;             //User defined integers
    unsigned int pozSum; //Sum of all positive integers
    int negSum;          //Sum of all negative integers
    int totSum;          //Sum of all integers
    char count = 10;
    
    //Input values
    cout<<"Input 10 whole numbers in any order: "<<endl; //Prompt user to input
    
    //Process values -> map inputs to outputs
    while(count>0)       //Reiterates the code until countdown reaches 0
    {
        cin>>num;        //Input numbers
        if(num>0)        //Sends positive numbers to be added to positive total
        {
            pozSum+=num; //Adds positive numbers to positive total   
        }
        else             //Sorts negative numbers to be added to negative total
        {
            negSum+=num; //Adds negative numbers to negative total
        }
        totSum+=num;     //Adds all numbers to all number total
        count--;         //Reduces count by 1
    }
    
    //Display output
    cout<<endl;
    cout<<"Sum of positive numbers: "<<pozSum<<endl;  //Output sum of positives
    cout<<"Sum of negative numbers: "<<negSum<<endl;  //Output sum of negatives
    cout<<"Total sum of all numbers: "<<totSum<<endl; //Output sum of all
    
    //Exit program
    return 0;
}

