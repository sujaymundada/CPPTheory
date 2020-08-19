/*************************** Sujay *************************
  
* File Name             :   vector.cpp
    
* Author                :   Sujay

* Creation Date         :   10-06-2020

* Last Modified         :   Sun Jun 21 11:10:32 2020

***********************************************************/


#include<iostream>
#include<vector>
using namespace std;


/* Understanding the difference between vector size and capacity */ 
/* Understanding the vector memory allocation scheme */ 

template<typename T>
void printStats(vector<T>a){
    cout << "Size: " << a.size() << endl ;
    cout << "Capacity: " << a.capacity() << endl; 
}

int main(){
    vector<double> numbers{10,11,12,13}; /* Size of vector 5 and capacity 5 */  /* Initializes to 0 value */ 
    
    auto lambda = [](auto i){cout << i << " ";}; 
    printStats(numbers); 

    numbers.resize(4);     /* Changes size of the vector and increases capacity if capacity is less */ 
    
    std::for_each(numbers.begin(),numbers.end(),lambda) ; 
    cout << endl ; 
    numbers.insert(numbers.begin()+2,3) ; 
    std::for_each(numbers.begin(),numbers.end(),lambda) ; 
    cout << "Sujay:" << endl ;
    numbers.emplace(numbers.begin()+2,4); 
    std::for_each(numbers.begin(),numbers.end(),lambda) ;
    cout << endl ;
    return 0; 
    
    for(int i=0;i<100;i++){
        numbers.push_back(i);   /* If size exceeds capacity then the capacity is increased */ 
        printStats(numbers); 
    }

    printStats(numbers); 
    numbers.reserve(100);   /* No effect on the size of the vector but changes the capacity */ 

    printStats(numbers); 

    /* 2 dimensional vectors */ 

    vector< vector<double> > grid(3,vector<double>(5,0)); /* Initializes 3 members of vectors of size 5 initialized to 0 */

    printStats(grid);

}

