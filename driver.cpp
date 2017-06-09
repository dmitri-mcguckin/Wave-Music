#include "songList.h"

int main()
{
    char opt = NULL;
    char *version = "4.2.0";
    char *fileName = "lib/wave_backup.dll";
    
    clear();
    cout << "Welcome to Wave " << version << "!" << endl << "Please wait while we load some things!" << endl;
     
    SongList library(fileName);
    system("sleep 2");  
  
    while(true)
    {
	opt = NULL;
        //clear();
        printFile(fileName);
        menu();
        cin >> opt;

	switch(toupper(opt))
	{
		case 'A':
			library.addSong("Dummy Track","Dummy Artist",9,99,"Dummy Album");
			break;
		case 'L':
			cout << "Listing:" << endl;
			library.getLibrary();
			break;
		case 'E':
			cout << "This feature is not yet available!" << endl;
			break;
                case 'R':
			cout << "Remove:" << endl;
			break;
                case 'S':
			cout << "Search:" << endl;
			break;
                case 'C':
			cout << "Change Lib:" << endl;
			break;
                case 'Q':
			cout << "Good Bye!" << endl;
			pause();
			clear();
			exit(0);
			break;
		default:
			if(error(cin))
				handle(cin);
			break;
	}
    }
    
    return 0;
}
