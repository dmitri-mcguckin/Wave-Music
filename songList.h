#ifndef SONGLIST_H
#define SONGLIST_H

#include "song.h"

const int INCREASE = 50;
const int CAP = 999;

class SongList
{
    private:
        Song *list;
        int size;
        int capacity;
        int increase;
    public:
        // Constructors
        SongList();
        SongList(char *);
        
        // Destructors
        ~SongList();
        
        // Accessors
        void getLibrary();
        void getLibrary(ostream & buffer);
        void getSong(int);
        void getSize();
        
        // Mutators
        void addSong();
        void addSong(char [], char [], int, int, char[]);
        void searchLibrary();
        void writeLibrary(char *);
        void removeSong();
        void removeSong(int);
};

#endif
