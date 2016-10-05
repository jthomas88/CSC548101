/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on September 16, 2016, 12:00 PM
 * Purpose: Determine if meeting attendance meets fire code
 */

//System Libraries
#include <iostream>  //Input/Output objects
using namespace std; //Namespace used in system library

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    unsigned int numMeet, //Number of people attending meeting
                 maxMeet; //Max number of people allowed
    
    //Input values
    do //Start of repeat condition
    {
        cout<<"Please enter the maximum capacity of the room: ";
        cin>>maxMeet; //Enter maximum capacity of room
        cout<<endl<<"Please enter the number of people attending: ";
        cin>>numMeet; //Enter number of people planning on attending
    
        //Display Output
        if(numMeet>maxMeet) //If the number of people attending exceeds maximum
                            //capacity, activate this branch
        {
            cout<<endl;
            cout<<"The number of people attending exceeds "
                  "fire code regulations.";
            cout<<endl<<"You must exclude "<<numMeet-maxMeet<<
                  " from this meeting";     //Displays number of people who must
                                            //sit out of meeting
        }
        else //If number of people meets fire code, activate this branch
        {
            cout<<endl;
            cout<<"This meeting does not break fire code.";
            if(maxMeet-numMeet==1) //Grammar branch ("person" if one more person
                                   //can attend, "people if 0 or 2+ can attend)
            {
                cout<<" You may invite "<<maxMeet-numMeet<<" more person.";  
            }
            else
            {
                cout<<" You may invite "<<maxMeet-numMeet<<" more people.";
            }
        }
        cout<<endl;
        cout<<"Enter 0 in both variables if you would to exit the program."; 
                                                            //Exit statement
        cout<<endl<<endl;
    }while(numMeet!=0 || maxMeet!=0); //Program will continue to run until
                                      //0 is entered in both variables
    
    
    //Exit program
    return 0;
}

