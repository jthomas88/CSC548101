/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on Month, Day, Year, Time
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/Output objects
#include <iomanip>   //Table Formatting
#include <cstdlib>   //Random Generator
#include <ctime>     //Random Seed

using namespace std; //Namespace used in system library

//User libraries

//Global constants
const int SIZE1=10;  //Problem 1 Array Size
const int MONTHS=12; //Problem 2 Array Size  (Number of months in a year)
const int FLAVOR=5;  //Problem 3 Array Size  (Number of salsa flavors)
const int SIZE4=100; //Problem 4 and 7 Array Size
const int MONKEYS=3; //Problem 5 Row Size    (Number of monkeys in the zoo)
const int WEEKDAY=5; //Problem 5 Column Size (Number of weekdays in a week)


//Function prototypes
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

//Problem 1 functions
void fillInt(int[],int);
void prntInt(int[],int);

int  higInt(int[],int&,int);
int  lowInt(int[],int&,int);

//Problem 2 functions
void fillFlt(float[],int);
void prntFlt(string[],float[],int);

float higFlt(float[],int&,int);
float lowFlt(float[],int&,int);

float sumFlt(float[],int);
float avgFlt(float[],int);

//Problem 3 functions
void prntSal(string[],string[],int[],int);

//Problem 4 functions
void lrgThnN(int,int[],int);

//Problem 5 Functions
void fill2D(int[][WEEKDAY]);
void prnt2D(int[][WEEKDAY]);

int hig2D(int[][WEEKDAY]);
int low2D(int[][WEEKDAY]);

float avg2D(int[][WEEKDAY]);

