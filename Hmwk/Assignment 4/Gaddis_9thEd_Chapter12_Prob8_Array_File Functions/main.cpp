/* 
 * Author: Triet Huynh
 * Date:
 * Purpose:
 */

//System Libraries Here
#include <iostream>
#include <fstream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Constants like PI, e, Gravity, Conversions, 2D array size only!

//Function Prototypes Here
void arrayToFile(string,int *,int);
void fileToArray(string,int *,int);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed Here
    
    //Declare all Variables Here
    const int MAX_SIZE=100; //max size of array is 100
    string fileNme;
    int *arr=new int [MAX_SIZE];
    int size;
    //Input or initialize values Here
    cout<<"Enter file name: "<<endl;
    cin>>fileNme;
    cout<<"Enter array size (<=50): "<<endl;
    cin>>size;
    cout<<"Enter array contents (Integers): "<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    //Process/Calculations Here
    arrayToFile(fileNme,arr,size);
    fileToArray(fileNme,arr,size);
    //Output Located Here
    cout<<"Array Contents: "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i];
        if(i!=size-1)cout<<", ";
    }
    //delete
    delete []arr;
    //Exit
    return 0;
}

void arrayToFile(string fileNme,int *arr,int size){
    fstream file(fileNme,ios::out|ios::binary);
    file.write(reinterpret_cast<char *>(arr),size);
    file.close();
}

void fileToArray(string fileNme,int *arr,int size){
    fstream file(fileNme,ios::in|ios::binary);
    file.read(reinterpret_cast<char *>(arr),10);
    file.close();
}