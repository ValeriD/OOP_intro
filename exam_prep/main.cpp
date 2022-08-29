#include <iostream>

using namespace std;

class MyString
{
    unsigned size; // number of characters until '\0'
    unsigned capacity;
    char *buffer; // pointer to the first block of the memory

    //
    // buffer
    //   |
    // ______ | ______  | ______ | _____ | ______ | ______ | ______ | ....
    //   ^
    // newBuffer

    void resize()
    {
        char *newBuffer = new char[this->capacity * 2];
        for (int i = 0; i < this->size; i++)
        {
            newBuffer[i] = this->buffer[i];
        }
        delete[] this->buffer;

        this->buffer = newBuffer;
        this->capacity *= 2;
    }

public:
    MyString()
    {
        this->size = 0;
        this->capacity = 2;
        buffer = new char[this->capacity];
        buffer[0] = '\0';
    }

    ~MyString()
    {
        delete[] this->buffer;
    }

    MyString(const string &s)
    {
        this->size = s.size();
        cout << this->size << endl;
        this->capacity = s.size() + 1;

        this->buffer = new char[this->capacity];

        //
        for (unsigned i = 0; i < s.size(); i++)
        {
            this->buffer[i] = s[i];
        }

        this->buffer[this->size] = '\0';
    }
    MyString(const MyString &other)
    {
        this->size = other.size;
        this->capacity = other.capacity;
        this->buffer = new char[this->capacity];
        for (int j = 0; j <= other.size; j++)
        {
            this->buffer[j] = other.buffer[j];
        }
    }

    MyString &operator=(const MyString &other)
    {
        if (this != &other)
        {
            this->size = other.size;
            this->capacity = other.capacity;

            delete[] this->buffer;
            this->buffer = new char[this->capacity];
            for (int i = 0; i <= other.size; i++)
            {
                this->buffer[i] = other.buffer[i];
            }
        }
        return *this;
    }

    unsigned getSize() const
    {
        return this->size;
    }

    unsigned getCapacity() const
    {
        return this->capacity;
    }
    const char *c_str() const
    {
        return this->buffer;
    }
    void append(const string &s)
    {
        if (this->capacity <= s.size() + this->size)
        {
            resize();
        }

        for (int i = 0; i <= s.size(); i++)
        {
            this->buffer[this->size + i] = s[i];
        }
    }
};

int main()
{
    MyString s("ab");
    string b("ba");
    s.append(b); // -> abba
    return 0;
}