/*************************** Sujay *************************
  
* File Name             :   lrvalue.cpp
    
* Author                :   Sujay

* Creation Date         :   10-06-2020

* Last Modified         :   Mon Jun 15 19:45:53 2020

***********************************************************/

#include<iostream>
using namespace std;

/* L values are defined as members which have addresses assigned to them */ 
/* The values returned from functions are usually R values. They are temporary nameless objects */ 

template<typename T>
void checkR(T &&rvalue){
    cout << "This function only takes rvalue references" << endl ; 
}

template<typename T> 
void checkL(T &lvalue){
    cout << "This function only takes lvalue references" << endl ; 
}

template<typename T>
void checkAll(const T& generalReference){
    cout << "This function takes both lvalues and rvalues" << endl ; 
}


struct Test{
    private:
        int one{1};
        int two{2};

    public:
        int three{3};
        int four{4};

        /* this pointer cannot be implicity captures in the lambda */
        /* It has to be explicity stated in the parameters */ 
        Test(){
            auto pLambda = [&](){one=5;two=3;three=4;}; 
            pLambda(); 
        }

        void printMembers(){
            cout << one << " " << two << " " << three << " " << four << endl ; 
        }
};


int main(){
    Test test; 

    test.printMembers(); 

    checkR(5) ; 

    int l = 5; 
    checkL(l); 

    checkAll(l); 
    checkAll(5) ; 
}

