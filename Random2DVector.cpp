
//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Number Library
#include <ctime>     //Time to set the random number seed
#include <vector>    //From the STL Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void filVc2D(vector<vector<int>> &,int,int);
void prtVc2D(const vector<vector<int>> &);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all variables for this function
    int rows=15;
    int cols=10;
    vector<vector<int>> array;
    
    //Allocate the 2D array
    filVc2D(array,rows,cols);
    
    //Display the array
    cout<<"Original 2D Vector"<<endl;
    prtVc2D(array);
    
    //Add rows to the original array
    rows=3;
    cols=5;
    filVc2D(array,rows,cols);
    
    //Display the array
    cout<<"Augment rows of Original 2D Vector"<<endl;
    prtVc2D(array);
    
    //Add columns to the augmented array
    cols=6;
    filVc2D(array,0,cols);
    
    //Display the array
    cout<<"Augmented Columns of previous 2D Vector"<<endl;
    prtVc2D(array);

    //Exit stage right
    return 0;
}

void prtVc2D(const vector<vector<int>> &array){
    cout<<endl;
    for(int row=0;row<array.size();row++){
        for(int col=0;col<array[row].size();col++){
            cout<<array[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void filVc2D(vector<vector<int>> &array,int rows,int cols){
    //Fill the array with random 2 Digit numbers
    //Add the number of rows and columns to the array vector
    //If row==0 then just add columns to the existing array
    int begin=array.size();
    if(rows==0)begin=0;
    int end=array.size()+rows;
    for(int row=begin;row<end;row++){
        if(rows!=0)array.push_back(vector<int>());
        for(int col=0;col<cols;col++){
            array[row].push_back(rand()%90+10);
        }
    }
}