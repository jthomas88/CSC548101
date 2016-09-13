/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on September 10, 2016, 11:40 PM
 * Purpose: Determine amount of fencing needed for a given yard
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
    unsigned int w, //W = width of the area
                 h, //H = height of the area
                 a, //A = fenced area
                 l; //L = Total length of fence needed
    
    //Input values
    cout << "Input the width of the fenced area: ";
    cin >> w;
    cout << endl << "Input the height of the fenced area: ";
    cin >> h;
    
    //Process values -> map inputs to outputs
    l = h*2 + w*2; //Perimeter formula for a rectangular figure
    a = h*w;
    //Display output
    cout << "Width of the area: " << w << endl;
    cout << "Height of the area: " << h << endl;
    cout << "Total length of fencing needed: " << l << endl;
    
    //Exit program
    return 0;
}

