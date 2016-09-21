/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Setpember 11, 2016, 10:30 PM
 * Purpose: Make a big C out of a given character
 */

//System Libraries
#include <iostream>  //Input/Output objects
using namespace std; //Namespace used in system library

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    char spc=' '; //Space character on grid
    char ltr;     //Character chosen by user to make the C
    
    //Input values
    cout<<"Select a character to make a C out of: ";
    cin>>ltr;

    //Display output
    cout<<spc<<spc<<ltr<<ltr<<ltr<<endl;
    cout<<spc<<ltr<<spc<<spc<<ltr<<endl;
    cout<<ltr<<spc<<spc<<spc<<spc<<endl;
    cout<<ltr<<spc<<spc<<spc<<spc<<endl;
    cout<<ltr<<spc<<spc<<spc<<spc<<endl;
    cout<<ltr<<spc<<spc<<spc<<spc<<endl;
    cout<<spc<<ltr<<spc<<spc<<ltr<<endl;
    cout<<spc<<spc<<ltr<<ltr<<ltr<<endl;
    
    //Exit program
    return 0;
}

