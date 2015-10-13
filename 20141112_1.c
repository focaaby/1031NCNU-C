#include <stdio.h>

int reverse(int x) {
    int rel = 0;
    while (x != 0) {
        rel = rel *10 + x % 10;
        x = x / 10;
    }
    return rel;
}

void reverseAndAdd(int x, int *rel, int *count) {
    int c = 0;
    while (x != reverse(x)) {
        x = x + reverse(x);
        c = c +1;
    }
    *rel = x;
    *count = c;
}


int y = 0; 
/* 
##
##	some textbook calls y as a global variable
##	y is visible to all functions of the "program" 
## 
*/

void fun() {
/*
##	x is local and also an auto variable 
##	which means x will be created when this functuin was called
##	and destroyed when this function returned.
*/
    int x;
    printf("fun1 was called, value fo y = %d\n", y);
}

void fun2() {
    printf("fun2 was called\n");
}

void callFun(void (*p)()) {
/*
##	p is apointer to functuon
##	call a function through pointer p
##
*/
    (*p)();
}

/*
##	pointer is adata type
##	which stores "address" if variable or function
*/
int main() {
//    callFun(fun1);
//    callFun(fun2);
    int n, i, val, rel , count;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
       scanf("%d", &val);
       reverseAndAdd(val, &rel, &count);
       printf("%d %d\n", rel, count);
    } 
    return 0;
}
