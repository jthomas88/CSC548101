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
void rndEvnt(int&,int&,int&,int&);
void shop(int&,int&,int&,int&);
bool isBroke(int);
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
    //Intro Story
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
    
    //Initialize Variables
    counter=1;
    hung=100;
    happ=100;
    warm=100;
    coin=0;
    
    //Egg Phase
    while(hung>0&&happ>0&&warm>0&&counter<15){
        rndCoin=rand()%100;
        
        //Stats Menu
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
        
        //Choice tree
        switch(choice){
            case 1:
                cout<<"You head out to the streets to panhandle for the day"<<endl;
                cout<<"You made: "<<rndCoin<<" coins"<<endl;
                coin+=rndCoin;
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
                isBroke(coin);
                if(isBroke(coin)==false){
                    cout<<"Insufficient funds! Come back when you have money.";
                    cout<<endl<<endl;
                }
                else{
                    shop(hung,happ,warm,coin);
                }
                break;          
        }
        counter++;
    }
    
    //Check if player can progress to next phase
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
    
    //Larva Phase
    while(hung>0&&happ>0&&warm>0&&counter<40){
        rndCoin=rand()%100;
        
        //Stats Menu
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
        
        //Choice Tree
        switch(choice){
            case 1:
                cout<<"You make a nice profit at your local gambling alley. "
                    <<"Good thing you brought your own dice."<<endl;        
                cout<<"You made: "<<rndCoin<<" coins"<<endl;
                coin+=rndCoin;
                cout<<endl<<endl;
                
                //Trigger random event
                rndEvnt(hung,happ,warm,coin);

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
                
                //Trigger random event
                rndEvnt(hung,happ,warm,coin);

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
                
                //Trigger random event
                rndEvnt(hung,happ,warm,coin);
                
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
                
                //Trigger random event
                rndEvnt(hung,happ,warm,coin);

                warm+=15;
                happ-=10;
                hung-=10;
                break;
            case 5: 
                isBroke(coin);
                if(isBroke(coin)==false){
                    cout<<"Insufficient funds! Come back when you have money.";
                    cout<<endl<<endl;
                }
                else{
                    shop(hung,happ,warm,coin);
                }
                break;
                
        }
        counter++;
    }
    
    //Check if player can progress to the next phase
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
    
    //Adult Phase
    while(hung>0&&happ>0&&warm>0&&counter<100){
        rndCoin=rand()%100;
        
        //Stats Menu
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
        
        //Choice Tree
        switch(choice){
            case 1:
                cout<<"You buy some Disneyland tickets with credit card "
                    <<"information you happened upon and they sell like "<<endl
                    <<"hotcakes!";
                cout<<endl;
                cout<<"You made: "<<rndCoin<<" coins"<<endl;
                coin+=rndCoin;
                cout<<endl<<endl;
                
                //Trigger random event
                rndEvnt(hung,happ,warm,coin);

                warm-=10;
                happ-=10;
                hung-=10;
                break;
            case 2:
                cout<<"You open the back gate and your creature rushes out in "
                    <<"search of food. It returns hours later looking "<<endl
                    <<"satisfied. You look out the window and notice the "
                    <<"skeleton of some kind of large mammal resting against a "
                    <<"tree.";    
                cout<<endl;
                cout<<"Stomach + 15";
                cout<<endl<<endl;
                
                //Trigger random event
                rndEvnt(hung,happ,warm,coin);

                warm-=10;
                happ-=10;
                hung+=15;
                break;
            case 3:
                cout<<"You use your heavy duty steamer to remove the blood "
                    <<"and waste stains from the carpet. ";
                cout<<endl;    
                cout<<"Happiness + 15";
                cout<<endl<<endl;
                
                //Trigger random event
                rndEvnt(hung,happ,warm,coin);
                
                warm-=10;
                happ+=15;
                hung-=10;
                break;
            case 4: 
                cout<<"You drape a heavy blanket over your creature and it "
                    <<"begins to vibrate at a high frequency in order to "
                    <<"generate heat";
                cout<<endl;
                cout<<"Warmth + 15";
                cout<<endl<<endl;
                
                //Trigger random event
                rndEvnt(hung,happ,warm,coin);
                warm+=15;
                happ-=10;
                hung-=10;
                break;
            case 5: 
                isBroke(coin);
                if(isBroke(coin)==false){
                    cout<<"Insufficient funds! Come back when you have money.";
                    cout<<endl<<endl;
                }
                else{
                    shop(hung,happ,warm,coin);
                }
                break;
        }
        counter++;
    }
    
    //Check for GAME OVER
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

