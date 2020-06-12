/*************************** Sujay *************************
  
* File Name             :   exceptionHandling.cpp
    
* Author                :   Sujay

* Creation Date         :   10-06-2020

* Last Modified         :   Wed Jun 10 10:17:46 2020

***********************************************************/


#include<iostream>
#include<exception>
using namespace std;

/* Notes ***********

1. The standard practice for exceptions in C++ is ...

                **Throw by value, catch by reference**

Catching by value is problematic in the face of inheritance hierarchies. Suppose for your example that there is another type MyException which inherits from CustomException and overrides items like an error code. If a MyException type was thrown your catch block would cause it to be converted to a CustomException instance which would cause the error code to change.

2. throw() infront of the function signature tells the compiler that this function wont throw an exception 

3. class bad_alloc is a subclass of class exception 

4. Always put the subclasses catching blocks of codes before superclasses so that the right exception gets caught. 

5. A catch of superclass also catches the object of a subclass because of polymorphism. 

*/ 

void inheritanceError(){
    bool error1 = false;
    bool error2 = true;

    if(error1){
        throw std::bad_alloc();
    }

    if(error2){
        throw std::exception();
    }
}

/* std::bad_alloc exception */ 
class memoryAlloc{
    
    public:
        memoryAlloc(){
           double * ptr = new double [9999999999999999]; /* Throws std::bad_alloc() exception because it cannot allocate that much memory */ 
            delete [] ptr ;
        }
};
/*****************************/ 


/* throwing different types of exception int, string etc */
void errorFunc(){
    bool error = false; 
    bool serror = true; 

    if (error){ 
        throw 8; // You could throw strings or objects or particularly anything as exceptions 
    }

    if(serror){
        throw std::string("String Error") ; 
    }
}

/* building your own exception class */ 

class myException : public exception{
    public:
        virtual const char* what() const throw(){   // throw() infront of the function signature tells you that your function doesnt throw an exception
            return "Something bad has happened here" ; 
        }
}; 


class myCustomExceptionTest{
    public:
        myCustomExceptionTest(){
            throw myException();
        }
};



int main(){
    try{
        //errorFunc();

        //memoryAlloc mymem ; 

        //myCustomExceptionTest test; 

        inheritanceError(); 
    }
    catch(int e){
        cout << "Error encountered with error code: " << e << endl ; 
    }
    catch(char const * str){
        cout << "Error encountered with string " << str << endl ;
    }
    catch(std::string e){ // You need to catch reference
        cout << "Error encountered with error code: " << e << endl ;
    }
    catch(std::bad_alloc &e){
        cout << "Error encountered with error code: " << e.what() << endl ; 
    }
    catch(myException &e){
        cout << "Error encountered with error code: " << e.what() << endl ;
    }
    catch(std::exception &e){
        cout << "Error encountered with error code: " << e.what() << endl ; 
        // bad_alloc gets caught here but since what is a virtual method. The right function gets executed.
    }
    catch(std::bad_alloc &e){
        cout << "Error encountered with error code: " << e.what() << endl ;
    }
}
