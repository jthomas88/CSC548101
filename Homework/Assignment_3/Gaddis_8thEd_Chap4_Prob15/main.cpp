/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 5, 2016, 10:34 PM
 * Purpose: Calculate amount of calories from fat in a given food
 */

//System Libraries
#include <iostream> //Input/Output objects

using namespace std; //Namespace used in system library

//User libraries

//Global constants
const unsigned short FATCAL=9;    //1 gram of fat has 9 calories
const unsigned short PERCENT=100; //Percent converter

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    unsigned int usrCal,usrFat; //Amount of calories and grams of fat
    unsigned int calFF;         //Calories from fat
    unsigned short fatPct;      //Percent of calories form fat
    
    //Input values
    cout<<"Input the number of calories in a serving: ";
    cin>>usrCal;
    cout<<"Input the number of grams of fat: ";
    cin>>usrFat;
    
    //Process values -> map inputs to outputs
    calFF=usrFat*FATCAL; //Calories from fat calculation
    //Fat calorie percentage calculation
    fatPct=(static_cast<float>((calFF))/static_cast<float>(usrCal))*PERCENT;
    
    //Display output
    cout<<"Total calories: "<<usrCal<<endl;
    cout<<"Calories from fat: "<<calFF<<endl;
    cout<<"Percent of calories from fat: "<<fatPct<<"%"<<endl;
    //Notify user if food is low in fat or not
    if(fatPct<30){ 
        cout<<"This is a low fat food.";
    }
    else{
        cout<<"This is not a low fat food.";
    } 
    //Exit program
    return 0;
}

