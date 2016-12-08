/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <fstream>
#include <string>

using namespace std; //Namespace used in system library

//User libraries

//Global constants
int const LENGTH=5;
int const WIDTH=5;

//Function prototypes
void dispMap(int [LENGTH][WIDTH]);
void fillFloor(char[][LENGTH][WIDTH],int,string);

//Execution begins here
int main(int argc, char** argv) 
{
    //Declare Structures
    struct Monster{
        int    hpt;   //Health Points
        int    atk;   //Base Attack
        int    def;   //Base Defense
        int    spd;   //Base Speed
        string name;  //Monster Name
        char   type;  //Monster Elemental Type
    };
    
    //Declare Arrays
    int  map[LENGTH][WIDTH];    //Array that holds room type on map
    char roomTp[5][LENGTH][WIDTH];
    
    //Declare Variables
    int room=5;
    string file="maps.dat";
    
    //Display map
    dispMap(map);
    
    //fillFloor(roomTp,room,file);
    
    //Exit program
    return 0;
}

void fillFloor(char roomTp[][LENGTH][WIDTH],int room,string file){
    fstream read;
    read.open(file);
    
    for(int i=0;i<room;i++){
        for(int j=0;j<LENGTH;j++){
            for(int k=0;k<WIDTH;k++){
                read>>roomTp[i][j][k];
                //read>>' ';
                //if(k%5==4)read>>endl;
            }
            //if(j%5==4)read>>endl;
        }
    }
    read.close();
}

void dispMap(int map[LENGTH][WIDTH]){
    int floor=0;
    for(int i=0;i<LENGTH;i++){
        for(int j=0;j<WIDTH;j++){
            cout<<"| "<<' '<<" |";
            if(j%5==4)cout<<endl;     
        }
        for(int j=0;j<WIDTH;j++){
            cout<<' '<<"---"<<' ';
            if(j%5==4)cout<<endl;
        }
    }
}