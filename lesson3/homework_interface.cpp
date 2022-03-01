#include<iostream>


//============================================================================
// Homework on basic class
//============================================================================

class Planet{
    //TODO add fields
public:
    Planet(const char *name, double distanceToSun, double diameter, double weight);
    ~Planet();

    //TODO add getters and setters

    void print();
    double getSecondsToSun();
};

int main(){

    //Get the name from the console
    //Then create an object of type Planet and test all the methods.

    return 0;
}