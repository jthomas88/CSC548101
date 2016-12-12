/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on December 3, 2016, 12:36 AM
 * Purpose: Project 2
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <fstream>   //File I/O
#include <string>    //String Manipulation
#include <ctime>     //Random Seed
#include <cstdlib>   //Random Generator
using namespace std; //Namespace used in system library

//User Libraries
#include "Monster.h"

//Global constants
int const LENGTH=5;  //Length of 3D array representing dungeon
int const WIDTH=5;   //Width of 3D array representing dungeon


//Function prototypes
//Print Functions
    //Prints floor map to screen
    void dispMap(char[][LENGTH][WIDTH],int);
    //Outputs title of game
    void dispTtl(string);
//Floor Functions
    //Fills floor array with original values before 'O' & '?' are added
    void fillFloor(char[][LENGTH][WIDTH],int,string);
    //Updates floor array with 'O' & '?' added
    void updtFloor(char[][LENGTH][WIDTH],bool[LENGTH][WIDTH],bool[LENGTH][WIDTH],int);
//Bool Functions
    //Initializes visitd array with correct values
    void ifVisit(char[][LENGTH][WIDTH],bool[LENGTH][WIDTH],int);
    //Initializes inside array with correct values and updates current location
    void ifInsid(char[][LENGTH][WIDTH],bool[LENGTH][WIDTH],int);
//Search Functions
    //Searches for x,y position of 'B' on floor array
    void findB(char[][LENGTH][WIDTH],int,int&,int&);
//Generate Functions
    //Levels up GF
    void lvlUp(Monster&);
    //Generate Monster function
    void gnratGf(Monster&,string[],char[]);
    //Generate Enemy function
    void gnratEn(Monster&,string[],int);
//Battle Functions
    //Simulates battle with boss
    int bsBattl(Monster&,Monster[],int,char&,int&);
    //Simulates battle with lesser enemy
    int enBattl(Monster&,Monster&,string[],int,char&,int&);
