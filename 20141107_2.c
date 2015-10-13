#include <stdio.h>
//pointer is a data type like int, float, char etc.
//operators for pointer are &, *, +, -

int fun(int x) {
    printf("address of x in fun is %p\n", &x);
    x = 0;
}

int main() {
    int x = 100;
    fun(x);
    printf("address of x in main is %p\n", &x);
    printf("%d\n", x);
    return 0;
}
