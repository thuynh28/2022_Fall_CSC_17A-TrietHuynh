/* 
 * Author: Triet Huynh
 * Date:10/21/2022 10:30AM
 * Purpose: CSC17A Midterm Problem 2 - Paycheck
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Constants like PI, e, Gravity, Conversions, 2D array size only!

//Structures
struct Paycheck{
    string name;    //employee's name
    string compNme, //company's name
        comAddr;    //company's address
    float hours;    //hours worked
    float rate;     //pay rate
    float gross;    //gross pay
};

//Function Prototypes Here
void fillArr(Paycheck [],int);
void prntChk(Paycheck [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed Here
    //Declare all Variables Here
    int numEmpl;    //number of employees
    //Input or initialize values Here
    cout<<"Enter number of employees to write checks: "<<endl;
    cin>>numEmpl;
    //Create an array of structures dynamically
    Paycheck *Emplee=new Paycheck[numEmpl];
    //Fill in the array
    cout<<"Now enter information for each employee."<<endl<<endl;
    fillArr(Emplee,numEmpl);
    //Output Located Here
    prntChk(Emplee,numEmpl);
    //Exit
    return 0;
}

void fillArr(Paycheck Emplee[],int numEmpl){
    for(int i=0;i<numEmpl;i++){
        cout<<"Employee number "<<i+1<<endl;
        cin.ignore();
        cout<<"Enter Company's Name: ";
        getline(cin,Emplee[i].compNme);
        cout<<"Enter Company's Address: ";
        getline(cin,Emplee[i].comAddr);
        cout<<"Enter employee's name: ";
        getline(cin,Emplee[i].name);
        cout<<"Enter their pay rate: ";
        cin>>Emplee[i].rate;
        //Input validation
        while(Emplee[i].rate<=0){
            cout<<"Invalid Rate. Try Again."<<endl;
            cout<<"Enter their pay rate: ";
            cin>>Emplee[i].rate;
        }
        cout<<"Enter hours worked: ";
        cin>>Emplee[i].hours;
        //Input Validation
        while(Emplee[i].hours<=0){
            cout<<"Invalid Hours Input. Try again."<<endl;
            cout<<"Enter hours worked: ";
            cin>>Emplee[i].hours;
        }
        cout<<endl;
        //calculating gross pay
        Emplee[i].gross=Emplee[i].hours>40?(Emplee[i].hours-40)*Emplee[i].rate*3+20*Emplee[i].rate*2+20*Emplee[i].rate:
            Emplee[i].hours>20?(Emplee[i].hours-20)*Emplee[i].rate*2+20*Emplee[i].rate:
                Emplee[i].hours*Emplee[i].rate;
    }
}

void prntChk(Paycheck Emplee[],int numEmpl){
    for(int i=0;i<numEmpl;i++){
        int grossInt=static_cast<int>(Emplee[i].gross);     //gross pay in integer
        int change=(Emplee[i].gross-grossInt)*100;          //pennies
        int n1000=grossInt/1000%10;
        int n100=grossInt/100%10;
        int n10=grossInt/10%10;
        int n1=grossInt%10;
        cout<<"Now Printing Check for Employee "<<i+1<<endl<<endl;
        cout<<Emplee[i].compNme<<endl;
        cout<<Emplee[i].comAddr<<endl;
        cout<<"Pay To The Order Of: "<<setw(50)<<left<<Emplee[i].name<<setw(10)<<right<<"Amount: $"<<Emplee[i].gross<<endl;
        cout<<"Amount: ";
        switch(n1000){
        case 1:cout<<"One Thousand ";break;
        case 2:cout<<"Two Thousand ";break;
        case 3:cout<<"Three Thousand ";break;
        default:break;
    }
    switch(n100){
        case 1:cout<<"One Hundred ";break;
        case 2:cout<<"Two Hundred ";break;
        case 3:cout<<"Three Hundred ";break;
        case 4:cout<<"Four Hundred ";break;
        case 5:cout<<"Five Hundred ";break;
        case 6:cout<<"Six Hundred ";break;
        case 7:cout<<"Seven Hundred ";break;
        case 8:cout<<"Eight Hundred ";break;
        case 9:cout<<"Nine Hundred ";break;
        default:break;
    }
    switch(n10){
        case 2:cout<<"Twenty ";break;
        case 3:cout<<"Thirty ";break;
        case 4:cout<<"Forty ";break;
        case 5:cout<<"Fifty ";break;
        case 6:cout<<"Sixty ";break;
        case 7:cout<<"Seventy ";break;
        case 8:cout<<"Eighty ";break;
        case 9:cout<<"Ninety ";break;
        default:break;
    }
    if(n10==1)
    {
        switch(n1){
        case 1:cout<<"Eleven ";break;
        case 2:cout<<"Twelve ";break;
        case 3:cout<<"Thirteen ";break;
        case 4:cout<<"Fourteen ";break;
        case 5:cout<<"Fifteen ";break;
        case 6:cout<<"Sixteen ";break;
        case 7:cout<<"Seventeen ";break;
        case 8:cout<<"Eighteen ";break;
        case 9:cout<<"Nineteen ";break;
        default:break;
        }
    }else{
        switch(n1){
        case 1:cout<<"One ";break;
        case 2:cout<<"Two ";break;
        case 3:cout<<"Three ";break;
        case 4:cout<<"Four ";break;
        case 5:cout<<"Five ";break;
        case 6:cout<<"Six ";break;
        case 7:cout<<"Seven ";break;
        case 8:cout<<"Eight ";break;
        case 9:cout<<"Nine ";break;
        default:break;
        }
    }
                    
    cout<<"and "<<change<<"/100's Dollars"<<endl;
    cout<<"                               Signature: "<<endl<<endl;
    }
}