/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month, Day, Year, Time
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>   //Table formatting

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    int  velo;
    int  hrsTrav;
    
    //Input values
    cout<<"What is the speed of the vehicle in mph? ";
    cin>>velo;
    cout<<"How many hours has it traveled? ";
    cin>>hrsTrav;
    while(velo<0||hrsTrav<1){
        cout<<endl;
        cout<<"Invalid input!"<<endl;
        cout<<"What is the speed of the vehicle in mph? ";
        cin>>velo;
        cout<<"How many hours has it traveled? ";
        cin>>hrsTrav;
    }
    cout<<"Hour"<<"     "<<"Distance Traveled"<<endl;
        cout<<"-------------------------------"<<endl;
        for(int i=1;i<=hrsTrav;i++){
            cout<<i<<setw(10)<<velo*i<<endl;
        }
   
    //Exit program
    return 0;
}

