/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on November 28, 2016, 10:40 AM
 * Purpose: Raise a mysterious creature to adulthood
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>   //Random Numbers
#include <ctime>     //Random Seed
#include <fstream>   //File I/O

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
void fillAry(int[],int);
void prntAry(int[],int);
void copyAry(int[],int[],int);

int  linSrch(int[],int,int);
int  binSrch(int[],int,int);

void slcOrdr(int[],int);
void bubOrdr(int[],int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    const int SIZE=8;
    int bubArry[SIZE]={};//8 element array for bubble sort
    int slcArry[SIZE]={};//8 element array for selection sort
    
    //Populate first array with random elements
    fillAry(bubArry,SIZE);
    
    //Copy values of first array to second array
    copyAry(bubArry,slcArry,SIZE);
    
    //Output first array
    cout<<"Bubble Array"<<endl;
    prntAry(bubArry,SIZE);
    cout<<endl;
    
    //Output second array
    cout<<"Selection Array"<<endl;
    prntAry(slcArry,SIZE);
    cout<<endl<<endl;
    
    //Test efficiency of bubble sort
    cout<<"Bubble Sorted Array"<<endl;
    bubOrdr(bubArry,SIZE);
    cout<<endl;
    
    
    //Test efficiency of linear sort
    cout<<"Selection Sorted Array"<<endl;
    slcOrdr(slcArry,SIZE);
    cout<<endl;
    
    //Exit program
    return 0;
}

void fillAry(int array[],int size){
    for(int i=0;i<size;i++){
        array[i]=rand()%90+10;
    }
}

void copyAry(int array[],int copy[],int size){
    for(int i=0;i<size;i++){
        copy[i]=array[i];
    }
}

void prntAry(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<' ';
        if(i%10==9)cout<<endl;
    }
}

void bubOrdr(int array[],int size){
    int temp=0;
    int count=0;
    bool isSwap;
    do{
        isSwap=false;
        for(int i=-1;i<size-1;i++){
            if(array[i]>array[i+1]){
                temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
                isSwap=true;    
            }
        }
        count++;
        cout<<"Pass "<<count<<": ";
        prntAry(array,size);
        cout<<endl;
    }while(isSwap);   
}

void slcOrdr(int array[],int size){
    int count=0;
    for(int i=0;i<size-1;i++){
        int mIndx=i;
        int minVal=array[i];
        for(int j=i+1;j<size;j++){
            if(array[j]<minVal){
                minVal=array[j];
                mIndx=j;
                //count++;
            }
        }
        array[mIndx]=array[i];
        array[i]=minVal;
        count++;
        cout<<"Pass "<<count<<": ";
        prntAry(array,size);
        cout<<endl;
    }
}