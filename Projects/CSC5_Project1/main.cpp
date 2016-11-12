/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 22, 2016, 09:32 PM
 * Purpose: Raise a mysterious creature to adulthood
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>   //Format text
#include <fstream>   //File input and output

using namespace std; //Namespace used in system library

//User libraries

//Global constants
int const SIZE=11;

//Function prototypes

//Menu Functions
void opt1Coin(int&,int&,int&,int&,int,int,int);
void opt2Hung(int&,int&,int&,int,int,int);
void opt3Happ(int&,int&,int&,int,int,int);
void opt4Warm(int&,int&,int&,int,int,int);
void opt5Shop(int&,int&,int&,int&,string);

//Other Functions
bool isBroke(int); //Checks if user has enough money to go to the store
void rndEvnt(int&,int&,int&,int&,string); //Random event generator

//Execution begins here
int main(int argc, char** argv) 
{
    //Random Number Seed
    srand(time(NULL));
    //Declaration of variables    
    char           choice;  //Used to choose options within the game
    int            rndCoin; //Number of coins earned
    int            coin;    //Held coins   
    int            hung,    //Creature hunger rating
                   happ,    //Creature happiness rating    
                   warm;    //Creature warmth rating
    unsigned short counter; //Counts number of days
    string         ctrName; //Name of the creature
    
    int            hungInc, //Rate of increase for hunger
                   happInc, //Rate of increase for happiness
                   warmInc; //Rate of increase for warmth
    int            hungDec, //Rate of decrease for hunger
                   happDec, //Rate of decrease for happiness
                   warmDec; //Rate of decrease for warmth
    
    int stats[SIZE]={};
    
    
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
    cout<<"Please give your little friend a name: ";
    cin>>ctrName;
    cout<<endl;
    
    //Initialize Variables
    counter=1;
    coin=0;
    hung=100;  happ=100;   warm=100;
    hungInc=0; happInc=10; warmInc=20;
    hungDec=0; happDec=0;  warmDec=10;
    
    
    
    
    //Egg Phase
    
    //Continues looping as long as stats remain above 0 and ends when counter
    //reaches 15
    while(hung>0&&happ>0&&warm>0&&counter<15){      
        //Stats Menu
        cout<<"Day      : "<<counter<<endl;
        cout<<"Stomach  : "<<hung<<endl;
        cout<<"Happiness: "<<happ<<endl;
        cout<<"Warmth   : "<<warm<<endl;
        cout<<"Money    : "<<coin<<" coins"<<endl;
        cout<<endl;
        //Ask for input
        cout<<"What would you like to do?"<<endl;
        cout<<"1) Make Money"<<endl
            <<"2) Feed "<<ctrName<<endl
            <<"3) Clean Pen"<<endl
            <<"4) Cuddle"<<endl
            <<"5) Go shopping"<<endl;    
        cin>>choice;
        cout<<endl;        
        //Input Validation
        while(choice>54||choice<49){ //ASCII 1-6 has value of 49-53
            cout<<"Invalid choice!";
            cout<<endl;
            cout<<"Day      : "<<counter<<endl;
            cout<<"Stomach  : "<<hung<<endl;
            cout<<"Happiness: "<<happ<<endl;
            cout<<"Warmth   : "<<warm<<endl;
            cout<<"Money    : "<<coin<<" coins"<<endl;
            cout<<endl;
            cout<<"What would you like to do?"<<endl;
            cout<<"1) Make Money"<<endl
                <<"2) Feed "<<ctrName<<endl
                <<"3) Clean Pen"<<endl
                <<"4) Cuddle"<<endl
                <<"5) Go shopping"<<endl;    
            cin>>choice;
            cout<<endl;
        }
        //Choice tree
        switch((choice%49)+1){ //Branching for different options
            case 1: //"Make money" branch
                cout<<"You head out to the streets to panhandle for the day";
                cout<<endl;
                opt1Coin(coin,hung,happ,warm,hungDec,happDec,warmDec);
                break;
            case 2: //"Feed" branch
                cout<<"Try as you might, you can't seem to find a way to feed "
                    <<ctrName<<". Now must not be a good time..."<<endl;
                opt2Hung(hung,happ,warm,hungInc,happDec,warmDec);
                break;
            case 3: //"Clean pen" branch
                cout<<"You spend some time cleaning up the dust in and around "
                    <<"the pen. This thing makes quite a mess for simply being "
                    <<"an egg."<<endl;
                opt3Happ(hung,happ,warm,hungDec,happInc,warmDec);
                break;
            case 4: //"Cuddle" branch
                cout<<"You've grown attached to the egg you've invested all "
                    <<"this time in and decide to spend the rest of the day "
                    <<"cuddling with your new friend."<<endl;
                opt4Warm(hung,happ,warm,hungDec,happDec,warmInc);
                break;
            case 5: //"Go shopping" branch
                isBroke(coin); //Test is user has sufficient funds
                if(isBroke(coin)==false){ //Output insufficient funds message
                    cout<<"Insufficient funds! Come back when you have money.";
                    cout<<endl<<endl;
                }
                else{ //Enter store if funds are sufficient
                    opt5Shop(hung,happ,warm,coin,ctrName); //Call shop function
                }
                break;
            case 6: //"Save and exit" branch
                for(int i=0;i<SIZE;i++){
                    
                }
                fstream save;
                save.open("load.dat");
                save<<stats[];
                save.close();
                return 0;
        }
        counter++; //Increase counter by 1
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
            <<"that "<<ctrName<<" is blind.";
        cout<<endl<<endl;
        cout<<ctrName<<" HAS BEGUN ITS LARVA STAGE.";
        cout<<endl<<endl;
        happ-=50; //Reduces happiness by 50 (artificial difficulty)
    }
    
    //Change stat increases and decreases (for normal game)
    if(ctrName!="harambe"||ctrName!="leviathan"||ctrName!="eeyore"){
        hungInc=15; happInc=15; warmInc=15;
        hungDec=10; happDec=10; warmDec=10;
    }
    
    //Larva Phase
    
    //Continues looping as long as stats remain above 0 and ends when counter
    //reaches 40
    while(hung>0&&happ>0&&warm>0&&counter<40){
        rndCoin=rand()%100; //Initialize random money generator 
        
        //Stats Menu
        cout<<"Day      : "<<counter<<endl;
        cout<<"Stomach  : "<<hung<<endl;
        cout<<"Happiness: "<<happ<<endl;
        cout<<"Warmth   : "<<warm<<endl;
        cout<<"Money    : "<<coin<<" coins"<<endl;
        cout<<endl;
        //Ask for input
        cout<<"What would you like to do?"<<endl;
        cout<<"1) Make Money"<<endl
            <<"2) Feed "<<ctrName<<endl
            <<"3) Clean Pen"<<endl
            <<"4) Cuddle"<<endl
            <<"5) Go shopping"<<endl;    
        cin>>choice;
        cout<<endl;
        
        //Input Validation
        while(choice>53||choice<49){
            cout<<"Invalid choice!";
            cout<<endl;
            cout<<"Day      : "<<counter<<endl;
            cout<<"Stomach  : "<<hung<<endl;
            cout<<"Happiness: "<<happ<<endl;
            cout<<"Warmth   : "<<warm<<endl;
            cout<<"Money    : "<<coin<<" coins"<<endl;
            cout<<endl;
            cout<<"What would you like to do?"<<endl;
            cout<<"1) Make Money"<<endl
                <<"2) Feed "<<ctrName<<endl
                <<"3) Clean Pen"<<endl
                <<"4) Cuddle"<<endl
                <<"5) Go shopping"<<endl;    
            cin>>choice;
            cout<<endl;
        }
        
        //Choice Tree
        switch((choice%49)+1){
            case 1: //"Make money" branch
                cout<<"You make a nice profit at your local gambling alley. "
                    <<"Good thing you brought your own dice."<<endl;        
;
                opt1Coin(coin,hung,happ,warm,hungDec,happDec,warmDec);
                
                //Trigger random event
                rndEvnt(hung,happ,warm,coin,ctrName);
                
                break;
            case 2: //"Feed" branch
                cout<<"You place a dead rabbit into the pen with a large stick. "
                    <<ctrName<<" devours it whole with its gaping maw."
                    <<endl;
                opt2Hung(hung,happ,warm,hungInc,happDec,warmDec);
                
                //Trigger random event
                rndEvnt(hung,happ,warm,coin,ctrName);
                
                break;
            case 3: //"Clean pen" branch
                cout<<"You spend some time cleaning up the dirt and waste "
                    <<"that "<<ctrName<<" accumulates in its living space. "
                    <<"You do your best to ignore the screeches it "<<endl
                    <<"emits when you clean up its precious garbage pile.";
                cout<<endl;    
                
                opt3Happ(hung,happ,warm,hungDec,happInc,warmDec);;
                
                //Trigger random event
                rndEvnt(hung,happ,warm,coin,ctrName);
                
                break;
            case 4: //"Cuddle" branch
                cout<<"You swaddle "<<ctrName<<" in a special chainmail "
                    <<"blanket to avoid getting bitten and spend some time "
                    <<"cuddling with it."<<endl;
                
                opt4Warm(hung,happ,warm,hungDec,happDec,warmInc);
                
                //Trigger random event
                rndEvnt(hung,happ,warm,coin,ctrName);

                break;
            case 5: //"Go shopping" branch
                isBroke(coin); //Test is user has sufficient funds
                if(isBroke(coin)==false){ //Output insufficient funds message
                    cout<<"Insufficient funds! Come back when you have money.";
                    cout<<endl<<endl;
                }
                else{ //Enter store if funds are sufficient
                    opt5Shop(hung,happ,warm,coin,ctrName); //Call shop function
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
        cout<<ctrName<<" has matured quite a bit in these past 40 days and "
            <<"you're quite proud of it. You can't help but wonder "<<endl
            <<"though if any more issues lie ahead.";                
        cout<<endl<<endl;
        cout<<ctrName<<" HAS BEGUN ITS ADULTHOOD STAGE.";
        cout<<endl<<endl;
    }
    
    //Adult Phase
    
    //Continues looping as long as stats remain above 0 and ends when counter
    //reaches 100
    while(hung>0&&happ>0&&warm>0&&counter<100){
        rndCoin=rand()%100;
        
        //Stats Menu
        cout<<"Day      : "<<counter<<endl;
        cout<<"Stomach  : "<<hung<<endl;
        cout<<"Happiness: "<<happ<<endl;
        cout<<"Warmth   : "<<warm<<endl;
        cout<<"Money    : "<<coin<<" coins"<<endl;
        cout<<endl;
        //Ask for input
        cout<<"What would you like to do?"<<endl;
        cout<<"1) Make Money"<<endl
            <<"2) Feed "<<ctrName<<endl
            <<"3) Clean Pen"<<endl
            <<"4) Cuddle"<<endl
            <<"5) Go shopping"<<endl;    
        cin>>choice;
        cout<<endl;
        
        //Input Validation
        while(choice>53||choice<49){
            cout<<"Invalid choice!";
            cout<<endl;
            cout<<"Day      : "<<counter<<endl;
            cout<<"Stomach  : "<<hung<<endl;
            cout<<"Happiness: "<<happ<<endl;
            cout<<"Warmth   : "<<warm<<endl;
            cout<<"Money    : "<<coin<<" coins"<<endl;
            cout<<endl;
            cout<<"What would you like to do?"<<endl;
            cout<<"1) Make Money"<<endl
                <<"2) Feed "<<ctrName<<endl
                <<"3) Clean Pen"<<endl
                <<"4) Cuddle"<<endl
                <<"5) Go shopping"<<endl;    
            cin>>choice;
            cout<<endl;
        }
        //Choice Tree
        switch((choice%49)+1){
            case 1: //"Make money" branch
                cout<<"You buy some Disneyland tickets with credit card "
                    <<"information you happened upon and they sell like "<<endl
                    <<"hotcakes!";
                cout<<endl;
                        
                opt1Coin(coin,hung,happ,warm,hungDec,happDec,warmDec);
                
                //Trigger random event
                rndEvnt(hung,happ,warm,coin,ctrName);

                break;
            case 2: //"Feed" branch
                cout<<"You open the back gate and "<<ctrName<<" rushes out in "
                    <<"search of food. It returns hours later looking "<<endl
                    <<"satisfied. You look out the window and notice the "
                    <<"skeleton of some kind of large mammal resting against a "
                    <<"tree.";    
                cout<<endl;
                
                opt2Hung(hung,happ,warm,hungInc,happDec,warmDec);
                
                //Trigger random event
                rndEvnt(hung,happ,warm,coin,ctrName);

                break;
            case 3: //"Clean pen" branch
                cout<<"You use your heavy duty steamer to remove the blood "
                    <<"and waste stains from the carpet. ";
                cout<<endl;    
                
                opt3Happ(hung,happ,warm,hungDec,happInc,warmDec);
                
                //Trigger random event
                rndEvnt(hung,happ,warm,coin,ctrName);
                
                break;
            case 4: 
                cout<<"You drape a heavy blanket over "<<ctrName<<" and it "
                    <<"begins to vibrate at a high frequency in order to "
                    <<"generate heat";
                cout<<endl;
                
                opt4Warm(hung,happ,warm,hungDec,happDec,warmInc);
                
                //Trigger random event
                rndEvnt(hung,happ,warm,coin,ctrName);

                break;
            case 5: 
                isBroke(coin); //Test is user has sufficient funds
                if(isBroke(coin)==false){ //Output insufficient funds message
                    cout<<"Insufficient funds! Come back when you have money.";
                    cout<<endl<<endl;
                }
                else{ //Enter store if funds are sufficient
                    opt5Shop(hung,happ,warm,coin,ctrName); //Call shop function
                }
                break;
        }
        counter++; //Increase counter by 1
    }
    
    //Check if player has won
    if(hung>0&&happ>0&&warm>0){
        cout<<"Just like any other day, you wake up and prepare to take care "
            <<"of "<<ctrName<<". However, it sounds far too quiet. Normally, "
            <<endl<<"you wake up to the sounds of high pitched screeches or "
            <<"the sound of a bird getting attacked. You peek around the "
            <<"corner and find your wall has a massive hole. Could it have "
            <<endl<<"actually dome this much damage?";
        cout<<endl<<endl;
        cout<<"You inspect further and you find a letter addressed to you "
            <<"sitting in a wedge on the makeshift pen. The letter reads: ";
        cout<<endl<<endl;
        cout<<"Dearest Friend, "<<endl<<endl<<setw(15);
        cout<<"I've discovered true compassion in being raised by you. While "
            <<"you may have been a "<<endl<<"degenerate, you were my friend."
            <<"I'm afraid I must leave now. My motherland calls me.";
        cout<<endl;
        cout<<"Take Care, ";
        cout<<endl;
        cout<<setw(10)<<ctrName;
    }
    
    //Check for GAME OVER
    if(hung<=0||happ<=0||warm<=0){
        cout<<"You awaken one morning to discover something terrible.";
        cout<<"You little buddy appears to be laying still in the center of "
            <<endl<<"the pen shriveled up. It's far too late to do anything "
            <<"for it now";    
        cout<<endl<<endl;
        cout<<"GAME OVER";
        return 0; //End program
    }       
    
    //Exit program
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Random Event Generator   *************************
//Purpose:  Output a random event that changes course of game
//Inputs:   Inputs to the function here -> Description, Range, Units
//  xhung->Current hunger level
//  xhapp->Current happiness level
//  xwarm->Current warmth level
//  xcoin->Current coin level
//  name ->Creature's name
//Output:   This is a void function. It changes the above values but does not
//          output them
//******************************************************************************
void rndEvnt(int &xhung,int &xhapp,int &xwarm,int &xcoin,string name){
    int rndChoi=rand()%8;      //Variable will output a random number 0-7
    int rndBuff=(rand()%20)+1; //Provide random increase/decrease
    switch(rndChoi){ //Selects random branch
        case 0: //Increase stomach
            cout<<endl<<endl;
            cout<<"A bird flies into your apartment through an open window "
                <<"and before you can reach for a broom, "<<name<<endl
                <<"strikes it out of the air and devours it. You are concerned "
                <<"at first but also in awe of how cool it was.";
            cout<<endl;
            cout<<"Stomach + "<<rndBuff;
            cout<<endl<<endl;
            xhung+=rndBuff;       
            break;
        case 1: //Increase happiness
            cout<<endl<<endl;
            cout<<name<<" passes some time chasing its own tail until "
                <<"it tires itself out.";
            cout<<endl;
            cout<<"Happiness + "<<rndBuff;
            cout<<endl<<endl;
            xhapp+=rndBuff;          
            break;
        case 2: //Increase warmth
            cout<<endl<<endl;
            cout<<"The sun peers in perfectly through your living room window "
                <<"allowing "<<name<<" to bask in the sunlight for a "<<endl
                <<"little while. ";
            cout<<endl;
            cout<<"Warmth + "<<rndBuff;
            cout<<endl<<endl;
            xwarm+=rndBuff;          
            break;
        case 3: //Increase money
            cout<<endl<<endl;
            cout<<"Lucky day! A poor sap was walking home alone while you "
                <<"waited in the alleyway you frequently hang out in. "<<endl
                <<"You mug them and it goes off without a hitch. ";
            cout<<endl;
            cout<<"Coins + "<<rndBuff;
            cout<<endl<<endl;
            xcoin+=rndBuff;           
            break;
        case 4: //Decrease stomach
            cout<<endl<<endl;
            cout<<name<<" undergoes a molting phase and grows quite "
                <<"a bit. The process puts stress on its body and uses "<<endl
                <<"a lot of energy. ";
            cout<<endl;
            cout<<"Stomach - "<<rndBuff;
            cout<<endl<<endl;
            xhung-=rndBuff;           
            break;
        case 5: //Decrease happiness
            cout<<endl<<endl;
            cout<<"The day seems to drag by for "<<name<<" as you see it "
                <<"pacing back and forth in its pen. It seems to be very bored";
            cout<<endl;
            cout<<"Happiness - "<<rndBuff;
            cout<<endl<<endl;
            xhapp-=rndBuff;           
            break;
        case 6: //Decrease warmth
            cout<<endl<<endl;
            cout<<"You forget to lay a blanket down for "<<name<<" before nap "
                <<"time and return to the living room hours later to "<<endl
                <<"discover that it's been shivering. Poor thing... ";
            cout<<endl;
            cout<<"Warmth - "<<rndBuff;
            cout<<endl<<endl;
            xwarm-=rndBuff;           
            break;
        case 7: //Decrease money
            cout<<endl<<endl;
            cout<<"Your gambling habit got a bit out of hand tonight and you "
                <<"return home not just emptyhanded but with a net loss. ";
            cout<<endl;
            cout<<"Coin - "<<rndBuff;
            cout<<endl<<endl;
            xcoin-=rndBuff;           
            break;
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//***************************   Sufficient Funds   *****************************
//Purpose:  Determine if user has enough money to enter the shop
//Inputs:   Inputs to the function here -> Description, Range, Units
//  xcoin->Current coin level
//Output:   True(If user has enough money) or False(If user does not)
//******************************************************************************
bool isBroke(int xcoin){
    return xcoin/100; //Return 0 or 1+ depending on amt of money
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//********************************   Make Money   ******************************
//Purpose:  Handle stat changes for "make money" option
//Inputs:   Inputs to the function here -> Description, Range, Units
//  xhung->Current hunger level
//  xhapp->Current happiness level
//  xwarm->Current warmth level
//  xcoin->Current coin level
//  name ->Creature's name
//Output:   This is a void function. It changes the above values but does not
//          output them
//******************************************************************************
void opt1Coin(int &xcoin,int &xhung,int &xhapp,int &xwarm,
          int hungDec,int happDec,int warmDec){
    int rndCoin=rand()%100;
    
    cout<<"You made: "<<rndCoin<<" coins"<<endl;
    xcoin+=rndCoin; //Adds coins to total
    cout<<endl<<endl;

    xhung-=hungDec; //Reduce hunger by hunger decrease factor
    xhapp-=happDec; //Reduce happiness by happiness decrease factor
    xwarm-=warmDec; //Reduce warmth by warmth decrease factor
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//**********************************   Feed   **********************************
//Purpose:  Handle stat changes for "make money" option
//Inputs:   Inputs to the function here -> Description, Range, Units
//  xhung->Current hunger level
//  xhapp->Current happiness level
//  xwarm->Current warmth level
//  xcoin->Current coin level
//  name ->Creature's name
//Output:   This is a void function. It changes the above values but does not
//          output them
//******************************************************************************
void opt2Hung(int &xhung,int &xhapp,int &xwarm,
        int hungInc,int happDec,int warmDec){
    cout<<"Stomach + "<<hungInc;
    xhung+=hungInc;
    cout<<endl<<endl;

    xhapp-=happDec; //Reduce happiness by happiness decrease factor
    xwarm-=warmDec; //Reduce warmth by warmth decrease factor
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//**********************************   Feed   **********************************
//Purpose:  Handle stat changes for "make money" option
//Inputs:   Inputs to the function here -> Description, Range, Units
//  xhung->Current hunger level
//  xhapp->Current happiness level
//  xwarm->Current warmth level
//  xcoin->Current coin level
//  name ->Creature's name
//Output:   This is a void function. It changes the above values but does not
//          output them
//******************************************************************************
void opt3Happ(int &xhung,int &xhapp,int &xwarm,
          int hungDec,int happInc,int warmDec){
    cout<<"Happiness + "<<happInc;
    xhapp+=happInc;
    cout<<endl<<endl;

    xhung-=hungDec; //Reduce happiness by happiness decrease factor
    xwarm-=warmDec; //Reduce warmth by warmth decrease factor
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//**********************************   Feed   **********************************
//Purpose:  Handle stat changes for "make money" option
//Inputs:   Inputs to the function here -> Description, Range, Units
//  xhung->Current hunger level
//  xhapp->Current happiness level
//  xwarm->Current warmth level
//  xcoin->Current coin level
//  name ->Creature's name
//Output:   This is a void function. It changes the above values but does not
//          output them
//******************************************************************************
void opt4Warm(int &xhung,int &xhapp,int &xwarm,
          int hungDec,int happDec,int warmInc){
    cout<<"Warmth + "<<warmInc;
    xwarm+=warmInc;
    cout<<endl<<endl;

    xhung-=hungDec; //Reduce happiness by happiness decrease factor
    xhapp-=happDec; //Reduce warmth by warmth decrease factor
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*******************************   Shop   ************************************
//Purpose:  Handle all shop functions (purchase, buff creature)
//Inputs:   Inputs to the function here -> Description, Range, Units
//  xhung->Current hunger level
//  xhapp->Current happiness level
//  xwarm->Current warmth level
//  xcoin->Current coin level
//  name ->Creature's name
//Output:   This is a void function. It changes the above values but does not
//          output them
//******************************************************************************
void opt5Shop(int &xhung,int &xhapp, int &xwarm, int &xcoin,string name){
    
    char choice; //User choice
    //Ask for input
    cout<<"Select an item for purchase";
    cout<<endl;
    cout<<"All items are 100 coins each.";
    cout<<endl;
    cout<<endl<<"1) Bag of Mice"
        <<endl<<"2) Dog Toy"
        <<endl<<"3) 10 pack of hand warmers"
        <<endl;
    cin>>choice;
    //Input validation
    while(choice>51||choice<49){
        cout<<"Invalid choice!";
        cout<<endl;
        cout<<"Select an item for purchase";
        cout<<endl;
        cout<<"All items are 100 coins each.";
        cout<<endl;
        cout<<endl<<"1) Bag of Mice"
            <<endl<<"2) Dog Toy"
            <<endl<<"3) 10 pack of hand warmers"
            <<endl;
        cin>>choice;
    }
    switch((choice%49)+1){ //Selects item based on user choice
        case 1: //Bag of mice branch
            cout<<endl;
            cout<<"You purchase a bag of mice and throw it in "<<name<<"'s "
                <<"pen. It slowly approaches the bag and proceeds to rip "
                <<endl<<"the bag to shreds and devour its contents.";
            cout<<endl;
            cout<<"Stomach +50";
            cout<<endl<<endl;
            xcoin-=100; //Reduce coin by 100
            xhung+=50;  //Increase stomach by 50
            break;
        case 2: //Dog toy branch
            cout<<endl;
            cout<<"You purchase a dog toy and throw it in "<<name<<"'s "
                <<"pen. It is confused at first but eventually gets the hang "
                <<endl<<"of it and it continues playing with it for the rest "
                <<"of the day.";    
            cout<<endl;
            cout<<"Happiness +50";
            cout<<endl<<endl;
            xcoin-=100; //Reduce coin by 100
            xhapp+=50;  //Increase happiness by 50
            break;
        case 3: //10 pack of hand warmers branch
            cout<<endl;
            cout<<"You purchase a 10 pk of hand warmers and throw it in "
                <<name<<"'s pen. It nuzzles itself against the activated "
                <<endl<<"hand warmers until the heat slowly fades away.";
            cout<<endl;
            cout<<"Warmth +50";
            cout<<endl<<endl;
            xcoin-=100; //Decrease coin by 100
            xwarm+=50;  //Increase warmth by 50
            break;
    }
}