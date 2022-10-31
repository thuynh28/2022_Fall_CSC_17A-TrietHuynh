/* 
 * Author: Triet Huynh
 * Date:
 * Purpose:
 */

//System Libraries Here
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Constants like PI, e, Gravity, Conversions, 2D array size only!

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed Here
    
    //Declare all Variables Here
    string inFile, outFile;
    fstream in,out;
    char ch;
    //Input or initialize values Here
    cout<<"Enter name of file to get data from: "<<endl;
    cin>>inFile;
    cout<<"Enter name of file to write data to: "<<endl;
    cin>>outFile;
    //Process/Calculations Here
    in.open(inFile,ios::in);
    out.open(outFile,ios::out);
    if(in){
        //read a char from in file 
        in.get(ch);
        //if the first read was successful, write the uppercase char to out file
        if(in){
            out.put(toupper(ch));
            in.get(ch);
        }
        //while the last read was successful, continue
        while(in){
            //check for end of sentence
            if(ch=='\n'){
                out.put(ch);
                in.get(ch);
                if(in){
                    //write uppercase char to out file if its start of a new sentence
                    out.put(toupper(ch));
                    in.get(ch);
                }
            }else{
                //write lowercase char to out file its not at the start of a sentence
                out.put(tolower(ch));
                in.get(ch);
            }
        }
        //Close the files
        in.close();
        out.close();
        cout<<"File has been converted."<<endl;
    }else{
        cout<<"Cannot open file."<<endl;
    }
    //Output Located Here
    
    //Exit
    return 0;
}