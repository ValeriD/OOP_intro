#include <iostream>

using namespace std;

class ExampleBase{
protected:
    int a;
public:
    ExampleBase(){
        
        cout<<"ExampleBase default constructor" << endl;
    }

    ExampleBase(int a){
        this->a = a;
        cout<<"ExampleBase parameter constructor" << endl;
    }

    ~ExampleBase(){
        cout<<"ExampleBase destructor" << endl;
    }
    int getA()const{ return this->a;}

};


class ExampleChild : public ExampleBase{

public:
    ExampleChild(int a):ExampleBase(a){
        cout<<"In Example child" << endl;
    }
    ~ExampleChild(){
        cout << "ExampleChild destructor" << endl;
    }
};

int main(){
    ExampleChild child(2);
    ExampleBase base(5);
    cout<< base.getA() << " " << child.getA() << endl;
    return 0;
}