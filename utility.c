#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void addBlanks(char arr[], int lastLen) {
  int i; int constanteBlanks = 2;
  int length = strlen(arr) - countOfAllGermanUmlauts(arr);
  for (i = 0; i < lastLen - length + constanteBlanks; i++)
    strcat(arr," ");
}

int countOfAllGermanUmlauts (char arr[]) {
  int um = 0;
  um += countOfMultiChar(arr,"Ä");
  um += countOfMultiChar(arr,"ä");

  um += countOfMultiChar(arr,"Ü");
  um += countOfMultiChar(arr,"ü");

  um += countOfMultiChar(arr,"Ö");
  um += countOfMultiChar(arr,"ö");

  um += countOfMultiChar(arr,"ß");
  return um;
}

int countOfMultiChar (char arr[], char umlaut[]) {
  int len = 0;
  int i = 0;
  for(i = 0; i < strlen(arr); i++)
    if(arr[i] == umlaut[0] && arr[i+1] == umlaut[1])
        len++;
  return len;
}
