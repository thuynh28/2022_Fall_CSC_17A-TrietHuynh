/* 
 * File:
 * Author:
 * Date:
 * Purpose:
 * Version:
 */

//System Libraries - Post Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    //7 characters or less
    float first,//first input
        second,//second input
        third,//third input
        fourth;//fourth input
        
    //Initialize or input data here
    cin>>first;
    cin>>second;
    cin>>third;
    cin>>fourth;
    
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    
    //Format and display outputs here
    cout<<fixed;
    cout<<setw(9)<<setprecision(0)<<first<<setw(10)<<setprecision(1)<<first<<setw(10)<<setprecision(2)<<first<<endl;
    cout<<setw(9)<<setprecision(0)<<second<<setw(10)<<setprecision(1)<<second<<setw(10)<<setprecision(2)<<second<<endl;
    cout<<setw(9)<<setprecision(0)<<third<<setw(10)<<setprecision(1)<<third<<setw(10)<<setprecision(2)<<third<<endl;
    cout<<setw(9)<<setprecision(0)<<fourth<<setw(10)<<setprecision(1)<<fourth<<setw(10)<<setprecision(2)<<fourth;
    
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}