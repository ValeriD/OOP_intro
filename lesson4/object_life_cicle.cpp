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

    Example(const Example& other){
        cout<< "Hello from copy constructor"<<endl;

        this->count = other.count;
        this->arr = new int[other.count];
        for(int i=0; i<other.count; i++){
            this->arr[i] = other.arr[i];
        }

    }

    Example& operator=(const Example& other){
        
        cout<< "Hello from assign operator"<<endl;
        if(this == &other){ // Check if we want to copy the same object
            return *this;
        }
        this->count = other.count;
        delete [] this->arr;
        this->arr = new int[other.count];
        for(int i=0; i < other.count; i++){
            this->arr[i] = other.arr[i];
        }
        return *this;
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
    Example e2(2);
    Example e3 = e; //Copy constructor
    e = e2; //Copy assignment

    return 0;
}