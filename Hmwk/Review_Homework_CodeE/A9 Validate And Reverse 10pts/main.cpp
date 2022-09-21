/* 
 * File:   main.cpp
 * Author: Triet Huynh
 * Created 9/9/2022
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
#include <ctype.h>//isdigit
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool  inRange(const char [],unsigned short &);//Output true,unsigned or false
bool  reverse(unsigned short,signed short &);//Output true,short or false
short subtrct(signed short,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;     //More than enough
    char  digits[SIZE];    //Character digits or not
    unsigned short unShort;//Unsigned short
    short snShort;         //Signed short
    
    //Input or initialize values Here
    cout<<"Reverse a number and subtract if possible."<<endl;
    cout<<"Input a number in the range of an unsigned short"<<endl;
    cin>>digits;
    unShort=0;
    for(int i=0;i<strlen(digits);i++){
        unShort=unShort*10+static_cast<int>(digits[i])-static_cast<int>('0');
    }
    //Test if it is in the Range of an unsigned short
    if(!inRange(digits,unShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Reverse and see if it falls in the range of an signed short
    if(!reverse(unShort,snShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Now subtract if the result is not negative else don't subtract
    snShort=subtrct(snShort,999);
    
    //Output the result
    cout<<snShort<<endl;
    
    //Exit
    return 0;
}
//Function to check if input is in range of unsigned short
bool  inRange(const char digits[],unsigned short &unShort){
    bool inRnge=true;
    for(int i=0;i<strlen(digits);i++){
        if(!isdigit(digits[i])){
            inRnge=false;
        }
    }
    if(unShort<0||unShort>65535){
        inRnge=false;
    }
    return inRnge;
}
//Function to check if reverse number is within singed short range
bool reverse(unsigned short unShort,signed short &snShort){
    bool inRnge;
    short n10000=(unShort/10000)%10,
            n1000=(unShort/1000)%10,
            n100=(unShort/100)%10,
            n10=(unShort/10)%10,
            n1=(unShort/1)%10;
    int temp; //temporary value used to check range
    temp=n1*10000+n10*1000+n100*100+n1000*10+n10000;
    if(temp>=-32768&&temp<=32767){  //check range
        inRnge=true;
        snShort=temp;
    }else
        inRnge=false;
    return inRnge;
}
//function to subtract reversed 
short subtrct(signed short snShort,int num){
    if(snShort-num>=0)
        return snShort-num;
    else
        return snShort;
}
