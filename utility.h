#ifndef UTILITY_H
#define UTILITY_H
#include "teil.h"

void freeSpace(teil *HEAD);
void existFile(FILE *file);
int getMax(int a, int b);
int countOfMultiChar (char arr[], char umlaut[]);
int countOfAllGermanUmlauts (char arr[]);
void addBlanks(char arr[], int lastLen);

#endif
