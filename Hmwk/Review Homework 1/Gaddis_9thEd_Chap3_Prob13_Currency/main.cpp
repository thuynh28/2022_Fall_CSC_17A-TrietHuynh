/* 
 * Author: Triet Huynh
 * Date: 9/2/2022
 * Purpose: Review Homework 1- 3.13
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Constants like PI, e, Gravity, Conversions, 2D array size only!

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed Here
    
    //Declare all Variables Here
    float dollar,       //amount in Dollar
            yen,        //amount in Yen
            euros,      //amount in Euros
            dlr2Yen,    //Dollar to Yen conversion rate 
            dlr2Eur;    //Dollar to Euros conversion rate
    //Input or initialize values Here
    dlr2Yen=98.93;
    dlr2Eur=0.74;
    cout<<"This program converts US Dollar to Yen and Euros."<<endl
            <<"Enter the US Dollar amount here: ";
    cin>>dollar;
    //Process/Calculations Here
    yen=dlr2Yen*dollar;
    euros=dlr2Eur*dollar;
    //Output Located Here
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<dollar<<"$ is "<<yen<<" Yen and "<<euros<<" Euros."<<endl;
    //Exit
    return 0;
}