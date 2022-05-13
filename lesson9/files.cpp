#include<iostream>
#include<fstream>

using namespace std;

int main(){

    fstream f;
    f.open("example.txt", ios::in | ios::out | ios::trunc);

////////////////////////////
Name: 
Artist:
Length: 
/////////////////////////////

    f << "Hello, world\n";

    string str;
    
    f.seekg(0, ios::beg);

    
    getline(f, str);
    cout << str << endl;

    f.close();
    
    return 0;
}