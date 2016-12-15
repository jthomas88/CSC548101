/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <fstream>   //File I/O

using namespace std; //Namespace used in system library

//User libraries

//Global constants
const int LENGTH=15;

//Function prototypes
void fillAry(char[][LENGTH],int,string);
void prntAry(char[][LENGTH],int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Declare constants
    const int names=10;
    
    //Declare variables
    string file="input.dat";
    
    //Declare arrays
    char ayyLmao[names][LENGTH]; //Ayyrray of ayylien names
    
    //Read array data from input.dat
    fillAry(ayyLmao,names,file);
    
    //Output filled array
    prntAry(ayyLmao,names);
    
    //Process Values
    
    //Exit program
    return 0;
}

void fillAry(char ayyLmao[][LENGTH],int names,string file){
    ifstream read;
    read.open(file);
    for(int i=0;i<names;i++){
        for(int j=0;j<LENGTH;j++){
            read>>ayyLmao[i][j];
        }
    }
}

void prntAry(char ayyLmao[][LENGTH],int names){
    for(int i=0;i<names;i++){
        for(int j=0;j<LENGTH;j++){
            cout<<ayyLmao[i][j];
            if(j%LENGTH==LENGTH-1)cout<<endl;
        }
    }
}

void sortAry(){
    
}