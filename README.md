# Sujay Modern CPP Shortnotes

## C++ tutorial 

## CRTP - Curiously Recurring Template Pattern
1.  Curiously recurring template pattern / Static Polymorphism. 
2.  Dynamic binding of virtual tables happens at run time and this pays a cost. 
3.  However you can shift this to compile time using static cast however for multiple such inheritances each new
    template resolution of the base class is a new class and has to pay memory cost.

## Lvalue and Rvalue References 
L value and R value references. 

You can only assign Lvalues to Lvalue references. 

All named variables are lvalue references. 

You can assign both lvalues and rvalues to const l value references.

You can only assign rvalues to rvalue references. 

An overloaded function of input parameter rvalue reference is preffered over an function of const lvalue reference. 

Const l value references can take both lvalues and r values as the arguments. 

## Shallow Copy vs Deep Copy 
Shallow Copy vs Deep Copy. 

A shallow copy of an object copies all of the member field values. This works well if the fields are values, but may not be what you want for fields that point to dynamically allocated memory. The pointer will be copied. but the memory it points to will not be copied

The deep copy however ensures that a copy of the dynamically alloted memory is also made. Make sure to have the destructor to delete the dynamically alloted memory and the overloaded assignment operator and the copy constructor for deep copy. 

## Assignment Operator vs Copy Constructor vs Move Constructor 
Copy Constructor: const l value reference as the argument 

Assignment Operator: Returns reference to the object / \*this pointer so that chaining works and copy constructor / destructor is not called as compared to pass by value 

Move Constructor : Takes r value reference as the parameter. Set pointers to heap memory blocks to nullptr so that destructors dont deallocate that memory
block. 

## Copy and Swap Idiom 

    void A::swap(A &other){
        swap(*this.a,other.a);
        swap(*this.b,other.b);
    }

    A& A::operator=(A other) noexcept {
        swap(other) ;
        return *this ;
    }

>The above approach has multiple advantages:

>> Self Assignment check can be skipped so useful for throwing noexcept

>> Other is passed to assignment operator as a value and so memory deallocation of \*this previously allocated memory happens automatically

>> This can take both lvalue and rvalue so implements both the copy assignment and move assignment.


## Mutuable Lambdas 

- Usually you pass parameters to lambadas by value or reference. 

- When you pass the variables by values you are not allowed to change / assign to those variables in the scope of implementation of the lambda. 

- **Mutable** keyword makes this possible

> \[\=\]()mutable{a=3; cout << a << endl ; } ; 
    >> a still retains its old value after this but prints 3 inside the lambda expression 

## Delegating Constructors 

- C++98 dint allow you to call one constructor from another. C++11 allows you to 


## Static Cast

- Evaluated at compile time 

> Parent &&parentObj = static\_cast\<Parent &&\>(lvalueobj) ; 

## Curiously Recurring Template Pattern (CRTP)

- Virtual functions resolution at runtime using VTables is a big cost to pay. 

- However such resolution could be used at compile time and run time cost could be avoided. 

- CRTP is a design pattern in C++ in which a class X derives from a class template instantiation using X itself as template argument. More generally it is known as F-bound polymorphism.

- This is a time vs space trade off

- Another use case of CRTP is, when it’s required to access the derived class object in the base class member functions then will have to use CRTP.

    template<typename T>
    class Parent{
        void somefunction{
            auto derived = static_cast<T*>(this) ;
            derived->somefunction() ;
        }
    };

## Dynamic Cast

- Run Time Type Information needs to be turned on in compilers

- Type information using dynamic\_cast\<T\> is derived at run time. 

- This is thus safer than the static\_cast for polymorphism as static\_cast will allow base class objects to be pointed by derived class pointers. 

- Dynamic cast returns nullptr if the run time type check fails 

    Derived\* derivedptr = dynamic\_cast\<Derived\*>(Parentptr) ;

## Reinterpret cast

- Has even less checks than static cast.

