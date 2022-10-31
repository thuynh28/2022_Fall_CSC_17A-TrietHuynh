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
int **getData(int &,int &);//Get the Matrix Data
void printDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed Here
    
    //Declare all Variables Here
    int **ary=nullptr,  //original array
            **augAry=nullptr;   //augmented array
    int row,    //number of rows
            col;    //number of columns
    //Input or initialize values Here
    ary=getData(row,col);
    augAry=augment(ary,row,col);
    //Process/Calculations Here
    
    //Output Located Here
    printDat(ary,row,col);
    cout<<endl;
    printDat(augAry,row+1,col+1);
    //Exit
    destroy(ary,row);
    destroy(augAry,row);
    return 0;
}

int **getData(int &row,int &col){
    cin>>row>>col;
    // Declare memory block of size row 
    int **ary=new int*[row];
    for(int i=0;i<row;i++){
        // Declare a memory block
        // of size col
        ary[i]=new int[col];
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>ary[i][j];
        }
    }
    return ary;
}

int **augment(const int * const *ary,int row,int col){
    int **augAry=new int*[row+1];
    for(int i=0;i<row+1;i++){
        augAry[i]=new int[col+1];
    }
    for(int i=0;i<row+1;i++){
        for(int j=0;j<col+1;j++){
            //copy with 0's in the 1st row and column
            if(i==0||j==0)
                augAry[i][j]=0;
            //fill the other rows and columns using the original array
            else
                augAry[i][j]=ary[i-1][j-1];
        }
    }
    return augAry;
}

void printDat(const int * const *ary,int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<ary[i][j];
            if(j!=col-1)cout<<" ";
        }
        if(i!=row-1)cout<<endl;
    }
}

void destroy(int **ary,int num){
    delete [] ary;
    ary=nullptr;
}