#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double n;
    double i;
    
    do{
    cout << "Enter the number of terms to approximate (or zero to quit):" << endl;
    cin >> n;
    if(n>0){
    double result = 0;
    double pivalue = 0;
    for(i=1;i<=n;i++){
        result = result + pow(-1,i)*(1/(2*i+1));
        pivalue = 4 * (1+result);
    }
    cout << "The approximation for Leibniz's Formula is " << pivalue << " using " << n << " terms."<< endl;
    }else{
        return 0;
    }
    }while(n>0);

    return 0;  
}