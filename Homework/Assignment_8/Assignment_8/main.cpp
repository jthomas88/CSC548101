/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on December 1, 2016, 1:30 AM
 * Purpose: Assignment 8
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>   //Random Numbers
#include <ctime>     //Random Seed
#include <fstream>   //File I/O

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
//Problem Functions
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();
void prob8();
void prob9();
void prob10();

//Fill and Print Functions
void readAry(int[],int,string);
void prntAry(int[],int);

//Search Functions
bool findMat(int[],int,int);
int  binSrch(int[],int,int);

//Sort Functions
void bubbSrt(int[],int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Declare variables
    int menuCho;
    
    //Open Menu
    do{
        cout<<"1)  Problem 1:  Charge Account Validation"<<endl;
        cout<<"2)  Problem 2:  Lottery Winners"<<endl;
        cout<<"3)  Problem 3:  Lottery Winners Mod (Binary)"<<endl;
        cout<<"4)  Problem 4:  Charge Acct Validation Mod (Binary)"<<endl;
        cout<<"5)  Problem 5:  Rainfall Statistics Mod (Sort)"<<endl;
        cout<<"6)  Problem 6:  String Selection Sort"<<endl;
        cout<<"7)  Problem 8:  Search Benchmarks"<<endl;
        cout<<"8)  Problem 9:  Sorting Benchmarks"<<endl;
        cout<<"9)  Problem 10: Sorting Orders"<<endl;
        cout<<"10) Problem 11: String Selection Sort Mod (File I/O)"<<endl;
        cin>>menuCho;
        switch(menuCho){
            case  1: prob1();cout<<endl;break;
            case  2: prob2();cout<<endl;break;
            case  3: prob3();cout<<endl;break;
            case  4: prob4();cout<<endl;break;
            case  5: prob5();cout<<endl;break;
            case  6: prob6();cout<<endl;break;
            case  7: prob7();cout<<endl;break;
            case  8: prob8();cout<<endl;break;
            case  9: prob9();cout<<endl;break;
            case 10:prob10();cout<<endl;break;
        }
    }while(menuCho>0&&menuCho<=10);  
    
    //Exit program
    return 0;
}
//Problem Functions
void  prob1(){
    cout<<endl;
    cout<<"Problem 1: Charge Account Validation"<<endl;
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    const int SIZE=18;   //Number of accts to search through
    int acctNum=rand()%9000000+1000000; //User's account number
    int accts[SIZE]={};  //18 Account Numbers
    string file="accts.dat";
    
    //Read in values from file and write into array
    readAry(accts,SIZE,file);
    
    //Output values from array
    cout<<"Account numbers on file:"<<endl<<endl;
    prntAry(accts,SIZE);
    cout<<endl;
    
    //Output acct number trying to be looked up
    cout<<"Your account number is: "<<acctNum;
    cout<<endl;
    
    //Check if acct number matches any of the number on file
    findMat(accts,acctNum,SIZE)==0?cout<<"The account number matches."
            :cout<<"Cannot find account number.";
    
    //Exit program
    cout<<endl;
}
void  prob2(){
    cout<<endl;
    cout<<"Problem 2:  Lottery Winners"<<endl;
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    const int SIZE=10;            //Number of lottery tickets
    int lotto=rand()%90000+10000; //Randomly selected lotto number
    //int lotto=77777;            //Test variable
    int tix[SIZE]={};             //10 Lottery tickets
    string file="tix.dat";        //File name for function call
    
    //Fill array with file data
    readAry(tix,SIZE,file);
    
    //Output Array
    cout<<"Your tickets"<<endl<<endl;
    prntAry(tix,SIZE);
    cout<<endl;
    
    //Output random lotto number
    cout<<"This week's winning lottery number is: "<<lotto;
    cout<<endl;
    
    //Check if player is a winner
    findMat(tix,lotto,SIZE)==0?cout<<"A winner is you!":cout<<"Sorry, loser!";
    
    //Exit program
    cout<<endl;
}
void  prob3(){
    cout<<endl;
    cout<<"Problem 3:  Lottery Winners Mod (Binary)"<<endl;
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    const int SIZE=10;            //Number of lottery tickets
    int lotto=rand()%90000+10000; //Randomly selected lotto number
    //int lotto=77777;            //Test variable
    int tix[SIZE]={};             //10 Lottery tickets
    string file="tix.dat";        //File name for function call
    
    //Fill array with file data
    readAry(tix,SIZE,file);
    
    //Output Array
    cout<<"Your tickets"<<endl<<endl;
    prntAry(tix,SIZE);
    cout<<endl;
    
    //Output random lotto number
    cout<<"This week's winning lottery number is: "<<lotto;
    cout<<endl;
    
    //Check if player is a winner
    binSrch(tix,lotto,SIZE)==0?cout<<"A winner is you!":cout<<"Sorry, loser!";
    
    //Exit program
    cout<<endl;
}
void  prob4(){
    cout<<endl;
    cout<<"4)  Problem 4:  Charge Acct Validation Mod (Binary)"<<endl;
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    const int SIZE=18;       //Number of accts to search through
    int acctNum=rand()%9000000+1000000; //User's account number
    //int acctTst=5658845;   //Test variable
    int accts[SIZE]={};      //18 Account Numbers
    string file="accts.dat"; //File name for function call
    
    //Read in values from file and write into array
    readAry(accts,SIZE,file);
    
    //Output values from array
    cout<<"Account numbers on file:"<<endl<<endl;
    prntAry(accts,SIZE);
    cout<<endl;
    
    //Output acct number trying to be looked up
    cout<<"Your account number is: "<<acctNum;
    cout<<endl;
    
    //Sort acct numbers least to greatest
    bubbSrt(accts,SIZE);
    
    //Check if acct number matches any of the number on file
    binSrch(accts,acctNum,SIZE)!=-1?cout<<"The account number matches."
            :cout<<"Cannot find account number.";
    
    //Exit program
    cout<<endl;
}
void  prob5(){
    cout<<"Problem E"<<endl;
    //Input
    //Process
    //Output
}
void  prob6(){
    cout<<"Problem F"<<endl;
    //Input
    //Process
    //Output
}
void  prob7(){
    cout<<"Problem G"<<endl;
    //Input
    //Process
    //Output
}
void  prob8(){
    cout<<"Problem H"<<endl;
    //Input
    //Process
    //Output
}
void  prob9(){
    cout<<"Problem I"<<endl;
    //Input
    //Process
    //Output
}
void prob10(){
    cout<<"Problem J"<<endl;
    //Input
    //Process
    //Output
}

