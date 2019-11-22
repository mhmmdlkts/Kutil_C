#include "utility.h"

void freeSpace(teil *HEAD) {
    teil *p = HEAD;
    while (p != NULL) {
    	teil *tmp = p;
        p = p->next;
    	free(tmp);
    }
}
