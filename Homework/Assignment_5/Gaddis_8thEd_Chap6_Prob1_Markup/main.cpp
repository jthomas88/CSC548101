/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on November 5, 2016, 2:30 PM
 * Purpose: Calculate the retail price of a product
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>   //Truncate output to dollars and cents

using namespace std; //Namespace used in system library

//User libraries

//Global constants
const int PERCENT=100; //Percent conversion constant

//Function prototypes
void markup(float,int,float&); //

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    float whlSale=0.00f; //Wholesale product price
    int   mrkPerc=0;     //Markup rate
    float total=0;       //Retail markup price
    
    
    //Announce purpose
    cout<<"This program calculates the retail price of a product."<<endl;
    cout<<endl;
    
    //Input values
    cout<<"Enter a products wholesale price: $";
    cin>>whlSale;
    cout<<"Enter the retail markup in percent: ";
    cin>>mrkPerc;
    
    //Call markup function
    markup(whlSale,mrkPerc,total);
    
    //Output total
    cout<<"The retail price of this product is: $";
    cout<<fixed<<setprecision(2)<<total;
    cout<<endl<<endl;
    
    //Exit program
    return 0;
}

void markup(float price,int markup,float &total){
    //Formula to determine final price
    total=price*(static_cast<float>(markup)/PERCENT)+price;
}