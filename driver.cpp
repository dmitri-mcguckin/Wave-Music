<<<<<<< HEAD
#include "songList.h"
=======
#include "music.h"
>>>>>>> 8a5a45c24575a95bd23c6906e357b7a4083de0ff

int main()
{
	clear();	
	SongList lib;
	ifstream inFile;
	ofstream outFile;
	char fileName[CAP];
<<<<<<< HEAD
    char option = NULL;
    
	lib.readLibrary(inFile,fileName);
=======
    	char option = NULL;
	char path[CAP] = "./lib/";    
	char version[CAP] = "4.0.1";
	lib.readLibrary(inFile,fileName,path);
>>>>>>> 8a5a45c24575a95bd23c6906e357b7a4083de0ff
    
    while(true)
    {
        clear();
<<<<<<< HEAD
        printFile(fileName);
        cout << "Size of Library: " << lib.getSize() << " Songs." << endl;
=======
        printFile(fileName,version);
	cout << "Size of Library: " << lib.getSize() << " Songs." << endl;
>>>>>>> 8a5a45c24575a95bd23c6906e357b7a4083de0ff
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
<<<<<<< HEAD
                printFile(fileName);
=======
                printFile(fileName,version);
>>>>>>> 8a5a45c24575a95bd23c6906e357b7a4083de0ff
                lib.addSong();
                break;
        case 'L':
                clear();
<<<<<<< HEAD
                printFile(fileName);
=======
                printFile(fileName,version);
>>>>>>> 8a5a45c24575a95bd23c6906e357b7a4083de0ff
                lib.getLibrary();
                pause();
                break;
        case 'E':
                clear();
<<<<<<< HEAD
                printFile(fileName);
=======
                printFile(fileName,version);
>>>>>>> 8a5a45c24575a95bd23c6906e357b7a4083de0ff
                cout << "Feature is not yet available!" << endl;
                pause();
                break;
        case 'R':
                clear();
<<<<<<< HEAD
                printFile(fileName);
=======
                printFile(fileName,version);
>>>>>>> 8a5a45c24575a95bd23c6906e357b7a4083de0ff
                lib.removeSong();
                break;
        case 'S':
                clear();
<<<<<<< HEAD
                printFile(fileName);
=======
                printFile(fileName,version);
>>>>>>> 8a5a45c24575a95bd23c6906e357b7a4083de0ff
                lib.searchLibrary();
                break;
        case 'C':
                clear();
<<<<<<< HEAD
                printFile(fileName);
                cin.ignore();
                lib.readLibrary(inFile,fileName);
                break;
	case 'Q':
        	clear();
                printFile(fileName);
                lib.writeLibrary(outFile,fileName);
=======
                printFile(fileName,version);
                cin.ignore();
                lib.readLibrary(inFile,fileName,path);
                break;
	case 'Q':
        	clear();
                printFile(fileName,version);
                lib.writeLibrary(outFile,fileName,path);
>>>>>>> 8a5a45c24575a95bd23c6906e357b7a4083de0ff
                break;
            default:
                cout << "Invalid input!" << endl;
                pause();
                break;
        }
    }

	return 0;
}
