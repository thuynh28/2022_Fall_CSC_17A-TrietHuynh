/* 
 * Author: Triet Huynh
 * Date: 9/2/2022
 * Purpose: Review Homework 1- 3.12
 */

//System Libraries Here
#include <iostream>
#include <fstream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
const int ROWS=3,
        COLS=30;
//Constants like PI, e, Gravity, Conversions, 2D array size only!

//Function Prototypes Here
void fileInp(char[][COLS],string);
void mnthDspl(char [][COLS]);
void ttlDspl(char [][COLS]);
void mstRain(char array[][COLS]);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed Here
    
    //Declare all Variables Here
    char wther[ROWS][COLS];
    //string fleNme;
    //Input or initialize values Here
    //fleNme="RainOrShine.txt";
    fileInp(wther,"RainOrShine.txt");
    //Process/Calculations Here
    
    //Output Located Here
    mnthDspl(wther);
    ttlDspl(wther);
    mstRain(wther);
    //Exit
    return 0;
}

//function to input data from file into array
void fileInp(char array[ROWS][COLS],string fleNme){
    ifstream inputFile;
    inputFile.open(fleNme);
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            inputFile>>array[i][j];
        }
    }
    inputFile.close();
}

//function to display rainy, sunny, cloudy days in each month
void mnthDspl(char array[ROWS][COLS]){
    int rainy,
            cloudy,
            sunny;
    for(int i=0;i<ROWS;i++){
        rainy=sunny=cloudy=0;
        for(int j=0;j<COLS;j++){
            if(array[i][j]=='R')
                rainy++;
            else if(array[i][j]=='C')
                cloudy++;
            else if(array[i][j]=='S')
                sunny++;
        }
        if(i==0)
            cout<<"June:"<<endl;
        else if(i==1)
            cout<<"July:"<<endl;
        else if(i==2)
            cout<<"August:"<<endl;
        cout<<"Total rainy days: "<<rainy<<" days"<<endl;
        cout<<"Total cloudy days: "<<cloudy<<" days"<<endl;
        cout<<"Total sunny days: "<<sunny<<" days"<<endl<<endl;
    }
}

//function to display rainy, sunny, cloudy days in all months
void ttlDspl(char array[ROWS][COLS]){
    int rainy=0,
            cloudy=0,
            sunny=0;
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            if(array[i][j]=='R')
                rainy++;
            if(array[i][j]=='C')
                cloudy++;
            if(array[i][j]=='S')
                sunny++;
        }
    }
    cout<<"Total rainy days for all months: "<<rainy<<endl;
    cout<<"Total cloudy days for all months: "<<cloudy<<endl;
    cout<<"Total sunny days for all months: "<<sunny<<endl<<endl;
}

//function to display which month has the most rain
void mstRain(char array[ROWS][COLS]){
    int rainy,
            mstRain,
            hgsMnth;
    int rnyDays[ROWS];
    for(int i=0;i<ROWS;i++){
        rainy=0;
        for(int j=0;j<COLS;j++){
            if(array[i][j]=='R')
                rainy++;
        }
        rnyDays[i]=rainy;
    }
    mstRain=rnyDays[0];
    hgsMnth=0;
    for(int i=0;i<ROWS;i++){
        if(rnyDays[i]>mstRain){
            mstRain=rnyDays[i];
            hgsMnth=i;
        }
    }
    if(hgsMnth==0)
        cout<<"June has the most rain."<<endl;
    else if(hgsMnth==1)
        cout<<"July has the most rain."<<endl;
    else if(hgsMnth==2)
        cout<<"August has the most rain."<<endl;
}
