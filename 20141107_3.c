#include <stdio.h>
//pointer is a data type like int, float, char etc.
//operators for pointer are &, *, +, -

int sum(int x) {
    int y;
    y = 5;
    printf("%p\n", &x);
    if (x == 0)
        return 0;
    return x + sum(x-1);
}

int main() {
    int x = 100;
    scanf("%d", &x);
    printf("%d\n", sum(x));
    return 0;
}
