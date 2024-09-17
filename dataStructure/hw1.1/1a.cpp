//Author: 陳展皝 B123245006
//Date: Sept. 11, 2024
//Purpose: Create muiltiple magic square

#include<iostream>
#include<iomanip>
using namespace std;

//function for creating square
void arrayCreate(int k){
    //create clean 2D array
    int **arr = new int*[k];
    for(int i=0;i<k;i++){
        arr[i] = new int[k];
    }

    //set the middle of the top row to be 1
    arr[0][k/2] = 1;

    //set variable to save last place edted
    int currentEdit[2] = {0,k/2};

    //run through the remaining numbers
    for(int i = 0;i<(k*k-1);i++){
        //if next edit has a value
        if (arr[(currentEdit[0]+(k-1))%k][(currentEdit[1]+(k-1))%k]!=0){
            //move down x by 1
            currentEdit[0]+=1;
            currentEdit[0]%=k;
        }

        //next edit does not have a value
        else{
            //move up by 1
            currentEdit[0]+=(k-1);
            currentEdit[0]%=k;
            //move left by 1
            currentEdit[1]+=(k-1);
            currentEdit[1]%=k;
        }
        
        //set the new empty space
        arr[currentEdit[0]][currentEdit[1]] = i+2;
    }

    //print out the 2D array
    //loop through rows
    for (int i=0;i<k;i++){
        //loop through columns
        for(int j=0;j<k;j++){
            //set the width to 3 and have space as trailing
            cout<<setw(3)<<arr[i][j]<<" ";
        }
        //change line after end of 1 row
        cout<<endl;
    }
}

int main(){
    //set n for different 2D array
    int n[] = {1,3,5,7,9};

    //loop through n
    for(size_t i=0;i<sizeof(n)/sizeof(n[0]);i++){
        //print current n and the square
        cout<<n[i]<<endl;
        arrayCreate(n[i]);
        cout<<endl;
    }
}
