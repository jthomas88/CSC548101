/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 5, 2016, 10:02 AM
 * Purpose: Sort 3 numbers least to greatest
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
    short a,b,c,d;
    
    //Input values
    cout<<"Input three integers: ";
    cin>>a>>b>>c;
    
    //Sort for A being the largest
    cout<<endl;
    if(a>b&&a>c){
        if(b>c){
            cout<<c<<' '<<b<<' '<<a;
        }
        else{
            cout<<b<<' '<<c<<' '<<a;
        }
    }
    //Sort for B being the largest
    else if(b>a&&b>c){
        if(a>c){
            cout<<c<<' '<<a<<' '<<b;
        }
        else{
            cout<<a<<' '<<c<<' '<<b;
        }
    }
    //Sort for C being the largest
    else{
        if(a>b){
            cout<<b<<' '<<a<<' '<<c;
        }
        else{
            cout<<a<<' '<<b<<' '<<c;
        }
    }      
    
    //Exit program
    return 0;
}

