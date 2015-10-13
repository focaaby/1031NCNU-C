#include <stdio.h>

/*
** in C, string is pepresented ad an array of char terminated by '\0'
** not by '0'
*/

int main() {
    //x is an array[5] of int
    int i, n;
    char s[] = "Hello World\n";
    scanf("%d", &n);
    int x[n];
    for (i = 0; i < 5;i = i+1) 
        x[i] = i;
    for (i = 0; i < 5;i = i+1) 
        printf("%d\n", x[i]);
    return 0;
}
