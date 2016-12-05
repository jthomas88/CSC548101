/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on December 1, 2016, 1:30 AM
 * Purpose: Assignment 8
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>   //Format tables
#include <cstdlib>   //Random Numbers
#include <ctime>     //Random Seed
#include <fstream>   //File I/O

using namespace std; //Namespace used in system library

//User libraries

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
void fillInt(int[],int);            //Fill array of ints
void fillFlt(float[],int);          //Fill array of floats
void copyAry(int[],int[],int);      //Copy existing array of ints
void readInt(int[],int,string);     //Read int data from file and put into array
void readStg(string[],int,string);  //Read string data from file and into array
void prntAry(int[],int);            //Print int array
void prntAry(string[],float[],int); //Print table with 2 data types (Problem 5)
void prntStg(string[],int);         //Print string array

//Sort Functions
void bubbSrt(int[],int);            //Bubble sort array of ints
void sortMnt(float[],string[],int); //Sort 2 parallel arrays of different types
void slctSrt(int[],int);            //Selection sort array of ints
void strgSlc(string[],int);         //Selection sort array of strings

void bubOrdr(int[],int);            //Bubble sort ints,output after each pass
void slcOrdr(int[],int);            //Selection sort ints,output after each pass

//Search Functions
bool  findMat(int[],int,int);       //Determine if a given value has been found
int   linSrch(int[],int,int);       //Linear search an int array
int   binSrch(int[],int,int);       //Binary dearch an int array
float findHig(float[],int &,int);   //Find highest value in array
float findLow(float[],int &,int);   //Find lowest value in array

