/*************************** Sujay *************************

* File Name             :   myString.cpp
    
* Author                :   Sujay

* Creation Date         :   28-07-2020

* Last Modified         :   Wed Jul 29 08:53:46 2020

* Description           :   A custom string class with the required functions , constructors and destructors 

***********************************************************/

#include<iostream>
using namespace std ;


class myString{
    private:
        int m_len ;
        int m_buff ;
    public:
        myString(): m_len(0), m_buff(nullptr){
            cout << "Default Constructor" << endl ; 
        }

        myString(const char* buff): m_len(strlen(buff), m_buff(new char[m_len])
};
