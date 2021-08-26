## C++ Lab Site Notes


---
`textbook`
Problem Solving with C++. Walter Savitch, Edition 9 or 10.   
`Class Website`
http://sites.cs.ucsb.edu/~zsisco/cs16/#lab-sections
   
>### Section 1--Lab1
1.0 Hello.cpp  
<br>
<i>Hello.cpp</i>

```C++
#include <iostream>

using namespace std;

int main(){
    cout << "Hello, world!" << endl;
    cout << "I am ready for cs16!" << endl;

    return 0;
}
``` 
Insights: basic `cout` implementation and the "skeleton program"-int main. 
<br></br>
1.1 Calculate.cpp   
<i>Calculate.cpp</i> 
```C++
#include <iostream>

using namespace std;


int main(){
    
    int num1,num2,num3;
    cout << "Please enter 3 numbers." << endl;
    cin >> num1;
    cin >> num2;
    cin >> num3;
    cout << "The formula result is: " << num1 + num2 + num3 << endl;

    return 0;
```
Insights: 
* `cout` can be used to display a variable or calculation of variables.
* `cin` can be used to input information into computer. 
> ### Section 2--lab3
2.0 Block.cpp  
<i>Block.cpp</i>
```C++
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
```