//File Manipulation Functions
    //Writes data to external file which can be accessed upon startup
    void save(bool[][WIDTH],bool,Monster&,int,string);
    //Reads data from external file upon startup
    void load(bool[][WIDTH],bool,Monster&,int&,string);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize Random Seed
    srand(time(0));   
    
    //Declare Arrays
    char roomTp[5][LENGTH][WIDTH];
    
    //Location checks
    bool visitd[LENGTH][WIDTH]={};
    bool inside[LENGTH][WIDTH]={};
    bool used[LENGTH][WIDTH]={};
    
    //Boss Monsters
    Monster boss[5];
    
    //Initialize Bosses
    
    //Initialize LILIM
    boss[0].hpt=20;
    boss[0].chp=boss[0].hpt;
    boss[0].atk=8;
    boss[0].def=12;
    boss[0].spd=12;
    boss[0].name="L.I.L.I.M.";
    boss[0].flvr="A wretched mutant GMO with small wings. She is the leader of "
            "the lesser monsters of Floor B1";
    
    //Initialize ISHTAR
    boss[1].hpt=40;
    boss[1].chp=boss[1].hpt;
    boss[1].atk=20;
    boss[1].def=12;
    boss[1].spd=18;
    boss[1].name="I.S.H.T.A.R.";
    boss[1].flvr="A reptilian GMO whose fangs can kill instantly. She is the "
            "leader of the lesser monsters of Floor B2";
    
    //Initialize FREYA
    boss[2].hpt=60;
    boss[2].chp=boss[2].hpt;
    boss[2].atk=30;
    boss[2].def=30;
    boss[2].spd=30;
    boss[2].name="F.R.E.Y.A.";
    boss[2].flvr="A massive GMO with skin made of steel. She is the leader of "
            "the lesser monsters of Floor B3";
    
    //Initialize EROS
    boss[3].hpt=80;
    boss[3].chp=boss[3].hpt;
    boss[3].atk=42;
    boss[3].def=35;
    boss[3].spd=65;
    boss[3].name="E.R.O.S.";
    boss[3].flvr="A vile GMO with large pores endlessly leaking. She is the "
            "leader of the lesser monsters of Floor B4";
    
    //Initialize APHRODITE
    boss[4].hpt=100;
    boss[4].chp=boss[4].hpt;
    boss[4].atk=65;
    boss[4].def=50;
    boss[4].spd=80;
    boss[4].name="A.P.H.R.O.D.I.T.E.";
    boss[4].flvr="Queen of the mutant nest that's formed in the depths of the "
            "abandoned research facility. Because she's attached to the walls, "
            "she sends scavengers to collect food.";
    
    //GF Name Prefixes
    string syllabl[18]={"LAC","KAM","FAN","KAR","PIP","LOR","DOR","ANN","TOR",
                        "MAR","DAN","LEX","RUB","LIL","KIK","VIK","HID","ARR"};
    
    //GF "version numbers" (for naming)
    char   numCh[]={'0','1','2','3','4','5','6','7','8','9'};
    
    //Enemy Names
    string enNames[5] ={"Mutant GF","Wandering Security Drone","Giant Rat",
                        "Daughter of Aphrodite","GF Ghost"};
    
    //Declare Variables         
    char   movDir;          //Direction player chooses to move
    char   choice;          //Choice input for various prompts
    
    int    outcome;         //Determines battle outcome branch
    int    floor;           //The current floor of the dungeon  
    int    room=5;          //Number of floors in the dungeon      
    int    bosPosX,bosPosY; //Boss location on grid
    int    curPosX,curPosY; //Player's location on grid
    
    bool   intro;           //Holds whether player has completed intro or not
    bool   isLoad;          //Holds whether player has already loaded game
    
    string maps="maps.dat";  //Holds file name for map data
    string data="data.dat";  //Holds file name for save data
    string titl="title.dat"; //Holds file name for game title ASCII art
    
    Monster gf1;             //Player's GF
    Monster en;              //Lesser enemies
    
    //Output Title
    dispTtl(titl);
    
    //Prompt user to select an option
    cout<<"1. New Game"<<endl;
    cout<<"2. Load Game"<<endl;
    do{
        cin>>choice;      //Select an option
        cin.ignore();     //Allows cin.get() to work correctly
        switch(choice){  
            case 49:      //49 is ASCII value of '1'
                floor=0;  //Set floor to 0
                intro=1;  //Indicate introduction has not been completed
                isLoad=1; //Indicate save file was not loaded
                break;
            case 50:
                cout<<endl;
                //Load File
                load(visitd,intro,gf1,floor,data);
                isLoad=0; //Indicate save file was loaded
                break;
            default:
                //Output invalid input statement
                cout<<"INVALID INPUT"<<endl<<endl;
                break;
        }
    }while(choice>50||choice<49); //Check to make sure input is valid
 
    if(intro==1){ //Check if introduction has already been done
        //Introduction
        cout<<endl;
        cout<<"Hello! Welcome to GMO (Girlfriends Made to Order)!"<<endl<<endl;
        cout<<"I'm the lead researcher here. I'd like to thank you for agreeing "
            <<endl<<"to participate in our beta testing. We take it upon ourselves"
            <<endl<<"to provide a much needed service for people like you and I. "
            <<endl<<"We're great guys who just can't seem to get a gf no matter how"
            <<endl<<"hard we try! Let's take a quick tour of the facility and then"
            <<endl<<"we can let you start the testing process!";    
        cout<<endl<<endl;
        
        cout<<"Press ENTER to continue";
        cin.get();  //Wait for user to press enter
        cout<<endl;
        
        cout<<"(You're led to a room with a huge glass chamber inside)"<<endl<<endl;
        cout<<"This is our GMOGen Girlfriend Generator, or GMOGGG. This is what we"
            <<endl<<"will utilize for this beta test. Go ahead and press that big"
            <<endl<<"button in the middle of the console.";
        cout<<endl<<endl;
        cout<<"Press ENTER to start the beta test";
        cin.get();  //Wait for user to press enter
        cout<<endl;

        cout<<"(The machine emits a puff of smoke and a figure appears)"<<endl;
        //Randomly generate party member
        gnratGf(gf1,syllabl,numCh);
        //Display generated party member
        cout<<"You have created: "<<gf1.name<<endl; //Name
        cout<<"Vitality : "<<gf1.hpt<<endl;         //Max Health
        cout<<"Strength : "<<gf1.atk<<endl;         //Attack
        cout<<"Toughness: "<<gf1.def<<endl;         //Defense
        cout<<"Agility  : "<<gf1.spd<<endl;         //Speed
        //Prompt user for response
        cout<<"Will you keep this one? ('y' to keep or 'n' to try again)";
        cout<<endl;
        
        do{
            cin>>choice;  //Input choice
            cin.ignore(); //Allows cin.get() to work correctly
            cout<<endl;
            switch(choice){
                case 'y': //If Yes
                    //Notify that party member has been added
                    cout<<gf1.name<<" has been added to your party!";
                    cout<<endl<<endl;
                    break;
                case 'n': //If no
                    //Notify that another GF will be created
                    cout<<gf1.name<<" is sent into a room labeled 'INCINERATOR'";
                    cout<<endl<<endl;
                    
                    //Randomly generate another GF
                    cout<<"(The machine emits a puff of smoke and a figure appears)"<<endl;
                    gnratGf(gf1,syllabl,numCh);
                    cout<<"You have created: "<<gf1.name<<endl;
                    cout<<"Vitality : "<<gf1.hpt<<endl;
                    cout<<"Strength : "<<gf1.atk<<endl;
                    cout<<"Toughness: "<<gf1.def<<endl;
                    cout<<"Agility  : "<<gf1.spd<<endl;
                    cout<<"Will you keep this one? ('y' to keep or 'n' to try again)";
                    cout<<endl;
                    break;
                default: //If input is invalid
                    cout<<"INVALID INPUT";
                    cout<<endl<<endl;
            }
        }while(choice!='y'); //Reiterate until player is satisfied
        
        //More plot
        cout<<"(The lights shut off and loud sirens begin to blare)";

        cout<<endl<<endl;

        cout<<"RED ALERT. RED ALERT. APHRODITE HAS AWOKEN. SHUT DOWN COMMENCING.";

        cout<<endl<<endl;

        cout<<"(You're confused by the sudden alert but you know that whatever it"
            <<endl<<"is can't possibly be good. All of the exits are closing one"
            <<endl<<"by one. Your tour guide has abandoned you. You must find a "
            <<endl<<"way out before it's too late. You see an elevator that hasn't"
            <<endl<<"been shut yet.)";

        cout<<endl<<endl;
        cout<<"Press ENTER to run";
        cin.get();  //Wait for user to press enter
        cout<<endl;

        cout<<"(You make it into the elevator right before it closes. Your GMO"
            <<endl<<"seems to have followed you as well. You look at the elevator"
            <<endl<<"panel and notice it only has one button. You have no idea"
            <<endl<<"where it will go but you seem to have no choice now.)";

        cout<<endl<<endl;

        cout<<"Press ENTER to press the elevator button";
        cin.get();  //Wait for user to press enter
        cout<<endl;

        cout<<"(You arrive to a dark corridor. The sign on the wall says \"B1\")";

        cout<<endl<<endl;
        intro=0;    //Indicate that introduction has been completed
    }
    
    //Game Start
    for(floor;floor<room;++floor){ //Loop repeats for number of floors
        //Output Current Floor
        cout<<"Floor: B"<<floor+1<<endl;
        
        //If new game, load default data
        if(isLoad==1){
            //Fill in map data from file
            fillFloor(roomTp,room,maps);     

            //Update ifVisit
            ifVisit(roomTp,visitd,floor);

            //Update ifInsid
            ifInsid(roomTp,inside,floor);
            
            //Find boss tile and assign coordinates
            findB(roomTp,floor,bosPosX,bosPosY);

            //Spawn player at Hub
            for(int j=0;j<LENGTH;j++){
                for(int k=0;k<WIDTH;k++){
                    if(roomTp[floor][j][k]=='H'){
                        inside[j][k]=0;
                        visitd[j][k]=0;
                    }
                }
            }

            //Update floor map with correct symbols
            updtFloor(roomTp,visitd,inside,floor);

            //Display floor map
            dispMap(roomTp,floor);
            cout<<endl;

            //Initialize/Reset rooms to be unused
            for(int i=0;i<LENGTH;i++){
                for(int j=0;j<WIDTH;j++){
                    used[i][j]=1;
                }
            }
        }
        
        //If load game, initialize loaded data
        if(isLoad==0){
            //Fill floor map with file data
            fillFloor(roomTp,room,maps);
            
            //Set all visited rooms to 'used'
            for(int i=0;i<LENGTH;i++){
                for(int j=0;j<WIDTH;j++){
                    used[i][j]=visitd[i][j];
                }
            }
            
            //Update ifInsid
            ifInsid(roomTp,inside,floor);
            
            //Find boss tile and assign coordinates
            findB(roomTp,floor,bosPosX,bosPosY);

            //Spawn player at Hub
            for(int j=0;j<LENGTH;j++){
                for(int k=0;k<WIDTH;k++){
                    if(roomTp[floor][j][k]=='H'){
                        inside[j][k]=0;
                        visitd[j][k]=0;
                        used[j][k]=1;
                    }
                }
            }
            
            //Update Map
            updtFloor(roomTp,visitd,inside,floor);

            //Display Map
            dispMap(roomTp,floor);
            cout<<endl;
            isLoad=1;   //Change flag to allow game to be loaded again
        }                
        
        //Display Hub Options
        do{
            cout<<"This room appears to still have working "
                <<"equipment inside. What would you like to do?";
            cout<<endl;
            //Prompt user for input
            cout<<"1. Save Game"<<endl;
            cout<<"2. Rest"<<endl;
            cout<<"3. Leave Hub"<<endl;
            cout<<"4. Quit Game"<<endl;
            cin>>choice; //Input choice
            cout<<endl;
            switch(choice){
                case 49: //If choice is 1
                    //Update data on floor map
                    updtFloor(roomTp,visitd,inside,floor);
                    //Display floor map
                    dispMap(roomTp,floor);
                    cout<<endl;    
                    //Save Game
                    save(visitd,intro,gf1,floor,data);
                    //Affirm that game has been successfully saved
                    cout<<"GAME SAVED";
                    cout<<endl<<endl;
                    break;
                case 50: //If choice is 2
                    //Update data on floor map
                    updtFloor(roomTp,visitd,inside,floor);
                    //Display floor map
                    dispMap(roomTp,floor);
                    cout<<endl;
                    //Set maximum health to current health
                    gf1.chp=gf1.hpt;
                    //Affirm that GF has been healed
                    cout<<gf1.name<<" has been fully healed.";
                    cout<<endl<<endl;
                    break;
                case 51: //If choice is 3
                    //Update data on floor map
                    updtFloor(roomTp,visitd,inside,floor);
                    //Display floor map
                    dispMap(roomTp,floor);
                    cout<<endl;
                    break;
                case 52: //If choice is 4
                    return 0; //End Program
                    break;
                default: //If choice is invalid
                    cout<<"INVALID INPUT"; //Output invalid statment
                    cout<<endl<<endl;
            }
        }while(choice!=51); //Reiterate until player leaves
                     
        //Move Character
        do{
            //Display controls
            cout<<"CONTROLS"<<endl;
            cout<<"'w' = Move forward"<<endl;
            cout<<"'s' = Move backward"<<endl;
            cout<<"'a' = Move left"<<endl;
            cout<<"'d' = Move right"<<endl;
            cout<<"Press ENTER after you input your movement.";
            cout<<endl<<endl;
            cin>>movDir; //Player input
            switch(movDir){
                case 'w': //If player moves forward
                    cout<<endl;
                    //Search for player's current location
                    for(int i=0;i<LENGTH;i++){
                        for(int j=0;j<WIDTH;j++){      
                            if(inside[i][j]==0){                         
                                inside[i][j]=1;  //Set current location to empty
                                inside[i-1][j]=0;//Set location +1 y to filled
                                visitd[i-1][j]=0;//Set location +1 y to visited
                                
                                curPosX=j;       //Set x coordinate of player
                                curPosY=i-1;     //Set y coordinate of player
                                
                                //Check for walls or edges
                                if(i==0||roomTp[floor][i-1][j]=='X'){
                                    //Output failure message
                                    cout<<"There seems to be a wall in the way...";
                                    cout<<endl;
                                    //Set all changed variables back to previous
                                    inside[i][j]=1;
                                    inside[i-1][j]=1;
                                    inside[i+1][j]=0;
                                    visitd[i][j]=1;
                                }
                            }
                        }
                    }
                //Return Original Symbols
                fillFloor(roomTp,room,maps);    

                //Update Map after move
                updtFloor(roomTp,visitd,inside,floor);

                //Display Map after move
                dispMap(roomTp,floor);
                break;

                case 's': //If player moves backward
                    cout<<endl;
                    //Search for player's current location
                    for(int i=LENGTH-1;i>=0;i--){
                        for(int j=WIDTH-1;j>=0;j--){      
                            if(inside[i][j]==0){  
                                inside[i][j]=1;  //Set current location to empty
                                inside[i+1][j]=0;//Set location -1 y to filled
                                visitd[i+1][j]=0;//Set location -1 y to visited
                                
                                curPosX=j;       //Set x coordinate of player
                                curPosY=i+1;     //Set y coordinate of player
                                
                                //Check for walls or edges
                                if(i==4||roomTp[floor][i+1][j]=='X'){
                                    //Output failure message
                                    cout<<"There seems to be a wall in the way...";
                                    cout<<endl;
                                    //Set all changed variables back to previous
                                    inside[i][j]=1;
                                    inside[i+1][j]=1;
                                    inside[i-1][j]=0;
                                    visitd[i][j]=1;
                                }
                            }
                        }
                    }
                //Return Original Symbols
                fillFloor(roomTp,room,maps);    

                //Update Map after move
                updtFloor(roomTp,visitd,inside,floor);

                //Display Map after move
                dispMap(roomTp,floor);
                break;

                case 'a': //If player moves left
                    cout<<endl;
                    //Search for player's current location
                    for(int i=0;i<LENGTH;i++){
                        for(int j=0;j<WIDTH;j++){      
                            if(inside[i][j]==0){                         
                                inside[i][j]=1;  //Set current location to empty
                                inside[i][j-1]=0;//Set location -1 x to filled
                                visitd[i][j-1]=0;//Set location -1 x to visited
                                
                                curPosX=j-1;     //Set x coordinate of player
                                curPosY=i;       //Set y coordinate of player

                                //Check for walls or edges
                                if(j==0||roomTp[floor][i][j-1]=='X'){
                                    //Output failure message
                                    cout<<"There seems to be a wall in the way...";
                                    cout<<endl;
                                    //Set all changed variables back to previous
                                    inside[i][j]=1;
                                    inside[i][j-1]=1;
                                    inside[i][j+1]=0;
                                    visitd[i][j]=1;
                                }
                            }
                        }
                    }
                //Return Original Symbols
                fillFloor(roomTp,room,maps);    

                //Update Map after move
                updtFloor(roomTp,visitd,inside,floor);

                //Display Map after move
                dispMap(roomTp,floor);

                break;

                case 'd': //If player moves right
                    cout<<endl;
                    //Search for player's current location
                    for(int i=LENGTH-1;i>=0;i--){
                        for(int j=WIDTH-1;j>=0;j--){      
                            if(inside[i][j]==0){  
                                inside[i][j]=1;  //Set current location to empty
                                inside[i][j+1]=0;//Set location -1 x to filled
                                visitd[i][j+1]=0;//Set location -1 x to visited
                                
                                curPosX=j+1;     //Set x coordinate of player
                                curPosY=i;       //Set y coordinate of player
                                
                                //Check for walls or edges
                                if(roomTp[floor][i][j+1]=='X'){
                                    //Output failure message
                                    cout<<"There seems to be a wall in the way...";
                                    cout<<endl;
                                    //Set all changed variables back to previous
                                    inside[i][j]=1;
                                    inside[i][j+1]=1;
                                    inside[i][j-1]=0;
                                    visitd[i][j]=1;
                                }
                            }
                        }
                    }
                //Return Original Symbols
                fillFloor(roomTp,room,maps);    

                //Update Map after move
                updtFloor(roomTp,visitd,inside,floor);

                //Display Map after move
                dispMap(roomTp,floor);
                break;
            }
            cout<<endl;
            
            //Apply effect of tile player is on
            if(inside[curPosY][curPosX]==0&&used[curPosY][curPosX]==1){  
                //Fill floor with original data
                fillFloor(roomTp,room,maps);
                //Declare XP gain variable
                int xpGainz=(rand()%15+1*(floor+1)); //Gives 1-15 xp*floor factor
                switch(roomTp[floor][curPosY][curPosX]){
                    case 'E': //If player is on enemy tile
                        //Start battle
                        enBattl(gf1,en,enNames,floor,choice,outcome);
                        if(outcome==1){ //If player loses battle and wants to load
                            //Load previous state
                            load(visitd,intro,gf1,floor,data);
                            //Fill floor with original map data
                            fillFloor(roomTp,room,maps);
                            //Set all previously visited rooms to used
                            for(int i=0;i<LENGTH;i++){
                                for(int j=0;j<WIDTH;j++){
                                    used[i][j]=visitd[i][j];
                                }
                            }
                            //Update ifInsid
                            ifInsid(roomTp,inside,floor);
                            //Find boss and assign coordinates
                            findB(roomTp,floor,bosPosX,bosPosY);                       
                            //Spawn player at Hub
                            for(int j=0;j<LENGTH;j++){
                                for(int k=0;k<WIDTH;k++){
                                    if(roomTp[floor][j][k]=='H'){
                                        inside[j][k]=0;
                                        visitd[j][k]=0;
                                        used[j][k]=1;
                                    }
                                }
                            }
                            //Update Map
                            updtFloor(roomTp,visitd,inside,floor);
                            //Display Map
                            dispMap(roomTp,floor);
                            cout<<endl;
                            isLoad=1;
                        }
                        if(outcome==2){ //If player loses and wants to quit game
                            return 0;
                        }
                        if(outcome==3){ //If player wins battle
                            //Output amount of XP gained
                            cout<<gf1.name<<" gained "<<xpGainz<<" EXP";
                            cout<<endl<<endl;
                            //Add XP to total
                            gf1.cxp+=xpGainz;
                            //Call level up function
                            lvlUp(gf1);
                            cout<<endl;
                            //Output XP status
                            cout<<"Max XP              : "<<gf1.mxp<<endl; 
                            cout<<"Current amount of XP: "<<gf1.cxp<<endl;
                            cout<<"XP Needed to lvl up : "<<gf1.mxp-gf1.cxp;
                            cout<<endl<<endl;
                            //Update Map
                            updtFloor(roomTp,visitd,inside,floor);
                            //Display Map
                            dispMap(roomTp,floor);
                            cout<<endl;
                            used[curPosY][curPosX]=0; //Set tile to used
                        }                       
                        break;
                        
                    case 'T': //If player is on treasure tile
                        switch(rand()%3){ //Randomly select prize for player
                            case 0: //Prize 1: Some peace and quiet
                                cout<<"You scour the room and find nothing of "
                                    <<"value. However, not having to"
                                    <<endl<<"fight one of those abominations is "
                                    <<"a treasure in itself.";
                                cout<<endl;
                                used[curPosY][curPosX]=0; //Set tile to used
                                break;
                            case 1: //Prize 2: Restore health
                                cout<<"You find some snack mix in a "
                                    <<"scientist's office. You're not very "
                                    <<endl<<"hungry but "<<gf1.name<<" gladly "
                                    <<"eats it.";
                                cout<<endl<<endl;
                                //Set current HP to maximum HP
                                gf1.chp=gf1.hpt;
                                //Affirm that health has been restored
                                cout<<gf1.name<<" has been fully healed!";
                                cout<<endl;
                                used[curPosY][curPosX]=0; //Set tile to used
                                break;
                            case 2: //Prize 3: Level Up
                                cout<<"You find some strange pills in a lockbox. "
                                    <<gf1.name<<" consumes them"
                                    <<endl<<"and starts to glow with newfound "
                                    <<"energy.";
                                cout<<endl<<endl;
                                //Fill XP meter
                                gf1.cxp=gf1.mxp;
                                //Call level up function
                                lvlUp(gf1);
                                used[curPosY][curPosX]=0; //Set tile to used                                
                                cout<<endl;
                                //Update Map
                                updtFloor(roomTp,visitd,inside,floor);
                                //Display Map
                                dispMap(roomTp,floor);
                                cout<<endl;                                
                                break;
                        }
                        break;
                        
                    case 'H': //If player is on Hub tile
                        do{
                            cout<<"This room appears to still have working "
                                <<"equipment inside. What would you like to do?";
                            cout<<endl;
                            //Prompt user for input
                            cout<<"1. Save Game"<<endl;
                            cout<<"2. Rest"<<endl;
                            cout<<"3. Leave Hub"<<endl;
                            cout<<"4. Quit Game"<<endl;
                            cin>>choice; //Input choice
                            switch(choice){
                                case 49: //If player chooses to save
                                    //Save Game
                                    save(visitd,intro,gf1,floor,data);
                                    //Affirm game has been saved
                                    cout<<"GAME SAVED"<<endl;
                                    break;
                                case 50: //If player chooses to rest
                                    //Set current HP to maximum HP
                                    gf1.chp=gf1.hpt;
                                    //Affirm health has been restored
                                    cout<<gf1.name<<" has been fully healed.";
                                    cout<<endl;
                                    break;
                                case 51: //If player chooses to leave Hub
                                    //Update floor map
                                    updtFloor(roomTp,visitd,inside,floor);
                                    //Display floor map
                                    dispMap(roomTp,floor);
                                    break;
                                case 52: //If player chooses to quit game
                                    //Exit Program
                                    return 0;
                                    break;
                                default: //If player input is invalid
                                    //Output failure statement
                                    cout<<"INVALID INPUT";
                                    cout<<endl<<endl;
                                    break;
                            }
                        }while(choice!=51); //Reiterate until player leaves Hub
                        break;
                    case 'B': //If player lands on boss tile
                        //Initiate boss battle
                        bsBattl(gf1,boss,floor,choice,outcome);
                        if(outcome==1){ //If user loses battle and wants to load
                            //Load Game
                            load(visitd,intro,gf1,floor,data);
                            //Fill floor map with file data
                            fillFloor(roomTp,room,maps);
                            //Set all previously visited tiles to used
                            for(int i=0;i<LENGTH;i++){
                                for(int j=0;j<WIDTH;j++){
                                    used[i][j]=visitd[i][j];
                                }
                            }
                            //Update ifInsid
                            ifInsid(roomTp,inside,floor);
                            //Find boss and assign coordinates
                            findB(roomTp,floor,bosPosX,bosPosY);
                            //Spawn player at Hub
                            for(int j=0;j<LENGTH;j++){
                                for(int k=0;k<WIDTH;k++){
                                    if(roomTp[floor][j][k]=='H'){
                                        inside[j][k]=0;
                                        visitd[j][k]=0;
                                        used[j][k]=1;
                                    }
                                }
                            }
                            //Update Map
                            updtFloor(roomTp,visitd,inside,floor);
                            //Display Map
                            dispMap(roomTp,floor);
                            cout<<endl;
                            isLoad=1; //Set load flag so game can be loaded again
                        }
                        if(outcome==2){ //If player loses battle and wants to quit
                            //End Program
                            return 0;
                            break;
                        }
                        if(outcome==3){ //If player wins battle
                            //Output amount of XP gained
                            cout<<gf1.name<<" gained "<<xpGainz<<" EXP";
                            cout<<endl<<endl;
                            //Output amount of additional XP gained
                            cout<<gf1.name<<" gained an additional "<<xpGainz<<" EXP";
                            cout<<endl<<endl;
                            //Add XP
                            gf1.cxp+=xpGainz;
                            gf1.cxp+=xpGainz*3;
                            //Level Up function
                            lvlUp(gf1);
                            cout<<endl;
                            //Ouput XP status
                            cout<<"Max XP              : "<<gf1.mxp<<endl; 
                            cout<<"Current amount of XP: "<<gf1.cxp<<endl;
                            cout<<"XP Needed to lvl up : "<<gf1.mxp-gf1.cxp;
                            cout<<endl<<endl;
                            //Output floor victory message
                            cout<<"You walk past "<<boss[floor].name<<"'s corpse "
                                <<"and proceed onward to the next floor.";    
                            cout<<endl<<endl;
                            used[curPosY][curPosX]=0; //Set tile to used
                        }                       
                        break;
                }
            }
         //Reiterate until player defeats boss   
        }while(inside[bosPosX][bosPosY]==1&&visitd[bosPosX][bosPosY]==1);
    }
    //Exit program
    return 0;
}

