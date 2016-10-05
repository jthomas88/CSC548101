/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 4, 2016, 11:40 PM
 * Purpose: Convert a number 1 through 10 to a Roman numeral.
 */

//System Libraries
#include <iostream>  //Input/Output objects

using namespace std; //Namespace used in system library

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    unsigned short digit;  //Digit to be converted
    
    //Input values
    cout<<"Enter a digit 1 through 10 to be converted to a Roman numeral: ";
    cin>>digit;
    
    //Output case based on input
    switch(digit)
    {
        case 1:cout<<"The Roman numeral of "<<digit<<" is I";break;
        case 2:cout<<"The Roman numeral of "<<digit<<" is II";break;
        case 3:cout<<"The Roman numeral of "<<digit<<" is III";break;
        case 4:cout<<"The Roman numeral of "<<digit<<" is IV";break;
        case 5:cout<<"The Roman numeral of "<<digit<<" is V";break;
        case 6:cout<<"The Roman numeral of "<<digit<<" is VI";break;
        case 7:cout<<"The Roman numeral of "<<digit<<" is VII";break;
        case 8:cout<<"The Roman numeral of "<<digit<<" is VIII";break;
        case 9:cout<<"The Roman numeral of "<<digit<<" is IX";break;
        case 10:cout<<"The Roman numeral of "<<digit<<" is X";break;
        default:cout<<"Invalid input."; //Input validation
    }
    
    
    //Exit program
    return 0;
}

