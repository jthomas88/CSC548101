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
const int SIZE=18;

void fillAry(int[]);
void prntAry(int[]);
bool findMat(int[],int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    int acctNum=rand()%9000000+1000000; //User's account number
    int accts[SIZE]={};  //18 Account Numbers
    
    //Read in values from file and write into array
    fillAry(accts);
    
    //Output values from array
    cout<<"Account numbers on file:"<<endl<<endl;
    prntAry(accts);
    cout<<endl;
    
    //Output acct number trying to be looked up
    cout<<"Your account number is: "<<acctNum;
    cout<<endl;
    
    //Check if acct number matches any of the number on file
    findMat(accts,acctNum)==0?cout<<"The account number matches."
            :cout<<"Cannot find account number.";
    
    //Exit program
    return 0;
}
void fillAry(int array[]){
    ifstream read;
    read.open("accts.dat");
    for(int i=0;i<SIZE;i++){
        read>>array[i];
    }
    read.close();
}

void prntAry(int array[]){
    for(int i=0;i<SIZE;i++){
        cout<<array[i]<<' ';
        if(i%2==1)cout<<endl;
    }
}

bool findMat(int array[],int acctNum){
    for(int i=0;i<SIZE;i++){
        if(acctNum==array[i]){
            return 0;
        }
    }
    return 1;
}
