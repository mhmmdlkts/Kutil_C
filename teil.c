#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teil.h"
#include "utility.h"

teil* newTeil(char typ[], char bez[], char einheit[], char gewicht[], char preis[]) {
    teil *temp = (teil*)malloc(sizeof(teil));
    strcpy(temp->typ, typ);
    strcpy(temp->bez, bez);
    strcpy(temp->einheit, einheit);
    strcpy(temp->gewicht, gewicht);
    strcpy(temp->preis, preis);
    temp->needs = NULL;
    temp->next = NULL;
}

teil* newSubTeil(char typ[], char bez[]) {
    return newTeil(typ, bez, NULL, NULL, NULL);
}

teil* readTeils(teil *HEAD, char path[]) {
    FILE *teilFile = fopen(path, "r");
    if (teilFile == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

    char teil_typ[30], teil_bez[30], teil_einheit[10], teil_gewicht[30], teil_preis[30];  //teil.dat

	  teil *TAIL = NULL;


    while( fscanf(teilFile,"%s %s %s %s %s", teil_typ, teil_bez, teil_einheit, teil_gewicht, teil_preis) != EOF )
    {
        teil *temp = newTeil(teil_typ, teil_bez, teil_einheit, teil_gewicht, teil_preis);

        if(HEAD == NULL) {
            HEAD = temp;
            TAIL = temp;
        } else {
            TAIL->next = temp;
            TAIL = temp;
        }

    }
    fclose(teilFile);
    return HEAD;
}

void readSchritts(teil *HEAD, char path[]) {

    FILE *schrittFile = fopen(path, "r");
    if (schrittFile == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

	teil *TAIL_temp = NULL;
    char ziel_typ[30], ziel_bez[30], quel_typ[30], quel_bez[30]; //schritt.dat
    int nr = 0;

    while( fscanf(schrittFile,"%s %s %d %s %s %*s %*s %*s", ziel_typ, ziel_bez, &nr, quel_typ, quel_bez) != EOF )
    {
        teil *temp = newSubTeil(ziel_typ, ziel_bez);

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

teil* sortingTeils(teil *HEAD, teil *HEAD_sorted) {

    teil *TAIL_sorted = NULL;

    while (HEAD != NULL) {
        teil *p = HEAD;
        teil *p_prev = NULL;
        while (p != NULL) {
            teil *n = p->needs;
            short check = 1;
            while(n != NULL) {
                teil *p2 = HEAD_sorted;
                while (p2 != NULL) {
                    if((strcmp(n->typ, p2->typ) == 0) && (strcmp(n->bez, p2->bez)== 0)) {
                        check = 1;
                        break;
                    }else{
                        check = 0;
                    }
                    p2 = p2->next;
                }
                if(check == 0)
                    break;
                n = n->needs;
            }
            if(check == 1) {
                //OK
                if (HEAD_sorted == NULL) {
                    HEAD_sorted = p;
                    TAIL_sorted = p;
                } else {
                    TAIL_sorted->next = p;
                    TAIL_sorted = p;
                }

                if (p_prev == NULL) {
                    HEAD = p->next;
                } else {
                    p_prev->next = p->next;
                }
                p->next = NULL;
            }
            p_prev = p;
            p = p->next;
            teil *d = HEAD_sorted;
            while (d != NULL) {
                d = d->next;
            }
            teil *du = HEAD;
            while (du != NULL) {
                du = du->next;
            }
        }
    }
    freeSpace(HEAD);
    return HEAD_sorted;
}

void printTeils(teil *HEAD, char path[]) {
    FILE * fOutput = fopen(path, "w");
    teil *p = HEAD;
    while (p != NULL) {
        fprintf(fOutput,"%s %s %s %s %s\n", p->typ, p->bez, p->einheit, p->gewicht, p->preis);
        p = p->next;
    }
    fclose(fOutput);
    freeSpace(HEAD);
}
