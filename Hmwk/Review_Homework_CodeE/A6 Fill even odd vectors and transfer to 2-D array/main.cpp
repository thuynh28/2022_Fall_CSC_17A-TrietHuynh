/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}

void read(vector<int> &even, vector<int> &odd){
    int size,
            val;
    cout<<"Input the number of integers to input."<<endl;
    cin>>size;
    cout<<"Input each number."<<endl;
    for(int i=0;i<size;i++){
        cin>>val;
        if(val%2==0)
            even.push_back(val);
        if(val%2==1)
            odd.push_back(val);
    }
}

void prntVec(vector<int>even, vector<int>odd,int num){
    cout<<"    Vector      Even       Odd"<<endl;
    if(even.size()<odd.size()){
        for(int i=0;i<odd.size();i++){
            if(i==(odd.size()-1))
                cout<<setw(num*3)<<odd[i]<<endl;
            else
                cout<<setw(num*2)<<even[i]<<setw(num)<<odd[i]<<endl;
        }
    }else if(odd.size()<even.size()){
        for(int i=0;i<even.size();i++){
            if(i==(even.size()-1))
                cout<<setw(num*2)<<even[i]<<"          "<<endl;
            else
                cout<<setw(num*2)<<even[i]<<setw(num)<<odd[i]<<endl;
        }
    }else{
        for(int i=0;i<even.size();i++){
            cout<<setw(num*2)<<even[i]<<setw(num)<<odd[i]<<endl;
        }
    }
}

void copy(vector<int>even, vector<int>odd,int array[][COLMAX]){
    int size;
    if(even.size()<odd.size())
        size=odd.size();
    else if(odd.size()<even.size())
        size=even.size();
    for(int i=0;i<size;i++){
        array[i][0]=even[i];
        array[i][1]=odd[i];
    }
}

void prntAry(const int array[][COLMAX],int eSize,int oSize,int num){
    cout<<"     Array      Even       Odd"<<endl;
    if(eSize<oSize){
        for(int i=0;i<oSize;i++){
            if(i==oSize-1)
                cout<<setw(num*3)<<array[i][1]<<endl;
            else
                cout<<setw(num*2)<<array[i][0]<<setw(num)<<array[i][1]<<endl;
        }
    }
    else if(oSize<eSize){
        for(int i=0;i<eSize;i++){
            if(i==eSize-1)
                cout<<setw(num*2)<<array[i][0]<<"          "<<endl;
            else
                cout<<setw(num*2)<<array[i][0]<<setw(num)<<array[i][1]<<endl;
        }
    }else{
        for(int i=0;i<eSize;i++){
            cout<<setw(num*2)<<array[i][0]<<setw(num)<<array[i][1]<<endl;
        }
    }
}