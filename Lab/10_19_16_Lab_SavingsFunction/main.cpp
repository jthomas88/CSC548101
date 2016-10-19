/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 19, 2016, 10:10 AM
 * Purpose: Estimate savings after a given number of years
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cmath>     //Powers, exponentials, log
#include <iomanip>   //Format for dollar outputs

using namespace std; //Namespace used in system library

//User libraries

//Global constants
const float PERCENT=100.0f;

//Function prototypes
float save1(float,float,int);
float save2(float,float,int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    float pVal,intRate; //Principal value and interest rate respectively
    int   comPer;       //Number of compounding periods
    
    //Input values
    pVal=100.0f;       //$100
    intRate=8/PERCENT; //8%
    comPer=9;          //9 years
    
    //Process values -> map inputs to outputs    
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Present Value   : $"<<pVal<<endl;
    cout<<"Interest Rate   : "<<intRate<<"%/year"<<endl;
    cout<<"Years in Account: "<<comPer<<" years"<<endl;
    cout<<"Future Value    : $"<<save1(pVal,intRate,comPer)<<endl;
    
    //Display output    
    
    //Exit program
    return 0;
}
//Purpose: Show rule of 72
//Inputs : 
//  p - Inital balance in $
//  i - Decimal value for the interest/year
//  n - number of compounding periods
//Output : Outputs 
float save1(float p,float i,int n){
    p*(pow(i+1,n));
}

//Purpose: Show rule of 72
//Inputs : 
//  p - Inital balance in $
//  i - Decimal value for the interest/year
//  n - number of compounding periods
//Output : Outputs 
float save2(float p,float i,int n){
    p*exp(n*log(1+i));
}