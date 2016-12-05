/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 22, 2016, 09:32 PM
 * Purpose: Raise a mysterious creature to adulthood
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std; //Namespace used in system library

//User libraries

//Global constants
int const FRAMES=10;
int const MAXPLAY=4;

//Function prototypes
//void prntAry(bool[],int);
void prntBrd();

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    const int PINS=10;
    
    bool pins[PINS];
    
    //Test Array
    //prntAry(pins,PINS);
    prntBrd();
    
    //Exit program
    return 0;
}

void prntAry(bool array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i];
    }
}

void prntBrd(){
    cout<<"---------"<<endl;
    cout<<"-o-o-o-o-"<<endl;
    cout<<"--o-o-o--"<<endl;
    cout<<"---o-o---"<<endl;
    cout<<"----o----"<<endl;
    cout<<"---------"<<endl;
}