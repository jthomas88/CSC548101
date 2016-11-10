/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 22, 2016, 09:32 PM
 * Purpose: Raise a mysterious creature to adulthood
 */

//System Libraries
#include <cstdlib>
#include <iostream>  //Input/Output objects
#include <iomanip>
#include <ctime>

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
void coinTos();

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize Random Seed
    srand(time(0));
    //Declaration of variables
    int choice=0; //Number of times coin will be tossed
    int count=0;  //Counter to form a table
    
    //Input Values
    cout<<"Enter number of times coin will be tossed: ";
    cin>>choice;
    cout<<endl;
    
    //Loop function
    for(int i=0;i<choice;i++){
        coinTos();
        cout<<' ';
        if(count++>5){
            cout<<endl;
            count=0;
        }
    }
    
    //Exit program
    return 0;
}

void coinTos(){
    int toss=rand()%2;
    toss==0?cout<<"Heads":cout<<"Tails";
}