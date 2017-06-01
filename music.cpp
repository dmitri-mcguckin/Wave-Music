#include "music.h"

// ----------------------------------------------------------------------
// ----------------------------- Song Class -----------------------------
// ----------------------------------------------------------------------


// ---- Contructors
Song::Song()
{
	setLine("","",0,0,"");
}

Song::Song(char tTitle[], char tArtist[], int min, int sec, char tAlbum[])
{
	setLine(tTitle,tArtist,min,sec,tAlbum);
}

// ---- Destructor
Song::~Song()
{
	//TODO: Nothing!
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
	strcpy(title,temp);
}

void Song::setArtist(char temp[])
{
	strcpy(artist,temp);
}

void Song::setTime(int min, int sec)
{
	time.minutes = min;
	time.seconds = sec;
}

void Song::setAlbum(char temp[])
{
	strcpy(album,temp);
}

void Song::setLine(char temp1[], char temp2[], int min, int sec, char temp3[])
{
    setTitle(temp1);
    setArtist(temp2);
    setTime(min,sec);
    setAlbum(temp3);
}

// --------------------------------------------------------------------------
// ----------------------------- SongList Class -----------------------------
// --------------------------------------------------------------------------

// ---- Constructors
SongList::SongList()
{
	size = 0;
}

// ---- Deconstructor
SongList::~SongList()
{
	//TODO: Nothing!
}

// ---- Accessors
int SongList::getSize()
{
	return size;
}

void SongList::getLibrary()
{
    for(int i = 0; i < size; i++)
    {   
        cout << "[" << (i + 1) << "]: ";
        if(size > 9 && i < 9)
            cout << " ";
        list[i].getLine();
    }
}

void SongList::searchLibrary()
{
    int opt = NULL, res = 0;
    char search[CAP], tTitle[CAP], tArtist[CAP], tAlbum[CAP];
    
    if(size == 0)
    {
        cout << "Wave didn't find any songs to search for!" << endl;
        pause();
        return;
    }
    
    while(opt == NULL)
    {        
        cout << "Would you like to search by:" << endl;
        cout << "[1]: Song Name" << endl;
        cout << "[2]: Artist" << endl;
        cout << "[3]: Album" << endl;
        cout << "?: ";
        
        cin >> opt;
        
        if(error(cin))
        {
            handle(cin);
            pause();
            opt = NULL;
            continue;
        }
        else if(opt < 1 || opt > 3)
        {
            cout << "Please enter an option within the indicies." << endl;
            opt = NULL;
            pause();
            continue;
        }
        else
        {
            break;
        }
    }
    
    switch(opt)
    {
        case 1:
            cout << "Enter Song name: ";
            
            cin.ignore();
            cin.get(search,CAP,'\n');
            
            if(error(cin))
            {
                handle(cin);
                opt = NULL;
                break;
            }
            cout << endl << endl;
            for(int i = 0; i < size; i++)
            {
                list[i].getTitle(tTitle);
                if(strcasestr(tTitle,search) != NULL)
                {
                    list[i].getLine();
                    res++;
                }
            }
            
            cout << "A total of " << res << " song(s) were found." << endl;
            
            pause();
            break;       
        case 2:
            cout << "Enter Artist name: ";
            
            cin.ignore();
            cin.get(search,CAP,'\n');
            
            if(error(cin))
            {
                handle(cin);
                opt = NULL;
                break;
            }
            cout << endl << endl;
            for(int i = 0; i < size; i++)
            {
                list[i].getArtist(tArtist);
                if(strcasestr(tArtist,search) != NULL)
                {
                    list[i].getLine();
                    res++;
                }
            }
            
            cout << "A total of " << res << " song(s) were found." << endl;
            
            pause();
            break;
        case 3:
            cout << "Enter Album name: ";
            
            cin.ignore();
            cin.get(search,CAP,'\n');
            
            if(error(cin))
            {
                handle(cin);
                opt = NULL;
                break;
            }
            cout << endl << endl;
            for(int i = 0; i < size; i++)
            {
                list[i].getAlbum(tAlbum);
                if(strcasestr(tAlbum,search) != NULL)
                {
                    list[i].getLine();
                    res++;
                }
            }
            
            cout << "A total of " << res << " song(s) were found." << endl;
            
            pause();
            break;
         default:
           cout << "Invalid option!" << endl;
            pause();
            break;
    }
}

void SongList::readLibrary(ifstream &inFile, char fileName[], char path[])
{
    char tTitle[CAP];
    char tArtist[CAP];
    int min;
    int sec;
    char tAlbum[CAP];
    
    size = 0;
    
    clear();

    cout << "Please enter file name: ";
    cin.get(fileName,CAP,'\n');
        
    inFile.open(strcat(path,fileName));
   
    if(error(inFile))
    {
        handle(inFile);
        pause();
        cout << endl << "Wave will now forcefully exit!" << endl;
        exit(0);
    }
    
    while(!inFile.eof())
    {
        if(size == (CAP - 1))
        {
            cout << "The buffer has reached max capacity!" << endl << "No more lines will be read!" << endl;
            inFile.close();
            return;
        }
        
        if(size !=0)
            inFile.ignore(CAP,'\n');
        inFile.get(tTitle,CAP,';');
        inFile.ignore();
        inFile.get(tArtist,CAP,';');
        inFile.ignore();
        inFile >> min;
        inFile.ignore();
        inFile >> sec;
        inFile.ignore();        
        inFile.get(tAlbum,CAP,'\n');
        
        cout << endl;
        
        list[size++].setLine(tTitle,tArtist,min,sec,tAlbum);
    }
    
    if(size > 0)
        removeSong(size);
    
    inFile.close();
}