- Used when static and dynamic cast cannot be used for casting very very different objects from one another. 

## Perfect Forwarding

- Correctly infers the reference type.

- Use static\_cast to correctly infer the argument type to be lvalue or rvalue. 

    template<typename T>
    void check(T &&arg){
        otherfunction(static\_cast<T>(arg)) ;
    }

- If you don't use static\_cast the reference collapses and you end up calling the lvalue function everytime. 

- One special function to this casting is forward. Which does exactly the same thing as static\_cast but is intended for these purposes.

    template<typename T>
    void check(T &&arg){
        otherfunction(forward<T>(arg)) ; 
    }

## Type Inference

- C++ infers the type strictly from the arguments of the function. If you dont use <>

- You can explicity state the template type T by using show\<double\>(arguments) ;  

## Bind && Placeholders

- include functional header and use namespace placeholders ;

> auto addElem = bind(functionName,\_2,\_1,3) ;
    >> now you can call addElem(arg1,arg2) and it thereby calls the function functionName with arguments(arg2,arg1,3)

> Most common use is to bind to the methods of class

    class Test{
        public:
            void add(int,int,int);
    }; 
    Test test ; 
    auto bindex = std::bind(&Test::add,test,_1,_2)

> Arugments to std::bind to bind methods - pointer to the function , object of the class , arguments/placeholders to the function 

## Smart Pointers
### unique\_ptr 

> unique\_ptr\<myClass[]\> ptrName(new myClass[2]) ; 

> unique pointers take care of deallocation of memory when the variable goes out of scope 

    class myClass{
        private:
            unique_ptr<int[]> myPtr ;
        public:
            myClass : myPtr(new int[3]){
            }
    }; 

> Note the difference between the following 2 lines of codes: 

    unique_ptr<int[]> myPtr(new int[3]) 
    unique_ptr<int> myPtr(new int(3)) 

> There is always a single unique pointer pointing to a single resource. So you can't do assignment to unique pointers 

>> However you can move the unique pointer to point to other resource using the new move semantics. 

    unique\_ptr\<int\> myPtr(new int) ; 
    unique\_ptr\<int\> newPtr = std::move(myPtr); 

> the () are the constructor brackets used. For classes declare the unique pointers and then initialize them in constructors of the class. 

> The get() method of unique pointers gets you the raw pointer to the particular address. Ex when you want to cast an int pointer to a char * you need to use get.

### Shared Pointers.

> There can be multiple shared pointers pointing to a single resource and thus you can do assignment operations in shared pointers. 

> Shared pointers internally keep a reference count and delete the resource only when all the references have gone out of scope. 

    shared\_ptr\<int\> myPtr(new int) ; 

> A better way to make shared pointers is using the following: This also initializes the value the pointer is pointing to  

    shared\_ptr\<int\> myPtr = make\_shared\<int\>(10) ; 

## Const Keyword
- Const Keyword Directly applies to whatever is to the immediate left of the keyword. 

- If nothing is to the immediate left of the keyword whatever to the immediate right is taken. 

> const char * p ======> pointer to a const char 

> char const * p ======> pointer to a const char 

> char * const p ======> constant pointer to a char 

- int const\* and const int\* are both the same and mean that the pointer is pointing to a constant integer whose value shouldnt be changed although the pointer can point to different constant integers. 

- int\* const is constant pointer to an integer. So the address where the pointer is pointing cannot change.

## std::string 

- std::string is of the basic\_string type and so you should not include cstring / string.h headers along with it. 

- std::string can be casted to the const char\* format using std::string.c\_str() method 

- char \*x is just a pointer to the start of an char array 

- string x ; internally has 16 characters of space allocated on the stack and for longer string it uses memory on the heap

- you can access the character array of the string as char \*myArr = myString.c\_str();

## Templates

- templates are used for generic programming

- syntax: template <class T> or template <typename T>

- you can define 2 templates as well. template <typename T, typename U> 

