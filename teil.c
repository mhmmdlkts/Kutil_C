#include "teil.h"

teil* readTeils(teil *HEAD, char path[]) {
    FILE *teilFile;
    if ((teilFile = fopen(path, "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

    char teil_typ[30], teil_bez[30], teil_einheit[10], teil_gewicht[30], teil_preis[30]; //teil.dat
	
	teil *TAIL = NULL;
    
    
    while( fscanf(teilFile,"%s %s %s %s %s", &teil_typ, &teil_bez, &teil_einheit, &teil_gewicht, &teil_preis) != EOF )
    {
        teil *temp = (teil*)malloc(sizeof(teil));
        strcpy(temp->typ, teil_typ);
        strcpy(temp->bez, teil_bez);
        strcpy(temp->einheit, teil_einheit);
        strcpy(temp->gewicht, teil_gewicht);
        strcpy(temp->preis, teil_preis);
        temp->needs = NULL;
        temp->next = NULL;

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
	
    FILE *schrittFile;
    if ((schrittFile = fopen(path, "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

	teil *TAIL_temp = NULL;
    char ziel_typ[30], ziel_bez[30], quel_typ[30], quel_bez[30]; //schritt.dat
    int nr = 0;

    while( fscanf(schrittFile,"%s %s %d %s %s %*lf %*s %*lf", &ziel_typ, &ziel_bez, &nr, &quel_typ, &quel_bez) != EOF )
    {
        teil *temp = (teil*)malloc(sizeof(teil));
        strcpy(temp->typ, quel_typ);
        strcpy(temp->bez, quel_bez);
        temp->next = NULL;
        temp->needs = NULL;

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

    while (HEAD != NULL) { // Liste boşalana kadar
        teil *p = HEAD;
        teil *p_prev = NULL;
        while (p != NULL) { // Tüm karışık liste için
            teil *n = p->needs;
            short bool = 1;
            while(n != NULL) { // Tüm ihtiyaçlar için
                teil *p2 = HEAD_sorted;
                while (p2 != NULL) { // Tüm sıralanmış liste için
                    if((strcmp(n->typ, p2->typ) == 0) && (strcmp(n->bez, p2->bez)== 0)) {
                        bool = 1;
                        break;
                    }else{
                        bool = 0;
                    }
                    p2 = p2->next;
                }
                if(bool == 0)
                    break;
                n = n->needs;
            }
            if(bool == 1) {
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
}
