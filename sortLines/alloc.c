#define BUFSIZE 2000
#include <stdio.h>
static char allocbuf[BUFSIZE];
static char *bufp = allocbuf;

char *alloc(int len) {
    if (allocbuf + BUFSIZE - bufp >= len) {
        bufp += len;
        return bufp - len;
    } else {
        return 0;
    }
}

void allocfree(char *p) {
    if (p >= allocbuf && p <= allocbuf + BUFSIZE) {
        bufp = p;
        return;
    } else {
        printf("allocfree: free operation failed");
    }
}

