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
const int SIZE=10;

void fillAry(int[]);
void prntAry(int[]);
//int  slctWin(int);
bool findWin(int[],int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    int lotto=rand()%90000+10000; //This week's lotto number
    //int lotto=77777; //Test variable
    int tix[SIZE]={};  //10 Lottery tickets
    
    //Process Values
    fillAry(tix);
    cout<<"Your tickets"<<endl<<endl;
    prntAry(tix);
    cout<<endl;
    cout<<"This week's winning lottery number is: "<<lotto;
    cout<<endl;
    findWin(tix,lotto)==0?cout<<"A winner is you!":cout<<"Sorry, loser!";
    
    //Exit program
    return 0;
}
void fillAry(int array[]){
    ifstream read;
    read.open("tix.dat");
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

bool findWin(int array[],int winner){
    for(int i=0;i<SIZE;i++){
        if(winner==array[i]){
            return 0;
        }
    }
    return 1;
}
