#include <stdio.h>

void print(char c, int n) {
    int i;
    for(i = 1;i <= n; i++) {
        printf("%c", c);
    }
} 

int main() {
    int n,i;
    scanf("%d", &n);
    for (i = 1; i <= n; i = i +1) {
        print(' ', n-j);
        print('*', 2*j-1);
        printf("\n");
    }
    return 0;
}
