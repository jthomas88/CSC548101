/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 22, 2016, 09:32 PM
 * Purpose: Raise a mysterious creature to adulthood
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std; //Namespace used in system library

//User libraries

//Global constants
int const FRAMES=10;
int const MAXPLAY=4;

//Function prototypes
//void prntAry(bool[],int);
void prntBrd(bool[],char[],int);
void toss(bool[],int,int&);

void fillBrd(char[][7],char[],int);
void dispBrd(char[][7],int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    const int PINS=10;
    
    bool isKnok[PINS];
    char pins[PINS];
    char board[4][7];
    
    int count=0;
    
    //Display before any throws
    cout<<"Starting board"<<endl;
    prntBrd(isKnok,pins,PINS);
    cout<<endl;
    fillBrd(board,pins,7);
    dispBrd(board,7);
    cout<<endl<<endl;
    
    //Take first throw
    toss(isKnok,PINS,count);
     
    //Display after first throw
    cout<<"After first throw"<<endl;
    cout<<"Pins fallen: "<<count<<endl;
    prntBrd(isKnok,pins,PINS);
    cout<<endl;
    fillBrd(board,pins,7);
    dispBrd(board,7);
    cout<<endl<<endl;
    
    //Take second throw
    toss(isKnok,PINS,count);
    
    //Display after second throw
    cout<<"After second throw"<<endl;
    cout<<"Pins fallen: "<<count<<endl;
    prntBrd(isKnok,pins,PINS);
    cout<<endl;
    fillBrd(board,pins,7);
    dispBrd(board,7);
    cout<<endl<<endl;
    
    //Exit program
    return 0;
}

/*
 *
void prntAry(bool array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i];
    }
}*/

void toss(bool isKnok[],int size,int &count){
    count=0;
    for(int i=0;i<size;i++){
        if(isKnok[i]!=1){
            isKnok[i]=rand()%2;
            count++;
        }
    }
}

void prntBrd(bool isKnok[],char pins[],int size){
    for(int i=0;i<size;i++){
        isKnok[i]%2==0?pins[i]='o':pins[i]='x';
    }
    for(int i=0;i<size;i++){
        cout<<pins[i]<<' ';
    }
}

void fillBrd(char board[][7],char pins[],int size){
    int k=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<size;j++){
            
            board[i][j]='-';
            if(i==j%2||i==j||(i%2==0&&j==i+2)){
                board[i][j]=pins[k];
                k++;
            }
            
        }
    }
}

void dispBrd(char board[][7],int size){
    for(int i=0;i<4;i++){
        for(int j=0;j<size;j++){
            cout<<board[i][j];
            if(j%7==6)cout<<endl;
        }
    }
}