/* 
 ** Author: Triet Huynh
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
int *getData(int &);             //Return the array size and the array from the inputs
int *sumAry(const int *,int);//Return the array with successive sums
void prntAry(const int *,int);//Print the array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed Here
    
    //Declare all Variables Here
    int *arr=nullptr,
            *sum=nullptr;
    int size;
    //Input or initialize values Here
    arr=getData(size);
    //Process/Calculations Here
    sum=sumAry(arr,size);
    //Output Located Here
    prntAry(arr,size);
    cout<<endl;
    prntAry(sum,size);
    //Exit
    delete [] arr;
    delete [] sum;
    arr=nullptr;
    sum=nullptr;
    return 0;
}

int *getData(int &size){
    cin>>size;
    //creating array dynamically
    int *arr=new int[size];
    //fill array
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    return arr;
}

int *sumAry(const int *arr,int size){
    //creating sum array dynamically
    int *sumAry=new int[size];
    //first element of sum array is same as input array
    sumAry[0]=arr[0];
    for(int i=1;i<size;i++){
        sumAry[i]=sumAry[i-1]+arr[i];
    }
    return sumAry;
}

void prntAry(const int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i];
        if(i!=size-1)cout<<" ";
    }
}