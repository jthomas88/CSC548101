/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month, Day, Year, Time
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <ctime>      //Random number generator
using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    srand(time(NULL));
    //Declaration of variables
    int            answer=(rand()%100)+1;
    short guess;
    short counter=0;
    
    //Input values
    do{
        counter++;
        cout<<answer<<endl;
        cout<<"What number am i thinking of? (1-100) ";
        cin>>guess;
        cout<<endl;
        if(guess>answer){
            cout<<"Too high! Guess again: "<<endl;
        }
        else if(guess<answer){
            cout<<"Too low! Guess again: "<<endl;
        }
        else{
            cout<<"Correct! The answer is "<<answer<<endl;
            if(counter==1){
                cout<<"It took you "<<counter<<" guess."<<endl;
            }
            else{
                cout<<"It took you "<<counter<<" guesses."<<endl;
            }
        }
    }while(guess!=answer);
    
    //Process values -> map inputs to outputs
    
    
    //Display output
    
    
    //Exit program
    return 0;
}

