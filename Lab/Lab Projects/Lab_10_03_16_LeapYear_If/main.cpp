/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 3, 2016, 09:40 AM
 * Purpose: Determine if a given year is a leap year
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
    unsigned short yr, mn; //Year and month given
    
    //Input values
    cout<<"Enter a year and month to return number of days in a month: ";
    cin>>yr>>mn;
    
    //Input Validation
    if(yr<1500||yr>3000)
    {
        cout<<"Invalid year."<<endl;
        return 1;
    }
    if(mn<1||mn>12)
    {
        cout<<"Invalid month."<<endl;
        return 1;
    }
    
    //Process values -> map inputs to outputs
    switch(mn)
    {
        case 1:cout<<"There are 31 days in January, "<<yr<<endl;break;
        case 2:{
                   if(yr%4!=0||(yr%100==0&&yr%400!=0))
                   {
                       cout<<"There are 28 days in February, "<<yr;
                   }
                   else
                   {
                       cout<<"There are 29 days in February, "<<yr;
                   }
               }break;
        case 3:cout<<"There are 31 days in March, "<<yr<<endl;break;
        case 4:cout<<"There are 30 days in April, "<<yr<<endl;break;
        case 5:cout<<"There are 31 days in May, "<<yr<<endl;break;
        case 6:cout<<"There are 31 days in June, "<<yr<<endl;break;
        case 7:cout<<"There are 31 days in July, "<<yr<<endl;break;
        case 8:cout<<"There are 31 days in August, "<<yr<<endl;break;
        case 9:cout<<"There are 30 days in September, "<<yr<<endl;break;
        case 10:cout<<"There are 31 days in October, "<<yr<<endl;break;
        case 11:cout<<"There are 30 days in November, "<<yr<<endl;break;
        case 12:cout<<"There are 31 days in December, "<<yr<<endl;break;
    }
    
    //Display output
    
    
    //Exit program
    return 0;
}

