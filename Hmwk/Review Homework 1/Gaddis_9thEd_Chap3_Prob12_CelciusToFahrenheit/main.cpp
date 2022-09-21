/* 
 * Author: Triet Huynh
 * Date: 9/2/2022
 * Purpose: Review Homework 1- 3.12
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
    float cTemp,  //degree in Celsius
           fTemp; //degree in Fahrenheit 
    //Input or initialize values Here
    cout<<"Input current degree in Celsius: ";
    cin>>cTemp;
    //Process/Calculations Here
    fTemp=9.0/5*cTemp+32;
    //Output Located Here
    cout<<cTemp<<" degree Celsius is "<<fTemp<<" degree Fahrenheit."<<endl;
    //Exit
    return 0;
}