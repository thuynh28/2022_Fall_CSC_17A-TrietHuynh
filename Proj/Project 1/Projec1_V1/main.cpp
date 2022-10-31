/* 
 * File:   main.cpp
 * Author: Triet Huynh
 * Created on October 14th, 2022
 * Purpose: Project 1_Simple Hide and Seek game in a 9 slots board
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Function Library
#include <ctime>     //Time Library
#include <iomanip>   //Formatting Library
#include <cmath>     //math library
#include <fstream>   //file stream
#include <cctype>    //for tolower
#include "Arry.h"
#include "Stats.h"
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void dplTble(const char [][3]);
float playGme(string,int&);
void playGme(int);
bool win(char[][3],int);
Stats *getInfo(int);
void bbleSort(int [], int);
void selSort(float [],string[], int);
void prntRnk(Stats *,int);
void del(Stats *);
void wrteBin(fstream &,Stats *);
Stats *readBin(fstream &);

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
            outputFile<<setw(6)<<attmps<<endl;   //save player's attempts in file
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
    enum Truth{FALSE,TRUE};
    Truth result=FALSE;
    for(int i=0;i<3;i++){
        for(int j=0;j<cols;j++){
            if(table[i][j]=='0')
                result=TRUE;
        }
    }
    return result;
}
//Multiplayer game
void playGme(int numPlyr=1){
    string nmeSrch;        //player's name to search for rank
    char search,            //whether player wants to search for their rank
            again;          //search again? yes or no
    fstream binFile;
    int MAX_PLYRS=20;       //maximum 20 players
    Stats players[MAX_PLYRS];
    binFile.open("data.bin",ios::in|ios::out|ios::binary|ios::trunc);
    //dynamically allocate structure pointers
    Stats *player=nullptr;
    Stats *copy=nullptr;
    //perform game with function for each player
    player=getInfo(numPlyr);
    //Sort the arrays
    bbleSort(player->sum,numPlyr);
    selSort(player->avg.data,player->names,numPlyr);
    //Write to and from binary file
    wrteBin(binFile,player);
    copy=readBin(binFile);
    //Display the ranking board
    prntRnk(copy,numPlyr);
    cout<<endl<<endl;
    //reverse and delete dynamically allocated memory
    del(player);
    delete copy;
    player=nullptr;
    copy=nullptr;
    //close file
    binFile.close();
}

//Perform game and gather scores for each player
Stats *getInfo(int numPlyr){
    string plyNme;   //player's name
    int atmpSum;            //sum of player attempts after 3 rounds
    float atmpAvg;          //average attempts to finish 3 rounds
    //dynamically allocate structure array
    Stats *a=new Stats;
    a->players=numPlyr;
    a->names=new string[a->players];
    a->sum=new int[a->players];
    a->avg.size=a->players;
    a->avg.data=new float[a->avg.size];
    //perform game until last player is done and fill in names, total score and avg score
    for(int i=0;i<numPlyr;i++){
        cout<<"Player number "<<i+1<<"'s name: ";
        cin>>plyNme;
        a->names[i]=plyNme;
        atmpAvg=playGme(plyNme,atmpSum);
        a->avg.data[i]=atmpAvg;
        a->sum[i]=atmpSum;
    }
    return a;
}

//Bubble sort
void bbleSort(int num[], int size){
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
//Print the ranking board
void prntRnk(Stats *player,int numPlyr){
    cout<<endl<<" Rank|     Name     |Total Attempts|    Average   "<<endl;
    for(int i=0;i<numPlyr;i++){
        cout<<setw(5)<<i+1<<"|"<<setw(14)<<player->names[i]<<"|"
                <<setw(14)<<player->sum[i]<<"|"
                <<setw(14)<<player->avg.data[i]<<endl;
    }
}
//delete dynamically allocated memory
void del(Stats *a){
    delete [] a->avg.data;
    delete [] a->names;
    delete [] a->sum;
    delete a;
}
//Write structure to binary file
void wrteBin(fstream &out,Stats *a){
    out.write(reinterpret_cast<char *>(&a->players),sizeof(int));
    out.write(reinterpret_cast<char *>(a->names),a->players*sizeof(string));
    out.write(reinterpret_cast<char *>(a->sum),a->players*sizeof(int));
    out.write(reinterpret_cast<char *>(&a->avg.size),sizeof(int));
    out.write(reinterpret_cast<char *>(a->avg.data),a->avg.size*sizeof(float));
}
//Read data structure from binary file
Stats *readBin(fstream &in){
    Stats *a=new Stats;
    long cursor=0L;
    //read data to structure
    in.seekg(cursor,ios::beg);
    in.read(reinterpret_cast<char *>(&a->players),sizeof(int));
    a->names=new string[a->players];
    in.read(reinterpret_cast<char *>(a->names),a->players*sizeof(string));
    a->sum=new int[a->players];
    in.read(reinterpret_cast<char *>(a->sum),a->players*sizeof(int));
    in.read(reinterpret_cast<char *>(&a->avg.size),sizeof(int));
    a->avg.data=new float[a->avg.size];
    in.read(reinterpret_cast<char *>(a->avg.data),a->avg.size*sizeof(float));
    return a;
}