// ---- Mutators
bool SongList::addSong()
{
	char tTitle[CAP];
	char tArtist[CAP];
	int min;
	int sec;
	char tAlbum[CAP];
	char opt = NULL;	

	clear();

	if(size >= CAP - 1)
	{
		cout << "The library already has " << size << " songs!" << endl;
		cout << "\tIt cannot hold any more songs!" << endl;
		cout << "No more songs will be added!" << endl;
		return false;
	}
	
	cout << "Adding a new song!" << endl;
	cin.ignore(CAP,'\n');
    
    
	cout << "Title: ";

	cin.get(tTitle,CAP,'\n');

	cout << "Artist: ";
	cin.ignore();
	cin.get(tArtist,CAP,'\n');

	cout << "Time <Minutes:Hours>: ";
	cin >> min;
	cin.ignore();
	cin >> sec;

	cout << "Album: ";
	cin.ignore();
	cin.get(tAlbum,CAP,'\n');


	cout << endl << "You're adding:" << endl;
	cout << left << '\t' << setw(20) << tTitle << setw(20) << tArtist;
	fixTime(min,sec);
	cout << setw(20) << " " << tAlbum << endl;
	
	while(opt == NULL)
	{
		cout << endl << "Is this correct?" << endl;
		cout << "[Y/N]: ";
		cin >> opt;
		
		switch(toupper(opt))
		{
			case 'Y':
			      
			    list[size++].setLine(tTitle,tArtist,min,sec,tAlbum);
				
				cout << "Song added!" << endl;
				return true;
			case 'N':
				cout << "Canceling process!" << endl;
				return false;
			default:
				cout << "Invalid input!" << endl;
				cin.ignore(CAP,'\n');
                handle(cin);
				opt = NULL;
				continue;
		}
	}

}

bool SongList::removeSong()
{
    int index = NULL;
    char opt = NULL;
    
    if(size < 1)
    {
        cout << "Wave didn't find any songs to remove!" << endl;
        pause();
        return false;
    }
    
    while(index == NULL)
    {
        getLibrary();
        cout << endl << "Which song (by index number) would you like to remove?" << endl << "?: ";
        cin >> index;
        
        if(error(cin))
        {
            handle(cin);
            index = NULL;
            pause();
            continue;
        }
        else if(index < 1 || index > size)
        {
            cout << "Please enter a valid number!" <<  endl;
            index = NULL;
            pause();
            continue;
        }
    }
    
    index--;
    
    while(opt == NULL)
    {
        clear();
        cout << "You are going to remove:" << endl;
        list[index].getLine();
        cout << "Is this correct? [Y/N]" << endl << "?: ";
        
        cin >> opt;
        
        if(error(cin))
        {
            handle(cin);
            opt = NULL;
            pause();
            continue;
        }
        
        switch(toupper(opt))
        {
            case 'Y':
                for (index; index < size; index++)
                {
                    list[index] = list[index + 1];
                }
    
                size--;
                return true;
            case 'N':
                cout << endl << "Canceling action!" << endl;
                pause();
                return false;
            default:
                cout << "Invalid input!" << endl;
                opt = NULL;
                pause();
                continue;
        }
    }
}

bool SongList::removeSong(int index)
{
    if(size < 1)
    {
        cout << "Wave didn't find any songs to remove!" << endl;
        pause();
        return false;
    }
    
    for(int i = index; i < size; i++)
        list[i] = list[i + 1];
    
    size--;
    return true;
}

void SongList::writeLibrary(ofstream &outFile,char fileName[], char path[])
{
    char opt = NULL;
    char temp[CAP];
    
    while(opt == NULL)
    {
        cout << "Wave wants to overwrite " << fileName << "!" << '\n';
        cout << "Is this ok? [Y/N]" << endl << "?: ";
        
        cin >> opt;
        
        if(error(cin))
        {
            handle(cin);
            opt = NULL;
            continue;
        }
        
        switch(toupper(opt))
        {
            case 'Y':
                cout << "Wave will now save the songs!" << endl;
                outFile.open(strcat(path,fileName));
                                                
                for(int i = 0; i < size; i++)
                {
                    list[i].writeLine(outFile);                  
                }
            
                outFile.close();
                break;
            case 'N':
                cout << endl << "Wave will not overwrite file!" << endl;
                break;
            default:
                cout << "Invalid input!" << endl;
                pause();
                opt = NULL;
                continue;
        }
    }
    
    cout << "Goodbye!" << endl;
    pause();
    clear();
    exit(0);
}