//Calculation Functions
float sum(float[],int);             //Find sum of elements in an array
float avg(float[],int);             //Find average of elements in an array

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
    readInt(accts,SIZE,file);
    
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
    cout<<"Problem 2: Lottery Winners"<<endl;
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    const int SIZE=10;            //Number of lottery tickets
    int lotto=rand()%90000+10000; //Randomly selected lotto number
    //int lotto=77777;            //Test variable
    int tix[SIZE]={};             //10 Lottery tickets
    string file="tix.dat";        //File name for function call
    
    //Fill array with file data
    readInt(tix,SIZE,file);
    
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
    cout<<"Problem 3: Lottery Winners Mod (Binary)"<<endl;
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    const int SIZE=10;            //Number of lottery tickets
    int lotto=rand()%90000+10000; //Randomly selected lotto number
    //int lotto=77777;            //Test variable
    int tix[SIZE]={};             //10 Lottery tickets
    string file="tix.dat";        //File name for function call
    
    //Fill array with file data
    readInt(tix,SIZE,file);
    
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
    cout<<"4)  Problem 4: Charge Acct Validation Mod (Binary)"<<endl;
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    const int SIZE=18;       //Number of accts to search through
    int acctNum=rand()%9000000+1000000; //User's account number
    //int acctTst=5658845;   //Test variable
    int accts[SIZE]={};      //18 Account Numbers
    string file="accts.dat"; //File name for function call
    
    //Read in values from file and write into array
    readInt(accts,SIZE,file);
    
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
    cout<<endl;
    cout<<"Problem 5: Rainfall Statistics Mod (Sort)"<<endl;
    //Initialize random seed
    srand(time(0));
            
    //Declaration of variables
    int count=0; //Month array element assignment
    int YEAR=12; //Number of months in a year
    float  rainfl[YEAR]={};
    string months[YEAR]={"Jan","Feb","Mar","Apr",
                         "May","Jun","Jul","Aug",
                         "Sep","Oct","Nov","Dec"};
    
    //Fill Array
    fillFlt(rainfl,YEAR);
    
    //Output Array
    cout<<"Monthly Rainfall Data"<<endl;
    prntAry(months,rainfl,YEAR);
    cout<<endl<<endl;
    
    //Sort Arrays
    sortMnt(rainfl,months,YEAR);
    
    //Output sorted array
    cout<<"Rainfall data sorted least-to-greatest"<<endl;
    prntAry(months,rainfl,YEAR);
    cout<<endl<<endl;
    
    //Find highest value and output
    findHig(rainfl,count,YEAR);
    cout<<"Month with most rainfall: "<<months[count];
    cout<<" ("<<findHig(rainfl,count,YEAR)<<"\")";
    cout<<endl;
    
    //Find lowest value and output
    findLow(rainfl,count,YEAR);
    cout<<"Month with least rainfall: "<<months[count];
    cout<<" ("<<findLow(rainfl,count,YEAR)<<"\")";
    cout<<endl;
    
    //Find total rainfall and output
    cout<<"Total annual rainfall: "<<sum(rainfl,YEAR)<<"\"";
    cout<<endl;
    
    //Find average rainfall and output
    cout<<"Average monthly rainfall: "<<avg(rainfl,YEAR)<<"\"";
    cout<<endl;
    
    //Exit program
    cout<<endl;
}
void  prob6(){
    cout<<endl;
    cout<<"Problem 6: String Selection Sort"<<endl;
    //Declaration of variables
    int const SIZE=20;  //Number of names
    //Array of 20 names
    string names[SIZE]={"Collins, Bill","Smith, Bart","Allen, Jim", 
                        "Griffin, Jim","Stamey, Marty","Rose, Geri", 
                        "Taylor, Terri","Johnson, Jill","Allison, Jeff", 
                        "Looney, Joe","Wolfe, Bill","James, Jean",
                        "Weaver, Jim", "Pore, Bob","Rutherford, Greg",
                        "Javens, Renee","Harrison, Rose","Setzer, Cathy", 
                        "Pike, Gordon","Holland, Beth" }; 
    
    //Print Array Before Sort
    cout<<"Names before sort:"<<endl;
    prntStg(names,SIZE);
    cout<<endl<<endl;
    
    //Sort Array
    strgSlc(names,SIZE);
    
    //Print Array After Sort
    cout<<"Names after sort:"<<endl;
    prntStg(names,SIZE);
    cout<<endl;

    //Exit program
    cout<<endl;
}
void  prob7(){
    cout<<endl;
    cout<<"Problem 8: Search Benchmarks"<<endl;
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    const int SIZE=100;       //Size of array
    int search=rand()%90+10;  //Selects random two digit number to search
    int array[SIZE]={};       //100 element array
    
    //Populate array with random elements
    fillInt(array,SIZE);
    cout<<endl;
    
    //Output array
    cout<<"Original Array"<<endl;
    prntAry(array,SIZE);
    cout<<endl;
    
    //Test efficiency of linear search
    linSrch(array,search,SIZE);
    cout<<endl<<endl;
    
    //Test efficiency of binary search
    bubbSrt(array,SIZE);
    cout<<"Sorted Array"<<endl;
    prntAry(array,SIZE);
    binSrch(array,search,SIZE);
    
    //Exit program
    cout<<endl;
}
void  prob8(){
    cout<<"Problem 9:  Sorting Benchmarks"<<endl;
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    const int SIZE=100;  //Size of array
    int bubArry[SIZE]={};//100 element array for bubble sort
    int slcArry[SIZE]={};//100 element array for selection sort
    
    //Populate first array with random elements
    fillInt(bubArry,SIZE);
    
    //Copy values of first array to second array
    copyAry(bubArry,slcArry,SIZE);
    
    //Output first array
    cout<<"Bubble Array"<<endl;
    prntAry(bubArry,SIZE);
    cout<<endl;
    
    //Output second array
    cout<<"Selection Array"<<endl;
    prntAry(slcArry,SIZE);
    cout<<endl;
    
    //Test efficiency of bubble sort
    cout<<"Bubble Sorted Array"<<endl;
    bubbSrt(bubArry,SIZE);
    cout<<endl;
    prntAry(bubArry,SIZE);
    cout<<endl;
    
    //Test efficiency of linear sort
    cout<<"Selection Sorted Array"<<endl;
    slctSrt(slcArry,SIZE);
    cout<<endl;
    prntAry(slcArry,SIZE);
    cout<<endl;
    
    //Exit program
}
void  prob9(){
    cout<<endl;
    cout<<"Problem 10: Sorting Orders"<<endl;
    //Initialize random seed
    srand(time(0));
    
    //Declaration of variables
    const int SIZE=8;
    int bubArry[SIZE]={};//8 element array for bubble sort
    int slcArry[SIZE]={};//8 element array for selection sort
    
    //Populate first array with random elements
    fillInt(bubArry,SIZE);
    
    //Copy values of first array to second array
    copyAry(bubArry,slcArry,SIZE);
    
    //Output first array
    cout<<"Bubble Array"<<endl;
    prntAry(bubArry,SIZE);
    cout<<endl;
    
    //Output second array
    cout<<"Selection Array"<<endl;
    prntAry(slcArry,SIZE);
    cout<<endl<<endl;
    
    //Test efficiency of bubble sort
    cout<<"Bubble Sorted Array"<<endl;
    bubOrdr(bubArry,SIZE);
    cout<<endl;
    
    
    //Test efficiency of linear sort
    cout<<"Selection Sorted Array"<<endl;
    slcOrdr(slcArry,SIZE);
    
    //Exit program
    cout<<endl;
}
void prob10(){
    cout<<"Problem 11: String Selection Sort Mod (File I/O)"<<endl;
    //Declaration of variables
    int const SIZE=20;
    string names[SIZE]={};
    string file="names.dat";
    
    //Read in data from file
    readStg(names,SIZE,file);
    
    //Print Array Before Sort
    cout<<"Names before sort:"<<endl;
    prntStg(names,SIZE);
    cout<<endl<<endl;
    
    //Sort Array
    strgSlc(names,SIZE);
    
    //Print Array After Sort
    cout<<"Names after sort:"<<endl;
    prntStg(names,SIZE);
    cout<<endl;
    
    //Process Values
    
    //Exit program
}

