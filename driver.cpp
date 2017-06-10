#include "songList.h"

int main()
{
    char opt = NULL;
    char *version = "4.5.5";
    char *fileName = new char[2];
    
    clear();
    cout << "Welcome to Wave " << version << "!" << endl << "Please wait while we load some things!" << endl;
     
    SongList library(fileName);
    
    while(true)
    {
        opt = NULL;
        clear();
        printFile(fileName);
        menu();
        cin >> opt;

        switch(toupper(opt))
        {
            case 'A':
                printFile(fileName);
                library.addSong();
                break;
            case 'L':
                clear();
                printFile(fileName);
                library.getLibrary();
                pause();
                break;
            case 'E':
                clear();
                printFile(fileName);
                cout << "This feature is not yet available!" << endl;
                pause();
                break;
            case 'R':
                clear();
                printFile(fileName);
                library.removeSong();
                break;
            case 'S':
                clear();
                printFile(fileName);
                library.searchLibrary();    
                break;
            case 'C':
                clear();
                printFile(fileName);
                cout << "This feature is not yet available!" << endl;
                pause();
                break;
                /*clear();
                printFile(fileName);
                library = SongList(fileName);
                break;*/
            case 'Q':
                clear();
                printFile(fileName);
                library.writeLibrary(fileName);
                break;
            default:
                cout << "Invalid input!" << endl;
                handle(cin);
                opt = NULL;   
                break;
        }
    }
    
    return 0;
}
