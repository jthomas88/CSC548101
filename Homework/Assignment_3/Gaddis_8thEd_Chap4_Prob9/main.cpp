/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 5, 2016, 09:37 PM
 * Purpose: Calculate a discount for bulk purchases
 */

//System Libraries
#include <iostream>  //Input/Output objects
using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    unsigned short unitCst=99; //Given cost per unit
    float subTtl;              //Total cost before discount
    float finTtl;              //Total cost after discount
    int unitAmt;      //User inputted number of units
    float dsct;                //Discount %
    
    //Input values
    cout<<"Enter the number of units to be purchased: ";
    cin>>unitAmt;
    
    //Input Validation
    while(unitAmt<1)
    {
        cout<<endl;
        cout<<"Invalid input. Minimum purchase is 1 unit."<<endl;
        cout<<"Enter the number of units to be purchased: ";
        cin>>unitAmt;
    }
    
    //Process values -> map inputs to outputs
    //Ternary operator to determine discount percentage
    (unitAmt/10==1)?dsct=0.2:
    ((unitAmt/10)>=2&&(unitAmt/10)<5)?dsct=0.3:
    ((unitAmt/10)>=5&&(unitAmt/10)<10)?dsct=0.4:
    ((unitAmt/10)>=10)?dsct=0.5:dsct=0;    
    
    subTtl=unitCst*unitAmt; //Calculate subtotal
    finTtl=subTtl*dsct;     //Calculate total w/ discount
    
    //Display output
    cout<<"Subtotal: $"<<subTtl<<endl;
    cout<<"Discount: "<<dsct<<"%"<<endl;
    cout<<"Total   : $"<<finTtl<<endl;

    //Exit program
    return 0;
}