//Fill and Print Functions
void fillInt(int array[],int size){
    for(int i=0;i<size;i++){
        array[i]=rand()%90+10;
    }
}
void fillFlt(float array[],int size){
    int random; //Variable to be assigned to random number
    for(int i=0;i<size;i++){
        //Assign variable to random number
        random=rand()%200; 
        //Assign array element to random number between 0.00-1.99
        array[i]=static_cast<float>(random)/100;
    }
}
void copyAry(int array[],int copy[],int size){
    for(int i=0;i<size;i++){ //Cycle through all elements of array
        copy[i]=array[i];    //Copy element of one array to another
    }
}
void readInt(int array[],int size,string file){
    ifstream read;       //Create read object
    read.open(file);     //Open file
    for(int i=0;i<size;i++){
        read>>array[i];  //Fill array
    }
    read.close();        //Close file
}
void readStg(string names[],int size,string file){
    ifstream read;              //Create read object
    read.open(file);            //Open file
    for(int i=0;i<size;i++){
        getline(read,names[i]); //Copy file data into array
    }
    read.close();               //Close file
}
void prntAry(int array[],int size){
    for(int i=0;i<size;i++){ //Ouput each element of the array
        cout<<array[i]<<' '; 
        if(i%(size/5)==(size/5)-1)cout<<endl; //Break line
    }
}
void prntAry(string names[],float array[],int size){
    int count=0;
    for(int i=0;i<size;i++){
        cout<<names[i]<<"  ";
    }
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<setprecision(2)<<fixed<<array[i]<<' ';
    }
}
void prntStg(string names[],int size){
    for(int i=0;i<size;i++){
        cout<<names[i];
        cout<<endl;
    }
}

//Sort Functions
void bubbSrt(int array[],int size){
    int  temp=0;  //Temporary variable for swap
    bool isSwap;  //Determines if variables have been swapped or not
    int  count=0; //Exchange counter
        do{
            isSwap=false; //Set swap to false
            for(int i=-1;i<size-1;i++){
                //Swap if current variable is larger than next
                if(array[i]>array[i+1]){ 
                    temp=array[i];
                    array[i]=array[i+1];
                    array[i+1]=temp;
                    isSwap=true; //Set swap to true after swap
                    count++; //Increment exchange counter
                }
            }
        }while(isSwap);
    //Output required number of exchanges to complete    
    cout<<"Bubble required "<<count<<" exchanges to complete the sort.";
    cout<<endl;
}
void sortMnt(float rain[],string month[],int size){
    float rnTemp;0.0f; //Temp float value for swapping
    string mnTemp;     //Temp string value for swapping
    bool isSwap;       //Check if swap has occurred
        do{
            isSwap=false; //Set swap check to false
            for(int i=-1;i<size-1;i++){
                //Swap float values if needed
                if(rain[i]>rain[i+1]){
                    rnTemp=rain[i];
                    rain[i]=rain[i+1];
                    rain[i+1]=rnTemp;
                    isSwap=true; //Set swap check to true
                    //Swap corresponding month value
                    mnTemp=month[i];
                    month[i]=month[i+1];
                    month[i+1]=mnTemp;                 
                }
            }
        }while(isSwap); //Loop until all swapped     
}
void slctSrt(int array[],int size){
    int count=0; //Initialize exchange counter
    for(int i=0;i<size-1;i++){
        int mIndx=i;               //Set lowest index
        int minVal=array[i];       //Set lowest known value
        for(int j=i+1;j<size;j++){ //Loop through array elements
            if(array[j]<minVal){   //Swap elements if one is larger than other
                minVal=array[j];   //Set lowest known value
                mIndx=j;           //Set index of lowest value
                count++;           //Increment exchange counter
            }
        }
        array[mIndx]=array[i];     //Set outer loop position to lowest index
        array[i]=minVal;           //Set position to lowest known value
        count++;                   //Increment exchange counter
    }
    cout<<"Selection required "<<count<<" exchanges to complete the sort.";
}
void strgSlc(string names[],int size){
    for(int i=0;i<size-1;i++){
        int mIndx=i;               //Set lowest index
        string minVal=names[i];    //Set lowest known value
        for(int j=i+1;j<size;j++){ //Loop through array elements
            if(names[j]<minVal){   //Swap elements if one is larger than other
                minVal=names[j];   //Set lowest known value
                mIndx=j;           //Set index of lowest value
            }
        }
        names[mIndx]=names[i];     //Set outer loop position to lowest index
        names[i]=minVal;           //Set position to lowest known value
    }
}
void bubOrdr(int array[],int size){
    int temp=0;  //Temporary variable for swap
    int count=0; //Pass counter
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
        count++; //Increment pass counter
        cout<<"Pass "<<count<<": "; //Output current pass
        cout<<endl;
        prntAry(array,size);        //Output sort on current pass
        cout<<endl;
    }while(isSwap);
}
void slcOrdr(int array[],int size){
    int count=0; //Initialize pass counter
    for(int i=0;i<size-1;i++){
        int mIndx=i;                //Set lowest index
        int minVal=array[i];        //Set lowest known value
        for(int j=i+1;j<size;j++){  //Loop through array elements
            if(array[j]<minVal){    //Swap elements if one is larger than other
                minVal=array[j];    //Set lowest known value
                mIndx=j;            //Set index of lowest value
            }
        }
        array[mIndx]=array[i];      //Set outer loop position to lowest index
        array[i]=minVal;            //Set position to lowest known value
        count++;                    //Increment pass counter
        cout<<"Pass "<<count<<": "; //Output current pass
        cout<<endl;       
        prntAry(array,size);        //Output array at current pass
        cout<<endl;
    }
}

