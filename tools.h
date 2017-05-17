#ifndef TOOLS_H
#define TOOLS_H

#include <istream>

using namespace std;

void menu();
void clear();
void printFile(char fileName[]);
void fixTime(int &, int &);
bool error(istream &buffer);
void handle(istream &buffer);
void pause();

#endif
