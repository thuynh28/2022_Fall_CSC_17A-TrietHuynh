/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Purpose:  Menu using Functions,
 *           extend for midterm
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Structures
struct Info{
    string accnt;
    string name;
    string address;
    float balance;
    float *checks;
    float *deposit;
};
struct Paycheck{
    string name;    //employee's name
    string compNme, //company's name
        comAddr;    //company's address
    float hours;    //hours worked
    float rate;     //pay rate
    float gross;    //gross pay
};
struct Array{
    int size; //Size of the Array
    int *data;//Values contained in the array
};
struct Stats{
    Array *mode;  //Array ADT contains number of modes and the modes themselves
    int modFreq;  //Mode Frequency
    float median; //Median of the array
    float avg;    //Average of the Array
};

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void fillArr(Paycheck [],int);
void prntChk(Paycheck [],int);
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure
void encrypt(int,int &);
void decrypt(int,int &);
int revrse(int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='4');
    
    //Exit stage right!
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Menu
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;   
    cout<<"Type 4 for Problem 4"<<endl<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 1
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm1(){
    cout<<"Problem 1"<<endl;
    char digit;
    int numChk,
            numDep;
    float overFee;      //overdrawn fee
    Info *customer=new Info;
    //Input or initialize values Here
    overFee=35.0f;
    cout<<"Enter your account number: "<<endl;
    cin.ignore();
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
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 2
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm2(){
    cout<<"Problem 2"<<endl;
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
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 3
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm3(){
    cout<<"Problem 3"<<endl;
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 4
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm4(){
    cout<<"problem 4"<<endl;
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

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    Stats *stats=new Stats;
    //calculating the average
    float total;
    for(int i=0;i<array->size;i++){
        total+=array->data[i];
    }
    stats->avg=total/array->size;
    //finding the median
    int index=array->size/2;
    if(array->size%2==0){
        stats->median=(array->data[index]+array->data[index-1])/2.0;
    }else
        stats->median=array->data[index];
    //finding mode
    stats->mode=new Array;
    stats->mode->size=0;
    int nModes=0,
            modNum=0;
    //finding number to control the modes
    for(int i=0;i<array->size;i++){
        //move the index ahead if there's a duplicate
        while(i<array->size&&array->data[i]==array->data[i+1]){
            i++;
        }
        modNum++;
    }
    //finding max frequency
    if(array->size%modNum==0)
        stats->modFreq=array->size/modNum;
    else
        stats->modFreq=array->size/modNum+1;
    //finding the number of modes
    if(modNum>=array->size)
        nModes=0;
    else
        nModes=array->size-modNum*(stats->modFreq-1);
    //Allocate the mode array
    stats->mode->size=nModes;
    if(nModes!=0){
        stats->mode->data=new int[nModes];
        for(int i=0;i<nModes;i++){
            stats->mode->data[i]=i;
        }
    }
    return stats;
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
    cout<<"Encrypted Number: "<<setfill('0')<<setw(4)<<output<<endl;
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
    cout<<"Decrypted Number: "<<setfill('0')<<setw(4)<<output<<endl;
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