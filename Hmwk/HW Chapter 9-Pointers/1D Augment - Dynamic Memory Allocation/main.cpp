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
int *getData(int &);//Read the array
int *augment(const int *,int);//Augment and copy the original array
void prntAry(const int *,int);//Print the array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed Here
    
    //Declare all Variables Here
    int *arr=nullptr,   //original array
            *augAry=nullptr;    //augmented array
    int size;
    //Input or initialize values Here
    arr=getData(size);
    augAry=augment(arr,size);
    //Process/Calculations Here
    
    //Output Located Here
    prntAry(arr,size);
    cout<<endl;
    prntAry(augAry,size+1);
    //Exit
    delete [] arr;
    delete [] augAry;
    arr=nullptr;
    augAry=nullptr;
    return 0;
}

int *getData(int &size){
    cin>>size;
    int *arr=new int[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    return arr;
}

int *augment(const int *arr,int size){
    int *augAry=new int[size+1];
    //place 0 in the first element and copy the rest
    //from the original shifted by 1 index
    augAry[0]=0;
    for(int i=1;i<size+1;i++){
        augAry[i]=arr[i-1];
    }
    return augAry;
}

void prntAry(const int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i];
        if(i!=size-1)cout<<" ";
    }
}