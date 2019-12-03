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
  int i;
  int length = strlen(arr);
  for (i = 0; i < lastLen - length; i++)
    strcat(arr," ");
}

int countOfUmlats (char arr[]) {
  if(strlen(arr) < 1)
    return 0;

  char delimiter[] = "a";
  char *ptr;

  ptr = strtok(arr, delimiter);
  int i = -1;
  while(ptr != NULL) {
    i++;
    printf("%s\n", ptr);
   	ptr = strtok(NULL, delimiter);
  }
  return i;
/*

  if(strlen(arr) < 1)
    return 0;
  char umleut[2] = {"ä"}; //als string weil als char bekommt man multi-charackter warning
  int len = 0;
  return strlen(arr);*/
}
