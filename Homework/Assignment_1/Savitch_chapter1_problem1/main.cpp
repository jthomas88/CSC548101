/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on September 10, 2016, 5:31 PM
 * Purpose: Determine number of peas from given number of pods and peas per pod.
 */

//System Libraries
#include <iostream>  //Input/Output objects

using namespace std; //Namespace used in system library

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration of variables
    unsigned int numPods, //Number of pea pods
                 perPod,  //Number of peas per pod
                 totPeas; //Total number of peas
    
    //Input values
    cout << "Press return after entering a number.\n";
    cout << "Enter the number of pods: \n";
    cin >> numPods;
    cout << "Enter the number of peas in a pod: \n";
    cin >> perPod;
    
    
    //Process values -> map inputs to outputs
    totPeas = numPods * perPod; //Generates total number of peas
    
    //Display output
    cout << "If you have " << numPods << "pea pods\n";
    cout << "and " << perPod << " peas in each pod, then\n";
    cout << "you have " << totPeas << " peas in all the pods.\n";
    
    //Exit program
    return 0;
}

