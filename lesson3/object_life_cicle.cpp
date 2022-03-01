#include<iostream>

// use -Wall when compiling
using namespace std;

class Example{
    int count;
    int* arr;
public: 
    Example(){
        cout<<"Hello from default constructor"<<endl;
    }

    Example(int i)
    :count(i), arr(new int[i])
    {
        cout<<"Hello from constructor"<<endl;

    }
    ~Example(){
        cout<<"Hello from destructor"<<endl;
    }

    void print()const{
        cout<<"In print"<<endl;
    }

};

int main(){
    Example e(1);

    e.print();

    Example* e2 = new Example();

    delete e2;

    return 0;
}