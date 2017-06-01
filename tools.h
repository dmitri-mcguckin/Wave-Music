#ifndef TOOLS_H
#define TOOLS_H

#include <istream>

using namespace std;

void menu();
void clear();
<<<<<<< HEAD
void printFile(char fileName[]);
void fixTime(int &, int &);
bool error(istream &buffer);
void handle(istream &buffer);
=======
void printFile(char [], char []);
void fixTime(int &, int &);
bool error(istream &);
void handle(istream &);
>>>>>>> 8a5a45c24575a95bd23c6906e357b7a4083de0ff
void pause();

#endif
