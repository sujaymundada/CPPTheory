/*************************** Sujay *************************
  
* File Name             :   initializer_list.cpp
    
* Author                :   Sujay

* Creation Date         :   10-06-2020

* Last Modified         :   Wed Jun 10 10:18:12 2020

***********************************************************/



#include<iostream>
#include<initializer_list> 
using namespace std; 

/* Initializer lists are used so that you can use the {} braced initialization for your classes / structs */
/* The default constructor is lost if you use initliazer list however you can use the empty braces */ 

struct R{
    R(initializer_list<string> texts){
        for(auto text: texts) cout << text << endl ; 
    }

    R() = default ;

    void print(initializer_list<string> texts){
        for(auto text: texts) cout << text << endl ; 
    }
};

int main()
{
    R r1{"Sujay","Harsh"}; 

    R r2; 

    r1.print({"Sujay","harsh"}); 
}

