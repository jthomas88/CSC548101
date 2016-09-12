
/* 
   File:   main
   Author: Jeffrey Thomas
   Created on August 29, 2016, 9:41 AM
   Purpose: Calculate NASA 2016 Budget Percentage
 * Reference: https://www.nasa.gov/sites/default/files/files/NASA_FY2016_Summary
 * _Brief_corrected.pdf
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
char PERCENT=100; //Percentage constant

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float usBdgt=3.999e12f; //Total US Federal Budget 2016
    float nsBdgt=18.5e9f;   //Total NASA Budget 2016
    float bdgtPct;          //Percentage of the budget
    
    //Process values -> Map inputs to Outputs
    bdgtPct=nsBdgt/usBdgt*PERCENT; //Calculation to find percentage
    
    //Display Output
    cout<<"US Federal Budget 2016: $"<<usBdgt<<endl;
    cout<<"NASA Budget 2016: $"<<nsBdgt<<endl;
    cout<<"Percentage of US budget NASA uses: "<<bdgtPct<<"%";

    //Exit Program
    return 0;
}