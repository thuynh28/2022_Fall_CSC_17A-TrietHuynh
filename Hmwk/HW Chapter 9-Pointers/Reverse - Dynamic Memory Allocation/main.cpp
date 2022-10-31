/* 
 * Author: Triet Huynh
 * Date: 9/17/2022
 * Purpose: pointer homework
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Constants like PI, e, Gravity, Conversions, 2D array size only!

//Function Prototypes Here
int *getData(int &);               //Fill the array
int *sort(const int *,int);         //Sort smallest to largest
int *reverse(const int *,int);  //Sort in reverse order
void prntDat(const int *,int); //Print the array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed Here
    
    //Declare all Variables Here
    int *arr=nullptr;
    int *revrse=nullptr;
    int size;
    //Input or initialize values Here
    arr=getData(size);
    //Process/Calculations Here
    arr=sort(arr,size);
    revrse=reverse(arr,size);
    //Output Located Here
    prntDat(arr,size);
    cout<<endl;
    prntDat(revrse,size);
    //Exit
    delete [] arr;
    delete [] revrse;
    arr=nullptr;
    revrse=nullptr;
    return 0;
}

int *getData(int &size){
    cin>>size;
    int *arr=new int [size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    return arr;
}

int *sort(const int *arr,int size){
    int *copy=new int [size];
    for(int i=0;i<size;i++){
        copy[i]=arr[i];
    }
    int minIndx,
            minVal;
    for(int start=0;start<size-1;start++){
        minVal=copy[start];
        minIndx=start;
        for(int indx=start+1;indx<size;indx++){
            if(copy[indx]<minVal){
                minIndx=indx;
                minVal=copy[indx];
            }
        }
        int temp=copy[start];
        copy[start]=copy[minIndx];
        copy[minIndx]=temp;
    }
    return copy;
}

int *reverse(const int *arr,int size){
    int *copy=new int[size];
    for(int i=0;i<size;i++){
        copy[i]=arr[i];
    }
    int maxIndx,
            maxVal;
    for(int start=0;start<size-1;start++){
        maxVal=copy[start];
        maxIndx=start;
        for(int indx=start+1;indx<size;indx++){
            if(copy[indx]>maxVal){
                maxIndx=indx;
                maxVal=copy[indx];
            }
        }
        int temp=copy[start];
        copy[start]=copy[maxIndx];
        copy[maxIndx]=temp;
    }
    return copy;
}

void prntDat(const int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i];
        if(i!=size-1)cout<<" ";
    }
}