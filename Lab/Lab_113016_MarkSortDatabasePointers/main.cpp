/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on November 30, 2016, 10:15 AM
 * Purpose:  Mark Sort as done in a database using pointer notation
 */

//System Libraries Here
#include <iostream>  //I/O
#include <cstdlib>   //Random
#include <ctime>     //Time
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void fillAry(int *,int *,int);
void prntAry(int *,int);
void prntAry(int *,int *,int);
void markSrt(int *,int *,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    int const SIZE=100;
    int array[SIZE],index[SIZE],utilize;
    
    //Input or initialize values Here
    do{
        cout<<"How much of the array to utilize?"<<endl;
        cout<<"Choose a number between 2 and 100"<<endl;
        cin>>utilize;
    }while(utilize<2||utilize>100);
    
    //Fill the array
    fillAry(array,index,utilize);
    
    //Output Located Here
    cout<<"The random arrays after fill and before the sort"<<endl;
    cout<<"The random array"<<endl;
    prntAry(array,utilize);
    cout<<"The indexed array"<<endl;
    prntAry(index,utilize);
    cout<<"The random array with the index"<<endl;
    prntAry(array,index,utilize);
    
    //Test out minPos
    markSrt(array,index,utilize);
    
    //Output Located Here
    cout<<"The random arrays after the sort"<<endl;
    cout<<"The random array"<<endl;
    prntAry(array,utilize);
    cout<<"The indexed array"<<endl;
    prntAry(index,utilize);
    cout<<"The random array with the index"<<endl;
    prntAry(array,index,utilize);

    //Exit
    return 0;
}

void markSrt(int *a,int *indx,int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(*(a+*(indx+i))>*(a+*(indx+j))){
                *(indx+i)=*(indx+i)^*(indx+j);
                *(indx+j)=*(indx+i)^*(indx+j);
                *(indx+i)=*(indx+i)^*(indx+j);
            }
        }
    }
}

void prntAry(int *a,int *indx,int n){
    //Output Located Here
    cout<<"The Array"<<endl;
    for(int i=0;i<n;i++){
        cout<<*(a+*(indx+i))<<" ";
        if(i%10==9)cout<<endl;
    }
    cout<<endl;
}

void prntAry(int *a,int n){
    //Output Located Here
    cout<<"The Array"<<endl;
    for(int i=0;i<n;i++){
        cout<<*(a+i)<<" ";
        if(i%10==9)cout<<endl;
    }
    cout<<endl;
}

void fillAry(int *a,int *indx,int n){
    //Fill the array
    for(int i=0;i<n;i++){
        *(a+i)=rand()%90+10;//Random 2 digit number
        *(indx+i)=i;
    }
}