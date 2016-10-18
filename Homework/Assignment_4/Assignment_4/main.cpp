/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 17, 2016, 7:10 PM
 * Purpose: Assignment 4
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>   //Utilized for table and precision manipulation
#include <ctime>     //Random number generator

using namespace std; //Namespace used in system library

//User libraries

//Global constants
float KMTOMIL=0.6214; //KM to mile conversion
char  PERCENT=100;    //Percent conversion

//Function prototypes
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();
void prob8();
void prob9();
void prob10();

//Execution begins here
int main(int argc, char** argv) 
{
    //Declare variables
    int menuCho;
    
    //Open Menu
    do{
        cout<<"1)  Problem 2  (Sum of Numbers)"<<endl;
        cout<<"2)  Problem 3  (Distance Traveled)"<<endl;
        cout<<"3)  Problem 5  (Speed Conversion Chart)"<<endl;
        cout<<"4)  Problem 6  (Ocean Levels)"<<endl;
        cout<<"5)  Problem 8  (Calories Burned)"<<endl;
        cout<<"6)  Problem 10 (Random Number Guessing Game)"<<endl;
        cout<<"7)  Problem 11 (Random Number Guessing Game Enhancement)"<<endl;
        cout<<"8)  Problem 15 (Population)"<<endl;
        cout<<"9)  Problem 18 (Rectangle Display)"<<endl;
        cout<<"10) Problem 22 (Sales Bar Chart)"<<endl;
        cin>>menuCho;
        switch(menuCho){
            case 1: prob1();break;
            case 2: prob2();break;
            case 3: prob3();break;
            case 4: prob4();break;
            case 5: prob5();break;
            case 6: prob6();break;
            case 7: prob7();break;
            case 8: prob8();break;
            case 9: prob9();break;
            case 10:prob10();break;
        }
    }while(menuCho>0&&menuCho<=10);  
    
    //Exit program
    return 0;
}

