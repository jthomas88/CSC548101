/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <fstream>   //File I/O
#include <string>    //String Manipulation
#include <ctime>     //Random Seed
#include <cstdlib>   //Random Generator


using namespace std; //Namespace used in system library

//User libraries

//Global constants
int const LENGTH=5;
int const WIDTH=5;

//Structures
struct Monster{
        int    hpt;   //Max Health Points
        int    chp;   //Current health
        int    atk;   //Base Attack
        int    def;   //Base Defense
        int    spd;   //Base Speed
        int    mxp;   //Max EXP
        int    cxp;   //Current EXP
        int    lvl;   //Current Level
        string name;  //Monster Name
        string flvr;  //Monster Flavor Text
        //char   type;  //Monster Elemental Type
    };

//Function prototypes
void dispMap(int [LENGTH][WIDTH],char[][LENGTH][WIDTH],int);

void fillFloor(char[][LENGTH][WIDTH],int,string);

void dispFloor(char[][LENGTH][WIDTH],int);

void updtFloor(char[][LENGTH][WIDTH],bool[LENGTH][WIDTH],bool[LENGTH][WIDTH],int);

//Bool Functions
void ifVisit(char[][LENGTH][WIDTH],bool[LENGTH][WIDTH],bool[LENGTH][WIDTH],int);
void ifInsid(char[][LENGTH][WIDTH],bool[LENGTH][WIDTH],bool[LENGTH][WIDTH],int);

//Search Functions
void findB(char[][LENGTH][WIDTH],int,int&,int&);

//Generate Monster function
void gnratGf(Monster&,string[]);

//Generate Enemy
void gnratEn(Monster&,string[],int);

//Battle Scenario
void enBattl(Monster&,Monster&,string[],int,bool,int&,string);

void bsBattl(Monster&,Monster[],int,int&);

void lvlUp(Monster&);

void save(bool,Monster&,int,string);

void load(bool,Monster&,int&,string);

void dispTtl(string);

