#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "teil.h"

int main()
{
    char teilPath[] = "teil.dat";
    char schrittPath[] = "schritt.dat";
    char geordnetPath[] = "geordnet.dat"; //TODO scan paths

    /*char *teilPath = argv[1];
    char *teilPath = argv[2];*/

    teil *HEAD = NULL;
	  HEAD = readTeils(HEAD, teilPath);
    readSchritts(HEAD, schrittPath);

    teil *HEAD_sorted = NULL;
    HEAD_sorted = sortingTeils(HEAD, HEAD_sorted);

	  printTeils(HEAD_sorted, geordnetPath);


    return 0;
}
