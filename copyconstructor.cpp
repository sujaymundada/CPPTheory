/*************************** Sujay *************************
  
* File Name             :   copyconstructor.cpp
    
* Author                :   Sujay

* Creation Date         :   10-06-2020

* Last Modified         :   Fri Jun 19 19:27:22 2020

***********************************************************/

#include<iostream>
#include<map>
using namespace std;


struct Point{
    int x;
    int y;

    Point():x(0),y(0){
    }

    Point(int x,int y):x(x),y(y){
    }

    Point(const Point &other){
        cout << "Copy Constructor" << endl ;
        x = other.x; 
        y = other.y; 
    }
};



int main(){
    map<int,Point> newmap ; 

    pair<int,Point> pp= make_pair(10,Point(1,2)); 
    cout << "Here" << endl ; 
    newmap.insert(make_pair(10,Point(1,2))); 
    /* Number of copy constructors 
    *   2 copy constructors are called here 
    */
    cout << "Here2" << endl; 
    newmap.insert(pp) ; 
}
