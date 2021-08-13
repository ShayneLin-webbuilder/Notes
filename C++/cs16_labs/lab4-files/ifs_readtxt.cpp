#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    ifstream inFile;
    inFile.open("list.txt");

    //Check For Error
    if (inFile.fail()){
        cerr << "Error Openign File" << endl;
        exit(1);
    }

    //Printing out the words.
    string item;
    int count = 0;

    while(!inFile.eof()){
        inFile >> item;
        if (item == "Kiwi"){
            count++;
        }
    }
    inFile.close();
    cout << count << "  instances of items found!" << endl;

    


}