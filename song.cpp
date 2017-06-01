#include "song.h"

// ---- Contructors
Song::Song()
{
	setLine(NULL,NULL,0,0,NULL);
}

Song::Song(char tTitle[], char tArtist[], int min, int sec, char tAlbum[])
{
	setLine(tTitle,tArtist,min,sec,tAlbum);
}

// ---- Destructor
Song::~Song()
{
	//TODO: Nothing!
	if(title)
        delete [] title;
	if(artist)
        delete [] artist;
	if(album)
        delete [] album;
}

// ---- Accessors
void Song::getTitle(char tTitle[])
{
    strcpy(tTitle,title);
}

void Song::getArtist(char tArtist[])
{
    strcpy(tArtist,artist);
}

void Song::getAlbum(char tAlbum[])
{
    strcpy(tAlbum,album);
}

int Song::getMin()
{
    return time.minutes;
}

int Song::getSec()
{
    return time.seconds;
}

void Song::getLine()
{
    cout << left << setw(30) << title;
    cout << left << setw(30) << artist;
    int min = getMin();
    int sec = getSec();
    fixTime(min,sec);
    setTime(min,sec);
    cout << left << setw(30) << " " << album;
    cout << endl;
}

void Song::writeLine(ofstream &buffer)
{
    buffer << title << ";" << artist << ";" << time.minutes << ";" << time.seconds << ";" << album << endl;
}

// ---- Mutators
void Song::setTitle(char temp[])
{
	if(title)
    {
		delete [] title;
        title = NULL;
    }
	char *title = new char [strlen(temp) + 1];
	strcpy(title,temp);
}

void Song::setArtist(char temp[])
{
	if(artist)
    {
		delete [] artist;
        artist = NULL;
    }
	char *artist = new char [strlen(temp) + 1];
	strcpy(artist,temp);
}

void Song::setTime(int min, int sec)
{
	time.minutes = min;
	time.seconds = sec;
}

void Song::setAlbum(char temp[])
{
	if(album)
    {
		delete [] album;
        album = NULL;
    }
	char *album = new char [strlen(temp) + 1];
	strcpy(album,temp);
}

void Song::setLine(char temp1[], char temp2[], int min, int sec, char temp3[])
{
    setTitle(temp1);
    setArtist(temp2);
    setTime(min,sec);
    setAlbum(temp3);
}

/*const Song &Song::operator = (const Song &list)
{
    if(this == &list)
    {
        return *this;
    }
    else
    {
        setLine(list.title,list.);
    }
}*/