/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on November 17, 2016, 11:45 PM
 * Purpose: Find values in an array larger than the specified value
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>   //Random generator
#include <ctime>     //Random seed
#include <iomanip>   //Formatting

using namespace std; //Namespace used in system library

//User libraries

//Global constants
const int SIZE=100; //Array Size

//Function prototypes

//Fill and Print Functions
void fillAry(int[]);
void prntAry(int[]);

//Search Functions
void lrgThnN(int,int[]); //Finds values larger than n

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
            
    //Declaration of variables
    int n=rand()%90+10; //Assigns N to random 2 digit number
    
    int array[SIZE]={};
    
    //Fill Array
    fillAry(array);
    
    //Output Array
    prntAry(array);
    cout<<endl;
    
    //Output specified value
    cout<<"Chosen value: "<<n;
    cout<<endl;
    
    //Find values greater than n and output;
    lrgThnN(n,array);
    
    //Exit program
    return 0;
}

//Find Highest
void lrgThnN(int n,int array[]){
    int count=0;
    for(int i=0;i<SIZE;i++){        
        if(array[i]>n){
            cout<<array[i]<<' ';
            count++;
        }
        if(count==10){
            cout<<endl;
            count=0;
        }
    }
}

//Fill Array
void fillAry(int array[]){
    int random;
    for(int i=0;i<SIZE;i++){
        random=rand()%90+10;
        array[i]=random;
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