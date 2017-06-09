#ifndef TOOLS_H
#define TOOLS_H

#include "song.h"

void menu();
void clear();
void printFile(char *fileName);
void fixTime(int &, int &);
bool error(istream &buffer);
void handle(istream &buffer);
void pause();

#endif
