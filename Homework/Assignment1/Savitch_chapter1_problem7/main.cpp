/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on September 11, 2016, 8:15 PM
 * Purpose: Output the sum and product of 2 integers
 */

//System Libraries
#include <iostream> //Input/Output objects
using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    int num1, num2, //The two integers that will be added and multiplied.
        sum, prod;  //Sum and product are the sum and product of the 
                    //2 integers, respectively. 
    
    //Input values
    cout << "Enter an integer: ";
    cin >> num1;
    cout << "Enter another integer: ";
    cin >> num2;
    
    //Process values -> map inputs to outputs
    sum = num1 + num2;
    prod = num1*num2;
    
    //Display output
    cout << "First integer: " << num1 << endl;
    cout << "Second integer: " << num2 << endl;
    cout << "Sum of the two integers: " << sum << endl;
    cout << "Product of the two integers: " << prod << endl;
    
    //Exit program
    return 0;
}

