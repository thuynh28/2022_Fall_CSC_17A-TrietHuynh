/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 22nd, 2021, 1:30 PM
 * Purpose:  Compare 1 and 2 Dimensional Dynamic Arrays
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions and Array Dimension


//Function Prototypes Here
void prntVec(vector<int> &,int);
void prntVec(vector<vector<int>> &,int,int);
void fillVec(vector<int> &,int,int,int);
void fillVec(vector<vector<int>> &,int,int);
void fillVec(vector<vector<int>> &,vector<int> &,int,int);
void swap(int &,int &);
void smlLst(vector<int> &,int);
void mrkSort(vector<int> &);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    int rowsize=4;//Row size for both 1 and 2 D arrays
    int colsize=3;//The column size for a 2 dimensional Array
    vector<int>avec(rowsize);
    vector<int>bvec(rowsize);
    vector<int>cvec(rowsize);
    
    //int **table;
    vector<int>row(colsize);
    vector<vector<int>>table(rowsize,row);
    int lowRng=100,highRng=999;
    int perLine=4;
        
    //Fill each parallel array
    fillVec(avec,rowsize,highRng/100,lowRng/100);
    fillVec(bvec,rowsize,highRng/10,lowRng/10);
    fillVec(cvec,rowsize,highRng,lowRng);
    
    //Sort the array the for all positions
    mrkSort(avec);
    mrkSort(bvec);
    mrkSort(cvec);
    
    //Fill the 2-D array
    fillVec(table,rowsize,colsize);
    fillVec(table,avec,rowsize,0);
    fillVec(table,bvec,rowsize,1);
    fillVec(table,cvec,rowsize,2);
    
    //Print the values in the array
    prntVec(avec,perLine);
    prntVec(bvec,perLine);
    prntVec(cvec,perLine);
    prntVec(table,rowsize,colsize);
    

    //Exit
    return 0;
}

void fillVec(vector<vector<int>> &a,vector<int> &c,int rowSize,int wchCol){
    for(int row=0;row<rowSize;row++){
        a[row][wchCol]=c[row];
    }
}

void fillVec(vector<int> &a,int n,int hr,int lr){
    for(int indx=0;indx<a.size();indx++){
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}

void fillVec(vector<vector<int>> &a,int rows,int cols){
    //Fill it with 0's
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            a[row][col]=0;
        }
    }
}

void prntVec(vector<vector<int>> &a,int rowsize,int colsize){
     cout<<endl<<"The Vector Values"<<endl;
    for(int row=0;row<rowsize;row++){
        for(int col=0;col<colsize;col++){
            cout<<setw(4)<<a[row][col];
        }
        cout<<endl;
    }
}

void prntVec(vector<int> &a,int perLine){
    //Print the values in the array
    cout<<endl<<"The Vector Values"<<endl;
    for(int indx=0;indx<a.size();indx++){
        cout<<a[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}


void mrkSort(vector<int> &a){
    for(int pos=0;pos<a.size()-1;pos++){
        smlLst(a,pos);
    }
}

void smlLst(vector<int> &a,int pos){
    for(int i=pos+1;i<a.size();i++){
        if(a[pos]>a[i]){
            swap(a[pos],a[i]);
        }
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}