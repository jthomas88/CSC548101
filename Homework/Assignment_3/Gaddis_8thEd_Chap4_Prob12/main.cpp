/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 5, 2016, 12:06 AM
 * Purpose: Display the winner of a race
 */

//System Libraries
#include <iostream>  //Input/Output objects

using namespace std; //Namespace used in system library

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    string runner1,runner2,runner3;         //Names of runners
    unsigned short minTim1,minTim2,minTim3; //Minute times
    unsigned short secTim1,secTim2,secTim3; //Seconds times
    unsigned int finTim1,finTim2,finTim3;   //Converted final time
    
    
    //Input values
    cout<<"Enter the first runner's name followed ";
    cout<<"by their time in minutes and seconds:";
    cin>>runner1>>minTim1>>secTim1;
    cout<<"Enter the second runner's name followed ";
    cout<<"by their time in minutes and seconds:";
    cin>>runner2>>minTim2>>secTim2;
    cout<<"Enter the third runner's name followed ";
    cout<<"by their time in minutes and seconds:";
    cin>>runner3>>minTim3>>secTim3;
    
    
    //Convert minutes and seconds to only seconds
    finTim1=(minTim1*60)+secTim1;
    finTim2=(minTim2*60)+secTim2;
    finTim3=(minTim3*60)+secTim3;
    
    //Display output
    cout<<endl;
    //Sort for runner 1 in 3rd
    if(finTim1>finTim2&&finTim1>finTim3){
        if(finTim2>finTim3){
            cout<<"1st: "<<runner3<<endl;
            cout<<"2nd: "<<runner2<<endl;
            cout<<"3rd: "<<runner1<<endl;
        }
        else{
            cout<<"1st: "<<runner2<<endl;
            cout<<"2nd: "<<runner3<<endl;
            cout<<"3rd: "<<runner1<<endl;
        }
    }
    //Sort for B runner 2 in 3rd
    else if(finTim2>finTim1&&finTim2>finTim3){
        if(finTim1>finTim3){
            cout<<"1st: "<<runner3<<endl;
            cout<<"2nd: "<<runner1<<endl;
            cout<<"3rd: "<<runner2<<endl;
        }
        else{
            cout<<"1st: "<<runner1<<endl;
            cout<<"2nd: "<<runner3<<endl;
            cout<<"3rd: "<<runner2<<endl;
        }
    }
    //Sort for runner 3 in 3rd
    else{
        if(finTim1>finTim2){
            cout<<"1st: "<<runner2<<endl;
            cout<<"2nd: "<<runner1<<endl;
            cout<<"3rd: "<<runner3<<endl;
        }
        else{
            cout<<"1st: "<<runner1<<endl;
            cout<<"2nd: "<<runner2<<endl;
            cout<<"3rd: "<<runner3<<endl;
        }
    }
    //Exit program
    return 0;
}

