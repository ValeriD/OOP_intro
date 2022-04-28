#include<iostream>
#include<cstring>

using namespace std;

class Song{
    char* name;
    char* artist;
    size_t length;

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
    Song(const char* name, const char* artist, size_t length) //DON'T USE ASSERT, USE IF ELSE
    : length(length)
    {
        if(!artist || !name)
            return;
        else
        {
            this->name = strdup(name);
            this->artist = strdup(artist);
        }
    }

    /**
     * @brief Construct a new Song object (Copy constructor)
     * 
     * @param other 
     */
    Song(const Song& other)
    {
        this->name = strdup(other.name);
        this->artist = strdup(other.artist);
        this->length = other.length;
    }

    /**
     * @brief Destroy the Song object
     * 
     */
    ~Song()
    {
        delete[] this->name;
        delete[] this->artist;
    }

    /**
     * @brief Assign operator
     * 
     * @param other 
     * @return Song& 
     */
    Song& operator=(const Song& other)
    {
        if(this == &other)
        {
            return *this;
        }
        delete [] this->name;
        delete [] this->artist;
        this->name = strdup(other.name);
        this->artist = strdup(other.artist);
        this->length = other.length;
        return *this;
    }

    //Add getters and setters
    void setName(const char* name){
        this->name = strdup(name);
    }
    void setArtist(const char* artist){
        this->artist = strdup(artist);
    }
    void setLength(size_t length){
        this->length = length;
    }


    char* getName()const{
        return this->name;
    }
    char* getArtist()const{
        return this->artist;
    }
    size_t getLength()const{
        return this->length;
    }

};

class Playlist{
    char* name;
    char* owner;
    size_t songCount;
    
    size_t capacity;
    Song *songs;


    void resize(){
        this->capacity *= 2;
        Song *new_arr = new Song[this->capacity];
        for(int i = 0; i < this->songCount; i++)
            new_arr[i] = this->songs[i];

        delete [] this->songs;
        this->songs = new_arr;
    }

    void shiftLeft(size_t index)
    {
        if(index > this->songCount)
            return;
        for(int i = index; i < this->songCount - 1; i++)
            this->songs[i] = this->songs[i + 1];
        this->songCount--;
    }
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
    int addSong(const Song& other)
    {
        for(int i = 0; i < this->songCount; i++)
        {
            if (!strcmp(this->songs[i].getName(), other.getName()) && !strcmp(this->songs[i].getArtist(), other.getArtist()))
            {
                return -1;
            }
        }
        if(this->songCount == this->capacity)
        {
            this->resize();
        }
        this->songs[this->songCount] = other;
        this->songCount++;
        return 0;
    }

    /**
     * @brief Remove song from the playlist. Check if song with this name and artist exists. If exists return -1
     * 
     */
    int removeSong(const char* name, const char* artist)
    {
        for(int i = 0; i < this->songCount; i++)
        {
            if(this->songs[i].getName() == name && this->songs[i].getArtist() == artist)
            {
                this->shiftLeft(i);
                this->songCount--;
                return -1;
            }
        }
        return 0;
    }

    /**
     * @brief Moving a song from one playlist to another. Check if the song exists in the current playlist. If exists return -1
     * 
     * @param other 
     * @param name 
     * @param artist 
     * @return int 
     */
    int moveSong(Playlist& other, const char* name, const char* artist)
    {
        size_t length;
        for(int i = 0; i < other.songCount; i++)
        {
            if(!strcmp(this->songs[i].getName(), name) && !strcmp(this->songs[i].getArtist(), artist))
            {
                length = this->songs[i].getLength();
                return -1;
            }
        }
        Song* new_song = new Song(name, artist, length);
        other.removeSong(name, artist);
        this->addSong(*new_song);
        return 0;
    }

    /**
     * @brief Get the Song object
     * 
     * @param name 
     * @param artist 
     * @return Song& 
     */
    Song& getSong(const char* name, const char* artist)const
    {
        for(int i = 0; i < this->songCount; i++)
        {
            if(this->songs[i].getName() == name && this->songs[i].getArtist() == artist)
                return this->songs[i];
        }
    }


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
    Song s1("song1", "artist1", 20);
    Song s2("song2", "artist2", 30);

    Playlist p1("Playlist1", "owner1");
    p1.addSong(s1);
    p1.addSong(s2);
    cout<< p1.getSongsCount() <<endl;
    
    Song s3 = p1.getSong("song2", "artist2");

    cout << s3.getName() << endl << s3.getArtist() << endl << s3.getLength() << endl;
    
    return 0;
}