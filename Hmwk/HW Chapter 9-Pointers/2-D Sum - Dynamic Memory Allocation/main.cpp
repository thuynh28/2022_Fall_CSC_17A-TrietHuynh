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
int **getData(int &,int &);        //Return the 2-D array and its size.
void prntDat(const int* const *,int,int);//Print the 2-D Array
void destroy(int **,int,int);       //Deallocate memory
int sum(const int * const *, int,int);    //Return the Sum
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed Here
    
    //Declare all Variables Here
    int **arr=nullptr;
    int row,
            col,
            ttl;
    //Input or initialize values Here
    arr=getData(row,col);
    //Process/Calculations Here
    ttl=sum(arr,row,col);
    //Output Located Here
    prntDat(arr,row,col);
    cout<<ttl;
    //Exit
    destroy(arr,row,col);
    return 0;
}

int **getData(int &row,int &col){
    cin>>row>>col;
    // Declare memory block of size row 
    int **arr=new int*[row];
    for(int i=0;i<row;i++){
        // Declare a memory block
        // of size col
        arr[i]=new int[col];
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    return arr;
}

void prntDat(const int* const *arr,int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j];
            if(j!=col-1)cout<<" ";
        }
        cout<<endl;
    }
}

int sum(const int * const *arr, int row,int col){
    int sum=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            sum+=arr[i][j];
        }
    }
    return sum;
}

void destroy(int **arr,int row,int col){
    delete [] arr;
    arr=nullptr;
}