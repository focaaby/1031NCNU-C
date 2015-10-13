#include <stdio.h>

void swap_po(int *x, int *y) {
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main() {
    int x = 0;
    int *y;
    int **z;
    y = &x;
    z = &y;
    printf("x value = %d\n",x);
    printf("x value(memory) = %p\n", &x);
    printf("y value = %p\n", y);
    printf("*y value = %d\n", *y);
    printf("y value(memory) = %p\n", &y);
    printf("z value = %p\n", z);
    printf("*z value = %p\n", *z);
    printf("**z value = %d\n", **z);
    printf("z value(memory) = %p\n", &z);
}
