#ifndef TEIL_H
#define TEIL_H

typedef struct teil {
    char typ[30], bez[30], einheit[10], gewicht[30], preis[30];
    struct teil * next;
    struct teil * needs;

}teil;

void readTeils(teil **HEAD, char path[]);
void readSchritts(teil *HEAD, char path[]);
void sortingTeils(teil *HEAD, teil **HEAD_sorted);
void printTeils(teil *HEAD, char path[]);

#endif
