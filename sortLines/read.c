#include "read.h"
#include <stdio.h>

#define MAXLEN 200

char *alloc(int size);
static int buf_full, buf_val;

/* getch() reads the character from the buffer or uses getchar() to read from the input stream. This function paired with ungetch(),
 * creates the effect of reading from and writing to the input character stream */
int getch(void) {
    if (buf_full) {
        buf_full = 0;
        return buf_val;
    } else {
        return getchar();
    }
}

void ungetch(int c) {
    if (!buf_full) {
        buf_val = c;
        buf_full = 1;
    } else {
        printf("ungetch(): buffer already full\n");
    }
}

int get_line(char *str, int maxlen) {
    /* reads a line into str and returns its length */
    int i, c;
    for (i=0; i< maxlen-1 && (c = getch()) != '\n' && c != EOF; i++) {
        str[i] = c;
    }
    
    str[i] = '\0';

    if (c == EOF) {
        ungetch(c);
    }

    return i;
}

void str_cpy(char *from, char *to) {
    for (int i=0; (to[i] = from[i]) != '\0'; i++);
}

int read_lines(char *lineptr[], int maxlines) {
    /* Store all the lines one after the other in the allocated buffer and store the pointers to the lines */
    char line[MAXLEN];
    int len, i=0;
    while ((len = get_line(line, MAXLEN)) != 0) {
        /* Read the line and copy it to the allocated space */
        if (i < maxlines) {
            lineptr[i] = alloc(len+1); // +1 to include space for the null character
            str_cpy(line, lineptr[i]);
            i++;
        } else {
            printf("read_lines(): no memory available to store input\n");
        }
    }
    return i;
}


