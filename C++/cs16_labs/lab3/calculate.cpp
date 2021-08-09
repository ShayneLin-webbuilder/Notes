// calculate.cpp
// By: <your name here>

#include <iostream>
#include <cstdlib>
using namespace std;

// Usage: ./calculate int char int
// char can either be: + x or %
int main(int argc, char *argv[]) {
    int i;
    if(argc != 4){
    cerr << "Number of arguments is incorrect.\n";
    }

    int firstnum = atoi(argv[1]);
    int secondnum = atoi(argv[3]);
    string op = argv[2];

    if(op == "+"){
        cout << firstnum + secondnum << endl;
    }else if(op == "x"){
        cout << firstnum * secondnum << endl;
    }else if (op == "%"){
        if(secondnum == 0){
            cerr << "Cannot divide by zero." << endl;
        }else{
            cout << firstnum % secondnum << endl;
        }
    }else {
        cerr << "Bad operation choice." << endl;
    }
    
    
    


    // PART 1: Check to see if the number of arguments is correct
    //         Hint: use "if (argc ...)" to check this,
    //         use cerr to output any messages

    // PART 2: Convert arguments into integers (only those that need it!)
    //         Hint: this means using atoi()

    // PART 3: Check for illegal operations like divide by zero...
    //         use cerr to output any messages

    // PART 4: Do the appropriate calculation,
    //         outputs using both cout and cerr

    return 0;
}