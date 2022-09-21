/* 
 * Author: Triet Huynh
 * Date: 9/2/2022
 * Purpose: Review Homework 1- 6.7
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Constants like PI, e, Gravity, Conversions, 2D array size only!

//Function Prototypes Here
float tmpConv(float);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed Here
    
    //Declare all Variables Here
    float cTemp,  //degree in Celsius
           fTemp; //degree in Fahrenheit 
    //Input or initialize values Here
    
    //Process/Calculations Here
    cout<<"Celsius  |  Fahrenheit"<<endl;
    for(cTemp=0;cTemp<=20;cTemp++){
        fTemp=tmpConv(cTemp);
        cout<<setw(7)<<cTemp<<"  |"<<setw(12)<<fTemp<<endl;
    }
    //Output Located Here
    
    //Exit
    return 0;
}

//function to convert from Celsius to Fahrenheit
float tmpConv(float cTemp){
    float fTemp;
    fTemp=9.0/5*cTemp+32;
    return fTemp;
}