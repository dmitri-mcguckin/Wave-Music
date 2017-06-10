#include "song.h"

// ----------------------------------------------------------------
// |                        Constructors                          |
// ----------------------------------------------------------------
Song::Song()
{
    char tTitle[] = "No Title", tArtist[] = "No Artist", tAlbum[] = "No Album";
    
    title = new char[strlen(tTitle)];
    strcpy(title,tTitle);
    
    artist = new char[strlen(tArtist)];
    strcpy(artist,tArtist);
    
    time.min = 0;
    time.sec = 0;
    
    album = new char[strlen(tAlbum)];
    strcpy(album,tAlbum);
}

Song::Song(char tTitle[], char tArtist[], int tMin, int tSec, char tAlbum[])
{
    title = new char[strlen(tTitle)];
    strcpy(title,tTitle);
    
    artist = new char[strlen(tArtist)];
    strcpy(artist,tArtist);
    
    time.min = tMin;
    time.sec = tSec;
    
    album = new char[strlen(tAlbum)];
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
        delete [] title;
        title = new char[strlen(song.title)];
        strcpy(this->title,song.title);
        
        delete [] artist;
        artist = new char[strlen(song.artist)];
        strcpy(this->artist,song.artist);
        
        this->time.min = song.time.min;
        this->time.sec = song.time.sec;
        
        delete [] album;
        album = new char[strlen(song.album)];
        strcpy(this->album,song.album);
        
        return *this;
    }
}
