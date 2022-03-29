#include<iostream>
#include<cstring>
using namespace std;

char* strDup(const char* str){
    int size = strlen(str);
    char* res = new char[size+1];
    
    for(int i = 0; i <= size; i++){
        res[i] = str[i];
    }
    return res;
}

class Animal{
    char* name;
    char* breed;
    size_t age;
    double averageAge;

public:

    /**
     * @brief Construct a new Animal object
     * 
     */
    Animal(){
    }
    
    /**
     * @brief Construct a new Animal object
     * 
     * @param name 
     * @param breed 
     * @param age 
     * @param averageAge 
     */
    Animal(const char* name,const char* breed, size_t age, double averageAge)
    : age(age), averageAge(averageAge)
    {
        if(!name || !breed)return;

        this->name = strdup(name); //Allocates memory and copy the characters from name
        this->breed = strdup(breed);
    }

    /**
     * @brief Construct a new Animal object
     * 
     * @param other 
     */
    Animal(const Animal& other)
    : age(other.age), averageAge(other.averageAge)
    {
        if(!other.name || !other.breed)return;

        this->name = strdup(other.name);
        this->breed = strdup(other.breed);
    }

    /**
     * @brief Destroy the Animal object
     * 
     */
    ~Animal(){
        delete [] this->name;
        delete [] this->breed;
    }

   
    /**
     * @brief Assign operator
     * 
     * @param other 
     * @return Animal& 
     */
    Animal& operator=(const Animal& other){
        if(this == &other || !other.name || !other.breed)return *this;

        delete [] this->breed;
        delete [] this->name;
        
        this->age = other.age;
        this->averageAge = other.averageAge;
        this->name = strdup(other.name);
        this->breed = strdup(other.breed);

        return *this;
    }

    /**
     * @brief Getters
     */
    char* getName()const { return this->name;}
    char* getbreed()const { return this->breed;}
    size_t getAge() const{ return this->age;}
    double getAverageAge()const { return this->averageAge;}

};

class Zoo{
    char* managerName;
    char* address;
    double ticketPrice;
    Animal *animals;
    size_t capacity;
    size_t size;

    /**
     * @brief resizing the array of animals 
     * 
     */
    void resize(){
        this->capacity *= 2;
        Animal* new_animals = new Animal[capacity];
        for(size_t i = 0; i < this->size; i++){
            new_animals[i] = this->animals[i];
        }


        delete [] this->animals;
        this->animals = new_animals;
    }

    /**
     * @brief Moving all elements with one position to the left from the start parameter
     * 
     * @param start 
     */
    void shiftLeft(size_t start){
        for(size_t i = start; i < this->size-1; i++){
            this->animals[i] = this->animals[i+1];
        }
    }
public:

    /**
     * @brief Construct a new Zoo object
     * 
     * @param managerName 
     * @param address 
     * @param ticketPrice 
     */
    Zoo(const char* managerName, const char* address, double ticketPrice)
    :capacity(2), size(0), ticketPrice(ticketPrice)
    {
        if(!managerName || !address) return;

        this->managerName = strdup(managerName);
        this->address = strdup(address);
        this->animals = new Animal[capacity];
    }

    /**
     * @brief Construct a new Zoo object
     * 
     * @param other 
     */
    Zoo(const Zoo& other) 
    :capacity(other.capacity), 
    size(other.size),
    ticketPrice(other.ticketPrice){
        if(!other.managerName || !other.address || !other.animals) return;
        
        this->managerName = strdup(other.managerName);
        this->address = strdup(other.address);
        this->animals = new Animal[capacity];
        for(size_t i = 0; i<size; i++) this->animals[i] = other.animals[i];
    }

    /**
     * @brief Destroy the Zoo object
     * 
     */
    ~Zoo(){
        delete [] this->managerName;
        delete [] this->address;
        delete [] this->animals;
    }

    /**
     * @brief Assign operator
     * 
     * @param other 
     * @return Zoo& 
     */
    Zoo& operator=(const Zoo& other){
        if(this == &other || !other.managerName || !other.address || !other.animals) return *this;
        this->ticketPrice = other.ticketPrice;
        this->capacity = other.capacity;
        this->size = other.size;

        delete [] this->animals;
        delete [] this->address;
        delete [] this->managerName;
        this->managerName = strdup(other.managerName);
        this->address = strdup(other.address);
        this->animals = new Animal[capacity];
        for(size_t i = 0; i<size; i++) this->animals[i] = other.animals[i];
        
        return *this;
    }

    /**
     * @brief Adding new animal to the zoo
     * 
     * @param other 
     * @return int 
     */
    int addAnimal(const Animal& other){
        if(this->size == this->capacity){ //Check if resize is needed
            resize();
        }
        for(size_t i = 0; i<this->size; i++){ 
            if(strcmp(animals[i].getName() ,other.getName()) == 0){ //Check if animal with this name is found
                return -1; // Terminate the method
            }
        }

        this->animals[this->size++] = other;
        return 0;
    }

    /**
     * @brief Removing an Animal from the zoo by it's name
     * 
     * @param name 
     * @return int 
     */
    int removeAnimal(const char* name){
        if(!name) return -1; // -1 invalid input

        for(size_t i = 0; i<this->size; i++){
            if(strcmp(animals[i].getName(), name) == 0){ //Comparing the names
                shiftLeft(i); 
                this->size--;
                return 0; // 0 becaouse success
            }
        }

        return 1; // 1 because not found
    }

    /**
     * @brief Moving an animal to another zoo
     * 
     * @param other 
     * @param name 
     * @return int 
     */
    int moveAnimal(Zoo& other, const char* name){
        if(!name) return -1; // -1 invalid input

        for(size_t i = 0; i<this->size; i++){
            if(strcmp(animals[i].getName(), name) == 0){ //Find the animal
                if(other.addAnimal(animals[i]) != -1){
                    shiftLeft(i); 
                    this-size--;
                    
                    return 0; // 0 becaouse success
                }
            }
        }
        return 1; // 1 because not found
    }

};
int main(int argc, char* argv[]){
    return 0;
}