void prsEntr();

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize Random Seed
    srand(time(0));   
    
    //Declare Arrays
    int  map[LENGTH][WIDTH];    //Array that holds room type on map
    char roomTp[5][LENGTH][WIDTH];
    
    //Location checks
    bool visitd[LENGTH][WIDTH]={};
    bool inside[LENGTH][WIDTH]={};
    bool used[LENGTH][WIDTH]={};
    
    //Boss Monsters
    Monster boss[5];
    
    //Initialize Bosses
    boss[0].hpt=20;
    boss[0].chp=boss[0].hpt;
    boss[0].atk=8;
    boss[0].def=12;
    boss[0].spd=12;
    boss[0].name="L.I.L.I.M.";
    boss[0].flvr="A wretched mutant GMO with small wings. She is the leader of "
            "the lesser monsters of Floor B1";
    
    boss[1].hpt=40;
    boss[1].chp=boss[1].hpt;
    boss[1].atk=20;
    boss[1].def=12;
    boss[1].spd=18;
    boss[1].name="I.S.H.T.A.R.";
    boss[1].flvr="A reptilian GMO whose fangs can kill instantly. She is the "
            "leader of the lesser monsters of Floor B2";
    
    boss[2].hpt=60;
    boss[2].chp=boss[2].hpt;
    boss[2].atk=30;
    boss[2].def=30;
    boss[2].spd=30;
    boss[2].name="F.R.E.Y.A.";
    boss[2].flvr="A massive GMO with skin made of steel. She is the leader of "
            "the lesser monsters of Floor B3";
    
    boss[3].hpt=80;
    boss[3].chp=boss[3].hpt;
    boss[3].atk=42;
    boss[3].def=35;
    boss[3].spd=65;
    boss[3].name="E.R.O.S.";
    boss[3].flvr="A vile GMO with large pores endlessly leaking. She is the "
            "leader of the lesser monsters of Floor B4";
    
    boss[4].hpt=100;
    boss[4].chp=boss[4].hpt;
    boss[4].atk=65;
    boss[4].def=50;
    boss[4].spd=80;
    boss[4].name="A.P.H.R.O.D.I.T.E.";
    boss[4].flvr="Queen of the mutant nest that's formed in the depths of the "
            "abandoned research facility. Because she's attached to the walls, "
            "she sends scavengers to collect food.";
    
    //Monster Traits
    string syllabl[10]={"ka","tor","dan","go","pip","rol","aa","rr","byl","-"};
    string enNames[5] ={"Mutant GF","Wandering Security Drone","Giant Rat",
                        "Daughter of Aphrodite","GF Ghost"};
    
    //Declare Variables
    char   choice;
    char   movDir;
    int    floor=0;
    int    numCho;
    int    room=5;
    int    curRoom=0;
    int    xPos,yPos=0;     //Boss location on grid
    int    curPosX,curPosY; //Player's location on grid
    bool   intro=1;    
    string file="maps.dat";
    string data="data.dat";
    string titl="title.dat";
    
    Monster gf1;
    Monster en;
    
    //Output Title
    dispTtl(titl);
    
    cout<<"1. New Game"<<endl;
    cout<<"2. Load Game"<<endl;
    do{
        cin>>numCho;
        switch(numCho){
            case 1:
                break;
            case 2:
                load(intro,gf1,floor,data);
                cout<<endl;
                cout<<intro<<endl;
                cout<<floor<<endl;
                cout<<gf1.name<<endl;
                cout<<gf1.hpt<<endl;
                cout<<gf1.chp<<endl;        
                cout<<gf1.atk<<endl;
                cout<<gf1.def<<endl;
                cout<<gf1.spd<<endl;
                cout<<gf1.mxp<<endl;
                cout<<gf1.cxp<<endl;
                cout<<gf1.lvl<<endl;
        }
    }while(numCho>2||numCho<1);
    
    if(intro==1){
        //Introduction
        cout<<"Hello! Welcome to GMO (Girlfriends Made to Order)!"<<endl<<endl;
        cout<<"I'm the lead researcher here. I'd like to thank you for agreeing "
            <<endl<<"to participate in our beta testing. We take it upon ourselves"
            <<endl<<"to provide a much needed service for people like you and I. "
            <<endl<<"We're great guys who just can't seem to get a gf no matter how"
            <<endl<<"hard we try! Let's take a quick tour of the facility and then"
            <<endl<<"we can let you start the testing process!";    
        cout<<endl<<endl;
        
        cout<<"Press ENTER to continue";
        cin.get();
        cout<<endl;
        
        cout<<"(You're led to a room with a huge glass chamber inside)"<<endl<<endl;
        cout<<"This is our GMOGen Girlfriend Generator, or GMOGGG. This is what we"
            <<endl<<"will utilize for this beta test. Go ahead and press that big"
            <<endl<<"button in the middle of the console.";
        cout<<endl<<endl;
        cout<<"Press ENTER to start the beta test";
        cin.get();
        cout<<endl;

        do{
            cout<<"(The machine emits a puff of smoke and a figure appears)"<<endl;
            gnratGf(gf1,syllabl);
            cout<<"You have created: "<<gf1.name<<endl;
            cout<<"Vitality : "<<gf1.hpt<<endl;
            cout<<"Strength : "<<gf1.atk<<endl;
            cout<<"Toughness: "<<gf1.def<<endl;
            cout<<"Agility  : "<<gf1.spd<<endl;
            cout<<"Will you keep this one? ('y' to keep or 'n' to try again)";
            cout<<endl;
            cin>>choice;
            cin.ignore();
            cout<<endl;
        }while(choice!='y');

        cout<<gf1.name<<" has been added to your party!";

        cout<<endl<<endl;

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
        cin.get();
        cout<<endl;

        cout<<"(You make it into the elevator right before it closes. Your GMO"
            <<endl<<"seems to have followed you as well. You look at the elevator"
            <<endl<<"panel and notice it only has one button. You have no idea"
            <<endl<<"where it will go but you seem to have no choice now.)";

        cout<<endl<<endl;

        cout<<"Press ENTER to press the elevator button";
        cin.get();
        cout<<endl;

        cout<<"(You arrive to a dark corridor. The sign on the wall says \"B1\")";

        cout<<endl<<endl;
        intro=true;
    }

    cout<<"CONTROLS"<<endl;
    cout<<"'w' = Move forward"<<endl;
    cout<<"'s' = Move backward"<<endl;
    cout<<"'a' = Move left"<<endl;
    cout<<"'d' = Move right"<<endl;
    cout<<"Press ENTER after you input your movement.";
    cout<<endl<<endl;
    
    for(floor;floor<room;++floor){
        
        cout<<"Floor: B"<<floor+1<<endl;
        //Fill in map data from file
        fillFloor(roomTp,room,file);     
        
        //Update ifVisit
        ifVisit(roomTp,visitd,inside,floor);

        //Update ifInsid
        ifInsid(roomTp,visitd,inside,floor);
        
        for(int j=0;j<LENGTH;j++){
            for(int k=0;k<WIDTH;k++){
                if(roomTp[floor][j][k]=='B'){
                    xPos=j;
                    yPos=k;
                }
            }
        }
        
        //Spawn Character

        for(int j=0;j<LENGTH;j++){
            for(int k=0;k<WIDTH;k++){
                if(roomTp[floor][j][k]=='H'){
                    inside[j][k]=0;
                    visitd[j][k]=0;
                }
            }
        }
        
        //Update Map
        updtFloor(roomTp,visitd,inside,floor);
        
        //Display Map
        dispMap(map,roomTp,floor);
        cout<<endl;
        
        //Reset used bool
        for(int i=0;i<LENGTH;i++){
            for(int j=0;j<WIDTH;j++){
                used[i][j]=0;
            }
        }
        
        do{
            cout<<"This room appears to still have working "
                <<"equipment inside. What would you like to do?";
            cout<<endl;
            cout<<"1. Save Game"<<endl;
            cout<<"2. Rest"<<endl;
            cout<<"3. Leave"<<endl;
            cin>>numCho;
            cout<<endl;
            switch(numCho){
                case 1:
                    //Save Function
                    break;
                case 2:
                    cout<<gf1.name<<" has been fully healed.";
                    cout<<endl<<endl;
                    gf1.chp=gf1.hpt;
                    break;
                case 3:
                    updtFloor(roomTp,visitd,inside,floor);
                    dispMap(map,roomTp,floor);
                    cout<<endl;
                    break;
            }
        }while(numCho!=3);
        
        //Move Character
        do{
            cin>>movDir;
            switch(movDir){
                case 'w':
                    cout<<endl;
                    for(int i=0;i<LENGTH;i++){
                        for(int j=0;j<WIDTH;j++){      
                            if(inside[i][j]==0){                         
                                inside[i][j]=1;
                                inside[i-1][j]=0;
                                visitd[i-1][j]=0;
                                
                                curPosX=j;
                                curPosY=i-1;
                                
                                if(i==0||roomTp[floor][i-1][j]=='X'){
                                    cout<<"There seems to be a wall in the way...";
                                    cout<<endl;
                                    inside[i][j]=1;
                                    inside[i-1][j]=1;
                                    inside[i+1][j]=0;
                                    visitd[i][j]=1;
                                }
                            }
                        }
                    }
                //Return Original Symbols
                fillFloor(roomTp,room,file);    

                //Update Map after move
                updtFloor(roomTp,visitd,inside,floor);

                //Display Map after move
                dispMap(map,roomTp,floor);
                cout<<endl;
                break;

                case 's':
                    for(int i=LENGTH-1;i>=0;i--){
                        for(int j=WIDTH-1;j>=0;j--){      
                            if(inside[i][j]==0){  
                                inside[i][j]=1;
                                inside[i+1][j]=0;
                                visitd[i+1][j]=0;
                                visitd[i][j]=0;
                                
                                curPosX=j;
                                curPosY=i+1;
                                
                                if(i==4||roomTp[floor][i+1][j]=='X'){
                                    cout<<"There seems to be a wall in the way...";
                                    cout<<endl;
                                    inside[i][j]=1;
                                    inside[i+1][j]=1;
                                    inside[i-1][j]=0;
                                    visitd[i][j]=1;
                                }
                            }
                        }
                    }
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
                                visitd[i][j-1]=0;
                                
                                curPosX=j-1;
                                curPosY=i;

                                if(j==0||roomTp[floor][i][j-1]=='X'){
                                    cout<<"There seems to be a wall in the way...";
                                    cout<<endl;
                                    inside[i][j]=1;
                                    inside[i][j-1]=1;
                                    inside[i][j+1]=0;
                                    visitd[i][j]=1;
                                }
                            }
                        }
                    }
                //Return Original Symbols
                fillFloor(roomTp,room,file);    

                //Update Map after move
                updtFloor(roomTp,visitd,inside,floor);

                //Display Map after move
                dispMap(map,roomTp,floor);
                cout<<endl;
                break;

                case 'd':
                    for(int i=LENGTH-1;i>=0;i--){
                        for(int j=WIDTH-1;j>=0;j--){      
                            if(inside[i][j]==0){  
                                inside[i][j]=1;
                                inside[i][j+1]=0;
                                visitd[i][j+1]=0;
                                
                                curPosX=j+1;
                                curPosY=i;
                                
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
                //Return Original Symbols
                fillFloor(roomTp,room,file);    

                //Update Map after move
                updtFloor(roomTp,visitd,inside,floor);

                //Display Map after move
                dispMap(map,roomTp,floor);
                cout<<endl;
                break;
            }

            cout<<endl;
            if(inside[curPosY][curPosX]==0&&used[curPosY][curPosX]==0){    
                fillFloor(roomTp,room,file);
                cout<<floor<<' '<<curPosY<<' '<<curPosX<<endl;
                int xpGainz=(rand()%15+1*(floor+1));
                switch(roomTp[floor][curPosY][curPosX]){
                    case 'E':
                        enBattl(gf1,en,enNames,floor,intro,numCho,data);
                        if(numCho==2)return 0;
                        
                        cout<<gf1.name<<" gained "<<xpGainz<<" EXP";
                        cout<<endl<<endl;
                        gf1.cxp+=xpGainz;
                        cout<<"Current amount of XP: "<<gf1.cxp<<endl;
                        lvlUp(gf1);
                        cout<<"Max XP              : "<<gf1.mxp<<endl; 
                        cout<<"Current amount of XP: "<<gf1.cxp<<endl;
                        cout<<"XP Needed to lvl up : "<<gf1.mxp-gf1.cxp<<endl;
                        updtFloor(roomTp,visitd,inside,floor);
                        dispMap(map,roomTp,floor);
                        used[curPosY][curPosX]=1;
                        break;
                    case 'T':
                        switch(rand()%3){
                            case 0:
                                cout<<"You scour the room and find nothing of "
                                    <<"value. However, not having to "
                                    <<endl<<"fight one of those abominations is "
                                    <<"a treasure in itself.";
                                cout<<endl;
                                used[curPosY][curPosX]=1;
                                break;
                            case 1:
                                cout<<"You find some snack mix in a "
                                    <<"scientist's office. You're not very "
                                    <<endl<<"hungry but "<<gf1.name<<" gladly "
                                    <<"eats it.";
                                cout<<endl<<endl;
                                cout<<gf1.name<<" has been fully healed!";
                                cout<<endl;
                                gf1.chp=gf1.hpt;
                                used[curPosY][curPosX]=1;
                                break;
                            case 2:
                                cout<<"You find some strange pills in a lockbox. "
                                    <<gf1.name<<" consumes them and"
                                    <<endl<<"starts to glow with newfound"
                                    <<" energy.";
                                cout<<endl<<endl;
                                gf1.cxp=gf1.mxp;
                                lvlUp(gf1);
                                used[curPosY][curPosX]=1;
                                break;
                        }
                        break;
                    case 'H':
                        do{
                            cout<<"This room appears to still have working "
                                <<"equipment inside. What would you like to do?";
                            cout<<endl;
                            cout<<"1. Save Game"<<endl;
                            cout<<"2. Rest"<<endl;
                            cout<<"3. Leave"<<endl;
                            cin>>numCho;
                            switch(numCho){
                                case 1:
                                    //Save Function
                                    break;
                                case 2:
                                    cout<<gf1.name<<" has been fully healed.";
                                    cout<<endl;
                                    gf1.chp=gf1.hpt;
                                    break;
                                case 3:
                                    updtFloor(roomTp,visitd,inside,floor);
                                    dispMap(map,roomTp,floor);
                                    break;
                            }
                        }while(numCho!=3);
                        break;
                    case 'B':
                        bsBattl(gf1,boss,floor,numCho);
                        if(numCho==2)return 0;
                        
                        cout<<gf1.name<<" gained "<<xpGainz<<" EXP";
                        cout<<endl<<endl;
                        gf1.cxp+=xpGainz;
                        cout<<"Current amount of XP: "<<gf1.cxp<<endl;
                        lvlUp(gf1);
                        cout<<"Max XP              : "<<gf1.mxp<<endl; 
                        cout<<"Current amount of XP: "<<gf1.cxp<<endl;
                        cout<<"XP Needed to lvl up : "<<gf1.mxp-gf1.cxp<<endl;
                        break;
                }
            }
        }while(inside[xPos][yPos]==1&&visitd[xPos][yPos]==1);
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
            }
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
            roomTp[floor][i][j]=='X'||roomTp[floor][i][j]=='O'||roomTp[floor][i][j]=='H'
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

