#include <iostream>

using namespace std;

/////////////////////////////////////////////////////////////////
// C++ types:
// int, unsigned int, long int (long), short int (short) - Whole numbers
// char - Characters
// float, double - Dotted numbers
// bool - Booleans
/////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////
// C++ console input/output:
// cin - input
// cout - output
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
// C++ references:
// Great explanation at: https://stackoverflow.com/a/596750
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
// Dynamic memory:
//    malloc, calloc, realloc, free - C
//    new, delete - C++
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
// Example implementation of malloc / calloc
////////////////////////////////////////////////////////////////
char* Malloc(){
    char* arr = new char[10];
    return arr;
}

////////////////////////////////////////////////////////////////
// Example implementation of realloc
////////////////////////////////////////////////////////////////
char* Realloc(char* arr){
    char* newArray = new char[20];
    for(int i = 0; i < 10; i++){
        newArray[i] = arr[i];
    }
    delete [] arr;
    arr = newArray;
    return arr;
}


////////////////////////////////////////////////////////////////
//Declarations
////////////////////////////////////////////////////////////////


/**
 * @brief Vector data structure
 * 
 */
struct vector_t{
    int* data;
    size_t capacity;
    size_t size;
};

typedef struct vector_t vector_t;


/**
 * @brief Initialization of a vector
 * 
 * @param capacity with default value of 2
 * @return vector_t& - the newly created vector
 */
// FYI Относно въпросът: "Може ли да не връщаме референция, а да използваме копирането на структури?", отговорът е
// да, може, но не е препоръчително. В случаят няма да има проблем, но ако искаме да копираме една структура и ползваме
// обикновеното копиране, две структури ще имат пойнтъри към едни и същи данни. Помислете как това би счупило програмата.
vector_t init(size_t capacity = 2);


/**
 * @brief Freeing the allocated memory by the vector
 * 
 * @param v 
 */
void destroy(vector_t& v){
    delete [] v.data;
}


/**
 * @brief 
 * 
 * @param argc number of arguments, passed when the program is executed 
 * @param argv array of strings - the argumetns
 * @return int 
 */
int main(int argc, char* argv[]){

    // cout << "Hello world!" << endl;

    // int a, b;
    // cin >> a >> b;

    // cout << a
    //     << " " 
    //     << b 
    //     << endl;
    
    // float, double - 1.34 

    vector_t v = init(); // -> Capacity = 2
    vector_t v1 = init(5); // -> Capacity = 5
    
    destroy(v);
    return 0;
}

////////////////////////////////////////////////////////////////
//Implementation
////////////////////////////////////////////////////////////////

vector_t init(size_t capacity = 2){
    vector_t v;
    v.data = new int[capacity];
    v.capacity = capacity;
    v.size = 0;

    return v;
}

void destroy(vector_t& v){
    delete [] v.data;
}