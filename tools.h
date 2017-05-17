#ifndef TOOLS_H
#define TOOLS_H

#include <istream>

using namespace std;

void menu();
void clear();
void printFile(char [], char []);
void fixTime(int &, int &);
bool error(istream &);
void handle(istream &);
void pause();

#endif
