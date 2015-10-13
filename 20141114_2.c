#include <stdio.h>

/*
** in C, string is pepresented ad an array of char terminated by '\0'
** not by '0'
** return the length of string s
** for example, input "Hello", retrun 5
*/

int mystrlen(char s[]) {
    int len = 0;
    while (s[len] != 0)
        len = len + 1;
    return len;
}

// line 18 == line 19
//char * mystrcat(char s1[], char s2[], char rel[]) { 
char * mystrcat(char *s1, char *s2, char *rel) {
    int len = 0, i;
    for (i = 0; s1[i] != 0; i++, len++)
        rel[len] = s1[i];
    for (i = 0; s2[i] != 0; i++, len++)
        rel[len] = s2[i];
    rel[len+1] = '\0';
    return rel;
}



int main() {
//    char s[] = "Hello World\n";
//    printf("%d\n", strlens(s));
    char s1[100];
    char s2[100];
    char result[200];
    scanf("%[^\n]s", s1);
    scanf("\n%[^\n]s", s2);
    printf("%s\n", s1);
    printf("%s\n", s2);
    printf("%s\n", mystrcat(s1, s2, result));
    return 0;
}
