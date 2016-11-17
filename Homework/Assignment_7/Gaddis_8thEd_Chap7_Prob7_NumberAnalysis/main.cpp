/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 22, 2016, 09:32 PM
 * Purpose: Analyze and draw out values from an array
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <fstream>   //Read and write file data
#include <cstdlib>   //Random number generator
#include <ctime>     //Random number seed

using namespace std; //Namespace used in system library

//User libraries

//Global constants
const int SIZE=100;

//Function prototypes
void fillAry(int[]);
void prntAry(int[]);

int  findLow(int[]);
int  findHig(int[]);

int  findSum(int[]);
float  findAvg(int[]);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random number seed
    srand(time(0));
    //Declaration of variables
    int data[SIZE]={};
    
    //Fill array and write to file
    fillAry(data);
    
    //Read array from file and output
    prntAry(data);
    cout<<endl<<endl;
    
    //Find lowest value and output
    cout<<"The lowest value in this set is: "<<findLow(data);
    cout<<endl;
    
    //Find highest value and output
    cout<<"The highest value in this set is: "<<findHig(data);
    cout<<endl;
    
    //Find sum of all numbers and output
    cout<<"The sum of all values is: "<<findSum(data);
    cout<<endl;
    
    //Find sum of all numbers and output
    cout<<"The average of all values is: "<<findAvg(data); 
    cout<<endl;
    
    //Exit program
    return 0;
}

//Fill Array
void fillAry(int data[]){
    ofstream write;
    write.open("array.dat");
    for(int i=0;i<SIZE;i++){
        data[i]=rand()%90+10;
        write<<data[i];
        write<<endl;
    }
    write.close();
}

//Print Array
void prntAry(int data[]){
    int count=0;
    ifstream read;
    read.open("array.dat");
    for(int i=0;i<SIZE;i++){
        cout<<data[i]<<' ';      
        if(count++==9){
            cout<<endl;
            count=0;
        }
    }
    read.close();
}

//Find Highest
int findHig(int data[]){
    int high=0;
    for(int i=0;i<SIZE;i++){
        if(data[i]>high){
            high=data[i];
        }
    }
    return high;
}

//Find Lowest
int findLow(int data[]){
    int high=0;
    int low=0;
    for(int i=0;i<SIZE;i++){
        if(data[i]>high){
            high=data[i];
        }
    }
    for(int i=0;i<SIZE;i++){
        if(data[i]<high){
            low=data[i];
            high=low;
        }
    }
    return low;
}

//Find Sum
int findSum(int data[]){
    int sum=0;
    for(int i=0;i<SIZE;i++){
        sum+=data[i];
    }
    return sum;
}

//Find Average
float findAvg(int data[]){
    int   sum=0;
    float avg=0.0f;
    for(int i=0;i<SIZE;i++){
        sum+=data[i];
    }
    avg=static_cast<float>(sum)/SIZE;
    return avg;
}