//Search for end point of the floor
void findB(char roomTp[][LENGTH][WIDTH],int floor,int &xPos,int &yPos){
    for(int i=0;i<LENGTH;i++){
        for(int j=0;j<WIDTH;j++){
            if(roomTp[floor][i][j]=='B')xPos=i;yPos=j;
        }
    }
}

void gnratGf(Monster &gf,string syllabl[]){
    gf.hpt=rand()%5+5;
    gf.chp=gf.hpt;
    gf.atk=rand()%5+5;
    gf.def=rand()%5+5;
    gf.spd=rand()%5+5;
    gf.mxp=10;
    gf.cxp=0;
    gf.lvl=1;
    gf.name=syllabl[rand()%10]+syllabl[rand()%10]+syllabl[rand()%10];
}

void gnratEn(Monster &en,string enNames[],int floor){
    en.lvl=(rand()%3+1)*(floor+1);
    en.hpt=((rand()%5+1)*en.lvl);
    en.chp=en.hpt;
    en.atk=((rand()%5+1)*en.lvl);
    en.def=((rand()%5+1)*en.lvl);
    en.spd=((rand()%5+1)*en.lvl);
    en.name=enNames[rand()%5];
}

void lvlUp(Monster &gf){
    while(gf.cxp>=gf.mxp){
        cout<<"LEVEL UP!"<<endl<<endl;
        gf.lvl+=1;           //Increase level by 1
        gf.cxp-=gf.mxp;      //Remove amount of xp needed for level up
        gf.mxp*=1.25; //Increase amount of xp needed to level up
        
        gf.hpt+=rand()%10;    //Increase max health by random amount
        gf.atk+=rand()%10;    //Increase attack power by random amount
        gf.def+=rand()%10;    //Increase defense by random amount
        gf.spd+=rand()%10;    //Increase speed by random amount
    }
    cout<<gf.name<<"'s Stats"<<endl;
    cout<<"Level    : "<<gf.lvl<<endl;
    cout<<"Vitality : "<<gf.hpt<<endl;
    cout<<"Strength : "<<gf.atk<<endl;
    cout<<"Toughness: "<<gf.def<<endl;
    cout<<"Agility  : "<<gf.spd<<endl;
}

