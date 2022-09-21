/* 
 * Author: Triet Huynh
 * Date: 9/2/2022
 * Purpose: Review Homework 1- 3.12
 */

//System Libraries Here
#include <iostream>
#include <string>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Constants like PI, e, Gravity, Conversions, 2D array size only!

//Function Prototypes Here
void selSort(string [], int);
int brySrch(string [], int, string);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed Here
    
    //Declare all Variables Here
    const int NUM_NMES=20;
    string names[NUM_NMES]={"Collins, Bill","Smith, Bart","Allen, Jim",
                            "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                            "Taylor, Terri", "Johnson, Jill",
                            "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                            "James, Jean", "Weaver, Jim", "Pore, Bob",
                            "Rutherford, Greg", "Javens, Renee",
                            "Harrison, Rose", "Setzer, Cathy",
                            "Pike, Gordon", "Holland, Beth"};
    int pos;
    string name;
    //Input or initialize values Here
    cout<<"Enter name to search: ";
    getline(cin,name);
    //Process/Calculations Here
    selSort(names,NUM_NMES);
    pos=brySrch(names,NUM_NMES,name);
    //Output Located Here
    cout<<name<<" is in position "<<pos<<" on the list."<<endl;
    //Exit
    return 0;
}

//function to selection sort array with strings
void selSort(string array[], int size){
    int minIndx;
    string minVal;
    for(int start=0;start<size-1;start++){
        minIndx=start;
        minVal=array[start];
        for(int indx=start+1;indx<size;indx++){
            if(array[indx]<minVal){
                minVal=array[indx];
                minIndx=indx;
            }
        }
        string temp;
        temp=array[start];
        array[start]=array[minIndx];
        array[minIndx]=temp;
    }
}

//function to binary search array with strings
int brySrch(string array[], int size, string val){
    int first=0,
            last=size-1,
            middle,
            pos=-1;
    bool found=false;
    while(!found&&first<=last){
        middle=(first+last)/2;
        if(array[middle]==val){
            found=true;
            pos=middle;
        }
        else if(array[middle]>val)
            last=middle-1;
        else
            first=middle+1;
    }
    return pos;
}