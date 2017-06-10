#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <string.h>

using namespace std;

#include "tools.h"

struct Time
{
    //int hour; // Maybe
    int min;
    int sec;
};

class Song
{
    private:
        char * title;
        char * artist;
        Time time;
        char * album;
    public:
        // Constructors
        Song();
        Song(char tTitle[], char tArtist[], int tMin, int tSec, char tAlbum[]);
        
        // Destructors
        ~Song();
        
        // Accessors
        void getTitle(char []);
        void getTitle();
        void getTitle(ostream &);
        void getArtist(char []);
        void getArtist();
        void getArtist(ostream &);
        void getTimeFormatted();
        void getAlbum(char []);
        void getAlbum();
        void getAlbum(ostream &);
        
        // Mutators
        friend ostream &operator << (ostream &, Song &);
        const Song & operator = (const Song &);
};

#endif