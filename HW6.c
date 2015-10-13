#include <stdio.h>
int reverse(int x) {
    int y = 0;      
    while(x != 0) { 
        y = y * 10 + x % 10;
        x /= 10;
    }
    return y;
}
int main() {
    int n, i, num, count;
    scanf("%d", &num);
    for(i = 0; i < num; i++) {
        count = 0;
        scanf("%d",&n);
        while(n != reverse(n)) {
            n = n + reverse(n);
            count++;
        }
        printf("%d %d\n", count, n);
    }
    return 0;
}
