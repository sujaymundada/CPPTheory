/*************************** Sujay *************************
  
* File Name             :   lamdaexpressions.cpp
    
* Author                :   Sujay

* Creation Date         :   10-06-2020

* Last Modified         :   Wed Jun 10 10:18:23 2020

***********************************************************/




#include<iostream>
using namespace std;

/* Lambda expression to get minimum of 2 numbers */ 
template<typename T>
auto pmin = [](T a,T b){ return a < b ? a : b ;}; 

/* Lambda expression to get addition of 2 numbers */ 
template<typename T>
auto psum = [](T a, T b){ return a+b;};

template<typename T>
auto add(T a, T b){
    return psum<T>(a,b);
}

template<typename S>
auto m_min(S a,S b){
    return pmin<S>(a,b); 
}


/* Usage of lambda expression in sort function */ 

/* Struct that stores the starting point of an event */ 

struct event{
    int start , end ; 
};

/* Sort an array of such structs so that events are sorted in order of their start times */ 

/* Always better to use trailing return types when the return values of functions are ambiguous */ 

int main(){
    //cout << add(1,2) << endl ;
    //cout << m_min(8.32,8.31) << endl ; 
    event arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} };
    int n = sizeof(arr)/sizeof(arr[0]);

    // sort the intervals in increasing order of
    // start time
    sort(arr, arr+n,[](event one,event two){return one.start < two.start;});

    cout << "Intervals sorted by start time : \n";
    for (int i=0; i<n; i++)
       cout << "[" << arr[i].start << "," << arr[i].end
            << "] ";

    return 0;
}
