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

int findMat(int[],int,int);

void slctSrt(int[],int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    const int SIZE=18;
    //int acctNum=rand()%9000000+1000000; //User's account number
    int acctTst=5658845;
    int accts[SIZE]={};  //18 Account Numbers
    
    //Read in values from file and write into array
    fillAry(accts,SIZE);
    
    //Output values from array
    cout<<"Account numbers on file:"<<endl;
    prntAry(accts,SIZE);
    cout<<endl;
    
    //Output acct number trying to be looked up
    cout<<"Your account number is: "<<acctTst;
    cout<<endl<<endl;
    
    //Sort acct numbers least to greatest
    slctSrt(accts,SIZE);
    
    //Output sorted numbers
    cout<<"Sorted account numbers: "<<endl;
    prntAry(accts,SIZE);
    cout<<endl;
    
    //Check if acct number matches any of the number on file
    findMat(accts,SIZE,acctTst)?cout<<"The account number matches."
            :cout<<"Cannot find account number.";
    
    //Exit program
    return 0;
}
void fillAry(int array[],int size){
    ifstream read;
    read.open("accts.dat");
    for(int i=0;i<size;i++){
        read>>array[i];
    }
    read.close();
}

void prntAry(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<' ';
        if(i%2==1)cout<<endl;
    }
}

int  findMat(int array[],int size,int match){
    //Declare and setup
    int beg=0;  //Initialize start point
    int mid;
    int end=size-1; //Initialize end point
    bool found=false;
    int pos=-1;
    //Loop until found
    do{
        mid=(beg+end)/2;
        if(array[mid]==match){
            found=true;
            pos=mid;
        }
        else if(array[mid]<match){
            beg=mid+1;
        }else{
            end=mid-1;
        }
    }while(end>=beg&&found!=true);
    return pos;
}

void slctSrt(int array[],int size){
    int temp=0;
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
        }while(isSwap);     
}
