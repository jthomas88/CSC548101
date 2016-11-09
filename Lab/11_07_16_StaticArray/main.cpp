/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on November 7, 2016, 08:36 AM
 * Purpose: Raise a mysterious creature to adulthood
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>   //Random
#include <iomanip>   //Format table
#include <ctime>     //Rand seed

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
void filArry(int[],int);
void prtArry(int[],int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize Random num seed
    srand(static_cast<unsigned int>(time(0)));
    //Declaration of variables
    int const SIZE=100;
    int array[SIZE],utilize;
    
    //Input values
    do{
        cout<<"Choose a number between 2 and 100 to";
        cout<<"choose how much of the array to utilize";
        cin>>utilize;
    }while(utilize<2||utilize>100);
    
    //Fill Array
    filArry(array,utilize);

    //Output table
    prtArry(array,utilize);
    cout<<endl;
    
    //Conclusion
    cout<<endl;
    cout<<"For-In passing through a function is illegal.";
    //Exit program
    return 0;
}

void prtArry(int a[],int n){
    int count=0;
    cout<<"The Array"<<endl;
    for(int var:a){
        cout<<var<<' ';
        if((count++)%10==9)cout<<endl;
    }
}

void filArry(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10; //Random 2 digit number
    }
}

