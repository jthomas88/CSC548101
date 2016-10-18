/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month, Day, Year, Time
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>   //Set fill for width variable

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    int  length,width;
    char fill='X';
    
    //Input values
    cout<<"Enter a length between 2 and 10: ";
    cin>>length;
    cout<<"Enter a width between 2 and 10: ";
    cin>>width;
    while((length>10||length<2)||(width>10||width<2)){
        cout<<"Invalid input!"<<endl;
        cout<<"Enter a length between 2 and 10: ";
        cin>>length;
        cout<<"Enter a width between 2 and 10: ";
        cin>>width;
    }
    
    //Process values -> map inputs to outputs    
    for(int i=length;i>0;i--){
        for(int i=width;i>0;i--){
            cout<<fill;
        }
        cout<<endl;
    }    
    
    //Exit program
    return 0;
}

