/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 5, 2016, 10:02 AM
 * Purpose: Sort 4 numbers least to greatest
 */

//System Libraries
#include <iostream>  //Input/Output objects

using namespace std; //Namespace used in system library

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    short a,b,c,d;
    
    //Input values
    cout<<"Input four integers: ";
    cin>>a>>b>>c>>d;
    
    cout<<endl;
    
    //Sort for A being the largest
    if(a>b&&a>c&&a>d)
    {
        //Sort for B being second largest
        if(b>c&&b>d){
            if(c>d){
                cout<<d<<' '<<c<<' '<<b<<' '<<a;
            }
            else{
                cout<<c<<' '<<d<<' '<<b<<' '<<a;
            }
        }
        //Sort for C being second largest
        else if(c>b&&c>d){
            if(b>d){
                cout<<d<<' '<<b<<' '<<c<<' '<<a;
            }
            else{
                cout<<b<<' '<<d<<' '<<c<<' '<<a;
            }
        }
        //Sort for D being second largest
        else{
            if(b>c){
                cout<<c<<' '<<b<<' '<<d<<' '<<a;
            }
            else{
                cout<<b<<' '<<c<<' '<<d<<' '<<a;
            }
        }
    }
    //Sort for B being the largest
    if(b>a&&b>c&&b>d)
    {
        //Sort for A being second largest
        if(a>c&&a>d){
            if(c>d){
                cout<<d<<' '<<c<<' '<<a<<' '<<b;
            }
            else{
                cout<<c<<' '<<d<<' '<<a<<' '<<b;
            }
        }
        //Sort for C being second largest
        else if(c>a&&c>d){
            if(a>d){
                cout<<d<<' '<<a<<' '<<c<<' '<<b;
            }
            else{
                cout<<a<<' '<<d<<' '<<c<<' '<<b;
            }
        }
        //Sort for D being second largest
        else{
            if(a>c){
                cout<<c<<' '<<a<<' '<<d<<' '<<b;
            }
            else{
                cout<<a<<' '<<c<<' '<<d<<' '<<b;
            }
        }
    }
    //Sort for C being the largest
    if(c>a&&c>b&&c>d)
    {
        //Sort for A being second largest
        if(a>b&&a>d){
            if(b>d){
                cout<<d<<' '<<b<<' '<<a<<' '<<c;
            }
            else{
                cout<<b<<' '<<d<<' '<<a<<' '<<c;
            }
        }
        //Sort for B being second largest
        else if(b>a&&b>d){
            if(a>d){
                cout<<d<<' '<<a<<' '<<b<<' '<<c;
            }
            else{
                cout<<a<<' '<<d<<' '<<b<<' '<<c;
            }
        }
        //Sort for D being second largest
        else{
            if(a>b){
                cout<<b<<' '<<a<<' '<<d<<' '<<c;
            }
            else{
                cout<<a<<' '<<b<<' '<<d<<' '<<c;
            }
        }
    }
    //Sort for D being the largest
    if(d>a&&d>b&&d>c)
    {
        //Sort for A being second largest
        if(a>b&&a>c){
            if(b>c){
                cout<<c<<' '<<b<<' '<<a<<' '<<d;
            }
            else{
                cout<<b<<' '<<c<<' '<<a<<' '<<d;
            }
        }
        //Sort for B being second largest
        else if(b>a&&b>c){
            if(a>c){
                cout<<c<<' '<<a<<' '<<b<<' '<<d;
            }
            else{
                cout<<a<<' '<<c<<' '<<b<<' '<<d;
            }
        }
        //Sort for C being second largest
        else{
            if(a>b){
                cout<<b<<' '<<a<<' '<<c<<' '<<d;
            }
            else{
                cout<<a<<' '<<b<<' '<<c<<' '<<d;
            }
        }
    }
    //Exit program
    return 0;
}

