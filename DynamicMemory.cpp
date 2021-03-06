//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Number Library
#include <ctime>     //Time to set the random number seed
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
int *filAray(int);
int *filIndx(int);
void prntAry(const int *,int,int);
void prntAry(const int *,const int *,int,int);
void markSrt(int *,int *,int);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all variables for this function
    int size=100;
    int perLine=10;
    int *array,*indx;
    
    //Initialize all known variables
    array=filAray(size);
    indx=filIndx(size);
    cout<<"Before Sorting"<<endl;
    cout<<"Original Unsorted Array"<<endl;
    prntAry(array,size,perLine);
    cout<<"Original Unsorted Indexed Array"<<endl;
    prntAry(indx,size,perLine);
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    markSrt(array,indx,size);
    
    //Display the Inputs/Outputs
    cout<<"After Sorting"<<endl;
    cout<<"Original Array"<<endl;
    prntAry(array,size,perLine);
    cout<<"Indexed Array"<<endl;
    prntAry(indx,size,perLine);
    cout<<"The original array with the sorted index"<<endl;
    prntAry(array,indx,size,perLine);

    //Clean up the code, close files, deallocate memory, etc....
    delete []array;
    delete []indx;
    
    //Exit stage right
    return 0;
}

//Function Implementations
void markSrt(int *a,int *indx,int n){
    //Find the smallest element in List i
    for(int i=0;i<n-1;i++){
        //Swap as you go to place the smallest element at the top
        for(int j=i+1;j<n;j++){
            //Logic swap
            if(a[indx[i]]>a[indx[j]]){
                int temp=indx[i];
                indx[i]=indx[j];
                indx[j]=temp;
            }
        }
    }
}

void prntAry(const int *a,const int *indx,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[indx[i]]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}


void prntAry(const int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *filIndx(int n){
    //Declare and allocate the array
    n=n<2?2:n;
    int *indx=new int[n];
    for(int i=0;i<n;i++){
        indx[i]=i;
    }
    return indx;
}

int *filAray(int n){
    //Declare and allocate the array
    n=n<2?2:n;
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=rand()%90+10;//2 Digit Random Array
    }
    return array;
}