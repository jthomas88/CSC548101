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

void updtFloor(char[][LENGTH][WIDTH],bool[LENGTH][WIDTH],bool[LENGTH][WIDTH],int);

//Bool Functions
void ifVisit(char[][LENGTH][WIDTH],bool[LENGTH][WIDTH],bool[LENGTH][WIDTH],int);
void ifInsid(char[][LENGTH][WIDTH],bool[LENGTH][WIDTH],bool[LENGTH][WIDTH],int);

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
    bool visitd[LENGTH][WIDTH]={};
    bool inside[LENGTH][WIDTH]={};
    
    //Declare Variables
    char   movDir;
    int    room=5;
    int    curRoom=0;
    string file="maps.dat";
    
    /*
    //Fill in map data from file
    fillFloor(roomTp,room,file);
    
    
    //Display Map (W/O Bools)
    dispMap(map,roomTp,curRoom);
    cout<<endl;
    
    //Update ifVisit
    ifVisit(roomTp,visitd,inside,curRoom);
    
    //Output ifVisit
    for(int i=0;i<LENGTH;i++){
        for(int j=0;j<WIDTH;j++){
            cout<<visitd[i][j]<<' ';
            if(j%5==4)cout<<endl;
        }
    }
    cout<<endl;
    
    //Update ifInsid
    ifInsid(roomTp,visitd,inside,curRoom);
    
    //Output ifInsid
    for(int i=0;i<LENGTH;i++){
        for(int j=0;j<WIDTH;j++){
            cout<<inside[i][j]<<' ';
            if(j%5==4)cout<<endl;
        }
    }
    cout<<endl;
    
    //Update Map
    updtFloor(roomTp,visitd,inside,curRoom);
    
    //Display Map (W/ Bools)
    dispMap(map,roomTp,curRoom);
    cout<<endl;
    
    //Spawn Character
    cout<<"CHARACTER SPAWNED HERE AT [4][2]"<<endl;
    inside[4][2]=0;
    
    //Update Map after spawn
    updtFloor(roomTp,visitd,inside,curRoom);
    
    //Display Map after spawn
    dispMap(map,roomTp,curRoom);
    cout<<endl;
    */
    
    
    
    for(int floor=0;floor<room;floor++){
        //Fill in map data from file
        fillFloor(roomTp,room,file);
        
        //Update ifVisit
        ifVisit(roomTp,visitd,inside,floor);
        
        //Update ifInsid
        ifInsid(roomTp,visitd,inside,floor);
        
        //Update Map
        updtFloor(roomTp,visitd,inside,floor);
        
        //Display Map
        //dispMap(map,roomTp,curRoom);
        cout<<endl;
        
        //Spawn Character
        for(int i=0;i<floor+2;i++){
            for(int j=0;j<LENGTH;j++){
                for(int k=0;k<WIDTH;k++){
                    if(roomTp[i][j][k]=='H'){
                        inside[j][k]=0;
                        cout<<j<<' '<<k;
                        cout<<endl<<endl;
                    }
                }
            }
        }
        
        //Update Map
        updtFloor(roomTp,visitd,inside,floor);
        
        //Display Map
        dispMap(map,roomTp,curRoom);
        cout<<endl;
        
        //Move Character
        do{
            cin>>movDir;
            switch(movDir){
                case 'w':
                    for(int i=0;i<LENGTH;i++){
                        for(int j=0;j<WIDTH;j++){      
                            if(inside[i][j]==0){                         
                                inside[i][j]=1;
                                inside[i-1][j]=0;
                                visitd[i][j]=0;

                                if(roomTp[floor][i-1][j]=='X'){
                                    cout<<"There seems to be a wall in the way...";
                                    cout<<endl;
                                    inside[i-1][j]=1;
                                    inside[i+1][j]=0;
                                    visitd[i+1][j]=1;
                                }
                            }
                        }
                    }
                //Check ifInsid
                for(int i=0;i<LENGTH;i++){
                    for(int j=0;j<WIDTH;j++){
                        cout<<inside[i][j]<<' ';
                        if(j%5==4)cout<<endl;
                    }
                }
                cout<<endl;

                //Check ifInsid
                for(int i=0;i<LENGTH;i++){
                    for(int j=0;j<WIDTH;j++){
                        cout<<visitd[i][j]<<' ';
                        if(j%5==4)cout<<endl;
                    }
                }
                cout<<endl;

                //Return Original Symbols
                fillFloor(roomTp,room,file);    

                //Update Map after move
                updtFloor(roomTp,visitd,inside,floor);

                //Display Map after move
                dispMap(map,roomTp,floor);
                cout<<endl;
                break;

                case 's':
                    for(int i=LENGTH-1;i>0;i--){
                        for(int j=WIDTH-1;j>0;j--){      
                            if(inside[i][j]==0){  
                                inside[i][j]=1;
                                inside[i+1][j]=0;
                                //inside[i+1][j]=0;
                                visitd[i][j]=0;
                                if(roomTp[floor][i+1][j]=='X'){
                                    cout<<"There seems to be a wall in the way...";
                                    cout<<endl;
                                    inside[i][j]=1;
                                    inside[i+1][j]=1;
                                    inside[i-1][j]=0;
                                }
                            }
                        }
                    }
                //Check ifInsid
                for(int i=0;i<LENGTH;i++){
                    for(int j=0;j<WIDTH;j++){
                        cout<<inside[i][j]<<' ';
                        if(j%5==4)cout<<endl;
                    }
                }
                cout<<endl;

                //Check ifInsid
                for(int i=0;i<LENGTH;i++){
                    for(int j=0;j<WIDTH;j++){
                        cout<<visitd[i][j]<<' ';
                        if(j%5==4)cout<<endl;
                    }
                }
                cout<<endl;

                //Return Original Symbols
                fillFloor(roomTp,room,file);    

                //Update Map after move
                updtFloor(roomTp,visitd,inside,floor);

                //Display Map after move
                dispMap(map,roomTp,floor);
                cout<<endl;
                break;

                case 'a':
                    for(int i=0;i<LENGTH;i++){
                        for(int j=0;j<WIDTH;j++){      
                            if(inside[i][j]==0){                         
                                inside[i][j]=1;
                                inside[i][j-1]=0;
                                visitd[i][j]=0;

                                if(roomTp[floor][i][j-1]=='X'){
                                    cout<<"There seems to be a wall in the way...";
                                    cout<<endl;
                                    inside[i][j-1]=1;
                                    inside[i][j+1]=0;
                                    visitd[i][j+1]=1;
                                }
                            }
                        }
                    }
                //Check ifInsid
                for(int i=0;i<LENGTH;i++){
                    for(int j=0;j<WIDTH;j++){
                        cout<<inside[i][j]<<' ';
                        if(j%5==4)cout<<endl;
                    }
                }
                cout<<endl;

                //Check ifInsid
                for(int i=0;i<LENGTH;i++){
                    for(int j=0;j<WIDTH;j++){
                        cout<<visitd[i][j]<<' ';
                        if(j%5==4)cout<<endl;
                    }
                }
                cout<<endl;

                //Return Original Symbols
                fillFloor(roomTp,room,file);    

                //Update Map after move
                updtFloor(roomTp,visitd,inside,floor);

                //Display Map after move
                dispMap(map,roomTp,floor);
                cout<<endl;
                break;

                case 'd':
                    for(int i=LENGTH-1;i>0;i--){
                        for(int j=WIDTH-1;j>0;j--){      
                            if(inside[i][j]==0){  
                                inside[i][j]=1;
                                inside[i][j+1]=0;
                                visitd[i][j]=0;
                                if(roomTp[floor][i][j+1]=='X'){
                                    cout<<"There seems to be a wall in the way...";
                                    cout<<endl;
                                    inside[i][j]=1;
                                    inside[i][j+1]=1;
                                    inside[i][j-1]=0;
                                    visitd[i][j]=1;
                                }
                            }
                        }
                    }
                //Check ifInsid
                for(int i=0;i<LENGTH;i++){
                    for(int j=0;j<WIDTH;j++){
                        cout<<inside[i][j]<<' ';
                        if(j%5==4)cout<<endl;
                    }
                }
                cout<<endl;

                //Check ifInsid
                for(int i=0;i<LENGTH;i++){
                    for(int j=0;j<WIDTH;j++){
                        cout<<visitd[i][j]<<' ';
                        if(j%5==4)cout<<endl;
                    }
                }
                cout<<endl;

                //Return Original Symbols
                fillFloor(roomTp,room,file);    

                //Update Map after move
                updtFloor(roomTp,visitd,inside,floor);

                //Display Map after move
                dispMap(map,roomTp,floor);
                cout<<endl;
                break;
            }
        }while(inside[0][4]==1);
    }
    //Exit program
    return 0;
}
//Floor Layout Manipulators
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

