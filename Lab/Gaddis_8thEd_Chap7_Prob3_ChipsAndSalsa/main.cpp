/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 22, 2016, 09:32 PM
 * Purpose: Raise a mysterious creature to adulthood
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>
#include <iomanip>

using namespace std; //Namespace used in system library

//User libraries

//Global constants
const int SIZE=5;

//Function prototypes
void fillAry(string[],int[]);
void prntAry(string[],string[],int[]);

int findHig(int[],int&);

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    //Initialize string array with 5 different flavors of salsa
    string flavor[SIZE]={"Mild","Medium","Sweet","Hot","Zesty"};
    string spacer[SIZE]={"  ",""," ","   "," "};
    //Initialize sales array to zero;
    int    sales[SIZE]={};    
    //Set counter
    int counter=0;
    
    //Fill sales array
    fillAry(flavor,sales);
    prntAry(flavor,spacer,sales);
    findHig(sales,counter);
    
    cout<<"The best selling flavor was "<<flavor[counter]
        <<" with "<<findHig(sales,counter)<<" sales.";
    
    //Process Values
    
    //Exit program
    return 0;
}

void fillAry(string flavor[],int sales[]){
    for(int i=0;i<SIZE;i++){
        cout<<"Enter the number of sales for "<<flavor[i]<<" flavor: ";
        cin>>sales[i];
        cout<<endl;
    }
}

void prntAry(string flavor[],string spacer[],int sales[]){
    for(int i=0;i<SIZE;i++){
        cout<<flavor[i]<<spacer[i]<<' '<<sales[i];
        cout<<endl;
    }
}

int findHig(int sales[],int &count){
    int high=0;
    for(int i=0;i<SIZE;i++){
        if(sales[i]<high){
            count++;
        }
        if(sales[i]>high)
            high=sales[i];
    }
    return high;
}