//Search Functions
bool  findMat(int array[],int match,int size){
    for(int i=0;i<size;i++){ //Loops for as many elements are in the array
        if(match==array[i]){ //Loop stops if match is found
            return 0;        //Return True
        }
    }
    return 1;                //Return false if no match is found
}
int   linSrch(int array[],int search,int size){
    for(int i=0;i<size;i++){  //Loop through each element of array
        if(search==array[i]){ //Stop search if there is a match
            //Output number of searches needed to find 
            cout<<"Linear: "<<search<<" required "<<i+1<<" searches to find.";
            cout<<endl;
            return search; //Return search query
        }
    }
    //Output failure to find
    cout<<"Linear: "<<search<<" is not present in this array.";
    return -1; //Return false flag
}
int   binSrch(int array[],int match,int size){
    //Declare and setup
    int numMove=0;    //Number of operations needed to perform search
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
            numMove++;         //Increment exchange counter
        }
        else if(array[mid]<match){ //Cut off bottom half of array
            beg=mid+1;             //Set new begin point
            numMove++;             //Increment exchange counter
        }else{                     //Cut off top half of array
            end=mid-1;             //Set new end point
            numMove++;             //Increment exchange counter
        }
    }while(end>=beg&&found!=true); //Continue looping until found
    if(found==true){               //Output number of searches
        cout<<endl;
        cout<<"Binary: "<<match<<" required "<<numMove<<" searches to find. ";
    }
    else{                          //Output failure to find number
        cout<<endl;
        cout<<"Binary: "<<match<<" is not present in this set. ";
    }
    return pos;                    //Output position
}
float findHig(float array[],int &count,int size){
    float high=0; //Initialize high
    for(int i=0;i<size;i++){ //Search through array for higher value
        if(array[i]>high){   
            high=array[i];   //Set high to new high value
            count=i;         //Set month reference counter to position in array
        }
    }
    return high;             //Return highest number
}
float findLow(float array[],int &count,int size){
    float high=0;  //Initialize high
    float low=0;   //Initialize low
    for(int i=0;i<size;i++){ //Search through array for higher value
        if(array[i]>high){
            high=array[i];   //Set high to new highest value
        }
    }
    for(int i=0;i<size;i++){ //Search again for lowest number
        if(array[i]<high){
            low=array[i];    //Set low to new lowest value    
            high=low;        //Set high to new lowest value
            count=i;         //Set month reference counter to position in array
        }
    }
    return low;              //Return lowest number
}

//Calculation Functions
float sum(float array[],int size){
    float total=0; //Initialize total to 0
    for(int i=0;i<size;i++){ //Loop through all elements
        total+=array[i];     //Sum each element into total
    }
    return total;            //Return sum
}
float avg(float array[],int size){
    float average=0; //Initialize average to 0
    for(int i=0;i<size;i++){
        average+=array[i]; //Sum all values in the array
    }
    average=average/size;  //Divide sum by number of elements
    return average;        //Return average
}