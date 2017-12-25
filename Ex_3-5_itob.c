/* Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b character representation in
 * the string s. In particular, itob(n,s,16) formats n as a hexadecimal integer in s. */

#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    /* reverse the string in place */
    int i,j;
    for (i=0, j=strlen(s)-1; i<j; i++, j--) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itob(int n, char s[], int b) {
    /* converts n to base b and stores the value in s */
    int d, i=0;
    char sign = '+';
    if (n<0) {
        sign = '-';
        n = -n;
    }
    do {
        d = n%b;
        /* Ternary operator to handle hexadecimal conversions */
        s[i++] = (d<10) ? d + '0': d-10+'a';
    } while ((n/=b) > 0);
    if (sign == '-')
        s[i++]=sign;
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[20];
    int n, b;
    printf("Enter the number to be converted: ");
    scanf("%d", &n);
    printf("Enter the new base: ");
    scanf("%d", &b);
    itob(n, s, b);
    printf("Converted number: %s\n", s);
    return 0;
}
