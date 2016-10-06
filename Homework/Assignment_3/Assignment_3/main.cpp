/* 
 * File:   main.cpp
 * Author: Jeffrey Thomas
 * Created on October 5, 2016, 11:31 PM
 * Purpose: 10 Programming Projects from Gaddis Chapter 4
 */

//System Libraries
#include <iostream> //Input/Output objects
#include <iomanip>  //Manipulate float precision

using namespace std; //Namespace used in system library

//User libraries

//Global constants
const float NEWT=9.8;  //Newton conversion constant
const char FATCAL=9;   //Calories per gram of fat
const char PERCENT=100; //Percent conversion factor

//Function prototypes

//Execution begins here
int main(int argc, char** argv) 
{
    int select;
    do
    {
        cout<<endl<<endl<<endl;
        cout<<"Select a program to run."<<endl<<endl;
        cout<<"1) Problem 2: Roman Numeral Converter"<<endl;
        cout<<"2) Problem 3: Magic Dates"<<endl;
        cout<<"3) Problem 4: Areas of Rectangles"<<endl;
        cout<<"4) Problem 5: Book Club Points"<<endl;
        cout<<"5) Problem 6: Mass and Weight"<<endl;
        cout<<"6) Problem 7: Time Calculator"<<endl;
        cout<<"7) Problem 9: Software Sales"<<endl;
        cout<<"8) Problem 12: Running the Race"<<endl;
        cout<<"9) Problem 14: Body Mass Index"<<endl;
        cout<<"10) Problem 15: Fat Gram Calculator"<<endl;
        cout<<"11) Exit Program"<<endl;
        cin>>select;
        cout<<endl<<endl<<endl;
    
        switch(select)
        {
            case 1:{
                //Declaration of variables
                unsigned short digit;  //Digit to be converted
    
                //Input values
                cout<<"Enter a digit 1 through 10 to be converted to a Roman numeral: ";
                cin>>digit;
    
                //Output case based on input
                switch(digit)
                {
                    case 1:cout<<"The Roman numeral of "<<digit<<" is I";break;
                    case 2:cout<<"The Roman numeral of "<<digit<<" is II";break;
                    case 3:cout<<"The Roman numeral of "<<digit<<" is III";break;
                    case 4:cout<<"The Roman numeral of "<<digit<<" is IV";break;
                    case 5:cout<<"The Roman numeral of "<<digit<<" is V";break;
                    case 6:cout<<"The Roman numeral of "<<digit<<" is VI";break;
                    case 7:cout<<"The Roman numeral of "<<digit<<" is VII";break;
                    case 8:cout<<"The Roman numeral of "<<digit<<" is VIII";break;
                    case 9:cout<<"The Roman numeral of "<<digit<<" is IX";break;
                    case 10:cout<<"The Roman numeral of "<<digit<<" is X";break;
                    default:cout<<"Invalid input."; //Input validation
                }break;}
            case 2:{
                //Declaration of variables
                unsigned short mn,dy,yr; //User inputted month, date, and year
    
                //Input values
                cout<<"Input the date, month, and year of the date to check: ";
                cin>>dy>>mn>>yr;
    
                //Process values and Output
                if(dy*mn==yr) //Check if month multiplied by day equals the year
                {   //Output positive
                    cout<<dy<<'/'<<mn<<'/'<<yr<<" is a magic date;";     
                }
                else
                {   //Output negative
                    cout<<dy<<'/'<<mn<<'/'<<yr<<" is not a magic date;";
                }break;}
            case 3:{
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
                }break;}
            case 4:{
                //Declaration of variables
                int numBook;
    
                //Input values
                cout<<"How many books have you purchased this month? ";
                cin>>numBook;  
    
                //Input Validation
                while(numBook<0)
                {
                    cout<<"Invalid input."<<endl;
                    cout<<"How many books have you purchased this month? ";
                    cin>>numBook; 
                }
    
                //Display output
                //Ternary operation testing for number of books purchased
                (numBook==0)?cout<<endl<<"You have earned 0 points!":
                (numBook==1)?cout<<endl<<"You have earned 5 points!":
                (numBook==2)?cout<<endl<<"You have earned 15 points!":
                (numBook==3)?cout<<endl<<"You have earned 30 points!":
                (numBook>=4)?cout<<endl<<"You have earned 60 points!":
                             cout<<"You have earned 0 points!";
                break;}
            case 5:{
                //Declaration of variables
                float mass,wgt; //Mass in kg and weight in newtons, respectively
    
                //Input values
                cout<<"Enter a mass in kg: ";
                cin>>mass;
    
                //Process values -> map inputs to outputs
                wgt=mass*NEWT;
    
                //Display output
                cout<<endl;
                if(wgt>1000) //Display too heavy message if mass exceeds 1000kg
                {
                    cout<<"Object mass: "<<mass<<"kg"<<endl;
                    cout<<"Object weight: "<<wgt<<"kg"<<endl;
                    cout<<"The object is too heavy."<<endl;
                }
                else if(wgt<10) //Display too light message if mass falls below 10kg
                {
                    cout<<"Object mass: "<<mass<<"kg"<<endl;
                    cout<<"Object weight: "<<wgt<<"kg"<<endl;
                    cout<<"The object is too light."<<endl;
                }
                else
                {
                    cout<<"Object mass: "<<mass<<"kg"<<endl;
                    cout<<"Object weight: "<<wgt<<"kg"<<endl;
                    cout<<"The object is adequate."<<endl;
                }break;}
            case 6:{
                //Declaration of variables
                unsigned int sec;          //User inputted seconds
                unsigned int day,hr,min=0; //Conversions
                //Input values
                cout<<"Enter a number of seconds to be converted: ";
                cin>>sec;
    
                //Process values -> map inputs to outputs
                if(sec>=86400)     //Check for number of days
                    day=sec/86400; //Convert seconds to days
                    sec=sec%86400; //Assign remainder to seconds value
                if(sec>=3600)      //Check for number of hours
                    hr=sec/3600;   //Convert seconds to hours
                    sec=sec%3600;  //Assign remainder to seconds value
                if(sec>=60)        //Check for number of minutes
                    min=sec/60;    //Convert seconds to minutes
                    sec=sec%60;    //Assign remainder to minutes value
                //Display output
                cout<<endl<<day<<" day(s), "<<hr<<" hour(s), "
                          <<min<<" minute(s), "<<sec<<" second(s)";
                break;}
            case 7:{
                //Declaration of variables
                unsigned short unitCst=99; //Given cost per unit
                float subTtl;              //Total cost before discount
                float finTtl;              //Total cost after discount
                int unitAmt;      //User inputted number of units
                float dsct;                //Discount %
    
                //Input values
                cout<<"Enter the number of units to be purchased: ";
                cin>>unitAmt;
    
                //Input Validation
                while(unitAmt<1)
                {
                    cout<<endl;
                    cout<<"Invalid input. Minimum purchase is 1 unit."<<endl;
                    cout<<"Enter the number of units to be purchased: ";
                    cin>>unitAmt;
                }
    
                //Process values -> map inputs to outputs
                //Ternary operator to determine discount percentage
                (unitAmt/10==1)?dsct=0.2:
                ((unitAmt/10)>=2&&(unitAmt/10)<5)?dsct=0.3:
                ((unitAmt/10)>=5&&(unitAmt/10)<10)?dsct=0.4:
                ((unitAmt/10)>=10)?dsct=0.5:dsct=0;    
    
                subTtl=unitCst*unitAmt; //Calculate subtotal
                finTtl=subTtl*dsct;     //Calculate total w/ discount
    
                //Display output
                cout<<"Subtotal: $"<<subTtl<<endl;
                cout<<"Discount: "<<dsct<<"%"<<endl;
                cout<<"Total   : $"<<finTtl<<endl;break;}
            case 8:{
                //Declaration of variables
                string runner1,runner2,runner3;         //Names of runners
                unsigned short minTim1,minTim2,minTim3; //Minute times
                unsigned short secTim1,secTim2,secTim3; //Seconds times
                unsigned int finTim1,finTim2,finTim3;   //Converted final time
    
    
                //Input values
                cout<<"Enter the first runner's name followed ";
                cout<<"by their time in minutes and seconds:";
                cin>>runner1>>minTim1>>secTim1;
                cout<<"Enter the second runner's name followed ";
                cout<<"by their time in minutes and seconds:";
                cin>>runner2>>minTim2>>secTim2;
                cout<<"Enter the third runner's name followed ";
                cout<<"by their time in minutes and seconds:";
                cin>>runner3>>minTim3>>secTim3;
    
    
                //Convert minutes and seconds to only seconds
                finTim1=(minTim1*60)+secTim1;
                finTim2=(minTim2*60)+secTim2;
                finTim3=(minTim3*60)+secTim3;
    
                //Display output
                cout<<endl;
                //Sort for runner 1 in 3rd
                if(finTim1>finTim2&&finTim1>finTim3){
                    if(finTim2>finTim3){
                        cout<<"1st: "<<runner3<<endl;
                        cout<<"2nd: "<<runner2<<endl;
                        cout<<"3rd: "<<runner1<<endl;
                    }
                    else{
                        cout<<"1st: "<<runner2<<endl;
                        cout<<"2nd: "<<runner3<<endl;
                        cout<<"3rd: "<<runner1<<endl;
                    }
                }
                //Sort for B runner 2 in 3rd
                else if(finTim2>finTim1&&finTim2>finTim3){
                    if(finTim1>finTim3){
                        cout<<"1st: "<<runner3<<endl;
                        cout<<"2nd: "<<runner1<<endl;
                        cout<<"3rd: "<<runner2<<endl;
                    }
                    else{
                        cout<<"1st: "<<runner1<<endl;
                        cout<<"2nd: "<<runner3<<endl;
                        cout<<"3rd: "<<runner2<<endl;
                    }
                }
                //Sort for runner 3 in 3rd
                else{
                    if(finTim1>finTim2){
                        cout<<"1st: "<<runner2<<endl;
                        cout<<"2nd: "<<runner1<<endl;
                        cout<<"3rd: "<<runner3<<endl;
                    }
                    else{
                        cout<<"1st: "<<runner1<<endl;
                        cout<<"2nd: "<<runner2<<endl;
                        cout<<"3rd: "<<runner3<<endl;
                    }
                }break;}
            case 9:{
                //Declaration of variables
                float height, weight; //Height and weight of the user
                float bmi;            //Calculated BMI of the user
    
                //Input values
                cout<<"Enter your height in inches and weight in lbs: ";
                cin>>height>>weight;
    
                //Process values -> map inputs to outputs
                bmi=weight*(703/(height*height)); //BMI calculation
    
                //Display output
                if(bmi>25) //Display overweight outcome
                {
                    cout<<"Height: "<<height<<"\""<<endl;
                    cout<<"Weight: "<<weight<<"lbs."<<endl;
                    cout<<"Your BMI: "<<setprecision(3)<<bmi<<endl;
                    cout<<"You are obese. Lay off the Cheetos, tubby.";
                }
                else if(bmi<18.5) //Display underweight outcome
                {
                    cout<<"Height: "<<height<<"\""<<endl;
                    cout<<"Weight: "<<weight<<"lbs."<<endl;
                    cout<<"Your BMI: "<<setprecision(3)<<bmi<<endl;
                    cout<<"You are underweight. Rattle me bones!";
                }
                else //Display optimal weight outcome
                {
                    cout<<"Height: "<<height<<"\""<<endl;
                    cout<<"Weight: "<<weight<<"lbs."<<endl;
                    cout<<"Your BMI: "<<setprecision(3)<<bmi<<endl;
                    cout<<"You are optimal weight. I'm proud of you, son.";
                }break;}
            case 10:{
                //Declaration of variables
                unsigned int usrCal,usrFat; //Amount of calories and grams of fat
                unsigned int calFF;         //Calories from fat
                unsigned short fatPct;      //Percent of calories form fat
    
                //Input values
                cout<<"Input the number of calories in a serving: ";
                cin>>usrCal;
                cout<<"Input the number of grams of fat: ";
                cin>>usrFat;
    
                //Process values -> map inputs to outputs
                calFF=usrFat*FATCAL; //Calories from fat calculation
                //Fat calorie percentage calculation
                fatPct=(static_cast<float>((calFF))/static_cast<float>(usrCal))*PERCENT;
    
                //Display output
                cout<<"Total calories: "<<usrCal<<endl;
                cout<<"Calories from fat: "<<calFF<<endl;
                cout<<"Percent of calories from fat: "<<fatPct<<"%"<<endl;
                //Notify user if food is low in fat or not
                if(fatPct<30){ 
                    cout<<"This is a low fat food.";
                }
                else{
                    cout<<"This is not a low fat food.";
                }break;}
        }
    }while(select!=11);
    
    
    //Exit program
    return 0;
}

