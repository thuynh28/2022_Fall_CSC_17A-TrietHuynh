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
    const int NUM_REPRTS=16; //4 divisions x 4 quarters
    Data slReprt;
    fstream file("SaleReports.dat",ios::out);
    //Input or initialize values Here
    for(int i=0;i<NUM_REPRTS;i++){
        file<<endl;
        cout<<"Enter Division Name (East, West, North or South): ";
        cin>>slReprt.div;
        file<<slReprt.div<<endl;
        cout<<"Enter Quarter (1, 2, 3, or 4): ";
        cin>>slReprt.qutr;
        file<<slReprt.qutr<<endl;
        cout<<"Enter Quarterly Sales: ";
        cin>>slReprt.sales;
        //input validation
        while(slReprt.sales<0){
            cout<<"Enter Quarterly Sales: ";
            cin>>slReprt.sales;
        }
        file<<slReprt.sales<<endl;
    }
    //Process/Calculations Here
    file.close();
    //Output Located Here
    
    //Exit
    return 0;
}