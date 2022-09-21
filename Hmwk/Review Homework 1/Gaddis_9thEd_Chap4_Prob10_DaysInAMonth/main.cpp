/* 
 * Author: Triet Huynh
 * Date: 9/2/2022
 * Purpose: Review Homework 1- 4.10
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Constants like PI, e, Gravity, Conversions, 2D array size only!

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed Here
    
    //Declare all Variables Here
    int day,
        month,
        year;
    bool leap;      //true if the year entered is a leap year, false other wise
    //Input or initialize values Here
    cout<<"Enter a month (1-12): ";
    cin>>month;
    cout<<"Enter a year: ";
    cin>>year;
    //Process/Calculations Here
    if(year%100==0){
        if(year%400==0)//leap year if year divisible by 100 and 400
            leap=true;
        else
            leap=false;
    }else{
        if(year%4==0)//leap year if year is not divisible by 100 but is divisible by 4
            leap=true;
        else
            leap=false;
    }
    switch(month){
        case 1: day=31;break;
        case 2: {
            if(leap==true){
                day=29;
                break;
            }
            else{
                day=28;
                break;
            }
        }
        case 3: day=31;break;
        case 4: day=30;break;
        case 5: day=31;break;
        case 6: day=30;break;
        case 7: day=31;break;
        case 8: day=31;break;
        case 9: day=30;break;
        case 10: day=31;break;
        case 11: day=30;break;
        case 12: day=31;break;
    }
    
    //Output Located Here
    cout<<day<<" days"<<endl;
    //Exit
    return 0;
}