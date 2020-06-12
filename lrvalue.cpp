/*************************** Sujay *************************
  
* File Name             :   lrvalue.cpp
    
* Author                :   Sujay

* Creation Date         :   10-06-2020

* Last Modified         :   Wed Jun 10 10:18:40 2020

***********************************************************/

#include<iostream>
using namespace std;

/* L values are defined as members which have addresses assigned to them */ 
/* The values returned from functions are usually R values. They are temporary nameless objects */ 

struct Test{
    private:
        int one{1};
        int two{2};

    public:
        int three{3};
        int four{4};

        Test(){
            auto pLambda = [one,two,three,four](){one=5;two=3;three=4;}; 
            pLambda(); 
        }

        void printMembers(){
            cout << one << " " << two << " " << three << " " << four << endl ; 
        }
};


int main(){
    Test test; 

    test.printMembers(); 
}

