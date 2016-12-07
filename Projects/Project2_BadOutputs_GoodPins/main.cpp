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

//Score Management Functions
void dispScr(int[][10],int,string[]);
void updtScr(int[][10],int[],int,int&,int);

//Reset Function
void reset(bool[],int);

void outputArray(int[],int);

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
    
    int utilize=0; //Number of columns to be utilized
    int totCont=0; //Score counter for each frame
    
    //Ask how many people will be playing
    do{
    cout<<"How many players are there? (1 - 4 Players) ";
    cin>>utilize;
    }while(utilize<0||utilize>5);
    
    int rawScor[utilize*10]={};
    int dspScor[utilize][10]={};
    string names[utilize]={};
    
    for(int i=0;i<utilize;i++){
        cout<<"Input name of Player "<<i+1<<": ";
        cin>>names[i];
    }
    
    //Loop Begins Here
    for(int i=0;i<20;i++){
        //Output Scoreboard
        cout<<"Scores"<<endl;
        dispScr(dspScor,utilize,names);
        cout<<endl;

        //Display before any throws
        cout<<"Starting board"<<endl;
        prntBrd(isKnok,pins,PINS);
        cout<<endl;
        fillBrd(board,pins,7);
        dispBrd(board,7);
        cout<<endl<<endl;

        //Take first throw (P1)
        //cout<<"Press 'SPACE' to throw the ball.";
        //cin>>
        toss(isKnok,PINS,totCont);

        //Display after first throw
        cout<<"After first throw"<<endl;
        cout<<"Pins fallen: "<<totCont<<endl;
        prntBrd(isKnok,pins,PINS);
        cout<<endl;
        fillBrd(board,pins,7);
        dispBrd(board,7);
        cout<<endl<<endl;

        //Take second throw (P1)
        toss(isKnok,PINS,totCont);

        //Display after second throw
        cout<<"After second throw"<<endl;
        cout<<"Pins fallen: "<<totCont<<endl;
        prntBrd(isKnok,pins,PINS);
        cout<<endl;
        fillBrd(board,pins,7);
        dispBrd(board,7);
        cout<<endl<<endl;

        //Update Score
        updtScr(dspScor,rawScor,utilize,totCont,i);
        dispScr(dspScor,utilize,names);
        cout<<endl;

        //Reset Pins
        reset(isKnok,PINS);
        totCont=0;
    }
    cout<<endl<<endl<<endl;
    outputArray(rawScor,utilize);
    
    /*
     
    
    //Output Scoreboard
    cout<<"Scores"<<endl;
    dispScr(score,utilize,names);
    cout<<endl;
    
    //Display before any throws
    cout<<"Starting board"<<endl;
    prntBrd(isKnok,pins,PINS);
    cout<<endl;
    fillBrd(board,pins,7);
    dispBrd(board,7);
    cout<<endl<<endl;
    
    //Take first throw (P1)
    //cout<<"Press 'SPACE' to throw the ball.";
    //cin>>
    toss(isKnok,PINS,totCont);
     
    //Display after first throw
    cout<<"After first throw"<<endl;
    cout<<"Pins fallen: "<<totCont<<endl;
    prntBrd(isKnok,pins,PINS);
    cout<<endl;
    fillBrd(board,pins,7);
    dispBrd(board,7);
    cout<<endl<<endl;
    
    //Take second throw (P1)
    toss(isKnok,PINS,totCont);
    
    //Display after second throw
    cout<<"After second throw"<<endl;
    cout<<"Pins fallen: "<<totCont<<endl;
    prntBrd(isKnok,pins,PINS);
    cout<<endl;
    fillBrd(board,pins,7);
    dispBrd(board,7);
    cout<<endl<<endl;
    
    //Update Score
    updtScr(score,utilize,totCont);
    dispScr(score,utilize,names);
    cout<<endl;
    
    //Reset Pins
    reset(isKnok,PINS);
     * */
    
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

void updtScr(int dspScor[][10],int rawScor[],int utilize,int &totCont,int frame){
    for(int i=0;i<10;i++){
        for(int j=0;j<utilize;j++){
            if(dspScor[i][j]!=0)break;
            rawScor[i]=totCont;
            dspScor[j][i]=rawScor[(i*utilize)+j];
            //if(dspScor[i][j+1]==0)totCont=0;
        }
    }
}

void outputArray(int rawScor[],int utilize){
    for(int i=0;i<utilize*10;i++){
        cout<<rawScor[i]<<' ';
        if(i%10==9)cout<<endl;
    }
}

void dispScr(int score[][10],int utilize,string names[]){
    for(int i=0;i<utilize;i++){
        cout<<names[i]<<" | ";
        for(int j=0;j<10;j++){
            cout<<score[i][j]<<"  | ";
            if(j%10==9)cout<<endl;
        }
    }
}