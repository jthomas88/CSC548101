/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 22, 2016, 09:32 PM
 * Purpose: Raise a mysterious creature to adulthood
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <ctime>     //Random seed
#include <cstdlib>   //Random generator

using namespace std; //Namespace used in system library

//User libraries

//Global constants
const int SIZE=3; 

//Function prototypes
bool isMagic(int[][SIZE]);

void fillAry(int[][SIZE]);
void prntAry(int[][SIZE]);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    int rndSqr[][SIZE]={};
    int magSqr[SIZE][SIZE]={4,9,2,3,5,7,8,1,6};
    
    //Fill Array
    fillAry(rndSqr);
    
    //Output magic square
    prntAry(magSqr);
    cout<<endl;
    
    //Output random square
    prntAry(rndSqr);
    cout<<endl;
    
    //Exit program
    return 0;
}

void fillAry(int square[][SIZE]){
    int num=rand()%9+1; //Random number 1-9
    int a,b;
    for(a=0;a<SIZE;a++){
        for(b=0;b<SIZE;b++){
            square[a][b]=rand()%9+1;
        }
    }
}

void prntAry(int square[][SIZE]){
    int a,b;
    int count;
    for(a=0;a<SIZE;a++){
        for(b=0;b<SIZE;b++){
            cout<<square[a][b]<<' ';
            if(b==2){
                cout<<endl;
            }
        }
    }
}

bool isMagic(int square[][SIZE]){
    int a,b;
    int sum;
    
    for(int a=0;a<SIZE;a++){
        for(int b=0;b<SIZE;b++){
            if(a%2==0&&b%2==0){
                if(square[a][b]%2==0){
                    
                }
            }
            if(a%2)
        }
    }
}

bool chkOdds

bool chkEven

