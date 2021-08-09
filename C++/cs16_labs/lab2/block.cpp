#include <iostream> 

using namespace std;

int main(){
    int row;
    int col;
    

    
    while(row > 0 && col > 0){
    int i;
    int j;
    cout << "Enter number of rows and columns:"<<endl;
    cin >> row >> col;
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
            cout << "X."; 
            } 
            cout << endl; 
        }
    }
    return 0;
}