#include <stdio.h>
int main() {
    int n, val, max, min , i;
    scanf("%d", &n);
    scanf("%d", &val);
    max = min = val;
    for(i = 1; i < n; i++) {
        scanf("%d", &val);
        if(val > max)
            max = val;
        if(val < min)
            min = val;
    }
    printf("%d %d\n", max, min);
    return 0;
}
/*
int main() {
    int count;
    scanf("%d", &count);
    int num;
    int max = -1;
    int min = 100001;
    int i;
    for(i = 0; i < count; i++){
        scanf("%d", &num);
        if(num > max)
            max = num;
        if(num < min)
            min = num;
    }
    printf("max:%d min:%d\n", max, min);
    return 0;
}
*/
