#include "songList.h"

// ----------------------------------------------------------------
// |                        Constructors                          |
// ----------------------------------------------------------------
SongList::SongList()
{    
    head = NULL;
    tail = NULL;
    size = 0;
    head->data = Song();
}

SongList::SongList(char *fileName)
{    
    head = NULL;
    tail = NULL;
    size = 0;
    
    ifstream inFile;
        
    char tName[CAP];
    char dir[CAP] = "lib/";
    char tTitle[CAP];
    char tArtist[CAP];
    int tMin;
    int tSec;
    char tAlbum[CAP];
    
    cout << "Please enter file name: ";
    cin.get(tName,CAP,'\n');
    
    strncat(dir,tName,CAP);
    
    if(fileName)
        delete [] fileName;
    fileName = new char[strlen(dir)];
    strcpy(fileName,dir);
    
    inFile.open(fileName);
   
    if(error(inFile))
    {
	clear();
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
        
        insert(tTitle,tArtist,tMin,tSec,tAlbum);
    }
    
    inFile.close();
}


// ----------------------------------------------------------------
// |                         Destructors                          |
// ----------------------------------------------------------------    
SongList::~SongList()
{

}

// ----------------------------------------------------------------
// |                         Accessors                            |
// ----------------------------------------------------------------
void SongList::getLibrary()
{   
    Node * curr = head;
    
    if(size != 0)
    {
        cout << "[N] ";
        
        if(size > 9)
            cout << " ";
        
        cout << left << setw(25);
        cout << "Title";
        cout << " ";
        cout << right << setw(25);
        cout << "Artist";
        cout << " ";
        cout << left << setw(7);
        cout << "  Time";
        cout << " ";
        cout << left << setw(20);
        cout << " Album";
        cout << endl;
        
        for(int i = 0; i < 80; i++)
        {
            cout << "-";
        }
        cout << endl;
        
        for (int i = 0; i < size; i++)
        {
            cout << "[" << (i + 1) << "] ";
                        
            if(size > 9)
            {
                if(i < 9)
                {
                    cout << " ";
                }
            }
            
            cout << left << setw(25);
            curr->data.getTitle();
            cout << " ";
            cout << internal << setw(25);
            curr->data.getArtist();
            cout << " ";
            curr->data.getTimeFormatted();
            cout << " ";
            cout << internal << setw(20);
            curr->data.getAlbum();
            cout << endl;
            
            curr = curr->next;
        }
    }
    else
    {
        cout << "Wave couldn't find any songs to list! :(" << endl;
    }
}

void SongList::getLibrary(ostream & buffer)
{
    char t[CAP];
    Node *curr = head;
    
    if(size != 0)
    {
        for (int i = 0; i < size; i++)
        {
            curr->data.getTitle(t);
            
            if(t)
                buffer << curr->data;
            if(!(i == (size - 1)))
                buffer << endl;
            curr = curr->next;
        }
    }
}

void SongList::getSong(int i)
{
    Node *curr = head;
    
    for(int j = 0; j < i; j++)
    {
        curr = curr->next;
    }
    
    cout << left << setw(25);
    curr->data.getTitle();
    cout << " ";
    cout << right << setw(25);
    curr->data.getArtist();
    cout << " ";
    curr->data.getTimeFormatted();
    cout << " ";
    cout << left << setw(20);
    curr->data.getAlbum();
    cout << endl;
}

// ----------------------------------------------------------------
// |                          Mutators                            |
// ----------------------------------------------------------------

void SongList::addSong()
{
	char tTitle[CAP];
	char tArtist[CAP];
	int tMin;
	int tSec;
	char tAlbum[CAP];
	char opt = NULL;	

	clear();
	
	cout << "Adding a new song!" << endl;
	cin.ignore(CAP,'\n');
    
    
	cout << "Title: ";

	cin.get(tTitle,CAP,'\n');

	cout << "Artist: ";
	cin.ignore();
	cin.get(tArtist,CAP,'\n');

	cout << "Time <Minutes:Seconds>: ";
	cin >> tMin;
	cin.ignore();
	cin >> tSec;

	cout << "Album: ";
	cin.ignore();
	cin.get(tAlbum,CAP,'\n');


	cout << endl << "You're adding:" << endl;
	cout << left << '\t' << setw(20) << tTitle << setw(20) << tArtist;
	fixTime(tMin,tSec);
	cout << setw(20) << " " << tAlbum << endl;
	
	while(opt == NULL)
	{
		cout << endl << "Is this correct?" << endl;
		cout << "[Y/N]: ";
		cin >> opt;
		
		switch(toupper(opt))
		{
			case 'Y': 
			    insert(tTitle,tArtist,tMin,tSec,tAlbum);
				
				cout << "Song added!" << endl;
				return;
			case 'N':
				cout << "Canceling process!" << endl;
				return;
			default:
				cout << "Invalid input!" << endl;
				cin.ignore(CAP,'\n');
                handle(cin);
				opt = NULL;
				continue;
		}
	}

}

