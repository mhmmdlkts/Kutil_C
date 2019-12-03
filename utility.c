#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

void freeSpace(teil *HEAD) {
    if(HEAD == NULL)
    	return;
    teil *p = HEAD;
    while (p != NULL) {
    	teil *tmp = p;
        p = p->next;
    	free(tmp);
    }
}

void existFile(FILE *file) {
    if (file == NULL)
    {
        printf("Error! opening file.\n");
        exit(1);
    }
}

int getMax(int a, int b) {
  if (a > b)
    return a;
  return b;
}

int getLenght (char arr[]) {
  
}
