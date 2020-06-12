/*************************** Sujay *************************
  
* File Name             :   newfile.cpp
    
* Author                :   Sujay

* Creation Date         :   10-06-2020

* Last Modified         :   Wed Jun 10 10:17:19 2020

***********************************************************/


#include<iostream>
using namespace std;

template <typename T>
class ring{
    public:
        /* Nested class */ 
        /* This class can access all the members of the outer class
        * Just as any other member function -- including the private members
        * But the outer class cannot access all the members of the nested class
        */ 

        class iterator ;
    private:
        T* m_arr;
        const int m_size; 
        int m_pos; 
    public:
        ring():  m_arr(NULL),m_size(0), m_pos(0){
        }
        
        ring(int n): m_size(n), m_pos(0), m_arr(NULL){
            m_arr = new T[n] ;
        }

        ~ring(){
            delete [] m_arr;
        }

        iterator begin(){
            cout << "begin is called" << endl ;
            return iterator(0,*this); 
        }
        iterator end(){
            cout << "end is called" << endl ; 
            return iterator(m_size,*this); 
        }

        void add(T x){
            m_arr[m_pos] = x ;
            m_pos ++; 

            if(m_pos >= m_size) m_pos = 0;
        }

        T &get(int pos){
            return m_arr[pos] ;
        }

};

template<typename T>
class ring<T>::iterator{
    public:
        int m_pos; 
        ring<T> &m_ring;
    public:


        iterator(): m_pos(0),m_ring(NULL){
        }

        iterator(int m,ring<T> &aring): m_pos(m), m_ring(aring){
        }

        iterator &operator++(int a){     //postfix operator 
            m_pos ++ ; 
            return *this ; 
        }
        
        iterator &operator++(){
            m_pos ++ ; 
            return *this ; 
        }

        bool operator!=(const iterator &other) const{
            return m_pos != other.m_pos ; 
        }

        T &operator*(){
            return m_ring.get(m_pos); 
        }

};
