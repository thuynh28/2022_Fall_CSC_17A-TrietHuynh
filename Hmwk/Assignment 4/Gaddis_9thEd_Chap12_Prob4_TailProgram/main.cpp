/* 
 * Author: Triet Huynh
 * Date:
 * Purpose:
 */

//System Libraries Here
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Constants like PI, e, Gravity, Conversions, 2D array size only!

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed Here
    
    //Declare all Variables Here
    string fleNme, buffer;
	int count = 0;
	char ch;
        
    //Input or initialize values Here
    cout << "Enter the name of a text file: ";
    cin  >> fleNme;
    fstream file(fleNme, ios::in);
    if (!file){
		cout << "Error opening file.\n";
		return 0;
	}

    for(long i = 0; count <= 10; i++){
        file.seekg(-1 * i, ios::end);
	ch = file.get();
	if (ch == '\n'){
            count++;
	}
    }
    //Process/Calculations Here
    file.seekg(0, ios::cur);
    getline(file, buffer);
    cout << buffer << endl;
    //Output Located Here
    
    //Exit
    return 0;
}