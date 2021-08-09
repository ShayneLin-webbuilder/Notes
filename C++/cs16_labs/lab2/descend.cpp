#include <iostream>

// Write a program that takes 3 integer inputs from the user and prints them back in descending order.Hint: 
// Nested if-else statements can be very helpful here!
// Remember: You cannot use techniques we have not yet covered in class to solve this!
// A session should look exactly like the following example (including whitespace and formatting), 
// with all manner of different values for the input and output. 
// Note, the first line is the user input and the second line what the program outputs
using namespace std;



int main(){

    int num1,num2,num3;
    cin >> num1;
    cin >> num2;
    cin >> num3;
    
    if (num1 >= num2){
        if(num2 >= num3){
            cout << num1 << " " << num2 << " " << num3 << endl;
        }else{
            if(num3 >= num1){
            cout << num3 << " " << num1 << " " << num2 << endl;
            }else{
            cout << num1 << " " << num3 << " " << num2 << endl;   
            }
        }
    }else{
        if (num1 >= num3){
            cout << num2 << " " << num1 << " " << num3 << endl;
        }else {
            if(num3 >= num2){
            cout << num3 << " " << num2 << " " << num1 << endl;
            }else{
            cout << num2 << " " << num3 << " " << num1 << endl;    
            }
        }
    }
  
  return 0;
}