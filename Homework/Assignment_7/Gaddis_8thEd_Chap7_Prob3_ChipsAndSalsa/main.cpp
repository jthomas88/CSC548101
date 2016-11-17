/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on November 15, 2016, 08:32 AM
 * Purpose: Determine sales figures for a salsa company
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
void fillAry(string[],int[]); //Fills array with sales data
void prntAry(string[],string[],int[]); //Outputs array

int  findHig(int[],int&); //Finds highest value in array
int  findLow(int[],int&); //Finds lowest value in array

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    
    //Initialize string array with 5 different flavors of salsa
    string flavor[SIZE]={"Mild","Medium","Sweet","Hot","Zesty"};
    
    //Spacer values to format table
    string spacer[SIZE]={"  ",""," ","   "," "};
    
    //Initialize sales array to zero;
    int    sales[SIZE]={};    
    
    //Set counter
    int counter=0;
    
    //Fill sales array
    fillAry(flavor,sales);
    
    //Display table of sales
    prntAry(flavor,spacer,sales);
    cout<<endl;
    
    //Find highest value in the array
    findHig(sales,counter);
    
    //Display best selling flavor
    cout<<"The most popular flavor was "<<flavor[counter]
        <<" with "<<findHig(sales,counter)<<" sales.";
    cout<<endl;
    
    //Find lowest value in the array
    findLow(sales,counter);
    
    //Display worst selling flavor
    cout<<"The least popular flavor was "<<flavor[counter]
        <<" with "<<findLow(sales,counter)<<" sales.";   
    
    //Exit program
    return 0;
}

//Fill Array
void fillAry(string flavor[],int sales[]){
    for(int i=0;i<SIZE;i++){
        cout<<"Enter the number of sales for "<<flavor[i]<<" flavor: ";
        cin>>sales[i];
        cout<<endl;
    }
}

//Print Array
void prntAry(string flavor[],string spacer[],int sales[]){
    for(int i=0;i<SIZE;i++){
        cout<<flavor[i]<<spacer[i]<<' '<<sales[i];
        cout<<endl;
    }
}

//Find Highest
int findHig(int sales[],int &count){
    int high=0;
    for(int i=0;i<SIZE;i++){
        if(sales[i]>high){
            high=sales[i];
            count=i;
        }
    }
    return high;
}

//Find Lowest
int findLow(int sales[],int &count){
    int high=0;
    int low=0;
    for(int i=0;i<SIZE;i++){
        if(sales[i]>high){
            high=sales[i];
        }
    }
    for(int i=0;i<SIZE;i++){
        if(sales[i]<high){
            low=sales[i];
            high=low;
            count=i;
        }
    }
    return low;
}