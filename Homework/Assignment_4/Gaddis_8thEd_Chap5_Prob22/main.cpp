/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month, Day, Year, Time
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    unsigned int str1,str2,str3;
    
    //Input values
    cout<<"Input the sales of store 1 to the nearest hundred: ";
    cin>>str1;
    cout<<"Input the sales of store 2 to the nearest hundred: ";
    cin>>str2;
    cout<<"Input the sales of store 3 to the nearest hundred: ";
    cin>>str3;
    
    //Process values -> map inputs to outputs  
    cout<<"TODAY'S SALES"<<endl;
    cout<<"(* = $100)"<<endl;
    cout<<"Store 1: ";
    for(int i=0;i<str1/100;i++){
        cout<<'*';
    }
    cout<<endl;
    
    cout<<"Store 2: ";
    for(int i=0;i<str2/100;i++){
        cout<<'*';
    }
    cout<<endl;
    
    cout<<"Store 3: ";
    for(int i=0;i<str3/100;i++){
        cout<<'*';
    }
    cout<<endl;    
    
    //Exit program
    return 0;
}

