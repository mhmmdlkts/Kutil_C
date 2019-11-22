#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "teil.c"

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
	

    return 0;
}
