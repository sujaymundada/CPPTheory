#include<iostream>
#include<memory>
using namespace std;

int main(){
    int *test = new int[20];
    memset(test,0,10);

    memset(test+10,0,10);

    for(int i=0;i<20;i++){
        cout << test[i] << " ";
    }
    cout << endl ;
}
