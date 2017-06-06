#include "songList.h"

// ----------------------------------------------------------------
// |                        Constructors                          |
// ----------------------------------------------------------------
SongList::SongList()
{
    capacity = INCREASE;
    
    list = new Song[capacity];
    size = 0;
}

SongList::SongList(char fileName[])
{
    capacity = INCREASE;
    
    list = new Song[capacity];
    size = 0;
    
    ifstream inFile;
    
    char tTitle[CAP];
    char tArtist[CAP];
    int tMin;
    int tSec;
    char tAlbum[CAP];
    
    clear();
    printFile(fileName);
    
    inFile.open(fileName);
   
    if(error(inFile))
    {
        handle(inFile);
        pause();
        cout << endl << "Wave will now forcefully exit!" << endl;
        exit(0);
    }
    
    while(!inFile.eof())
    {
        if(size !=0)
        	inFile.ignore(CAP,'\n');
        inFile.get(tTitle,CAP,';');
        inFile.ignore();
        inFile.get(tArtist,CAP,';');
        inFile.ignore();
        inFile >> tMin;
        inFile.ignore();
        inFile >> tSec;
        inFile.ignore();        
        inFile.get(tAlbum,CAP,'\n');
        
        cout << "Info was retrieved!" << endl;
        addSong(tTitle,tArtist,tMin,tSec,tAlbum);
    }
    
    //if(size > 0)
        //removeSong(size);
    
    inFile.close();
}


// ----------------------------------------------------------------
// |                         Destructors                          |
// ----------------------------------------------------------------    
SongList::~SongList()
{
    if(list)
    {
        delete [] list;
        list = NULL;
    }
}

// ----------------------------------------------------------------
// |                         Accessors                            |
// ----------------------------------------------------------------
void SongList::getLibrary()
{
    if(size != 0)
    {
        for (int i = 0; i < size; i++)
        {
            cout << list[i];
        }
    }
    else
    {
        cout << "Wave couldn't find any songs to list! :(" << endl;
    }
}

void SongList::getLibrary(ostream & buffer)
{
    if(size != 0)
    {
        for (int i = 0; i < size; i++)
        {
            buffer << "[" << i << "]" << list[i];
        }
    }
    else
    {
        cout << "Wave couldn't find any songs to list! :(" << endl;
    }
}

void SongList::getSize()
{
    cout << size;
}

// ----------------------------------------------------------------
// |                          Mutators                            |
// ----------------------------------------------------------------
void SongList::addSong(char tTitle[], char tArtist[], int tMin, int tSec, char tAlbum[])
{
    if(size == capacity)
        growList();
    
    list[size] = Song(tTitle,tArtist,tMin,tSec,tAlbum);
    
    size++;
}

void SongList::growList()
{
    capacity += INCREASE;
    
    Song *temp = new Song[capacity];
    
    for(int i = 0; i < size; i++)
    {
        temp[i] = list[i];
    }
    
    delete [] list;
    
    list = temp;
    
    temp = NULL;
}
