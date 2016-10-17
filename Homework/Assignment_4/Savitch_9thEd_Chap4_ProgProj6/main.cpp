/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month, Day, Year, Time
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    const unsigned short TKPRICE=350;  //Price of a deep fried twinkie
    unsigned short       total;        //Total amount of money user has inserted
    float                dispTot=0.00; //Total displayed on the screen for user
    int                  amt;          //Amount user has chosen to add
    //Input values
    do{
        //Display interface
        cout<<"A Twinkie costs $3.50 "<<endl;
        cout<<"Insert your coins now"<<endl;
        cout<<"Total amount inserted: $"<<dispTot<<endl;
        cout<<"1) Nickel"<<endl;
        cout<<"2) Dime"<<endl;
        cout<<"3) Quarter"<<endl;
        cout<<"4) Dollar"<<endl;
        cin>>amt; //Input coin value
        if(amt==1){      //Check for nickels
            total+=5;
        }
        else if(amt==2){ //Check for dimes
            total+=10;
        }
        else if(amt==3){ //Check for quarters
            total+=25;
        }
        else if(amt==4){ //Check for dollars
            total+=100;
        }
        else{            //Check for bad inputs
            cout<<"Invalid input!"<<endl;
        }
        dispTot=static_cast<float>(total)/100; //Update total displayed on screen
    }while(total<TKPRICE); //Repeat loop until enough money has been added
    
    //Display Output
    cout<<endl<<"Thank you! your change is "<<total-TKPRICE<<" cents.";  
    
    //Exit program
    return 0;
}

