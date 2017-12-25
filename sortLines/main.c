#include <stdio.h>
#include "read.h"

#define MAXLINES 3

int str_comp(char *, char *);
void quick_sort(char *ptr_array[], int left, int right);

int main() {
    char *lineptr[MAXLINES];
    int nlines = read_lines(lineptr, MAXLINES);
    quick_sort(lineptr, 0, nlines - 1);

    printf("Printing lines\n");
    for (int i=0; i<nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
    return 0;
}

int str_comp(char *s, char *t) {
    int i;
    for (i=0; s[i] == t[i]; i++) {
        if (s[i] == '\0') {
            return 0;
        }
    }
    return s[i] - t[i];
}

void swap(char *ptr_array[], int i, int j) {
    char *temp = ptr_array[i];
    ptr_array[i] = ptr_array[j];
    ptr_array[j] = temp;
}

void quick_sort(char *ptr_array[], int left, int right) {
    int i = left;
    int j = left+1;
    /* The condition left == right does not suffice, consider the algorithm for 2 elements */
    if (left >= right)
        return;

    while (j <= right) {
        if (str_comp(ptr_array[j], ptr_array[left]) <= 0) {
            swap(ptr_array, ++i, j);
        }
        j++;
    }
    swap(ptr_array, i, left);
    quick_sort(ptr_array, left, i-1);
    quick_sort(ptr_array, i+1, right);
}

