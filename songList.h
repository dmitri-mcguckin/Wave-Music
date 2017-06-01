#ifndef SONG_LIST_H
#define SONG_LIST_H

#include "song.h"

class SongList
{
	private:
		int size;
		Song *list;
	public:
		// Constructors	
		SongList();	

		// Destructor
		~SongList();

		// Accessors	
		int getSize();
		void getLibrary();
        void searchLibrary();
	    void readLibrary(ifstream &, char []);
        
        
        // Mutators
		bool addSong();
        bool removeSong();
	    bool removeSong(int);
	    void writeLibrary(ofstream &,char []);        
};

#endif