//Problem 7 functions
int   sumInt(int[],int);
float avgInt(int[],int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Declare variables
    int menuCho;
    
    //Open Menu
    do{
        cout<<"1)  Problem 1: Largest/Smallest Array Values"<<endl;
        cout<<"2)  Problem 2: Rainfall Statistics"<<endl;
        cout<<"3)  Problem 3: Chips and Salsa"<<endl;
        cout<<"4)  Problem 4: Larger Than N"<<endl;
        cout<<"5)  Problem 5: Monkey Business"<<endl;
        cout<<"6)  Problem F"<<endl;
        cout<<"7)  Problem 7: Number Analysis"<<endl;
        cout<<"8)  Problem H"<<endl;
        cout<<"9)  Problem I"<<endl;
        cout<<"10) Problem J"<<endl;
        cin>>menuCho;
        cout<<endl;
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

void  prob1(){
    cout<<"Problem 1: Largest/Smallest Array Values"<<endl;
    //Initialize random seed
    srand(time(0));
            
    //Declaration of variables
    int array[SIZE1]={};
    int null;
    
    //Fill Array
    fillInt(array,SIZE1);
    
    //Output Array
    prntInt(array,SIZE1);
    cout<<endl;
    
    //Find highest value and output
    cout<<"Highest Value: "<<higInt(array,null,SIZE1);
    cout<<endl;
    
    //Find lowest value and output
    cout<<"Lowest Value: "<<lowInt(array,null,SIZE1);
    cout<<endl;
}
void  prob2(){
    cout<<"Problem 2: Rainfall Statistics"<<endl;
    //Initialize random seed
    srand(time(0));
            
    //Declaration of variables
    int count=0; //Month array element assignment
    
    float  rainfl[MONTHS]={};
    string months[MONTHS]={"Jan","Feb","Mar","Apr",
                         "May","Jun","Jul","Aug",
                         "Sep","Oct","Nov","Dec"};
    
    //Fill Array
    fillFlt(rainfl,MONTHS);
    
    //Output Array
    prntFlt(months,rainfl,MONTHS);
    cout<<endl<<endl;
    
    //Find highest value and output
    higFlt(rainfl,count,MONTHS);
    cout<<"Month with most rainfall: "<<months[count];
    cout<<" ("<<higFlt(rainfl,count,MONTHS)<<"\")";
    cout<<endl;
    
    //Find lowest value and output
    lowFlt(rainfl,count,MONTHS);
    cout<<"Month with least rainfall: "<<months[count];
    cout<<" ("<<lowFlt(rainfl,count,MONTHS)<<"\")";
    cout<<endl;
    
    //Find total rainfall and output
    cout<<"Total annual rainfall: "<<sumFlt(rainfl,MONTHS)<<"\"";
    cout<<endl;
    
    //Find average rainfall and output
    cout<<"Average monthly rainfall: "<<avgFlt(rainfl,MONTHS)<<"\"";
    cout<<endl;
}
void  prob3(){
    cout<<"Problem 3: Chips and Salsa"<<endl;
    //Initialize string array with 5 different flavors of salsa
    string flavor[FLAVOR]={"Mild","Medium","Sweet","Hot","Zesty"};
    
    //Spacer values to format table
    string spacer[FLAVOR]={"  ",""," ","   "," "};
    
    //Initialize sales array
    int    sales[FLAVOR]={};    
    
    //Set counter
    int counter=0;
    
    //Fill sales array
    fillInt(sales,FLAVOR);
    
    //Display table of sales
    prntSal(flavor,spacer,sales,FLAVOR);
    cout<<endl;
    
    //Find highest value in the array
    higInt(sales,counter,FLAVOR);
    
    //Display best selling flavor
    cout<<"The most popular flavor was "<<flavor[counter]
        <<" with "<<higInt(sales,counter,FLAVOR)<<" sales.";
    cout<<endl;
    
    //Find lowest value in the array
    lowInt(sales,counter,FLAVOR);
    
    //Display worst selling flavor
    cout<<"The least popular flavor was "<<flavor[counter]
        <<" with "<<lowInt(sales,counter,FLAVOR)<<" sales."; 
    cout<<endl;
}
void  prob4(){
    cout<<"Problem 4: Larger Than N"<<endl;
    //Initialize random seed
    srand(time(0));
            
    //Declaration of variables
    int n=rand()%90+10; //Assigns N to random 2 digit number
    
    int array[SIZE4]={};
    
    //Fill Array
    fillInt(array,SIZE4);
    
    //Output Array
    prntInt(array,SIZE4);
    cout<<endl;
    
    //Output specified value
    cout<<"Chosen value: "<<n;
    cout<<endl;
    
    //Find values greater than n and output;
    lrgThnN(n,array,SIZE4);
    cout<<endl;
}
void  prob5(){
    cout<<"Problem 5: Monkey Business"<<endl;
    //Initialize random seed
    srand(time(0));
            
    //Declaration of variables
    int mnkCoun=0; //Monkey array element assignment
    int dayCoun=0; //Day array element assignment
    
    int mnkFood[][WEEKDAY]={}; //Monkey food data array
    
    //Fill Array
    fill2D(mnkFood);
    
    //Output table header
    cout<<"          ";
    for(int i=0;i<WEEKDAY;i++){
        cout<<"Day "<<i+1<<"  ";
    }
    cout<<endl;
    
    //Output Array
    prnt2D(mnkFood);
    cout<<endl;
    
    //Find most food eaten and output
    cout<<"Most food eaten this week: "<<hig2D(mnkFood)<<" lbs.";
    cout<<endl;
    
    //Find least food eaten and output
    cout<<"Least food eaten this week: "<<low2D(mnkFood)<<" lbs.";
    cout<<endl;
    
    //Find average consumption and output
    cout<<"Average daily consumption: ";
    cout<<setprecision(2)<<avg2D(mnkFood)<<" lbs.";
    cout<<endl;
}
void  prob6(){
    cout<<"Problem F"<<endl;
    //Input
    //Process
    //Output
}
void  prob7(){
    cout<<"Problem 7: Number Analysis"<<endl;
    //Initialize random number seed
    srand(time(0));
    //Declaration of variables
    int data[SIZE4]={};
    int null;
    
    //Fill array and write to file
    fillInt(data,SIZE4);
    
    //Read array from file and output
    prntInt(data,SIZE4);
    cout<<endl<<endl;
    
    //Find lowest value and output
    cout<<"The lowest value in this set is: "<<lowInt(data,null,SIZE4);
    cout<<endl;
    
    //Find highest value and output
    cout<<"The highest value in this set is: "<<higInt(data,null,SIZE4);
    cout<<endl;
    
    //Find sum of all numbers and output
    cout<<"The sum of all values is: "<<sumInt(data,SIZE4);
    cout<<endl;
    
    //Find sum of all numbers and output
    cout<<"The average of all values is: "<<avgInt(data,SIZE4); 
    cout<<endl;
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





//Fill Array (Prob 1)
void fillInt(int array[],int size){
    for(int i=0;i<size;i++){
        array[i]=rand()%90+10;
    }
}

//Print Array (Prob 1)
void prntInt(int array[],int size){
    int count=0;
    for(int i=0;i<size;i++){
        cout<<array[i]<<' ';
        if(count++==9){
            cout<<endl;
            count=0;
        }
    }
}

//Find Highest (Prob 1)
int higInt(int array[],int &count,int size){
    int high=0;
    for(int i=0;i<size;i++){
        if(array[i]>high){
            high=array[i];
            count=i;
        }
    }
    return high;
}

//Find Lowest (Prob 1)
int lowInt(int array[],int &count,int size){
    int high=0;
    int low=0;
    for(int i=0;i<size;i++){
        if(array[i]>high){
            high=array[i];
        }
    }
    for(int i=0;i<size;i++){
        if(array[i]<high){
            low=array[i];
            high=low;
            count=i;
        }
    }
    return low;
}


//Fill Array (Prob 2)
void fillFlt(float array[],int size){
    int random;
    for(int i=0;i<size;i++){
        random=rand()%200;
        array[i]=static_cast<float>(random)/100;
    }
}

//Print Array (Prob 2)
void prntFlt(string names[],float array[],int size){
    int count=0;
    for(int i=0;i<size;i++){
        cout<<names[i]<<"  ";
    }
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<setprecision(2)<<fixed<<array[i]<<' ';
    }
}

//Calculate Sum
float sumFlt(float array[],int size){
    float total=0;
    for(int i=0;i<size;i++){
        total+=array[i];
    }
    return total;
}

//Calculate Average
float avgFlt(float array[],int size){
    float average=0;
    for(int i=0;i<size;i++){
        average+=array[i];
    }
    average=average/size;
    return average;
}

//Find Highest (Prob 2)
float higFlt(float array[],int &count,int size){
    float high=0;
    for(int i=0;i<size;i++){
        if(array[i]>high){
            high=array[i];
            count=i;
        }
    }
    return high;
}

//Find Lowest (Prob 2)
float lowFlt(float array[],int &count,int size){
    float high=0;
    float low=0;
    for(int i=0;i<size;i++){
        if(array[i]>high){
            high=array[i];
        }
    }
    for(int i=0;i<size;i++){
        if(array[i]<high){
            low=array[i];        
            high=low;
            count=i;
        }
    }
    return low;
}


//Print Array (Prob 3)
void prntSal(string flavor[],string spacer[],int sales[],int size){
    for(int i=0;i<size;i++){
        cout<<flavor[i]<<spacer[i]<<' '<<sales[i];
        cout<<endl;
    }
}


//Find Values Larger Than N (Prob 4)
void lrgThnN(int n,int array[],int size){
    int count=0;
    for(int i=0;i<size;i++){        
        if(array[i]>n){
            cout<<array[i]<<' ';
            count++;
        }
        if(count==10){
            cout<<endl;
            count=0;
        }
    }
}


//Fill 2D Array (Prob 5)
void fill2D(int array[][WEEKDAY]){
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

//Print 2D Array (Prob 5)
void prnt2D(int array[][WEEKDAY]){
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

//Find Highest Value in 2D Array (Prob 5)
int hig2D(int array[][WEEKDAY]){
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

//Find Lowest Value in 2D Array (Prob 5)
int low2D(int array[][WEEKDAY]){
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

//Find 2D array average (Prob 5)
float avg2D(int array[][WEEKDAY]){
    float average=0;
    for(int row=0;row<MONKEYS;row++){
        for(int col=0;col<WEEKDAY;col++){
            average+=array[row][col];
        }
    }
    average=average/(MONKEYS*WEEKDAY);
    return average;
}


//Find sum of all values (Prob 7)
int sumInt(int data[],int size){
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=data[i];
    }
    return sum;
}

//Find average of all values (Prob 7)
float avgInt(int data[],int size){
    int   sum=0;
    float avg=0.0f;
    for(int i=0;i<size;i++){
        sum+=data[i];
    }
    avg=static_cast<float>(sum)/size;
    return avg;
}