/* 
 * Author: Triet Huynh
 * Date: 10/21/2022 6:00PM
 * Purpose: CSC 17A Midterm Problem 4 - Encrypt
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Constants like PI, e, Gravity, Conversions, 2D array size only!

//Function Prototypes Here
void encrypt(int,int &);
void decrypt(int,int &);
int revrse(int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed Here
    
    //Declare all Variables Here
    int input,
            output;
    int choice;
    //Input or initialize values Here
    //Menu
    cout<<"1.Encrypt"<<endl
            <<"2.Decrypt"<<endl;
    cin>>choice;
    //Process/Calculations Here
    switch(choice){
        case 1:encrypt(input,output);break;
        case 2:decrypt(input,output);break;
    }
    //Exit
    return 0;
}

void encrypt(int input,int &output){
    string num;
    int n1,n2,n3,n4;
    fstream file;
    do{
    cout<<"Enter a number to encrypt: ";
    cin.ignore();
    getline(cin,num);
    while(num.length()!=4){
        cout<<"Error. Number enter must contain 4 digits. Try again."<<endl;
        cout<<"Enter a number to encrypt: ";
        getline(cin,num);
    }
    file.open("data.dat",ios::out);
    file<<num;
    file.close();
    file.open("data.dat",ios::in);
    file>>input;
    file.close();
    n1=input/1000%10;
    n2=input/100%10;
    n3=input/10%10;
    n4=input%10;
    if(n1<0||n1>7||n2<0||n2>7||n3<0||n3>7||n4<0||n4>7)
        cout<<"Error. All digits must be between 0 and 7."<<endl;
    }while(n1<0||n1>7||n2<0||n2>7||n3<0||n3>7||n4<0||n4>7);
    n1=(n1+6)%8;
    n2=(n2+6)%8;
    n3=(n3+6)%8;
    n4=(n4+6)%8;
    output=n3*1000+n4*100+n1*10+n2;
    cout<<"Encrypted Number: "<<setfill('0')<<setw(4)<<output;
}

void decrypt(int input,int &output){
    string num;
    int n1,n2,n3,n4;
    fstream file;
    do{
    cout<<"Enter a number to decrypt: ";
    cin.ignore();
    getline(cin,num);
    while(num.length()!=4){
        cout<<"Error. Number enter must contain 4 digits. Try again."<<endl;
        cout<<"Enter a number to decrypt: ";
        getline(cin,num);
    }
    file.open("data.dat",ios::out);
    file<<num;
    file.close();
    file.open("data.dat",ios::in);
    file>>input;
    file.close();
    n1=input/1000%10;
    n2=input/100%10;
    n3=input/10%10;
    n4=input%10;
    if(n1<0||n1>7||n2<0||n2>7||n3<0||n3>7||n4<0||n4>7)
        cout<<"Error. All digits must be between 0 and 7."<<endl;
    }while(n1<0||n1>7||n2<0||n2>7||n3<0||n3>7||n4<0||n4>7);
    n1=revrse(n1);
    n2=revrse(n2);
    n3=revrse(n3);
    n4=revrse(n4);
    output=n3*1000+n4*100+n1*10+n2;
    cout<<"Decrypted Number: "<<setfill('0')<<setw(4)<<output;
}

int revrse(int a){
    switch(a){
        case 0: return 2;break;
        case 1: return 3;break;
        case 2: return 4;break;
        case 3: return 5;break;
        case 4: return 6;break;
        case 5: return 7;break;
        case 6: return 0;break;
        case 7: return 1;break;
    }
}