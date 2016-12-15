/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month Day, Year, Time AM/PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <ctime>
#include <cstdlib>

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes
void markSrt1F(int[],int);

//Execution begins here
int main(int argc, char** argv) 
{
    int common[]={25,2,49,50,27,28,4,29,5,6,31,52,75,10,56,11,95,32,33,77,78,80,
                  79,100,101,102,103,16,36,18,81,39,104,82,59,42,83,107,84,86,
                  108,111,88,109,45,20,63,113,64,55,90,65,66,67,22};
    int uncomm[]={};
    inr rareee[]={}
    
    srand(time(0));
    
    
    for(int i=0;i<180;i++){
        array[i]=rand()%135+1;
    }
    cout<<"Array"<<endl;
    for(int i=0;i<180;i++){
        cout<<array[i]<<' ';
        if(i%10==9)cout<<endl;
    }
    
    markSrt1F(array,180);
    
    cout<<endl<<endl;
    cout<<"Sorted"<<endl;
    for(int i=0;i<180;i++){
        cout<<array[i]<<' ';
        if(i%10==9)cout<<endl;
    }
    
    //Exit program
    return 0;
}

void markSrt1F(int a[],int size){   
    for(int i=0;i<size-1;i++){
        int pos=i;
        for(int j=pos+1;j<size;j++){
            if(a[pos]>a[j]){
                a[pos]=a[pos]^a[j];
                a[j]=a[pos]^a[j];
                a[pos]=a[pos]^a[j];
            }
        }
    }
}