> for defining class templates 

    template <typename T>;
        class Array{
            private:
                T* ptr ;
                int size;
            public:
                Array(T arr,int size); //constructor 
                Array(int index);
        }

> You can also define default values of the templates 
    >> e.g.    template <typename T, typename U =char>

> You can also pass non type parameters to templates. They are usually used to specify max or min values or const value for an instance of a template. It should be a compile time constant though

- Difference between function overloading and templates:
    - Function overloading is used when different argument based functions do **similar** functionality 
    - Templates are used when they have **identical** functionality 

> Ques. What happens when there is static member in a template class/function?
    >> Ans. Each instance of a template contains its own static variable.

## Extern Keyword 

- To give a constant an external linkage so that it can be referenced from another file we define it using the keyword reference. 
    - e.g. extern const int z = 3; 

## Typedef Keyword 

- typedef is used to make aliases for defining new variable types.

- Usually used to convey logical information to the reader or to make larger representations easy to use
    > typedef int* int_pt ;
    > typedef map<list<int>,vector<int>>::iterator mapitr ; 


## Copy Constructor vs Assignment Operator 

- A copy constructor can be called in the following cases:
    1. A function returns an object by value 
    2. An object is passed as an argument by value
    3. A new object is initialized using an existing one. e.g. classA a = b; Copy constructor is called.
    4. Compiler generates an temporary object. 

> classA a = b; copy constructor 

> ClassA a ,b ; a = b ; assignment operator 

- Copy constructor takes const lvalue reference as the parameter so that both lvalue and rvalue refs can be captures as arguments

- Assignment operator returns reference to the object (\*this) so that the object is passed by reference and not by value because
if the object is passed by value everytime you do the assignment a copy constructor and a destructor will be called as well. 

> Remember to delete the heap memory in assignment operator if it has been already allocated in the constructors 

## Move Constructors 

- Move constructors are used to take advantage of the memory allocated by temporary objects. 

- They take in rvalue references as the parameter

- One random issue could be assigning the moving temp object to itself. 

- Another issue could be that the destructor of the temporary object delete the heap memory if we are using it. 

- However you could ensure that the memory is not deleted if before the destructor is called the pointer that memory block is moved and set to nullptr. 

## Private Constructors 
- Constructors can be defined in the private members but then inheritance of that class wont work

- Virtual destructors should be use if you have a virtual function ! Deleting the base pointer to the derived object only clears the base pointer memory 

## File Input/Output 

- File input and output are handled by streams. 

- ios is a base class that has istream and ostream as the 2 derived classes 

- iostream is the class that we have access to and is derived from istream and ostream. 

- cin is the object of istream class and cout is the object of ostream class. 

- ios gives us 2 functions get(char) or get(void) and put(char). They must be invoked on the appropriate iostream objects. 

- Also we get getline and write functions as getline(char * ,int size). Newline character is read and the reading process is stopped. 

- The char\* array is terminated with the null character

- write statement will output write(char \*,int size) size number of characters starting from charr[0] irrespective of the size of char array used in the argument. 

- ios functions
  > width() precision() fill() setf() unsetf()

- c++ never truncates the values if the width is less than what we need to output. it then just appends it at the end of the buffer

- width() should be called for each string. 

- precision() retains the settings until it is reset 

- default precision is 6 digits. 

- filling the unused fill widths with special characters can be done using fill() cout.fill('\*'). Fill is retained until reset

- cout.setf(ios::showpoint) ; is used to display trailing zeros

- Alternatives to the above functions are mainupulators. cout << setw(5) << x << endl  ;

    fin.eof() != 0 ;// checks condition for the end of file
    f.good() ;
    f.fail() ;
    f.good() ;


## Priority Queues Implementation 

> priority\_queue(T,vector\<T\>,comparator) ;

    class comparator{
        bool operator()(classA a1, classB b1){
            //Implementation
        }
    };

