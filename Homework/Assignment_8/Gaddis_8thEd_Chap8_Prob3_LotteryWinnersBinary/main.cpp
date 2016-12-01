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

int findWin(int[],int,int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    const int SIZE=10;
    int winner=rand()%90000+10000; //This week's lotto number
    //int winner=77777; //Test variable
    int tix[SIZE]={};  //10 Lottery tickets
    
    //Read values from file
    fillAry(tix,SIZE);
    
    //Display Array
    cout<<"Your tickets"<<endl<<endl;
    prntAry(tix,SIZE);
    cout<<endl;
    
    //Display winning number
    cout<<"This week's winning lottery number is: "<<winner;
    cout<<endl;
    
    //Check if player has won
    findWin(tix,SIZE,winner)!=-1?cout<<"A winner is you!":cout<<"Haha, loser!";
    
    //Exit program
    cout<<endl;
    return 0;
}
void fillAry(int array[],int size){
    ifstream read;
    read.open("tix.dat");
    for(int i=0;i<size;i++){
        read>>array[i];
    }
    read.close();
}

void prntAry(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<"Number "<<i+1<<": "<<array[i]<<' ';
        if(i%2==1)cout<<endl;
    }
}

int  findWin(int array[],int size,int winner){
    //Declare and setup
    int beg=0;  //Initialize start point
    int mid;
    int end=size-1; //Initialize end point
    bool found=false;
    int pos=-1;
    //Loop until found
    do{
        mid=(beg+end)/2;
        if(array[mid]==winner){
            found=true;
            pos=mid;
        }
        else if(array[mid]<winner){
            beg=mid+1;
        }else{
            end=mid-1;
        }
    }while(end>=beg&&found!=true);
    return pos;
}
