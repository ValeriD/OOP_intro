#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

enum Color{
    RED,
    GREEN,
    BLUE,
    PURPLE
};

class Figure{

protected:
    char* name;
    size_t sides;
    Color color;
public:
    Figure()
    :sides(3), color(Color::RED)
    {
        name = strdup("");
    }

    Figure(const char* name, size_t sides, Color color)
    :sides(sides), color(color)
    {
        this->name = strdup(name);
    
    }
    ~Figure(){
        delete [] name;
    }

    size_t getSides() const{ return this->sides;}
    char* getName() const{ return this->name; }
};

class Triangle: public Figure{
    size_t height;
    vector<double> angles;
public:
    Triangle():Figure(){}
    Triangle(const char* name, size_t sides, Color color, vector<double>& angles)
    :Figure(name, sides, color), angles(angles)
    {
    }
    ~Triangle(){}

};


int main(){
    vector<double> angles = {60,60,60};
    Triangle* t = new Triangle("T1", 3, Color::GREEN, angles);
    Figure* f = t;
    cout<< f->getSides() << " " << f->getName() <<endl;
    delete f;
    return 0;
}