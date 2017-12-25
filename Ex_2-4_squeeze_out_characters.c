#include <stdio.h>
#define MAXLEN 30
#define MAXCHAR 10

void squeeze(char s[], char c) {
    /* Function to remove all occurences of c from the string s */
    int i,j;
    for(i=j=0; s[i]!='\0'; i++) {
        if(s[i] != c) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

int main() {
    char str[MAXLEN], c, rem_char[MAXCHAR];
    int i=0;
    printf("Enter the string: ");
    while((c = getchar()) != '\n') {
        str[i++] = c;
    }
    str[i] = '\0';
    i=0;
    printf("\nEnter the characters to be removed without spaces in between: ");
    while((c = getchar()) != '\n') {
        rem_char[i++] = c;
    }
    rem_char[i] = '\0';
    /* "squeeze" out the characters one at a time */
    for (int i=0; (c = rem_char[i]) != '\0'; i++) {
        squeeze(str, c);
    }
    printf("\nThe squeezed string: %s\n", str);
    return 0;
}

