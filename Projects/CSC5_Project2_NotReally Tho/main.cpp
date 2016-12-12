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
void prntAry(int[][MAXPLAY],string[],string[]);
void fillAry(int[][MAXPLAY]);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables    
    int    score[FRAMES][MAXPLAY]={};
    string names[MAXPLAY]={"Jeff    |","Sneed   |","        |","        |"};
    string align[MAXPLAY]={};
    
    //Fill in Scores
    fillAry(score);
    
    //Output Scoreboard
    prntAry(score,names,align);
    
    
    //Exit program
    return 0;
}

void prntAry(int score[][MAXPLAY],string names[],string align[]){
    cout<<"        ";
    //Ouput 
    for(int i=0;i<FRAMES;i++){
        cout<<"Frame "<<i+1<<' ';
    }
    cout<<endl<<"        ";
    for(int i=0;i<FRAMES;i++){
        cout<<"--------";
    }
    cout<<endl;
    for(int i=0;i<MAXPLAY;i++){       
        cout<<names[i];
        for(int j=0;j<FRAMES;j++){
            cout<<score[i][j]<<"      |";
        }
        cout<<endl;
    }
}

//Fix this
void fillAry(int score[][MAXPLAY]){
    ofstream write;
    write.open("scoretest.dat");
    for(int i=0;i<MAXPLAY;i++){
        for(int j=0;j<FRAMES;j++){
            score[j][i]=i+1; 
            write<<score[j][i];
            write<<endl;
        }
    }
    write.close();
}