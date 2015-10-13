#include <stdio.h>

int main() {
    int year;
    scanf("%d", &year);
    // leap year 
    if (year%4 == 0){
        if (year%100 ==0) {
            if(year%400 ==0)
                printf("not leap\n");
            else 
                printf("not leap\n");
        } else {
            printf("leap\n");
        }
    } else {
        printf("not leap\n");
    }
}
