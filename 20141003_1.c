#include <stdio.h>

int main() {
    int birthYear;
    scanf("%d", &birthYear);
    if (2014-birthYear >= 18) {
        if (2014-birthYear >= 20) {
            printf("你有投票權\n");
        } else {
            printf("你沒有投票權\n");
        }
    } else {
        printf("你未成年\n");
    }
}
