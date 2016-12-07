/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>   //Random number generator
#include <ctime>     //Random number seed

using namespace std; //Namespace used in system library

//User libraries

//Global constants
int const FRAME=10; //Number of frames in a game of bowling

//Function prototypes

//Pin display functions
//Check if pins are outputting on board correctly
void prntBrd(bool[],char[],int);
//Assign char value to each element of 4x7 array
void fillBrd(char[][7],char[],int);
//Output char array
void dispBrd(char[][7],int);

//Scoreboard functions
//Assign new 1D array values to 2D array
void updtScr(int[][10],int[],bool[],int,int&);
//Output scoreboard function
void dispScr(int[][FRAME],int);

//Array manipulation functions
//Randomly assign bool value for each pin
void toss(bool[],int,int&);
//Set all pins back to standing
void reset(bool[],int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declare constants
    int PIN=10;    //Number of pins on the board
    
    
    //Declare Variables
    int utilize=0; //Number of array rows to be utilized
    int totCont=0; //Total number of pins knocked down in one frame
    
    //Input number of players
    cin>>utilize;
    
    //Declare Arrays
    int  rawScor[utilize*10]={};     //Holds frame scores for all players
    bool isPassd[utilize*10]={};//Holds whether frame has been completed
    int  dspScor[utilize][FRAME]={}; //"Parallel" array to rawScor
    bool isKnok[PIN]={};             //Holds standing/fallen status of pins
    char pins[PIN]={};               //Displays a standing or fallen pin
    char board[4][7];                //Displays entire 10 pin board
    
    //Output Scoreboard
    cout<<"Scores"<<endl;
    dispScr(dspScor,utilize);
    cout<<endl;

    //Display before any throws
    cout<<"Starting board"<<endl;
    prntBrd(isKnok,pins,PIN);
    cout<<endl<<endl;
    
    fillBrd(board,pins,7);
    dispBrd(board,7);
    cout<<endl<<endl;
    
    for(int i=0;i<40;i++){
        isPassd[i]=1;
    }
    
    for(int i=0;i<40;i++){
        cout<<isPassd[i]<<' ';
        if(i%10==9)cout<<endl;
    }
    cout<<endl;

    for(int i=0;i<40;i++){
        //Take first throw (P1)
        toss(isKnok,PIN,totCont);

        //Update score and board
        updtScr(dspScor,rawScor,isPassd,utilize,totCont);
        cout<<"Scores"<<endl;
        dispScr(dspScor,utilize);
        cout<<endl;

        cout<<"Roll "<<i+1<<endl;
        prntBrd(isKnok,pins,PIN);
        cout<<endl<<endl;

        fillBrd(board,pins,7);
        dispBrd(board,7);
        cout<<endl<<endl;
        reset(isKnok,PIN);
    }
    
    //Exit program
    return 0;
}

//Pin display functions
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

//Scoreboard Functions
void updtScr(int dspScor[][10],int rawScor[],bool isPassd[],int utilize,int &totCont){
    //int count=0;
/*
 *
    for(int i=0;i<10;i++){
        for(int j=0;j<utilize;j++){
            if(isPassd[(i*utilize)+j]!=0){
                rawScor[(i*utilize)+j]=totCont;
                isPassd[(i*utilize)+j]=0;
                totCont=0;
                break;
            }
            //totCont=0;
        }
        //totCont=0;
    }
*/
    for(int i=0;i<utilize*10;i++){
        if(isPassd[i]==0){
            rawScor[i]=rawScor[i];
        }
        if(isPassd[i]!=0){
            rawScor[i]=totCont;
            isPassd[i]=true;
            totCont=0;
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<utilize;j++){
            dspScor[j][i]=rawScor[(i*utilize)+j];
        }
    }
}






void dispScr(int dspScor[][10],int utilize){
    for(int i=0;i<utilize;i++){;
        for(int j=0;j<10;j++){
            cout<<dspScor[i][j]<<' ';
            if(j%10==9)cout<<endl;
        }
    }
}

//Array manipulation functions
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

void reset(bool isKnok[],int size){
    for(int i=0;i<size;i++){
        isKnok[i]=0;
    }
}