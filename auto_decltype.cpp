/*************************** Sujay *************************
  
* File Name             :   auto_decltype.cpp
    
* Author                :   Sujay

* Creation Date         :   10-06-2020

* Last Modified         :   Wed Jun 10 10:17:19 2020

***********************************************************/



#include<iostream>
#include<string>
using namespace std;

template<typename T>

/* Use functions with trailing return types if the return values from it are ambiguous */ 
/* If the return value can be safely deduced by the compiler then you can directly use auto with function return types */

auto printValue(T t) -> decltype(t){
    cout << t << endl ;
    return t ; 
}

int main(){
    int k = 3; 
    decltype(k) retval = printValue(k) ;    /* decltype is used to deduce type of a variable */ 
    string s = "Sujay" ;
    decltype(s) retval2 = printValue(s) ;
    return 1; 
}

