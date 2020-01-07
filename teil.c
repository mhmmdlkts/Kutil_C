#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teil.h"
#include "utility.h"

teil* newTeil(char typ[], char bez[], char einheit[], char gewicht[], char preis[]) {
    teil *temp = (teil*)malloc(sizeof(teil));
    if(typ != NULL)
	    strcpy(temp->typ, typ);
    if(bez != NULL)
	    strcpy(temp->bez, bez);
    if(einheit != NULL)
	    strcpy(temp->einheit, einheit);
    if(gewicht != NULL)
	    strcpy(temp->gewicht, gewicht);
    if(preis != NULL)
	    strcpy(temp->preis, preis);
    temp->needs = NULL;
    temp->next = NULL;
    return temp;
}

void addTeilToList(teil **HEAD, teil **TAIL, teil *p) {
    if(*HEAD == NULL) {
        *HEAD = p;
        *TAIL = p;
    } else {
        (*TAIL)->next = p;
        *TAIL = p;
    }
}

void transferTeil(teil **HEAD_FROM, teil **HEAD_TO, teil **TAIL_TO, teil *p, teil *p_prev) {
    if (*HEAD_TO == NULL) {
        *HEAD_TO = p;
        *TAIL_TO = p;
    } else {
        (*TAIL_TO)->next = p;
        *TAIL_TO = p;
    }

    if (p_prev == NULL) {
        *HEAD_FROM = p->next;
    } else {
        p_prev->next = p->next;
    }
    p->next = NULL;
}

short isSameTeil (teil *teil1, teil *teil2) {
  if ((strcmp(teil1->typ, teil2->typ) == 0) && (strcmp(teil1->bez, teil2->bez)== 0))
    return 1;
  return 0;
}

short canTeilBuild (teil *HEAD_sorted, teil *p) {
	teil *n = p->needs;
    short check = 1; //bool check = true;
    while(n != NULL) {
        teil *p2 = HEAD_sorted;
        while (p2 != NULL) {
            if(isSameTeil(n,p2)) {
                check = 1;
                break;
            }else{
                check = 0;
            }
            p2 = p2->next;
        }
        if(!check)
            break;
        n = n->needs;
    }
    return check;
}

void readTeils(teil** HEAD, char path[]) {
    FILE *teilFile = fopen(path, "r");
    existFile(teilFile);

    char teil_typ[30], teil_bez[30], teil_einheit[10], teil_gewicht[30], teil_preis[30];  //teil.dat

	teil *TAIL = NULL;

    while( fscanf(teilFile,"%s %s %s %s %s", teil_typ, teil_bez, teil_einheit, teil_gewicht, teil_preis) != EOF )
    {
        teil *temp = newTeil(teil_typ, teil_bez, teil_einheit, teil_gewicht, teil_preis);
        addTeilToList (HEAD, &TAIL, temp);
	}
    fclose(teilFile);
}


void readSchritts(teil *HEAD, char path[]) {

    FILE *schrittFile = fopen(path, "r");
    existFile(schrittFile);

    teil *TAIL_temp = NULL;
    char ziel_typ[30], ziel_bez[30], quel_typ[30], quel_bez[30]; //schritt.dat
    int nr = 0;

    while( fscanf(schrittFile,"%s %s %d %s %s %*s %*s %*s", ziel_typ, ziel_bez, &nr, quel_typ, quel_bez) != EOF ) // TODO %s to %100s // Ja.  Rade
    {
        teil *temp = newTeil(quel_typ, quel_bez, NULL, NULL, NULL);

        // Dieser Teil setzt die richtige Sortierreihenfolge von schritt.dat voraus, das ist nicht ganz so gut.  Rade
        if(nr == 1) {
            teil *p = HEAD;
            while (p != NULL) {
                if((strcmp(p->typ, ziel_typ) == 0) && (strcmp(p->bez, ziel_bez)== 0)) {
                    p->needs = temp;
                    TAIL_temp = p->needs;
                    break;
                }
                p = p->next;
            }
        } else {
            TAIL_temp->needs = temp;
            TAIL_temp = temp;
        }
    }

    fclose(schrittFile);
}

void sortingTeils(teil *HEAD, teil **HEAD_sorted) {

    teil *TAIL_sorted = NULL;

    while (HEAD != NULL) {
        teil *p = HEAD;
        teil *p_prev = NULL;
        while (p != NULL) {
            if(canTeilBuild(*HEAD_sorted, p)) {
            	transferTeil(&HEAD, HEAD_sorted, &TAIL_sorted, p, p_prev);
            }
            p_prev = p;
            p = p->next;
        }
    }
    freeSpace(HEAD);
}

void doItBlockFormat(teil *HEAD) {
  int maxTyp=0, maxBez=0, maxEinheit=0, maxGewicht=0, maxPreis=0;
  teil *p = HEAD;
  while (p != NULL) {
    maxTyp = getMax(maxTyp, strlen(p->typ));
    maxBez = getMax(maxBez, strlen(p->bez));
    maxEinheit = getMax(maxEinheit, strlen(p->einheit));
    maxGewicht = getMax(maxGewicht, strlen(p->gewicht));
    maxPreis = getMax(maxPreis, strlen(p->preis));
    p = p->next;
  }
  p = HEAD;
  while (p != NULL) {
    addBlanks(p->typ, maxTyp);
    addBlanks(p->bez, maxBez);
    addBlanks(p->einheit, maxEinheit);
    addBlanks(p->gewicht, maxGewicht);
    addBlanks(p->preis, maxPreis);
    p = p->next;
  }
}

void printTeils(teil *HEAD, char path[]) {
  doItBlockFormat(HEAD);
    FILE * fOutput = fopen(path, "w");
    teil *p = HEAD;
    while (p != NULL) {
        fprintf(fOutput,"%s %s %s %s %s\n", p->typ, p->bez, p->einheit, p->gewicht, p->preis);
        p = p->next;
    }
    fclose(fOutput);
    freeSpace(HEAD);
}
