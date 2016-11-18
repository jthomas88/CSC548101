/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 22, 2016, 09:32 PM
 * Purpose: Raise a mysterious creature to adulthood
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>   //Random generator
#include <ctime>     //Random seed

using namespace std; //Namespace used in system library

//User libraries

//Global constants
const int SIZE=10;

//Function prototypes
void fillAry(int[]);
void prntAry(int[]);

int findHig(int[]);
int findLow(int[]);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
            
    //Declaration of variables
    int array[SIZE]={};
    
    //Fill Array
    fillAry(array);
    
    //Output Array
    prntAry(array);
    cout<<endl;
    
    //Find highest value and output
    cout<<"Highest Value: "<<findHig(array);
    cout<<endl;
    
    //Find lowest value and output
    cout<<"Lowest Value: "<<findLow(array);        
    
    //Process Values
    
    //Exit program
    return 0;
}

//Find Highest
int findHig(int array[]){
    int high=0;
    for(int i=0;i<SIZE;i++){
        if(array[i]>high){
            high=array[i];
        }
    }
    return high;
}

//Find Lowest
int findLow(int array[]){
    int high=0;
    int low=0;
    for(int i=0;i<SIZE;i++){
        if(array[i]>high){
            high=array[i];
        }
    }
    for(int i=0;i<SIZE;i++){
        if(array[i]<high){
            low=array[i];
            high=low;
        }
    }
    return low;
}

//Fill Array
void fillAry(int array[]){
    for(int i=0;i<SIZE;i++){
        array[i]=rand()%90+10;
    }
}

//Print Array
void prntAry(int array[]){
    int count=0;
    for(int i=0;i<SIZE;i++){
        cout<<array[i]<<' ';
        if(count++==9){
            cout<<endl;
            count=0;
        }
    }
}