#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "teil.h"
#include "utility.h"

int main(int argc, char *argv[])
{
    char *geordnetPath = "geordnet.dat";
    char *teilPath = argv[1];
    char *schrittPath = argv[2];

    teil *HEAD = NULL;
    teil *HEAD_sorted = NULL;

    int a = countOfUmlats(argv[3]);
    printf("%d\n", a);

  	readTeils(&HEAD, teilPath);
    readSchritts(HEAD, schrittPath);
    sortingTeils(HEAD, &HEAD_sorted);

  	printTeils(HEAD_sorted, geordnetPath);


    return 0;
}
