/*************************** Sujay *************************
  
* File Name             :   functors.cpp
    
* Author                :   Sujay

* Creation Date         :   10-06-2020

* Last Modified         :   Fri Jun 19 19:31:04 2020

***********************************************************/

/* Any object that is callable and has the operator () overloaded is called a function */ 

/* To represent all general functor you could do the following */
#include<functional>
#include<iostream>

using namespace std; 

/* Use of function library to represent all kinds of functors including lambdas */ 
void SomeRandomFunction(function<bool(int k)> boolfunc){
    cout << boolfunc(3) << endl;
}

/* You can now call SomeRandomFuntion using 
 * lambda expression 
 * function pointer
 * some class object which has () operator overloaded 
 */ 
 
bool match(int k){
    cout << "here" << endl ; 
    return k==3;
}


int main(){
    
    bool (*functor)(int) = match ;

    SomeRandomFunction(functor) ; 

    SomeRandomFunction(match) ; 
    
    /* Lambda Expression */ 
    SomeRandomFunction([](int k=3){return k==3;}); 

}
