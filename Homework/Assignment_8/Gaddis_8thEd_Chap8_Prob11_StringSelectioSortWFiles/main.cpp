/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 22, 2016, 09:32 PM
 * Purpose: Raise a mysterious creature to adulthood
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <string>    //String manipulation
#include <fstream>   //Read from file

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
//Fill and Print Functions
void writAry(string[],int);
void prntAry(string[],int);

//Sorting functions
void strgSrt(string[],int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    int const SIZE=20;
    string names[SIZE]={}; 
    
    //Read in data from file
    writAry(names,SIZE);
    
    //Print Array Before Sort
    cout<<"Names before sort:"<<endl;
    prntAry(names,SIZE);
    cout<<endl<<endl;
    
    //Sort Array
    strgSrt(names,SIZE);
    
    //Print Array After Sort
    cout<<"Names after sort:"<<endl;
    prntAry(names,SIZE);
    cout<<endl;
    
    //Process Values
    
    //Exit program
    return 0;
}

void strgSrt(string names[],int size){
    for(int i=0;i<size-1;i++){
        int mIndx=i;
        string minVal=names[i];
        for(int j=i+1;j<size;j++){
            if(names[j]<minVal){
                minVal=names[j];
                mIndx=j;
            }
        }
        names[mIndx]=names[i];
        names[i]=minVal;
    }
}

void prntAry(string names[],int size){
    for(int i=0;i<size;i++){
        cout<<names[i];
        cout<<endl;
    }
}

void writAry(string names[],int size){
    ifstream read;
    read.open("names.dat");
    for(int i=0;i<size;i++){
        getline(read,names[i]);
    }
    read.close();
}