//Fill and Print Functions
void readAry(int array[],int size,string file){
    ifstream read;       //Create read object
    read.open(file);     //Open file
    for(int i=0;i<size;i++){
        read>>array[i];  //Fill array
    }
    read.close();        //Close file
}

void prntAry(int array[],int size){
    for(int i=0;i<size;i++){ //Ouput each element of the array
        cout<<array[i]<<' '; 
        if(i%(size/5)==(size/5)-1)cout<<endl; //Break line
    }
}

//Sort Functions
void bubbSrt(int array[],int size){
    int temp=0;  //Temporary variable for swap
    bool isSwap; //Determines if variables have been swapped or not
        do{
            isSwap=false; //Set swap to false
            for(int i=-1;i<size-1;i++){
                //Swap if current variable is larger than next
                if(array[i]>array[i+1]){ 
                    temp=array[i];
                    array[i]=array[i+1];
                    array[i+1]=temp;
                    isSwap=true; //Set swap to true after swap                 
                }
            }
        }while(isSwap);     
}

//Search Functions
bool findMat(int array[],int match,int size){
    for(int i=0;i<size;i++){ //Loops for as many elements are in the array
        if(match==array[i]){ //Loop stops if match is found
            return 0;        //Return True
        }
    }
    return 1;                //Return false if no match is found
}

int  binSrch(int array[],int match,int size){
    //Declare and setup
    int beg=0;        //Initialize start point
    int mid;          //Midpoint to be found
    int end=size-1;   //Initialize end point
    bool found=false; //Default found status to false
    int pos=-1;       //Starting position
    //Loop until found
    do{
        mid=(beg+end)/2; //Set midpoint to average of top and bottom position
        if(array[mid]==match){ //Check if match has been found
            found=true;        //Set found to true
            pos=mid;           //Set found position
        }
        else if(array[mid]<match){ //Cut off bottom half of array
            beg=mid+1;             //Set new begin point
        }else{                     //Cut off top half of array
            end=mid-1;             //Set new end point
        }
    }while(end>=beg&&found!=true); //Continue looping until found
    return pos;                    //Output position
}
