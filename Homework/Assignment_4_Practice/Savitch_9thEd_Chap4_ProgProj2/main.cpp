/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 12, 2016, 09:33 AM
 * Purpose: Calculate clothing size given height and weight
 */

//System Libraries
#include <iostream> //Input/Output objects
#include <iomanip>  //Manipuilate precision of outputs

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
    
    float         szHat,    //Computed hat size
                  szJak,    //Computed jacket size
                  szWst=0;  //Computed waist size
    
    float         ageMult;  //Holds value for added size
    
    //Input values
    cin>>usrHgt>>usrWgt>>usrAge;
    
    //Process values -> map inputs to outputs
    
    //Hat size calculation
    szHat=(static_cast<float>(usrWgt)/static_cast<float>(usrHgt))*2.9;
    
    //Chest size calculation
    if((usrAge/10)>3){
        szJak=((static_cast<float>(usrHgt)*static_cast<float>(usrWgt))/288);
        for(int i=usrAge/10;i>3;i--){
            ageMult+=0.125;
        }
        szJak+=ageMult;
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
        szWst+=ageMult;
    }
    else{
        szWst=usrWgt/5.7;
    }
    
    //Display output
    cout<<endl<<"Your hat size is: "<<setprecision(1)<<szHat;
    cout<<endl<<"Your jacket size is: "<<setprecision(2)<<szJak;
    cout<<endl<<"Your waist size is: "<<setprecision(2)<<szWst;
    
    //Exit program
    return 0;
}

