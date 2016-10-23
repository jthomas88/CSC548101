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
    
    hung=100;
    happ=100;
    warm=100;
    coin=0;
    
    for(int i=15;i>0;i--){
        rndCoin=rand()%100;
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
                cout<<coin;
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
                cout<<"Warmth + 10";
                cout<<endl<<endl;
                
                warm+=20;
                break;
            case 5: 
                //Shopping code
                break;
        }
    }
    
    
    //Exit program
    return 0;
}

