/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 5, 2016, 12:47 AM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>   //Manipulate precision of the output

using namespace std; //Namespace used in system library

//User libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    float length1,length2; //lengths of the rectangles
    float width1,width2;   //widths of the rectangles
    float area1,area2;     //areas of the rectangles
    
    //Input values
    cout<<"Input the length and width of the first rectangle: ";
    cin>>length1>>width1;
    cout<<"Input the length and width of the second rectangle: ";
    cin>>length2>>width2;
    
    //Process values -> map inputs to outputs
    area1=length1*width1; //Calculate area of rectangle 1
    area2=length2*width2; //Calculate area of rectangle 2
    
    
    //Display output
    if(area1>area2) //Condition for rectangle 1 larger than rectangle 2
    {
        cout<<endl;
        cout<<"The first rectangle is larger."<<endl;
        cout<<"Rectangle 1 area: "<<setprecision(4)<<area1<<" in^2"<<endl;
        cout<<"Rectangle 2 area: "<<setprecision(4)<<area2<<" in^2"<<endl;
    }
    else if(area1<area2) //Condition for rectangle 2 larger than rectangle 1
    {
        cout<<endl;
        cout<<"The second rectangle is larger."<<endl;
        cout<<"Rectangle 1 area: "<<setprecision(4)<<area1<<" in^2"<<endl;
        cout<<"Rectangle 2 area: "<<setprecision(4)<<area2<<" in^2"<<endl;
    }
    else //Condition for rectangles both being the same size
    {
        cout<<endl;
        cout<<"Both rectangles have the same area."<<endl;
        cout<<"Rectangle 1 area: "<<setprecision(4)<<area1<<" in^2"<<endl;
        cout<<"Rectangle 2 area: "<<setprecision(4)<<area2<<" in^2"<<endl;
    }
    //Exit program
    return 0;
}

