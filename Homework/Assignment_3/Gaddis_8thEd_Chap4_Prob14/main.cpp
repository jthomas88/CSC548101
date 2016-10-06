/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 5, 2016, 10:11 PM
 * Purpose: Calculate a persons BMI given their height and weight
 */

//System Libraries
#include <iostream> //Input/Output objects
#include <iomanip>  //Set precision of decimals

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    float height, weight; //Height and weight of the user
    float bmi;            //Calculated BMI of the user
    
    //Input values
    cout<<"Enter your height in inches and weight in lbs: ";
    cin>>height>>weight;
    
    //Process values -> map inputs to outputs
    bmi=weight*(703/(height*height)); //BMI calculation
    
    //Display output
    if(bmi>25) //Display overweight outcome
    {
        cout<<"Height: "<<height<<"\""<<endl;
        cout<<"Weight: "<<weight<<"lbs."<<endl;
        cout<<"Your BMI: "<<setprecision(3)<<bmi<<endl;
        cout<<"You are obese. Lay off the Cheetos, tubby.";
    }
    else if(bmi<18.5) //Display underweight outcome
    {
        cout<<"Height: "<<height<<"\""<<endl;
        cout<<"Weight: "<<weight<<"lbs."<<endl;
        cout<<"Your BMI: "<<setprecision(3)<<bmi<<endl;
        cout<<"You are underweight. Rattle me bones!";
    }
    else //Display optimal weight outcome
    {
        cout<<"Height: "<<height<<"\""<<endl;
        cout<<"Weight: "<<weight<<"lbs."<<endl;
        cout<<"Your BMI: "<<setprecision(3)<<bmi<<endl;
        cout<<"You are optimal weight. I'm proud of you, son.";
    }
    
    //Exit program
    return 0;
}

