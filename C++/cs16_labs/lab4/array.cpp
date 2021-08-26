#include <iostream>

using namespace std;


int main(){
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