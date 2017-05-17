#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <string.h>
#include "tools.h"

using namespace std;

const int CAP = 999;

struct Time
{
	int minutes;
	int seconds;
};

class Song
{
	private:
		char title[CAP];
		char artist[CAP];
		Time time;
		char album[CAP];
	public:
		// Constructors
		Song();
		Song(char [], char [], int, int, char []);
	
		// Destructor
		~Song(); 
	
		// Accessors
        void getTitle(char []);
        void getArtist(char []);
        void getAlbum(char []);
        int getMin();
        int getSec();
        void getLine();
        void writeLine(ofstream &buffer);
		
		// Mutators	
        void setTitle(char []);
        void setArtist(char []);
        void setTime(int, int);
        void setAlbum(char []);
        void setLine(char [], char [],int, int, char[]);
};

class SongList
{
	private:
		int size;
		Song list[CAP];
	public:
		// Constructors	
		SongList();	

		// Destructor
		~SongList();

		// Accessors	
		int getSize();
		void getLibrary();
        void searchLibrary();
        void readLibrary(ifstream &, char [], char []);
        
        
        // Mutators
		bool addSong();
        bool removeSong();
        bool removeSong(int);
        void writeLibrary(ofstream &, char [], char []);        
};

#endif
