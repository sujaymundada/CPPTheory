/*************************** Sujay *************************

* File Name             :   movesemantics.cpp
    
* Author                :   Sujay

* Creation Date         :   15-06-2020

* Last Modified         :   Mon Jun 15 20:23:48 2020

***********************************************************/


#include<iostream>
using namespace std;


class Test{
    public:
        int* m_pBuffer{nullptr} ;
        int m_size{0}; 

    public:
        /* Default Constructor */
        Test() : m_pBuffer(nullptr){
            cout << "Calling the basic Constructor" << endl ; 
        }

        /* Parametrized Constructor */
        Test(int m){
            m_size = m; 
            m_pBuffer = new int[m] ; 
            memset(m_pBuffer,0,m);
        }

        /* Deep Copy Custom Copy Constructor */
        Test(const Test& other){
            m_size = other.m_size ; 
            /* Allocating a new memory block and copying the memory is a overkill for temporary objects since they are anyways deleted
             * after this function call and their allocated resources are deleted as well which could be used directly
             * Hence move constructors are much more beneficial in such rvalue reference cases 
            */ 
            m_pBuffer = new int [m_size] ; 
            memcpy(m_pBuffer,other.m_pBuffer,m_size*sizeof(int)); 
        }

        /*Assignment Operator*/ 
        /* Assignment Operator Returns Lvalue Reference so that you could use chaining like test1 = test2 = test3 */ 
        /* However if you return by value everytime you do assignment you would call the copy constructor and destructor */ 
        Test& operator=(const Test& other){
            if(m_pBuffer) delete [] m_pBuffer ;
            m_size = other.m_size ; 
            m_pBuffer = new int [m_size] ; 
            memcpy(m_pBuffer,other.m_pBuffer,m_size*sizeof(int)); 
        }

        /* Move Constructor */ 

        Test(Test&& other){
            m_pBuffer = other.m_pBuffer ; 
            /* Deleting nullptrs in destructors is safe */ 
            /* The below line ensures that even after destructor is called on the object that was moved the original block of memory was not deleted */ 
            other.m_pBuffer = nullptr ; 
        }

        /* Destructor */
        ~Test(){
            delete [] m_pBuffer ; 
        }
};

int main(){

    Test myTest[50] ; 
    Test newTest = myTest[0] ; 
}


