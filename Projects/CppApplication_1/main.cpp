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
void dispMap(int [LENGTH][WIDTH],char[][LENGTH][WIDTH],int);

void fillFloor(char[][LENGTH][WIDTH],int,string);

void dispFloor(char[][LENGTH][WIDTH],int);

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
    
    //Location checks
    bool visitd[LENGTH][WIDTH];
    bool inside[LENGTH][WIDTH];
    
    //Declare Variables
    int room=5;
    int curRoom=0;
    string file="maps.dat";
    
    //Fill in map data from file
    fillFloor(roomTp,room,file);
    
    //Check if map data was read in correctly
    //dispFloor(roomTp,room);
    
    //Display Map
    dispMap(map,roomTp,curRoom);
    
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
                //if(k%5==4)cout<<endl;
            }
            //if(j%5==4)cout<<endl;
        }
    }
    read.close();
}

void dispFloor(char roomTp[][LENGTH][WIDTH],int room){
    for(int i=0;i<room;i++){
        for(int j=0;j<LENGTH;j++){
            for(int k=0;k<WIDTH;k++){
                cout<<roomTp[i][j][k]<<' ';
                if(k%5==4)cout<<endl;
            }
            if(j%5==4)cout<<endl;
        }
    }
}

void dispMap(int map[LENGTH][WIDTH],char roomTp[][LENGTH][WIDTH],int floor){
    for(int i=0;i<LENGTH;i++){
        for(int j=0;j<WIDTH;j++){
            
            cout<<"| "<<roomTp[floor][i][j]<<" |";
            
            if(j%5==4)cout<<endl;     
        }
        for(int j=0;j<WIDTH;j++){
            cout<<' '<<"---"<<' ';
            if(j%5==4)cout<<endl;
        }
    }
}