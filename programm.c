#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "teil.h"

#include "teil.c"//TODO DELETE
#include "utility.c"

int main()
{
    char teilPath[] = "teil.dat";
    char schrittPath[] = "schritt.dat";
    char geordnetPath[] = "geordnet.dat"; //TODO scan paths

    /*char *teilPath = argv[1];
    char *teilPath = argv[2];*/

    teil *HEAD = NULL;
    teil *HEAD_sorted = NULL;
    
	readTeils(&HEAD, teilPath);
    readSchritts(HEAD, schrittPath);
    sortingTeils(HEAD, &HEAD_sorted);

	printTeils(HEAD_sorted, geordnetPath);


    return 0;
}
