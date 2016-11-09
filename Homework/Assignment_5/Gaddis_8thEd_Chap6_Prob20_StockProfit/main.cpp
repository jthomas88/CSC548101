/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 22, 2016, 09:32 PM
 * Purpose: Raise a mysterious creature to adulthood
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>   //Set precision to dollars and cents

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
float stkProf(int,float,float,float,float);

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    int   numShar; //Number of shares owned
    float salePrc; //Current sale price
    float salComm; //Sale commission
    float purcPrc; //Original purchase price
    float purComm; //Purchase commission
    
    //Input Values
    cout<<"Enter the number of shares you own: ";
    cin>>numShar;
    cout<<"Enter the amount the stocks are currently worth: $";
    cin>>salePrc;
    cout<<"Enter the amount the stocks were purchased for: $";
    cin>>purcPrc;
    cout<<"Enter the sale commission: $";
    cin>>salComm;
    cout<<"Enter the purchase commission: $";
    cin>>purComm;
    //Process Values
    cout<<endl;
    cout<<"Current net profit: $";
    cout<<fixed<<setprecision(2);
    //Output calculated value
    cout<<stkProf(numShar,salePrc,purcPrc,salComm,purComm);
    
    //Exit program
    return 0;
}

//Stock profit calculation function
float stkProf(int numShar,float salePrc,float purcPrc,float salComm,float purComm)
{
    float profit; //Holds profit value
    profit=((numShar*salePrc)-salComm)-((numShar*purcPrc)+purComm);
    return profit;
}

