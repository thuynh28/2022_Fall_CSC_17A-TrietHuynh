/* 
 * Author: Triet Huynh
 * Date: 9/2/2022
 * Purpose: Review Homework 1- 5.11
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
    short PERCENTAGE=100;
    float crntFee,      //current membership fee of 2500
            rate,       //rate of increase each year
            newFee;     //new membership fee after increase
            
    //Input or initialize values Here
    crntFee=2500;
    rate=4.0/PERCENTAGE;
    newFee=crntFee;     //fee at year 0
    //Process/Calculations Here
    for(int i=1;i<=6;i++){
        newFee=newFee*(1+rate);
        cout<<fixed<<showpoint<<setprecision(2);
        cout<<"Membership fee for the next "<<i<<" year is: "<<newFee<<"$"<<endl;
    }
    
    //Output Located Here
    
    //Exit
    return 0;
}