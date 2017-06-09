#ifndef SONGLIST_H
#define SONGLIST_H

#include "song.h"

const int INCREASE = 1;
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
        SongList(char fileName[]);
        
        // Destructors
        ~SongList();
        
        // Accessors
        void getLibrary();
        void getLibrary(ostream & buffer);
        void getSize();
        
        // Mutators
        void addSong(char [], char [], int, int, char[]);
        void growList();
};

#endif
