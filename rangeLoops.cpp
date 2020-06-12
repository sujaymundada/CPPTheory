/*************************** Sujay *************************
  
* File Name             :   rangeLoops.cpp
    
* Author                :   Sujay

* Creation Date         :   10-06-2020

* Last Modified         :   Wed Jun 10 10:17:19 2020

***********************************************************/


#include<iostream>
using namespace std;


/* Using auto to iterate through ranged loops */ 

int main(){
    
    int arr[100000] = {0}; 
    
    /* The following syntax is similar to 
     * for(auto j = arr.begin(); j!=arr.end() ; j++) 
     *
     */ 
    for (auto j: arr){

        for (auto i:arr ){
            continue ; 
        }
    }
}
