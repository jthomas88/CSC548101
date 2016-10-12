/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 12, 2016, 09:33 AM
 * Purpose: Calculate clothing size given height and weight
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
    unsigned int  usrAge,   //Given age of user
                  usrHgt,   //Given height of user
                  usrWgt;   //Given weight of user
    
    unsigned int  szHat,     //Computed hat size
                  szJak,     //Computed jacket size
                  szWst=0;   //Computed waist size
    
    float ageMult;           //Holds value for added size
    
    //Input values
    cin>>usrHgt>>usrWgt>>usrAge;
    
    //Process values -> map inputs to outputs
    
    //Hat size calculation
    szHat=(static_cast<float>(usrWgt)/static_cast<float>(usrHgt))*2.9;
    
    //Chest size calculation
    if((usrAge/10)>3){
        szJak=((usrHgt*usrWgt)/288);
        for(int i=usrAge/10;i>3;i--){
            ageMult+=0.125;
        }
    }
    else{
        szJak=((usrHgt*usrWgt)/288);
    }
    
    //Waist size calculation
    if(usrAge/2>14){
        szWst=usrWgt/5.7;
        for(int i=usrAge/2;i>14;i--){
            ageMult+=0.1;
        }
    }
    else{
        szWst=usrWgt/5.7;
    }
    
    //Display output
    cout<<endl<<szHat<<endl<<szJak<<endl<<szWst<<endl<<ageMult;
    
    //Exit program
    return 0;
}

