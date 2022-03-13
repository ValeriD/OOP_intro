#include<iostream>
#include<cstring>
//----------------------------------------------------------------
// Preparation for exam homework
//----------------------------------------------------------------

using namespace std;

class Song{
    //TODO add name, artist and length in seconds

public:
    /**
     * @brief Construct a new Song object
     * 
     */
    Song()
    {}

    /**
     * @brief Construct a new Song object
     * 
     * @param name needs validation
     * @param artist needs validation
     * @param length 
     */
    Song(const char* name,const char* artist, size_t length); //DON'T USE ASSERT, USE IF ELSE

    /**
     * @brief Construct a new Song object (Copy constructor)
     * 
     * @param other 
     */
    Song(const Song& other);

    /**
     * @brief Destroy the Song object
     * 
     */
    ~Song();

    /**
     * @brief Assign operator
     * 
     * @param other 
     * @return Song& 
     */
    Song& operator=(const Song& other);

    //Add getters and setters

};

class Playlist{
    char* name;
    char* owner;
    size_t songCount;
    
    size_t capacity;
    Song *songs;


    void resize(){}
    void shiftLeft(){}
public:

    /**
     * @brief Construct a new Playlist object
     * 
     * @param name 
     * @param owner 
     */
    Playlist(const char* name, const char* owner){
        if(!name || !owner) return;

        this->name = strdup(name);
        this->owner = strdup(owner);
        this->songCount = 0;
        this->capacity = 2;
        this->songs = new Song[this->capacity];
    }

    /**
     * @brief Construct a new Playlist object
     * 
     * @param other 
     */
    Playlist(const Playlist& other){
        this->name = strdup(other.name);
        this->owner = strdup(other.owner);
        this->songCount = other.songCount;
        this->capacity = other.capacity;
        this->songs = new Song[this->capacity];

        for(size_t i = 0; i < other.songCount; i++){
            this->songs[i] = other.songs[i];
        }
    }

    /**
     * @brief Assign operator
     * 
     * @param other 
     * @return Playlist& 
     */
    Playlist& operator=(const Playlist& other){
        if(this != &other){
            delete [] this->name;
            delete [] this->owner;
            this->name = strdup(other.name);
            this->owner = strdup(other.owner);

            this->songCount = other.songCount;
            this->capacity = other.capacity;

            delete [] this->songs;

            this->songs = new Song[this->capacity];

            for(size_t i = 0; i < other.songCount; i++){
                this->songs[i] = other.songs[i];
            }
        }
        return *this;
    }

    /**
     * @brief Adding song to the playlist. Check if song with this name and artist exists. If exists return -1
     * 
     * @param other 
     * @return int 
     */
    int addSong(const Song& other){}

    /**
     * @brief Remove song from the playlist. Check if song with this name and artist exists. If exists return -1
     * 
     */
    int removeSong(const char* name, const char* artist){}

    /**
     * @brief Moving a song from one playlist to another. Check if the song exists in the current playlist. If exists return -1
     * 
     * @param other 
     * @param name 
     * @param artist 
     * @return int 
     */
    int moveSong(Playlist& other, const char* name, const char* artist){}

    /**
     * @brief Get the Song object
     * 
     * @param name 
     * @param artist 
     * @return Song& 
     */
    Song& getSong(const char* name, const char* artist)const{}


    /*
        Getters
    */
    char* getName()const{ 
        return this->name;
    }
    char* getOwner()const{ 
        return this->owner;
    }
    size_t getSongsCount()const{
        return this->songCount;
    }
};

int main(int argc, char* argv[]){


    //TEST THE FUNCTIONALITIES
    
    return 0;
}