//Print Functions

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*****************************   Display Map    *******************************
//Purpose:  Output Floor Map
//Inputs:   roomTp  -> 3D Array, 'O''X''E''B''?''T''H', char
//          floor   -> int     , 0-5                  , ints
//Output:   void function
//******************************************************************************
void dispMap(char roomTp[][LENGTH][WIDTH],int floor){
    for(int i=0;i<LENGTH;i++){
        for(int j=0;j<WIDTH;j++){           
            cout<<"| "<<roomTp[floor][i][j]<<" |"; //Output each tile of map            
            if(j%5==4)cout<<endl;                  //Break Line after 5 tiles 
        }
        for(int j=0;j<WIDTH;j++){
            cout<<' '<<"---"<<' ';                 //Output lines in between
            if(j%5==4)cout<<endl;                  //Break line after 5 iterations
        }
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*****************************   Display Title   ******************************
//Purpose:  Output Game Title
//Inputs:   titl  -> string representing file name
//Output:   void function
//******************************************************************************
void dispTtl(string titl){
    string lines[6];            //Array for number of lines in ASCII art
    ifstream read;              //Declare ifstream object
    read.open(titl);            //Open file
    for(int i=0;i<6;i++){
        getline(read,lines[i]); //Read in each line of ASCII art
    }
    for(int i=0;i<6;i++){
        cout<<lines[i]<<endl;   //Output each line of ASCII art
    }
    read.close();               //Close file
}

//Floor Functions
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//********************************   Fill Floor   ******************************
//Purpose:  Fill floor tile array with data
//Inputs:   roomTp  -> 3D Array, 'O''X''E''B''?''T''H', char
//          room    -> rumber of floors, 0-5, int
//          maps    -> string representing map file
//Output:   void function
//******************************************************************************
void fillFloor(char roomTp[][LENGTH][WIDTH],int room,string maps){
    fstream read;                      //Declare fstream object
    read.open(maps);                   //Open file
    for(int i=0;i<room;i++){
        for(int j=0;j<LENGTH;j++){
            for(int k=0;k<WIDTH;k++){
                read>>roomTp[i][j][k]; //Read in floor tile data
            }
        }
    }
    read.close();                      //Close file
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************************   Update Floor   ******************************
//Purpose:  Update floor tiles to correct char
//Inputs:   roomTp  -> 3D Array, 'O''X''E''B''?''T''H', char
//          room    -> rumber of floors, 0-5, int
//          maps    -> string representing map file
//Output:   void function
//******************************************************************************
void updtFloor(char roomTp[][LENGTH][WIDTH],bool visited[LENGTH][WIDTH],
               bool inside[LENGTH][WIDTH],int floor){
    for(int i=0;i<LENGTH;i++){
        for(int j=0;j<WIDTH;j++){
            if(inside[i][j]==0){ //Search for tile player is on
                roomTp[floor][i][j]='O'; //Set character on player tile to 'O'
            }
            else if(visited[i][j]==0&&inside[i][j]==1){ //Check if tile has been visited
                roomTp[floor][i][j]=roomTp[floor][i][j];//Set tile to original char
            }         
            else if(visited[i][j]==1&&inside[i][j]==1){ //Check if tile is unknown
                roomTp[floor][i][j]='?';                //Set tile to '?'
            }            
        }
    }
}

//Bool Functions
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************************   If Visited   ********************************
//Purpose:  Set array that determines which characters appear upon start
//Inputs:   roomTp  -> 3D Array, 'O''X''E''B''?''T''H', char
//          visited -> bool array of 25 (0 or 1)
//          floor   -> int, current floor player is on
//Output:   void function
//******************************************************************************
void ifVisit(char roomTp[][LENGTH][WIDTH],bool visited[LENGTH][WIDTH],int floor){
    for(int i=0;i<LENGTH;i++){
        for(int j=0;j<WIDTH;j++){
            //If tile is 'X','O', or 'H', set them as already visited
            roomTp[floor][i][j]=='X'||roomTp[floor][i][j]=='O'||roomTp[floor][i][j]=='H'
                ?visited[i][j]=0:visited[i][j]=1;
        }
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*******************************   If Inside   ********************************
//Purpose:  Set array that determines which tile player is on
//Inputs:   roomTp  -> 3D Array, 'O''X''E''B''?''T''H', char
//          inside  -> bool array of 25 (0 or 1)
//          floor   -> int, current floor player is on
//Output:   void function
//******************************************************************************
void ifInsid(char roomTp[][LENGTH][WIDTH],bool inside[LENGTH][WIDTH],int floor){
    for(int i=0;i<LENGTH;i++){
        for(int j=0;j<WIDTH;j++){
            //If tile is 'O', set it as inside
            roomTp[floor][i][j]=='O'
                ?inside[i][j]=0:inside[i][j]=1;
        }
    }
}

//Search Functions
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*******************************   Find Boss   ********************************
//Purpose:  Find tile boss is on and assign coordinates
//Inputs:   roomTp  -> 3D Array, 'O''X''E''B''?''T''H', char
//          floor   -> int, current floor player is on
//          bosPosX -> referenced int, location of boss on x axis
//          bosPosY -> referenced int, location of boss on y axis
//Output:   void function
//******************************************************************************
void findB(char roomTp[][LENGTH][WIDTH],int floor,int &bosPosX,int &bosPosY){
    for(int i=0;i<LENGTH;i++){    //Search for 'B'
        for(int j=0;j<WIDTH;j++){
            //Set loop iterations to boss x and y position
            if(roomTp[floor][i][j]=='B')bosPosX=i;bosPosY=j;
        }
    }
}

//Generate Functions
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*******************************   Find Boss   ********************************
//Purpose:  Increase GF stats by level up
//Inputs:   gf, Monster struct variable, holds all GF data
//Output:   void function
//******************************************************************************
void lvlUp(Monster &gf){
    while(gf.cxp>=gf.mxp){   //Continue leveling up until not enough XP 
        cout<<"LEVEL UP!";   //Output level up message
        cout<<endl<<endl;
        gf.lvl+=1;           //Increase level by 1
        gf.cxp-=gf.mxp;      //Remove amount of xp needed for level up
        gf.mxp*=1.25;        //Increase amount of xp needed to level up
        
        gf.hpt+=rand()%10;   //Increase max health by random amount
        gf.atk+=rand()%10;   //Increase attack power by random amount
        gf.def+=rand()%10;   //Increase defense by random amount
        gf.spd+=rand()%10;   //Increase speed by random amount
    }
    //Output new stats
    cout<<gf.name<<"'s Stats"<<endl;
    cout<<"Level    : "<<gf.lvl<<endl;
    cout<<"Vitality : "<<gf.hpt<<endl;
    cout<<"Strength : "<<gf.atk<<endl;
    cout<<"Toughness: "<<gf.def<<endl;
    cout<<"Agility  : "<<gf.spd<<endl;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*****************************   Generate GF   ********************************
//Purpose:  Generate companion using pseudo-random elements
//Inputs:   gf      -> Monster struct variable, holds all GF data
//          syllabl -> string array holding prefixes of GF names
//          numCh   -> char array holding integers
//Output:   void function
//******************************************************************************
void gnratGf(Monster &gf,string syllabl[],char numCh[]){
    gf.hpt=rand()%5+5; //Assign hp random value 5-10
    gf.chp=gf.hpt;     //Assign same value as above
    gf.atk=rand()%5+5; //-----
    gf.def=rand()%5+5; //-----
    gf.spd=rand()%5+5; //-----
    gf.mxp=10;         //Starting XP meter at 10 XP
    gf.cxp=0;          //XP starts at 0
    gf.lvl=1;          //Starting Level: 1
    //Assign random prefix + same middle + random 3 digit suffix
    gf.name=syllabl[rand()%18]+"-E_mk."+numCh[rand()%10]+numCh[rand()%10]+numCh[rand()%10];
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//**************************   Generate Enemy   ********************************
//Purpose:  Generate enemy monster using pseudo-random elements
//Inputs:   gf      -> Monster struct variable, holds all GF data
//          enNames -> string array holding possible enemy names
//          floor   -> int holding current floor
//Output:   void function
//******************************************************************************
void gnratEn(Monster &en,string enNames[],int floor){
    en.lvl=(rand()%3+1)*(floor+1); //Assign random level multiplier 1-3*current floor
    en.hpt=((rand()%5+1)*en.lvl);  //Assign HP value 1-5 * current floor
    en.chp=en.hpt;
    en.atk=((rand()%5+1)*en.lvl);  //Assign ATK value 1-5 * current floor
    en.def=((rand()%5+1)*en.lvl);  //Assign DEF value 1-5 * current floor
    en.spd=((rand()%5+1)*en.lvl);  //Assign SPD value 1-5 * current floor
    en.name=enNames[rand()%5];     //Assign random name from array
}

//Battle Functions
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*****************************   Boss Battle   ********************************
//Purpose:  Simulate Boss Battle
//Inputs:   gf      -> Monster struct variable, holds all GF data
//          boss    -> string array holding possible enemy names
//          floor   -> int holding current floor
//          choice  -> choice input
//          outcome -> final result of battle (win/lose)
//Output:   returns outcome of battle (win, loss, quit, load)
//******************************************************************************
int bsBattl(Monster &gf,Monster boss[],int floor,char &choice,int &outcome){
    int  pryChnc=0; //Parry Chance
    bool blkLast=1; //Check if player blocked last turn
    
    //Output name and flavor text of enemy
    cout<<"A POWERFUL ENEMY REVEALS ITSELF!";
    cout<<endl<<endl;
    cout<<"Name: "<<boss[floor].name<<endl;
    cout<<"Analysis: "<<boss[floor].flvr;
    cout<<endl<<endl;
    
    do{
        //Output health of player and enemy
        cout<<gf.name<<"'s health: "<<gf.chp<<endl;
        cout<<boss[floor].name<<"'s health: "<<boss[floor].chp<<endl;
        cout<<endl;
        //Prompt player for input
        cout<<"What will you do?"<<endl<<endl;
        cout<<"1. Attack"<<endl;
        cout<<"2. Block"<<endl;
        cout<<"3. Parry"<<endl;
        //Input Choice
        cin>>choice;
        cout<<endl;
        switch(choice){
            case 49: //If user chooses to attack
                //Check if player's speed is higher
                if(gf.spd>boss[floor].spd){
                    //Check if player is strong enough to deal damage
                    if(gf.atk>boss[floor].def/2){
                        //Output amount of damage dealt
                        cout<<"You attack and deal "<<gf.atk-boss[floor].def/2<<" damage!";
                        cout<<endl;
                        //Calculate damage
                        boss[floor].chp-=gf.atk-boss[floor].def/2;
                    }
                    else{
                        //Output no damage message
                        cout<<"You attack and deal 0 damage!";
                        cout<<endl;
                        //Remove no health
                        boss[floor].chp-=0;
                    }
                    //Check if enemy is strong enough to deal damage and if alive
                    if(boss[floor].atk>gf.def/2&&boss[floor].chp>0){
                        //Output amount of damage dealt
                        cout<<boss[floor].name<<" attacks and deals "<<boss[floor].atk-gf.def/2
                            <<" damage!";
                        cout<<endl;
                        //Calculate damage
                        gf.chp-=boss[floor].atk-gf.def/2;
                    }
                    else if(boss[floor].atk<gf.def/2&&boss[floor].chp>0){
                        //Output no damage message
                        cout<<boss[floor].name<<" attacks and deals 0 damage!";
                        cout<<endl;
                        //Remove no health
                        gf.chp-=0;
                    }
                    //If enemy is dead
                    else{
                        //Output victory message
                        cout<<boss[floor].name<<" falls to the floor defeated.";
                        cout<<endl;
                    }
                }
                else{
                    //Check if enemy is strong enough to deal damage
                    if(boss[floor].atk>gf.def/2){
                        //Output amount of damage dealt
                        cout<<boss[floor].name<<" attacks and deals "<<boss[floor].atk-gf.def/2
                            <<" damage!";
                        cout<<endl;
                        //Calculate damage
                        gf.chp-=(boss[floor].atk-gf.def/2);
                    }
                    else{
                        //Output no damage message
                        cout<<boss[floor].name<<" attacks and deals 0 damage!";
                        cout<<endl;
                        //Remove no health
                        gf.chp-=0;
                    }
                    //Check if player is strong enough to deal damage and if alive
                    if(gf.atk>boss[floor].def/2&&gf.chp>0){
                        //Output amount of damage dealt
                        cout<<"You attack and deal "<<gf.atk-boss[floor].def/2<<" damage!";
                        cout<<endl;
                        //Calculate damage
                        boss[floor].chp-=gf.atk-boss[floor].def/2;
                    }
                    else if(gf.atk<boss[floor].def/2&&gf.chp>0){
                        //Output no damage message
                        cout<<"You attack and deal 0 damage!";
                        cout<<endl;
                        //Remove no health
                        boss[floor].chp-=0;
                    }
                    //If enemy is dead
                    else{
                        //Output defeat message
                        cout<<gf.name<<" falls to the floor defeated.";
                        cout<<endl;
                    }
                }
                blkLast=1; //Set block flag to not blocked
                break;
            case 50: //If player chooses to block
                if(blkLast==1){ //Check if player blocked last turn
                    //Output block success
                    cout<<"You block the enemy's attack!"<<endl;
                    blkLast=0;  //Set block flag to blocked
                }
                else{
                    //Output failure message 
                    cout<<"You failed to block the enemy's attack."<<endl;
                    //Check if enemy is strong enough to attack
                    if(boss[floor].atk-gf.def/2<=0){ 
                        //Output failure
                        cout<<"You take 0 damage!"<<endl;
                        //Deal no damage
                        gf.chp-=0;
                    }
                    else{
                        //Output amount of damage dealt
                        cout<<"You take "<<boss[floor].atk-gf.def/2<<" damage!"<<endl;
                        //Calculate damage
                        gf.chp-=boss[floor].atk-gf.def/2;
                    }
                    blkLast=1; //Set block flag to not blocked
                    if(gf.chp<=0)cout<<gf.name<<" falls to the floor defeated.";
                    cout<<endl;
                }
                break;
            case 51: //If player chooses to parry
                if(pryChnc==rand()%2){ //If parry is successful
                    //Output success message
                    cout<<"Parry successful!"<<endl;
                    //Output damage dealt
                    cout<<"You dealt "<<(gf.atk*2)<<" damage!"<<endl;
                    //Calculate damage
                    boss[floor].chp-=(gf.atk*2);
                    //Check if enemy is dead
                    if(boss[floor].chp<=0)cout<<boss[floor].name<<" falls to the floor defeated.";
                    cout<<endl;
                }
                else{ //If parry fails
                    //Output failure message
                    cout<<"Parry unsuccessful!"<<endl;
                    //Output damage dealt
                    cout<<"You take "<<(boss[floor].atk*2)<<" damage!"<<endl;
                    //Calculate damage
                    gf.chp-=(boss[floor].atk*2);
                    //Check if player is dead
                    if(gf.chp<=0)cout<<gf.name<<" falls to the floor defeated.";
                    cout<<endl;
                }
                blkLast=1; //Set block flag to not blocked
                break;
            default: //If input is invalid
                cout<<"Invalid input!";
                cout<<endl<<endl;
                break;
        }
    }while(gf.chp>0&&boss[floor].chp>0); //Reiterate until someone dies
    
    if(gf.chp>0){ //If player is winner
        //Output victory message
        cout<<"You defeated "<<boss[floor].name<<'!';
        cout<<endl<<endl;
        //Return victory
        outcome=3;
        return outcome;
    }
    else{ //If boss is winner
        //Output defeat message
        cout<<"After slaying your GMO, "<<boss[floor].name<<" slowly turns and fixes"
            <<endl<<"its gaze on you. Looks like this is the end...";
        cout<<endl<<endl;
        cout<<"GAME OVER";
        cout<<endl<<endl;
        do{
            //Prompt user for choice
            cout<<"What would you like to do?"<<endl;
            cout<<"1. Load Game"<<endl;
            cout<<"2. Quit Game"<<endl;
            //Input choice
            cin>>choice;
            switch(choice){
                case 49: //If choice is load
                    //Return load outcome
                    outcome=1;
                    return outcome;
                    break;
                case 50: //If choice is quit
                    //Return quit outcome
                    outcome=2;
                    return outcome;
                    break;
                default: //If input is invalid
                    cout<<"Invalid input!";
                    cout<<endl;
                    break;
            }
        }while(choice<49||choice>50);   
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*****************************   Enemy Battle   ********************************
//Purpose:  Simulate Enemy Battle
//Inputs:   gf      -> Monster struct variable, holds all GF data
//          en      -> string array holding possible enemy names
//          floor   -> int holding current floor
//          choice  -> choice input
//          outcome -> final result of battle (win/lose)
//Output:   returns outcome of battle (win, loss, quit, load)
//******************************************************************************
int enBattl(Monster &gf,Monster &en,string enNames[],int floor,char &choice,int &outcome){
    int  pryChnc=0; //Parry Chance
    bool blkLast=1; //Check if player blocked last turn
    //Generate enemy
    gnratEn(en,enNames,floor);
    cout<<"A level "<<en.lvl<<' '<<en.name<<" appeared!";
    cout<<endl<<endl;
    do{
        //Output health of player and enemy
        cout<<gf.name<<"'s health: "<<gf.chp<<endl;
        cout<<en.name<<"'s health: "<<en.chp<<endl;
        cout<<endl;
        //Prompt user
        cout<<"What will you do?"<<endl<<endl;
        cout<<"1. Attack"<<endl;
        cout<<"2. Block"<<endl;
        cout<<"3. Parry"<<endl;
        //Input choice
        cin>>choice;
        cout<<endl;
        switch(choice){
            case 49: //If user chooses to attack
                //Check if player's speed is higher
                if(gf.spd>en.spd){ 
                    //Check if player is strong enough to deal damage
                    if(gf.atk>en.def/2){
                        //Output damage dealt and calculate
                        cout<<"You attack and deal "<<gf.atk-en.def/2<<" damage!";
                        cout<<endl;
                        en.chp-=gf.atk-en.def/2;
                    }
                    else{
                        //Output failure message
                        cout<<"You attack and deal 0 damage!";
                        cout<<endl;
                        en.chp-=0;
                    }
                    //Check if enemy is strong enough to attack
                    if(en.atk>gf.def/2&&en.chp>0){
                        //Output damage dealt and calculate
                        cout<<en.name<<" attacks and deals "<<en.atk-gf.def/2
                            <<" damage!";
                        cout<<endl;
                        gf.chp-=en.atk-gf.def/2;
                    }
                    else if(en.atk<gf.def/2&&en.chp>0){
                        //Output failure message
                        cout<<en.name<<" attacks and deals 0 damage!";
                        cout<<endl;
                        gf.chp-=0;
                    }
                    else{
                        //Output victory message
                        cout<<en.name<<" falls to the floor defeated.";
                        cout<<endl;
                    }
                }
                else{
                    //Check if enemy is strong enough to deal damage
                    if(en.atk>gf.def/2){
                        //Output damage dealt and calculate
                        cout<<en.name<<" attacks and deals "<<en.atk-gf.def/2
                            <<" damage!";
                        cout<<endl;
                        gf.chp-=(en.atk-gf.def/2);
                    }
                    else{
                        //Output failure message
                        cout<<en.name<<" attacks and deals 0 damage!";
                        cout<<endl;
                        gf.chp-=0;
                    }
                    //Check if player is strong enough to deal damage
                    if(gf.atk>en.def/2&&gf.chp>0){
                        //Output damage dealt and calculate
                        cout<<"You attack and deal "<<gf.atk-en.def/2<<" damage!";
                        cout<<endl;
                        en.chp-=gf.atk-en.def/2;
                    }
                    else if(gf.atk<en.def/2&&gf.chp>0){
                        //Output failure message
                        cout<<"You attack and deal 0 damage!";
                        cout<<endl;
                        en.chp-=0;
                    }
                    else{
                        //Output defeat message
                        cout<<gf.name<<" falls to the floor defeated.";
                        cout<<endl;
                    }
                }
                blkLast=1; //Set block flag to false
                break;
            case 50: //If player chooses to block
                if(blkLast==1){ //If player didn't block last turn
                    //Output success
                    cout<<"You block the enemy's attack!"<<endl;
                    blkLast=0; //Set block flag to true
                }
                else{
                    //Output failure message
                    cout<<"You failed to block the enemy's attack."<<endl;
                    if(en.atk-gf.def/2<=0){ //If enemy is too weak to deal damage
                        cout<<"You take 0 damage!"<<endl;
                        gf.chp-=0;
                    }
                    else{
                        //Output damage and calculate
                        cout<<"You take "<<en.atk-gf.def/2<<" damage!"<<endl;
                        gf.chp-=en.atk-gf.def/2;
                    }
                    blkLast=1; //Set block flag to false
                    //Output defeat message if dead
                    if(gf.chp<=0)cout<<gf.name<<" falls to the floor defeated.";
                    cout<<endl;
                }
                break;
            case 51: //If player chooses to parry
                if(pryChnc==rand()%2){
                    //Output success and calculate damage
                    cout<<"Parry successful!"<<endl;
                    cout<<"You dealt "<<(gf.atk*2)<<" damage!"<<endl;
                    en.chp-=(gf.atk*2);
                    //Output victory if enemy is dead
                    if(en.chp<=0)cout<<en.name<<" falls to the floor defeated.";
                    cout<<endl;
                }
                else{
                    //Output failure
                    cout<<"Parry unsuccessful!"<<endl;
                    //Output damage and calculate
                    cout<<"You take "<<(en.atk*2)<<" damage!"<<endl;
                    gf.chp-=(en.atk*2);
                    //Output defeat if dead
                    if(gf.chp<=0)cout<<gf.name<<" falls to the floor defeated.";
                    cout<<endl;
                }
                blkLast=1; //Set block flag to false
                break;
            default: //If input is invalid
                cout<<"Invalid input!";
                cout<<endl<<endl;
                break;
        }
    }while(gf.chp>0&&en.chp>0); //Reiterate until someone is dead
    
    if(gf.chp>0){ //If player is alive
        //Output victory and return victory outcome
        cout<<"You defeated "<<en.name<<'!';
        cout<<endl<<endl;
        outcome=3;
        return outcome;
    }
    else{
        //Output defeat message
        cout<<"After slaying your GMO, "<<en.name<<" slowly turns and fixes"
            <<endl<<"its gaze on you. Looks like this is the end...";
        cout<<endl<<endl;
        cout<<"GAME OVER";
        cout<<endl<<endl;
        do{
            //Prompt user for input
            cout<<"What would you like to do?"<<endl;
            cout<<"1. Load Game"<<endl;
            cout<<"2. Quit Game"<<endl;
            //Input choice
            cin>>choice;
            switch(choice){
                case 49: //If player chooses to load
                    //return load outcome
                    outcome=1;
                    return outcome;
                    break;
                case 50: //If player chooses to quit
                    //Return quit outcome
                    outcome=2;
                    return outcome;
                    break;
                default: //If input is invalid
                    cout<<"Invalid input!";
                    cout<<endl;
                    break;
            }
        }while(choice<49||choice>50); //Reiterate until valid choice is made   
    }
}

//File Manipulation Functions
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*******************************   Save Game   ********************************
//Purpose:  Save game data to file
//Inputs:   visitd  -> bool array holding which tiles have been stepped on
//          prog    -> bool flag which tells whther intro has been completed
//          gf      -> Monster struct variable, holds all GF data
//          floor   -> int holding current floor
//          data    -> string representing file name
//Output:   sends all data to data.dat
//******************************************************************************
void save(bool visitd[][WIDTH],bool prog,Monster &gf,int floor,string data){
    ofstream write;       //Declare write object
    write.open(data);     //Open file
    write<<prog<<endl;    //Write data to file
    write<<floor<<endl;
    write<<gf.name<<endl;
    write<<gf.hpt<<endl;
    write<<gf.chp<<endl;        
    write<<gf.atk<<endl;
    write<<gf.def<<endl;
    write<<gf.spd<<endl;
    write<<gf.mxp<<endl;
    write<<gf.cxp<<endl;
    write<<gf.lvl<<endl;
    //Write map data from visitd array
    for(int i=0;i<LENGTH;i++){
        for(int j=0;j<WIDTH;j++){
            write<<visitd[i][j]<<' ';
            if(j%5==4)write<<endl;
        }
    }
    
    write.close();      //Close file
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*******************************   Load Game   ********************************
//Purpose:  Load game data from file
//Inputs:   visitd  -> bool array holding which tiles have been stepped on
//          prog    -> bool flag which tells whther intro has been completed
//          gf      -> Monster struct variable, holds all GF data
//          floor   -> int holding current floor
//          data    -> string representing file name
//Output:   sends all data to data.dat
//******************************************************************************
void load(bool visitd[][WIDTH],bool prog,Monster &gf,int &floor,string data){
    ifstream read;   //Declare read object
    read.open(data); //Open file
    read>>prog;      //Read in all data from file
    read>>floor;
    read>>gf.name;
    read>>gf.hpt;
    read>>gf.chp;
    read>>gf.atk;
    read>>gf.def;
    read>>gf.spd;
    read>>gf.mxp;
    read>>gf.cxp;
    read>>gf.lvl;
    //Read map data from file back into array
    for(int i=0;i<LENGTH;i++){
        for(int j=0;j<WIDTH;j++){
            read>>visitd[i][j];
        }
    }
    
    read.close();     //Close file
}