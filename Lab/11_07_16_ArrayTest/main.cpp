/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on November 7, 2016, 08:36 AM
 * Purpose: Raise a mysterious creature to adulthood
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>   //Format table

using namespace std; //Namespace used in system library

//User libraries

//Global constants
const int SCORE=5;

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    //int test[ARRAY];
    //int setZero[10]={};
    string name[SCORE];
    int    test[SCORE];
    
    //Input values
    for(int i=0;i<SCORE;i++){
        cout<<"Enter student "<<i+1<<" name: ";
        cin>>name[i];
        cout<<"Enter student "<<i+1<<" score: ";
        cin>>test[i];
        cout<<endl;
    }
    cout<<endl<<endl;
    //Output table
    cout<<"NAME"<<setw(15)<<"SCORE";
    cout<<endl;
    for(int i=0;i<SCORE;i++){
        cout<<left<<setw(0)<<name[i]<<left<<setw(10)<<test[i];
        cout<<endl;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    //Test Array
    /*
     * for(int i=0;i<ARRAY;i++){
        test[i]=i+1;
        cout<<test[i]<<endl;
    }
     **/
    
    //SetZero Array
    /*for(int i=0;i<10;i++){
        cout<<setZero[i]<<endl;
    }
     * */
    
    
    //Exit program
    return 0;
}

