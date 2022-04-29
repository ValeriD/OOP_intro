#include <iostream>
#include <vector>

using namespace std;


class House{
    string name;
    vector<string> houseMembers;
    string address;
    double area;

public:
    House()
    :name("")
    ,address("")
    ,area(0)
    {}

    House(const string& name, 
            const vector<string>& houseMembers,
            const string& address, 
            double area)
    :name(name)
    ,houseMembers(houseMembers)
    ,address(address)
    ,area(area)
    {
        if(name.empty() || address.empty() || area < 0) throw invalid_argument("Provided params are invalid!");
    }
    string& getName(){
        return name;
    }

    friend istream& operator>>(istream& in, House& h){

        in >> h.name;
        in >> h.address;
        in >> h.area;
        
        return in;
    }

    friend ostream& operator<<(ostream& out, House& h){
        out << "=================================="
            << "\n"
            << h.name 
            <<"\n"
            << h.address 
            <<"\n"
            << h.area
            << "\n" 
            << "==================================";
            

        return out;
    }
};

int main(int argc, char* argv[]){
    House h;
    cin >> h;
    cout << h << endl;
}