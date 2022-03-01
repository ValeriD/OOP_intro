#include<iostream>
#include<cmath>

using namespace std;

class Figure{
    size_t sides;
    size_t side_length;


public:
    /**
     * @brief Construct a new Figure object
     * 
     */
    Figure()
    :sides(3), side_length(1)
    {}


    /**
     * @brief Construct a new Figure object
     * 
     * @param sides 
     * @param side_length 
     */
    Figure(int sides, size_t side_length){
        if(sides < 3 || side_length == 0){
            return;
        }

        this->sides = sides;
        this->side_length = side_length;
    }

    /**
     * @brief Get the Sides Count object
     * 
     * @return size_t 
     */
    size_t getSidesCount()const{
        return this->sides;
    }

    /**
     * @brief Get the Sides Length object
     * 
     * @return size_t 
     */
    size_t getSidesLength()const{
        return this->side_length;
    }

    /**
     * @brief Set the Sides object
     * 
     * @param sides 
     */
    void setSides(size_t sides){
        if (sides < 3){
            return;
        }
        this->sides = sides;
    }
    /**
     * @brief Set the Side Length object
     * 
     * @param side_length 
     */
    void setSideLength(size_t side_length){
        if( side_length == 0){
            return;
        }
        this->side_length = side_length;
    }

    /**
     * @brief Calculates the Perimeter of the figure
     * 
     * @return size_t 
     */
    size_t calculatePerimeter() const{
        return this->side_length * this->sides;
    }

    /**
     * @brief Calculates the area of the figure
     * 
     * @return double 
     */
    double calculateArea() const{
        return this->sides * pow(this->side_length,2) * (1 / tan(M_PI/this->sides)) / 4; //Formula from internet
    }

};