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

//Function prototypes

//Write to file function
void ppltAry(string,int);
//Read from array function
void fillAry(int[],string,int);
void prntAry(int[],int);
void prnt2d(int[][10],int);

//Update scoreboard function
void updtScr(int[][10],int[],int);

//Display scoreboard function
void dispScr(int[][10],int);

//Reset frame function
void reset(bool[],int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    const int PINS=10;
    
    bool isKnok[PINS]={};
    char pins[PINS];
    char board[4][7];
    
    
    //int score[][10]={};
    
    int utilize=4; //Number of columns to be utilized
    int totCont=0; //Score counter for each frame
    
    int rawScor[utilize*10]={};
    int dspScor[utilize][10]={};
    string file="scoretest.dat";
    
    //Fill file
    //ppltAry(file,utilize*10);
    
    //Fill array
    fillAry(rawScor,file,utilize*10);
    
    //Output Array
    prntAry(rawScor,utilize*10);
    cout<<endl<<endl;
    
    //Output 2d before update
    prnt2d(dspScor,utilize);
    cout<<endl<<endl;
    
    //Output 2d after update
    updtScr(dspScor,rawScor,utilize);
    prnt2d(dspScor,utilize);
    
    //Cross-Reference Against 2D Array
    //updtScr(dspScor,rawScor,utilize);
    //dispScr(dspScor,utilize);
    
    //Exit program
    return 0;
}

void reset(bool isKnok[],int size){
    for(int i=0;i<size;i++){
        isKnok[i]=0;
    }
}

void toss(bool isKnok[],int size,int &totCont){
    int curCont=0;
    for(int i=0;i<size;i++){
        if(isKnok[i]!=1){
            isKnok[i]=rand()%2;
            if(isKnok[i]==1){
                curCont++;
            }
        }
    }
    totCont+=curCont;
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

void updtScr(int dspScor[][10],int rawScor[],int utilize){
    for(int i=0;i<10;i++){
        for(int j=0;j<utilize;j++){
            dspScor[j][i]=rawScor[(i*utilize)+j];
        }
    }
}

void dispScr(int score[][10],int utilize){
    for(int i=0;i<utilize;i++){;
        for(int j=0;j<10;j++){
            cout<<score[i][j]<<"  | ";
            if(j%10==9)cout<<endl;
        }
    }
}

//1D Array Functions
void ppltAry(string file,int size){
    ofstream write;
    write.open(file);
    for(int i=0;i<size;i++){
        write<<rand()%10;
        write<<endl;
    }
    write.close();
}

void fillAry(int rawScor[],string file,int size){
    ifstream read;
    read.open(file);
    for(int i=0;i<size;i++){
        read>>rawScor[i];
    }
    read.close();
}

void prntAry(int rawScor[],int size){
    for(int i=0;i<size;i++){
        cout<<rawScor[i]<<' ';
        if(i%10==9)cout<<endl;
    }
}

void prnt2d(int dspScor[][10],int utilize){
    for(int i=0;i<utilize;i++){;
        for(int j=0;j<10;j++){
            cout<<dspScor[i][j]<<' ';
            if(j%10==9)cout<<endl;
        }
    }
}