#ifndef SONG_H
#define SONG_H

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
		char *title;
		char *artist;
		Time time;
		char *album;
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
        
        // Operators
        //const Song &operator = (const Song &list);
};

#endif