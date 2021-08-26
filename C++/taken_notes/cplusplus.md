## `Chapter 7` - Arrays
___

### 7.1 Programming with Arrays

* Why we need arrays?
    * Because arrays can give us much more spaces to store multiple variables at once than to declare many variables. ex. If we want to take in 100 scores, it is impractical to use 100 variables than to use 1 single array to handle the memory.  

<i>Syntax</i>
* Declaring an array consisting of `five` variables of type `int `; That is, score[0] to score[4] are all int variables.
```C++ 
    int scores[5];
```
* You can declare arrays and regular variables together.
```C++
    int next, score[5], max;
```
* Giving an indexed variable, such as score[2] a value.
```C++
    int n = 2;
    score[n] = 99;
```
* Making a program more versatile with array.
```C++
Const int NUMBER_OF_STUDENTS = 5;
int i, score[NUMBER_OF_STUDENTS], max;
```


