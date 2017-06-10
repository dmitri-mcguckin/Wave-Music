#ifndef SONGLIST_H
#define SONGLIST_H

#include "song.h"

const int CAP = 999;

struct Node
{
    Song data;
    Node * next;
    Node * prev;
};

class SongList
{
    private:
        Node * head;
        Node * tail;
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
        
        // Mutators
        void addSong();
        void insert(char [], char [], int, int, char[]);
        void searchLibrary();
        void writeLibrary(char *);
        void removeSong();
        void remove(int);
};

#endif
