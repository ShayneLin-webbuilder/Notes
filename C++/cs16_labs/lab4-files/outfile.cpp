#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ofstream outFile;

    outFile.open("writingfromcpp.txt");

    outFile << "First Number: " << 5;

    outFile.close();

    return 0;

}