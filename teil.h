#ifndef TEIL_H
#define TEIL_H

typedef struct teil {
    char typ[30], bez[30], einheit[10], gewicht[30], preis[30];
    struct teil * next;
    struct teil * needs;

}teil;

teil* newTeil(char typ[], char bez[], char einheit[], char gewicht[], char preis[]);
void transferTeil(teil **HEAD_FROM, teil **HEAD_TO, teil **TAIL_TO, teil *p, teil *p_prev);
short canTeilBuild (teil *HEAD_sorted, teil *p);
void readTeils(teil **HEAD, char path[]);
void readSchritts(teil *HEAD, char path[]);
void sortingTeils(teil *HEAD, teil **HEAD_sorted);
void printTeils(teil *HEAD, char path[]);
short isSameTeil (teil *teil1, teil *teil2);
void doItBlockFormat(teil *HEAD);

#endif
