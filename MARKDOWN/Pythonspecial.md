## Object Oriented programming in Python
### OOP Fundamentals  

####  Class anatomy: the _ _ init_ _ constructor  

> Methods, then to constructor

* Methods are function definition within a class
* `self` as the first argument
* Define attributes by assignment
* Refer to attributes in class via `self._ _ _`
```python
class MyClass:
    # function definition in class
    # first argument is self
    def my_method1(self,other_args...):
        # do things here

    def my_method2(self, my_attr):
        # attribute created by assignment
        self.my_attr = my_attr
        ...
```
However, this way can get unsustainable if your classes contain a lot of data.

> Solution to this: _ _init_ _ Constructor

* <b>Constructor</b> `_ _init_ _()` method is called every time on object is created.

<b>Here's the single parameter Constructor code</b>
```Python
class Customer:
    def _ _init_ _(self,name):
        self.name = name # <--- Create the .name attribute and set it to the name parameter
        print("The _ _init_ _ method was called")
cust = Customer("Lara de Silva")
print(cust.name)
```
<b>Multiple parameter constructor code</b>

```Python
class Customer:
    def _ _init_ _(self,name,balance): # <-- balance parameter added
        self.name = name
        self.balance = balance # <-- balance attribute added
        print("The _ _init_ _ method was called")
cust = Customer("Lara de Silva",1000)
print(cust.name)
print(cust.balance)
```
Terminal shows
The _ _init_ _ method was called  
Lara de Silva
1000

<b>initialize a default value in constructor code</b>

```Python
class Customer:
    def _ _init_ _(self,name,balance=0): # <-- balance parameter added
        self.name = name
        self.balance = balance # <-- balance attribute added
        print("The _ _init_ _ method was called")
cust = Customer("Lara de Silva")
print(cust.name)
print(cust.balance)
```
Terminal shows
The _ _init_ _ method was called  
Lara de Silva
0  


> Real difference here when compared attributes created in methods and attributes created in the constructor. 

<b>Attributes in methods</b>

```Python
class MyClass:
    def my_method1(self,attr1):
        self.attr1 = attr1
        ...
    def my_method2(self, attr2):
        self.attr2 = attr2
        ...
obj = MyClass()
obj.my_method1(val1) # <-- attr1 created
obj.my_method2(val2) # <-- attr2 created
```
<b>Attributes in the constructor</b>

```Python
class MyClass:
    def_ _init_ _(self,attr1,attr2):
        self.attr1 = attr1
        self.attr2 = attr2
        ...
# All attributes are created
obj = MyClass(val1,val2)
```
* easier to know all the attributes.
* attributes are created when the objected is created
* more usable and maintainable code.

> Notes to take away

1. Initilize attributes in `_ _init_ _ ()`
2. Naming
    * `CamelCase` for classes,
    * `lower_snake_case` for functions and attributes
3. keep self as self. In Java, is `this`. 


#### Add a class constructor

#### 