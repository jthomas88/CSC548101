/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 22, 2016, 09:32 PM
 * Purpose: Raise a mysterious creature to adulthood
 */

//System Libraries
#include <iostream>  //Input/Output objects

using namespace std; //Namespace used in system library

//Global constants
const int SIZE=20;

//User libraries
struct Name{
    string first;
    char   mi;
    char   last[SIZE]={};
    
};

//Global constants


//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declare variables
    Name name1;
    
    //Prompt user
    cout<<"Please enter your first name: ";
    cin>>name1.first;
    
    cout<<"Please enter your first name: ";
    cin>>name1.mi;
    
    cout<<"Please enter your last name: ";
    cin>>name1.last;
    
    //Output name
    cout<<endl;
    cout<<"Your name is "<<name1.first<<' '<<name1.mi<<' '<<name1.last;
    
    //Exit program
    return 0;
}

