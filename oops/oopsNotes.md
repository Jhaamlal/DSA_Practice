## OPPS CONCEPT :
[first Notes](https://github.com/Jhaamlal/DSA-SUPREME-2-0-NOTES/blob/master/DSA%20SUPREME%202.0%20NOTES/25.%20CLASS%20NOTES/OOPS%20CLASS%2001%20NOTES.pdf)

[second Nots](https://github.com/Jhaamlal/DSA-SUPREME-2-0-NOTES/blob/master/DSA%20SUPREME%202.0%20NOTES/26.%20CLASS%20NOTES/OOPS%20CLASS%2002%20NOTES.pdf)

[Third note](ttps://github.com/Jhaamlal/DSA-SUPREME-2-0-NOTES/blob/master/DSA%20SUPREME%202.0%20NOTES/27.%20CLASS%20NOTES/OOPS%20CLASS%2003%20NOTES.pdf)

> #### What is local and globel variable ?
Global variable is what ,that is accessible in the whole ,function and class    and         the local variable are only access inside the single block. 

***
> #### What is stack and heap memory ?
Stack Memory :

    1) It is static type of memory ,
    2) Allocation happens in the continues block of memory .
    3) Memory allocation and de allocation happens in the faster as compare to the heap memory
    4) All function or runtime process happens in the stack memory.
    5) Stack memory has less memory as compare to the heap memory.


Heap Memory :

    1) It is dynamic type of memory allocation.
    2) It has not continuous block of memory allocation.
    3) It size grows from down to up ,where as stack size grows form high to low in downword way .
    4) Memory allocation happens at the execution time of  program.
    5) It is here the memory leak happen .


***
#### What is class and object ?
    Class is Bundle of properties/state/attributes and behavior.It is blue print and user define data type. 
    
    Object is instance of class ,and object is define as data field ,that is unique attributes and behavior .

***
#### What is constructer ?


    1) Constructor is special method that is initialise a newly created object 
    2) Constructor is automatically called when new object is formed .
    3) Constructor has same name what class has ,and has no return type .
    4) Constructor will always be public . But can also be private,to use as private you need to be have friend keyword.
    5) Mainly 3 type of Constructor , default Constructor,parameterize Constructor,and default Constructor (called polymorphism )
```
c++ :

<!-- Default  Constructor  -->
   Student()
    {
        cout << "Student ctor called" << endl;
    }


    // parameterized Constructor
    Student(int id, int age, bool present, string name, int nos, string gf)
    {
        this->id = id;
        this->age = age;
        this->present = present;
        this->name = name;
        this->nos = nos;
        this->gf = gf;
        this->v = new int(10);
        cout << "Student paremeterized ctor called" << endl;
    }
```

***
#### What is this pointer ?
    1) This pointer is private data member in class.
    2) The pointer is point to current object 
    3) Pointer add by compiler privately.

    It is been use when local variable or parameter variable has same value as member variable ,this pointer is explicitly refer to member variable .

    It means that if the parameter has same name as the ,attribute in that case we should use the   this -> , to remove the confusion

****
####  STATIC AND DYNAMIC MEMORY ALLOCATION IN OBJECT CREATION:
    int obj1=class -> static memory allocation
    int dynamicObj = new Class() => Dynamic memory allocation
    Student *s1=new Student() => Dynamic memory allocation

    When ever there is new keyword, in that case dynamic memory allocation 

***

#### ACCESS OF MEMBER CLASS 
    When is it static,means data member are static in that case you can allocate it ,by using 
    OBJECT1.dataMember  => s1.name,s1.age

    This can't be done with the dynamic member ,because it is on the heap and ,you need to reference it 
    (*s1).name,(*s1).age
    s1->name,s2->age
***
#### PADDING
    Padding ,is one of the way compiler give nearest possible by to the memory for the ,member .
    let's say you have three type of data type string,bool,int == there byte is 8,1,4 now what compiler will to it will allocate 16 byte of memory ,but only 13 byte will be used rest will be the padding .

***
#### SHALLOW COPY VS DEEP COPY
    SHALLOW :
        It is simply the element those are copying the element are just referring to same item ,means that of one item value is changed all values will be changed.

    DEEP:
        In this we create new memory location and copy the value in that element, in that case new instance is create, so if we change the value at one point other value will not changed.  

****

#### Copy constructor
```
Student(const student &srcObj){
    this->id=srcObj.id;
    this->name=srcObj.name;
    this->age=srcObj.age;
    this->gender=srcObj.gender;
}
```
    Copy constructor are the constructor that invoke while copy one class object to other. This help in doing the deep copy. By default also we make the copy constructor. 

***

####  Destructor

    Destructor is automatically called,but we must make our own destructor when we dynamically allocate the memory to the item.
    In this way stop from memory leak.

***
#### Inheritence 
<span style="color:red">Public</span> : It is access by all the classes ,below it all. 

<span style="color:green">Private</span> : Not shared with anybody,not with drive class till not mention keyword FRIEND.

<span style="color:yellow">Protected</span> : It is accessible by derivative class and class itself

***
#### Dynamic Polymorfism
check the notes
