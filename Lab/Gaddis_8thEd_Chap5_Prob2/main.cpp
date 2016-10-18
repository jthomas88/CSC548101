/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month, Day, Year, Time
 * Purpose: 
 */

//System Libraries
#include <iostream> //Input/Output objects
using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    int romNum;
    int araNum;
    
    //Input values
    cin>>araNum;
    
    //Process values -> map inputs to outputs
    if(araNum/1000>=1){
        for(int i=araNum/1000;i>0;i--){
            cout<<'M';
            araNum-=1000*(araNum/1000);
        }
    }
    if(araNum/500>=1){
            for(int i=araNum/500;i>0;i--){
                cout<<'D';
                araNum-=500*(araNum/500);
            }
    }
    if(araNum/100>=1){
        for(int i=araNum/100;i>0;i--){
            cout<<'C';
            araNum-=100*(araNum/100);
        }
    }  
    //Display output
    
    
    //Exit program
    return 0;
}

