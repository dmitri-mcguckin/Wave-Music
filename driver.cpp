#include "songList.h"

int main()
{
    char *opt = NULL;
    char *version = "4.0.1";
    char *fileName = "lib/wave.dll";
    
    clear();
    cout << "Welcome to Wave " << version << "!" << endl << "Please wait while we load some things!" << endl;
    system("sleep 2");
    
    SongList library(fileName);
    
    while(opt == NULL)
    {
        clear();
        printFile(fileName);
        menu();
        cin >> opt;
    }
    
    return 0;
}