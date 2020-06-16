# Udemy Course Files

## c++ tutorial 

## CONST KEYWORD 
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

## TEMPLATES 
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
    e.g.    template <typename T, typename U =char>

> You can also pass non type parameters to templates. They are usually used to specify max or min values or const value for an instance of a template. It should be a compile time constant though

- Difference between function overloading and templates:
    - Function overloading is used when different argument based functions do **similar** functionality 
    - Templates are used when they have **identical** functionality 

> Ques. What happens when there is static member in a template class/function?
>> Ans. Each instance of a template contains its own static variable.

## extern keyword 

- To give a constant an external linkage so that it can be referenced from another file we define it using the keyword reference. 
    e.g. extern const int z = 3; 

## typedef keyword 

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

> fin.eof() != 0 // checks condition for the end of file
> f.good()
> f.fail()
> f.good()


## Priority Queues Implementation 

> priority\_queue(T,vector<T>,comparator) ;

    class comparator{
        bool operator()(classA a1, classB b1){
            //Implementation
        }
    };

## Mutuable Lambdas 

- Usually you pass parameters to lambadas by value or reference. 
- When you pass the variables by reference you are not allowed to change / assign to those variables in the scope of implementation of the lambda. 

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











