/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 26, 2016, 09:56 AM
 * Purpose: Raise a mysterious creature to adulthood
 */

//System Libraries
#include <iostream>  //Input/Output objects

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
bool isLpYr (int);         //Check if year is leap year
int  getCVal(int);         //Get century value
int  getYVal(int);         //Get year value
int  getMVal(int,int);     //Get month value
string duSem(int,int,int); //Get day of week

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    
    //Input Values
    
    //Process Values
    
    //Exit program
    return 0;
}

bool isLpYr(int year){
    return((year%400==0)||((year%4==0)&&(year%100!=0)));
}

int getCVal(int year){
    return 2*(3-year%4);
}

int getYVal(int year){
    int dig2=year%100;
    return dig2+dig2/4;
}

int getMVal(int month,int year){
    switch(month){
        case 1 :return isLpYr(year)?6:0;
        case 2 :return isLpYr(year)?2:3;
        case 3 :return 3;
        case 4 :return 6;
        case 5 :return 1;
        case 6 :return 4;
        case 7 :return 6;
        case 8 :return 2;
        case 9 :return 5;
        case 10:return 0;
        case 11:return 3;
        case 12:return 5;
    }
}

string duSem(int month,int day,int year){
    int nDay=(month+getMVal(month,year)+getYVal(year)+getCVal(year))%7;
    switch(nDay){
        case 0:return "Sunday";
        case 1:return "Monday";
        case 2:return "Tuesday";
        case 3:return "Wednesday";
        case 4:return "Thursday";
        case 5:return "Friday";
        case 6:return "Saturday";
    }
}