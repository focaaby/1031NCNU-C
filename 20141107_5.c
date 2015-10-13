#include <stdio.h>

void swap(int x, int y) {
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}

void swap_po(int *x, int *y) {
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main() {
    int x = 5, y = 20;
    printf("before swap, x=%d, y=%d\n", x,y);
    swap_po(&x, &y);
    printf("agter swap, x=%d, y=%d\n", x,y);
}
