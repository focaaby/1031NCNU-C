#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int i,j;
    for (i = 1; i <= n; i = i +1) {
        //print line j
        //line j has n-j space
        for (j = 1; j <= n-i; j = j +1) {
            printf(" ");
        }
        for (j = 1; j <= 2*i-1; j = j +1) {
            printf("*");
        }
        printf("\n");
    }
    for (i = n-1; i >= 1; i = i -1) {
        for (j = 1; j <= n-i; j = j +1) {
            printf(" ");
        }
        for (j = 1; j <= 2*i-1; j = j +1) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