//Random Event function
void rndEvnt(int &xhung,int &xhapp,int &xwarm,int &xcoin){
    int rndChoi=rand()%8;
    int rndBuff=(rand()%20)+1;
    switch(rndChoi){
        case 0:
            cout<<endl<<endl;
            cout<<"A bird flies into your apartment through an open window "
                <<"and before you can reach for a broom, your creature "<<endl
                <<"strikes it out of the air and devours it. You are concerned "
                <<"at first but also in awe of how cool it was.";
            cout<<endl<<endl;
            cout<<"Stomach +"<<rndBuff;
            cout<<endl<<endl;
            xhung+=rndBuff;
            //return hung;
            break;
        case 1:
            cout<<endl<<endl;
            cout<<"Your creature passes some time chasing its own tail until "
                <<"it tires itself out.";
            cout<<endl<<endl;
            cout<<"Happiness +"<<rndBuff;
            cout<<endl<<endl;
            xhapp+=rndBuff;
            //return happ;
            break;
        case 2:
            cout<<endl<<endl;
            cout<<"The sun peers in perfectly through your living room window "
                <<"allowing your creature to bask in the sunlight for a "<<endl
                <<"little while. ";
            cout<<endl<<endl;
            cout<<"Warmth +"<<rndBuff;
            cout<<endl<<endl;
            xwarm+=rndBuff;
            //return warm;
            break;
        case 3:
            cout<<endl<<endl;
            cout<<"Lucky day! A poor sap was walking home alone while you "
                <<"waited in the alleyway you frequently hang out in. "<<endl
                <<"You mug them and it goes off without a hitch. ";
            cout<<endl<<endl;
            cout<<"Coins +"<<rndBuff;
            cout<<endl<<endl;
            xcoin+=rndBuff;
            //return coin;
            break;
        case 4:
            cout<<endl<<endl;
            cout<<"Your creature undergoes a molting phase and grows quite "
                <<"a bit. The process puts stress on its body and uses "<<endl
                <<"a lot of energy. ";
            cout<<endl<<endl;
            cout<<"Stomach -"<<rndBuff;
            cout<<endl<<endl;
            xhung-=rndBuff;
            //return hung;
            break;
        case 5:
            cout<<endl<<endl;
            cout<<"The day seems to drag by for your creature as you see it "
                <<"pacing back and forth in its pen. it seems to be very bored";
            cout<<endl<<endl;
            cout<<"Happiness -"<<rndBuff;
            cout<<endl<<endl;
            xhapp-=rndBuff;
            //return happ;
            break;
        case 6:
            cout<<endl<<endl;
            cout<<"You forget to lay a blanket down for your friend before nap "
                <<"time and return to the living room hours later to "<<endl
                <<"discover that it's been shivering. Poor thing... ";
            cout<<endl<<endl;
            cout<<"Warmth -"<<rndBuff;
            cout<<endl<<endl;
            xwarm-=rndBuff;
            //return warm;
            break;
        case 7:
            cout<<endl<<endl;
            cout<<"Your gambling habit got a bit out of hand tonight and you "
                <<"return home not just emptyhanded but with a net loss. ";
            cout<<endl<<endl;
            cout<<"Coin -"<<rndBuff;
            cout<<endl<<endl;
            xcoin-=rndBuff;
            //return coin;
            break;
    }
}

//Shop Function
void shop(int &xhung,int &xhapp, int &xwarm, int &xcoin){
    int choice;
    cout<<"Select an item for purchase";
    cout<<endl;
    cout<<"All items are 100 coins each.";
    cout<<endl;
    cout<<endl<<"1) Bag of Mice"
        <<endl<<"2) Dog Toy"
        <<endl<<"3) 10 pack of hand warmers"
        <<endl;
    cin>>choice;
    switch(choice){
        case 1:
            cout<<endl;
            cout<<"You purchase a bag of mice and throw it in the creature's"
                <<"pen. It slowly approaches the bag and proceeds to rip "
                <<endl<<"the bag to shreds and devour its contents.";
            cout<<endl;
            cout<<"Stomach +50";
            cout<<endl<<endl;
            xcoin-=100;
            xhung+=50;
            break;
        case 2:
            cout<<endl;
            cout<<"You purchase a dog toy and throw it in the creature's"
                <<"pen. It is confused at first but eventually gets the hang "
                <<endl<<"of it and it continues playing with it for the rest "
                <<"of the day.";    
            cout<<endl;
            cout<<"Happiness +50";
            cout<<endl<<endl;
            xcoin-=100;
            xhapp+=50;
            break;
        case 3:
            cout<<endl;
            cout<<"You purchase a 10 pk of hand warmers and throw it in the "
                <<"creature's pen. It nuzzles itself against the activated "
                <<endl<<"hand warmers until the heat slowly fades away.";
            cout<<endl;
            cout<<"Warmth +50";
            cout<<endl<<endl;
            xcoin-=100;
            xwarm+=50;
            break;
    }
}

//Budget Function
bool isBroke(int xcoin){
    return xcoin/100;
}