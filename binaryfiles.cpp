/*************************** Sujay *************************
  
* File Name             :   binaryfiles.cpp
    
* Author                :   Sujay

* Creation Date         :   10-06-2020

* Last Modified         :   Wed Jun 10 10:17:26 2020

***********************************************************/

#include<iostream>
#include<fstream>

using namespace std;


/* This preprocessor directive is used to turn off packing in structs */ 
/* A struct always aligns its member variables in chunks of 4 bytes for a 32 bit system and 8 bytes for a 62 bit system */ 

#pragma pack(push,1)
struct Person{
    char name[50];
    double height;
    int age;
};
#pragma pack(pop)



int main(){
    Person sujay = {"Sujay",1.82,24};

    fstream myFile ; 

    string filename = "output.bin";

    myFile.open(filename,ios::binary | ios::out);   /* out and binary are static members (flags) of the ios class */ 

    if(myFile.is_open()){
        myFile.write(reinterpret_cast<char *>(&sujay),sizeof(sujay));   /* You have to specify how many bytes to write as an argument to write function */ 
        myFile.close();
    }
    else{
        cout << "Error in file opening" << endl;
    }

    Person who ; 
    myFile.open(filename,ios::binary | ios::in);

    if(myFile.is_open()){
        myFile.read((char *) &who, sizeof(who)); 
        myFile.close();
    }
    else{
        cout << "Error in reading the file" << endl ; 
    }


    cout << who.name << ", " << who.age << ", " << who.height << endl ; 
}



