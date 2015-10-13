#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int i,j;
    for (i = 1; i <= n; i = i +1) {
        for (j = 1; j <= i; j = j +1) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
