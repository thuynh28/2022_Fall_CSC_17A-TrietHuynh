/* 
 * Author: Triet Huynh
 * Date: 10/20/2022 6:00PM
 * Purpose: CSC 17A Midterm Problem 1
 */

//System Libraries Here
#include <iostream>
#include <string>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Constants like PI, e, Gravity, Conversions, 2D array size only!
//Structures
struct Info{
    string accnt;
    string name;
    string address;
    float balance;
    float *checks;
    float *deposit;
};

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed Here
    
    //Declare all Variables Here
    char digit;
    int numChk,
            numDep;
    float overFee;      //overdrawn fee
    Info *customer=new Info;
    //Input or initialize values Here
    overFee=35.0f;
    cout<<"Enter your account number: "<<endl;
    getline(cin,customer->accnt);
    while(customer->accnt.length()!=5){
        cout<<"Invalid account number. "
                "Please make sure your account number is 5 digit in length."<<endl;
        cout<<"Enter your account number: "<<endl;
        getline(cin,customer->accnt);
    }
    cout<<"Enter your name: "<<endl;
    getline(cin,customer->name);
    cout<<"Enter your address: "<<endl;
    getline(cin,customer->address);
    cout<<"Enter your balance: "<<endl;
    cin>>customer->balance;
    cout<<"How many checks have you deposited this month?"<<endl;
    cin>>numChk;
    cout<<"How many deposits have you made this month?"<<endl;
    cin>>numDep;
    customer->checks=new float[numChk];
    customer->deposit=new float[numDep];
    //Process/Calculations Here
    for(int i=0;i<numChk;i++){
        cout<<"Enter check number "<<i+1<<" amount: "<<endl;
        cin>>customer->checks[i];
        customer->balance-=customer->checks[i];
        if(customer->balance<0){
            customer->balance-=35;
            cout<<"WARNING: Your account has been overdrawn. An overdrawn fee of $35 will be "
                    <<"subtracted from your balance."<<endl;
            cout<<"Your new balance is: $"<<customer->balance<<endl;
        }else
            cout<<"Your new balance is: $"<<customer->balance<<endl;
    }
    for(int i=0;i<numDep;i++){
        cout<<"Enter deposit number "<<i+1<<" amount: "<<endl;
        cin>>customer->deposit[i];
        customer->balance+=customer->deposit[i];
        cout<<"Your new balance is: $"<<customer->balance<<endl;
    }
    //Output Located Here
    cout<<endl<<"--Your account summary--"<<endl;
    cout<<"Account Number: "<<customer->accnt<<endl;
    cout<<"Name:         : "<<customer->name<<endl;
    cout<<"Address:      : "<<customer->address<<endl;
    cout<<"Checks Written: ";
    for(int i=0;i<numChk;i++){
        cout<<"$"<<customer->checks[i];
        if(i!=numChk-1)cout<<", ";
        else cout<<endl;
    }
    cout<<"Deposits      : ";
    for(int i=0;i<numDep;i++){
        cout<<"$"<<customer->deposit[i];
        if(i!=numDep-1)cout<<", ";
        else cout<<endl;
    }
    cout<<"Final Balance : $"<<customer->balance<<endl;
    //Exit
    return 0;
}