void updtFloor(char roomTp[][LENGTH][WIDTH],bool visited[LENGTH][WIDTH],
               bool inside[LENGTH][WIDTH],int floor){
    for(int i=0;i<LENGTH;i++){
        for(int j=0;j<WIDTH;j++){
            if(inside[i][j]==0){
                roomTp[floor][i][j]='O';
            }
            else if(visited[i][j]==0&&inside[i][j]==1){
                roomTp[floor][i][j]=roomTp[floor][i][j];
            }         
            else if(visited[i][j]==1&&inside[i][j]==1){
                roomTp[floor][i][j]='?';
            }
            
        }
    }
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

//Outline of map
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

//Bool Array Manipulators
void ifVisit(char roomTp[][LENGTH][WIDTH],bool visited[LENGTH][WIDTH],
               bool inside[LENGTH][WIDTH],int floor){
    for(int i=0;i<LENGTH;i++){
        for(int j=0;j<WIDTH;j++){
            roomTp[floor][i][j]=='X'||roomTp[floor][i][j]=='O'
                ?visited[i][j]=0:visited[i][j]=1;
        }
    }
}

void ifInsid(char roomTp[][LENGTH][WIDTH],bool visited[LENGTH][WIDTH],
               bool inside[LENGTH][WIDTH],int floor){
    for(int i=0;i<LENGTH;i++){
        for(int j=0;j<WIDTH;j++){
            roomTp[floor][i][j]=='O'
                ?inside[i][j]=0:inside[i][j]=1;
        }
    }
}