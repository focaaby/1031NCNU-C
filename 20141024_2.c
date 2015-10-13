#include <stdio.h>
int len(int n) {
    int count = 1;
    while(n != 1) {
        if(n % 2 == 1)       //如果n是奇數, n = 3 * n + 1
            n = 3 * n + 1;
        else                 // 否則 n = n / 2
            n = n / 2;
        count++;
        printf("%d ", n);
    }
    return count;               
}
int main() {
    int num;
    scanf("%d", &num);
    printf("%d\n", len(num));
    return 0;
}
