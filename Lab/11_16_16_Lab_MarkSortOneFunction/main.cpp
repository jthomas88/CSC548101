/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on November 16, 2016, 09:32 AM
 * Purpose: Mark Sort in one function
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>   //Random Generator
#include <ctime>     //Random Seed

using namespace std; //Namespace used in system library

//User libraries

//Global constants
int SIZE=50;

//Function prototypes
void fillAry(int[]);
void prntAry(int[]);
void swap(int&,int&);

void minPos(int [],int,int);
void markSrt(int [],int);
void markSrt1F(int[],int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize Rand Seed
    srand(time(0));
    
    //Declaration of variables
    int array[SIZE]={};
    
    fillAry(array);
    prntAry(array);
    markSrt1F(array,SIZE);
    cout<<endl;
    prntAry(array);
    
    //Process Values
    
    //Exit program
    return 0;
}
void fillAry(int array[]){
    int num;
    for(int i=0;i<SIZE;i++){
        num=rand()%90+10;
        array[i]=num;
    }
}

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

void markSrt1F(int a[],int size){   
    for(int i=0;i<size-1;i++){
        int pos=i;
        for(int j=pos+1;j<size;j++){
            if(a[pos]>a[j]){
                a[pos]=a[pos]^a[j];
                a[j]=a[pos]^a[j];
                a[pos]=a[pos]^a[j];
            }
        }
    }
}

void markSrt(int a[],int size){
    for(int i=0;i<size-1;i++){
        minPos(a,size,i);
    }
}

void minPos(int a[],int size,int pos){
    for(int j=pos+1;j<size;j++){
        if(a[pos]>a[j])swap(a[pos],a[j]);
    }
}

void swap(int &a,int &b){
    /*
    *
    //Temp Memory Swap
    int temp=a;
    a=b;
    b=temp;
     * */
    
    //In Place Memory Swap
    a=a^b;
    b=a^b;
    a=a^b;
}