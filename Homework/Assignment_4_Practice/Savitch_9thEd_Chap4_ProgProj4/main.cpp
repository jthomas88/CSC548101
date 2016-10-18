/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 15, 2016, 09:00 PM
 * Purpose: Sing "99 bottles"
 */

//System Libraries
#include <iostream>  //Input/Output objects
using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    string tens; //Tens place assignment (10,20,30,40,50,60,70,80,90)
    string ones; //Ones place assignment (0,1,2,3,4,5,6,7,8,9)
    string spec; //Special numbers that do not fit the pattern (11-19)
    
    //Begin loop
    for(int beer=99;beer>=0;beer--){
        //Ternary operators to assign values to text
        //Tens place assignment (string is assigned based on value of tens)
        beer/10==9?tens="ninety":
        beer/10==8?tens="eighty":
        beer/10==7?tens="seventy":
        beer/10==6?tens="sixty":
        beer/10==5?tens="fifty":
        beer/10==4?tens="forty":
        beer/10==3?tens="thirty":
        beer/10==2?tens="twenty":
        beer/10==1?tens="ten":tens="zero";
        
        //Ones place assignment (string is assigned based on value of ones)
        beer%10==9?ones="nine":
        beer%10==8?ones="eight":    
        beer%10==7?ones="seven":
        beer%10==6?ones="six":
        beer%10==5?ones="five":    
        beer%10==4?ones="four":    
        beer%10==3?ones="three":
        beer%10==2?ones="two":    
        beer%10==1?ones="one":ones=" ";   
        
        //Special number assignment
        beer/10==1&&beer%10==9?spec="nineteen":
        beer/10==1&&beer%10==8?spec="eighteen":
        beer/10==1&&beer%10==7?spec="seventeen":
        beer/10==1&&beer%10==6?spec="sixteen":
        beer/10==1&&beer%10==5?spec="fifteen":
        beer/10==1&&beer%10==4?spec="fourteen":
        beer/10==1&&beer%10==3?spec="thirteen":
        beer/10==1&&beer%10==2?spec="twelve":
        beer/10==1&&beer%10==1?spec="eleven":spec=" ";    
        
        //Display output
        if(beer%10!=0){ //Check for numbers that are not multiples of 10
            if(beer>10&&beer<20){ //Check for numbers 11-19
                cout<<spec<<" bottles of beer on the wall.\n";
                cout<<spec<<" bottles of beer.\n";
                cout<<"take one down, pass it around.\n";
                cout<<spec<<" bottles of beer on the wall.\n";
                cout<<endl;
            }
            else if(beer<10){ //Check for numbers less than 10
                cout<<ones<<" bottles of beer on the wall.\n";
                cout<<ones<<" bottles of beer.\n";
                cout<<"take one down, pass it around.\n";
                cout<<ones<<" bottles of beer on the wall.\n";
                cout<<endl;
            }
            else{ //Default assignment for numbers
                cout<<tens<<'-'<<ones<<" bottles of beer on the wall.\n";
                cout<<tens<<'-'<<ones<<" bottles of beer.\n";
                cout<<"take one down, pass it around.\n";
                cout<<tens<<'-'<<ones<<" bottles of beer on the wall.\n";
                cout<<endl;
            }
        }
        else{ //Check for multiples of 10
            if(beer==0){ //Check for zero
                cout<<tens<<" bottles of beer on the wall.\n";
                cout<<tens<<" bottles of beer.\n";
                cout<<"now we're all out of beer on the wall.\n";
                cout<<endl;
            }
            else{
                cout<<tens<<" bottles of beer on the wall.\n";
                cout<<tens<<" bottles of beer.\n";
                cout<<"take one down, pass it around.\n";
                cout<<tens<<" bottles of beer on the wall.\n";
                cout<<endl;
            }
        }
    }  
    
    //Exit program
    return 0;
}

