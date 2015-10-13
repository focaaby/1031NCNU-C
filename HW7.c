#include <stdio.h>
int len(int n) {
    int count = 1;
    while(n != 1) {
        if(n % 2 == 1)
            n = 3 * n + 1;
        else
            n = n / 2;
        count++;
    }
    return count;               
}
int main() {
    int sta, fin, max, i;
    max = -1;
    scanf("%d %d", &sta, &fin);
    for(i = sta; i <= fin; i++) {
        if(len(i) > max) {
            max = len(i);
        }
    }
    printf("%d %d %d\n", sta, fin, max);
    return 0;
}
