/* 
 * Author: Triet Huynh
 * Date: 10/22/2022 9PM
 * Purpose: CSC 17A midterm problem 7- prime factors
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Constants like PI, e, Gravity, Conversions, 2D array size only!
//Structures
struct Prime{
    unsigned short prime;
    unsigned char power;
};

struct Primes{
    unsigned char nPrimes;
    Prime *prime;
};

//Function Prototypes Here
Primes *factor(int);    //function to return all prime factors
void prntPrm(Primes *); //function to output all prime factors

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed Here
    
    //Declare all Variables Here
    int input;
    Primes *info=nullptr;
    //Input or initialize values Here
    cout<<"Enter a number between [2,65000] to check for prime factor: "<<endl;
    cin>>input;
    while(input<2||input>65000){
        cout<<"Invalid entry. Input must be in [2,65000] range."<<endl;
        cout<<"Enter a number between [2,65000] to check for prime factor: "<<endl;
        cin>>input;
    }
    //Process/Calculations Here
    info=factor(input);
    //Output Located Here
    cout<<input<<" = ";
    prntPrm(info);
    //delete
    delete []info->prime;
    delete info;
    info=nullptr;
    //Exit
    return 0;
}

Primes *factor(int input){
    short pow=0,    //power of prime
        nPrime=0;   //number of prime
    Primes *info=new Primes;
    //dynamically allocate array with size equal to input/2 (since 2 is the smallest possible prime factor)
    info->prime=new Prime[input/2];
    //Finding factors
    for(int i=2;i<=input;i++){
        while(input%i==0){  //if i divides input, replace input with input/i and increment power
            input=input/i;
            pow++;
        }
        info->prime[nPrime].power=pow;
        info->prime[nPrime].prime=i;
        if(pow>0)   //prime is found when power is greater than 0
            nPrime++;
        //reset power to 0
        pow=0;
    }
    info->nPrimes=nPrime;
    return info;
}

void prntPrm(Primes *info){
    for(int i=0;i<static_cast<int>(info->nPrimes);i++){
        cout<<info->prime[i].prime<<"^"<<static_cast<int>(info->prime[i].power);
        if(i!=static_cast<int>(info->nPrimes)-1)
            cout<<" * ";
    }
}