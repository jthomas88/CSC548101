/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on September 16, 2016, 11:16 AM
 * Purpose: Validate a persons addiction for diet soda
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
    const float pSweet = 0.001f; //Percent of sweetener in a can of soda (0.1%)
    float pKill = 0.143f;        //Percent of sweetener needed to kill in
                                 //relation to body mass
    int //cWeight,               //User's current weight
        iWeight,                 //User's ideal weight
        gWeight,                 //User's ideal weight in grams   
        kWeight,                 //Sweetener amount in grams needed to kill
        sodaMax;                 //Max number of cans one can drink before death
    int sodaWgt = 350;           //Mass of soda can in grams
    
    //Input values
        cout<<"Boric Hexafluoride (commonly used as a sweetener in diet soda)\n"
        <<"has recently been found by the FDA to be 'undoubtedly toxic.'\n"
        <<"Use this calculator to determine how many cans of diet soda you\n"
        <<"you can drink without dying."<<endl<<endl; 
        while(iWeight>0)
        {
            cout<<"Enter your ideal weight in lbs: ";
            cin>>iWeight;
    
        //Process values -> map inputs to outputs
            gWeight=iWeight*453.592; //Pound to gram conversion factor
            kWeight=gWeight*pKill;   //Calculate sweetener amount needed to kill
            sodaMax=kWeight/sodaWgt; //Calculate number of cans of soda
    
        //Display output
            cout<<endl<<"Your ideal weight in lbs: "
            <<iWeight<<" lbs"<<endl;   //Display desired weight of user
            cout<<"Your ideal weight in grams: "    
            <<gWeight<<" grams"<<endl; //Display weight converted
            cout<<"Amount of Boric Hexafluoride in one can of diet soda: " 
            <<"3.5 grams"<<endl;       //Display amount of sweetener
            cout<<"Number of cans you can drink without dying: "
            <<sodaMax<<" cans";        //Display amount of cans of soda 
                                       //one can drink without dying
            cout<<endl<<endl<<"Enter another weight or enter 0 to exit"
            <<endl<<endl;              //Repeat Prompt        
        }
    cout<<"Goodbye!";
    //Exit program
    return 0;
}