void SongList::insert(char tTitle[], char tArtist[], int tMin, int tSec, char tAlbum[])
{    
    Node * temp = new Node;
    Node * curr = head;
    
    temp->data = Song(tTitle,tArtist,tMin,tSec,tAlbum);
    temp->next = NULL;
    temp->prev = NULL;
    
    
	while(curr)
	{
		if(curr->next)
			curr = curr->next;
		else
			break;
	}
    
    if(!head)
    {
        head = temp;
        tail = head;
        size++;
    }
    else if(curr == tail)
    {
        curr->next = temp;
        temp->prev = curr;
        tail = temp;
        size++;
    }
    else
    {
        temp->next = curr->next;
        curr->next = temp;
        temp->next->prev = temp;
        temp->prev = curr;
        size++;
    }
}

void SongList::searchLibrary()
{
/*    int opt = NULL, res = 0;
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
            
            
            cout << endl;
            for(int i = 0; i < size; i++)
            {
                list[i].getTitle(tTitle);
                if(strcasestr(tTitle,search))
                {
                    getSong(i);
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
            
            
            cout << endl;
            for(int i = 0; i < size; i++)
            {
                list[i].getArtist(tArtist);
                if(strcasestr(tArtist,search))
                {
                    getSong(i);
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
            
            
            cout << endl;
            for(int i = 0; i < size; i++)
            {
                list[i].getAlbum(tAlbum);
                if(strcasestr(tAlbum,search))
                {
                    getSong(i);
                    res++;
                }
            }
            
            cout << endl << "A total of " << res << " song(s) were found." << endl;
            
            pause();
            break;
         default:
           cout << "Invalid option!" << endl;
            pause();
            break;
    }*/
}

void SongList::writeLibrary(char *fileName)
{
    /*char opt = NULL;
    char temp[CAP];
    ofstream outFile;
    
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
                outFile.open(fileName);
                                                
                getLibrary(outFile);
            
                outFile.close();
                delete [] fileName;
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
    exit(0);*/
}

void SongList::removeSong()
{
    int opt = NULL;
    char rep = NULL;
    
    while(!opt)
    {
        getLibrary();
        
        cout << endl << "Which song would you like to remove? (enter -1 to exit)" << endl << "?:";
        cin >> opt;
        
        if(opt == -1)
        {
            cout << "Wave will not remove anything!" << endl;
            pause();
            return;
        }
        
        if(!(opt > 0 && opt <= size))
        {
            cout << "Please enter an option within the indicies." << endl;
            handle(cin);
            clear();
            opt = NULL;
            continue;
        }
        
        if(error(cin))
        {
            cout << endl << "Invalid input!" << endl;
            handle(cin);
            clear();
            opt = NULL;
            continue;
        }
        
        opt--;
        
        while(!rep)
        {
            cout << "You are about to remove:" << endl << "      ";
            getSong(opt);
            cout << "Is this correct? [Y/N]:" << endl << "?:";
            cin >> rep;
            
            switch(toupper(rep))
            {
                case 'Y':
                    cout << opt << endl;
                    remove(opt);
                    
                    cout << endl << "Song was removed!" << endl;
                    pause();
                    return;
                case 'N':
                    cout << endl << "Song removal was canceled!" << endl;
                    pause();
                    return;
                default:
                    cout << "Invalid input!" << endl;
                    pause();
                    clear();
                    rep = NULL;
            }
        }   
    }
}

void SongList::remove(int i)
{
    Node *curr = head;
    
    for(int j = 0; j < i; j++)
    {
        curr = curr->next;
    }
    
    if(curr == head)
    {
        head = curr->next;
        if(head)
            head->prev = NULL;
        curr->next = NULL;
        delete curr;
        curr = NULL;
        if(!head)
            tail = NULL;
    }
    else if (curr == tail)
    {
        tail = curr->prev;
        if(tail)
            tail->next = NULL;
        curr->prev = NULL;
        delete curr;
        curr = NULL;
        if(!tail)
            head = NULL;
    }
    else
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
        curr = NULL;
    }
    
    size--;
}