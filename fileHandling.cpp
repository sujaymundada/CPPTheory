/*************************** Sujay *************************
  
* File Name             :   fileHandling.cpp
    
* Author                :   Sujay

* Creation Date         :   10-06-2020

* Last Modified         :   Wed Jun 10 10:17:58 2020

***********************************************************/

#include<iostream>
#include<fstream>

using namespace std;


int main(){
    fstream obj ;

    obj.open("myfile.txt",ios::out) ; //ios::out is a static member of the ios class

    if(obj.is_open()){
        obj << "Sujay testing file output" << endl;
        obj.close();
    }
}
    


