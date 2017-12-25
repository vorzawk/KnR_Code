/* Program to display a histogram of the lengths of words in its input. Exercise 1-13 in "The C programming Language"
 * by Kernighan and Ritchie */
 
#include <stdio.h>

int main() {
    /* A word can be loosely defined as a sequence of characters which does not contain any whitespace characters. So,
     * the program below looks out for any newline or blank space characters in the input and counts the number of
     * characters in between. This gives the word lengths as per the definition and these are used to update the array
     * of word lengths */
    int cnt = 0, c, array[20], maxCnt=0;
    for (int i=0; i<20; ++i) {
        array[i] = 0;
    }

    while((c = getchar()) != EOF) {
        if ((c != '\n') && (c != ' ')) {
            ++cnt;
        } else if (cnt != 0) {
            // maxCnt stores the length of the longest word so that the histogram doesn't contain blank lines at the end
            maxCnt = (cnt > maxCnt) ? cnt: maxCnt;
            ++array[cnt];
            cnt = 0;
        }
    }

    for (int i=0; i <= maxCnt; ++i) {
        for (int j=0; j < array[i]; ++j) {
            printf("- ");
        }
        printf("\n");
    }
}
    
