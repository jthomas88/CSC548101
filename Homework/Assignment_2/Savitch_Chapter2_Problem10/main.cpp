/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on September 26, 2016. 10:35 AM
 * Purpose: Output sums and averages of different integers
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
    int   negSum;        //Sum of all negative integers
    int   totSum;        //Sum of all integers
    float pozAvg;        //Average of all positive integers
    float negAvg;        //Average if all negative integers
    float totAvg;        //Average of all integers
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
    pozAvg=static_cast<float>(pozSum)/10; //Generate average of positives
    negAvg=static_cast<float>(negSum)/10; //Generate average of negatives
    totAvg=static_cast<float>(totSum)/10; //Generate average of total
    
    //Display output
    cout<<endl;
    //Output sum and average of positive numbers
    cout<<"Sum of positive numbers: "<<pozSum<<endl;
    cout<<"Average of positive numbers: "<<pozAvg<<endl<<endl;
    //Output sum and average of negative numbers
    cout<<"Sum of negative numbers: "<<negSum<<endl;
    cout<<"Average of all negative numbers: "<<negAvg<<endl<<endl; 
    //Output sum and average of all numbers
    cout<<"Total sum of all numbers: "<<totSum<<endl; 
    cout<<"Average of all numbers: "<<totAvg<<endl;  
    
    //Exit program
    return 0;
}

