#include<iostream>


using namespace std;

class Book{
    string title;
    string author;
    size_t pageCount;


public:
    /**
     * @brief Construct a new Book object
     * 
     * @param title 
     * @param author 
     * @param pageCount 
     */
    Book(string title, string author, size_t pageCount)
    :title(title),
     author(author),
     pageCount(pageCount)
    {}

    /**
     * @brief Copy constructor for a new Book object
     * 
     * @param other 
     */
    Book(const Book& other)
    :title(other.title),
     author(other.author),
     pageCount(other.pageCount)
     {}
    /**
     * @brief Destroy the Book object
     * 
     */
    ~Book(){}

    Book& operator=(const Book& other){
        if (this != &other){
            this->title = other.title;
            this->author = other.author;
            this->pageCount = other.pageCount;
        }
        return *this;
    }
    /**
     * @brief Get the Title object
     * 
     * @return string 
     */
    string getTitle() const { 
        return this->title; 
    }

    /**
     * @brief Get the Author object
     * 
     * @return string 
     */
    string getAuthor() const { 
        return this->author; 
    }

    /**
     * @brief Get the Page Count object
     * 
     * @return size_t 
     */
    size_t getPageCount() const {
         return this->pageCount; 
    }
};


int main(){

    Book b("Harry Potter", "J.K.Rowling", 400);
    Book b1 = b;

    cout<< b.getTitle() << endl;
    cout<< b.getAuthor() << endl;
    cout<< b.getPageCount() << endl;

    return 0;
}