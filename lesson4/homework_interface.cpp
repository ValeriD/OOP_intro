#include <iostream>

using namespace std;
class Book{
    string title;
    string author;
    size_t pageCount;
    bool isAvailable;


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
     pageCount(pageCount),
     isAvailable(true)
    {}

    /**
     * @brief Copy constructor for a new Book object
     * 
     * @param other 
     */
    Book(const Book& other)
    :title(other.title),
     author(other.author),
     pageCount(other.pageCount),
     isAvailable(other.isAvailable)
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
            this->isAvailable = other.isAvailable;
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
    bool isBookAvailable()const{
        return this->isAvailable;
    }

    void changeAvailability(bool to){
        this->isAvailable = to;
    }
};


class Library{

    //Array of books, books count, array size, capacity

    /**
     * @brief Resizing the array with double capacity. Resize is private method because it is used only by the addition of the book
     * 
     */
    void resize(){}
public:
    /**
     * @brief Construct a new Library object. Creating empty library with the booksCount as capacity
     * 
     * @param booksCount 
     */
    Library(size_t booksCount){}

    /**
     * @brief Construct a new Library object. Creating library with books count as capacity and copying the Book objects from books
     * 
     * @param books 
     * @param booksCount 
     */
    Library(Book* books, size_t booksCount){}

    /**
     * @brief Construct a new Library object. Copy constructor
     * 
     * @param other 
     */
    Library(const Library& other){}


    /**
     * @brief Assign operator overloading
     * 
     * @param other 
     * @return Library& 
     */
    Library& operator=(const Library& other){} //Write it if you want it is almost the same as the copy constructor

    /**
     * @brief Get a book at the provided index. Validate the index
     * 
     * @param index 
     * @return const Book& 
     */
    const Book& at(size_t index)const{};

    /**
     * @brief Adding a Book to a Library. Check if a Book with this name already exists in the library if so return -1, else return 0.
     * 
     * @param book 
     */
    int add(const Book& book){}

    /**
     * @brief Remove a book from the array. Return -1 if not found, else return 0
     * 
     * @param title 
     * @return int 
     */
    int remove(string title){}

    /**
     * @brief Change the isAvailable field of the book. Aka lending the book. Validate if the book is available
     * 
     * @param title 
     * @return int 
     */
    int lendBook(string title){}

    /**
     * @brief Change the isAvailable field of the book. Aka returning a landed book. Make a validation if this book has been lended
     * 
     * @param title 
     */
    void returnBook(string title){}
};