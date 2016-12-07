/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on November 30, 2016, 10:30 PM
 * Purpose: CSC-5 Final Project
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
void updtScr(int[][FRAME],int[],bool[],int,int&);
//Output scoreboard function
void dispScr(int[][FRAME],string[],int);
void dispScr1D(int[],int);

//Array manipulation functions
//Randomly assign bool value for each pin
void toss(bool[],int,int&);
//Set all pins back to standing
void reset(bool[],int);

//Totaling functions
//Totals and returns score of an individual player
int ttlScor(int[][FRAME],int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declare constants
    int PIN=10;    //Number of pins on the board
    
    
    //Declare Variables
    int  utilize=0; //Number of array rows to be utilized
    int  totCont=0; //Total number of pins knocked down in one frame
    //char continu='';//Press enter to continue
    
    //Input number of players
    do{
        cout<<"Input the number of players (1 - 4)"<<endl;
        cin>>utilize;
    }while(utilize<1||utilize>4);
    
    
    //Declare Arrays
    int    rawScor[utilize*FRAME]={};  //Holds frame scores for all players
    bool   isPassd[utilize*FRAME]={};  //Holds whether frame has been completed
    int    dspScor[utilize][FRAME]={}; //"Parallel" array to rawScor
    bool   isKnok[PIN]={};             //Holds standing/fallen status of pins
    char   pins[PIN]={};               //Displays a standing or fallen pin
    char   board[4][7];                //Displays entire 10 pin board
    string names[utilize];             //Names of the players
    
    //Declare player names
    for(int i=0;i<utilize;i++){
        cout<<"Name of Player "<<i+1<<": ";
        cin>>names[i];
    }
    
    //Output Scoreboard
    cout<<"Scores"<<endl;
    dispScr(dspScor,names,utilize);
    cout<<endl;

    //Display before any throws
    cout<<"Starting board"<<endl;
    prntBrd(isKnok,pins,PIN);
    cout<<endl<<endl;
    
    fillBrd(board,pins,7);
    dispBrd(board,7);
    cout<<endl<<endl;
    
    //Set all bools to false
    for(int i=0;i<utilize*FRAME;i++){
        isPassd[i]=1;
    }
    
    //Set Counter
    int count=0;
    
    //Fixes bug in which 1st roll rolls automatically
    cin.ignore();
    
    do{
        cout<<"Press enter to roll"<<endl;
        cin.ignore();
                
        //Take first throw (P1)
        toss(isKnok,PIN,totCont);        
        
        //Update score and board
        //updtScr(dspScor,rawScor,isPassd,utilize,totCont);
        cout<<"Scores"<<endl;
        dispScr(dspScor,names,utilize);
        cout<<endl;

        //Display current pins
        cout<<"Roll "<<count<<endl;
        prntBrd(isKnok,pins,PIN);
        cout<<endl<<endl;

        fillBrd(board,pins,7);
        dispBrd(board,7);
        cout<<endl<<endl;
        
        //Take second throw
        cout<<"Press enter to roll"<<endl;
        cin.ignore();
                
        //Take first throw (P1)
        toss(isKnok,PIN,totCont);        
        
        //Update score and board
        updtScr(dspScor,rawScor,isPassd,utilize,totCont);
        cout<<"Scores"<<endl;
        dispScr(dspScor,names,utilize);
        cout<<endl;

        //Display current pins
        cout<<"Roll "<<count<<endl;
        prntBrd(isKnok,pins,PIN);
        cout<<endl<<endl;

        fillBrd(board,pins,7);
        dispBrd(board,7);
        cout<<endl<<endl;
        
        //Reset pins
        reset(isKnok,PIN);
        totCont=0;
        count++;
    }while(count<utilize*FRAME);
    
    //Return Player 1 Score
    for(int i=0;i<utilize;i++){
        cout<<names[i]<<"'s score: "<<ttlScor(dspScor,i);
        cout<<endl;
    }
    
    //Exit program
    return 0;
}

//Pin display functions
void prntBrd(bool isKnok[],char pins[],int size){
    //Check if pins is standing or fallen
    for(int i=0;i<size;i++){
        isKnok[i]%2==0?pins[i]='o':pins[i]='x';
    }
    //Output pin status
    for(int i=0;i<size;i++){
        cout<<pins[i]<<' ';
    }
}

void fillBrd(char board[][7],char pins[],int size){
    int k=0; //Third nested loop counter
    for(int i=0;i<4;i++){
        for(int j=0;j<size;j++){            
            board[i][j]='-'; //Set all tiles on board to '-'
            if(i==j%2||i==j||(i%2==0&&j==i+2)){
                //Change tile if it is in the position of one of the pins
                board[i][j]=pins[k];
                k++; //Increment counter
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
void updtScr(int dspScor[][FRAME],int rawScor[],bool isPassd[],int utilize,int &totCont){
    for(int i=0;i<utilize*10;i++){  //Set counter to increment for # of frames
        if(isPassd[i]!=0){          //Check if frame has passed yet
            rawScor[i]=totCont;     //Update score
            isPassd[i]=0;           //Indicate that frame has now passed
            totCont=0;              //Reset score
            break;                  //End loop
        }
    }
    
    for(int i=0;i<10;i++){
        for(int j=0;j<utilize;j++){
            dspScor[j][i]=rawScor[(i*utilize)+j]; //Assign 1D value to 2D array
        }
    }
}

//2D Array Display
void dispScr(int dspScor[][FRAME],string names[],int utilize){        
    for(int i=0;i<utilize;i++){;
    cout<<names[i]<<" | ";              //Output player names in front of scores
        for(int j=0;j<10;j++){
            if(dspScor[i][j]<10)cout<<' ';
            cout<<dspScor[i][j]<<" | ";        //Output scores
            
            if(j%10==9)cout<<endl;      //Line break after 10 frames
        }
    }
}

//Array manipulation functions
void toss(bool isKnok[],int size,int &totCont){
    int curCont=0;               //Score of current toss
    for(int i=0;i<size;i++){
        if(isKnok[i]!=1){        //Check if pin has been knocked down yet
            isKnok[i]=rand()%2;  //50% chance of knocking down unknocked pin 
            if(isKnok[i]==1){    //Check if any new pins have been knocked down
                curCont++;       //Add to throw total
            }
        }
    }
    totCont+=curCont;            //Add to frame total
}

void reset(bool isKnok[],int size){
    for(int i=0;i<size;i++){
        isKnok[i]=0;         //Set all pins back to standing
    }
}

//Totaling functions
int ttlScor(int dspScor[][FRAME],int player){
    int totScor=0;
    for(int i=0;i<FRAME;i++){
        totScor+=dspScor[player][i];
    }
    return totScor;
}