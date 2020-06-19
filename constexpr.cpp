/*************************** Sujay *************************

* File Name             :   constexpr.cpp
    
* Author                :   Sujay

* Creation Date         :   19-06-2020

* Last Modified         :   Fri Jun 19 14:11:14 2020

***********************************************************/
#include<iostream>
using namespace std; 

constexpr long int fib(int n)
{
    return (n <= 1)? n : fib(n-1) + fib(n-2);
}

int main ()
{
    // value of res is computed at compile time.
    //const long int res = fib(30);
    long int res2 = fib(28); 
    cout << res2;
    return 0;
}

