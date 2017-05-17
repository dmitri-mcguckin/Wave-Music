#include "music.h"

int main()
{
	clear();	
	SongList lib;
	ifstream inFile;
	ofstream outFile;
	char fileName[CAP];
    	char option = NULL;
	char path[CAP] = "./lib/";    
	char version[CAP] = "4.0.1";
	lib.readLibrary(inFile,fileName,path);
    
    while(true)
    {
        clear();
        printFile(fileName,version);
	cout << "Size of Library: " << lib.getSize() << " Songs." << endl;
        menu();
        
        cin >> option;
        
        if(error(cin))
        {
            handle(cin);
            continue;
        }
        
        switch(toupper(option))
        {
        case 'A':
                clear();
                printFile(fileName,version);
                lib.addSong();
                break;
        case 'L':
                clear();
                printFile(fileName,version);
                lib.getLibrary();
                pause();
                break;
        case 'E':
                clear();
                printFile(fileName,version);
                cout << "Feature is not yet available!" << endl;
                pause();
                break;
        case 'R':
                clear();
                printFile(fileName,version);
                lib.removeSong();
                break;
        case 'S':
                clear();
                printFile(fileName,version);
                lib.searchLibrary();
                break;
        case 'C':
                clear();
                printFile(fileName,version);
                cin.ignore();
                lib.readLibrary(inFile,fileName,path);
                break;
	case 'Q':
        	clear();
                printFile(fileName,version);
                lib.writeLibrary(outFile,fileName,path);
                break;
            default:
                cout << "Invalid input!" << endl;
                pause();
                break;
        }
    }

	return 0;
}
