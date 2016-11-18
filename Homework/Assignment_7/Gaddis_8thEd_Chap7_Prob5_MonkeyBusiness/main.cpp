/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on November 17, 2016, 12:10 PM
 * Purpose: Calculate annual rainfall data
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <cstdlib>   //Random generator
#include <ctime>     //Random seed
#include <iomanip>   //Formatting

using namespace std; //Namespace used in system library

//User libraries

//Global constants
const int MONKEYS=3; //Number of monkeys in the zoo
const int WEEKDAY=5; //Number of weekdays in a week

//Function prototypes

//Fill and Print Functions
void fillAry(int[][WEEKDAY]);
void prntAry(int[][WEEKDAY]);

//Search Functions
int findHig(int[][WEEKDAY]);
int findLow(int[][WEEKDAY]);

//Totaling functions
float avg(int[][WEEKDAY]);

//Execution begins here
int main(int argc, char** argv) 
{
    //Initialize random seed
    srand(time(0));
            
    //Declaration of variables
    int mnkCoun=0; //Monkey array element assignment
    int dayCoun=0; //Day array element assignment
    
    int mnkFood[][WEEKDAY]={}; //Monkey food data array
    
    //Fill Array
    fillAry(mnkFood);
    
    //Output table header
    cout<<"          ";
    for(int i=0;i<WEEKDAY;i++){
        cout<<"Day "<<i+1<<"  ";
    }
    cout<<endl;
    
    //Output Array
    prntAry(mnkFood);
    cout<<endl;
    
    //Find most food eaten and output
    cout<<"Most food eaten this week: "<<findHig(mnkFood)<<" lbs.";
    cout<<endl;
    
    //Find least food eaten and output
    cout<<"Least food eaten this week: "<<findLow(mnkFood)<<" lbs.";
    cout<<endl;
    
    //Find average consumption and output
    cout<<"Average daily consumption: ";
    cout<<setprecision(2)<<avg(mnkFood)<<" lbs.";
    cout<<endl;
    
    //Process Values
    
    //Exit program
    return 0;
}

//Find Highest

 
int findHig(int array[][WEEKDAY]){
    int high=0;
    for(int row=0;row<MONKEYS;row++){
        for(int col=0;col<WEEKDAY;col++){
            if(array[row][col]>high){
            high=array[row][col];
            }
        }
    }
    return high;
}

//Find Lowest
int findLow(int array[][WEEKDAY]){
    float high=0;
    float low=0;
    for(int row=0;row<MONKEYS;row++){
        for(int col=0;col<WEEKDAY;col++){
            if(array[row][col]>high){
            high=array[row][col];
            }
        }
        
    }
    for(int row=0;row<MONKEYS;row++){
        for(int col=0;col<WEEKDAY;col++){
            if(array[row][col]<high){
            low=array[row][col];        
            high=low;
            }
        }
    }
    return low;
}

//Fill Array
void fillAry(int array[][WEEKDAY]){
    int random;
    for(int row=0;row<MONKEYS;row++){
        for(int col=0;col<WEEKDAY;col++){           
            //A monkey eats an average of 7 lbs per day
            //Random value is average monkey intake +/- 2 lbs
            random=rand()%10;
            array[row][col]=random;
        }
    }
}

//Print Array
void prntAry(int array[][WEEKDAY]){
    int count=0;
    for(int row=0;row<MONKEYS;row++){
        cout<<"Monkey "<<row+1<<": ";
        for(int col=0;col<WEEKDAY;col++){
            cout<<array[row][col]<<" lbs. ";
            if(count++==4){
                cout<<endl;
                count=0;
            }
        }
    }
}

//Find array average
float avg(int array[][WEEKDAY]){
    float average=0;
    for(int row=0;row<MONKEYS;row++){
        for(int col=0;col<WEEKDAY;col++){
            average+=array[row][col];
        }
    }
    average=average/(MONKEYS*WEEKDAY);
    return average;
}
