/* 
 * Author: Triet Huynh
 * Date: 9/17/2022
 * Purpose: pointer homework-mode
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Constants like PI, e, Gravity, Conversions, 2D array size only!

//Function Prototypes Here
int *getData(int &);         //Return the array size and the array
void prntDat(int *,int);    //Print the integer array
float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *,int);     //Print the median Array
int *copy(int *,int );      //copy the original array for sorting
void selSort(int *,int);    //sort the copy array to find median

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed Here
    
    //Declare all Variables Here
    int size;
    int *num=nullptr;
    float *med=nullptr;
    //Input or initialize values Here
    num=getData(size);
    //Process/Calculations Here
    med=median(num,size);
    //Output Located Here
    prntDat(num,size);
    prntMed(med,size);
    //Exit
    return 0;
}

int *getData(int &size){
    cin>>size;
    int *num= new int [size];
    for(int i=0;i<size;i++){
        cin>>num[i];
    }
    return num;
}

void prntDat(int *num,int size){
    for(int i=0;i<size;i++){
        cout<<*(num+i)<<" ";
    }
    cout<<endl;
}

int *copy(int *num,int size){
    //Declare and allocate an array
    int *copy=new int[size];
    //Fill with passed array
    for(int i=0;i<size;i++){
        copy[i]=num[i];
    }
    //Return the copy
    return copy;
}

void selSort(int *num,int size){
    int minIndx,
            minVal;
    for(int start=0;start<(size-1);start++){
        minIndx=start;
        minVal=num[start];
        for(int indx=start+1;indx<size;indx++){
            if(num[indx]<minVal){
                minIndx=indx;
                minVal=num[indx];
            }
        }
        int temp=num[start];
        num[start]=num[minIndx];
        num[minIndx]=temp;
    }
}

float *median(int *num,int size){
    int *copyAry=new int[size];
    float med;
    float *median=new float[size+2];
    //copy the original array to sort and find median
    copyAry=copy(num,size);
    selSort(copyAry,size);
    //converting values in integer arrays to floats and store in median array
    for(int i=2;i<size+2;i++){
        median[i]=num[i-2]*1.0f;
    }
    //finding median
    //when there is an odd amount of numbers
    if(size%2==1){
        med=copyAry[size/2];
    //when there is an even amount of numbers
    }else if(size%2==0){
        med=(copyAry[size/2-1]+copyAry[size/2])/2.0;
    }
    //fill in the first 2 slots in median array
    median[0]=size+2;
    median[1]=med;
    //delete dynamic pointers
    delete [] copyAry;
    //return
    return median;
}

void prntMed(float *median,int size){
    cout<<median[0]<<" ";
    for(int i=1;i<size+2;i++){
        cout<<fixed<<showpoint<<setprecision(2);
        cout<<median[i]<<" ";
    }
    cout<<endl;
}