void  prob1(){
    int loopNum; //User inputted value/Number of iterations of loop
    int total;   //Total sum of all numbers
    
    //Input values
    cout<<endl;
    cout<<"Input a value to get a sum of all previous numbers: ";
    cin>>loopNum;
    
    //Process values -> map inputs to outputs
    for(int i=loopNum;i>0;i--){ //Reiterates for number that user inputted
        total+=loopNum;         //Adds of total as loop reiterates
        loopNum--;              //Lowers counter toward 0
    }
    
    //Display output
    cout<<endl;
    cout<<"The total sum is: "<<total;
    cout<<endl<<endl;
}
void  prob2(){
    //Declaration of variables
    int  velo;    //User inputted speed of the vehicle
    int  hrsTrav; //Number of hours the vehicle traveled
    
    //Input values
    cout<<endl;
    cout<<"What is the speed of the vehicle in mph? ";
    cin>>velo;
    cout<<"How many hours has it traveled? ";
    cin>>hrsTrav;
    while(velo<0||hrsTrav<1){ //Input Validation
        cout<<endl;
        cout<<"Invalid input!"<<endl;
        cout<<"What is the speed of the vehicle in mph? ";
        cin>>velo;
        cout<<"How many hours has it traveled? ";
        cin>>hrsTrav;
    }
    cout<<"Hour"<<"     "<<"Distance Traveled"<<endl;  //Table header
        cout<<"-------------------------------"<<endl; //Table separator
        //Reiterated for number of hours traveled
        for(int i=1;i<=hrsTrav;i++){ 
            //Output distance traveled after each hour
            cout<<i<<setw(10)<<velo*i<<endl; 
        }
    cout<<endl<<endl;
}
void  prob3(){
    int   kph=60; //Starting value on table
    float mph=0;  //MPH value to be converted
    
    //Process values -> map inputs to outputs
    cout<<endl;
    cout<<"Km/h"<<"    "<<"Mil/h"<<endl; //Table header
    cout<<"---------------"<<endl;       //Table separator
    for(int i=kph;i<=130;i+=5){ //Iterates in increments of 5 for table
        mph=kph*KMTOMIL;        //Convert KM to mile
        
        //Output values
        cout<<kph<<setw(10)<<setprecision(3)<<mph<<endl;
        kph+=5;                 //Increment KM by 5
    }
    cout<<endl<<endl;
}
void  prob4(){
    const float seaRise=3.1;     //Sea level rise in mm per year
    float       totRise=seaRise; //Total rise over given number of years

    //Output table
    cout<<endl;
    cout<<"Year"<<"       "<<"Sea level rise (mm)"<<endl; //Table header
    cout<<"---------------------------------"<<endl;      //Table separator
    for(int i=1;i<=25;i++){ //Iterates for given number of years
        cout<<i<<setw(20);  //Output year
        cout<<setprecision(3)<<totRise<<endl; //Output total rise for given year
        totRise+=seaRise;   //Increment total rise for next iteration
    }
    cout<<endl<<endl;
}
void  prob5(){
    float calBurn=3.9f; //Calories burned per minute on specific machine
    float totBurn=0.0f; //Total calories burned for each minute
    
    //Output table
    cout<<endl;
    cout<<"Minutes on treadmill"<<"    "<<"Calories burned"<<endl;//Table header
    cout<<"--------------------------------------"<<endl; //Table separator
    for(int i=10;i<=30;i+=5){ //Iterates in 5 minute increments
        totBurn=calBurn*i;    //Calculate total calories burned
        cout<<i<<setw(30)<<setprecision(3)<<totBurn<<endl; //Output values
    }
    cout<<endl<<endl;
}
void  prob6(){
    //Initialize random number seed
    srand(time(NULL));
    //Declaration of variables
    int answer=(rand()%100)+1; //Variable generates random number
    int guess;                 //User inputted guess of random number
    
    //Input values
    cout<<endl;
    do{ //Continues looping until solution is reached
        //Prompt user
        cout<<"What number am i thinking of? (1-100)";
        //Input values
        cin>>guess;
        if(guess>answer){ //Check if guess is too high
            cout<<"Too high! Guess again: "<<endl;
        }
        else if(guess<answer){ //Check if answer is too low
            cout<<"Too low! Guess again: "<<endl;
        }
        else{ //Indicates that guess is correct
            cout<<"Correct! The answer is "<<answer<<endl;
        }
    }while(guess!=answer); //Loop ends when guess is the same as the answer
    cout<<endl<<endl;
}
void  prob7(){
    //Initialize random number seed
    srand(time(NULL));
    //Declaration of variables
    int answer=(rand()%100)+1; //Variable generates random number
    int guess;                 //User inputted guess of random number
    int counter=0;             //Counts number of guesses user needs
    
    //Input values
    cout<<endl;
    do{ //Continues looping until solution is reached
        //Prompt user
        counter++;
        cout<<"What number am i thinking of? (1-100)";
        //Input values
        cin>>guess;
        if(guess>answer){ //Check if guess is too high
            cout<<"Too high! Guess again: "<<endl;
        }
        else if(guess<answer){ //Check if answer is too low
            cout<<"Too low! Guess again: "<<endl;
        }
        else{ //Indicates that guess is correct
            cout<<"Correct! The answer is "<<answer<<endl;
            if(counter==1){ //Grammar check ("guess" for 1, "guesses" for 2+)
                cout<<"It took you "<<counter<<" guess."<<endl; //Singular
            }
            else{
                cout<<"It took you "<<counter<<" guesses."<<endl; //Plural
            }
        }
    }while(guess!=answer); //Loop ends when guess is the same as the answer
    cout<<endl<<endl;
}
void  prob8(){
    //Declaration of variables
    float strtPop; //User indicated starting population
    int   incPer;  //Period of time being observed
    float popInc;  //Number of new organisms
    float incRate; //Percent increase over time
    
    //Input values
    cout<<endl;
    cout<<"Enter the starting population size: ";
    cin>>strtPop;
    //Input validation for population size
    while(strtPop<2){ 
        cout<<"Invalid input!"<<endl;
        cout<<"Enter the starting population size: ";
        cin>>strtPop;
    }
    cout<<"Enter the rate at which the population is increasing: ";
    cin>>incRate;
    //Input validation for population rate
    while(incRate<=0){
        cout<<"Invalid input!"<<endl;
        cout<<"Enter the rate at which the population is increasing: ";
        cin>>incRate;
    }
    cout<<"Enter the period of growth to observe in days: ";
    cin>>incPer;
    //Input validation for observation time
    while(incPer<1){
        cout<<"Invalid input!"<<endl;
        cout<<"Enter the period of growth to observe in days: ";
        cin>>incPer;
    }
    
    //Process values -> map inputs to outputs    
    incRate=incRate/100;    //Calculate percent increase in decimals
    popInc=strtPop*incRate; //Calculate population increase over one day
    cout<<endl;
    //Table header
    cout<<"Observation day"<<"         "<<"New population"<<endl;
    //Table Separator
    cout<<"-------------------------------------"<<endl;
    for(int i=1;i<=incPer;i++){ //Reiterate for each observation day
        cout<<i<<setw(25)<<static_cast<int>(strtPop)<<endl;
        strtPop+=popInc; //Change starting population to current population
        popInc=strtPop*incRate; //Recalculate number of new organisms
    }
    cout<<endl<<endl;
}
void  prob9(){
    int  length,width; //Inputted length and width of rectangle
    char fill='X';     //Character used to fill rectangle
    
    //Input values
    cout<<endl;
    cout<<"Enter a length between 2 and 10: ";
    cin>>length;
    cout<<"Enter a width between 2 and 10: ";
    cin>>width;
    while((length>10||length<2)||(width>10||width<2)){ //Input validation
        cout<<"Invalid input!"<<endl;
        cout<<"Enter a length between 2 and 10: ";
        cin>>length;
        cout<<"Enter a width between 2 and 10: ";
        cin>>width;
    }   
    //Length loop (iterates down for each unit of length)    
    for(int i=length;i>0;i--){ 
        //Width loop (iterates right for each unit of width)
        for(int i=width;i>0;i--){
            cout<<fill;
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
void prob10(){
    unsigned int str1,str2,str3; //3 stores whose sales are being compared
    
    //Input values
    cout<<endl;
    cout<<"Input the sales of store 1 to the nearest hundred: ";
    cin>>str1;
    cout<<"Input the sales of store 2 to the nearest hundred: ";
    cin>>str2;
    cout<<"Input the sales of store 3 to the nearest hundred: ";
    cin>>str3;
    
    //Output Table  
    cout<<"TODAY'S SALES"<<endl;
    cout<<"(* = $100)"<<endl; //Key of table
    cout<<"Store 1: ";
    for(int i=0;i<str1/100;i++){ //Iterate for each hundred dollars store earned
        cout<<'*';
    }
    cout<<endl;
    
    cout<<"Store 2: ";
    for(int i=0;i<str2/100;i++){ //Iterate for each hundred dollars store earned
        cout<<'*';
    }
    cout<<endl;
    
    cout<<"Store 3: ";
    for(int i=0;i<str3/100;i++){ //Iterate for each hundred dollars store earned
        cout<<'*';
    }
    cout<<endl<<endl;
}

