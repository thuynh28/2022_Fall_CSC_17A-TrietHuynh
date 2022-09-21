/* 
 * Purpose:  Searching for multiple occurrence of patterns
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays
 * 
 */

//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int  srch1(const char [],const char [],int);//Search for 1 occurrence
void srchAll(const char [],const char [],int []);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const int []); //Print the array of indexes where the pattern found

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce,pattern,match);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(match);
    
    //Exit
    return 0;
}

int  srch1(const char sntnce[],const char pttn[],int pos){
    int plength=strlen(pttn);
    int slength=strlen(sntnce);
    int j=0;    //number of characters that match
    while(sntnce[pos+j]==pttn[j]&&pttn[j]!='\0'){
        j++;
    }
    if(plength==j)  // if all character in pattern is also found in sentence
        return pos; //return index in sentence from where pattern starts
    else
        return -1;  //not found otherwise
}

void srchAll(const char sentence[],const char pattern[],int array[81])//Search for all occurrences
{
    int pLength = strlen(pattern);
    int sLength = strlen(sentence);
    int cnt=0;
    /// iterate through sentence
    for(int i=0;i<81;i++){
    //search for every start_index as i
        int index=srch1(sentence,pattern,i);
        array[cnt++]=index; ///add into match array
    }
}

void print(const int array[]){
    int found=0;
    for(int i=0;i<81;i++){
        if(array[i]!=-1){
            found=1;
            cout<<array[i]<<endl;
        }
    }
    if(found==0)
        cout<<"None"<<endl;
}

void print(const char array[]){
    for(int i=0;i<strlen(array);i++){
        cout<<array[i];
    }
    cout<<endl;
}