void enBattl(Monster &gf,Monster &en,string enNames[],int floor,bool intro,int &numCho,string data){
    int  pryChnc=0; //Parry Chance
    bool blkLast=1; //Check if player blocked last turn
    gnratEn(en,enNames,floor);
    cout<<"A level "<<en.lvl<<' '<<en.name<<" appeared!";
    cout<<endl<<endl;
    do{
        cout<<gf.name<<"'s health: "<<gf.chp<<endl;
        cout<<en.name<<"'s health: "<<en.chp<<endl;
        cout<<endl;
        cout<<"What will you do?"<<endl<<endl;
        cout<<"1. Attack"<<endl;
        cout<<"2. Block"<<endl;
        cout<<"3. Parry"<<endl;
        cin>>numCho;
        switch(numCho){
            case 1:
                if(gf.spd>en.spd){
                    if(gf.atk>en.def/2){
                        cout<<"You attack and deal "<<gf.atk-en.def/2<<" damage!";
                        cout<<endl;
                        en.chp-=gf.atk-en.def/2;
                    }
                    else{
                        cout<<"You attack and deal 0 damage!";
                        cout<<endl;
                        en.chp-=0;
                    }
                    
                    if(en.atk>gf.def/2&&en.chp>0){
                        cout<<en.name<<" attacks and deals "<<en.atk-gf.def/2
                            <<" damage!";
                        cout<<endl;
                        gf.chp-=en.atk-gf.def/2;
                    }
                    else if(en.atk<gf.def/2&&en.chp>0){
                        cout<<en.name<<" attacks and deals 0 damage!";
                        cout<<endl;
                        gf.chp-=0;
                    }
                    else{
                        cout<<en.name<<" falls to the floor defeated.";
                        cout<<endl;
                    }
                }
                else{
                    if(en.atk>gf.def/2){
                        cout<<en.name<<" attacks and deals "<<en.atk-gf.def/2
                            <<" damage!";
                        cout<<endl;
                        gf.chp-=(en.atk-gf.def/2);
                    }
                    else{
                        cout<<en.name<<" attacks and deals 0 damage!";
                        cout<<endl;
                        gf.chp-=0;
                    }
                    
                    if(gf.atk>en.def/2&&gf.chp>0){
                        cout<<"You attack and deal "<<gf.atk-en.def/2<<" damage!";
                        cout<<endl;
                        en.chp-=gf.atk-en.def/2;
                    }
                    else if(gf.atk<en.def/2&&gf.chp>0){
                        cout<<"You attack and deal 0 damage!";
                        cout<<endl;
                        en.chp-=0;
                    }
                    else{
                        cout<<gf.name<<" falls to the floor defeated.";
                        cout<<endl;
                    }
                }
                blkLast=1;
                break;
            case 2:
                if(blkLast==1){
                    cout<<"You block the enemy's attack!"<<endl;
                    blkLast=0;
                }
                else{
                    cout<<"You failed to block the enemy's attack."<<endl;
                    cout<<"You take "<<en.atk-gf.def/2<<" damage!"<<endl;
                    gf.chp-=en.atk-gf.def/2;
                    blkLast=1;
                    if(gf.chp<=0)cout<<gf.name<<" falls to the floor defeated.";
                    cout<<endl;
                }
                break;
            case 3:
                if(pryChnc==rand()%2){
                    cout<<"Parry successful!"<<endl;
                    cout<<"You dealt "<<(gf.atk*2)<<" damage!"<<endl;
                    en.chp-=(gf.atk*2);
                    if(en.chp<=0)cout<<en.name<<" falls to the floor defeated.";
                    cout<<endl;
                }
                else{
                    cout<<"Parry unsuccessful!"<<endl;
                    cout<<"You take "<<(en.atk*2)<<" damage!"<<endl;
                    gf.chp-=(en.atk*2);
                    if(gf.chp<=0)cout<<gf.name<<" falls to the floor defeated.";
                    cout<<endl;
                }
                blkLast=1;
                break;
            default:
                cout<<"Invalid input!"<<endl;
                break;
        }
    }while(gf.chp>0&&en.chp>0);
    if(gf.chp>0){
        cout<<"You defeated "<<en.name<<'!';
        cout<<endl<<endl;
    }
    else{
        cout<<"After slaying your GMO, "<<en.name<<" slowly turns and fixes its"
            <<endl<<"gaze on you. Looks like this is the end...";
        cout<<endl<<endl;
        cout<<"GAME OVER";
        cout<<endl<<endl;
        do{
            cout<<"What would you like to do?"<<endl;
            cout<<"1. Load Game"<<endl;
            cout<<"2. Quit Game"<<endl;
            cin>>numCho;
            switch(numCho){
                case 1:
                    load(intro,gf,floor,data);
                    cout<<endl;
                    cout<<intro<<endl;
                    cout<<floor<<endl;
                    cout<<gf.name<<endl;
                    cout<<gf.hpt<<endl;
                    cout<<gf.chp<<endl;        
                    cout<<gf.atk<<endl;
                    cout<<gf.def<<endl;
                    cout<<gf.spd<<endl;
                    cout<<gf.mxp<<endl;
                    cout<<gf.cxp<<endl;
                    cout<<gf.lvl<<endl;
                    break;
                case 2:
                    //Exits game upon leaving function
                    break;
                default:
                    cout<<"Invalid input!";
                    cout<<endl;
                    break;
            }
        }while(numCho<1||numCho>2);   
    }
}

