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
//Structures
struct Data{
    string div;             //division name
    int qutr;               //quarter
    float sales;     //quarterly sales
};
//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed Here
    
    //Declare all Variables Here
    const int NUM=4; //number of quarters and divisions
    fstream inFile;
    Data sale;
    float eastSle[NUM], //sale for each division per quarter
        westSle[NUM],
        southSle[NUM],
        northSle[NUM];
    float qtrTtl[NUM],      //total sales for each quarter
        qtrAvg[NUM];
    float westTtl,        //yearly total sale for each div
        eastTtl,
        southTtl,
        northTtl;
    float yrTtl;        //company total yearly sales
    //Input or initialize values Here
    westTtl=eastTtl=southTtl=northTtl=0;
    inFile.open("SaleReports.dat",ios::in);
    if(inFile){
        for(int i=0;i<NUM*NUM;i++){
        inFile>>sale.div>>sale.qutr>>sale.sales;
        if(sale.div=="west"){
            westSle[sale.qutr-1]=sale.sales;
        }else if(sale.div=="east"){
            eastSle[sale.qutr-1]=sale.sales;
        }else if(sale.div=="south"){
            southSle[sale.qutr-1]=sale.sales;
        }else{
            northSle[sale.qutr-1]=sale.sales;
        }
        }
        //Process Calculations Here
        for(int i=0;i<NUM;i++){
            westTtl+=westSle[i];
            eastTtl+=eastSle[i];
            southTtl+=southSle[i];
            northTtl+=northSle[i];
            qtrTtl[i]=westSle[i]+eastSle[i]+southSle[i]+northSle[i];
            cout<<"Total corporate sales for quarter "<<i+1<<" : "<<qtrTtl[i]<<endl;
        }
        yrTtl=westTtl+eastTtl+southTtl+northTtl;
        cout<<"Total yearly sales for west div: "<<westTtl<<endl;
        cout<<"Total yearly sales for east div: "<<eastTtl<<endl;
        cout<<"Total yearly sales for south div: "<<southTtl<<endl;
        cout<<"Total yearly sales for north div: "<<northTtl<<endl;
        cout<<"Total yearly sales for all div: "<<yrTtl<<endl;
    }else{
        cout<<"File cannot be opened."<<endl;
    }
    //Output Located Here
    
    //Exit
    return 0;
}