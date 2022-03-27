# Final will have more database questions than R, but is still cumulative
# CONTROL STRUCTURES and WRITING FUNCTIONS
# %% modulus operand

# x == y "x is equal to y"
# x != y "x is not equal to y"
# x > y "x is greater than y"
#x < y "x is less than or equal to y"
#x >= y "x is greater than or equal to y"

# Combine these using the & or && operators for AND.
# | or || are the operators for OR

# CONTROL STRUCTURES set a condition and tell R what to do when that condition 
# is met or is not met

# *Control Structures*
# Definition:
# CONTROL STRUCTURES set a condition and tell R what to do when that condition 
# is met or is not met
# if, if... else, ifelse testing a condition
# for: execute a loop for a fixed # of times
# while: execute a loop while a condition is true
# repeat: execute a loop while seeing a break.
# break: break the execution of a loop
# next: skip an iteration of a loop
# return: exit a function

# if, if...else | can be followed by an optional else statement
# Using 'if'. The operator == tests a condition. Returns TRUE or FALSE

x <- 2
x==2
if(x==3){ print("This is true")} # Nothing happens
if(x==2){ print("This is true")} # "This is true"

# %in% logical operator. Used to identify if an element belongs to an R project
x <- c("Hello", "world")
if("Hello" %in% x){print ("hello")} # "hello"

# if and if...else
x <- c("hello","world")
if ("goodbye" %in% x){print("goodbye")}else{print("see you later")} # "see you later"

x <- 5
if (x > 0) {print("positive number")} else{print("negative number")} # "positive number"

# ifelse
#ifelse(test expression, yes, no)
# If the test expression is TRUE, return values for true elements of test
# If the test expression is FALSE, return values for FALSE elements of test

x <- 1:10
ifelse(x<5 | x>8,x,0) # if x is less than 5 OR greater than 8, print the values for which they are true, otherwise print 0

ifelse(x<3 | x>9, x,"Missing") # a char string, returns value as characters (in quotes)
x <- c(5:2)
ifelse(x==5 | x>3, x,0) #5 4 0 0


# Loops allows us to execute a statement or group of statements multiple times
# Repeat Loops executes the same code again and again until a stop condition is met
  # terminates loop statement and transfers execution to the statement immediately following the loop
# While LOOP repeats a statement or group of statements while a given condition is true. It tests the condition before executing the loop body
# For LOOP like a while statement, except that it tests the condition at the end of the loop body

x <- 1
repeat {print(x) x = x+1 if (x==4){break}} #doesn't work

repeat{
  print(x)
  x = x+1
  if (x > 4){
    break
  }
}

i <- 1
while (i < 6) {
  print(i)
  i = i+1
}


# ***While Loop exercise*** 
#Given x <- c(2,4)
# write a while loop that adds even numbers to x, WHILE the length of x is less than 12
# after the 1st iteration of the while loop, we want 6 to be added to x. 
#So x = c(2,4,6), 2nd iteration x = c(2,4,6,8) and the 3rd x = (2,4,6,10)
# While the length of x is less than 12

# x <- c(2,4) | initialize i = 6 bc that's the first even number we need to add
# code the test expression: while the length of x is less than 12. while (length(x) < 12)
# statements: x = c(x,i) (x=c(2,4,6))
# now increment x by 2

x <- c(2,4)
i=6 # initialize the increment variable

while( length(x) < 12){
  x = c(x,i) # adding a value to a c()
  i = i + 2
}

x # 2 4 6 8 10 12 14 16 18 20 22 24
length(x) # 12


# ***For Loop exercise***
# count the even numbers in a vector
# the operator %% gives the remainder or modulus

x <- c(2,5,3,9,8,11,6)
count <- 0

for(i in x){
  if(i %% 2 == 0)
  count = count + 1
}
print(count) # prints count after exiting the loop

# i is a placeholder for x values; every loop i moves to the next x value
# count is a vector outside the loop but can be munipulated by the loop
# for each value of x, if the remainder is 0 when divided by 2, replace count with count + 1
# these x values are 2, 8, 6
# thus the new value of count is 3 for the 3 values of x

# ***For Loop Second Exercise***
# write code for loop that increments x by three and decreases y by two, for each i
x <- 1
y <- 40
i <- c(1:10)
for(j in i){
  x <- x+3
  y = y-2
}
x # 31
y # 40

# ***Function Creation Exercise***
# functions are created using the function() directive and are stored as R objects just like anything else.
# In particular, they are R objects of class "function"
# write a function to convert fahrenheit to centigrade
# call the unction with a fahrenheit temperature of 82

fahrenheit_to_centigrade <- function(temp_F) {
  temp_C <- ((temp_F - 32) * (5/9))
  return(temp_C)
}
fahrenheit_to_centigrade(82)

# Create a function to print squares of numbers in sequence, call the function supplying 6 as an argument
My_function <- function(a) {
  for(i in 1:a){
    b = i^2
    print(b)
  }
}
My_function(4)

# using the variables a, b write a nested for() loop where
# the outer for loops increments a for 2 to 8 by 1
# the inner for loop increments v from 1 to 6 by 1
# if a<b output ...

for(a in 2:8){
  for(b in 1:6){
    if(a<b){
      cat(a, 'less than',b,'\n')
    }
  }
}
# no linefeeds are output unless explicitly requested by "\n"