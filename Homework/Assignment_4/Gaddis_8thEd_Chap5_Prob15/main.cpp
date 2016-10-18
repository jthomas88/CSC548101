/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month, Day, Year, Time
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>   //Table manipulaiton

using namespace std; //Namespace used in system library

//User libraries

//Global constants
char PERCENT=100;

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    float   strtPop;
    int   incPer;
    float   popInc;
    float incRate;
    
    //Input values
    cout<<"Enter the starting population size: ";
    cin>>strtPop;
    while(strtPop<2){
        cout<<"Invalid input!"<<endl;
        cout<<"Enter the starting population size: ";
        cin>>strtPop;
    }
    cout<<"Enter the rate at which the population is increasing: ";
    cin>>incRate;
    while(incRate<=0){
        cout<<"Invalid input!"<<endl;
        cout<<"Enter the rate at which the population is increasing: ";
        cin>>incRate;
    }
    cout<<"Enter the period of growth to observe in days: ";
    cin>>incPer;
    while(incPer<1){
        cout<<"Invalid input!"<<endl;
        cout<<"Enter the period of growth to observe in days: ";
        cin>>incPer;
    }
    
    //Process values -> map inputs to outputs    
    incRate=incRate/100;
    popInc=strtPop*incRate;
    cout<<endl;
    cout<<"Observation day"<<"         "<<"New population"<<endl;
    cout<<"-------------------------------------"<<endl;
    for(int i=1;i<=incPer;i++){
        cout<<i<<setw(25)<<static_cast<int>(strtPop)<<endl;
        strtPop+=popInc;
        popInc=strtPop*incRate;
    }
    
    //Display output    
    
    //Exit program
    return 0;
}

