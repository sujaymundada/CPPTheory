/*************************** Sujay *************************
  
* File Name             :   nestedclases.cpp
    
* Author                :   Sujay

* Creation Date         :   10-06-2020

* Last Modified         :   Wed Jun 10 10:17:19 2020

***********************************************************/


#include<iostream>
#include"ring.h"
using namespace std;
int main(){

    ring<double> myRing(3);

    myRing.add(1);
    myRing.add(2.2);
    myRing.add(3);
    myRing.add(4.2);

    for(ring<double>::iterator it = myRing.begin() ; it != myRing.end() ; it++) cout << *it << endl ;

    /* The following syntax also evaluates to the above expression thus to use it you have to overload
    * the relevant operators in your iterator class 
    */ 

    for(auto x : myRing) {
        cout << x << endl ; 
    }

}
