#include<iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////
// TASK:
// Implement as many methods as you can.
////////////////////////////////////////////////////////////////////////

struct vector_t{
    int* data;
    size_t size;
    size_t capacity;
};

typedef struct vector_t vector_t;

/**
 * @brief Initializing the vector with the provided capacity
 * 
 * @param capacity 
 * @return vector_t* 
 */
vector_t* init(size_t capacity = 2);
// Or vector_t init(size_t capacity = 2);

/**
 * @brief Creates a new vector with the same elements as the provided vector
 * 
 * @param vector 
 * @return vector_t* the copied vector
 */
vector_t* copyVector(const vector_t* vector);
//Or vector_t copyVector(vector_t& vector);

/**
 * @brief Retrieves the value of the vector at the provided index
 * 
 * @param vector 
 * @param index 
 * @return int 
 */
int at(const vector_t* vector, size_t index);
//Or int at(const vector_t& vector);


/**
 * @brief Inserts element at the back of the vector
 * 
 * @param vector 
 * @param element 
 * @return int 0 if successful, otherwise -1
 */
int push_back(const vector_t* vector, int element);
//Or int push_back(const vector_t& vector, int element);

/**
 * @brief Enlarge the vector with capacity*2
 * 
 * @param vector 
 */
void resize(vector_t* vector);
//Or void resize(vector_t& vector)

/**
 * @brief Removes the last element of the vector 
 * 
 * @param vector 
 * @param index 
 */
void remove_back(vector_t* vector);
//Or void remove_back(vector_t& vector);

/**
 * @brief Deletes the allocated memory by the vector
 * 
 * @param vector 
 */
void destroy(vector_t* vector);
//Or void destroy(vector_t& vector);