#include <stdio.h>

int isLeap(int y) {
    return y%400 ==0 || (y%4 == 0 && y%100!=0);
} 


int main() {
    int year;
    scanf("%d", &year);
    // leap year 
    if (isLeap(year)) {
        printf("leap\n");
    } else {
        printf("not leap\n");
    }
}
