#include "songList.h"

int main()
{
    char opt = NULL;
    char *version = "4.2.0";
    char *fileName = "lib/wave.dll";
    
    clear();
    cout << "Welcome to Wave " << version << "!" << endl << "Please wait while we load some things!" << endl;
     
    SongList library(fileName);
    system("sleep 0.8");  
    
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
                library.searchLibrary();    
                break;
            case 'C':
                
                break;
            case 'Q':
                clear();
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
