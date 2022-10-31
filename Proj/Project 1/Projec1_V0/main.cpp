/* 
 * File:   main.cpp
 * Author: Triet Huynh
 * Created on July 30th, 2022, 10:30 AM
 * Purpose: Project 1_Simple Hide and Seek game in a 9 slots board for 1 player
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Function Library
#include <ctime>     //Time Library
#include <iomanip>   //Formatting Library
#include <cmath>     //math library
#include <fstream>   //file stream
#include <vector>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void dplTble(const char [][3]);
float playGme(string,int&);
void playGme(int);
bool win(char[][3],int);
void bbleSort(vector<int>&, int);
void selSort(float [],string[], int);
int rnkSrch(const string [], int, string);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const unsigned short ROWS=3,
            COLS=3;
    int gmeType,        //single player or multiplayer
        numPlyer,       //number of players, 1 or 2
            atmpSum;    //Sum of attempts that player takes to finish the game
    char start;         //user choice to start or quit the game
    float atmpAvg;    //average number of attempts it takes for player to succeed per round
    string plyer;       //player's name
    
    //Initialize or input i.e. set variable values
    do{
        cout<<"Would you like to play a simple hide and seek game?"<<endl;
        cout<<"Enter 'y' to start or 'n' to exit : ";
        cin>>start;
    if(start=='y'||start=='Y'){
        cout<<endl<<"             Game starts!  "<<endl<<endl;
        cout<<"Enter 1 or 2:"<<endl
                <<"1. Single Player"<<endl
                <<"2. Multiplayer"<<endl;
        cin>>gmeType;
        //Input validation
        while(gmeType!=1&&gmeType!=2){
            cout<<"Invalid choice. Enter [1-2]."<<endl;
            cin>>gmeType;
        }
        if(gmeType==1){
            cout<<"Enter player's name: ";      
            cin>>plyer;
            playGme(plyer,atmpSum);
        }else if(gmeType==2){
            cout<<"Input number of players: ";
            cin>>numPlyer;
            playGme(numPlyer);
    }else if(start=='n'||start=='N'){   //quits game
        cout<<"Exiting. See ya later!"<<endl<<endl;
        exit(0);
    }else{                              //invalid input
        cout<<"Invalid choice! Please try again."<<endl<<endl;
        }   
    } 
    }while(start!='n'&&start!='N');
    //Exit stage right or left!
    return 0;
}
//Function to display game table
void dplTble(const char table[][3]){
    cout<<"\t     |     |     "<<endl;
    cout<<"\t  "<<table[0][0]<<"  |  "<<table[0][1]<<"  |  "<<table[0][2]<<"  "<<endl;
    cout<<"\t_____|_____|_____"<<endl;
    cout<<"\t     |     |     "<<endl;
    cout<<"\t  "<<table[1][0]<<"  |  "<<table[1][1]<<"  |  "<<table[1][2]<<"  "<<endl;
    cout<<"\t_____|_____|_____"<<endl;
    cout<<"\t     |     |     "<<endl;
    cout<<"\t  "<<table[2][0]<<"  |  "<<table[2][1]<<"  |  "<<table[2][2]<<"  "<<endl;
    cout<<"\t     |     |     "<<endl<<endl;
}
//Single player game
float playGme(string plyer,int &atmpSum){
    const int ROWS=3,   //game board has 3 rows and 3 columns
            COLS=3;
    int choice,         //player's guess
            hide,       //where the object is hiding
            attmps,     //number of attempts it took for user to find the right spot
            temp,       //temporary value to hold number of attempts in each round
            rounds;     //3 rounds in total
    float atmpAvg;    //average number of attempts it takes for player to succeed per round
        cout<<endl<<"          The rule is simple"<<endl;
        cout<<"Find out where I am hiding in the board below"<<endl<<endl;
        ofstream outputFile(plyer);
        atmpSum=0;
        //start game from round 1->3
        for(rounds=0;rounds<3;rounds++){
            char table[ROWS][COLS]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};   //game's board
            hide=(rand()%9)+1; //generate a random number as hiding slot
            attmps=0,temp=0;
            //display table
            dplTble(table);
            cout<<"Round "<<rounds+1<<endl;
            do{
                cout<<"Where am I hiding [1-9] : ";
                cin>>choice;
                //input validation
                if(choice<1||choice>9)
                    cout<<"Invalid input. Please try again."<<endl;
                else{
                attmps++;
                switch (choice){
                    case 1:{
                        if(choice==hide)
                        {
                            table[0][0]='0';
                            //display updated table
                            dplTble(table);
                            break;
                        }else
                        {
                            table[0][0]='X';
                            //display updated table
                            dplTble(table);
                            break;
                        }
                    }
                case 2:{
                    if(choice==hide)
                        {
                            table[0][1]='0';
                            dplTble(table);
                            break;
                        }else
                        {
                            table[0][1]='X';
                            dplTble(table);
                            break;
                        }
                    }
                case 3:{
                    if(choice==hide)
                        {
                            table[0][2]='0';
                            dplTble(table);
                            break;
                        }else
                        {
                            table[0][2]='X';
                            dplTble(table);
                            break;
                        }
                }
                case 4:{
                    if(choice==hide)
                        { 
                        table[1][0]='0';
                            dplTble(table);
                            break;
                        }else
                        {
                            table[1][0]='X';
                            dplTble(table);
                            break;
                        }
                }
                case 5:{
                    if(choice==hide)
                        {
                            table[1][1]='0';
                            dplTble(table);
                            break;
                        }else
                        {
                            table[1][1]='X';
                            dplTble(table);
                            break;
                        }
                }
                case 6:{
                    if(choice==hide)
                        {
                            table[1][2]='0';
                            dplTble(table);
                            break;
                        }else
                        {
                            table[1][2]='X';
                            dplTble(table);
                            break;
                        }
                }
                case 7:{
                    if(choice==hide)
                        {
                            table[2][0]='0';
                            dplTble(table);
                            break;
                        }else
                        {
                            table[2][0]='X';
                            dplTble(table);
                            break;
                        }
                }
                case 8:{
                    if(choice==hide)
                        {
                            table[2][1]='0';
                            dplTble(table);
                            break;
                        }else
                        {
                            table[2][1]='X';
                            dplTble(table);
                            break;
                        }
                }
                case 9:{
                    if(choice==hide)
                        {
                            table[2][2]='0';
                            dplTble(table);
                            break;
                        }else
                        {
                            table[2][2]='X';
                            dplTble(table);
                            break;
                        }
                }   
                }
                }
            }while(choice!=hide);
            if(win(table,COLS)==true){
            cout<<"Success!"<<endl;
            cout<<"It took you "<<attmps<<" attempts in round "<<rounds+1<<endl;
            }
            outputFile<<attmps<<endl;   //save player's attempts in file
        }
        outputFile.close();
        ifstream inputFile;
        inputFile.open(plyer);  //create a file with player's name and store attempts for record
        while(inputFile>>temp){
            atmpSum+=temp;
        }
        inputFile.close();
        atmpAvg=abs(static_cast<float>(atmpSum)/3.0);
        cout<<fixed<<showpoint<<setprecision(2);
        cout<<plyer<<" take an average "<<atmpAvg<<" attempts to finish the game."<<endl<<endl;
        return atmpAvg;
}
//check for winning status
bool win(char table[][3],int cols){
    for(int i=0;i<3;i++){
        for(int j=0;j<cols;j++){
            if(table[i][j]=='0')
                return true;
        }
    }
    return false;
}
//Multiplayer game
void playGme(int numPlyr=1){
    string plyer,           //player's name
            nmeSrch;        //player's name to search for rank
    int atmpSum;            //sum of player attempts after 3 rounds
    float atmpAvg;          //average attempts to finish 3 rounds
    string names[numPlyr];  //players ' names array
    float avg[numPlyr];     //and their average attempts
    vector<int>sum;         //player's attempts total array
    char search,            //whether player wants to search for their rank
            again;          //search again? yes or no
    int rank;               //player's rank
    //perform game until last player is done and fill in names, total score and avg score
    for(int i=0;i<numPlyr;i++){
        cout<<"Player number "<<i+1<<"'s name: ";
        cin>>plyer;
        names[i]=plyer;
        atmpAvg=playGme(plyer,atmpSum);
        avg[i]=atmpAvg;
        sum.push_back(atmpSum);
    }
    //Sort the arrays and vectors 
    bbleSort(sum,sum.size());
    selSort(avg,names,numPlyr);
    //Display the ranking board
    cout<<endl<<" Rank|     Name     |Total Attempts|    Average   "<<endl;
    for(int i=0;i<numPlyr;i++){
        cout<<setw(5)<<i+1<<"|"<<setw(14)<<names[i]<<"|"
                <<setw(14)<<sum[i]<<"|"
                <<setw(14)<<avg[i]<<endl;
    }
    //Prompt user for rank search
    cout<<endl<<"Would you like to search for your rank(y or n) : ";
    cin>>search;
    //Input validation
    while(search!='y'&&search!='n'&&search!='Y'&&search!='N'){
        cout<<"Invalid choice. Try again (y or n): ";
        cin>>search;
    }
    do{
        cout<<"Name: ";
        cin>>nmeSrch;
        rank=rnkSrch(names,numPlyr,nmeSrch);
        if(rank==-1)
            cout<<"Invalid name."<<endl;
        else
            cout<<nmeSrch<<"'s rank is "<<rank+1<<endl;
        cout<<"Again(y or n)? ";
        cin>>again;
        //Input validation
        while(again!='y'&&again!='n'&&again!='Y'&&again!='N'){
            cout<<"Invalid choice. Try again (y or n): ";
            cin>>again;
        }
    }while(again!='n'&&again!='N'); //repeat until player enter no to repeat
    cout<<endl<<endl;
}
//Bubble sort on a vector
void bbleSort(vector<int>&num, int size){
    for(int maxEle=size-1;maxEle>0;maxEle--){
        for(int indx=0;indx<maxEle;indx++){
            //if first value is greater than second value, swap them
            if(num[indx]>num[indx+1]){
                int temp=num[indx];
                num[indx]=num[indx+1];
                num[indx+1]=temp;
            }
        }
    }
}
//Dual sort with array names and array average using selection sort
void selSort(float avg[],string names[], int size){
    float minVal;
    int minIndx;
    for(int start=0;start<(size-1);start++){
        minIndx=start;
        minVal=avg[start];
        for(int indx=start+1;indx<size;indx++){
            if(avg[indx]<minVal){
                minVal=avg[indx];
                minIndx=indx;
            }
        }
        //if value of index indx in first array is less than min value, swap them
        float flTemp=avg[minIndx];
        avg[minIndx]=avg[start];
        avg[start]=flTemp;
        //swap elements in second array accordingly
        string strTemp=names[minIndx];
        names[minIndx]=names[start];
        names[start]=strTemp;
    }
}
//search for player's name to find out their rank using linear search
int rnkSrch(const string arr[], int size, string name){
    int index=0;
    int pos=-1;
    bool found=false;
    while(index<size&&!found){
        if(arr[index]==name)
        {
            found=true;
            pos=index;
        }
        index++;
    }
    return pos;
}