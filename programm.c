#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "teil.c"
#include "utility.c"

int main()
{
    char teilPath[] = "teil.dat";
    char schrittPath[] = "schritt.dat";
    char geordnetPath[] = "geordnet.dat";

    teil *HEAD = NULL;
	HEAD = readTeils(HEAD, teilPath);
    readSchritts(HEAD, schrittPath);
    
    teil *HEAD_sorted = NULL;
    HEAD_sorted = sortingTeils(HEAD, HEAD_sorted);

	printTeils(HEAD_sorted, geordnetPath);
	freeSpace(HEAD);
	

    return 0;
}
