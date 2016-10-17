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
    unsigned int  usrAge,    //Given age of user
                  usrHgt,    //Given height of user
                  usrWgt;    //Given weight of user
    
    float         szHat,     //Computed hat size
                  szJak,     //Computed jacket size
                  szJak10,   //Jacket size 10 years later
                  szWst,     //Computed waist size
                  szWst10=0; //Waist size in 10 years
    
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
        szJak10=szJak+0.125;
    }
    else{
        szJak=((usrHgt*usrWgt)/288);
        szJak10=szJak;
    }
    
    //Waist size calculation
    if(usrAge/2>14){
        szWst=usrWgt/5.7;
        for(int i=usrAge/2;i>14;i--){
            ageMult+=0.1;
        }
        szWst+=ageMult;
        szWst10=szWst+0.5;
    }
    else{
        szWst=usrWgt/5.7;
        for(int i=(usrAge+10)/2;i>14;i--){
            ageMult+=0.1;
        }
        szWst10+=ageMult;
    }
    
    //Display output
    cout<<endl<<"Your hat size is: "<<setprecision(1)<<szHat;
    cout<<endl<<"Your jacket size is: "<<setprecision(2)<<szJak;
    cout<<endl<<"Your jacket size in 10 years will be: "<<setprecision(2)<<szJak10;
    cout<<endl<<"Your waist size is: "<<setprecision(2)<<szWst;
    cout<<endl<<"Your waist size in 10 years will be: "<<setprecision(2)<<szWst10;
    
    //Exit program
    return 0;
}

