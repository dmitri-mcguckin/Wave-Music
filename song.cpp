#include "song.h"

// ----------------------------------------------------------------
// |                        Constructors                          |
// ----------------------------------------------------------------
Song::Song()
{
    title = new char[9];
    strcpy(title,"No Title");
    artist = new char[10];
    strcpy(artist,"No Artist");
    time.min = 0;
    time.sec = 0;
    album = new char[9];
    strcpy(album,"No Album");
}

Song::Song(char tTitle[], char tArtist[], int tMin, int tSec, char tAlbum[])
{
    title = new char[strlen(tTitle) + 1];
    strcpy(title,tTitle);
    
    artist = new char[strlen(tArtist) + 1];
    strcpy(artist,tArtist);
    
    time.min = tMin;
    time.sec = tSec;
    
    album = new char[strlen(tAlbum) + 1];
    strcpy(album,tAlbum);
}

// ----------------------------------------------------------------
// |                         Destructors                          |
// ----------------------------------------------------------------    
Song::~Song()
{
    delete [] title;
    title = NULL;
    delete [] artist;
    artist = NULL;
    delete [] album;
    album = NULL;
}

// ----------------------------------------------------------------
// |                         Accessors                            |
// ----------------------------------------------------------------

void Song::getTitle(char temp[])
{ 
    strcpy(temp, title);
}

void Song::getTitle()
{
    cout << title;
}

void Song::getTitle(ostream & buffer)
{
    buffer << title;
}

void Song::getArtist(char temp[])
{
    strcpy(temp, artist);
}

void Song::getArtist()
{
    cout << artist;
}

void Song::getArtist(ostream & buffer)
{
    buffer << artist;
}

void Song::getTimeFormatted()
{
    fixTime(time.min,time.sec);
}

void Song::getAlbum(char temp[])
{
    strcpy(temp, album);
}

void Song::getAlbum()
{
    cout << album;
}

void Song::getAlbum(ostream & buffer)
{
    buffer << album;
}

// ----------------------------------------------------------------
// |                          Mutators                            |
// ----------------------------------------------------------------


// ----------------------------------------------------------------
// |                          Operators                           |
// ----------------------------------------------------------------
ostream & operator << (ostream & buffer, Song & song)
{
    buffer << song.title << ";" << song.artist << ";" << song.time.min << ";" << song.time.sec << ";" << song.album;
    
    return buffer;
}

const Song & Song::operator = (const Song & song)
{
    if(this == &song)
    {
        return *this;
    }
    else
    {
        strcpy(this->title,song.title);
        strcpy(this->artist,song.artist);
        this->time.min = song.time.min;
        this->time.sec = song.time.sec;
        strcpy(this->album,song.album);
        
        return *this;
    }
}
