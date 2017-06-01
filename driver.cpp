#include "songList.h"

int main()
{
	clear();	
	SongList lib;
	ifstream inFile;
	ofstream outFile;
	char fileName[CAP];
    char option = NULL;
    
	lib.readLibrary(inFile,fileName);
    
    while(true)
    {
        clear();
        printFile(fileName);
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
                printFile(fileName);
                lib.addSong();
                break;
        case 'L':
                clear();
                printFile(fileName);
                lib.getLibrary();
                pause();
                break;
        case 'E':
                clear();
                printFile(fileName);
                cout << "Feature is not yet available!" << endl;
                pause();
                break;
        case 'R':
                clear();
                printFile(fileName);
                lib.removeSong();
                break;
        case 'S':
                clear();
                printFile(fileName);
                lib.searchLibrary();
                break;
        case 'C':
                clear();
                printFile(fileName);
                cin.ignore();
                lib.readLibrary(inFile,fileName);
                break;
	case 'Q':
        	clear();
                printFile(fileName);
                lib.writeLibrary(outFile,fileName);
                break;
            default:
                cout << "Invalid input!" << endl;
                pause();
                break;
        }
    }

	return 0;
}