void bsBattl(Monster &gf,Monster boss[],int floor,int &numCho){
    int  pryChnc=0; //Parry Chance
    bool blkLast=1; //Check if player blocked last turn
    cout<<"A powerful enemy reveals itself!";
    cout<<endl<<endl;
    cout<<"Name: "<<boss[floor].name<<endl;
    cout<<"Analysis: "<<boss[floor].flvr<<endl;
    do{
        cout<<gf.name<<"'s health: "<<gf.chp<<endl;
        cout<<boss[floor].name<<"'s health: "<<boss[floor].chp<<endl;
        cout<<endl;
        cout<<"What will you do?"<<endl<<endl;
        cout<<"1. Attack"<<endl;
        cout<<"2. Block"<<endl;
        cout<<"3. Parry"<<endl;
        cin>>numCho;
        switch(numCho){
            case 1:
                if(gf.spd>boss[floor].spd){
                    if(gf.atk>boss[floor].def/2){
                        cout<<"You attack and deal "<<gf.atk-boss[floor].def/2<<" damage!";
                        cout<<endl;
                        boss[floor].chp-=gf.atk-boss[floor].def/2;
                    }
                    else{
                        cout<<"You attack and deal 0 damage!";
                        cout<<endl;
                        boss[floor].chp-=0;
                    }
                    
                    if(boss[floor].atk>gf.def/2&&boss[floor].chp>0){
                        cout<<boss[floor].name<<" attacks and deals "<<boss[floor].atk-gf.def/2
                            <<" damage!";
                        cout<<endl;
                        gf.chp-=boss[floor].atk-gf.def/2;
                    }
                    else if(boss[floor].atk<gf.def/2&&boss[floor].chp>0){
                        cout<<boss[floor].name<<" attacks and deals 0 damage!";
                        cout<<endl;
                        gf.chp-=0;
                    }
                    else{
                        cout<<boss[floor].name<<" falls to the floor defeated.";
                        cout<<endl;
                    }
                }
                else{
                    if(boss[floor].atk>gf.def/2){
                        cout<<boss[floor].name<<" attacks and deals "<<boss[floor].atk-gf.def/2
                            <<" damage!";
                        cout<<endl;
                        gf.chp-=(boss[floor].atk-gf.def/2);
                    }
                    else{
                        cout<<boss[floor].name<<" attacks and deals 0 damage!";
                        cout<<endl;
                        gf.chp-=0;
                    }
                    
                    if(gf.atk>boss[floor].def/2&&gf.chp>0){
                        cout<<"You attack and deal "<<gf.atk-boss[floor].def/2<<" damage!";
                        cout<<endl;
                        boss[floor].chp-=gf.atk-boss[floor].def/2;
                    }
                    else if(gf.atk<boss[floor].def/2&&gf.chp>0){
                        cout<<"You attack and deal 0 damage!";
                        cout<<endl;
                        boss[floor].chp-=0;
                    }
                    else{
                        cout<<gf.name<<" falls to the floor defeated.";
                        cout<<endl;
                    }
                }
                blkLast=1;
                break;
            case 2:
                if(blkLast==1){
                    cout<<"You block the enemy's attack!"<<endl;
                    blkLast=0;
                }
                else{
                    cout<<"You failed to block the enemy's attack."<<endl;
                    cout<<"You take "<<boss[floor].atk-gf.def/2<<" damage!"<<endl;
                    gf.chp-=boss[floor].atk-gf.def/2;
                    blkLast=1;
                    if(gf.chp<=0)cout<<gf.name<<" falls to the floor defeated.";
                    cout<<endl;
                }
                break;
            case 3:
                if(pryChnc==rand()%2){
                    cout<<"Parry successful!"<<endl;
                    cout<<"You dealt "<<(gf.atk*2)-boss[floor].def/2<<" damage!"<<endl;
                    boss[floor].chp-=(gf.atk*2)-boss[floor].def/2;
                    if(boss[floor].chp<=0)cout<<boss[floor].name<<" falls to the floor defeated.";
                    cout<<endl;
                }
                else{
                    cout<<"Parry unsuccessful!"<<endl;
                    cout<<"You take "<<(boss[floor].atk*2)-gf.def/2<<" damage!"<<endl;
                    gf.chp-=(boss[floor].atk*2)-boss[floor].def/2;
                    if(gf.chp<=0)cout<<gf.name<<" falls to the floor defeated.";
                    cout<<endl;
                }
                blkLast=1;
                break;
            default:
                cout<<"Invalid input!"<<endl;
                break;
        }
    }while(gf.chp>0&&boss[floor].chp>0);
    if(gf.chp>0){
        if(gf.chp>0){
            cout<<"You defeated "<<boss[floor].name<<'!';
            cout<<endl<<endl;
        }
    }
    else{
        cout<<"After slaying your GMO, "<<boss[floor].name<<" slowly turns and fixes its"
            <<endl<<"gaze on you. Looks like this is the end...";
        cout<<endl<<endl;
        cout<<"GAME OVER";
        cout<<endl<<endl;
        do{
            cout<<"What would you like to do?"<<endl;
            cout<<"1. Load Game"<<endl;
            cout<<"2. Quit Game"<<endl;
            cin>>numCho;
            switch(numCho){
                case 1:
                    //Load Game
                    break;
                case 2:
                    //Exits game upon leaving function
                    break;
                default:
                    cout<<"Invalid input!";
                    cout<<endl;
                    break;
            }
        }while(numCho<1||numCho>2);   
    }
}

void save(bool prog,Monster &gf,int floor,string data){
    ofstream write;
    write.open(data);
    write<<prog<<endl;
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
    write.close();
}

void load(bool prog,Monster &gf,int &floor,string data){
    ifstream read;
    read.open(data);
    getline(read,data);
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
    read.close();
}

void dispTtl(string titl){
    string lines[6];
    ifstream read;
    read.open(titl);
    for(int i=0;i<6;i++){
        getline(read,lines[i]);
    }
    for(int i=0;i<6;i++){
        cout<<lines[i]<<endl;
    }
    read.close();
}