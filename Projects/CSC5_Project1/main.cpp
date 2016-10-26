/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 22, 2016, 09:32 PM
 * Purpose: Raise a mysterious creature to adulthood
 */

//System Libraries
#include <iostream>  //Input/Output objects

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
void egg(int,int,int,int,int,int);
void storeData(int,int,int,int,int);
//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    srand(time(NULL));
    int rndCoin; //Number of coins earned
    int    coin; //Held coins
    int  choice; //Used to choose options within the game
    int    hung, //Creature hunger rating
           happ, //Creature happiness rating    
           warm; //Creature warmth rating
    int counter; //Counts number of days
    
    //Game Start
    cout<<"After a night of heavy drinking, you wake up as you would any other "
        <<"afternoon. You stumble into the kitchen with a splitting headache "
        <<endl<<"and search for alka-seltzer and something greasy to soothe "
        <<"your hangover. As you try to pop your Jimmy Dean breakfast sandwich "
        <<endl<<"into the microwave, you notice there is something inside.";
    cout<<endl<<endl;
    cout<<"It appears to be a large spotted egg. While you have no idea where "
        <<"it came from, you are curious to see what may come of it. ";
    cout<<endl<<"You spend the rest of the day building a pen out of leftover "
        <<"plywood and chicken wire in the middle of your apartment.";    
    cout<<endl<<endl;        
    
    counter=1;
    hung=100;
    happ=100;
    warm=100;
    coin=0;
    
    while(hung>0&&happ>0&&warm>0&&counter<15){
        rndCoin=rand()%100;
        cout<<"Day      : "<<counter<<endl;
        cout<<"Stomach  : "<<hung<<endl;
        cout<<"Happiness: "<<happ<<endl;
        cout<<"Warmth   : "<<warm<<endl;
        cout<<"Money    : "<<coin<<" coins"<<endl;
        cout<<endl;
        cout<<"What would you like to do?"<<endl;
        cout<<"1) Make Money"<<endl
            <<"2) Feed creature"<<endl
            <<"3) Clean Pen"<<endl
            <<"4) Cuddle"<<endl
            <<"5) Go shopping"<<endl;    
        cin>>choice;
        cout<<endl;
        switch(choice){
            case 1:
                cout<<"You head out to the streets to panhandle for the day"<<endl;
                cout<<"You made: "<<rndCoin<<" coins"<<endl;
                coin+=rndCoin;
                //cout<<coin;
                cout<<endl<<endl;

                warm-=10;
                break;
            case 2:
                cout<<"Try as you might, you can't seem to find a way to feed "
                    <<"the egg. Now must not be a good time..."<<endl;
                cout<<"Stomach + 0";
                cout<<endl<<endl;

                warm-=10;
                break;
            case 3:
                cout<<"You spend some time cleaning up the dust in and around "
                    <<"the pen. This thing makes quite a mess for simply being "
                    <<"an egg."<<endl;
                cout<<"Happiness + 10";
                cout<<endl<<endl;

                happ+=10;
                warm-=10;
                break;
            case 4: 
                cout<<"You've grown attached to the egg you've invested all "
                    <<"this time in and decide to spend the rest of the day "
                    <<"cuddling with your new friend."<<endl;
                cout<<"Warmth + 20";
                cout<<endl<<endl;

                warm+=20;
                break;
            case 5: 
                //Shopping code
                break;          
        }
        counter++;
    }
    
    if(hung>0&&happ>0&&warm>0){
        cout<<endl<<endl;
        cout<<"You awaken one morning to a rustling in your living room. "
            <<"Fearful that it may be a vagrant who's broken in, "<<endl
            <<"you pull your baseball bat out from under your bed and creep "
            <<"your way toward the living room. You enter to discover "<<endl
            <<"eggshell pieces all over the floor and a small reptilian "
            <<"creature skittering around the floor repeatedly "<<endl
            <<"bumping its head against the walls of the pen.";
        cout<<endl<<endl;
        cout<<"You're happy that the egg has finally hatched, but it seems "
            <<"that your friend is blind.";
        cout<<endl<<endl;
        cout<<"YOUR CREATURE HAS BEGUN ITS LARVA STAGE.";
        cout<<endl<<endl;
        happ-=50;
    }
    
    while(hung>0&&happ>0&&warm>0&&counter<40){
        rndCoin=rand()%100;
        cout<<"Day      : "<<counter<<endl;
        cout<<"Stomach  : "<<hung<<endl;
        cout<<"Happiness: "<<happ<<endl;
        cout<<"Warmth   : "<<warm<<endl;
        cout<<"Money    : "<<coin<<" coins"<<endl;
        cout<<endl;
        cout<<"What would you like to do?"<<endl;
        cout<<"1) Make Money"<<endl
            <<"2) Feed creature"<<endl
            <<"3) Clean Pen"<<endl
            <<"4) Cuddle"<<endl
            <<"5) Go shopping"<<endl;    
        cin>>choice;
        cout<<endl;
        switch(choice){
            case 1:
                cout<<"You head out to the streets to panhandle for the day"<<endl;
                cout<<"You made: "<<rndCoin<<" coins"<<endl;
                coin+=rndCoin;
                cout<<endl<<endl;

                warm-=10;
                happ-=10;
                hung-=10;
                break;
            case 2:
                cout<<"You place a dead rabbit into the pen with a large stick. "
                    <<"The creature devours it whole with its gaping maw."
                    <<endl;
                cout<<"Stomach + 15";
                cout<<endl<<endl;

                warm-=10;
                happ-=10;
                hung+=15;
                break;
            case 3:
                cout<<"You spend some time cleaning up the dirt and waste "
                    <<"that the creature accumulates in its living space. "
                    <<"You do your best to ignore the screeches it "<<endl
                    <<"emits when you clean up its precious garbage pile.";
                cout<<endl;    
                cout<<"Happiness + 15";
                cout<<endl<<endl;
                
                warm-=10;
                happ+=15;
                hung-=10;
                break;
            case 4: 
                cout<<"You swaddle the creature in a special chainmail blanket "
                    <<"to avoid getting bitten and spend some time cuddling "
                    <<"with it."<<endl;
                cout<<"Warmth + 15";
                cout<<endl<<endl;

                warm+=15;
                happ-=10;
                hung-=10;
                break;
            case 5: 
                //Shopping code
                break;
                
        }
        counter++;
    }
    
    if(hung>0&&happ>0&&warm>0){
        cout<<endl<<endl;
        cout<<"Through this tumultuous month of caring for an infant monster, "
            <<"you began questioning your will to live. However, it "<<endl    
            <<"seems things may finally start getting a little easier. "
            <<"It doesn't scream nearly as much as it used to, it began "<<endl
            <<"walking on its hind legs, and it's finally house trained!";    
        cout<<endl<<endl;
        cout<<"Your friend has matured quite a bit in these past 40 days and "
            <<"you're quite proud of it. You can't help but wonder "<<endl
            <<"though if any more issues lie ahead.";                
        cout<<endl<<endl;
        cout<<"YOUR CREATURE HAS BEGUN ITS ADULTHOOD STAGE.";
        cout<<endl<<endl;
    }
    
    if(hung<=0||happ<=0||warm<=0){
        cout<<"You awaken one morning to discover something terrible.";
        cout<<"You little buddy appears to be laying still in the center of "
            <<endl<<"the pen shriveled up. It's far too late to do anything "
            <<"for him now";    
        cout<<endl<<endl;
        cout<<"GAME OVER";
        return 0;
    }    
    
    
    //Exit program
    return 0;
}

