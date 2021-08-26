/*
/ Skeleton file for arrays.cpp for CS16, 2021, UCSB
/ Copyright © 2021 by Zachary Sisco. All rights reserved.
/
*/

// DO NOT MODIFY THESE NEXT 6 LINES - DO NOT ADD TO THEM
#include <iostream> // for cout, cin
#include <fstream>  // for ifstream
#include <cstdlib>  // for exit
using namespace std;
#include "headers.h"    // contains the function declarations
#include "constants.h"  // contains 4 global variables

int main( )
{

int max,min;
    
    int array[] = {23, 22, -5, -21, 21, 0, -12, -55, 9111, 1233, 1, 3, 5, 6, 7, 8, 9, 12, -11, 17};
    //Printing all the indexes of the array.
    print_array(array,20);
    
    //Getting the max index of the array.
    cout << "Max = " << maxArray(array,20) << endl;
  
    //Getting the minimum index of the array.
    cout << "Min = " << minArray(array,20) << endl; 
   
    //Getting the Sum of all the indexes of the array.
    cout << "Sum = " << sumArray(array,20) << endl;

    //Getting the even numbers of the array.
    cout << "Evens: "; 
    evensArray(array,20); 
    cout << "end" << endl;

    //Getting the prime numbers of the array.
    cout << "Primes: ";
    primesArray(array,20);
    cout << "end" << endl;

    //Gettinng single target.
    cout << "Searches:" << endl;
    cout << SeqSearch(array,20,-55) << endl;
    
    //Getting multiple target from a new array.
    AllSearches(array,20);

    return 0;
}


/* defining the functions here */

void print_array(int arr[], int asize){
    int i;
    string res;
    for(i=0;i<asize;i++){
        res += to_string(arr[i]);
        res += ",";
    }
    res = res.substr(0,res.size()-1);
    cout << res << endl;
}

int maxArray(int arr[], int asize){
    int i;
    int max = arr[0];
    
    for(i=0;i<asize;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }

    return max;
}

int minArray(int arr[], int asize){
    int i;
    int min = arr[0];
    for(i=0;i<asize;i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}

int sumArray(int arr[], int asize){
    int i;
    int sum = 0;
    for(i=0;i<asize;i++){
        sum += arr[i];
    }
    return sum;
}

void evensArray(int arr[], int asize){
    int i;
    for(i=0;i < asize;i++){
        if(arr[i] % 2 == 0){
            cout << arr[i] << ", ";
        }
    }
}
/* The actual body of the program */
bool isprime(int n){
    int j; 
    for(j=2;j<n;j++){
        if(n==3){
            return true;
        }
        else if(n%j==0 || n%3==0){
            return false;
        }
        else{
            return true;
        }
    }
    return 0;
}

 //Getting the prime numbers of the array.
void primesArray(int arr[], int asize){
    int i;
    for(i = 0; i<asize;i++){
        if(isprime(arr[i])){
            cout << arr[i];
            cout << ", ";
        }else{  
            continue;
        }   
    }    
}

int SeqSearch(int arr[], int array_size, int target){
    int i;
    for(i=0;i<array_size;i++){
        if(arr[i]==target){
            return i;
    }

    }
      return -1;
}
// Pre-Condition: takes in an integer array, its size, and an int target.
//                  This function must be called within AllSearches().
// Post-Condition: if the function finds "target", it returns its index in the array, otherwise it returns -1.
//                  the function only takes ONE integer (at a time) when searching.


void AllSearches(int array[], int array_size){
    int i;
    for(i=0;i<10;i++){
        cout << "Looking for " << to_string(SEARCHES[i]) << ".";
        if(SeqSearch(array,array_size,SEARCHES[i])!=-1){
            cout << " Found at index: ";
            cout << to_string(SeqSearch(array,array_size,SEARCHES[i])) << endl;
        }
        else{
            cout << " Not Found!" << endl;
        }
    }
}



