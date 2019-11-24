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
